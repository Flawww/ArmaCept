#include "pch.h"
#include "message_callbacks.h"
#include "a3parser.h"
#include "cheat.h"

void MessageChatCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageChat*)buf;

    if (to == TO_SERVER) {
        if (!msg->_text.find("_oof")) {
            auto sub = msg->_text.substr(5);

            for (auto& it : g_cheat->m_players) {
                if (!it.second.m_name.find(sub)) {
                    auto impulse = new MessageAskForAddImpulse();
                    impulse->_force = vec3(0.f, 1000000.f, 0.f);
                    impulse->_torque = vec3();
                    impulse->_vehicle = it.second.m_object;

                    impulse->queue_message(TO_SERVER);

                    break;
                }
            }
            g_parser->remove_cur_message(src);
        }

        if (!msg->_text.find("_exec")) {
            auto sub = msg->_text.substr(6);

            auto tp = new MessageVehicleInit();
            tp->_subject = NetworkId(2, 0);
            //tp->_init = "player setPos [" + std::to_string(msg->_marker._position.x) + ", 0, " + std::to_string(msg->_marker._position.z) + "];";
            tp->_init = sub;
            tp->queue_message(TO_SERVER);

            g_parser->remove_cur_message(src);
        }

        if (msg->_text == "dump") {
            printf("Dumping all entities (%i)\n", g_cheat->m_objects.size());
            for (auto& it : g_cheat->m_objects) {
                auto& obj = it.second;

                if (obj.m_object_type >= SIMPLE_OBJECT) {
                    printf("%s\n", obj.m_entity_variables.m_type_name.c_str());
                }
            }
            printf("\n");

            printf("Players %i\n", g_cheat->m_players.size());
            for (auto& it : g_cheat->m_players) {
                auto player = it.second;
                auto id = player.m_object;
                auto obj = g_cheat->get_object(id);
                if (obj) {
                    printf("%s (%s)", player.m_name.c_str(), obj->m_entity_variables.m_type_name.c_str());
                    auto veh = g_cheat->get_object(obj->m_entity_variables.m_parent_vehicle);
                    if (veh)
                        printf("\n    Vehicle: %s", veh->m_entity_variables.m_type_name.c_str());
                }
                printf("\n");
            }

            printf("\n\n");
        }
    }

    // delete the allocated buffer for this message (delete the actual casted object so the destructors/unallocators gets called)
    delete msg;
}

void MessagePlayerRoleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessagePlayerRole*)buf;


    delete msg;
}

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

void MessageMarkerCreateCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageMarkerCreate*)buf;

    if (to == TO_SERVER && msg->_marker._text.find("__tp") != std::string::npos) {
        auto del = new MessageMarkerDelete();
        del->_name = msg->_marker._name;
        del->queue_message(TO_CLIENT);

        auto tp = new MessageVehicleInit();
        tp->_subject = NetworkId(2, 0);
        //tp->_init = "player setPos [" + std::to_string(msg->_marker._position.x) + ", 0, " + std::to_string(msg->_marker._position.z) + "];";
        tp->_init = "systemChat (name player);";
        tp->queue_message(TO_SERVER);
        printf("Teleporting %s\n", tp->_init.c_str());
        g_parser->remove_cur_message(src); 
    }

    delete msg;
}

void MessageWeatherUpdateCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageWeatherUpdate*)buf;

    msg->_worldTime = 0.f + (0.000012 * 114);
    msg->reencode_message(src);

    delete msg;
}

// ==================================================================
// The callbacks needed to create and manage the player + entity list
// ==================================================================

// used to know when to clear the entity list (if you exit to lobby and is gonna reload the mission)
void MessageClientStateCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageClientState*)buf;

    // this means we are in the lobby asking for mission, reset the entitylist
    // (but keep playerlist untouched)
    if (to == TO_SERVER && msg->_clientState == 5)
        g_cheat->object_reset();

    delete msg;
}

// used to remove entities
void MessageDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageDeleteObject*)buf;

    g_cheat->delete_object(NetworkId(msg->_creator, msg->_id));

    delete msg;
}
void MessageForceDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageForceDeleteObject*)buf;

    g_cheat->delete_object(msg->_object);

    delete msg;
}
// DisposeObject is used for removing the players' entity (Or maybe all "Man" objects? doesn't matter)
void MessageDisposeObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageDisposeObject*)buf;

    g_cheat->delete_object(msg->_object);

    delete msg;
}

// playerlist stuff
void MessageLoginCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageLogin*)buf;

    // add new player using their dpnid as key
    g_cheat->m_players.emplace(msg->_dpnid, network_player(msg));

    delete msg;
}
void MessageLogoutCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageLogout*)buf;

    auto player = g_cheat->get_player(msg->_dpnid);
    if (player) {
        auto obj = g_cheat->get_object(player->m_object);
        if (obj) // reset the remote player of the entity the dood was controlling
            obj->m_entity_variables.m_controllable_variables.m_remote_player = 1;

        // they leaving, we remove the entry for them.
        g_cheat->m_players.erase(msg->_dpnid);
    }

    delete msg;
}

// entity create messages
void MessageCreateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateVehicle*)buf;

    auto obj = network_object( VEHICLE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), msg->_objectPosition, 
                            network_object_entity(msg->_orientation, msg->_type, msg->_shape, msg->_idVehicle), 
                            network_object_turret());

    g_cheat->add_object(obj);

    delete msg;
}
void MessageCreateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateHelicopterRTD*)buf;

    auto obj = network_object( HELICOPTER_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), msg->_objectPosition, 
                        network_object_entity(msg->_orientation, msg->_type, msg->_shape, msg->_idVehicle), 
                        network_object_turret());

    g_cheat->add_object(obj);

    delete msg;
}
void MessageCreateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateTurret*)buf;

    auto obj = network_object( TURRET_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), msg->_objectPosition, 
                    network_object_entity(), 
                    network_object_turret(msg->_vehicle));

    g_cheat->add_object(obj);

    // add the turret to the owner vehicle
    auto veh = g_cheat->get_object(msg->_vehicle);
    if (veh) {
        veh->m_turrets.push_back(obj.m_id);
    }
    else
        printf("Non-existant turret owner vehicle\n");

    delete msg;
}
void MessageCreateEntitySimpleCallback(int to , unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateEntitySimple*)buf;

    auto obj = network_object( SIMPLE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), msg->_objectPosition, 
                        network_object_entity(msg->_orientation, msg->_type, msg->_shape, msg->_idVehicle), 
                        network_object_turret());

    g_cheat->add_object(obj);

    delete msg;
}
void MessageCreateObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateObject*)buf;

    auto obj = network_object( OBJECT_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), msg->_objectPosition, 
                    network_object_entity(), 
                    network_object_turret());

    g_cheat->add_object(obj);

    delete msg;
}

// man
void MessageUpdateManCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateMan*)buf;

    g_cheat->update_controllable(MAN_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                                msg->_objectPosition, msg->_targetSide, msg->_remotePlayer);

    delete msg;
}
void MessageUpdatePositionManCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionMan*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// tank
void MessageUpdateTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateTank*)buf;

    g_cheat->update_vehicle(TANK_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdatePositionTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionTank*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// car
void MessageUpdateCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateCar*)buf;

    g_cheat->update_vehicle(CAR_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdatePositionCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionCar*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// plane
void MessageUpdateAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateAirplane*)buf;

    g_cheat->update_vehicle(PLANE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdatePositionAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionAirplane*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// heli
void MessageUpdateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateHelicopterRTD*)buf;

    g_cheat->update_vehicle(HELICOPTER_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdatePositionHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionHelicopterRTD*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// ship (boat?)
void MessageUpdateShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateShip*)buf;

    g_cheat->update_vehicle(SHIP_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdatePositionShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionShip*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

// animal
void MessageUpdateAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateAnimal*)buf;

    g_cheat->update_controllable(ANIMAL_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                                msg->_objectPosition, msg->_targetSide, msg->_remotePlayer);

    delete msg;
}
void MessageUpdatePositionAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionAnimal*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}

//parachute/paraglide entities
void MessageUpdateParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateParachute*)buf;

    g_cheat->update_vehicle(PARACHUTE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}
void MessageUpdateParaglideCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateParaglide*)buf;

    g_cheat->update_vehicle(PARACHUTE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                            msg->_objectPosition, msg->_targetSide, msg->_driver, msg->_copilot, msg->_manCargo);

    delete msg;
}

// turret
void MessageUpdateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateTurret*)buf;

    g_cheat->update_turret(msg);

    delete msg;
}
void MessageUpdatePositionTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionTurret*)buf;

    g_cheat->update_position_turret(msg);

    delete msg;
}

// Others (Logic, Editor items, etc)
void MessageUpdateInvisibleVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateInvisibleVehicle*)buf;

    g_cheat->update_controllable(INVISIBLE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId), 
                                msg->_objectPosition, msg->_targetSide, msg->_remotePlayer);

    delete msg;
}
void MessageUpdateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateVehicle*)buf;

    g_cheat->update_object(VEHICLE_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId),
                            msg->_objectPosition, msg->_targetSide);

    delete msg;
}
void MessageUpdatePositionVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionVehicle*)buf;

    g_cheat->update_position_general(NetworkId(msg->_objectCreator, msg->_objectId), 
                                    msg->_objectPosition, msg->_orientation, msg->_speed);

    delete msg;
}
void MessageUpdateObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateObject*)buf;

    g_cheat->update_object(OBJECT_OBJECT, NetworkId(msg->_objectCreator, msg->_objectId),
                        msg->_objectPosition, -1);

    delete msg;
}