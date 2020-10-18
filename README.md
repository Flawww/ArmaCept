## ArmaCept
A pretty complete framework for for developing network hacks for the game ![ARMA 3](https://arma3.com)

This was my first dabble with doing network-level cheating and it was a lot of fun. Because of ARMA's clientside authorative nature a network hack is extremely powerful and you can accomplish basically anything you could internally. 

## Setup
To be able to use this properly you need an extra device running linux for which you can route your network connection through. (Alternatively use something like ARP-Spoofing).
The way it's done here is using NFQUEUE (libnetfilter_queue) to inspect all packets.

The setup I used was: 
Connect main PC to my laptop which is running linux (and will be running the hack). The laptop was then connected to WiFi, and that WiFi connection was routed through to the PC. At this point you can simply set up the iptables to make NFQUEUE intercept the packets. Refer to `start.sh`

## The Framework
ARMA has a LOT of different netmessages, luckily they all have very descriptive names. Take a look `netmessages.h` for a complete list of them. 
For the whole list of netmessages, complete with the associated datastructure for that message, look at `netmessage_structs.h`
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
A full log of all netmessages sent in a quick session (on a more or less empty server) can be seen in the file `full_server_log.txt`

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

# Entitylist
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
The packets are encrypted in 3 stages. First of all, the message body is encrypted with AES, then the whole message is scrambled by using something that seems to be their in-house "scrambler", and finally the header is scrambled. The various keys and keytables are quite easy to find in memory (And it completely doable with BattlEye disabled!). The current keytables in the repo are **OUTDATED**, so I'll leave finding those keytables as an exercise to the reader.
A tip for where to begin is breakpointing the recvfrom function and looking around (Pay special attention to the thisptr of the caller)
