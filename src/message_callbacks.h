#pragma once
#include "networkmessage.h"
#include "format_init.h"

typedef void(*MsgCallback)(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageChatCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessagePlayerRoleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageWeatherUpdateCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageAskForApplyDoDamageCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

// all the vehicle/player update messages
void MessageLoginCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

void MessageCreateVehicleCallback(int to, unsigned char* buf, NetworkMessageRaw* src);

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

//void MessageUpdateParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src);
//void MessageUpdatePositionParachuteCallback(int to, unsigned char* buf, NetworkMessageRaw* src);