#include "pch.h"
#include "a3parser.h"
#include "message_scrambler.h"
#include "cheat.h"

a3parser::a3parser(/*uint8_t* client_ip, */uint8_t* server_ip/*, uint8_t* victimmac, uint8_t* targetmac, const uint8_t* my_mac*/): m_client_ports_set(false), m_server_ports_set(false), m_enable_printing(false), m_parted_to_client(nullptr), m_parted_to_server(nullptr) {
    //m_client_info = IpPortInfo(client_ip, server_ip);
    m_server_info = IpPortInfo(server_ip, server_ip);
    //memcpy(m_victimmac, victimmac, 6);
    //memcpy(m_targetmac, targetmac, 6);
    //memcpy(m_my_mac, my_mac, 6);

    // set the server encryption & decryption key
    uint8_t key[16];
    for (int i = 0; i < 16; i++) {
        key[i] = server_xorkey[i] ^ server_xorhash[i];  
    }
    aes_setkey_dec(&m_server_dec, key, 128);
    aes_setkey_enc(&m_server_enc, key, 128);

    // set client encryption & decryption key
    for (int i = 0; i < 16; i++) {
        key[i] = client_xorkey[i] ^ client_xorhash[i];
    }
    aes_setkey_dec(&m_client_dec, key, 128);
    aes_setkey_enc(&m_client_enc, key, 128);

    // set be server encryption & decryption key
    for (int i = 0; i < 16; i++) {
        key[i] = be_server_xorkey[i] ^ be_server_xorhash[i];  
    }
    aes_setkey_dec(&m_be_server_dec, key, 128);
    aes_setkey_enc(&m_be_server_enc, key, 128);

    // set be client encryption & decryption key
    for (int i = 0; i < 16; i++) {
        key[i] = be_client_xorkey[i] ^ be_client_xorhash[i];
    }
    aes_setkey_dec(&m_be_client_dec, key, 128);
    aes_setkey_enc(&m_be_client_enc, key, 128);

    init_default_formats();

    memset(m_log_message, false, sizeof(bool) * 2 * NETWORK_MESSAGE_COUNT);
    memset(m_callbacks, 0, sizeof(MsgCallback) * 2 * NETWORK_MESSAGE_COUNT);
    
    setup_callbacks();
    setup_printing();

    m_out_file = fopen("log.txt", "w");
}

void a3parser::setup_callbacks() {
    SET_CALLBACK(TO_SERVER, MessageChat);

    ENABLE_CALLBACK(MessageAskForApplyDoDamage);
    SET_CALLBACK(TO_CLIENT, MessageWeatherUpdate);
    SET_CALLBACK(TO_CLIENT, MessagePlayerRole);
    SET_CALLBACK(TO_SERVER, MessageMarkerCreate);   

    // Create/Update function for entities
    SET_CALLBACK(TO_SERVER, MessageClientState);

    ENABLE_CALLBACK(MessageDeleteObject);
    ENABLE_CALLBACK(MessageForceDeleteObject);
    ENABLE_CALLBACK(MessageDisposeObject);

    SET_CALLBACK(TO_CLIENT, MessageLogin);
    SET_CALLBACK(TO_CLIENT, MessageLogout);

    ENABLE_CALLBACK(MessageCreateVehicle);
    ENABLE_CALLBACK(MessageCreateHelicopterRTD);
    ENABLE_CALLBACK(MessageCreateTurret);
    ENABLE_CALLBACK(MessageCreateEntitySimple);
    ENABLE_CALLBACK(MessageCreateObject);

    ENABLE_CALLBACK(MessageUpdateMan);
    ENABLE_CALLBACK(MessageUpdatePositionMan);
    ENABLE_CALLBACK(MessageUpdateTank);
    ENABLE_CALLBACK(MessageUpdatePositionTank);
    ENABLE_CALLBACK(MessageUpdateCar);
    ENABLE_CALLBACK(MessageUpdatePositionCar);
    ENABLE_CALLBACK(MessageUpdateAirplane);
    ENABLE_CALLBACK(MessageUpdatePositionAirplane);
    ENABLE_CALLBACK(MessageUpdateHelicopterRTD);
    ENABLE_CALLBACK(MessageUpdatePositionHelicopterRTD);
    ENABLE_CALLBACK(MessageUpdateShip);
    ENABLE_CALLBACK(MessageUpdatePositionShip);
    ENABLE_CALLBACK(MessageUpdateAnimal);
    ENABLE_CALLBACK(MessageUpdatePositionAnimal);
    ENABLE_CALLBACK(MessageUpdateParachute);
    ENABLE_CALLBACK(MessageUpdateParaglide);
    ENABLE_CALLBACK(MessageUpdateTurret);
    ENABLE_CALLBACK(MessageUpdatePositionTurret);

    ENABLE_CALLBACK(MessageUpdateInvisibleVehicle);
    ENABLE_CALLBACK(MessageUpdateVehicle);
    ENABLE_CALLBACK(MessageUpdateObject);
    ENABLE_CALLBACK(MessageUpdatePositionVehicle);
    
}

void a3parser::setup_printing() {
    //ENABLE_PRINT(TO_SERVER, NetworkMessageMarkerCreate);
    //ENABLE_PRINT(TO_SERVER, NetworkMessageMarkerDelete);

    /*
    //these are for when inverted mode is turned on as these spam like crazy
    ENABLE_PRINT(TO_SERVER, NetworkMessageDataSignatureAnswer);
    ENABLE_PRINT(TO_CLIENT, NetworkMessageTransferMissionFile);

    ENABLE_PRINT(TO_CLIENT, NetworkMessageTransferFile);
    ENABLE_PRINT(TO_SERVER, NetworkMessageTransferFile);
    ENABLE_PRINT(TO_SERVER, NetworkMessageUpdatePositionVehicle);
    */
}

bool a3parser::parse_packet(uint8_t* pkt) {
    uint8_t buf[2048];

    m_packet_out = pkt;

    iphdr* iph = (iphdr*)(pkt);
    
    // if it isnt a UDP packet lets not process it further
    if (iph->protocol != UDP_PROTOCOL)
        return false;

    // figure out if this packet is going to the client or the server
    uint8_t to;
    if (!memcmp(&iph->saddr, m_server_info.m_srcip, 4))
        to = TO_CLIENT;
    else if (!memcmp(&iph->daddr, m_server_info.m_srcip, 4))
        to = TO_SERVER;
    else // if neither this wasnt meant for us, not a game packet. 
        return false;

    udphdr* udph = (udphdr*)(uintptr_t(iph) + sizeof(iphdr));
    uint8_t* data = (uint8_t*)(uintptr_t(udph) + sizeof(udphdr));

    int16_t datagram_size = ntohs(udph->len) - sizeof(udphdr);

    // make sure its a valid packet going to the game
    if (datagram_size < MSG_HEADER_LEN || datagram_size > 2048)
        return false;

    memcpy(buf, data, datagram_size);

    m_be_message = false;

    // packet going to the BEClient, ignore (for now, reversing this might be interesting)
    // and might be able to be used to bypass the heartbeat (by emulating it)
    uint16_t be_port = htons(2306);
    if (udph->uh_dport == be_port || udph->uh_sport == be_port) {
        m_be_message = true;
        return false;
    }

    // decrypt the packet
    decrypt_packet(buf);

    // verify the arma crc and only continue processing if the crc verifies
    if (!check_crc(buf, datagram_size))
    {
        printf("CRC failed\n");
        print_ascii(buf, datagram_size, to);
        return false;
    }

    // dont process battleye further, lets just dump for analysis...
    if (m_be_message) {
        // dump?
        return false;
    }

    // just override any current flags/whatnot if we need to send a part message
    if (to == TO_SERVER) {
        if (m_parted_to_server) {
            write_part_packet(m_parted_to_server);
            return true;
        }
    }
    else if (m_parted_to_client) {
        printf("Writing part to client\n");
        write_part_packet(m_parted_to_client);
        return true;
    }

    int16_t len = datagram_size - MSG_HEADER_LEN;
    if (!len)
        return false;

    ArmaMessageHeader* hdr = (ArmaMessageHeader*)buf;
    uint16_t flags = hdr->flags;

    if (flags & MSG_VOICE_FLAG || flags & MSG_MAGIC_FLAG || flags & MSG_DUMMY_FLAG)
        return false;

    // skip partial messages for now until I rebuild the packet merging
    if (flags & MSG_PART_FLAG) {
        return false;
        printf("\nPART header\n");
        print_header((uint8_t*)hdr);

        if (flags & MSG_CLOSING_FLAG)
            printf("CLOSING FLAG\n");
        if (flags & MSG_BUNCH_FLAG)
            printf("bunch flag\n");

        printf("\n");
        return false;
    }

    NetworkMessageRaw src = NetworkMessageRaw(buf, len);

    bool ok = process_messages(&src, to);

    if (ok) {
        process_queued_messages(&src, to == TO_SERVER ? m_messages_to_server : m_messages_to_client);

        // if we changed or added something we need to actually re-encrypt the packet and write it to the "actual" packet
        if (src.m_write_to_packet)
            write_to_packet(&src, to);
    }

    return ok;
}

void a3parser::process_queued_messages(NetworkMessageRaw* src, threaded_queue<msg_queue_item>& queue) {
    std::lock_guard<std::mutex> lock(queue.mtx); // locks the queue so no other thread can mess with this while we are processing >:(

    auto& q = queue.q;

    while (!q.empty() && src->m_pos < 1200) { // maximum is 1500 octets for eth packets (lets not bother with fragmenting the eth packet), headers are about 100 - lets just be safe and not overrun the packet by using 1250 as the cut-off
        auto it = q.front();

        // encode the queue message and increase the message count
        if (!encode_message(src, it.m_type, it.m_msg)) {
            printf("Failed queuing messages!\n");
            return;
        }
        src->m_message_count++;

        // now clean up the memory allocated for the message
        CleanupNetworkMessage[it.m_type](it.m_msg);

        q.pop();
    }

    // finally change the message count in the message if we need.
    int pos_backup = src->m_pos;

    src->m_pos = sizeof(int);

    int type;
    src->Get(type, NCTSmallUnsigned);

    if (type == NetworkMessageMessages) {
        int pos_message_count = src->m_pos;

        int message_count = 0;
        src->Get(message_count, NCTSmallUnsigned);
        
        if (message_count != src->m_message_count) {
            auto tmp_buf = new unsigned char[src->m_buf_size + 24];

            src->m_write_to_packet = true; // make sure this is true
            int pos_after_count = src->m_pos;

            // backup everything in the case that the size of the message count changes
            memcpy(tmp_buf, src->m_buf + src->m_pos, pos_backup - src->m_pos);

            src->m_pos = pos_message_count;
            src->Put(src->m_message_count, NCTSmallUnsigned);

            // restore the saved bytes in case the size changed
            if (pos_after_count != src->m_pos) {
                memcpy(src->m_buf + src->m_pos, tmp_buf, pos_backup - pos_after_count);
                pos_backup += src->m_pos - pos_after_count; // add the delta to this (so it has the proper size incase the size changed)
            }

            delete[ ] tmp_buf;
        }
    }
    else if (src->m_message_count != 1) {
        auto tmp_buf = new unsigned char[src->m_buf_size + 24];

        // if message count is not 1 and not type is not NetworkMessageMessages we have "encode" a NetworkMessageMessages as the first message
        src->m_write_to_packet = true;

        src->m_pos = sizeof(int);
        int first_message_pos = src->m_pos;

        // back dis up
        memcpy(tmp_buf, src->m_buf + first_message_pos, pos_backup - first_message_pos);
        
        src->Put((int)NetworkMessageMessages, NCTSmallUnsigned);
        src->Put(src->m_message_count, NCTSmallUnsigned);

        // and now restore it at the new pos
        memcpy(src->m_buf + src->m_pos, tmp_buf, pos_backup - first_message_pos);
        pos_backup += src->m_pos - first_message_pos; // add the delta to the "size"

        delete[ ] tmp_buf;
    }

    src->m_pos = pos_backup;
    src->m_size = pos_backup;
}

void a3parser::queue_message_to_server(int type, unsigned char* msg) {
    auto& q = m_messages_to_server;

    std::lock_guard<std::mutex> lock(q.mtx);

    auto new_msg = msg_queue_item(type, msg);

    q.q.push(new_msg);
}

void a3parser::queue_message_to_client(int type, unsigned char* msg) {
    auto& q = m_messages_to_client;

    std::lock_guard<std::mutex> lock(q.mtx);

    auto new_msg = msg_queue_item(type, msg);
    
    q.q.push(new_msg);
}

bool a3parser::process_messages(NetworkMessageRaw* src, int to) {
    if (!decrypt_message(src, to))
        return false;

    m_message_print_indentation = "";
    bool printed_source = false;
    m_enable_printing = false;

    // now start the actual processing of networkmessages
    // first read the time from the message (useless for us)
    int time = 0;
    src->Get(time, NCTNone);

    // save the position before reading the message, the callback might need it if it re-encodes the message
    src->m_saved_pos = src->m_pos;

    // now get the message type
    int type = 0;
    src->Get(type, NCTSmallUnsigned);

    // if type is "Messages" it means this packet contains several messages, process them all.
    if (type == NetworkMessageMessages) {
        int message_count = 0;
        src->Get(message_count, NCTSmallUnsigned);

        src->m_message_count = message_count;

        for (int i = 0; i < message_count; i++) 
        {
            // save the position before reading the message, the callback might need it if it re-encodes the message
            src->m_saved_pos = src->m_pos;

            // get the message type
            src->Get(type, NCTSmallUnsigned);
            
            if (type >= NETWORK_MESSAGE_COUNT) {
                printf("invalid message type\n");
                return false;
            }

            if (m_log_message[to][type]/* || to == TO_SERVER*/) {
                m_enable_printing = true;
                if (!printed_source) {
                    PRINT("====================[%s]====================\n", to == TO_CLIENT ? "server" : "client");
                    printed_source = true;
                }
            }
            else
                m_enable_printing = false;

            NetworkMessageFormat* format = &GMsgFormats[type];

            if (!decode_message(to, src, format, type)) {
                printf("failed to decode message %s\n", NetworkMessageNames[type]);
                return false;
            }

            // add extra newline between messages
            PRINT("\n");
        }
    }
    else {
        if (type >= NETWORK_MESSAGE_COUNT) {
            printf("invalid message type\n");
            return false;
        }

        if (m_log_message[to][type] /*|| to == TO_SERVER*/) {
            m_enable_printing = true;
            if (!printed_source) {
                PRINT("====================[%s]====================\n", to == TO_CLIENT ? "server" : "client");
                printed_source = true;
            }
        }

        NetworkMessageFormat* format = &GMsgFormats[type];

        src->m_message_count = 1;

        if (!decode_message(to, src, format, type)) {
            printf("failed to decode message %s\n", NetworkMessageNames[type]);
            return false;
        }
    }

    PRINT("\n");

    return true;
}

bool a3parser::decode_message(int to, NetworkMessageRaw* src, NetworkMessageFormat* format, int type, unsigned char* msg) {
    auto items = format->m_items;

    // only set the callback and allocate space for the msg if the param is nullptr, else it might be a nested message
    MsgCallback callback = nullptr;
    if (!msg) {
        callback = m_callbacks[to][type];
        if (callback) {
            msg = CreateNetworkMessage[type]();
        }
    }

    // this means its a nested message - set it to nullptr (needs to be done AFTER above check)
    // this is because we dont  want to process nested messages individually, only the "mother" message.
    if (msg == (unsigned char*)-1)
        msg = nullptr;

    PRINT_SPACED("[%s (%i)] (msg: %lx, size %i)\n", NetworkMessageNames[type], type, msg, format->m_struct_size);

    // iterate all the format items for the message and process em'
    for (auto it : items) {
        PRINT_SPACED("%s (%s): ", it.m_name, NetworkDataTypeNames[it.m_specs.m_type]);

        // parse the item depending on the datatype and compression
        if (!decode_message_item(to, src, it, msg)) {
            printf("Decoding item %s (%s) failed\n", it.m_name, NetworkDataTypeNames[it.m_specs.m_type]);        
            return false;
        }
    }

    // DISCLAIMER: We DON'T need to clean up the msg here, its easier if we let the callback clean it up
    // WHICH MEANS that: dont fucking forget to clean it all up in the callback unless you want a horrible memleak
    // "delete" the actual casted object and not the buffer itself, so that the destructors gets called properly to clean up properly and free memory
    if (callback)
        callback(to, msg, src);

    return true;
}

bool a3parser::encode_message(NetworkMessageRaw* src, int type, unsigned char* msg) {
    src->m_write_to_packet = true;

    src->Put(type, NCTSmallUnsigned);

    auto format = &GMsgFormats[type];
    auto items = format->m_items;

    // iterate all the items of this message type and write each one
    for (auto it : items) {
        
        // write the item with the proper compression etc (reading it from the msg buffer, using the offset from the format
        if (!encode_message_item(src, it, msg)) {
            printf("Encoding items %s (%s) failed\n", it.m_name, NetworkDataTypeNames[it.m_specs.m_type]);
            return false;
        }
    }

    return true;
}

bool a3parser::remove_cur_message(NetworkMessageRaw* src) {
    src->m_write_to_packet = true;

    // decrease the message count (this will get written to the packet later on)
    src->m_message_count--;

    auto buf = src->m_buf;
    int pos = src->m_pos;
    int saved = src->m_saved_pos;
    int delta = pos - saved; // size of the message we are removing

    memcpy(buf + saved, buf + pos, src->m_size - pos);

    // change the size of it, and set the pos correctly
    src->m_size -= delta;
    src->m_pos = saved; 

    return true;
}

bool a3parser::reencode_message(NetworkMessageRaw* src, int type, unsigned char* msg) {
    auto tmp_buf = new unsigned char[src->m_buf_size];

    int old_size = src->m_size;
    int pos = src->m_pos;
    int backup_size = src->m_size - pos;

    memcpy(tmp_buf, src->m_buf + pos, src->m_size - pos);
    
    // set pos to the start of the current netmessage to rewrite it
    src->m_pos = src->m_saved_pos;

    encode_message(src, type, msg);

    // apply the delta between the old position and the new position to the size to "resize" it properly
    int delta = src->m_pos - pos;
    src->m_size = old_size;
    src->m_size += delta;

    // restore the bytes we backed up earlier
    memcpy(src->m_buf + src->m_pos, tmp_buf, backup_size);

    delete[ ] tmp_buf;

    return true;
}

bool a3parser::encode_message_item(NetworkMessageRaw* src, NetworkMessageFormatItem format, unsigned char* msg) {
    auto compression = format.m_specs.m_compression;

    bool ok = true;
    switch (format.m_specs.m_type) {
    case NDTBool:
    {
        WRITE_MSG_VAL_FROM_BUFFER(bool, compression, );
        break;
    }
    case NDTInteger:
    {
        WRITE_MSG_VAL_FROM_BUFFER(int, compression, );
        break;
    }
    case NDTInt64:
    {
        WRITE_MSG_VAL_FROM_BUFFER(int64_t, compression, );
        break;
    }
    case NDTFloat:
    {
        WRITE_MSG_VAL_FROM_BUFFER(float, compression, );
        break;
    }
    case NDTString:
    {
        CREATE_VAR_FROM_BUFFER(std::string);
        src->Put((char*)val.c_str(), compression);
        break;
    }
    case NDTRawData:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<char>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val) {
            src->Put(it, NCTNone);
        }

        break;
    }
    case NDTTime:
    {
        WRITE_MSG_VAL_FROM_BUFFER(Time, NCTNone, );
        break;
    }
    case NDTVector:
    {
        WRITE_MSG_VAL_FROM_BUFFER(vec3, compression, );
        break;
    }
    case NDTMatrix:
    {
        WRITE_MSG_VAL_FROM_BUFFER(matrix3x3, compression, );
        break;
    }
    case NDTBoolArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<char>);
        int size = val.size();
        src->Put(size, NCTSmallUnsigned);
        
        if (compression == NCTDefault) {
            int numbytes = (size + 7) >> 3;
            auto bits = (unsigned char*)src->PutRaw(numbytes);

            for (int j = 0; j < size; j++) {
                if (val[j])
                    bits[j >> 3] |= (1 << (j & 7));
                else
                    bits[j >> 3] &= ~(1 << (j & 7));
            }
        }
        else {
            for (auto& it : val)
                src->Put((bool)it, compression);
        }

        break;
    }
    case NDTIntArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<int>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put(it, compression);

        break;
    }
    case NDTFloatArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<float>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put(it, compression);

        break;
    }
    case NDTStringArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<std::string>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put((char*)it.c_str(), compression);

        break;
    }
    case NDTStringBArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<std::string>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put((char*)it.c_str(), compression);

        break;
    }
    case NDTSentence:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<Sentence>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val) {
            src->Put((char*)it.m_string.c_str(), compression);
            src->Put(it.m_pause, compression);
        }

        break;
    }
    case NDTObject:
    {
        int subtype = *(int*)format.m_specs.m_def_value;

        encode_message(src, subtype, msg + format.m_offset);

        break;
    }
    case NDTObjectArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<unsigned char*>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        int subtype = *(int*)format.m_specs.m_def_value;

        for (auto& it : val) {
            bool not_empty = it != nullptr;
            src->Put(not_empty, compression);

            if (!not_empty)
                continue;

            encode_message(src, subtype, it);
        }

        break;
    }
    case NDTObjectSRef:
    {
        bool not_empty = *(bool*)(msg + format.m_offset - sizeof(int64_t));
        src->Put(not_empty, compression);
        
        if (!not_empty)
            break;

        int subtype = *(int*)format.m_specs.m_def_value;

        encode_message(src, subtype, msg + format.m_offset);

        break;
    }
    case NDTRef:
    {
        WRITE_MSG_VAL_FROM_BUFFER(NetworkId, compression, );
        break;
    }
    case NDTRefArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<NetworkId>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put(it, compression);

        break;
    }
    case NDTData:
    {
        printf("fuck you, no encoding for this stupid shit until I actually ever see it sent ingame\n");
        ok = false;
        break;
    }
    case NDTXUIDArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<int64_t>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put(it, compression);

        break;
    }
    case NDTXNADDR:
    {
        auto buf = (unsigned char*)src->PutRaw(36);

        memcpy(buf, msg + format.m_offset, 36);

        break;
    }
    case NDTXOnlineStatArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<XOnlineStat>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val) {
            auto buf = (unsigned char*)src->PutRaw(16);

            memcpy(buf, it.m_stat, 16);
        }

        break;
    }
    case NDTLocalizedString:
    {
        WRITE_MSG_VAL_FROM_BUFFER(LocalizedString, compression, );
        break;
    }
    case NDTLocalizedStringArray:
    {
        CREATE_VAR_FROM_BUFFER(std::vector<LocalizedString>);
        src->Put((int)val.size(), NCTSmallUnsigned);

        for (auto& it : val)
            src->Put(it, compression);

        break;
    }
    default:
        return false;
    }

    return ok;
}

bool a3parser::decode_message_item(int to, NetworkMessageRaw* src, NetworkMessageFormatItem format, unsigned char* msg) {
    auto compression = format.m_specs.m_compression;

    bool ok = true;
    switch (format.m_specs.m_type) {
    case NDTBool:
    {
        bool val;
        src->Get(val, compression);
        if (val) {
            PRINT("true\n");
        }
        else {
            PRINT("false\n");
        }

        READ_MSG_VAL_TO_BUFFER(bool, = val);

        break;
    }
    case NDTInteger:
    {
        int val;
        src->Get(val, compression);
        PRINT("%i\n", val);

        READ_MSG_VAL_TO_BUFFER(int, = val);

        break;
    }
    case NDTInt64:
    {
        int64_t val;
        src->Get(val, compression);
        PRINT("%lld\n", val);

        READ_MSG_VAL_TO_BUFFER(int64_t, = val);

        break;
    }
    case NDTFloat:
    {
        float val;
        src->Get(val, compression);
        PRINT("%s\n", get_float_truncated(val).c_str());

        READ_MSG_VAL_TO_BUFFER(float, = val);

        break;
    }
    case NDTString:
    {
        // It returns the pointer to the null-terminated string in val variable
        char* val = nullptr;
        src->Get(val, compression);
        if (val) {
            PRINT("\"%s\"\n", val);
            READ_MSG_VAL_TO_BUFFER(std::string, = std::string(val));
        }
        else {
            PRINT("\n");
            READ_MSG_VAL_TO_BUFFER(std::string, = std::string());
        }

        break;
    }
    case NDTRawData:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            // print the first element seperately so formatting is correct
            char val = 0;
            src->Get(val, NCTNone);
            PRINT("{ %02x", (unsigned char)val);

            READ_MSG_VAL_TO_BUFFER(std::vector<char>, .push_back(val));

            for (int i = 1; i < m; i++) {
                src->Get(val, NCTNone);
                PRINT(", %02x", (unsigned char)val);

                READ_MSG_VAL_TO_BUFFER(std::vector<char>, .push_back(val));
            }

            PRINT(" }\n");
        }
        else {
            PRINT("\n");
        }
        break;
    }
    case NDTTime:
    {
        int val;
        src->Get(val, NCTNone);
        PRINT("%i\n", val);

        READ_MSG_VAL_TO_BUFFER(int, = val);

        break;
    }
    case NDTVector:
    {
        vec3 val;
        src->Get(val, compression);
        PRINT("{x: %s, y: %s, z: %s}\n", get_float_truncated(val.x).c_str(), get_float_truncated(val.y).c_str(), get_float_truncated(val.z).c_str());

        READ_MSG_VAL_TO_BUFFER(vec3, = val);

        break;
    }
    case NDTMatrix:
    {
        matrix3x3 val;
        src->Get(val, compression);
        PRINT("{ aside{x: %s, y: %s, z: %s}, up{x: %s, y: %s, z: %s}, dir{x: %s, y: %s, z: %s} }\n", get_float_truncated(val.m_aside.x).c_str(), get_float_truncated(val.m_aside.y).c_str(), get_float_truncated(val.m_aside.z).c_str(), get_float_truncated(val.m_up.x).c_str(), get_float_truncated(val.m_up.y).c_str(), get_float_truncated(val.m_up.z).c_str(), get_float_truncated(val.m_dir.x).c_str(), get_float_truncated(val.m_dir.y).c_str(), get_float_truncated(val.m_dir.z).c_str());
       
        READ_MSG_VAL_TO_BUFFER(matrix3x3, = val);
        
        break;
    }
    case NDTBoolArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);

        if (!m) {
            PRINT("\n");
            break;
        }

        if (compression == NCTDefault) {
            int numbytes = (m + 7) >> 3;

            unsigned char* bits = (unsigned char*)src->GetRaw(numbytes);

            PRINT("{ %i", ((bits[0 >> 3] & (1 << (0 & 7))) != 0));

            READ_MSG_VAL_TO_BUFFER(std::vector<char>, .push_back((bits[0 >> 3] & (1 << (0 & 7))) != 0))

            for (int j = 1; j < m; j++)
            {
                bool val = (bits[j >> 3] & (1 << (j & 7))) != 0;
                PRINT(", %i", val);

                READ_MSG_VAL_TO_BUFFER(std::vector<char>, .push_back((bits[j >> 3] & (1 << (j & 7))) != 0))
            }
            PRINT(" }\n");
        }
        else {
            bool val;
            src->Get(val, compression);
            PRINT("{ %i", val);

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);
                PRINT(", %i", val);
            }
            PRINT(" }\n");
        }

        break;
    }
    case NDTIntArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            int val;
            src->Get(val, compression);
            PRINT("{ %i", val);

            READ_MSG_VAL_TO_BUFFER(std::vector<int>, .push_back(val));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);
                PRINT(", %i", val);

                READ_MSG_VAL_TO_BUFFER(std::vector<int>, .push_back(val));
            }
            PRINT(" }\n");
        }
        else
            PRINT("\n");

        break;
    }
    case NDTFloatArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            float val;
            src->Get(val, compression);
            PRINT("{ %s", get_float_truncated(val).c_str());

            READ_MSG_VAL_TO_BUFFER(std::vector<float>, .push_back(val));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);
                PRINT(", %s", get_float_truncated(val).c_str());

                READ_MSG_VAL_TO_BUFFER(std::vector<float>, .push_back(val));
            }
            PRINT(" }\n");
        }
        else
            PRINT("\n");

        break;
    }
    case NDTStringArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            char* val = nullptr;
            src->Get(val, compression);

            if (!val)
                break;

            PRINT("{ \"%s\"", val);

            READ_MSG_VAL_TO_BUFFER(std::vector<std::string>, .push_back(std::string(val)));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);

                if (!val)
                    break;

                PRINT(", \"%s\"", val);

                READ_MSG_VAL_TO_BUFFER(std::vector<std::string>, .push_back(std::string(val)));
            }
            PRINT(" }\n");
        }
        else
            PRINT("\n");
        break;
    }
    case NDTStringBArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            char* val = nullptr;
            src->Get(val, compression);

            if (!val)
                break;

            PRINT("{ \"%s\"", val);

            READ_MSG_VAL_TO_BUFFER(std::vector<std::string>, .push_back(std::string(val)));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);

                if (!val)
                    break;

                PRINT(", \"%s\"", val);

                READ_MSG_VAL_TO_BUFFER(std::vector<std::string>, .push_back(std::string(val)));
            }
            PRINT(" }\n");
        }
        else
            PRINT("\n");
        break;
    }
    case NDTSentence:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            char* val = nullptr;
            float pause = 0.f;
            src->Get(val, compression);
            src->Get(pause, compression);

            if (!val)
                break;

            PRINT("{ {\"%s\", %s}", val, get_float_truncated(pause).c_str());

            READ_MSG_VAL_TO_BUFFER(std::vector<Sentence>, .push_back(Sentence(std::string(val), pause)));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);
                src->Get(pause, compression);

                if (!val)
                    break;

                PRINT(", {\"%s\", %s}", val, get_float_truncated(pause).c_str());

                READ_MSG_VAL_TO_BUFFER(std::vector<Sentence>, .push_back(Sentence(std::string(val), pause)));
            }
            PRINT(" }\n");
        }
        else
            PRINT("\n");
        break;
    }
    case NDTObject:
    {
        int subtype = *(int*)format.m_specs.m_def_value;
        auto subformat = &GMsgFormats[subtype];

        // add spacing for submessages
        m_message_print_indentation += "  ";
        PRINT("\n");
        PRINT_SPACED("{\n");
        m_message_print_indentation += "  ";

        decode_message(to, src, subformat, subtype, msg ? msg + format.m_offset : (unsigned char*)-1);

        // now remove the spacing we added
        m_message_print_indentation.resize(m_message_print_indentation.size() - 2);
        PRINT_SPACED("}\n");
        m_message_print_indentation.resize(m_message_print_indentation.size() - 2);

        break;
    }
    case NDTObjectArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);

        if (m) {
            // add spacing for submessages
            m_message_print_indentation += "  ";
            PRINT("\n");
            PRINT_SPACED("{\n");
            m_message_print_indentation += "  ";

            int subtype = *(int*)format.m_specs.m_def_value;
            auto subformat = &GMsgFormats[subtype];

            int count = 0;

            for (int j = 0; j < m; j++) {
                bool not_empty;
                src->Get(not_empty, compression);

                if (!not_empty)
                    continue;

                PRINT_SPACED("{\n");
                m_message_print_indentation += "  ";

                // allocate submsg and push it to the vector
                unsigned char* subbuf = (unsigned char*)-1;
                if (msg) {
                    subbuf = new unsigned char[subformat->m_struct_size];
                    memset(subbuf, 0, subformat->m_struct_size);
                    READ_MSG_VAL_TO_BUFFER(std::vector<unsigned char*>, .push_back(subbuf));
                }

                // decode the encoded message
                decode_message(to, src, subformat, subtype, subbuf);
                
                m_message_print_indentation.resize(m_message_print_indentation.size() - 2);
                PRINT_SPACED("},\n");

                count++;
            }

            // now remove the spacing we added
            m_message_print_indentation.resize(m_message_print_indentation.size() - 2);
            PRINT_SPACED("}\n");
            m_message_print_indentation.resize(m_message_print_indentation.size() - 2);

        }
        else
            PRINT("\n");
        break;
    }
    case NDTObjectSRef:
    {
        bool not_empty;
        src->Get(not_empty, compression);

        if (msg) {
            (*(int64_t*)(msg + format.m_offset - sizeof(int64_t))) = not_empty;
        }

        if (not_empty) {
            int subtype = *(int*)format.m_specs.m_def_value;
            auto subformat = &GMsgFormats[subtype];

            // add spacing for submessages
            m_message_print_indentation += "  ";
            PRINT("\n");
            PRINT_SPACED("{\n");
            m_message_print_indentation += "  ";

            decode_message(to, src, subformat, subtype, msg ? msg + format.m_offset : (unsigned char*)-1);

            // now remove the spacing we added
            m_message_print_indentation.resize(m_message_print_indentation.size() - 2);
            PRINT_SPACED("}\n");
            m_message_print_indentation.resize(m_message_print_indentation.size() - 2);
        }
        else {
            PRINT("\n");
        }
        break;
    }
    case NDTRef:
    {
        NetworkId val;
        src->Get(val, compression);
        PRINT("id %i creator %i\n", val.id, val.creator);

        READ_MSG_VAL_TO_BUFFER(NetworkId, = val);

        break;
    }
    case NDTRefArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);
        if (m) {
            NetworkId val;
            src->Get(val, compression);
            PRINT("{ (id %i creator %i)", val.id, val.creator);

            READ_MSG_VAL_TO_BUFFER(std::vector<NetworkId>, .push_back(val));

            for (int j = 1; j < m; j++)
            {
                src->Get(val, compression);
                PRINT(", (id %i creator %i)", val.id, val.creator);

                READ_MSG_VAL_TO_BUFFER(std::vector<NetworkId>, .push_back(val));
            }

            PRINT(" }\n");
        }
        else
            PRINT("\n");

        break;
    }
    case NDTData: // cba writing anything to the message for this, ive never seen this actually used so meh
    {
        NetworkFormatSpecs specs;
        src->Get((int&)specs.m_type, NCTSmallUnsigned);
        src->Get((int&)specs.m_compression, NCTSmallUnsigned);

        printf("NDATA MESSAGE FUCK %i %i\n", specs.m_type, specs.m_compression);
        return false;

        //PRINT("type (%s - %i) compression (%s) default_val ", NetworkDataTypeNames[specs.m_type], specs.m_type, NetworkCompressionTypeNames[specs.m_compression]);

        if (specs.m_type == NDTData) {
            printf("NDTData type was NDTData\n");
            return false;
        }
        else if (specs.m_type == NDTObject || specs.m_type == NDTObjectArray || specs.m_type ==  NDTObjectSRef) {
            NetworkMessageFormatItem subformat;
            subformat.m_specs.m_type = NDTInteger;
            subformat.m_specs.m_compression = NCTSmallUnsigned;

            if (!decode_message_item(to, src, subformat, nullptr))
                return false;
        }
        else {
            NetworkMessageFormatItem subformat;
            subformat.m_specs.m_type = specs.m_type;
            subformat.m_specs.m_compression = specs.m_compression;
            if (!decode_message_item(to, src, subformat, nullptr))
                return false;

        }

        PRINT("\n");

        break;
    }
    case NDTXUIDArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);

        if (m) {
            int64_t val;
            src->Get(val, compression);

            PRINT("{ %i", val);

            READ_MSG_VAL_TO_BUFFER(std::vector<int64_t>, .push_back(val));

            for (int j = 1; j < m; j++) {
                src->Get(val, compression);

                PRINT(", %i", val);

                READ_MSG_VAL_TO_BUFFER(std::vector<int64_t>, .push_back(val));
            }
        }
        PRINT("}\n");
        break;
    }
    case NDTXNADDR:
    {
        unsigned char* buf = (unsigned char*)src->GetRaw(36);

        if (msg) {
            memcpy(msg + format.m_offset, buf, 36);
        }

        for (int i = 0; i < 36; i++)
            PRINT("%02x ", buf[i]);

        PRINT("\n");

        break;
    }
    case NDTXOnlineStatArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);

        if (m) {
            for (int j = 0; j < m; j++) {
                unsigned char* buf = (unsigned char*)src->GetRaw(16);

                XOnlineStat val;
                memcpy(val.m_stat, buf, 16);

                READ_MSG_VAL_TO_BUFFER(std::vector<XOnlineStat>, .push_back(val));

                PRINT("{ ");

                for (int i = 0; i < 16; i++)
                    PRINT("%02x ", buf[i]);

                PRINT("}, ");
            }
        }
        PRINT("\n");
        break;
    }
    case NDTLocalizedString:
    {
        LocalizedString val;
        src->Get(val, compression);

        PRINT("(type %i id: \"%s\")", val.m_type, val.m_id.c_str());

        READ_MSG_VAL_TO_BUFFER(LocalizedString, = val);

        break;
    }
    case NDTLocalizedStringArray:
    {
        int m;
        src->Get(m, NCTSmallUnsigned);

        if (m) {
            LocalizedString val;
            src->Get(val, compression);

            PRINT("{ (type %i id: \"%s\")", val.m_type, val.m_id.c_str());

            READ_MSG_VAL_TO_BUFFER(std::vector<LocalizedString>, .push_back(val));

            for (int j = 1; j < m; j++) {
                src->Get(val, compression);
                PRINT(", (type %i id: \"%s\")", val.m_type, val.m_id.c_str());

                READ_MSG_VAL_TO_BUFFER(std::vector<LocalizedString>, .push_back(val));
            }

            PRINT(" }\n");
        }
        else
            PRINT("\n");

        break;
    }
    default:
    {
        PRINT_SPACED("INVALID ITEM DATATYPE\n");
        break;
    }
    }

    return ok;
}

void a3parser::print_hex(uint8_t* data, uint16_t len, uint8_t to) {
    printf("[%s]\t", to == TO_CLIENT ? "server" : "client");

    for (int i = 0; i < len; i++)
        printf("%02x ", data[i]);

    printf("\n");
}

void a3parser::print_ascii(uint8_t* data, uint16_t size, uint8_t to) {
    printf("[%s]\t\n", to == TO_CLIENT ? "server" : "client");

    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i) {
        printf("%02X ", ((unsigned char*)data)[i]);
        if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
            ascii[i % 16] = ((unsigned char*)data)[i];
        }
        else {
            ascii[i % 16] = '.';
        }
        if ((i + 1) % 8 == 0 || i + 1 == size) {
            printf(" ");
            if ((i + 1) % 16 == 0) {
                printf("|  %s \n", ascii);
            }
            else if (i + 1 == size) {
                ascii[(i + 1) % 16] = '\0';
                if ((i + 1) % 16 <= 8) {
                    printf(" ");
                }
                for (j = (i + 1) % 16; j < 16; ++j) {
                    printf("   ");
                }
                printf("|  %s \n", ascii);
            }
        }
    }

    printf("\n");
}

void a3parser::print_header(uint8_t* data) {
    ArmaMessageHeader* hdr = (ArmaMessageHeader*)data;
    printf("Length: %i Flags: %x CRC: %x Serial: %i Ack: %i Control1: %i Control2: %i\n", hdr->length, hdr->flags, hdr->crc, hdr->serial, hdr->ack_origin, hdr->c.control1, hdr->c.control2);
}

void a3parser::write_to_packet(NetworkMessageRaw* src, int to) {
    src->m_size = src->m_pos;
    encrypt_message(src, to); // pad the message, calculate the netmessage checksum and do the AES encryption

    auto msg = new NetMessage(src->m_buf, src->m_size, (ArmaMessageHeader*)(src->m_buf - MSG_HEADER_LEN));
    if (to == TO_SERVER) {
        m_parted_to_server = msg;
        write_part_packet(m_parted_to_server);
    }
    else {
        m_parted_to_client = msg;
        write_part_packet(m_parted_to_client);
    }
}

void a3parser::write_part_packet(NetMessage*& msg) {
    auto buf = m_packet_out;

    iphdr* iph = (iphdr*)(buf);
    udphdr* udph = (udphdr*)(uintptr_t(iph) + sizeof(iphdr));
    uint8_t* data = (uint8_t*)(uintptr_t(udph) + sizeof(udphdr));

    int size = msg->m_size;
    int len = size;

    auto& hdr = msg->hdr;

    // needs to get part'd
    if (size > 1348) {
        // I can't get this retarded shit working, just fuck off with parted messages
        printf("Message parting not supported!\n");

        delete msg;
        msg = nullptr;

        return;

        hdr.flags = MSG_VIM_FLAG | MSG_ORDERED_FLAG | MSG_PART_FLAG | MSG_BUNCH_FLAG;

        int delta = size - msg->m_pos;
        len = std::min(delta, 1348); // clamp the length we wanna read

        memcpy(data + MSG_HEADER_LEN, msg->m_data + msg->m_pos, len);
        msg->m_pos += len;

        if (msg->m_pos == size) {
            printf("Closing with pos %i (delta %i)\n", msg->m_pos, len);
            hdr.flags |= MSG_CLOSING_FLAG;
        }
    }
    else {
        // copy the new buffer into the udp datagram (incldue the decrypted arma header)
        memcpy(data + MSG_HEADER_LEN, msg->m_data, len);

        msg->m_pos = len;
    }

    len += MSG_HEADER_LEN;

    hdr.length = len;
    if (hdr.flags & MSG_PART_FLAG)
        hdr.c.control2 = hdr.serial - 1;

    *(ArmaMessageHeader*)(data) = hdr;

    //printf("SENDING MSG: flags: %x ser: %i pred: %i control: %i ack_origin: %i\n", hdr.flags, hdr.serial, hdr.c.control2, hdr.c.control1, hdr.ack_origin);

    encrypt_packet(data); // calculate the arma header checksum scramble the message contents and the arma header

    hdr.serial++;

    int udp_len = len + sizeof(udphdr);
    udph->len = htons(udp_len); // datagram size + udp header size

    int ip_len = udp_len + sizeof(iphdr);
    iph->tot_len = htons(ip_len);

    // now recalculate the udp and ip checksums
    iph->check = 0;
    iph->check = cksum_generic((uint8_t*)iph, sizeof(iphdr), 0);

    udph->check = 0;
    udph->check = get_udp_checksum((unsigned char*)iph);

    // if we read the full message, deletus. 
    if (msg->m_pos == msg->m_size)
    {
        delete msg;
        msg = nullptr;
    }
}

void a3parser::send_packet() {
    auto new_packet = m_packet_out;

    // recalculate the length for the pcap header in case we modified the packet
    auto ip = (iphdr *)(new_packet);
    int len = ntohs(ip->tot_len);

    // "send" / queue the actual packet here?

    int cur = ntohs(ip->id);
    cur++;
    ip->id = htons(cur);
}

bool a3parser::check_crc(uint8_t* buf, uint16_t len) {
    uint32_t crc = *(uint32_t*)(buf + 4);
    *(uint32_t*)(buf + 4) = 0;

    return crc == crc32(0, buf, len);
}

void a3parser::decrypt_packet(uint8_t* buf) {
    if (m_be_message) {
        scramble_header_part1(buf + 2, 2, be_key_table_2, sizeof(be_key_table_2), 0x200u);
        scramble_header_part1(buf + 8, 16, be_key_table_3, sizeof(be_key_table_3), 0x200u);
    }
    else {
        scramble_header_part1(buf + 2, 2, key_table_2, sizeof(key_table_2), 0x200u);
        scramble_header_part1(buf + 8, 16, key_table_3, sizeof(key_table_3), 0x200u);
    }


    scramble_message_contents(buf, m_be_message ? be_key_table_1 : key_table_1);
}

void a3parser::encrypt_packet(uint8_t* buf) {
    uint16_t len = *(uint16_t*)buf;
    *(uint32_t*)(buf + 4) = 0;
    *(uint32_t*)(buf + 4) = crc32(0, buf, len);

    scramble_message_contents(buf, m_be_message ? be_key_table_1 : key_table_1);

    if (m_be_message) {
        scramble_header_part1(buf + 2, 2, be_key_table_2, sizeof(be_key_table_2), 0x200u);
        scramble_header_part1(buf + 8, 16, be_key_table_3, sizeof(be_key_table_3), 0x200u);
    }
    else {
        scramble_header_part1(buf + 2, 2, key_table_2, sizeof(key_table_2), 0x200u);
        scramble_header_part1(buf + 8, 16, key_table_3, sizeof(key_table_3), 0x200u);
    }

}

// i really couldnt be bothered properly reversing this, as it just didnt fucking work when I tried a proper reverse of it, enjoy the ida pseudo paste
bool a3parser::decrypt_message(NetworkMessageRaw* src, int to) {
    int pos_backup = 0; 
    char v7 = 0;
    int size; 
    int v10; 
    unsigned int length;
    unsigned int v13; 
    uint8_t *buf;
    int v15;
    int crc_pos = 0; 
    bool v18; 
    int16_t v19;
    int64_t v20;
    int64_t incoming_csum;
    char v23 = 0;
    char v24 = 0; 
    uint16_t csum;
    char v27 = 0; 
    char out;
    unsigned char iv[16];

    pos_backup = src->m_pos;
    size = src->m_size;

    v10 = (size & 0xF) - 1;
    if (v10 < 0)
        return 0;


    length = size - (size & 0xF);
    src->m_pos = size - 1;
    src->Get(out, NCTNone);

    if (v10 <= 0)
    {
        if (out >= 0)
            v13 = out & 0xF;
        else
            v13 = 0;
    }
    else
    {
        v13 = (unsigned int)(uint8_t)out >> 4;
        v7 = 16 * out | (out >> 4) & 0xF;
        if ((out & 0xF) != v10)
            return 0;
    }

    buf = src->m_buf;
    src->m_pos = pos_backup;

    if (to == TO_SERVER) {
        memcpy(iv, client_iv, 16);
        aes_crypt_cbc(m_be_message ? &m_be_client_dec : &m_client_dec, AES_DECRYPT, length, iv, src->m_buf, src->m_buf);
    }
    else {
        memcpy(iv, server_iv, 16);
        aes_crypt_cbc(m_be_message ? &m_be_server_dec : &m_server_dec, AES_DECRYPT, length, iv, src->m_buf, src->m_buf);
    }

    if (v13 > 0xF)
        return 0;

    v15 = length - v13;
    if (v15 < 4)
        return 0;

    pos_backup = src->m_pos;
    crc_pos = v15 - 3;
    src->m_pos = crc_pos;

    src->Get(v24, NCTNone);
    src->Get(v23, NCTNone);
    src->Get(v27, NCTNone);

    if (v10 <= 0)
    {
        if (v13)
        {
            if ((unsigned int)(uint8_t)v27 >> 4 != v13)
                return 0;
            goto LABEL_24;
        }
        v18 = (v27 & 0xF) == 8;
    }
    else
    {
        v18 = v27 == v7;
    }
    if (!v18)
        return 0;
LABEL_24:
    v19 = (uint8_t)v24;
    v20 = (uint16_t)((uint8_t)v23 << 8);
    src->m_pos = pos_backup;
    incoming_csum = (uint16_t)(v19 | v20);
    buf = src->m_buf;
    csum = crc16(buf, crc_pos);

    if (csum != (uint16_t)incoming_csum)
    {
        printf("CRC16 failed: calculated %x incoming %x\n", csum, incoming_csum);
        return 0;
    }
    return 1;
}

// basically how I implemented this since pasting the ida pseudo didnt work out (look into this more later) is that I FORCE it to take a specific path in the decrypt function to make sure it passes & decrypts properly
bool a3parser::encrypt_message(NetworkMessageRaw* src, int to) {
    int len = src->m_pos;
    if (len < 4)
        return 0;

    auto buf = src->m_buf;

    // pad it until 3 "before" a multiple of 16
    int addlen = 0x10 - ((len + 3) % 0x10);
    src->m_pos += addlen;

    uint16_t checksum = crc16(buf, src->m_pos);

    src->Put((char)LOBYTE(checksum), NCTNone);
    src->Put((char)HIBYTE(checksum), NCTNone);

    // force "v18 = (v27 & 0xF) == 8;" to pass
    src->Put((char)8, NCTNone);

    unsigned char iv[16];
    if (to == TO_SERVER) {
        memcpy(iv, client_iv, 16);
        aes_crypt_cbc(m_be_message ? &m_be_client_enc : &m_client_enc, AES_ENCRYPT, src->m_pos, iv, src->m_buf, src->m_buf);
    }
    else {
        memcpy(iv, server_iv, 16);
        aes_crypt_cbc(m_be_message ? &m_be_server_enc : &m_server_enc, AES_ENCRYPT, src->m_pos, iv, src->m_buf, src->m_buf);
    }

    src->Put((char)0, NCTNone);

    src->m_size = src->m_pos;

    return 1;
}