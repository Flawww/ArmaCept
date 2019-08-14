#include "pch.h"
#include "message_callbacks.h"
#include "a3parser.h"

void MessageChatCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageChat*)buf;

    if (to == TO_SERVER) {
        auto chat = new MessageChat();
        chat->_channel = 0;
        chat->_name = "";
        chat->_sender = NetworkId(0, 0);
        chat->_text = "CHAT GOT'";
        chat->queue_message(TO_CLIENT);
    }

    // delete the allocated buffer for this message (delete the actual casted object so the destructors/unallocators gets called)
    delete msg;
}

void MessagePlayerRoleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessagePlayerRole*)buf;

    msg->reencode_message(src);

    delete msg;
}

void MessageAskForApplyDoDamageCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageAskForApplyDoDamage*)buf;

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

    delete msg;
}

// used to remove entities
void MessageDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageDeleteObject*)buf;

    delete msg;
}
void MessageForceDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageForceDeleteObject*)buf;

    delete msg;
}
// DisposeObject is used for removing the players' entity (Or maybe all "Man" objects? doesn't matter)
void MessageDisposeObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageDisposeObject*)buf;

    delete msg;
}

// playerlist stuff
void MessageLoginCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageLogin*)buf;

    delete msg;
}
void MessageLogoutCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageLogout*)buf;

    delete msg;
}

// entity create messages
void MessageCreateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateVehicle*)buf;

    delete msg;
}
void MessageCreateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateHelicopterRTD*)buf;

    delete msg;
}
void MessageCreateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageCreateTurret*)buf;

    delete msg;
}

// man
void MessageUpdateManCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateMan*)buf;

    delete msg;
}
void MessageUpdatePositionManCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionMan*)buf;
    
    delete msg;
}

// tank
void MessageUpdateTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateTank*)buf;

    delete msg;
}
void MessageUpdatePositionTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionTank*)buf;

    delete msg;
}

// turret
void MessageUpdateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateTurret*)buf;

    delete msg;
}
void MessageUpdatePositionTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionTurret*)buf;

    delete msg;
}

// car
void MessageUpdateCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateCar*)buf;

    delete msg;
}
void MessageUpdatePositionCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionCar*)buf;

    delete msg;
}

// plane
void MessageUpdateAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateAirplane*)buf;

    delete msg;
}
void MessageUpdatePositionAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionAirplane*)buf;

    delete msg;
}

// heli
void MessageUpdateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateHelicopterRTD*)buf;

    delete msg;
}
void MessageUpdatePositionHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionHelicopterRTD*)buf;

    delete msg;
}

// ship (boat?)
void MessageUpdateShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateShip*)buf;

    delete msg;
}
void MessageUpdatePositionShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionShip*)buf;

    delete msg;
}

// animal
void MessageUpdateAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateAnimal*)buf;

    delete msg;
}
void MessageUpdatePositionAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionAnimal*)buf;

    delete msg;
}

//parachute/paraglide entities
void MessageUpdateParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateParachute*)buf;

    delete msg;
}
void MessageUpdateParaglideCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateParaglide*)buf;

    delete msg;
}

// Others (Logic, Editor items, etc)
void MessageUpdateInvisibleVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateInvisibleVehicle*)buf;

    delete msg;
}
void MessageUpdateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdateVehicle*)buf;

    delete msg;
}
void MessageUpdatePositionVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src) {
    auto msg = (MessageUpdatePositionVehicle*)buf;

    delete msg;
}
