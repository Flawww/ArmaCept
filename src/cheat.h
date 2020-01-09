#pragma once
#include "pch.h"
#include "networkmessage.h"
#include "netmessage_structs.h"
#include "network_objects.h"

struct network_player {
    network_player(MessageLogin* login) {
        m_dpnid = login->_dpnid;
        m_playerid = login->_playerid;
        m_steamid = login->_steamID;
        m_name = login->_name;

        m_object = NetworkId();
    }

    int m_dpnid; // some pseudo id used to reference players
    int m_playerid; // used for stuff like "creator"
    int64_t m_steamid;
    std::string m_name;
    NetworkId m_object; // The object this player controls
};

// lambda to combine the netid and creator to a single variable (for map lookups)
static auto netid64 = [](const NetworkId& other) -> int64_t { return (int64_t)other.id << 32 | (int64_t)other.creator; };

class network_hack {
public:
    void add_object(network_object obj);
    void delete_object(NetworkId id);
    network_object* get_object(NetworkId id);
    network_player* get_player(int dpnid);

    // "update" functions 
    void update_object(int type, NetworkId id, vec3 pos, int side = -1);
    void update_controllable(int type, NetworkId id, vec3 pos, int side, int remote);
    void update_vehicle(int type, NetworkId id, vec3 pos, int side, NetworkId driver, NetworkId copilot, std::vector<NetworkId> passengers);
    void update_turret(MessageUpdateTurret* msg);

    // position updates
    void update_position_general(NetworkId id, vec3 pos, matrix3x3 orient, vec3 speed);
    void update_position_turret(MessageUpdatePositionTurret* msg);

    // used to either completely reset or to reset the entitylist
    void full_reset();
    void object_reset();

    // all the actual players
    std::unordered_map<int, network_player> m_players;
    NetworkId m_localplayer;

        // all units / vehicles / etc on the map
    std::unordered_map<int64_t, network_object> m_objects;

private:

};