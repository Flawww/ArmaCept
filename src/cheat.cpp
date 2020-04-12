#include "pch.h"
#include "cheat.h"
#include "a3parser.h"

void network_hack::add_object(network_object obj) {
    int64_t hash = netid64(obj.m_id);

    //printf("Adding object %i:%i (%lx)\n", obj.m_id.creator, obj.m_id.id, hash);
    m_objects.emplace(hash, obj);
}

// delete the object and perform cleanup if needed
// (TODO: How shold we handle AskForDelete or if parent vehicle of Turret gets removed?)
void network_hack::delete_object(NetworkId id) {
    auto it = m_objects.find(netid64(id));
    if (it == m_objects.end()) {
        //printf("Tried deleting non-existant object\n");
        return;
    }

    auto obj = &it->second;

    if (obj->is_controllable()) {
        int dpnid = obj->m_entity_variables.m_controllable_variables.m_remote_player;
        if (dpnid != 1) {
            auto player = get_player(dpnid);
            if (player)
                player->m_object = NetworkId(); // reset the players' "object" if we are removing the entity they are controlling
        }
    }

    // iterate all attached turrets and also remove them
    // DISCLAIMER: I am not sure about this, they might get seperately removed? TODO: Test
    for (auto& turret_id : obj->m_turrets) {
        delete_object(turret_id);
    }

    // Debug print to check if turret is ever attached to non-vehicle entity TODO: Remove
    if (obj->m_turrets.size() && !obj->is_vehicle())
        printf("Non-vehicle \"%s\" has %i turrets!", obj->m_entity_variables.m_type_name.c_str(), obj->m_turrets.size());

    // finally delete the actual entity
    m_objects.erase(it);
}

network_object* network_hack::get_object(NetworkId id) {
    if (!id.valid()) // if its not a valid id don't bother to look for it
        return nullptr;

    auto it = m_objects.find(netid64(id));
    if (it == m_objects.end())
        return nullptr;

    return &it->second;
}

network_player* network_hack::get_player(int dpnid) {
    if (dpnid == 1) // 1 means AI-controlled
        return nullptr;

    auto it = m_players.find(dpnid);
    if (it == m_players.end())
        return nullptr;

    return &it->second;
}

void network_hack::update_object(int type, NetworkId id, vec3 pos, int side) {
    auto obj = get_object(id);
    if (!obj) {
        //printf("Recieved update for non-existanst entity\n");
        return;
    }

    obj->m_object_type = type;
    obj->m_pos = pos;
    obj->m_entity_variables.m_targetside = side; // for "objects this will be -1, otherwise we want to set it"
}

void network_hack::update_controllable(int type, NetworkId id, vec3 pos, int side, int remote) {
    // this is just for testing for a bit - REMOVE LATER
    if (remote < 1)
        printf("0 or neg remoteplayer: %i\n", remote);

    auto obj = get_object(id);
    if (!obj) {
        //printf("Recieved update for non-existanst entity\n");
        return;
    }

    obj->m_object_type = type;
    obj->m_pos = pos;
    obj->m_entity_variables.m_targetside = side;

    // check if the remote player has changed and act accordingly
    int old_remote = obj->m_entity_variables.m_controllable_variables.m_remote_player;
    if (old_remote != remote) {
        // remove the object from the old remote player
        auto old_player = get_player(old_remote);
        if (old_player)
            old_player->m_object = NetworkId();
        
        // add it to the new player
        auto new_player = get_player(remote);
        if (new_player)
            new_player->m_object = id;

        obj->m_entity_variables.m_controllable_variables.m_remote_player = remote;
    }
}

void network_hack::update_vehicle(int type, NetworkId id, vec3 pos, int side, NetworkId driver, NetworkId copilot, std::vector<NetworkId> passengers) {
    auto obj = get_object(id);
    if (!obj) {
        //printf("Recieved update for non-existanst entity\n");
        return;
    }
    
    obj->m_object_type = type;
    obj->m_pos = pos;
    obj->m_entity_variables.m_targetside = side;
    auto& veh = obj->m_entity_variables.m_vehicle_variables;

    auto& old_driver = veh.m_driver;
    if (old_driver != driver) {
        auto old_driver_obj = get_object(old_driver);
        if (old_driver_obj)
            old_driver_obj->m_entity_variables.m_parent_vehicle.reset();
        
        auto new_driver_obj = get_object(driver);
        if (new_driver_obj)
            new_driver_obj->m_entity_variables.m_parent_vehicle = id;

        // now override the driver with the new one
        old_driver = driver;
    }

    auto& old_copilot = veh.m_copilot;
    if (old_copilot != copilot) {
        auto old_copilot_obj = get_object(old_copilot);
        if (old_copilot_obj)
            old_copilot_obj->m_entity_variables.m_parent_vehicle.reset();

        auto new_copilot_obj = get_object(copilot);
        if (new_copilot_obj)
            new_copilot_obj->m_entity_variables.m_parent_vehicle = id;

            // override the copilot of the "vehicle" struct
            old_copilot = copilot;
    }

    auto& old_passengers = veh.m_passenger_slots;
    if (old_passengers.size() != passengers.size()) {
        // if the number of mancargo changed redo all of the vector
        for (auto& passenger_id : old_passengers) {
            auto passenger_obj = get_object(passenger_id);
            if (passenger_obj) 
                passenger_obj->m_entity_variables.m_parent_vehicle.reset();
        }

        for (auto& passenger_id : passengers) {
            auto passenger_obj = get_object(passenger_id);
            if (passenger_obj)
                passenger_obj->m_entity_variables.m_parent_vehicle = id;
        }

        old_passengers = passengers;
    }
    else {
        // if number of mancargo is still the same just diff' em
        for (int i = 0; i < passengers.size(); i++) {
            auto& old_passenger_id = old_passengers.at(i);
            auto& passenger_id = passengers.at(i);

            // only bother updating anything if its actually diffed
            if (old_passenger_id != passenger_id) {
                auto old_passenger_obj = get_object(old_passenger_id);
                if (old_passenger_obj)
                    old_passenger_obj->m_entity_variables.m_parent_vehicle.reset();

                auto new_passenger_obj = get_object(passenger_id);
                if (new_passenger_obj)
                    new_passenger_obj->m_entity_variables.m_parent_vehicle.reset();

                old_passenger_id = passenger_id;
            }
        }
    }
}

void network_hack::update_turret(MessageUpdateTurret* msg) {
    auto id = NetworkId(msg->_objectCreator, msg->_objectId);
    auto turret_obj = get_object(id);
    if (!turret_obj) {
        //printf("Recieved update for non-existant turret\n");
        return;
    }

    turret_obj->m_object_type = TURRET_OBJECT;

    // Debug print, just making sure the parent vehicle of a turret can not change
    if (turret_obj->m_turret_variables.m_owner != msg->_owner)
        printf("Turret owner vehicle changed, yikes.\n");

    auto owner_obj = get_object(msg->_owner);
    if (!owner_obj) {
        //printf("Owner vehicle of turret not found\n");
        return;
    }

    auto& old_gunner_id = turret_obj->m_turret_variables.m_gunner;
    if (old_gunner_id != msg->_gunner) {
        auto old_gunner_obj = get_object(old_gunner_id);
        if (old_gunner_obj)
            old_gunner_obj->m_entity_variables.m_parent_vehicle.reset();

        auto new_gunner_obj = get_object(msg->_gunner);
        if (new_gunner_obj) {
            // set the new gunners parent vehicle to the owner vehicle of the turret
            new_gunner_obj->m_entity_variables.m_parent_vehicle = owner_obj->m_id;
        }

        old_gunner_id = msg->_gunner;
    }

    turret_obj->m_pos = msg->_objectPosition;
}

void network_hack::update_position_general(NetworkId id, vec3 pos, matrix3x3 orient, vec3 speed) {
    auto obj = get_object(id);
    if (!obj) {
        return;
    }

    obj->m_pos = pos;
    obj->m_entity_variables.m_orientation = orient;
    obj->m_entity_variables.m_speed = speed;
}

void network_hack::update_position_turret(MessageUpdatePositionTurret* msg) {
    auto turret_obj = get_object(NetworkId(msg->_objectCreator, msg->_objectId));
    if (!turret_obj) {
        //printf("Tried updating position for non-existant turret\n");
    }
}

// used to either completely reset or to reset the entitylist
void network_hack::full_reset() {
    m_localplayer.reset();
    m_players.clear();
    m_objects.clear();
}

void network_hack::object_reset() {
    m_objects.clear();
}

