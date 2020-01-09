#pragma once
#include "pch.h"
#include "networkmessage.h"
#include "netmessage_structs.h"

enum vehicle_types {
    OBJECT_OBJECT,
    TURRET_OBJECT,
    SIMPLE_OBJECT,
    VEHICLE_OBJECT, // generic "vehicle" - stuff like storage boxes and editor items
    
    // controllables
    INVISIBLE_OBJECT, // usually stuff like Logic entities
    MAN_OBJECT,
    ANIMAL_OBJECT,
    
    // explicit driveable vehicles
    TANK_OBJECT,
    CAR_OBJECT,
    PLANE_OBJECT,
    HELICOPTER_OBJECT,
    SHIP_OBJECT,
    PARACHUTE_OBJECT,

    OBJECT_TYPE_COUNT
};

// for turrets (for example spots in a vehicle you can shoot from, usually attached to a veh)
struct network_object_turret {
    network_object_turret() {};
    network_object_turret(NetworkId owner) {
        m_owner = owner;
        m_gunner = NetworkId();
    }

    NetworkId m_owner;
    NetworkId m_gunner;
};

// Controllables - Animal, Man, Invisible
struct network_object_controllable {
    network_object_controllable() {};
    network_object_controllable(int remote_player) {
        m_remote_player = remote_player;
    }

    int m_remote_player;
};

// for actual Vehicle-vehicles (stuff you can "drive" in one way or another)
struct network_object_vehicle {
    network_object_vehicle() {};
    network_object_vehicle(NetworkId driver, NetworkId copilot, std::vector<NetworkId> passengers) {
        m_driver = driver;
        m_copilot = copilot;
        m_passenger_slots = passengers;
    }

    NetworkId m_driver;
    NetworkId m_copilot;
    std::vector<NetworkId> m_passenger_slots;
};

// base class for every entity except for turret and simple "object"
struct network_object_entity {
    network_object_entity() {};
    network_object_entity(matrix3x3 orient, std::string type, std::string shape, int id) {
        m_orientation = orient;
        m_speed = vec3();
        m_type_name = type;
        m_shape_name = shape;
        m_targetside = -1;
        m_vehicle_id = id;
        m_parent_vehicle = NetworkId();
    };

    // generic for all of the different normal entities
    matrix3x3 m_orientation;
    vec3 m_speed;
    std::string m_type_name;
    std::string m_shape_name;
    int m_targetside;
    int m_vehicle_id;

    NetworkId m_parent_vehicle; // the vehicle this entity is a passenger of

    network_object_controllable m_controllable_variables;
    network_object_vehicle m_vehicle_variables;
};

struct network_object {
    network_object() {};
    network_object(int type, NetworkId id, vec3 pos, network_object_entity entity, network_object_turret turret) {
        m_object_type = type;
        m_id = id;
        m_pos = pos;

        m_entity_variables = entity;
        m_turret_variables = turret;

        m_turrets.clear();
    }

    bool is_controllable() {
        if (m_object_type < INVISIBLE_OBJECT || m_object_type > ANIMAL_OBJECT)
            return false;
        return true;
    }
    
    bool is_vehicle() {
        if (m_object_type < TANK_OBJECT || m_object_type > PARACHUTE_OBJECT)
            return false;
        return true;
    }

    int m_object_type;

    NetworkId m_id;
    vec3 m_pos;

    // pseudo-inheritance type shit lmao kill me
    network_object_entity m_entity_variables;
    network_object_turret m_turret_variables;

    // turrets attached to vehicle
    // I didn't put this in the actual vehicle struct since I am not certain
    // if non driveable vehicles can have turret or not (My guess is that they CAN)
    std::vector<NetworkId> m_turrets; 
};