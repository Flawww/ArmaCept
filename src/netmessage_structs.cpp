#pragma once
#include "pch.h"
#include "netmessage_structs.h"
#include "a3parser.h"

void MessageMsgFormatItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgFormatItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgFormatItem, (unsigned char*)this);
}

void MessageMsgFormatItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgFormatItem, (unsigned char*)this);
}

MessageMsgFormat::~MessageMsgFormat() {
    for (auto it : _items)
        delete it;

}
void MessageMsgFormat::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgFormat, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgFormat, (unsigned char*)this);
}

void MessageMsgFormat::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgFormat, (unsigned char*)this);
}

void MessagePlayer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayer, (unsigned char*)this);
}

void MessagePlayer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayer, (unsigned char*)this);
}

void MessageMessages::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMessages, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMessages, (unsigned char*)this);
}

void MessageMessages::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMessages, (unsigned char*)this);
}

void MessageServerState::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerState, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerState, (unsigned char*)this);
}

void MessageServerState::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerState, (unsigned char*)this);
}

void MessageClientState::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageClientState, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageClientState, (unsigned char*)this);
}

void MessageClientState::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageClientState, (unsigned char*)this);
}

void MessagePlayerClientState::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerClientState, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerClientState, (unsigned char*)this);
}

void MessagePlayerClientState::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerClientState, (unsigned char*)this);
}

void MessageLogin::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLogin, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLogin, (unsigned char*)this);
}

void MessageLogin::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLogin, (unsigned char*)this);
}

void MessageLogout::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLogout, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLogout, (unsigned char*)this);
}

void MessageLogout::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLogout, (unsigned char*)this);
}

void MessageSquad::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSquad, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSquad, (unsigned char*)this);
}

void MessageSquad::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSquad, (unsigned char*)this);
}

void MessagePublicVariable::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicVariable, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicVariable, (unsigned char*)this);
}

void MessagePublicVariable::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicVariable, (unsigned char*)this);
}

void MessageTeamMemberSetVariable::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTeamMemberSetVariable, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTeamMemberSetVariable, (unsigned char*)this);
}

void MessageTeamMemberSetVariable::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTeamMemberSetVariable, (unsigned char*)this);
}

void MessageLogMsgOnServer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLogMsgOnServer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLogMsgOnServer, (unsigned char*)this);
}

void MessageLogMsgOnServer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLogMsgOnServer, (unsigned char*)this);
}

void MessageChat::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageChat, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageChat, (unsigned char*)this);
}

void MessageChat::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageChat, (unsigned char*)this);
}

void MessageRadioChat::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChat, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChat, (unsigned char*)this);
}

void MessageRadioChat::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChat, (unsigned char*)this);
}

void MessageRadioChatWave::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChatWave, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChatWave, (unsigned char*)this);
}

void MessageRadioChatWave::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChatWave, (unsigned char*)this);
}

void MessageSetSpeaker::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetSpeaker, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetSpeaker, (unsigned char*)this);
}

void MessageSetSpeaker::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetSpeaker, (unsigned char*)this);
}

void MessageMissionHeader::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMissionHeader, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMissionHeader, (unsigned char*)this);
}

void MessageMissionHeader::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMissionHeader, (unsigned char*)this);
}

void MessagePlayerRole::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerRole, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerRole, (unsigned char*)this);
}

void MessagePlayerRole::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerRole, (unsigned char*)this);
}

void MessageSelectPlayer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSelectPlayer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSelectPlayer, (unsigned char*)this);
}

void MessageSelectPlayer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSelectPlayer, (unsigned char*)this);
}

void MessageAttachPerson::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAttachPerson, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAttachPerson, (unsigned char*)this);
}

void MessageAttachPerson::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAttachPerson, (unsigned char*)this);
}

void MessageTransferFile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTransferFile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTransferFile, (unsigned char*)this);
}

void MessageTransferFile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTransferFile, (unsigned char*)this);
}

void MessageAskMissionFile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskMissionFile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskMissionFile, (unsigned char*)this);
}

void MessageAskMissionFile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskMissionFile, (unsigned char*)this);
}

void MessageTransferMissionFile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTransferMissionFile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTransferMissionFile, (unsigned char*)this);
}

void MessageTransferMissionFile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTransferMissionFile, (unsigned char*)this);
}

void MessageTransferFileToServer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTransferFileToServer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTransferFileToServer, (unsigned char*)this);
}

void MessageTransferFileToServer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTransferFileToServer, (unsigned char*)this);
}

void MessageAskForDamage::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDamage, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDamage, (unsigned char*)this);
}

void MessageAskForDamage::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDamage, (unsigned char*)this);
}

void MessageAskForSetDamage::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetDamage, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetDamage, (unsigned char*)this);
}

void MessageAskForSetDamage::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetDamage, (unsigned char*)this);
}

void MessageAskForSetSkill::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetSkill, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetSkill, (unsigned char*)this);
}

void MessageAskForSetSkill::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetSkill, (unsigned char*)this);
}

void MessageAskForGetIn::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForGetIn, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForGetIn, (unsigned char*)this);
}

void MessageAskForGetIn::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForGetIn, (unsigned char*)this);
}

void MessageAskForAssignAs::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAssignAs, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAssignAs, (unsigned char*)this);
}

void MessageAskForAssignAs::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAssignAs, (unsigned char*)this);
}

void MessageAskForMoveOutTo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForMoveOutTo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForMoveOutTo, (unsigned char*)this);
}

void MessageAskForMoveOutTo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForMoveOutTo, (unsigned char*)this);
}

void MessageAskForRemoveVehicleFromGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForRemoveVehicleFromGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForRemoveVehicleFromGroup, (unsigned char*)this);
}

void MessageAskForRemoveVehicleFromGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForRemoveVehicleFromGroup, (unsigned char*)this);
}

void MessageAskForGetOut::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForGetOut, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForGetOut, (unsigned char*)this);
}

void MessageAskForGetOut::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForGetOut, (unsigned char*)this);
}

void MessageAskWaitForGetOut::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskWaitForGetOut, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskWaitForGetOut, (unsigned char*)this);
}

void MessageAskWaitForGetOut::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskWaitForGetOut, (unsigned char*)this);
}

void MessageAskForChangePosition::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForChangePosition, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForChangePosition, (unsigned char*)this);
}

void MessageAskForChangePosition::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForChangePosition, (unsigned char*)this);
}

void MessageAskForSelectWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSelectWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSelectWeapon, (unsigned char*)this);
}

void MessageAskForSelectWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSelectWeapon, (unsigned char*)this);
}

void MessageAskForAmmo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAmmo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAmmo, (unsigned char*)this);
}

void MessageAskForAmmo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAmmo, (unsigned char*)this);
}

void MessageAskForAddImpulse::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAddImpulse, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAddImpulse, (unsigned char*)this);
}

void MessageAskForAddImpulse::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAddImpulse, (unsigned char*)this);
}

void MessageAskForMoveVector::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForMoveVector, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForMoveVector, (unsigned char*)this);
}

void MessageAskForMoveVector::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForMoveVector, (unsigned char*)this);
}

void MessageAskForMoveMatrix::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForMoveMatrix, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForMoveMatrix, (unsigned char*)this);
}

void MessageAskForMoveMatrix::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForMoveMatrix, (unsigned char*)this);
}

void MessageAskForJoinGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForJoinGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForJoinGroup, (unsigned char*)this);
}

void MessageAskForJoinGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForJoinGroup, (unsigned char*)this);
}

void MessageAskForJoinUnits::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForJoinUnits, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForJoinUnits, (unsigned char*)this);
}

void MessageAskForJoinUnits::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForJoinUnits, (unsigned char*)this);
}

void MessageExplosionDamageEffects::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageExplosionDamageEffects, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageExplosionDamageEffects, (unsigned char*)this);
}

void MessageExplosionDamageEffects::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageExplosionDamageEffects, (unsigned char*)this);
}

void MessageFireWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageFireWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageFireWeapon, (unsigned char*)this);
}

void MessageFireWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageFireWeapon, (unsigned char*)this);
}

void MessageMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMagazine, (unsigned char*)this);
}

void MessageMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMagazine, (unsigned char*)this);
}

void MessageNetWeaponInfo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNetWeaponInfo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNetWeaponInfo, (unsigned char*)this);
}

void MessageNetWeaponInfo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNetWeaponInfo, (unsigned char*)this);
}

MessageUpdateEntityAIWeapons::~MessageUpdateEntityAIWeapons() {
    for (auto it : _weapons)
        delete it;

    for (auto it : _magazines)
        delete it;

}
void MessageUpdateEntityAIWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateEntityAIWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateEntityAIWeapons, (unsigned char*)this);
}

void MessageUpdateEntityAIWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateEntityAIWeapons, (unsigned char*)this);
}

void MessageUpdateWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateWeapons, (unsigned char*)this);
}

void MessageUpdateWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateWeapons, (unsigned char*)this);
}

void MessageAddWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddWeapon, (unsigned char*)this);
}

void MessageAddWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddWeapon, (unsigned char*)this);
}

void MessageRemoveWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveWeapon, (unsigned char*)this);
}

void MessageRemoveWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveWeapon, (unsigned char*)this);
}

void MessageAddWeaponCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddWeaponCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddWeaponCargo, (unsigned char*)this);
}

void MessageAddWeaponCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddWeaponCargo, (unsigned char*)this);
}

void MessageRemoveWeaponCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveWeaponCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveWeaponCargo, (unsigned char*)this);
}

void MessageRemoveWeaponCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveWeaponCargo, (unsigned char*)this);
}

void MessageAddItemCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddItemCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddItemCargo, (unsigned char*)this);
}

void MessageAddItemCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddItemCargo, (unsigned char*)this);
}

void MessageRemoveItemCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveItemCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveItemCargo, (unsigned char*)this);
}

void MessageRemoveItemCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveItemCargo, (unsigned char*)this);
}

void MessageModifyMagazineAmmoInCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageModifyMagazineAmmoInCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageModifyMagazineAmmoInCargo, (unsigned char*)this);
}

void MessageModifyMagazineAmmoInCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageModifyMagazineAmmoInCargo, (unsigned char*)this);
}

void MessageSetUnitLoadOutFromClassName::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetUnitLoadOutFromClassName, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetUnitLoadOutFromClassName, (unsigned char*)this);
}

void MessageSetUnitLoadOutFromClassName::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetUnitLoadOutFromClassName, (unsigned char*)this);
}

void MessageMagazineString::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMagazineString, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMagazineString, (unsigned char*)this);
}

void MessageMagazineString::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMagazineString, (unsigned char*)this);
}

void MessageCountedString::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCountedString, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCountedString, (unsigned char*)this);
}

void MessageCountedString::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCountedString, (unsigned char*)this);
}

void MessageCountedWeaponsString::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCountedWeaponsString, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCountedWeaponsString, (unsigned char*)this);
}

void MessageCountedWeaponsString::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCountedWeaponsString, (unsigned char*)this);
}

MessageContainerRawData::~MessageContainerRawData() {
    for (auto it : _magazinesDef)
        delete it;

    for (auto it : _items)
        delete it;

    for (auto it : _weapons)
        delete it;

    for (auto it : _containers)
        delete it;

}
void MessageContainerRawData::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageContainerRawData, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageContainerRawData, (unsigned char*)this);
}

void MessageContainerRawData::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageContainerRawData, (unsigned char*)this);
}

void MessageSetUnitLoadOutFromRawData::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetUnitLoadOutFromRawData, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetUnitLoadOutFromRawData, (unsigned char*)this);
}

void MessageSetUnitLoadOutFromRawData::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetUnitLoadOutFromRawData, (unsigned char*)this);
}

void MessageAssignItemToSlot::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAssignItemToSlot, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAssignItemToSlot, (unsigned char*)this);
}

void MessageAssignItemToSlot::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAssignItemToSlot, (unsigned char*)this);
}

void MessageUnAssignItemFromSlot::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUnAssignItemFromSlot, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUnAssignItemFromSlot, (unsigned char*)this);
}

void MessageUnAssignItemFromSlot::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUnAssignItemFromSlot, (unsigned char*)this);
}

void MessageOfferItemFromBody::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageOfferItemFromBody, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageOfferItemFromBody, (unsigned char*)this);
}

void MessageOfferItemFromBody::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageOfferItemFromBody, (unsigned char*)this);
}

void MessageLinkNewContainer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLinkNewContainer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLinkNewContainer, (unsigned char*)this);
}

void MessageLinkNewContainer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLinkNewContainer, (unsigned char*)this);
}

void MessageReplaceContainer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReplaceContainer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReplaceContainer, (unsigned char*)this);
}

void MessageReplaceContainer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReplaceContainer, (unsigned char*)this);
}

void MessageAddMagazineCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddMagazineCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddMagazineCargo, (unsigned char*)this);
}

void MessageAddMagazineCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddMagazineCargo, (unsigned char*)this);
}

void MessageAddBackpackCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddBackpackCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddBackpackCargo, (unsigned char*)this);
}

void MessageAddBackpackCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddBackpackCargo, (unsigned char*)this);
}

void MessageRemoveBackpackCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveBackpackCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveBackpackCargo, (unsigned char*)this);
}

void MessageRemoveBackpackCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveBackpackCargo, (unsigned char*)this);
}

void MessageRemoveMagazineCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveMagazineCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveMagazineCargo, (unsigned char*)this);
}

void MessageRemoveMagazineCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveMagazineCargo, (unsigned char*)this);
}

void MessageAddMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddMagazine, (unsigned char*)this);
}

void MessageAddMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddMagazine, (unsigned char*)this);
}

void MessageRemoveMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoveMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoveMagazine, (unsigned char*)this);
}

void MessageRemoveMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoveMagazine, (unsigned char*)this);
}

void MessageVehicleInit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVehicleInit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVehicleInit, (unsigned char*)this);
}

void MessageVehicleInit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVehicleInit, (unsigned char*)this);
}

void MessageVehicleDestroyed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVehicleDestroyed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVehicleDestroyed, (unsigned char*)this);
}

void MessageVehicleDestroyed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVehicleDestroyed, (unsigned char*)this);
}

void MessageStoreCreatedSite::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageStoreCreatedSite, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageStoreCreatedSite, (unsigned char*)this);
}

void MessageStoreCreatedSite::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageStoreCreatedSite, (unsigned char*)this);
}

void MessageDeleteCreatedSite::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDeleteCreatedSite, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDeleteCreatedSite, (unsigned char*)this);
}

void MessageDeleteCreatedSite::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDeleteCreatedSite, (unsigned char*)this);
}

void MessageRunInitSitesScript::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRunInitSitesScript, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRunInitSitesScript, (unsigned char*)this);
}

void MessageRunInitSitesScript::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRunInitSitesScript, (unsigned char*)this);
}

void MessageMarker::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMarker, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMarker, (unsigned char*)this);
}

void MessageMarker::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMarker, (unsigned char*)this);
}

void MessageMarkerCreate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMarkerCreate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMarkerCreate, (unsigned char*)this);
}

void MessageMarkerCreate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMarkerCreate, (unsigned char*)this);
}

void MessageMarkerDelete::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMarkerDelete, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMarkerDelete, (unsigned char*)this);
}

void MessageMarkerDelete::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMarkerDelete, (unsigned char*)this);
}

void MessageMarkerUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMarkerUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMarkerUpdate, (unsigned char*)this);
}

void MessageMarkerUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMarkerUpdate, (unsigned char*)this);
}

void MessageSetFlagOwner::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetFlagOwner, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetFlagOwner, (unsigned char*)this);
}

void MessageSetFlagOwner::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetFlagOwner, (unsigned char*)this);
}

void MessageSetFlagCarrier::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetFlagCarrier, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetFlagCarrier, (unsigned char*)this);
}

void MessageSetFlagCarrier::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetFlagCarrier, (unsigned char*)this);
}

void MessageMsgVTarget::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVTarget, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVTarget, (unsigned char*)this);
}

void MessageMsgVTarget::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVTarget, (unsigned char*)this);
}

void MessageMsgVFire::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVFire, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVFire, (unsigned char*)this);
}

void MessageMsgVFire::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVFire, (unsigned char*)this);
}

void MessageMsgVMove::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVMove, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVMove, (unsigned char*)this);
}

void MessageMsgVMove::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVMove, (unsigned char*)this);
}

void MessageMsgVFormation::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVFormation, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVFormation, (unsigned char*)this);
}

void MessageMsgVFormation::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVFormation, (unsigned char*)this);
}

void MessageMsgVSimpleCommand::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVSimpleCommand, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVSimpleCommand, (unsigned char*)this);
}

void MessageMsgVSimpleCommand::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVSimpleCommand, (unsigned char*)this);
}

void MessageMsgVLoad::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVLoad, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVLoad, (unsigned char*)this);
}

void MessageMsgVLoad::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVLoad, (unsigned char*)this);
}

void MessageMsgVAzimut::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVAzimut, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVAzimut, (unsigned char*)this);
}

void MessageMsgVAzimut::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVAzimut, (unsigned char*)this);
}

void MessageMsgVStopTurning::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVStopTurning, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVStopTurning, (unsigned char*)this);
}

void MessageMsgVStopTurning::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVStopTurning, (unsigned char*)this);
}

void MessageMsgVFireFailed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVFireFailed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVFireFailed, (unsigned char*)this);
}

void MessageMsgVFireFailed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVFireFailed, (unsigned char*)this);
}

void MessageChangeOwner::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageChangeOwner, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageChangeOwner, (unsigned char*)this);
}

void MessageChangeOwner::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageChangeOwner, (unsigned char*)this);
}

void MessagePlaySound::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlaySound, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlaySound, (unsigned char*)this);
}

void MessagePlaySound::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlaySound, (unsigned char*)this);
}

void MessageDeleteObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDeleteObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDeleteObject, (unsigned char*)this);
}

void MessageDeleteObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDeleteObject, (unsigned char*)this);
}

void MessageDeleteCommand::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDeleteCommand, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDeleteCommand, (unsigned char*)this);
}

void MessageDeleteCommand::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDeleteCommand, (unsigned char*)this);
}

void MessageCreateObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateObject, (unsigned char*)this);
}

void MessageCreateObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateObject, (unsigned char*)this);
}

void MessageUpdateObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateObject, (unsigned char*)this);
}

void MessageUpdateObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateObject, (unsigned char*)this);
}

void MessageCreateVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateVehicle, (unsigned char*)this);
}

void MessageCreateVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateVehicle, (unsigned char*)this);
}

void MessageUpdateVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateVehicle, (unsigned char*)this);
}

void MessageUpdateVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateVehicle, (unsigned char*)this);
}

void MessageUpdatePositionVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionVehicle, (unsigned char*)this);
}

void MessageUpdatePositionVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionVehicle, (unsigned char*)this);
}

void MessageEffects::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageEffects, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageEffects, (unsigned char*)this);
}

void MessageEffects::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageEffects, (unsigned char*)this);
}

void MessageCreateDetector::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateDetector, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateDetector, (unsigned char*)this);
}

void MessageCreateDetector::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateDetector, (unsigned char*)this);
}

void MessageUpdateDetector::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateDetector, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateDetector, (unsigned char*)this);
}

void MessageUpdateDetector::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateDetector, (unsigned char*)this);
}

void MessageUpdateSupply::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateSupply, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateSupply, (unsigned char*)this);
}

void MessageUpdateSupply::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateSupply, (unsigned char*)this);
}

void MessageUpdateFlag::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateFlag, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateFlag, (unsigned char*)this);
}

void MessageUpdateFlag::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateFlag, (unsigned char*)this);
}

void MessageCreateShot::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateShot, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateShot, (unsigned char*)this);
}

void MessageCreateShot::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateShot, (unsigned char*)this);
}

void MessageUpdateShot::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateShot, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateShot, (unsigned char*)this);
}

void MessageUpdateShot::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateShot, (unsigned char*)this);
}

void MessageCreateCrater::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateCrater, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateCrater, (unsigned char*)this);
}

void MessageCreateCrater::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateCrater, (unsigned char*)this);
}

void MessageCreateCraterOnVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateCraterOnVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateCraterOnVehicle, (unsigned char*)this);
}

void MessageCreateCraterOnVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateCraterOnVehicle, (unsigned char*)this);
}

void MessageCreateObjectDestructed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateObjectDestructed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateObjectDestructed, (unsigned char*)this);
}

void MessageCreateObjectDestructed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateObjectDestructed, (unsigned char*)this);
}

void MessageCreateAICenter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAICenter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAICenter, (unsigned char*)this);
}

void MessageCreateAICenter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAICenter, (unsigned char*)this);
}

void MessageUpdateAICenter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAICenter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAICenter, (unsigned char*)this);
}

void MessageUpdateAICenter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAICenter, (unsigned char*)this);
}

void MessageWaypoint::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWaypoint, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWaypoint, (unsigned char*)this);
}

void MessageWaypoint::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWaypoint, (unsigned char*)this);
}

MessageCreateAIGroup::~MessageCreateAIGroup() {
    for (auto it : _waypoints)
        delete it;

}
void MessageCreateAIGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAIGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAIGroup, (unsigned char*)this);
}

void MessageCreateAIGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAIGroup, (unsigned char*)this);
}

void MessageUnitSlot::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUnitSlot, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUnitSlot, (unsigned char*)this);
}

void MessageUnitSlot::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUnitSlot, (unsigned char*)this);
}

MessageUpdateAIGroup::~MessageUpdateAIGroup() {
    for (auto it : _unitSlots)
        delete it;

}
void MessageUpdateAIGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIGroup, (unsigned char*)this);
}

void MessageUpdateAIGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIGroup, (unsigned char*)this);
}

void MessageCreateAISubgroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAISubgroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAISubgroup, (unsigned char*)this);
}

void MessageCreateAISubgroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAISubgroup, (unsigned char*)this);
}

void MessageUpdateAISubgroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAISubgroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAISubgroup, (unsigned char*)this);
}

void MessageUpdateAISubgroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAISubgroup, (unsigned char*)this);
}

void MessageCreateAIBrain::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAIBrain, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAIBrain, (unsigned char*)this);
}

void MessageCreateAIBrain::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAIBrain, (unsigned char*)this);
}

void MessageUpdateProfessionStats::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateProfessionStats, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateProfessionStats, (unsigned char*)this);
}

void MessageUpdateProfessionStats::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateProfessionStats, (unsigned char*)this);
}

void MessageUpdateAIBrain::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIBrain, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIBrain, (unsigned char*)this);
}

void MessageUpdateAIBrain::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIBrain, (unsigned char*)this);
}

void MessageUpdateAIBrainPath::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIBrainPath, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIBrainPath, (unsigned char*)this);
}

void MessageUpdateAIBrainPath::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIBrainPath, (unsigned char*)this);
}

void MessageCreateAIUnit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAIUnit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAIUnit, (unsigned char*)this);
}

void MessageCreateAIUnit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAIUnit, (unsigned char*)this);
}

void MessageUpdateAIUnit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIUnit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIUnit, (unsigned char*)this);
}

void MessageUpdateAIUnit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIUnit, (unsigned char*)this);
}

void MessageUpdateAIUnitPath::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIUnitPath, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIUnitPath, (unsigned char*)this);
}

void MessageUpdateAIUnitPath::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIUnitPath, (unsigned char*)this);
}

void MessageCreateAIAgent::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAIAgent, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAIAgent, (unsigned char*)this);
}

void MessageCreateAIAgent::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAIAgent, (unsigned char*)this);
}

void MessageUpdateAIAgent::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIAgent, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIAgent, (unsigned char*)this);
}

void MessageUpdateAIAgent::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIAgent, (unsigned char*)this);
}

void MessageUpdateAIAgentPath::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAIAgentPath, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAIAgentPath, (unsigned char*)this);
}

void MessageUpdateAIAgentPath::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAIAgentPath, (unsigned char*)this);
}

void MessageCreateCommand::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateCommand, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateCommand, (unsigned char*)this);
}

void MessageCreateCommand::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateCommand, (unsigned char*)this);
}

void MessageUpdateCommand::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateCommand, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateCommand, (unsigned char*)this);
}

void MessageUpdateCommand::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateCommand, (unsigned char*)this);
}

void MessageUpdateVehicleAI::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateVehicleAI, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateVehicleAI, (unsigned char*)this);
}

void MessageUpdateVehicleAI::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateVehicleAI, (unsigned char*)this);
}

void MessageUpdateVehicleAIFull::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateVehicleAIFull, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateVehicleAIFull, (unsigned char*)this);
}

void MessageUpdateVehicleAIFull::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateVehicleAIFull, (unsigned char*)this);
}

void MessageUpdateVehicleBrain::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateVehicleBrain, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateVehicleBrain, (unsigned char*)this);
}

void MessageUpdateVehicleBrain::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateVehicleBrain, (unsigned char*)this);
}

void MessageUpdateTransport::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTransport, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTransport, (unsigned char*)this);
}

void MessageUpdateTransport::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTransport, (unsigned char*)this);
}

void MessageUpdateAnimal::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAnimal, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAnimal, (unsigned char*)this);
}

void MessageUpdateAnimal::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAnimal, (unsigned char*)this);
}

void MessageUpdatePositionAnimal::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionAnimal, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionAnimal, (unsigned char*)this);
}

void MessageUpdatePositionAnimal::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionAnimal, (unsigned char*)this);
}

void MessageUpdateMan::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateMan, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateMan, (unsigned char*)this);
}

void MessageUpdateMan::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateMan, (unsigned char*)this);
}

void MessageUpdatePositionMan::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionMan, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionMan, (unsigned char*)this);
}

void MessageUpdatePositionMan::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionMan, (unsigned char*)this);
}

void MessageUpdateTankOrCar::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTankOrCar, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTankOrCar, (unsigned char*)this);
}

void MessageUpdateTankOrCar::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTankOrCar, (unsigned char*)this);
}

void MessageUpdateTank::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTank, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTank, (unsigned char*)this);
}

void MessageUpdateTank::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTank, (unsigned char*)this);
}

void MessageUpdatePositionTank::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionTank, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionTank, (unsigned char*)this);
}

void MessageUpdatePositionTank::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionTank, (unsigned char*)this);
}

void MessageUpdateTurret::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTurret, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTurret, (unsigned char*)this);
}

void MessageUpdateTurret::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTurret, (unsigned char*)this);
}

void MessageUpdateCar::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateCar, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateCar, (unsigned char*)this);
}

void MessageUpdateCar::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateCar, (unsigned char*)this);
}

void MessageUpdatePositionCar::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionCar, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionCar, (unsigned char*)this);
}

void MessageUpdatePositionCar::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionCar, (unsigned char*)this);
}

void MessageUpdateAirplane::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAirplane, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAirplane, (unsigned char*)this);
}

void MessageUpdateAirplane::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAirplane, (unsigned char*)this);
}

void MessageUpdatePositionAirplane::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionAirplane, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionAirplane, (unsigned char*)this);
}

void MessageUpdatePositionAirplane::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionAirplane, (unsigned char*)this);
}

void MessageUpdateHelicopter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateHelicopter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateHelicopter, (unsigned char*)this);
}

void MessageUpdateHelicopter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateHelicopter, (unsigned char*)this);
}

void MessageUpdatePositionHelicopter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionHelicopter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionHelicopter, (unsigned char*)this);
}

void MessageUpdatePositionHelicopter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionHelicopter, (unsigned char*)this);
}

void MessageUpdateParachute::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateParachute, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateParachute, (unsigned char*)this);
}

void MessageUpdateParachute::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateParachute, (unsigned char*)this);
}

void MessageUpdateParaglide::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateParaglide, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateParaglide, (unsigned char*)this);
}

void MessageUpdateParaglide::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateParaglide, (unsigned char*)this);
}

void MessageUpdateShip::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateShip, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateShip, (unsigned char*)this);
}

void MessageUpdateShip::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateShip, (unsigned char*)this);
}

void MessageUpdatePositionShip::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionShip, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionShip, (unsigned char*)this);
}

void MessageUpdatePositionShip::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionShip, (unsigned char*)this);
}

void MessageNetMuzzleInfo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNetMuzzleInfo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNetMuzzleInfo, (unsigned char*)this);
}

void MessageNetMuzzleInfo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNetMuzzleInfo, (unsigned char*)this);
}

void MessagePersonInventoryDescriptor::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePersonInventoryDescriptor, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePersonInventoryDescriptor, (unsigned char*)this);
}

void MessagePersonInventoryDescriptor::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePersonInventoryDescriptor, (unsigned char*)this);
}

void MessagePathPoint::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePathPoint, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePathPoint, (unsigned char*)this);
}

void MessagePathPoint::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePathPoint, (unsigned char*)this);
}

void MessageUpdateMotorcycle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateMotorcycle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateMotorcycle, (unsigned char*)this);
}

void MessageUpdateMotorcycle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateMotorcycle, (unsigned char*)this);
}

void MessageUpdatePositionMotorcycle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionMotorcycle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionMotorcycle, (unsigned char*)this);
}

void MessageUpdatePositionMotorcycle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionMotorcycle, (unsigned char*)this);
}

void MessageAskForHideBody::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForHideBody, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForHideBody, (unsigned char*)this);
}

void MessageAskForHideBody::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForHideBody, (unsigned char*)this);
}

void MessageNetworkCommand::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNetworkCommand, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNetworkCommand, (unsigned char*)this);
}

void MessageNetworkCommand::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNetworkCommand, (unsigned char*)this);
}

void MessageIntegrityQuestion::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageIntegrityQuestion, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageIntegrityQuestion, (unsigned char*)this);
}

void MessageIntegrityQuestion::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageIntegrityQuestion, (unsigned char*)this);
}

void MessageIntegrityAnswer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageIntegrityAnswer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageIntegrityAnswer, (unsigned char*)this);
}

void MessageIntegrityAnswer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageIntegrityAnswer, (unsigned char*)this);
}

void MessageUpdateSeagull::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateSeagull, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateSeagull, (unsigned char*)this);
}

void MessageUpdateSeagull::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateSeagull, (unsigned char*)this);
}

void MessageUpdatePositionSeagull::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionSeagull, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionSeagull, (unsigned char*)this);
}

void MessageUpdatePositionSeagull::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionSeagull, (unsigned char*)this);
}

void MessagePlayerUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerUpdate, (unsigned char*)this);
}

void MessagePlayerUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerUpdate, (unsigned char*)this);
}

void MessageUpdateDamageVehicleAI::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateDamageVehicleAI, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateDamageVehicleAI, (unsigned char*)this);
}

void MessageUpdateDamageVehicleAI::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateDamageVehicleAI, (unsigned char*)this);
}

void MessageUpdateDamageObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateDamageObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateDamageObject, (unsigned char*)this);
}

void MessageUpdateDamageObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateDamageObject, (unsigned char*)this);
}

void MessageCreateHelicopter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateHelicopter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateHelicopter, (unsigned char*)this);
}

void MessageCreateHelicopter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateHelicopter, (unsigned char*)this);
}

void MessageUpdateClientInfo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateClientInfo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateClientInfo, (unsigned char*)this);
}

void MessageUpdateClientInfo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateClientInfo, (unsigned char*)this);
}

void MessageShowTarget::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageShowTarget, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageShowTarget, (unsigned char*)this);
}

void MessageShowTarget::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageShowTarget, (unsigned char*)this);
}

void MessageShowSuppressTarget::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageShowSuppressTarget, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageShowSuppressTarget, (unsigned char*)this);
}

void MessageShowSuppressTarget::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageShowSuppressTarget, (unsigned char*)this);
}

void MessageGroupSynchronization::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSynchronization, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSynchronization, (unsigned char*)this);
}

void MessageGroupSynchronization::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSynchronization, (unsigned char*)this);
}

void MessageDetectorActivation::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDetectorActivation, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDetectorActivation, (unsigned char*)this);
}

void MessageDetectorActivation::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDetectorActivation, (unsigned char*)this);
}

void MessageAskForCreateUnit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForCreateUnit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForCreateUnit, (unsigned char*)this);
}

void MessageAskForCreateUnit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForCreateUnit, (unsigned char*)this);
}

void MessageAskForDeleteVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDeleteVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDeleteVehicle, (unsigned char*)this);
}

void MessageAskForDeleteVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDeleteVehicle, (unsigned char*)this);
}

void MessageAskForReceiveUnitAnswer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForReceiveUnitAnswer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForReceiveUnitAnswer, (unsigned char*)this);
}

void MessageAskForReceiveUnitAnswer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForReceiveUnitAnswer, (unsigned char*)this);
}

void MessageAskForGroupRespawn::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForGroupRespawn, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForGroupRespawn, (unsigned char*)this);
}

void MessageAskForGroupRespawn::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForGroupRespawn, (unsigned char*)this);
}

void MessageGroupRespawnDone::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupRespawnDone, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupRespawnDone, (unsigned char*)this);
}

void MessageGroupRespawnDone::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupRespawnDone, (unsigned char*)this);
}

void MessageMissionParams::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMissionParams, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMissionParams, (unsigned char*)this);
}

void MessageMissionParams::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMissionParams, (unsigned char*)this);
}

void MessageUpdateMine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateMine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateMine, (unsigned char*)this);
}

void MessageUpdateMine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateMine, (unsigned char*)this);
}

void MessageAskForActivateMine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForActivateMine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForActivateMine, (unsigned char*)this);
}

void MessageAskForActivateMine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForActivateMine, (unsigned char*)this);
}

void MessageAskForDetectedMine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDetectedMine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDetectedMine, (unsigned char*)this);
}

void MessageAskForDetectedMine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDetectedMine, (unsigned char*)this);
}

void MessageDisposeObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDisposeObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDisposeObject, (unsigned char*)this);
}

void MessageDisposeObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDisposeObject, (unsigned char*)this);
}

void MessageVehicleDamaged::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVehicleDamaged, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVehicleDamaged, (unsigned char*)this);
}

void MessageVehicleDamaged::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVehicleDamaged, (unsigned char*)this);
}

void MessageUpdateFireplace::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateFireplace, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateFireplace, (unsigned char*)this);
}

void MessageUpdateFireplace::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateFireplace, (unsigned char*)this);
}

void MessageAskForInflameFire::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForInflameFire, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForInflameFire, (unsigned char*)this);
}

void MessageAskForInflameFire::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForInflameFire, (unsigned char*)this);
}

void MessageAskForAnimationPhase::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAnimationPhase, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAnimationPhase, (unsigned char*)this);
}

void MessageAskForAnimationPhase::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAnimationPhase, (unsigned char*)this);
}

void MessageIncomingMissile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageIncomingMissile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageIncomingMissile, (unsigned char*)this);
}

void MessageIncomingMissile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageIncomingMissile, (unsigned char*)this);
}

void MessageLaunchedCounterMeasures::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLaunchedCounterMeasures, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLaunchedCounterMeasures, (unsigned char*)this);
}

void MessageLaunchedCounterMeasures::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLaunchedCounterMeasures, (unsigned char*)this);
}

void MessageSharedMineUsed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSharedMineUsed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSharedMineUsed, (unsigned char*)this);
}

void MessageSharedMineUsed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSharedMineUsed, (unsigned char*)this);
}

void MessageSetShotParents::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetShotParents, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetShotParents, (unsigned char*)this);
}

void MessageSetShotParents::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetShotParents, (unsigned char*)this);
}

void MessageWeaponLocked::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWeaponLocked, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWeaponLocked, (unsigned char*)this);
}

void MessageWeaponLocked::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWeaponLocked, (unsigned char*)this);
}

void MessageForceDeleteObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageForceDeleteObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageForceDeleteObject, (unsigned char*)this);
}

void MessageForceDeleteObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageForceDeleteObject, (unsigned char*)this);
}

void MessageJoinIntoUnit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJoinIntoUnit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJoinIntoUnit, (unsigned char*)this);
}

void MessageJoinIntoUnit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJoinIntoUnit, (unsigned char*)this);
}

void MessageAIStatsMPRowCreate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAIStatsMPRowCreate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAIStatsMPRowCreate, (unsigned char*)this);
}

void MessageAIStatsMPRowCreate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAIStatsMPRowCreate, (unsigned char*)this);
}

void MessageAIStatsMPRowUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAIStatsMPRowUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAIStatsMPRowUpdate, (unsigned char*)this);
}

void MessageAIStatsMPRowUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAIStatsMPRowUpdate, (unsigned char*)this);
}

void MessageWeatherCreate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWeatherCreate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWeatherCreate, (unsigned char*)this);
}

void MessageWeatherCreate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWeatherCreate, (unsigned char*)this);
}

void MessageWeatherUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWeatherUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWeatherUpdate, (unsigned char*)this);
}

void MessageWeatherUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWeatherUpdate, (unsigned char*)this);
}

void MessageMuteList::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMuteList, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMuteList, (unsigned char*)this);
}

void MessageMuteList::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMuteList, (unsigned char*)this);
}

void MessageVoiceOn::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVoiceOn, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVoiceOn, (unsigned char*)this);
}

void MessageVoiceOn::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVoiceOn, (unsigned char*)this);
}

void MessageCleanupPlayer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCleanupPlayer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCleanupPlayer, (unsigned char*)this);
}

void MessageCleanupPlayer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCleanupPlayer, (unsigned char*)this);
}

void MessageLockGearItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLockGearItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLockGearItem, (unsigned char*)this);
}

void MessageLockGearItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLockGearItem, (unsigned char*)this);
}

void MessageUnlockGearItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUnlockGearItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUnlockGearItem, (unsigned char*)this);
}

void MessageUnlockGearItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUnlockGearItem, (unsigned char*)this);
}

void MessageAskItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskItem, (unsigned char*)this);
}

void MessageAskItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskItem, (unsigned char*)this);
}

void MessageAskWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskWeapon, (unsigned char*)this);
}

void MessageAskWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskWeapon, (unsigned char*)this);
}

void MessageAskMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskMagazine, (unsigned char*)this);
}

void MessageAskMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskMagazine, (unsigned char*)this);
}

void MessageAskBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskBackpack, (unsigned char*)this);
}

void MessageAskBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskBackpack, (unsigned char*)this);
}

void MessageReplaceItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReplaceItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReplaceItem, (unsigned char*)this);
}

void MessageReplaceItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReplaceItem, (unsigned char*)this);
}

void MessageStorePendingItem::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageStorePendingItem, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageStorePendingItem, (unsigned char*)this);
}

void MessageStorePendingItem::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageStorePendingItem, (unsigned char*)this);
}

void MessageReplaceWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReplaceWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReplaceWeapon, (unsigned char*)this);
}

void MessageReplaceWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReplaceWeapon, (unsigned char*)this);
}

void MessageReplaceMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReplaceMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReplaceMagazine, (unsigned char*)this);
}

void MessageReplaceMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReplaceMagazine, (unsigned char*)this);
}

void MessageReplaceBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReplaceBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReplaceBackpack, (unsigned char*)this);
}

void MessageReplaceBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReplaceBackpack, (unsigned char*)this);
}

void MessageReturnWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReturnWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReturnWeapon, (unsigned char*)this);
}

void MessageReturnWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReturnWeapon, (unsigned char*)this);
}

void MessageReturnMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReturnMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReturnMagazine, (unsigned char*)this);
}

void MessageReturnMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReturnMagazine, (unsigned char*)this);
}

void MessageReturnBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReturnBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReturnBackpack, (unsigned char*)this);
}

void MessageReturnBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReturnBackpack, (unsigned char*)this);
}

void MessageCancelTakeFlag::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCancelTakeFlag, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCancelTakeFlag, (unsigned char*)this);
}

void MessageCancelTakeFlag::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCancelTakeFlag, (unsigned char*)this);
}

void MessagePoolAskWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolAskWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolAskWeapon, (unsigned char*)this);
}

void MessagePoolAskWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolAskWeapon, (unsigned char*)this);
}

void MessagePoolAskMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolAskMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolAskMagazine, (unsigned char*)this);
}

void MessagePoolAskMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolAskMagazine, (unsigned char*)this);
}

void MessagePoolAskBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolAskBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolAskBackpack, (unsigned char*)this);
}

void MessagePoolAskBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolAskBackpack, (unsigned char*)this);
}

void MessagePoolReplaceWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReplaceWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReplaceWeapon, (unsigned char*)this);
}

void MessagePoolReplaceWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReplaceWeapon, (unsigned char*)this);
}

void MessagePoolReplaceMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReplaceMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReplaceMagazine, (unsigned char*)this);
}

void MessagePoolReplaceMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReplaceMagazine, (unsigned char*)this);
}

void MessagePoolReplaceBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReplaceBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReplaceBackpack, (unsigned char*)this);
}

void MessagePoolReplaceBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReplaceBackpack, (unsigned char*)this);
}

void MessagePoolReturnWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReturnWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReturnWeapon, (unsigned char*)this);
}

void MessagePoolReturnWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReturnWeapon, (unsigned char*)this);
}

void MessagePoolReturnMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReturnMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReturnMagazine, (unsigned char*)this);
}

void MessagePoolReturnMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReturnMagazine, (unsigned char*)this);
}

void MessagePoolReturnBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePoolReturnBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePoolReturnBackpack, (unsigned char*)this);
}

void MessagePoolReturnBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePoolReturnBackpack, (unsigned char*)this);
}

void MessageAskSetUnitLoadOutFromClassName::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskSetUnitLoadOutFromClassName, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskSetUnitLoadOutFromClassName, (unsigned char*)this);
}

void MessageAskSetUnitLoadOutFromClassName::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskSetUnitLoadOutFromClassName, (unsigned char*)this);
}

void MessageAskSetUnitLoadOutFromRawData::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskSetUnitLoadOutFromRawData, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskSetUnitLoadOutFromRawData, (unsigned char*)this);
}

void MessageAskSetUnitLoadOutFromRawData::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskSetUnitLoadOutFromRawData, (unsigned char*)this);
}

MessageUpdateWeaponsInfo::~MessageUpdateWeaponsInfo() {
    for (auto it : _magazines)
        delete it;

}
void MessageUpdateWeaponsInfo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateWeaponsInfo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateWeaponsInfo, (unsigned char*)this);
}

void MessageUpdateWeaponsInfo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateWeaponsInfo, (unsigned char*)this);
}

void MessageUpdateWeaponSlotsData::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateWeaponSlotsData, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateWeaponSlotsData, (unsigned char*)this);
}

void MessageUpdateWeaponSlotsData::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateWeaponSlotsData, (unsigned char*)this);
}

void MessageUpdateWeaponsPool::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateWeaponsPool, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateWeaponsPool, (unsigned char*)this);
}

void MessageUpdateWeaponsPool::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateWeaponsPool, (unsigned char*)this);
}

MessageUpdateMagazinesPool::~MessageUpdateMagazinesPool() {
    for (auto it : _magazines)
        delete it;

}
void MessageUpdateMagazinesPool::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateMagazinesPool, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateMagazinesPool, (unsigned char*)this);
}

void MessageUpdateMagazinesPool::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateMagazinesPool, (unsigned char*)this);
}

void MessageUpdateBackpacksPool::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateBackpacksPool, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateBackpacksPool, (unsigned char*)this);
}

void MessageUpdateBackpacksPool::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateBackpacksPool, (unsigned char*)this);
}

void MessageSite::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSite, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSite, (unsigned char*)this);
}

void MessageSite::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSite, (unsigned char*)this);
}

void MessageUpdateSlotMgr::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateSlotMgr, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateSlotMgr, (unsigned char*)this);
}

void MessageUpdateSlotMgr::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateSlotMgr, (unsigned char*)this);
}

void MessageSetRoleIndex::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetRoleIndex, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetRoleIndex, (unsigned char*)this);
}

void MessageSetRoleIndex::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetRoleIndex, (unsigned char*)this);
}

void MessageCreateSeagull::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateSeagull, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateSeagull, (unsigned char*)this);
}

void MessageCreateSeagull::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateSeagull, (unsigned char*)this);
}

void MessageMsgVLoadMagazine::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVLoadMagazine, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVLoadMagazine, (unsigned char*)this);
}

void MessageMsgVLoadMagazine::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVLoadMagazine, (unsigned char*)this);
}

void MessageMsgVWatchTgt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVWatchTgt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVWatchTgt, (unsigned char*)this);
}

void MessageMsgVWatchTgt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVWatchTgt, (unsigned char*)this);
}

void MessageMsgVWatchPos::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMsgVWatchPos, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMsgVWatchPos, (unsigned char*)this);
}

void MessageMsgVWatchPos::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMsgVWatchPos, (unsigned char*)this);
}

void MessageRevealTarget::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRevealTarget, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRevealTarget, (unsigned char*)this);
}

void MessageRevealTarget::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRevealTarget, (unsigned char*)this);
}

void MessageCreateDynSoundSource::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateDynSoundSource, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateDynSoundSource, (unsigned char*)this);
}

void MessageCreateDynSoundSource::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateDynSoundSource, (unsigned char*)this);
}

void MessageCreateDestructionEffects::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateDestructionEffects, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateDestructionEffects, (unsigned char*)this);
}

void MessageCreateDestructionEffects::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateDestructionEffects, (unsigned char*)this);
}

void MessageRemoteMuteList::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteMuteList, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteMuteList, (unsigned char*)this);
}

void MessageRemoteMuteList::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteMuteList, (unsigned char*)this);
}

void MessageAskForApplyDoDamage::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForApplyDoDamage, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForApplyDoDamage, (unsigned char*)this);
}

void MessageAskForApplyDoDamage::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForApplyDoDamage, (unsigned char*)this);
}

void MessageAskForApplyBleeding::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForApplyBleeding, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForApplyBleeding, (unsigned char*)this);
}

void MessageAskForApplyBleeding::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForApplyBleeding, (unsigned char*)this);
}

void MessageAskForStatsWrite::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForStatsWrite, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForStatsWrite, (unsigned char*)this);
}

void MessageAskForStatsWrite::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForStatsWrite, (unsigned char*)this);
}

void MessageLocalizedChat::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLocalizedChat, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLocalizedChat, (unsigned char*)this);
}

void MessageLocalizedChat::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLocalizedChat, (unsigned char*)this);
}

void MessageCreateTurret::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateTurret, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateTurret, (unsigned char*)this);
}

void MessageCreateTurret::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateTurret, (unsigned char*)this);
}

void MessageVoteMission::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVoteMission, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVoteMission, (unsigned char*)this);
}

void MessageVoteMission::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVoteMission, (unsigned char*)this);
}

void MessageVotingMissionProgress::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVotingMissionProgress, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVotingMissionProgress, (unsigned char*)this);
}

void MessageVotingMissionProgress::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVotingMissionProgress, (unsigned char*)this);
}

void MessagePlayerBan::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerBan, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerBan, (unsigned char*)this);
}

void MessagePlayerBan::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerBan, (unsigned char*)this);
}

void MessagePlayerBanSelf::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerBanSelf, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerBanSelf, (unsigned char*)this);
}

void MessagePlayerBanSelf::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerBanSelf, (unsigned char*)this);
}

void MessageServerTimeout::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerTimeout, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerTimeout, (unsigned char*)this);
}

void MessageServerTimeout::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerTimeout, (unsigned char*)this);
}

void MessageAcceptedKey::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAcceptedKey, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAcceptedKey, (unsigned char*)this);
}

void MessageAcceptedKey::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAcceptedKey, (unsigned char*)this);
}

void MessageAdditionalSignedFiles::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAdditionalSignedFiles, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAdditionalSignedFiles, (unsigned char*)this);
}

void MessageAdditionalSignedFiles::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAdditionalSignedFiles, (unsigned char*)this);
}

void MessageDataSignatureAsk::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDataSignatureAsk, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDataSignatureAsk, (unsigned char*)this);
}

void MessageDataSignatureAsk::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDataSignatureAsk, (unsigned char*)this);
}

void MessageDataSignatureAnswer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDataSignatureAnswer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDataSignatureAnswer, (unsigned char*)this);
}

void MessageDataSignatureAnswer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDataSignatureAnswer, (unsigned char*)this);
}

void MessageHackedData::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageHackedData, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageHackedData, (unsigned char*)this);
}

void MessageHackedData::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageHackedData, (unsigned char*)this);
}

void MessageCreateAITeam::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateAITeam, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateAITeam, (unsigned char*)this);
}

void MessageCreateAITeam::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateAITeam, (unsigned char*)this);
}

void MessageUpdateAITeam::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAITeam, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAITeam, (unsigned char*)this);
}

void MessageUpdateAITeam::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAITeam, (unsigned char*)this);
}

void MessageUpdatePositionTurret::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionTurret, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionTurret, (unsigned char*)this);
}

void MessageUpdatePositionTurret::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionTurret, (unsigned char*)this);
}

void MessageStaticObjectDestructed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageStaticObjectDestructed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageStaticObjectDestructed, (unsigned char*)this);
}

void MessageStaticObjectDestructed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageStaticObjectDestructed, (unsigned char*)this);
}

void MessageAskConnectVoice::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskConnectVoice, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskConnectVoice, (unsigned char*)this);
}

void MessageAskConnectVoice::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskConnectVoice, (unsigned char*)this);
}

void MessageConnectVoiceDirect::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageConnectVoiceDirect, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageConnectVoiceDirect, (unsigned char*)this);
}

void MessageConnectVoiceDirect::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageConnectVoiceDirect, (unsigned char*)this);
}

void MessageConnectVoiceNatNeg::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageConnectVoiceNatNeg, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageConnectVoiceNatNeg, (unsigned char*)this);
}

void MessageConnectVoiceNatNeg::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageConnectVoiceNatNeg, (unsigned char*)this);
}

void MessageDisconnect::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDisconnect, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDisconnect, (unsigned char*)this);
}

void MessageDisconnect::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDisconnect, (unsigned char*)this);
}

void MessageWaypointCreate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWaypointCreate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWaypointCreate, (unsigned char*)this);
}

void MessageWaypointCreate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWaypointCreate, (unsigned char*)this);
}

void MessageWaypointUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWaypointUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWaypointUpdate, (unsigned char*)this);
}

void MessageWaypointUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWaypointUpdate, (unsigned char*)this);
}

void MessageWaypointDelete::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWaypointDelete, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWaypointDelete, (unsigned char*)this);
}

void MessageWaypointDelete::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWaypointDelete, (unsigned char*)this);
}

void MessageHCSetGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageHCSetGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageHCSetGroup, (unsigned char*)this);
}

void MessageHCSetGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageHCSetGroup, (unsigned char*)this);
}

void MessageHCRemoveGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageHCRemoveGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageHCRemoveGroup, (unsigned char*)this);
}

void MessageHCRemoveGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageHCRemoveGroup, (unsigned char*)this);
}

void MessageHCClearGroups::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageHCClearGroups, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageHCClearGroups, (unsigned char*)this);
}

void MessageHCClearGroups::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageHCClearGroups, (unsigned char*)this);
}

void MessageMissionStats::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMissionStats, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMissionStats, (unsigned char*)this);
}

void MessageMissionStats::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMissionStats, (unsigned char*)this);
}

void MessageAskForFireWeapon::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForFireWeapon, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForFireWeapon, (unsigned char*)this);
}

void MessageAskForFireWeapon::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForFireWeapon, (unsigned char*)this);
}

void MessageAskForGetInWantsPlayer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForGetInWantsPlayer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForGetInWantsPlayer, (unsigned char*)this);
}

void MessageAskForGetInWantsPlayer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForGetInWantsPlayer, (unsigned char*)this);
}

void MessageAskForOrderGetIn::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForOrderGetIn, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForOrderGetIn, (unsigned char*)this);
}

void MessageAskForOrderGetIn::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForOrderGetIn, (unsigned char*)this);
}

void MessageAskForAllowGetIn::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAllowGetIn, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAllowGetIn, (unsigned char*)this);
}

void MessageAskForAllowGetIn::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAllowGetIn, (unsigned char*)this);
}

void MessageAskForAirportSetSide::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAirportSetSide, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAirportSetSide, (unsigned char*)this);
}

void MessageAskForAirportSetSide::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAirportSetSide, (unsigned char*)this);
}

void MessageAskForArbitration::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForArbitration, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForArbitration, (unsigned char*)this);
}

void MessageAskForArbitration::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForArbitration, (unsigned char*)this);
}

void MessageUpdateDamageVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateDamageVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateDamageVehicle, (unsigned char*)this);
}

void MessageUpdateDamageVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateDamageVehicle, (unsigned char*)this);
}

void MessageBattlEye::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageBattlEye, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageBattlEye, (unsigned char*)this);
}

void MessageBattlEye::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageBattlEye, (unsigned char*)this);
}

void MessageAskForTeamSwitch::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForTeamSwitch, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForTeamSwitch, (unsigned char*)this);
}

void MessageAskForTeamSwitch::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForTeamSwitch, (unsigned char*)this);
}

void MessageTeamSwitchResult::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTeamSwitchResult, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTeamSwitchResult, (unsigned char*)this);
}

void MessageTeamSwitchResult::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTeamSwitchResult, (unsigned char*)this);
}

void MessageFinishTeamSwitch::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageFinishTeamSwitch, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageFinishTeamSwitch, (unsigned char*)this);
}

void MessageFinishTeamSwitch::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageFinishTeamSwitch, (unsigned char*)this);
}

MessageKBReact::~MessageKBReact() {
    for (auto it : _arguments)
        delete it;

}
void MessageKBReact::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageKBReact, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageKBReact, (unsigned char*)this);
}

void MessageKBReact::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageKBReact, (unsigned char*)this);
}

void MessageObjectSetVariable::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjectSetVariable, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjectSetVariable, (unsigned char*)this);
}

void MessageObjectSetVariable::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjectSetVariable, (unsigned char*)this);
}

void MessageObjectSetVariablesCollection::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjectSetVariablesCollection, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjectSetVariablesCollection, (unsigned char*)this);
}

void MessageObjectSetVariablesCollection::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjectSetVariablesCollection, (unsigned char*)this);
}

void MessageWaypointsCopy::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageWaypointsCopy, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageWaypointsCopy, (unsigned char*)this);
}

void MessageWaypointsCopy::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageWaypointsCopy, (unsigned char*)this);
}

void MessageAttachObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAttachObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAttachObject, (unsigned char*)this);
}

void MessageAttachObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAttachObject, (unsigned char*)this);
}

void MessageDetachObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDetachObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDetachObject, (unsigned char*)this);
}

void MessageDetachObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDetachObject, (unsigned char*)this);
}

void MessageGroupSetVariable::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSetVariable, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSetVariable, (unsigned char*)this);
}

void MessageGroupSetVariable::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSetVariable, (unsigned char*)this);
}

void MessageCustomFile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCustomFile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCustomFile, (unsigned char*)this);
}

void MessageCustomFile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCustomFile, (unsigned char*)this);
}

MessageCustomFileList::~MessageCustomFileList() {
    for (auto it : _fileList)
        delete it;

}
void MessageCustomFileList::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCustomFileList, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCustomFileList, (unsigned char*)this);
}

void MessageCustomFileList::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCustomFileList, (unsigned char*)this);
}

void MessageCustomFilesWanted::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCustomFilesWanted, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCustomFilesWanted, (unsigned char*)this);
}

void MessageCustomFilesWanted::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCustomFilesWanted, (unsigned char*)this);
}

void MessageDeleteCustomFiles::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDeleteCustomFiles, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDeleteCustomFiles, (unsigned char*)this);
}

void MessageDeleteCustomFiles::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDeleteCustomFiles, (unsigned char*)this);
}

void MessagePlayerRoleUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerRoleUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerRoleUpdate, (unsigned char*)this);
}

void MessagePlayerRoleUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerRoleUpdate, (unsigned char*)this);
}

void MessageNatNegResult::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNatNegResult, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNatNegResult, (unsigned char*)this);
}

void MessageNatNegResult::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNatNegResult, (unsigned char*)this);
}

void MessageUpdateClientInfoDpid::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateClientInfoDpid, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateClientInfoDpid, (unsigned char*)this);
}

void MessageUpdateClientInfoDpid::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateClientInfoDpid, (unsigned char*)this);
}

void MessageServerTime::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerTime, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerTime, (unsigned char*)this);
}

void MessageServerTime::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerTime, (unsigned char*)this);
}

void MessageUpdateDoor::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateDoor, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateDoor, (unsigned char*)this);
}

void MessageUpdateDoor::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateDoor, (unsigned char*)this);
}

void MessageUpdatePositionDoor::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionDoor, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionDoor, (unsigned char*)this);
}

void MessageUpdatePositionDoor::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionDoor, (unsigned char*)this);
}

void MessageGroupSetUnconsciousLeader::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSetUnconsciousLeader, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSetUnconsciousLeader, (unsigned char*)this);
}

void MessageGroupSetUnconsciousLeader::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSetUnconsciousLeader, (unsigned char*)this);
}

void MessageGroupSelectLeader::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSelectLeader, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSelectLeader, (unsigned char*)this);
}

void MessageGroupSelectLeader::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSelectLeader, (unsigned char*)this);
}

void MessageAskForAssignTeam::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAssignTeam, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAssignTeam, (unsigned char*)this);
}

void MessageAskForAssignTeam::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAssignTeam, (unsigned char*)this);
}

void MessageLoadedFromSave::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLoadedFromSave, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLoadedFromSave, (unsigned char*)this);
}

void MessageLoadedFromSave::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLoadedFromSave, (unsigned char*)this);
}

void MessageServerDifficulty::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerDifficulty, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerDifficulty, (unsigned char*)this);
}

void MessageServerDifficulty::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerDifficulty, (unsigned char*)this);
}

void MessageServerAdmin::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerAdmin, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerAdmin, (unsigned char*)this);
}

void MessageServerAdmin::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerAdmin, (unsigned char*)this);
}

void MessageTakeBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTakeBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTakeBackpack, (unsigned char*)this);
}

void MessageTakeBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTakeBackpack, (unsigned char*)this);
}

void MessageAssemble::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAssemble, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAssemble, (unsigned char*)this);
}

void MessageAssemble::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAssemble, (unsigned char*)this);
}

void MessageDisAssemble::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDisAssemble, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDisAssemble, (unsigned char*)this);
}

void MessageDisAssemble::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDisAssemble, (unsigned char*)this);
}

void MessageAskProcessDisAssemble::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskProcessDisAssemble, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskProcessDisAssemble, (unsigned char*)this);
}

void MessageAskProcessDisAssemble::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskProcessDisAssemble, (unsigned char*)this);
}

void MessageShowGroupDir::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageShowGroupDir, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageShowGroupDir, (unsigned char*)this);
}

void MessageShowGroupDir::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageShowGroupDir, (unsigned char*)this);
}

void MessageAskForSetMaxHitZoneDamage::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetMaxHitZoneDamage, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetMaxHitZoneDamage, (unsigned char*)this);
}

void MessageAskForSetMaxHitZoneDamage::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetMaxHitZoneDamage, (unsigned char*)this);
}

void MessageAskForEnableVMode::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForEnableVMode, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForEnableVMode, (unsigned char*)this);
}

void MessageAskForEnableVMode::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForEnableVMode, (unsigned char*)this);
}

void MessageAskForForceGunLight::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForForceGunLight, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForForceGunLight, (unsigned char*)this);
}

void MessageAskForForceGunLight::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForForceGunLight, (unsigned char*)this);
}

void MessageAskForIRLaser::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForIRLaser, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForIRLaser, (unsigned char*)this);
}

void MessageAskForIRLaser::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForIRLaser, (unsigned char*)this);
}

void MessageAskForVehicleDoorState::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForVehicleDoorState, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForVehicleDoorState, (unsigned char*)this);
}

void MessageAskForVehicleDoorState::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForVehicleDoorState, (unsigned char*)this);
}

void MessageAskForChangeSide::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForChangeSide, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForChangeSide, (unsigned char*)this);
}

void MessageAskForChangeSide::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForChangeSide, (unsigned char*)this);
}

void MessageVehMPEventHandlers::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVehMPEventHandlers, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVehMPEventHandlers, (unsigned char*)this);
}

void MessageVehMPEventHandlers::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVehMPEventHandlers, (unsigned char*)this);
}

void MessageVehMPEvent::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageVehMPEvent, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageVehMPEvent, (unsigned char*)this);
}

void MessageVehMPEvent::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageVehMPEvent, (unsigned char*)this);
}

void MessageMissionMPEvent::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageMissionMPEvent, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageMissionMPEvent, (unsigned char*)this);
}

void MessageMissionMPEvent::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageMissionMPEvent, (unsigned char*)this);
}

void MessageRemoteEntityEvent::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteEntityEvent, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteEntityEvent, (unsigned char*)this);
}

void MessageRemoteEntityEvent::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteEntityEvent, (unsigned char*)this);
}

void MessageClearWeaponCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageClearWeaponCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageClearWeaponCargo, (unsigned char*)this);
}

void MessageClearWeaponCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageClearWeaponCargo, (unsigned char*)this);
}

void MessageClearItemCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageClearItemCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageClearItemCargo, (unsigned char*)this);
}

void MessageClearItemCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageClearItemCargo, (unsigned char*)this);
}

void MessageClearMagazineCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageClearMagazineCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageClearMagazineCargo, (unsigned char*)this);
}

void MessageClearMagazineCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageClearMagazineCargo, (unsigned char*)this);
}

void MessageClearBackpackCargo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageClearBackpackCargo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageClearBackpackCargo, (unsigned char*)this);
}

void MessageClearBackpackCargo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageClearBackpackCargo, (unsigned char*)this);
}

void MessageCreateClientCameraPosition::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateClientCameraPosition, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateClientCameraPosition, (unsigned char*)this);
}

void MessageCreateClientCameraPosition::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateClientCameraPosition, (unsigned char*)this);
}

void MessageUpdateClientCameraPosition::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateClientCameraPosition, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateClientCameraPosition, (unsigned char*)this);
}

void MessageUpdateClientCameraPosition::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateClientCameraPosition, (unsigned char*)this);
}

void MessageCreatePlayerRuntime::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreatePlayerRuntime, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreatePlayerRuntime, (unsigned char*)this);
}

void MessageCreatePlayerRuntime::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreatePlayerRuntime, (unsigned char*)this);
}

void MessageUpdatePlayerRuntime::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePlayerRuntime, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePlayerRuntime, (unsigned char*)this);
}

void MessageUpdatePlayerRuntime::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePlayerRuntime, (unsigned char*)this);
}

void MessageAskRemoteControlled::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteControlled, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteControlled, (unsigned char*)this);
}

void MessageAskRemoteControlled::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteControlled, (unsigned char*)this);
}

void MessageAskForSetRank::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetRank, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetRank, (unsigned char*)this);
}

void MessageAskForSetRank::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetRank, (unsigned char*)this);
}

void MessageAskForVehicleControl::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForVehicleControl, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForVehicleControl, (unsigned char*)this);
}

void MessageAskForVehicleControl::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForVehicleControl, (unsigned char*)this);
}

void MessageOwnerChanged::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageOwnerChanged, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageOwnerChanged, (unsigned char*)this);
}

void MessageOwnerChanged::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageOwnerChanged, (unsigned char*)this);
}

void MessageLastOperPos::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLastOperPos, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLastOperPos, (unsigned char*)this);
}

void MessageLastOperPos::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLastOperPos, (unsigned char*)this);
}

void MessageFileSignatureAsk::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageFileSignatureAsk, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageFileSignatureAsk, (unsigned char*)this);
}

void MessageFileSignatureAsk::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageFileSignatureAsk, (unsigned char*)this);
}

void MessageFileSignatureAnswer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageFileSignatureAnswer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageFileSignatureAnswer, (unsigned char*)this);
}

void MessageFileSignatureAnswer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageFileSignatureAnswer, (unsigned char*)this);
}

void MessageChangeCreatorId::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageChangeCreatorId, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageChangeCreatorId, (unsigned char*)this);
}

void MessageChangeCreatorId::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageChangeCreatorId, (unsigned char*)this);
}

void MessageAskForAllowCrewInImmobile::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAllowCrewInImmobile, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAllowCrewInImmobile, (unsigned char*)this);
}

void MessageAskForAllowCrewInImmobile::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAllowCrewInImmobile, (unsigned char*)this);
}

void MessageAskForPilotLight::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForPilotLight, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForPilotLight, (unsigned char*)this);
}

void MessageAskForPilotLight::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForPilotLight, (unsigned char*)this);
}

void MessageCreateRadioChannel::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateRadioChannel, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateRadioChannel, (unsigned char*)this);
}

void MessageCreateRadioChannel::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateRadioChannel, (unsigned char*)this);
}

void MessageRadioChannelLabel::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChannelLabel, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChannelLabel, (unsigned char*)this);
}

void MessageRadioChannelLabel::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChannelLabel, (unsigned char*)this);
}

void MessageRadioChannelCallSign::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChannelCallSign, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChannelCallSign, (unsigned char*)this);
}

void MessageRadioChannelCallSign::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChannelCallSign, (unsigned char*)this);
}

void MessageRadioChannelUnits::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChannelUnits, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChannelUnits, (unsigned char*)this);
}

void MessageRadioChannelUnits::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChannelUnits, (unsigned char*)this);
}

void MessageSendAUMsg::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSendAUMsg, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSendAUMsg, (unsigned char*)this);
}

void MessageSendAUMsg::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSendAUMsg, (unsigned char*)this);
}

void MessageLockSupply::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLockSupply, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLockSupply, (unsigned char*)this);
}

void MessageLockSupply::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLockSupply, (unsigned char*)this);
}

void MessageUnlockSupply::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUnlockSupply, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUnlockSupply, (unsigned char*)this);
}

void MessageUnlockSupply::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUnlockSupply, (unsigned char*)this);
}

MessageReturnEquipment::~MessageReturnEquipment() {
    for (auto it : _weaponInfos)
        delete it;

    for (auto it : _magazines)
        delete it;

}
void MessageReturnEquipment::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageReturnEquipment, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageReturnEquipment, (unsigned char*)this);
}

void MessageReturnEquipment::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageReturnEquipment, (unsigned char*)this);
}

void MessageServerInfo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageServerInfo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageServerInfo, (unsigned char*)this);
}

void MessageServerInfo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageServerInfo, (unsigned char*)this);
}

void MessagePublicVariableTo::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicVariableTo, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicVariableTo, (unsigned char*)this);
}

void MessagePublicVariableTo::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicVariableTo, (unsigned char*)this);
}

void MessageUavTerminalCreateConnection::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUavTerminalCreateConnection, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUavTerminalCreateConnection, (unsigned char*)this);
}

void MessageUavTerminalCreateConnection::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUavTerminalCreateConnection, (unsigned char*)this);
}

void MessageUpdateInvisibleVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateInvisibleVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateInvisibleVehicle, (unsigned char*)this);
}

void MessageUpdateInvisibleVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateInvisibleVehicle, (unsigned char*)this);
}

void MessageRadioChatBroadcast::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRadioChatBroadcast, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRadioChatBroadcast, (unsigned char*)this);
}

void MessageRadioChatBroadcast::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRadioChatBroadcast, (unsigned char*)this);
}

void MessageSetObjectTexture::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetObjectTexture, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetObjectTexture, (unsigned char*)this);
}

void MessageSetObjectTexture::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetObjectTexture, (unsigned char*)this);
}

void MessageForceFlagTexture::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageForceFlagTexture, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageForceFlagTexture, (unsigned char*)this);
}

void MessageForceFlagTexture::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageForceFlagTexture, (unsigned char*)this);
}

void MessageAddSideScore::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddSideScore, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddSideScore, (unsigned char*)this);
}

void MessageAddSideScore::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddSideScore, (unsigned char*)this);
}

void MessageAskForSetVisibility::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetVisibility, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetVisibility, (unsigned char*)this);
}

void MessageAskForSetVisibility::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetVisibility, (unsigned char*)this);
}

void MessageAskForEnableSimulation::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForEnableSimulation, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForEnableSimulation, (unsigned char*)this);
}

void MessageAskForEnableSimulation::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForEnableSimulation, (unsigned char*)this);
}

void MessageAskForRemoveFromCenter::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForRemoveFromCenter, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForRemoveFromCenter, (unsigned char*)this);
}

void MessageAskForRemoveFromCenter::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForRemoveFromCenter, (unsigned char*)this);
}

void MessageAskForForceWeatherUpdate::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForForceWeatherUpdate, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForForceWeatherUpdate, (unsigned char*)this);
}

void MessageAskForForceWeatherUpdate::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForForceWeatherUpdate, (unsigned char*)this);
}

void MessageAskForSetPlanningMode::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetPlanningMode, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetPlanningMode, (unsigned char*)this);
}

void MessageAskForSetPlanningMode::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetPlanningMode, (unsigned char*)this);
}

void MessageAskForDisconnectUav::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDisconnectUav, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDisconnectUav, (unsigned char*)this);
}

void MessageAskForDisconnectUav::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDisconnectUav, (unsigned char*)this);
}

void MessageUavTerminalReleaseConnection::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUavTerminalReleaseConnection, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUavTerminalReleaseConnection, (unsigned char*)this);
}

void MessageUavTerminalReleaseConnection::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUavTerminalReleaseConnection, (unsigned char*)this);
}

void MessageAskForSetRemoveMode::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetRemoveMode, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetRemoveMode, (unsigned char*)this);
}

void MessageAskForSetRemoveMode::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetRemoveMode, (unsigned char*)this);
}

void MessageSetParticleClass::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetParticleClass, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetParticleClass, (unsigned char*)this);
}

void MessageSetParticleClass::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetParticleClass, (unsigned char*)this);
}

void MessageAskForCreateAndAddBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForCreateAndAddBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForCreateAndAddBackpack, (unsigned char*)this);
}

void MessageAskForCreateAndAddBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForCreateAndAddBackpack, (unsigned char*)this);
}

void MessageAskForDeleteBackpack::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDeleteBackpack, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDeleteBackpack, (unsigned char*)this);
}

void MessageAskForDeleteBackpack::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDeleteBackpack, (unsigned char*)this);
}

void MessageAskForDeleteGroup::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForDeleteGroup, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForDeleteGroup, (unsigned char*)this);
}

void MessageAskForDeleteGroup::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForDeleteGroup, (unsigned char*)this);
}

void MessageStartWeaponDeploy::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageStartWeaponDeploy, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageStartWeaponDeploy, (unsigned char*)this);
}

void MessageStartWeaponDeploy::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageStartWeaponDeploy, (unsigned char*)this);
}

void MessageStopWeaponDeploy::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageStopWeaponDeploy, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageStopWeaponDeploy, (unsigned char*)this);
}

void MessageStopWeaponDeploy::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageStopWeaponDeploy, (unsigned char*)this);
}

void MessageUpdatePositionTankOrCar::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionTankOrCar, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionTankOrCar, (unsigned char*)this);
}

void MessageUpdatePositionTankOrCar::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionTankOrCar, (unsigned char*)this);
}

void MessageAskRemoteExecServer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteExecServer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteExecServer, (unsigned char*)this);
}

void MessageAskRemoteExecServer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteExecServer, (unsigned char*)this);
}

void MessageAskRemoteExecServerNamed::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteExecServerNamed, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteExecServerNamed, (unsigned char*)this);
}

void MessageAskRemoteExecServerNamed::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteExecServerNamed, (unsigned char*)this);
}

void MessageAskRemoteExecClient::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteExecClient, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteExecClient, (unsigned char*)this);
}

void MessageAskRemoteExecClient::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteExecClient, (unsigned char*)this);
}

void MessageRemoteExecServer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecServer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecServer, (unsigned char*)this);
}

void MessageRemoteExecServer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecServer, (unsigned char*)this);
}

void MessageRemoteExecClient::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecClient, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecClient, (unsigned char*)this);
}

void MessageRemoteExecClient::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecClient, (unsigned char*)this);
}

void MessageRemoteExecUnJIP::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecUnJIP, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecUnJIP, (unsigned char*)this);
}

void MessageRemoteExecUnJIP::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecUnJIP, (unsigned char*)this);
}

void MessageNamespaceSetVariable::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNamespaceSetVariable, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNamespaceSetVariable, (unsigned char*)this);
}

void MessageNamespaceSetVariable::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNamespaceSetVariable, (unsigned char*)this);
}

void MessageAskRemoteExecClientOne::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteExecClientOne, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteExecClientOne, (unsigned char*)this);
}

void MessageAskRemoteExecClientOne::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteExecClientOne, (unsigned char*)this);
}

void MessageSetGroupIdentity::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetGroupIdentity, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetGroupIdentity, (unsigned char*)this);
}

void MessageSetGroupIdentity::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetGroupIdentity, (unsigned char*)this);
}

void MessageRemoteExecServerExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecServerExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecServerExt, (unsigned char*)this);
}

void MessageRemoteExecServerExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecServerExt, (unsigned char*)this);
}

void MessageRemoteExecClientExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecClientExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecClientExt, (unsigned char*)this);
}

void MessageRemoteExecClientExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecClientExt, (unsigned char*)this);
}

void MessageRemoteExecClientMulti::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecClientMulti, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecClientMulti, (unsigned char*)this);
}

void MessageRemoteExecClientMulti::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecClientMulti, (unsigned char*)this);
}

void MessageSetObjectMaterial::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetObjectMaterial, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetObjectMaterial, (unsigned char*)this);
}

void MessageSetObjectMaterial::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetObjectMaterial, (unsigned char*)this);
}

void MessageObjectSetVariableClient::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjectSetVariableClient, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjectSetVariableClient, (unsigned char*)this);
}

void MessageObjectSetVariableClient::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjectSetVariableClient, (unsigned char*)this);
}

void MessageObjectSetVariableExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjectSetVariableExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjectSetVariableExt, (unsigned char*)this);
}

void MessageObjectSetVariableExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjectSetVariableExt, (unsigned char*)this);
}

void MessageObjectSetVariableExtArray::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjectSetVariableExtArray, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjectSetVariableExtArray, (unsigned char*)this);
}

void MessageObjectSetVariableExtArray::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjectSetVariableExtArray, (unsigned char*)this);
}

void MessageGroupSetVariableClient::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSetVariableClient, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSetVariableClient, (unsigned char*)this);
}

void MessageGroupSetVariableClient::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSetVariableClient, (unsigned char*)this);
}

void MessageGroupSetVariableExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSetVariableExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSetVariableExt, (unsigned char*)this);
}

void MessageGroupSetVariableExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSetVariableExt, (unsigned char*)this);
}

void MessageGroupSetVariableExtArray::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageGroupSetVariableExtArray, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageGroupSetVariableExtArray, (unsigned char*)this);
}

void MessageGroupSetVariableExtArray::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageGroupSetVariableExtArray, (unsigned char*)this);
}

void MessageTeamMemberSetVariableExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTeamMemberSetVariableExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTeamMemberSetVariableExt, (unsigned char*)this);
}

void MessageTeamMemberSetVariableExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTeamMemberSetVariableExt, (unsigned char*)this);
}

void MessageTeamMemberSetVariableExtArray::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTeamMemberSetVariableExtArray, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTeamMemberSetVariableExtArray, (unsigned char*)this);
}

void MessageTeamMemberSetVariableExtArray::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTeamMemberSetVariableExtArray, (unsigned char*)this);
}

void MessageNamespaceSetVariableExt::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNamespaceSetVariableExt, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNamespaceSetVariableExt, (unsigned char*)this);
}

void MessageNamespaceSetVariableExt::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNamespaceSetVariableExt, (unsigned char*)this);
}

void MessageNamespaceSetVariableExtArray::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageNamespaceSetVariableExtArray, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageNamespaceSetVariableExtArray, (unsigned char*)this);
}

void MessageNamespaceSetVariableExtArray::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageNamespaceSetVariableExtArray, (unsigned char*)this);
}

void MessageSetVisibility::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSetVisibility, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSetVisibility, (unsigned char*)this);
}

void MessageSetVisibility::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSetVisibility, (unsigned char*)this);
}

void MessageSyncVarsInJIPQueue::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageSyncVarsInJIPQueue, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageSyncVarsInJIPQueue, (unsigned char*)this);
}

void MessageSyncVarsInJIPQueue::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageSyncVarsInJIPQueue, (unsigned char*)this);
}

void MessagePublicKey::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicKey, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicKey, (unsigned char*)this);
}

void MessagePublicKey::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicKey, (unsigned char*)this);
}

void MessagePublicKeyAck::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicKeyAck, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicKeyAck, (unsigned char*)this);
}

void MessagePublicKeyAck::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicKeyAck, (unsigned char*)this);
}

void MessagePublicKeyBE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicKeyBE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicKeyBE, (unsigned char*)this);
}

void MessagePublicKeyBE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicKeyBE, (unsigned char*)this);
}

void MessagePublicKeyAckBE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePublicKeyAckBE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePublicKeyAckBE, (unsigned char*)this);
}

void MessagePublicKeyAckBE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePublicKeyAckBE, (unsigned char*)this);
}

void MessageCreateEntitySimple::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateEntitySimple, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateEntitySimple, (unsigned char*)this);
}

void MessageCreateEntitySimple::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateEntitySimple, (unsigned char*)this);
}

void MessageObjHideAnimSection::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageObjHideAnimSection, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageObjHideAnimSection, (unsigned char*)this);
}

void MessageObjHideAnimSection::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageObjHideAnimSection, (unsigned char*)this);
}

void MessageAskRemoteExecServerNamedObjGrp::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskRemoteExecServerNamedObjGrp, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskRemoteExecServerNamedObjGrp, (unsigned char*)this);
}

void MessageAskRemoteExecServerNamedObjGrp::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskRemoteExecServerNamedObjGrp, (unsigned char*)this);
}

void MessageRemoteExecUnJIPObjGrp::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRemoteExecUnJIPObjGrp, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRemoteExecUnJIPObjGrp, (unsigned char*)this);
}

void MessageRemoteExecUnJIPObjGrp::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRemoteExecUnJIPObjGrp, (unsigned char*)this);
}

void MessageTransferFileAck::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTransferFileAck, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTransferFileAck, (unsigned char*)this);
}

void MessageTransferFileAck::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTransferFileAck, (unsigned char*)this);
}

void MessageAskForEnableActiveSensors::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForEnableActiveSensors, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForEnableActiveSensors, (unsigned char*)this);
}

void MessageAskForEnableActiveSensors::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForEnableActiveSensors, (unsigned char*)this);
}

void MessageAskForApplyObjectFlag::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForApplyObjectFlag, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForApplyObjectFlag, (unsigned char*)this);
}

void MessageAskForApplyObjectFlag::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForApplyObjectFlag, (unsigned char*)this);
}

void MessageAskForceAIActiveSensors::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForceAIActiveSensors, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForceAIActiveSensors, (unsigned char*)this);
}

void MessageAskForceAIActiveSensors::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForceAIActiveSensors, (unsigned char*)this);
}

void MessageAskSetReportRemoteTargets::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskSetReportRemoteTargets, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskSetReportRemoteTargets, (unsigned char*)this);
}

void MessageAskSetReportRemoteTargets::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskSetReportRemoteTargets, (unsigned char*)this);
}

void MessageAskSetReceiveRemoteTargets::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskSetReceiveRemoteTargets, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskSetReceiveRemoteTargets, (unsigned char*)this);
}

void MessageAskSetReceiveRemoteTargets::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskSetReceiveRemoteTargets, (unsigned char*)this);
}

void MessageAskSetReportOwnPosition::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskSetReportOwnPosition, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskSetReportOwnPosition, (unsigned char*)this);
}

void MessageAskSetReportOwnPosition::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskSetReportOwnPosition, (unsigned char*)this);
}

void MessageAddEPEForce::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddEPEForce, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddEPEForce, (unsigned char*)this);
}

void MessageAddEPEForce::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddEPEForce, (unsigned char*)this);
}

void MessageAddEPETorque::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAddEPETorque, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAddEPETorque, (unsigned char*)this);
}

void MessageAddEPETorque::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAddEPETorque, (unsigned char*)this);
}

void MessageBankCount::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageBankCount, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageBankCount, (unsigned char*)this);
}

void MessageBankCount::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageBankCount, (unsigned char*)this);
}

void MessagePlayerBE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePlayerBE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePlayerBE, (unsigned char*)this);
}

void MessagePlayerBE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePlayerBE, (unsigned char*)this);
}

void MessageAskForGetOutToPos::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForGetOutToPos, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForGetOutToPos, (unsigned char*)this);
}

void MessageAskForGetOutToPos::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForGetOutToPos, (unsigned char*)this);
}

void MessageDataHashCheckAsk::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDataHashCheckAsk, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDataHashCheckAsk, (unsigned char*)this);
}

void MessageDataHashCheckAsk::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDataHashCheckAsk, (unsigned char*)this);
}

void MessageDataHashCheckAnswer::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDataHashCheckAnswer, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDataHashCheckAnswer, (unsigned char*)this);
}

void MessageDataHashCheckAnswer::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDataHashCheckAnswer, (unsigned char*)this);
}

void MessageTransferDataHashCheck::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTransferDataHashCheck, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTransferDataHashCheck, (unsigned char*)this);
}

void MessageTransferDataHashCheck::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTransferDataHashCheck, (unsigned char*)this);
}

void MessageAskCheckCmdPwd::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskCheckCmdPwd, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskCheckCmdPwd, (unsigned char*)this);
}

void MessageAskCheckCmdPwd::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskCheckCmdPwd, (unsigned char*)this);
}

void MessageAcceptCheckCmdPwd::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAcceptCheckCmdPwd, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAcceptCheckCmdPwd, (unsigned char*)this);
}

void MessageAcceptCheckCmdPwd::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAcceptCheckCmdPwd, (unsigned char*)this);
}

void MessageDenyCheckCmdPwd::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDenyCheckCmdPwd, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDenyCheckCmdPwd, (unsigned char*)this);
}

void MessageDenyCheckCmdPwd::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDenyCheckCmdPwd, (unsigned char*)this);
}

void MessageUpdateCuratorCommander::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateCuratorCommander, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateCuratorCommander, (unsigned char*)this);
}

void MessageUpdateCuratorCommander::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateCuratorCommander, (unsigned char*)this);
}

void MessageAskForJoinCuratorCommander::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForJoinCuratorCommander, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForJoinCuratorCommander, (unsigned char*)this);
}

void MessageAskForJoinCuratorCommander::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForJoinCuratorCommander, (unsigned char*)this);
}

void MessageAskForJoinCuratorLogic::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForJoinCuratorLogic, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForJoinCuratorLogic, (unsigned char*)this);
}

void MessageAskForJoinCuratorLogic::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForJoinCuratorLogic, (unsigned char*)this);
}

void MessageAskForChangeCuratorPoints::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForChangeCuratorPoints, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForChangeCuratorPoints, (unsigned char*)this);
}

void MessageAskForChangeCuratorPoints::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForChangeCuratorPoints, (unsigned char*)this);
}

void MessageAskForAddCuratorEditableUnit::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAddCuratorEditableUnit, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAddCuratorEditableUnit, (unsigned char*)this);
}

void MessageAskForAddCuratorEditableUnit::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAddCuratorEditableUnit, (unsigned char*)this);
}

void MessageAskForAddCuratorArea::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForAddCuratorArea, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForAddCuratorArea, (unsigned char*)this);
}

void MessageAskForAddCuratorArea::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForAddCuratorArea, (unsigned char*)this);
}

void MessageAskForRemoveCuratorArea::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForRemoveCuratorArea, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForRemoveCuratorArea, (unsigned char*)this);
}

void MessageAskForRemoveCuratorArea::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForRemoveCuratorArea, (unsigned char*)this);
}

void MessageAskForChangeCuratorCameraMoveCeiling::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForChangeCuratorCameraMoveCeiling, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForChangeCuratorCameraMoveCeiling, (unsigned char*)this);
}

void MessageAskForChangeCuratorCameraMoveCeiling::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForChangeCuratorCameraMoveCeiling, (unsigned char*)this);
}

void MessageAskForSetCuratorActionCoef::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetCuratorActionCoef, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetCuratorActionCoef, (unsigned char*)this);
}

void MessageAskForSetCuratorActionCoef::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetCuratorActionCoef, (unsigned char*)this);
}

void MessageAskForSetCuratorWaypointCost::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSetCuratorWaypointCost, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSetCuratorWaypointCost, (unsigned char*)this);
}

void MessageAskForSetCuratorWaypointCost::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSetCuratorWaypointCost, (unsigned char*)this);
}

void MessageAskForModifyCuratorAllowedAddons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForModifyCuratorAllowedAddons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForModifyCuratorAllowedAddons, (unsigned char*)this);
}

void MessageAskForModifyCuratorAllowedAddons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForModifyCuratorAllowedAddons, (unsigned char*)this);
}

void MessageAskForChangeCuratorEditAreaType::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForChangeCuratorEditAreaType, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForChangeCuratorEditAreaType, (unsigned char*)this);
}

void MessageAskForChangeCuratorEditAreaType::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForChangeCuratorEditAreaType, (unsigned char*)this);
}

void MessageAskForPingCurator::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForPingCurator, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForPingCurator, (unsigned char*)this);
}

void MessageAskForPingCurator::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForPingCurator, (unsigned char*)this);
}

void MessagePolymorphPosition::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessagePolymorphPosition, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessagePolymorphPosition, (unsigned char*)this);
}

void MessagePolymorphPosition::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessagePolymorphPosition, (unsigned char*)this);
}

void MessageJointDOFs::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJointDOFs, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJointDOFs, (unsigned char*)this);
}

void MessageJointDOFs::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJointDOFs, (unsigned char*)this);
}

void MessageJointLimits::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJointLimits, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJointLimits, (unsigned char*)this);
}

void MessageJointLimits::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJointLimits, (unsigned char*)this);
}

void MessageJointDrives::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJointDrives, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJointDrives, (unsigned char*)this);
}

void MessageJointDrives::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJointDrives, (unsigned char*)this);
}

void MessageJointDescription::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJointDescription, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJointDescription, (unsigned char*)this);
}

void MessageJointDescription::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJointDescription, (unsigned char*)this);
}

void MessageJointParameters::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageJointParameters, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageJointParameters, (unsigned char*)this);
}

void MessageJointParameters::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageJointParameters, (unsigned char*)this);
}

void MessageCreateJointConnection::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateJointConnection, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateJointConnection, (unsigned char*)this);
}

void MessageCreateJointConnection::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateJointConnection, (unsigned char*)this);
}

void MessageAttachEPE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAttachEPE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAttachEPE, (unsigned char*)this);
}

void MessageAttachEPE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAttachEPE, (unsigned char*)this);
}

void MessageDetachEPE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageDetachEPE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageDetachEPE, (unsigned char*)this);
}

void MessageDetachEPE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageDetachEPE, (unsigned char*)this);
}

void MessageUpdateSmokeEPE::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateSmokeEPE, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateSmokeEPE, (unsigned char*)this);
}

void MessageUpdateSmokeEPE::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateSmokeEPE, (unsigned char*)this);
}

void MessageChangeVisibilityAI::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageChangeVisibilityAI, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageChangeVisibilityAI, (unsigned char*)this);
}

void MessageChangeVisibilityAI::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageChangeVisibilityAI, (unsigned char*)this);
}

void MessageUpdateRagdollMan::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateRagdollMan, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateRagdollMan, (unsigned char*)this);
}

void MessageUpdateRagdollMan::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateRagdollMan, (unsigned char*)this);
}

void MessageRagdollRequested::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRagdollRequested, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRagdollRequested, (unsigned char*)this);
}

void MessageRagdollRequested::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRagdollRequested, (unsigned char*)this);
}

void MessageRagdollSyncAll::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRagdollSyncAll, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRagdollSyncAll, (unsigned char*)this);
}

void MessageRagdollSyncAll::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRagdollSyncAll, (unsigned char*)this);
}

void MessageRagdollShotImpact::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageRagdollShotImpact, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageRagdollShotImpact, (unsigned char*)this);
}

void MessageRagdollShotImpact::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageRagdollShotImpact, (unsigned char*)this);
}

void MessageCreateHelicopterRTD::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateHelicopterRTD, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateHelicopterRTD, (unsigned char*)this);
}

void MessageCreateHelicopterRTD::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateHelicopterRTD, (unsigned char*)this);
}

void MessageUpdateHelicopterRTD::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateHelicopterRTD, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateHelicopterRTD, (unsigned char*)this);
}

void MessageUpdateHelicopterRTD::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateHelicopterRTD, (unsigned char*)this);
}

void MessageUpdatePositionHelicopterRTD::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionHelicopterRTD, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionHelicopterRTD, (unsigned char*)this);
}

void MessageUpdatePositionHelicopterRTD::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionHelicopterRTD, (unsigned char*)this);
}

void MessageCreateRopeObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageCreateRopeObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageCreateRopeObject, (unsigned char*)this);
}

void MessageCreateRopeObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageCreateRopeObject, (unsigned char*)this);
}

void MessageUpdateRopeObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateRopeObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateRopeObject, (unsigned char*)this);
}

void MessageUpdateRopeObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateRopeObject, (unsigned char*)this);
}

void MessageUpdatePositionRopeObject::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePositionRopeObject, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePositionRopeObject, (unsigned char*)this);
}

void MessageUpdatePositionRopeObject::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePositionRopeObject, (unsigned char*)this);
}

void MessageAskForEnableRopeAttach::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForEnableRopeAttach, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForEnableRopeAttach, (unsigned char*)this);
}

void MessageAskForEnableRopeAttach::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForEnableRopeAttach, (unsigned char*)this);
}

void MessageAskForSlingLoadingAction::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForSlingLoadingAction, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForSlingLoadingAction, (unsigned char*)this);
}

void MessageAskForSlingLoadingAction::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForSlingLoadingAction, (unsigned char*)this);
}

void MessageAskForRopeCut::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForRopeCut, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForRopeCut, (unsigned char*)this);
}

void MessageAskForRopeCut::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForRopeCut, (unsigned char*)this);
}

void MessageUpdateAnimationsVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAnimationsVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAnimationsVehicle, (unsigned char*)this);
}

void MessageUpdateAnimationsVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAnimationsVehicle, (unsigned char*)this);
}

void MessageUpdateAnimationsMan::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateAnimationsMan, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateAnimationsMan, (unsigned char*)this);
}

void MessageUpdateAnimationsMan::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateAnimationsMan, (unsigned char*)this);
}

MessageUpdatePersonWeapons::~MessageUpdatePersonWeapons() {
    for (auto it : _weapons)
        delete it;

    for (auto it : _magazines)
        delete it;

}
void MessageUpdatePersonWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePersonWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePersonWeapons, (unsigned char*)this);
}

void MessageUpdatePersonWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePersonWeapons, (unsigned char*)this);
}

void MessageUpdatePersonGear::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdatePersonGear, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdatePersonGear, (unsigned char*)this);
}

void MessageUpdatePersonGear::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdatePersonGear, (unsigned char*)this);
}

void MessageAskUpdatePersonWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskUpdatePersonWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskUpdatePersonWeapons, (unsigned char*)this);
}

void MessageAskUpdatePersonWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskUpdatePersonWeapons, (unsigned char*)this);
}

MessageUpdateTransportWeapons::~MessageUpdateTransportWeapons() {
    for (auto it : _weapons)
        delete it;

    for (auto it : _magazines)
        delete it;

}
void MessageUpdateTransportWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTransportWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTransportWeapons, (unsigned char*)this);
}

void MessageUpdateTransportWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTransportWeapons, (unsigned char*)this);
}

void MessageUpdateTransportGear::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTransportGear, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTransportGear, (unsigned char*)this);
}

void MessageUpdateTransportGear::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTransportGear, (unsigned char*)this);
}

void MessageAskUpdateTransportWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskUpdateTransportWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskUpdateTransportWeapons, (unsigned char*)this);
}

void MessageAskUpdateTransportWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskUpdateTransportWeapons, (unsigned char*)this);
}

MessageUpdateTurretWeapons::~MessageUpdateTurretWeapons() {
    for (auto it : _weapons)
        delete it;

    for (auto it : _magazines)
        delete it;

}
void MessageUpdateTurretWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTurretWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTurretWeapons, (unsigned char*)this);
}

void MessageUpdateTurretWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTurretWeapons, (unsigned char*)this);
}

void MessageUpdateTurretGear::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUpdateTurretGear, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUpdateTurretGear, (unsigned char*)this);
}

void MessageUpdateTurretGear::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUpdateTurretGear, (unsigned char*)this);
}

void MessageAskUpdateTurretWeapons::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskUpdateTurretWeapons, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskUpdateTurretWeapons, (unsigned char*)this);
}

void MessageAskUpdateTurretWeapons::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskUpdateTurretWeapons, (unsigned char*)this);
}

void MessageLoadVehicleInVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageLoadVehicleInVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageLoadVehicleInVehicle, (unsigned char*)this);
}

void MessageLoadVehicleInVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageLoadVehicleInVehicle, (unsigned char*)this);
}

void MessageUnloadVehicleInVehicle::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageUnloadVehicleInVehicle, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageUnloadVehicleInVehicle, (unsigned char*)this);
}

void MessageUnloadVehicleInVehicle::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageUnloadVehicleInVehicle, (unsigned char*)this);
}

void MessageAskForEnableVehicleTransporting::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageAskForEnableVehicleTransporting, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageAskForEnableVehicleTransporting, (unsigned char*)this);
}

void MessageAskForEnableVehicleTransporting::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageAskForEnableVehicleTransporting, (unsigned char*)this);
}

void MessageTacticalPing::queue_message(int to) {
    if (to == TO_CLIENT)
        g_parser->queue_message_to_client(NetworkMessageTacticalPing, (unsigned char*)this);
    else
        g_parser->queue_message_to_server(NetworkMessageTacticalPing, (unsigned char*)this);
}

void MessageTacticalPing::reencode_message(NetworkMessageRaw* src) {
    g_parser->reencode_message(src, NetworkMessageTacticalPing, (unsigned char*)this);
}

