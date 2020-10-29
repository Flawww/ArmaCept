# ArmaCept
A pretty complete framework for developing network hacks for the game [ARMA 3](https://arma3.com)

This was my first dabble with network-level cheating and it was a lot of fun. Because of ARMA's clientside authorative nature, a network hack is extremely powerful and you can accomplish basically anything you could internally. 

## Setup
To be able to use this properly you need an extra device running linux which you can route your network connection through. (Alternatively use something like ARP-Spoofing).
The way it's done here is using NFQUEUE (libnetfilter_queue) to inspect all packets.

The setup I used was: 
Connect main PC to my laptop which is running linux (and will be running the hack). The laptop was then connected to WiFi, and that WiFi connection was routed through to the PC. At this point you can simply set up the iptables to make NFQUEUE intercept the packets. Refer to [start.sh](start.sh)

## The Framework
ARMA has a LOT of different netmessages, luckily they all have very descriptive names. Take a look [netmessages.h](src/netmessages.h) for a complete list of them. 
For the whole list of netmessages, complete with the associated datastructure for that message, look at [netmessage_structs.h](src/netmessage_structs.h)
The name of the message along with the struct should be plenty of info about what's going on, for instance:
```cpp
struct MessageChat {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::string _name;
    std::string _text;

    MessageChat() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};
```
For more information about a certain message, you can add printing for that message in `a3parser::setup_printing`
A full log of all netmessages sent in a quick session (on a more or less empty server) can be seen in the file [full_server_log.txt](full_server_log.txt)

For setting up a callback for a certain message, add it in `a3parser::setup_callbacks`
I already have some example callbacks set up, look at those to get see how the messages should be handled. 
Some examples:
* Force daytime 
```cpp
void MessageWeatherUpdateCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageWeatherUpdate*)buf;

    // force daytime
    msg->_worldTime = 0.f + (0.000012 * 114);
    msg->reencode_message(src);

    delete msg;
}
```
* Increase outgoing damage, decrease incoming
```cpp
void MessageAskForApplyDoDamageCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageAskForApplyDoDamage*)buf;

    if (to == TO_SERVER) {
        msg->_damage *= 5.f;
        for (auto& it : msg->_hits) {
            it *= 5.f;
        }
        msg->reencode_message(src);
    }
    else {
        msg->_damage *= 0.3f;
        for (auto& it : msg->_hits) {
            it *= 0.3f;
        }
        msg->reencode_message(src);
    }

    delete msg;
}
```

### Entitylist
Because the fact that we are on the network level, we can't access the entitylist of the game, and we have to keep track of all the entities and objects manually by parsing the messages that transmit this information (including the positions and all other information about objects). This is already set up, so you can simply use the entity list in from `g_cheat`
I recommend looking at `cheat.cpp` and `message_callbacks.cpp` to understand how this works.

Example of using it in practice to throw a specific player using the *AddImpulse* message
```cpp
	// in MessageChatCallback
        if (!msg->_text.find("_oof")) { // if chat message includes _oof
            auto name = msg->_text.substr(5); // get contents

            // loop all players and find the one we specified, yeet.
            for (auto& it : g_cheat->m_players) {
                if (!it.second.m_name.find(name)) {
                    auto impulse = new MessageAskForAddImpulse(); 
                    impulse->_force = vec3(0.f, 1000000.f, 0.f); // throw them
                    impulse->_torque = vec3();
                    impulse->_vehicle = it.second.m_object;

                    impulse->queue_message(TO_SERVER); // send the impulse message

                    break;
                }
            }
            g_parser->remove_cur_message(src); // Removes the message, it will never be sent to the server.
        }
```

## Encryption
Netmessage/packet encryption is done in 3 layers in ARMA 3. 
For decryption (encryption is the same but reverse obviously):

### Layer 1 and 2 (Scrambling)

In the function that calls *recvfrom* (which for the record is a member of the NetPeerUDP class) you will spot the following block of code

![recvfrom](https://i.imgur.com/kCBeqYr.png)

as can be seen here, it first (un)scrambles the header, and then goes on to (un)scramble the message itself. By inspecting the header scramble function closer we see

![scramblin](https://i.imgur.com/mf5tDxt.png)

and you guessed it! Those members that it passes into these functions are the keytables (and size of the keytables) for the header!
Similarly the function that scrambles the message contents also reads from the netpeer object to get the keytable used for it.

So to find these keytables you can simply break in any of the NetPeerUDP functions and inspect the thisptr to find the keytables you are looking for.

For a rebuilt version of the scrambling functions, look at [message_scrambler.h](src/message_scrambler.h)

### Layer 3 - AES (Message encryption)

This part was harder to find when getting started since the Virtual Reality engine uses a lot of virtual calls, and the netmessages are handled in a queue so you can not simply follow the execution.

The message encryption/decryption is done by a couple of the members of the class *NetworkEncryptorClient* and *NetworkEncryptorServer*.

![encryptor](https://i.imgur.com/VPGnFmo.png)

These functions are responsible for more than simply crypting with AES. They pad the messages with a random amount of random bytes, I assume to make finding patterns when inspecting packets harder (?), they also perform some verification by CRC16'ing the whole message etc. Those functions rebuilt can be found 
[here](https://github.com/Flawww/ArmaCept/blob/master/src/a3parser.cpp#L1574)

These functions also call into functions which looks somewhat like this

![aescrypt](https://i.imgur.com/NT0p3m3.png)

which is quite easy to recognize it being AES.
Easiet way to find the keys here would again be placing breakpoints and inspecting the arguments (especially the second arg, RDX).


I haven't looked into how these keys are derived, but they do change on every game update so I assume it uses the version alongside some other information to derive them, if someone finds out, please let me know :)

## Updating/Dumping netmessage names and structs for updating
ARMA helps us with this and makes it a breeze. There is a function CreateNetworkMessage that takes an int as argument, this constructs an object of the type of network message you pass into it. To see what the highest number is, just look at the switch case in the function.

You can simply call this function for each number that has an associated message and then get the name of the message by looking at the RTTI of the object you get back since it will contain the vtable of the message.

```cpp
const char* c_network_dumper::get_rtti_name(uintptr_t module_base, void* vtbl) {
    auto addr = *(uintptr_t*)(uintptr_t(vtbl) - sizeof(uintptr_t));

    auto class_hierarchy = *(int32_t*)(addr + 0x10);
    auto hierarchy_ptr = module_base + class_hierarchy;
    auto array_offset = *(int32_t*)(hierarchy_ptr + 0xC);
    auto array_ptr = module_base + array_offset;

    auto descriptor_offset = *(int32_t*)(array_ptr);
    auto descriptor_ptr = module_base + descriptor_offset;

    auto typedescriptor_offset = *(int32_t*)(descriptor_ptr);
    auto typedescriptor_ptr = module_base + typedescriptor_offset;

    auto name = (const char*)(typedescriptor_ptr + 0x14);
    
    auto len = strlen(name);
    auto rtti_name = strdup(name);
    rtti_name[len - 2] = 0; // -2 as to not include the @@ characters that RTTI includes

    return rtti_name;
}
   
// in the dump func:

for (int i = 0; i < m_networkmessage_count; i++) {
    void* msg = create_netmsg(i); // [E8 *? ? ? ?] 48 8B 0C FB
    void* vtbl = *(void**)msg;
 
    const char* name = get_rtti_name(g_modules[ARMA], vtbl);
    printf("%s\n", name);
    free(name);
}
```

### Structs with full names
Dumping the structs (with the real name of the member variables) is going to be a bit harder. Luckily, ARMA has a lot of "pseudo"-reflection with this, which allows us to get the proper names for everything.

First we're going to need to define some structs
```cpp
struct NetworkFormatSpecs {
    NetworkDataType m_type;
    NetworkCompressionType m_compression;
    void* m_def_value;
};

struct NetworkMessageFormatItem {
    c_armastring* m_name; // name of the item ("reflection", gives us the name the game actually uses for this member)
    NetworkFormatSpecs m_specs; // specs of this item
    int m_offset;
    char pad_001C[4];
};

class NetworkMessageFormat {
public:
    void* vtbl;
    c_autoarray<NetworkMessageFormatItem> m_items;
};
```

Click here to find the definitions for: [NetworkDataType](https://github.com/Flawww/ArmaCept/blob/master/src/networkmessage.h#L224) or [NetworkCompressionTypes](https://github.com/Flawww/ArmaCept/blob/master/src/networkmessage.h#L125)

The game sets up a global variable 
```cpp
// can be found with: 7D 0F [48 8D 0D *? ? ? ?] 48 63 C2
NetworkMessageFormat* g_MsgFormats[NETWORK_MESSAGE_COUNT];
```

Now to dump the struct, we can simply access the message we want to dump with its index, loop through the AutoArray for the items this struct (format*) has, and format it all nicely. It's worth noting that there are some recursion going on, so you want to make sure you only dump them once/solve for dependencies properly so you don't get stuck in infinite recursion lol

And there we go, now we got a nicely formatted struct for a netmessage with its proper names like its set up in the game and get something like below (And it also gives us information on how we should parse this format with the specified compression method on the network level, but that is another subject)
```cpp
struct MessageAskForApplyDoDamage {
    NetworkId _who;
    NetworkId _owner;
    NetworkId _shotInstigator;
    std::string _ammo;
    std::string _weapon;
    float _damage;
    std::vector<float> _hits;
    bool _direct;
};
```
