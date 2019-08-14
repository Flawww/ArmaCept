#pragma once
#include "networkmessage.h"
#include "format_init.h"

typedef void(*MsgCallback)(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageChatCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessagePlayerRoleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageWeatherUpdateCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageAskForApplyDoDamageCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// ================================================
// All the callbacks needed for player + entitylist
// ================================================

// used to know when to clear the entity list (if you exit to lobby and is gonna reload the mission)
void MessageClientStateCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// used to remove entities
void MessageDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageForceDeleteObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageDisposeObjectCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// used for building the playerlist
void MessageLoginCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageLogoutCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// entity create funcs
void MessageCreateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageCreateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageCreateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// the various update funcs 
void MessageUpdateManCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionManCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionTankCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionTurretCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionCarCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionAirplaneCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionHelicopterRTDCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionShipCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionAnimalCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageUpdateInvisibleVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
void MessageUpdatePositionVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);


