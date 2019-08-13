#pragma once
#include "pch.h"
#include "network_key_tables.h"
#include "networkmessage.h"
#include "aes.h"
#include "format_init.h"
#include "message_callbacks.h"

#define PRINTING

// macros are evil blah blah blah fuck you
#ifdef PRINTING
#define PRINT(...) if (!m_enable_printing) { fprintf(m_out_file, __VA_ARGS__); }
#define PRINT_SPACED(...) if (!m_enable_printing) { PRINT("%s", m_message_print_indentation.c_str()); PRINT(__VA_ARGS__) }
#else
#define PRINT(...)
#define PRINT_SPACED(...)
#endif

#define SET_CALLBACK(to, type) SET_CALLBACK2(to, Network##type, type##Callback);
#define SET_CALLBACK2(to, type, fn) m_callbacks[to][type] = fn;
#define ENABLE_PRINT(to, type) m_log_message[to][type] = true;

#define READ_MSG_VAL_TO_BUFFER(type, init) if (msg) { (*(type*)(msg + format.m_offset))init; }
#define WRITE_MSG_VAL_FROM_BUFFER(type, compression, accessor) src->Put((*(type*)(msg + format.m_offset))accessor, compression);
#define CREATE_VAR_FROM_BUFFER(type) type val = *(type*)(msg + format.m_offset);

#define __PAIR__(high, low) (((uint32_t)(high)<<sizeof(high)*8) | low)

#define UDP_PROTOCOL 0x11

enum {
    TO_CLIENT,
    TO_SERVER
};

struct msg_queue_item {
    msg_queue_item(int type, unsigned char* msg) { m_type = type; m_msg = msg; }

    int m_type;
    unsigned char* m_msg;
};

template <typename t>
struct threaded_queue {
    std::mutex mtx;
    std::queue<t> q;
};

struct IpPortInfo {
    IpPortInfo() {};

    IpPortInfo(uint8_t* src, uint8_t* dst) {
        memcpy(m_srcip, src, 4);
        memcpy(m_dstip, dst, 4);
        m_dst_port = 0;
        m_src_port = 0;
    }

    uint8_t m_srcip[4];
    uint8_t m_dstip[4];
    uint16_t m_dst_port;
    uint16_t m_src_port;
};

class a3parser {
public:
    a3parser(): m_client_ports_set(false), m_server_ports_set(false), m_parted_to_client(nullptr), m_parted_to_server(nullptr) { };
    a3parser(/*uint8_t* client_ip, */uint8_t* server_ip/*, uint8_t* victimmac, uint8_t* targetmac, const uint8_t* my_mac*/);

    ~a3parser() { 
        fclose(m_out_file); 

        if (m_parted_to_client) { 
            delete m_parted_to_client; 
            m_parted_to_client = nullptr; 
        } 

        if (m_parted_to_server) { 
            delete m_parted_to_server; 
            m_parted_to_server = nullptr; 
        }
    };

    // starts parsing the packet (lol)
    bool parse_packet(uint8_t* pkt);

    // functions to change a message "in place"
    bool remove_cur_message(NetworkMessageRaw* src);
    bool reencode_message(NetworkMessageRaw* src, int type, unsigned char* msg);

    void queue_message_to_server(int type, unsigned char* msg);
    void queue_message_to_client(int type, unsigned char* msg);

    void setup_callbacks();
    void setup_printing();

    static std::string get_float_truncated(float f) {
        std::ostringstream out;
        out.precision(2);
        out << std::fixed << f;

        return out.str();
    }

public:

    IpPortInfo m_server_info;
    IpPortInfo m_client_info;

private:
    void print_hex(uint8_t* data, uint16_t len, uint8_t to);
    void print_ascii(uint8_t* data, uint16_t len, uint8_t to);
    void print_header(uint8_t* data);
    bool check_crc(uint8_t* data, uint16_t len);

    // internal encoding functions
    bool encode_message(NetworkMessageRaw* src, int type, unsigned char* msg);
    bool encode_message_item(NetworkMessageRaw* src, NetworkMessageFormatItem format, unsigned char* msg);

    // decoding/processing
    bool process_messages(NetworkMessageRaw* src, int to);
    bool decode_message(int to, NetworkMessageRaw* src, NetworkMessageFormat* format, int type, unsigned char* msg = nullptr);
    bool decode_message_item(int to, NetworkMessageRaw* src, NetworkMessageFormatItem format, unsigned char* msg);

    void process_queued_messages(NetworkMessageRaw* src, threaded_queue<msg_queue_item>& queue);

    void encrypt_packet(uint8_t* buf);
    void decrypt_packet(uint8_t* buf);
    bool encrypt_message(NetworkMessageRaw* src, int to);
    bool decrypt_message(NetworkMessageRaw* src, int to);

    void send_packet();

    void write_to_packet(NetworkMessageRaw* src, int to);
    void write_part_packet(NetMessage*& net_msg);

private:
    threaded_queue<msg_queue_item> m_messages_to_client;
    threaded_queue<msg_queue_item> m_messages_to_server;

    // netmessages to send (used for messages which needs parting)
    NetMessage* m_parted_to_client;
    NetMessage* m_parted_to_server;

    // saved ptr to the actual original packet
    uint8_t* m_packet_out;

    // aes (d)encryption stuff
    aes_context m_client_dec;
    aes_context m_client_enc;
    aes_context m_server_dec;
    aes_context m_server_enc;

    // logging shit
    bool m_enable_printing;
    FILE* m_out_file;
    bool m_log_message[2][NETWORK_MESSAGE_COUNT];

    // callbacks that gets called when processing the "callbacked" message
    MsgCallback m_callbacks[2][NETWORK_MESSAGE_COUNT];

    // set these when we have set the src+dst ip and ports
    bool m_client_ports_set;
    bool m_server_ports_set;

    // saves the indentention (for correctly formatting messages we log)
    std::string m_message_print_indentation;

    // just some info about the actual networking shite
    uint8_t m_my_mac[6];
    uint8_t m_victimmac[6];
    uint8_t m_targetmac[6];
};

extern a3parser* g_parser;