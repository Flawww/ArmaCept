#pragma once
#include "pch.h"
#include "networkmessage.h"
#include "netmessage_structs.h"

// i just started writing some bs, this shit is fucking gay fuck


enum vehicle_types {
    MAN_OBJECT,
    TANK_OBJECT,
    TURRET_OBJECT,
    CAR_OBJECT,
    PLANE_OBJECT,
    HELICOPTER_OBJECT,
    SHIP_OBJECT,
    PARACHUTE_OBJECT,

    VEHICLE_TYPE_COUNT
};

struct network_vehicle {
    network_vehicle(int _type, NetworkId _id, vec3 _pos, int _side, NetworkId _driver, NetworkId _copilot = NetworkId(), std::vector<NetworkId> _mancargo = std::vector<NetworkId>(), network_vehicle* _owner = nullptr) {

    }

    // all object types
    int type;
    std::string type_name;
    NetworkId id;
    vec3 position;
    int side;


    NetworkId driver;
    NetworkId copilot;
    std::vector<NetworkId> man_cargo;
    std::vector<NetworkId> turrets;

    // gunner turret
    network_vehicle* owner_vehicle;
};

struct network_unit {
    network_unit(MessageUpdateMan* upd) {
        id.creator = upd->_objectCreator;
        id.id = upd->_objectId;

        position = upd->_objectPosition;
        side = upd->_targetSide;
        remote_player = upd->_remotePlayer;

        vehicle = nullptr;
    }

    NetworkId id;
    vec3 position;
    int side;
    int remote_player;
    network_vehicle* vehicle;
};

struct network_player {
    network_player(MessageLogin* login) {
        dpnid = login->_dpnid;
        playerid = login->_playerid;
        steamid = login->_steamID;
        name = login->_name;

        unit = nullptr;
    }

    int dpnid;
    int playerid;
    int64_t steamid;
    std::string name;
    network_unit* unit;
};

// lambda to combine the netid and creator to a single variable (for map lookups)
static auto combine_netid = [](const NetworkId& other) -> int64_t { return (int64_t)other.id << 32 | other.creator; };

class network_hack {
public:
    network_hack();
    ~network_hack();
    
private:

    // all the actual players
    std::unordered_map<int, network_player> m_players;
    network_player* m_localplayer;

    // all units / vehicles / etc on the map
    std::unordered_map<NetworkId, network_vehicle*, decltype(combine_netid)> m_vehicles;
};