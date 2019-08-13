#pragma once
#include "networkmessage.h"
#include "netmessage_structs.h"

// more macros B-)
#define GET_FORMAT(type) format = &GMsgFormats[Network##type]; format->m_struct_size = sizeof(type); typedef type TYPE;
#define PUSH_FORMAT_ITEM(name, data_type, compression, default_value, default_value_size)  { auto val = default_value; auto item = NetworkMessageFormatItem(); item.m_name = new char[sizeof(#name)]; item.m_specs.m_def_value = new char[default_value_size]; item.init(#name, data_type, compression, (void*)&val, default_value_size, offsetof(TYPE, _##name)); format->m_items.emplace_back(item); }

static NetworkMessageFormat GMsgFormats[NETWORK_MESSAGE_COUNT];

static void init_default_formats() {
    NetworkMessageFormat* format;

    {
        GET_FORMAT(MessageMsgFormatItem);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* def value was nullptr */);
        PUSH_FORMAT_ITEM(specs, NDTData, NCTNone, 0, 0 /* def value was nullptr */);
    }

    {
        GET_FORMAT(MessageMsgFormat);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(items, NDTObjectArray, NCTNone, NetworkMessageMsgFormatItem, 4);
    }

    {
        GET_FORMAT(MessagePlayer);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(server, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(vonDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(vonCodecQuality, NDTInteger, NCTNone, 3, 4);
        PUSH_FORMAT_ITEM(battlEye, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(steamServerId, NDTInt64, NCTNone, 0, 8);
        PUSH_FORMAT_ITEM(steamSecure, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sigVerRequired, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(regURL, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isJip, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageMessages);
    }

    {
        GET_FORMAT(MessageServerState);
        PUSH_FORMAT_ITEM(serverState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageClientState);
        PUSH_FORMAT_ITEM(clientState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessagePlayerClientState);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(clientState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageLogin);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(playerid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(inaddr, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(uid, NDTInt64, NCTNone, 0, 8);
        PUSH_FORMAT_ITEM(steamID, NDTInt64, NCTNone, 0, 8);
        PUSH_FORMAT_ITEM(ownerSteamID, NDTInt64, NCTNone, 0, 8);
        PUSH_FORMAT_ITEM(steamSessionTicket, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(face, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(glasses, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(speaker, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pitch, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(squad, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unitId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(fullname, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(email, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(icq, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(remark, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(filesCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(clientState, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(version, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(build, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(headlessClient, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isJip, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(userId, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(userGuest, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(cloudId, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(isVIP, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageLogout);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageSquad);
        PUSH_FORMAT_ITEM(id, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(nick, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(email, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(web, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(picture, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(title, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unitId, NDTInteger, NCTNone, -1, 4);
    }

    {
        GET_FORMAT(MessagePublicVariable);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageTeamMemberSetVariable);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageLogMsgOnServer);
        PUSH_FORMAT_ITEM(text, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(logInConsole, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageChat);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(text, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRadioChat);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(text, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(sentence, NDTSentence, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wordsClass, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRadioChatWave);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(senderName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wave, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetSpeaker);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(on, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageMissionHeader);
        PUSH_FORMAT_ITEM(gameType, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(island, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTLocalizedString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(description, NDTLocalizedString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(steamId, NDTInt64, NCTNone, 0, 8);
        PUSH_FORMAT_ITEM(fileName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fileDir, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fileSizeL, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(fileSizeH, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(fileCRC, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(respawn, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(respawnVehicleDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(bodyMinTime, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(bodyMaxTime, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(bodyLimit, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(bodyManagerMode, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(wreckMinTime, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(wreckMaxTime, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(wreckLimit, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(wreckManagerMode, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(minPlayerDistance, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(teamSwitchEnabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(disabledAI, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableAIDisable, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(aiKills, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(updateOnly, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hasMissionParams, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(noCopy, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffGroupIndicators, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffFriendlyTags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffEnemyTags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffDetectedMines, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffCommands, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffWaypoints, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffWeaponInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffStanceIndicator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffReducedDamage, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffStaminaBar, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffWeaponCrosshair, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffVisionAid, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffSquadRadar, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffThirdPersonView, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffCameraShake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffScoreTable, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffDeathMessages, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffVonID, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffMapContent, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(diffMiniMapAllowed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffAutomaticReporting, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffMultipleSaves, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(diffTacticalPing, NDTInteger, NCTNone, 255, 4);
        PUSH_FORMAT_ITEM(addOns, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(estimatedEndTime, NDTTime, NCTNone, -2147483647, 4);
        PUSH_FORMAT_ITEM(titleParam1, NDTLocalizedString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(valuesParam1, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(textsParam1, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(defValueParam1, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(titleParam2, NDTLocalizedString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(valuesParam2, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(textsParam2, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(defValueParam2, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(sizesParamArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(textsParamArray, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(valuesParamArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(titleParamArray, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(defaultParamArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(rtdServerForced, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(missionStatsID, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(dlcs, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skipLobby, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fileNameReal, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(serverStatsId, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePlayerRole);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(group, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(unit, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(unitIndexInGroup, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(vehicle, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(leader, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(description, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unitName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lifeState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageSelectPlayer);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(-340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00), 12);
        PUSH_FORMAT_ITEM(respawn, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAttachPerson);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageTransferFile);
        PUSH_FORMAT_ITEM(datamask, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(filenames, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(data, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(totSize, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(offset, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(totSegments, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(curSegment, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskMissionFile);
        PUSH_FORMAT_ITEM(valid, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageTransferMissionFile);
        PUSH_FORMAT_ITEM(path, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(data, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(totSize, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(offset, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(totSegments, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(curSegment, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageTransferFileToServer);
        PUSH_FORMAT_ITEM(datamask, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(filenames, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(data, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(totSize, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(offset, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(totSegments, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(curSegment, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForDamage);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(modelPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(val, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(valRange, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ammo, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(originDir, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAskForSetDamage);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(dammage, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(handleScore, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(ignoreHitPoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(immidiateEffect, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForSetSkill);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skill, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTNone, -1, 4);
    }

    {
        GET_FORMAT(MessageAskForGetIn);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoIndex, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(isFastMoveIn, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForAssignAs);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoIndex, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(unassign, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForMoveOutTo);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAskForRemoveVehicleFromGroup);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForGetOut);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(parachute, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(eject, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskWaitForGetOut);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForChangePosition);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 52, 4);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoIndex, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageAskForSelectWeapon);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForAmmo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(burst, NDTInteger, NCTSmallUnsigned, 1, 4);
    }

    {
        GET_FORMAT(MessageAskForAddImpulse);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(force, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(torque, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAskForMoveVector);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAskForMoveMatrix);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orient, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
    }

    {
        GET_FORMAT(MessageAskForJoinGroup);
        PUSH_FORMAT_ITEM(join, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(silent, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForJoinUnits);
        PUSH_FORMAT_ITEM(join, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(silent, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageExplosionDamageEffects);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(directHit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(componentIndex, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(hit, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(indirectHit, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(indirectHitRange, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(explosive, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(explosionEffectsRadius, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(surfNormal, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(inSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(outSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(dustness, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(explosionDir, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(enemyDamage, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(energyFactor, NDTFloat, NCTFloatMostly0To1, 1.00, 4);
        PUSH_FORMAT_ITEM(explosionFactor, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(damage, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageFireWeapon);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(dir, NDTVector, NCTFloat0To1, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(weapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(magazineCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(magazineId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(burstLeft, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(ammoLeft, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(magazineName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(visible, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateWeapons);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdateEntityAIWeapons, 4);
    }

    {
        GET_FORMAT(MessageAddWeapon);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfo, NDTObjectSRef, NCTNone, NetworkMessageNetWeaponInfo, 4);
    }

    {
        GET_FORMAT(MessageRemoveWeapon);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAddWeaponCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfo, NDTObjectSRef, NCTNone, NetworkMessageNetWeaponInfo, 4);
    }

    {
        GET_FORMAT(MessageRemoveWeaponCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfo, NDTObjectSRef, NCTNone, NetworkMessageNetWeaponInfo, 4);
    }

    {
        GET_FORMAT(MessageAddItemCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(item, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(ammo, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(opticsName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(opticsCreator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(opticsId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(muzzleName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzleCreator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(muzzleId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(flashlightName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flashlightCreator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(flashlightId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(underBarrelName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(underBarrelCreator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(underBarrelId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(primaryMag, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(secondaryMag, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoveItemCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
    }

    {
        GET_FORMAT(MessageModifyMagazineAmmoInCargo);
        PUSH_FORMAT_ITEM(containerEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(item, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(posInArray, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(newAmmo, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageSetUnitLoadOutFromClassName);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(className, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(firstItemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(uniformEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vestEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpackEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetUnitLoadOutFromRawData);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(firstItemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(uniformEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(uniform, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
        PUSH_FORMAT_ITEM(vestEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vest, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
        PUSH_FORMAT_ITEM(backpackEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
        PUSH_FORMAT_ITEM(containersInContainers, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAssignItemToSlot);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(item, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUnAssignItemFromSlot);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageOfferItemFromBody);
        PUSH_FORMAT_ITEM(fromBody, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targetUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTNone, 11, 4);
    }

    {
        GET_FORMAT(MessageLinkNewContainer);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(item, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targetType, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageReplaceContainer);
        PUSH_FORMAT_ITEM(targetSoldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fromSupply, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(item, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targetType, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAddMagazineCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(magazine, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(firstMagId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(count, NDTInteger, NCTNone, 1, 4);
    }

    {
        GET_FORMAT(MessageAddBackpackCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoveBackpackCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoveMagazineCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ammo, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAddMagazine);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazine, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessageRemoveMagazine);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ammo, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageVehicleInit);
        PUSH_FORMAT_ITEM(subject, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(init, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageVehicleDestroyed);
        PUSH_FORMAT_ITEM(killed, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shotInstigator, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(handleScore, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(ammo, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageStoreCreatedSite);
        PUSH_FORMAT_ITEM(site, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageDeleteCreatedSite);
        PUSH_FORMAT_ITEM(site, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRunInitSitesScript);
        PUSH_FORMAT_ITEM(site, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMarkerCreate);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(marker, NDTObject, NCTNone, NetworkMessageMarker, 4);
    }

    {
        GET_FORMAT(MessageMarkerDelete);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMarkerUpdate);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(newPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angle, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageSetFlagOwner);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(carrier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetFlagCarrier);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(carrier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVTarget);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVFire);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVMove);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(destination, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageMsgVFormation);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVSimpleCommand);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cmd, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(fakeCmd, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageMsgVLoad);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageMsgVAzimut);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(azimut, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageMsgVStopTurning);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(azimut, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageMsgVFireFailed);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageChangeOwner);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(owner, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(disconnected, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(prevOwner, NDTInteger, NCTNone, 1, 4);
    }

    {
        GET_FORMAT(MessagePlaySound);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(volume, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(frequency, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(soundId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(distance, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageDeleteObject);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageDeleteCommand);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(subgrp, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageCreateVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageCreateDetector);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(a, NDTFloat, NCTNone, 50.00, 4);
        PUSH_FORMAT_ITEM(b, NDTFloat, NCTNone, 50.00, 4);
        PUSH_FORMAT_ITEM(c, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(swapped, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(behaviourFlags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(angle, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(sinAngle, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(cosAngle, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(rectangular, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(activationBy, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(activationType, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(repeating, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeoutMin, NDTFloat, NCTNone, 50.00, 4);
        PUSH_FORMAT_ITEM(timeoutMid, NDTFloat, NCTNone, 50.00, 4);
        PUSH_FORMAT_ITEM(timeoutMax, NDTFloat, NCTNone, 50.00, 4);
        PUSH_FORMAT_ITEM(interruptable, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(action, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(assignedStatic, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(assignedVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(text, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(expCond, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(expActiv, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(expDesactiv, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(synchronizations, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(_syncId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(effects, NDTObject, NCTNone, NetworkMessageEffects, 4);
    }

    {
        GET_FORMAT(MessageUpdateDetector);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(assignedGroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateFlag);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(flagOwner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flagOwnerWanted, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flagTexture, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flagSide, NDTInteger, NCTSmallUnsigned, 4, 4);
    }

    {
        GET_FORMAT(MessageCreateShot);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(timeToLive, NDTFloat, NCTNone, 10.00, 4);
        PUSH_FORMAT_ITEM(createPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(createSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(createOrient, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzle, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateShot);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageCreateCrater);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(timeToLive, NDTFloat, NCTNone, 20.00, 4);
        PUSH_FORMAT_ITEM(size, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(effectsType, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(effectsTimeToLive, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(alpha, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(distToWater, NDTFloat, NCTNone, 1.00, 4);
    }

    {
        GET_FORMAT(MessageCreateCraterOnVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(timeToLive, NDTFloat, NCTNone, 20.00, 4);
        PUSH_FORMAT_ITEM(size, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(effectsType, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(effectsTimeToLive, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(alpha, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(distToWater, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(dir, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageCreateObjectDestructed);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(destroy, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(timeToLive, NDTFloat, NCTNone, 2.00, 4);
    }

    {
        GET_FORMAT(MessageCreateAICenter);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(skillCoef, NDTFloat, NCTFloat0To1, 0.50, 4);
        PUSH_FORMAT_ITEM(precisionCoef, NDTFloat, NCTFloat0To1, 0.50, 4);
    }

    {
        GET_FORMAT(MessageUpdateAICenter);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(friends0, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(friends1, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(friends2, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(friends3, NDTFloat, NCTNone, 1.00, 4);
    }

    {
        GET_FORMAT(MessageCreateAIGroup);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(center, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(varName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(waypoints, NDTObjectArray, NCTNone, NetworkMessageWaypoint, 4);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(clearIfEmpty, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateAIGroup);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(mainSubgroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(leader, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(semaphore, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(combatModeMinor, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(enemiesDetected, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(unknownsDetected, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(forceCourage, NDTFloat, NCTFloatM1ToP1, -1.00, 4);
        PUSH_FORMAT_ITEM(courage, NDTFloat, NCTFloat0To1, 1.00, 4);
        PUSH_FORMAT_ITEM(flee, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(waypointIndex, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(nextWaypointId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(attackEnabled, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(unitSlots, NDTObjectArray, NCTNone, NetworkMessageUnitSlot, 4);
        PUSH_FORMAT_ITEM(clearIfEmpty, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUnitSlot);
        PUSH_FORMAT_ITEM(healthState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageWaypoint);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(placement, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(completitionRadius, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idObject, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(housePos, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(combatMode, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(formation, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(speed, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(combat, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(forceBehaviour, NDTBool, NCTDefault, 0, 1);
        PUSH_FORMAT_ITEM(timeoutMin, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(timeoutMid, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(timeoutMax, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(description, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(expCond, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(expActiv, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(script, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(showWP, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(synchronizations, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(effects, NDTObject, NCTNone, NetworkMessageEffects, 4);
        PUSH_FORMAT_ITEM(visible, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(idWP, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(syncId, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(loiterRadius, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(loiterType, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageCreateAISubgroup);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateAISubgroup);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(leader, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(wantedPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(formation, NDTInteger, NCTSmallUnsigned, 5, 4);
        PUSH_FORMAT_ITEM(speedMode, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(lastPrec, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(formationCoef, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(direction, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageCreateAIBrain);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(firstName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lastName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(face, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(glasses, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(speaker, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pitch, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(rank, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(initExperience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(squadPicture, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(squadTitle, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soundName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skillsArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateAIBrain);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ability, NDTFloat, NCTFloat0To1, 0.20, 4);
        PUSH_FORMAT_ITEM(semaphore, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(combatModeMajor, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(dangerUntil, NDTTime, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(captive, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(lifeState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(disclosedStatus, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(getInAllowed, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(getInOrdered, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(remoteControlled, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(synchronizedObjects, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(professionStats, NDTObject, NCTNone, NetworkMessageUpdateProfessionStats, 4);
    }

    {
        GET_FORMAT(MessageUpdateAIBrainPath);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(house, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(housePos, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(wantedPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(planningMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 2, 4);
    }

    {
        GET_FORMAT(MessageCreateAIUnit);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(firstName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lastName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(face, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(glasses, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(speaker, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pitch, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(rank, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(initExperience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(squadPicture, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(squadTitle, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soundName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skillsArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(subgroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateAIUnit);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ability, NDTFloat, NCTFloat0To1, 0.20, 4);
        PUSH_FORMAT_ITEM(semaphore, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(combatModeMajor, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(dangerUntil, NDTTime, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(captive, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(lifeState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(disclosedStatus, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(getInAllowed, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(getInOrdered, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(remoteControlled, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(synchronizedObjects, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(professionStats, NDTObject, NCTNone, NetworkMessageUpdateProfessionStats, 4);
        PUSH_FORMAT_ITEM(formationAngle, NDTFloat, NCTFloatAngle, 0.00, 4);
        PUSH_FORMAT_ITEM(formationPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(assignedTeam, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateAIUnitPath);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(house, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(housePos, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(wantedPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(planningMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 2, 4);
    }

    {
        GET_FORMAT(MessageCreateAIAgent);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(firstName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lastName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(face, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(glasses, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(speaker, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pitch, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(rank, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(initExperience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(squadPicture, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(squadTitle, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soundName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skillsArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateAIAgent);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(experience, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ability, NDTFloat, NCTFloat0To1, 0.20, 4);
        PUSH_FORMAT_ITEM(semaphore, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(combatModeMajor, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(dangerUntil, NDTTime, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(captive, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(lifeState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(disclosedStatus, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(getInAllowed, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(getInOrdered, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(objectIdHistory, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(remoteControlled, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(synchronizedObjects, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(professionStats, NDTObject, NCTNone, NetworkMessageUpdateProfessionStats, 4);
    }

    {
        GET_FORMAT(MessageUpdateAIAgentPath);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(house, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(housePos, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(wantedPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(planningMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 2, 4);
    }

    {
        GET_FORMAT(MessageCreateCommand);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(subgroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enqueued, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(message, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targetE, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(destination, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(time, NDTTime, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(join, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(intParam, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(strParam, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(discretion, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(context, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(precision, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(intParam2, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageUpdateCommand);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(destination, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageUpdateVehicleAI);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateVehicleAIFull);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateVehicleBrain);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(remotePlayer, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(reportRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(receiveRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(reportOwnPosition, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateTransport);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateAnimal);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(remotePlayer, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(reportRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(receiveRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(reportOwnPosition, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(walkSpeedWanted, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(sideSpeedWanted, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(unitPosCommanded, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(unitPosScripted, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(flagCarrier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdatePositionAnimal);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(headXRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headYRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(lookXRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(lookYRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headXRotWantedCont, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headYRotWantedCont, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(move, NDTString, NCTStringMove, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateMan);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(remotePlayer, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(reportRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(receiveRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(reportOwnPosition, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hideBodyWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fatigueValue, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(walkSpeedWanted, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(sideSpeedWanted, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(unitPosCommanded, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(unitPosScripted, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(flagCarrier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(nvg, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(ladderBuilding, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ladderIndex, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(ladderPosition, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(irWanted, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(lightWanted, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(groundContainer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(healingActivated, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(healingFlag, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdatePositionMan);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(gunXRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(gunYRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headXRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headYRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(lookXRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(lookYRotWanted, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(move, NDTString, NCTStringMove, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gesture, NDTString, NCTStringMove, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isPersonTurret, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isMobileSwitching, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isReloadingMagazine, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateTankOrCar);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateTank);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionTank);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeAfterLastLandContact, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(rpmWanted, NDTFloat, NCTFloat0To2, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustLWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustRWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateTurret);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(locked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(crewHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(searchLightOn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(personTurretDisabledFlag, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateCar);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(plateNumber, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(scudState, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionCar);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeAfterLastLandContact, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(rpmWanted, NDTFloat, NCTFloat0To2, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(turnWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateAirplane);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotFlaps, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(gearDamage, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(pilotGear, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(vtolMode, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(planeState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(stopMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(stopResult, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(stopPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(openCabinWanted, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdatePositionAirplane);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(thrustWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustVectorWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(elevatorWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(rudderWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(aileronWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotSpeed, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateHelicopter);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(rotorSpeedWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotHeight, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(stopMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(stopResult, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(stopPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(pilotSpeedHelper, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(pilotHeightHelper, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(pilotDirHelper, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(pilotGear, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hoveringAutopilot, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(slingLoadingState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(slingLoadedCargo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slingLoadedCargoCenter, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(slingLoadingRopes, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdatePositionHelicopter);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(backRotorWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(mainRotorWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicForwardWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicAsideWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(rotorDiveWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(bankWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(diveWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotHeading, NDTFloat, NCTFloatAngle, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotDive, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageUpdateParachute);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(openState, NDTFloat, NCTFloatAngle, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateParaglide);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(deltaVertical, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(deltaHorizontal, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateShip);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(thrustLWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustRWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(stopPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(stopState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(sink, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionShip);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeAfterLastLandContact, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(rpmWanted, NDTFloat, NCTFloat0To2, 0.00, 4);
    }

    {
        GET_FORMAT(MessageMagazine);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ammo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(reload, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(reloadDuration, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(reloadMagazine, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(reloadMagazineTotal, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pylon, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageNetWeaponInfo);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(weaponCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(optics, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(opticsId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(opticsCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(muzzle, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzleId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(muzzleCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(flashlight, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flashlightId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(flashlightCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(underBarrel, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(underBarrelId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(underBarrelCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(primaryMag, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(secondaryMag, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessageNetMuzzleInfo);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzle, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazine, NDTObjectSRef, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessageContainerRawData);
        PUSH_FORMAT_ITEM(isGeneric, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(className, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isBackpack, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(magazinesDef, NDTObjectArray, NCTNone, NetworkMessageMagazineString, 4);
        PUSH_FORMAT_ITEM(magazinesCnt, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(items, NDTObjectArray, NCTNone, NetworkMessageCountedString, 4);
        PUSH_FORMAT_ITEM(weapons, NDTObjectArray, NCTNone, NetworkMessageCountedWeaponsString, 4);
        PUSH_FORMAT_ITEM(containers, NDTObjectArray, NCTNone, NetworkMessageContainerRawData, 4);
    }

    {
        GET_FORMAT(MessageMagazineString);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ammoLeft, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageCountedString);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(count, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageCountedWeaponsString);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(count, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(optics, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzle, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flashlight, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(underBarrel, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(primaryMuzzleMag, NDTObject, NCTNone, NetworkMessageMagazineString, 4);
        PUSH_FORMAT_ITEM(secondaryMuzzleMag, NDTObject, NCTNone, NetworkMessageMagazineString, 4);
    }

    {
        GET_FORMAT(MessagePersonInventoryDescriptor);
        PUSH_FORMAT_ITEM(primaryWeapon, NDTObjectSRef, NCTNone, NetworkMessageCountedWeaponsString, 4);
        PUSH_FORMAT_ITEM(secondaryWeapon, NDTObjectSRef, NCTNone, NetworkMessageCountedWeaponsString, 4);
        PUSH_FORMAT_ITEM(handgunWeapon, NDTObjectSRef, NCTNone, NetworkMessageCountedWeaponsString, 4);
        PUSH_FORMAT_ITEM(binocular, NDTObjectSRef, NCTNone, NetworkMessageCountedWeaponsString, 4);
        PUSH_FORMAT_ITEM(itemMap, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemCompass, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemWatch, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemRadio, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemGPS, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemGoggles, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemHMD, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemHeadgear, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(uniformDescriptor, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
        PUSH_FORMAT_ITEM(vestDescriptor, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
        PUSH_FORMAT_ITEM(backpackDescriptor, NDTObjectSRef, NCTNone, NetworkMessageContainerRawData, 4);
    }

    {
        GET_FORMAT(MessagePathPoint);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(cost, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateMotorcycle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(plateNumber, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(thrustWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(turnWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionMotorcycle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeAfterLastLandContact, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskForHideBody);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageNetworkCommand);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(content, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageIntegrityQuestion);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(offset, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(size, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageIntegrityAnswer);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(answer, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateSeagull);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(pilotHeading, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotHeight, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionSeagull);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(rpmWanted, NDTFloat, NCTFloat0To2, 0.00, 4);
        PUSH_FORMAT_ITEM(mainRotorWanted, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicForwardWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicAsideWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(wingDiveWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(thrustWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
    }

    {
        GET_FORMAT(MessagePlayerUpdate);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(minPing, NDTInteger, NCTSmallUnsigned, 10, 4);
        PUSH_FORMAT_ITEM(avgPing, NDTInteger, NCTSmallUnsigned, 100, 4);
        PUSH_FORMAT_ITEM(maxPing, NDTInteger, NCTSmallUnsigned, 1000, 4);
        PUSH_FORMAT_ITEM(minBandwidth, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(avgBandwidth, NDTInteger, NCTSmallUnsigned, 14, 4);
        PUSH_FORMAT_ITEM(maxBandwidth, NDTInteger, NCTSmallUnsigned, 28, 4);
        PUSH_FORMAT_ITEM(desync, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(rights, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(isJip, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateDamageVehicleAI);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isDestroyed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dammage, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDead, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateDamageObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isDestroyed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dammage, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageCreateHelicopter);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(rotorSpeed, NDTFloat, NCTFloat0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateClientInfo);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(cameraPosition, NDTVector, NCTVectorPositionCamera, vec3(-340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00), 12);
        PUSH_FORMAT_ITEM(cameraDirection, NDTVector, NCTFloat0To1, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(cameraFov, NDTFloat, NCTFloatMostly0To1, 0.75, 4);
    }

    {
        GET_FORMAT(MessageShowTarget);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageShowSuppressTarget);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageGroupSynchronization);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(synchronization, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(active, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageDetectorActivation);
        PUSH_FORMAT_ITEM(detector, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(active, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForCreateUnit);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(init, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(skill, NDTFloat, NCTNone, 0.50, 4);
        PUSH_FORMAT_ITEM(rank, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForDeleteVehicle);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForReceiveUnitAnswer);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(answer, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForGroupRespawn);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(from, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageGroupRespawnDone);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawn, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageMissionParams);
        PUSH_FORMAT_ITEM(param1, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(param2, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(paramsArray, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(updateOnly, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(disabledChatChannels, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(disabledVoNChannels, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateMine);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(active, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(triggerTimerTime, NDTFloat, NCTNone, 340282346638528859811704183484516925440.00, 4);
    }

    {
        GET_FORMAT(MessageAskForActivateMine);
        PUSH_FORMAT_ITEM(mine, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(activate, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForDetectedMine);
        PUSH_FORMAT_ITEM(center, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mine, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(addMine, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageDisposeObject);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(minTime, NDTTime, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(maxTime, NDTTime, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageVehicleDamaged);
        PUSH_FORMAT_ITEM(damaged, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(damage, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ammo, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateFireplace);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(burning, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForInflameFire);
        PUSH_FORMAT_ITEM(fireplace, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fire, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForAnimationPhase);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(animation, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(phase, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(bySource, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(speedCoef, NDTFloat, NCTNone, 1.00, 4);
    }

    {
        GET_FORMAT(MessageIncomingMissile);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageLaunchedCounterMeasures);
        PUSH_FORMAT_ITEM(cm, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(testedSystem, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(count, NDTInteger, NCTNone, 1, 4);
    }

    {
        GET_FORMAT(MessageSharedMineUsed);
        PUSH_FORMAT_ITEM(user, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mine, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(action, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageSetShotParents);
        PUSH_FORMAT_ITEM(shot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(newOwner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(newInstigator, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageWeaponLocked);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(locked, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageForceDeleteObject);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageJoinIntoUnit);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAIStatsMPRowCreate);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(role, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTSmallUnsigned, 1, 4);
    }

    {
        GET_FORMAT(MessageAIStatsMPRowUpdate);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(killsInfantry, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(killsSoft, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(killsArmor, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(killsAir, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(killsPlayers, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(customScore, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(liveStats, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(killed, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateSupply);
        PUSH_FORMAT_ITEM(fuelCargo, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(repairCargo, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(ammoCargo, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(itemContainersCnt, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(backpacksCnt, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(alloc, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(parentOwner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(deadBody, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(droppedFromBody, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageWeatherCreate);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(windSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(gust, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(rainDensityWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldOvercast, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFog, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFogDecay, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFogBase, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(worldWind, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(lightningsWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldTime, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(worldTimeMultip, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(wavesTimeWanted, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageWeatherUpdate);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(windSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(gust, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(rainDensityWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldOvercast, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFog, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFogDecay, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldFogBase, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(worldWind, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(lightningsWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(worldTime, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(worldTimeMultip, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(wavesTimeWanted, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageMuteList);
        PUSH_FORMAT_ITEM(list, NDTXUIDArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageVoiceOn);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(voiceOn, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageCleanupPlayer);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageLockGearItem);
        PUSH_FORMAT_ITEM(supply, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(user, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemID, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUnlockGearItem);
        PUSH_FORMAT_ITEM(supply, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(user, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemID, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskItem);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(itemType, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(supplyEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(actionContainer, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(actionMode, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskWeapon);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfo, NDTObjectSRef, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(slots, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(actionContainer, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskMagazine);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(actionContainer, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskBackpack);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageReplaceItem);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(itemCreator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(actionMode, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageStorePendingItem);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(itemId, NDTInteger, NCTNone, -1, 4);
    }

    {
        GET_FORMAT(MessageReplaceWeapon);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfo, NDTObjectSRef, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(actionContainer, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageReplaceMagazine);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazine, NDTObject, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(reload, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(actionContainer, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageReplaceBackpack);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageReturnWeapon);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageReturnMagazine);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazine, NDTObject, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessageReturnBackpack);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCancelTakeFlag);
        PUSH_FORMAT_ITEM(flag, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePoolAskWeapon);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slot, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(useBackpack, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessagePoolAskMagazine);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slot, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(useBackpack, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessagePoolAskBackpack);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePoolReplaceWeapon);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slot, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(useBackpack, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessagePoolReplaceMagazine);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(magazine, NDTObject, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(slot, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(useBackpack, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessagePoolReplaceBackpack);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(bagCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(bagId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(typeName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePoolReturnWeapon);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePoolReturnMagazine);
        PUSH_FORMAT_ITEM(magazine, NDTObject, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessagePoolReturnBackpack);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(typeName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskSetUnitLoadOutFromClassName);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(className, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskSetUnitLoadOutFromRawData);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(descriptor, NDTObjectSRef, NCTNone, NetworkMessagePersonInventoryDescriptor, 4);
    }

    {
        GET_FORMAT(MessageUpdateWeaponsInfo);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapons, NDTStringArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateWeaponSlotsData);
        PUSH_FORMAT_ITEM(mapName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(compassName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(watchesName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(radioName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gpsName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(headgearName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gogglesName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hmdName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(uniformName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(uniformEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vestName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vestEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateWeaponsPool);
        PUSH_FORMAT_ITEM(weapons, NDTStringArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateMagazinesPool);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
    }

    {
        GET_FORMAT(MessageUpdateBackpacksPool);
        PUSH_FORMAT_ITEM(creators, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ids, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMarker);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(text, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(linePointCoodinates, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(markerType, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(colorName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(alpha, NDTFloat, NCTFloat0To1, 1.00, 4);
        PUSH_FORMAT_ITEM(fillName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(a, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(b, NDTFloat, NCTNone, 1.00, 4);
        PUSH_FORMAT_ITEM(angle, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(drawBorder, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSite);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageEffects);
        PUSH_FORMAT_ITEM(condition, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(sound, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(voice, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soundEnv, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soundDet, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(track, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(titleType, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(titleEffect, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(title, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateSlotMgr);
        PUSH_FORMAT_ITEM(mapName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mapId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(mapCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(compassName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(compassId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(compassCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(watchesName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(watchesId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(watchesCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(radioName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(radioId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(radioCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(gpsName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gpsId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(gpsCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(headgearName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(headgearId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(headgearCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(gogglesName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gogglesId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(gogglesCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(hmdName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hmdId, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(hmdCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(uniformName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(uniformEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vestName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vestEnt, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateEntityAIWeapons);
        PUSH_FORMAT_ITEM(initialUpdate, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(currentWeapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(weapons, NDTObjectArray, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(loadedMagsHash, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(targetAimed, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(laserTargetOn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(laserTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetRoleIndex);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(roleIndex, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageCreateSeagull);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageMsgVLoadMagazine);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazineCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(magazineId, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(muzzle, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVWatchTgt);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMsgVWatchPos);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(receiver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageRevealTarget);
        PUSH_FORMAT_ITEM(to, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateDynSoundSource);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(soundName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateDestructionEffects);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(intensity, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(interval, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(fireIntensity, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(fireInterval, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(lifeTime, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(distToWater, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageRemoteMuteList);
        PUSH_FORMAT_ITEM(list, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForApplyDoDamage);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shotInstigator, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ammo, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(damage, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(hits, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(direct, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForApplyBleeding);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 3, 4);
    }

    {
        GET_FORMAT(MessageAskForStatsWrite);
        PUSH_FORMAT_ITEM(board, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(stats, NDTXOnlineStatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(boardTotal, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(statsTotal, NDTXOnlineStatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageLocalizedChat);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(args, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(chatMessageType, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageCreateTurret);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(path, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageVoteMission);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(diff, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageVotingMissionProgress);
        PUSH_FORMAT_ITEM(missions, NDTLocalizedStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(missionVotes, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(diff, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePlayerBan);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(content, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePlayerBanSelf);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageServerTimeout);
        PUSH_FORMAT_ITEM(timeout, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageAcceptedKey);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(content, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAdditionalSignedFiles);
        PUSH_FORMAT_ITEM(list, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageDataSignatureAsk);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageDataSignatureAnswer);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(fileName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(keyName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(keyContent, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(signature, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hash, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(version, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageHackedData);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(filename, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateAITeam);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(typeName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateAITeam);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(teamMembers, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(teamLeader, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(formation, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdatePositionTurret);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(gunStabilized, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(yRotWanted, NDTFloat, NCTFloatAngle, 0.00, 4);
        PUSH_FORMAT_ITEM(xRotWanted, NDTFloat, NCTFloatAngle, 0.00, 4);
        PUSH_FORMAT_ITEM(elevationWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageStaticObjectDestructed);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(now, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(immediate, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(damagedVariant, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskConnectVoice);
        PUSH_FORMAT_ITEM(publicAddr, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(privateAddr, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(voicePort, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(verNo, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageConnectVoiceDirect);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(addr, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(port, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(direct, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageConnectVoiceNatNeg);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(cookie, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(clientIndex, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageDisconnect);
        PUSH_FORMAT_ITEM(message, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageWaypointCreate);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(waypoint, NDTObject, NCTNone, NetworkMessageWaypoint, 4);
    }

    {
        GET_FORMAT(MessageWaypointUpdate);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(waypoint, NDTObject, NCTNone, NetworkMessageWaypoint, 4);
    }

    {
        GET_FORMAT(MessageWaypointDelete);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(idWP, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageHCSetGroup);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(team, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageHCRemoveGroup);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageHCClearGroups);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMissionStats);
        PUSH_FORMAT_ITEM(toCreate, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(toUpdate, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForFireWeapon);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(target, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(forceLock, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForGetInWantsPlayer);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flag, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForOrderGetIn);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flag, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForAllowGetIn);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flag, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForAirportSetSide);
        PUSH_FORMAT_ITEM(airportId, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForArbitration);
        PUSH_FORMAT_ITEM(sessionNonce, NDTInt64, NCTNone, 0, 8);
    }

    {
        GET_FORMAT(MessageUpdateDamageVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(isDestroyed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dammage, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageBattlEye);
        PUSH_FORMAT_ITEM(message, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForTeamSwitch);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawn, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageTeamSwitchResult);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(result, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageFinishTeamSwitch);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(killer, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fromGroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fromLeader, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageKBReact);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(topic, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(message, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(arguments, NDTObjectArray, NCTNone, NetworkMessagePublicVariable, 4);
    }

    {
        GET_FORMAT(MessageObjectSetVariable);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageObjectSetVariablesCollection);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(namesLength, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(names, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(valuesLength, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageWaypointsCopy);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAttachObject);
        PUSH_FORMAT_ITEM(obj, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(attachTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(memIndex, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageDetachObject);
        PUSH_FORMAT_ITEM(obj, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageGroupSetVariable);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCustomFile);
        PUSH_FORMAT_ITEM(filenames, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(typemask, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(crc, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(len, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageCustomFileList);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(fileList, NDTObjectArray, NCTNone, NetworkMessageCustomFile, 4);
    }

    {
        GET_FORMAT(MessageCustomFilesWanted);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(filesWanted, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageDeleteCustomFiles);
        PUSH_FORMAT_ITEM(list, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePlayerRoleUpdate);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(lifeState, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageNatNegResult);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(result, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateClientInfoDpid);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(cameraPosition, NDTVector, NCTVectorPositionCamera, vec3(-340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00), 12);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageServerTime);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(endTime, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateDoor);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionDoor);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageGroupSetUnconsciousLeader);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageGroupSelectLeader);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForAssignTeam);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(team, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageLoadedFromSave);
    }

    {
        GET_FORMAT(MessageServerDifficulty);
        PUSH_FORMAT_ITEM(forcedDifficulty, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(currentDifficulty, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageServerAdmin);
        PUSH_FORMAT_ITEM(admin, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(gameMaster, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageTakeBackpack);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAssemble);
        PUSH_FORMAT_ITEM(weapon, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(transform, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageDisAssemble);
        PUSH_FORMAT_ITEM(weapon, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskProcessDisAssemble);
        PUSH_FORMAT_ITEM(weapon, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageShowGroupDir);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(dir, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAskForSetMaxHitZoneDamage);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(dammage, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskForEnableVMode);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageAskForForceGunLight);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForIRLaser);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForVehicleDoorState);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(doorIndex, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(opened, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForChangeSide);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageVehMPEventHandlers);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(eventNum, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(handlers, NDTStringBArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageVehMPEvent);
        PUSH_FORMAT_ITEM(eventNum, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pars, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageMissionMPEvent);
        PUSH_FORMAT_ITEM(eventNum, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pars, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoteEntityEvent);
        PUSH_FORMAT_ITEM(eventNum, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pars, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageClearWeaponCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageClearItemCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageClearMagazineCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageClearBackpackCargo);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateClientCameraPosition);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateClientCameraPosition);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTVectorPositionCamera, vec3(-340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00, -340282346638528859811704183484516925440.00), 12);
    }

    {
        GET_FORMAT(MessageCreatePlayerRuntime);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(dpid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePlayerRuntime);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(cameraType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(opticsMode, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageAskRemoteControlled);
        PUSH_FORMAT_ITEM(whom, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForSetRank);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(rank, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForVehicleControl);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unlockedControls, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageOwnerChanged);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageLastOperPos);
        PUSH_FORMAT_ITEM(to, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(brain, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lastFieldPosX, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(lastFieldPosZ, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(x, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(z, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 3, 4);
        PUSH_FORMAT_ITEM(clearance, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(houseOrRoad, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(posIndex, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageFileSignatureAsk);
        PUSH_FORMAT_ITEM(file, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageFileSignatureAnswer);
        PUSH_FORMAT_ITEM(fileName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(keyName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(keyContent, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(signature, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(dataToHash, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(version, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(level, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTDefault, -1, 4);
    }

    {
        GET_FORMAT(MessageChangeCreatorId);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForAllowCrewInImmobile);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTDefault, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForPilotLight);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageCreateRadioChannel);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(color, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(label, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(callSign, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRadioChannelLabel);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(label, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRadioChannelCallSign);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(callSign, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRadioChannelUnits);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSendAUMsg);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageLockSupply);
        PUSH_FORMAT_ITEM(supply, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(user, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUnlockSupply);
        PUSH_FORMAT_ITEM(supply, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(user, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageReturnEquipment);
        PUSH_FORMAT_ITEM(to, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(from, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weaponInfos, NDTObjectArray, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageServerInfo);
        PUSH_FORMAT_ITEM(hostname, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(allowedLoadFileExtensions, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedPreprocessFileExtensions, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedHTMLloadExtensions, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedVoteCmds, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedVotedAdminCmds, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedVoteCmdsMask, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedVotedAdminCmdsMask, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(allowedHTMLloadURIs, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vonCodec, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessagePublicVariableTo);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(player, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageUavTerminalCreateConnection);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateInvisibleVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(remotePlayer, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(reportRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(receiveRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(reportOwnPosition, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageRadioChatBroadcast);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(sentence, NDTSentence, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wordsClass, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetObjectTexture);
        PUSH_FORMAT_ITEM(veh, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageForceFlagTexture);
        PUSH_FORMAT_ITEM(veh, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAddSideScore);
        PUSH_FORMAT_ITEM(side, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(score, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForSetVisibility);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(visible, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForEnableSimulation);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(simulate, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForRemoveFromCenter);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForForceWeatherUpdate);
        PUSH_FORMAT_ITEM(force, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForSetPlanningMode);
        PUSH_FORMAT_ITEM(brain, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(replan, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForDisconnectUav);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUavTerminalReleaseConnection);
        PUSH_FORMAT_ITEM(uav, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForSetRemoveMode);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageSetParticleClass);
        PUSH_FORMAT_ITEM(source, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(className, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForCreateAndAddBackpack);
        PUSH_FORMAT_ITEM(backpackName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForDeleteBackpack);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForDeleteGroup);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageStartWeaponDeploy);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(originalPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(originalOrientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(bipodPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(bipodOrientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(playerPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(horizontalLimit, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(mode, NDTInteger, NCTSmallUnsigned, -1, 4);
    }

    {
        GET_FORMAT(MessageStopWeaponDeploy);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdatePositionTankOrCar);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotBrake, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(timeAfterLastLandContact, NDTFloat, NCTFloatMostly0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskRemoteExecServer);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targets, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeDuplicates, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskRemoteExecServerNamed);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targets, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeDuplicates, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskRemoteExecClient);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targets, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeDuplicates, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(origin, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageRemoteExecServer);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(playerID, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(repeatCnt, NDTInteger, NCTSmallUnsigned, 1, 4);
    }

    {
        GET_FORMAT(MessageRemoteExecClient);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageRemoteExecUnJIP);
        PUSH_FORMAT_ITEM(JIPID, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageNamespaceSetVariable);
        PUSH_FORMAT_ITEM(namespace, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskRemoteExecClientOne);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targets, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeDuplicates, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(playerID, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageSetGroupIdentity);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(nameFormat, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(nameParts, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoteExecServerExt);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(playerID, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targetGroupsSides, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(origin, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageRemoteExecClientExt);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targetGroupOrSide, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(origin, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageRemoteExecClientMulti);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(repeatCnt, NDTInteger, NCTSmallUnsigned, 1, 4);
    }

    {
        GET_FORMAT(MessageSetObjectMaterial);
        PUSH_FORMAT_ITEM(veh, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTSmallUnsigned, -1, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageObjectSetVariableClient);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(object, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageObjectSetVariableExt);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageObjectSetVariableExtArray);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targets, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageGroupSetVariableClient);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(group, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageGroupSetVariableExt);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageGroupSetVariableExtArray);
        PUSH_FORMAT_ITEM(group, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targets, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageTeamMemberSetVariableExt);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageTeamMemberSetVariableExtArray);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targets, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageNamespaceSetVariableExt);
        PUSH_FORMAT_ITEM(namespace, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(target, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageNamespaceSetVariableExtArray);
        PUSH_FORMAT_ITEM(namespace, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(targets, NDTIntArray, NCTSmallUnsigned, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageSetVisibility);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(visible, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageSyncVarsInJIPQueue);
        PUSH_FORMAT_ITEM(id, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idPrev, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePublicKey);
        PUSH_FORMAT_ITEM(key, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePublicKeyAck);
        PUSH_FORMAT_ITEM(key, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePublicKeyBE);
        PUSH_FORMAT_ITEM(key, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessagePublicKeyAckBE);
        PUSH_FORMAT_ITEM(key, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateEntitySimple);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(shapeName, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(className, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageObjHideAnimSection);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(animation, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hide, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageUpdateProfessionStats);
        PUSH_FORMAT_ITEM(skills, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(customSkills, NDTStringArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(modifiers, NDTFloatArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskRemoteExecServerNamedObjGrp);
        PUSH_FORMAT_ITEM(command, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(params, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(originalCaller, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(targets, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeDuplicates, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(objgrp, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRemoteExecUnJIPObjGrp);
        PUSH_FORMAT_ITEM(creator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageTransferFileAck);
        PUSH_FORMAT_ITEM(path, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ackSegment, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForEnableActiveSensors);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTDefault, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForApplyObjectFlag);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(state, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(flag, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForceAIActiveSensors);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAskSetReportRemoteTargets);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskSetReceiveRemoteTargets);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskSetReportOwnPosition);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(value, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAddEPEForce);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(force, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageAddEPETorque);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(force, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageBankCount);
        PUSH_FORMAT_ITEM(channel, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(sender, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessagePlayerBE);
        PUSH_FORMAT_ITEM(dpnid, NDTInteger, NCTNone, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForGetOutToPos);
        PUSH_FORMAT_ITEM(soldier, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(pos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(dir, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(broadcast, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageDataHashCheckAsk);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(count, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(dataSizeDecompressed, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageDataHashCheckAnswer);
        PUSH_FORMAT_ITEM(index, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(bankPrefix, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(quickHash, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageTransferDataHashCheck);
        PUSH_FORMAT_ITEM(ID, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(data, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(totSize, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(offset, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(totSegments, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(curSegment, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskCheckCmdPwd);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(hash, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pwd, NDTRawData, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAcceptCheckCmdPwd);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(hash, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageDenyCheckCmdPwd);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(hash, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdateCuratorCommander);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(remotePlayer, NDTInteger, NCTNone, 1, 4);
        PUSH_FORMAT_ITEM(reportRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(receiveRemoteTargets, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(reportOwnPosition, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(assignedUnits, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(points, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(cameraCeiling, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(waypointCost, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(coeficients, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assignedCuratorCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(markersCounter, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(moveRadiuses, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(moveAreas, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(moveAreasIds, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(editRadiuses, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(editAreas, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(editAreasIds, NDTIntArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(areasType, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(logicGroup, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForJoinCuratorCommander);
        PUSH_FORMAT_ITEM(cCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForJoinCuratorLogic);
        PUSH_FORMAT_ITEM(cCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForChangeCuratorPoints);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(points, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskForAddCuratorEditableUnit);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crew, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(unassign, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForAddCuratorArea);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(worldPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(radius, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForRemoveCuratorArea);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(id, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForChangeCuratorCameraMoveCeiling);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(height, NDTFloat, NCTNone, 200.00, 4);
    }

    {
        GET_FORMAT(MessageAskForSetCuratorActionCoef);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(coef, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskForSetCuratorWaypointCost);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cost, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageAskForModifyCuratorAllowedAddons);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(addons, NDTStringArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(remove, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageAskForChangeCuratorEditAreaType);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForPingCurator);
        PUSH_FORMAT_ITEM(cLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(player, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageCreateJointConnection);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(jp, NDTObject, NCTNone, NetworkMessageJointParameters, 4);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(neighbour, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAttachEPE);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(child, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(jointParams, NDTObject, NCTNone, NetworkMessageJointParameters, 4);
    }

    {
        GET_FORMAT(MessageDetachEPE);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateSmokeEPE);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(smoke, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessagePolymorphPosition);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(selectionName, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageJointParameters);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(connectionPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(connectFrom, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(connectTo, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(axisConnectFrom, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(axisConnectTo, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(dirConnectFrom, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(dirConnectTo, NDTObject, NCTNone, NetworkMessagePolymorphPosition, 4);
        PUSH_FORMAT_ITEM(driveBySteering, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(jointDescription, NDTObject, NCTNone, NetworkMessageJointDescription, 4);
        PUSH_FORMAT_ITEM(dampingFrom, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(dampingTo, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(breakForce, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(collisionsEnabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(alignOrientation, NDTBool, NCTNone, 0, 1);
    }

    {
        GET_FORMAT(MessageChangeVisibilityAI);
        PUSH_FORMAT_ITEM(object, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ifVis, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(ifFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(ifView, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(ifGeo, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(updatePos, NDTFloat, NCTNone, 1.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateRagdollMan);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(ragdollMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(ragdollState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(itemOrientPrimary, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(itemPosPrimary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(itemSpeedPrimary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(itemAngVelocityPrimary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(itemOrientSecondary, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(itemPosSecondary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(itemSpeedSecondary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(itemAngVelocitySecondary, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageRagdollRequested);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageRagdollSyncAll);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(positionX, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(positionY, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(positionZ, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(quaternionX, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(quaternionY, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(quaternionZ, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(quaternionW, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageRagdollShotImpact);
        PUSH_FORMAT_ITEM(who, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(force, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(shotPos, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageJointDescription);
        PUSH_FORMAT_ITEM(dofs, NDTObject, NCTNone, NetworkMessageJointDOFs, 4);
        PUSH_FORMAT_ITEM(linearLimit, NDTObject, NCTNone, NetworkMessageJointLimits, 4);
        PUSH_FORMAT_ITEM(swing1Limit, NDTObject, NCTNone, NetworkMessageJointLimits, 4);
        PUSH_FORMAT_ITEM(swing2Limit, NDTObject, NCTNone, NetworkMessageJointLimits, 4);
        PUSH_FORMAT_ITEM(twistLowLimit, NDTObject, NCTNone, NetworkMessageJointLimits, 4);
        PUSH_FORMAT_ITEM(twistHighLimit, NDTObject, NCTNone, NetworkMessageJointLimits, 4);
        PUSH_FORMAT_ITEM(linearDriveX, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
        PUSH_FORMAT_ITEM(linearDriveY, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
        PUSH_FORMAT_ITEM(linearDriveZ, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
        PUSH_FORMAT_ITEM(angularSwingDrive, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
        PUSH_FORMAT_ITEM(angularTwistDrive, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
        PUSH_FORMAT_ITEM(angularSlerpDrive, NDTObject, NCTNone, NetworkMessageJointDrives, 4);
    }

    {
        GET_FORMAT(MessageJointDOFs);
        PUSH_FORMAT_ITEM(linearX, NDTInteger, NCTDefault, 2, 4);
        PUSH_FORMAT_ITEM(linearY, NDTInteger, NCTDefault, 2, 4);
        PUSH_FORMAT_ITEM(linearZ, NDTInteger, NCTDefault, 2, 4);
        PUSH_FORMAT_ITEM(swing1, NDTInteger, NCTDefault, 2, 4);
        PUSH_FORMAT_ITEM(swing2, NDTInteger, NCTDefault, 2, 4);
        PUSH_FORMAT_ITEM(twist, NDTInteger, NCTDefault, 2, 4);
    }

    {
        GET_FORMAT(MessageJointDrives);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(value, NDTFloat, NCTNone, 340282346638528859811704183484516925440.00, 4);
        PUSH_FORMAT_ITEM(spring, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(damping, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageJointLimits);
        PUSH_FORMAT_ITEM(value, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(restitution, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(spring, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(damping, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageCreateHelicopterRTD);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(rotorSpeed, NDTFloat, NCTFloat0To1, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateHelicopterRTD);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(fireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(curatorLogic, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(removeMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(knownForInfo, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(driver, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(driverLocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(effCommander, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(manCargo, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargoLocked, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(comFireTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(lock, NDTInteger, NCTDefault, 1, 4);
        PUSH_FORMAT_ITEM(driverHiddenWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(fuel, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(engineOff, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(manualFire, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnSide, NDTInteger, NCTDefault, 4, 4);
        PUSH_FORMAT_ITEM(respawning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnFlying, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(respawnUnit, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(respawnDelay, NDTFloat, NCTNone, -1.00, 4);
        PUSH_FORMAT_ITEM(respawnCount, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(enableVisionMode, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(allowCrewInImmobile, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(copilot, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(unLockedControls, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(enableCopilots, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(doors, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(wheelsBlocked, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(enableUavTerminalChangeWaypoints, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(damageEffectsFinished, NDTBoolArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(crashSoundType, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(vehiclesTransported, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(isDrowning, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(sensorsStates, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(rotorSpeedWanted, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(state, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(pilotHeight, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(stopMode, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(stopResult, NDTInteger, NCTSmallUnsigned, 2, 4);
        PUSH_FORMAT_ITEM(stopPosition, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(pilotSpeedHelper, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(pilotHeightHelper, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(pilotDirHelper, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(pilotGear, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hoveringAutopilot, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(slingLoadingState, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(slingLoadedCargo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slingLoadedCargoCenter, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(slingLoadingRopes, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(customWeight, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(rotorsFullyDestroyed, NDTInteger, NCTDefault, 0, 4);
    }

    {
        GET_FORMAT(MessageUpdatePositionHelicopterRTD);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(backRotorWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(mainRotorWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicForwardWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(cyclicAsideWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(rotorDiveWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(bankWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(diveWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotHeading, NDTFloat, NCTFloatAngle, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotDive, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(pilotSpeed, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
    }

    {
        GET_FORMAT(MessageCreateRopeObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(list, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(type, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(shape, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTNone, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(name, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(idVehicle, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfFirstStoredItem, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(idOfSupplyCreator, NDTInteger, NCTDefault, -1, 4);
        PUSH_FORMAT_ITEM(callInit, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(hierParent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(hit, NDTFloatArray, NCTFloat0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(parent, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(attachOffset, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(memoryPointIndex, NDTInteger, NCTNone, -1, 4);
        PUSH_FORMAT_ITEM(toObjs, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetX, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetY, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetZ, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(length, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(segments, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(ropeStartType, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ropeEndType, NDTString, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ropeStartDownVector, NDTVector, NCTNone, vec3(-0.00, -0.00, -0.00), 12);
        PUSH_FORMAT_ITEM(ropeEndDownVector, NDTVector, NCTNone, vec3(-0.00, -0.00, -0.00), 12);
    }

    {
        GET_FORMAT(MessageUpdateRopeObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(canSmoke, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(destroyed, NDTFloat, NCTFloat0To1, 0.00, 4);
        PUSH_FORMAT_ITEM(targetSide, NDTInteger, NCTSmallUnsigned, 1, 4);
        PUSH_FORMAT_ITEM(EPEMass, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(EPECom, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(ropeParentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(flags, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(pilotLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(collisionLight, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(supply, NDTObjectSRef, NCTNone, NetworkMessageUpdateSupply, 4);
        PUSH_FORMAT_ITEM(assembleTo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(winches, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(assembleBaseFrom, NDTString, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(vehicleTransportingDisabled, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(parentVehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ropeLength, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(toObjs, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetX, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetY, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(toAttachOffsetZ, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(ropeStartDownVector, NDTVector, NCTNone, vec3(-0.00, -0.00, -0.00), 12);
        PUSH_FORMAT_ITEM(ropeEndDownVector, NDTVector, NCTNone, vec3(-0.00, -0.00, -0.00), 12);
    }

    {
        GET_FORMAT(MessageUpdatePositionRopeObject);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(orientation, NDTMatrix, NCTMatrixOrientation, matrix3x3(vec3(1.00, 1.00, 1.00)), 36);
        PUSH_FORMAT_ITEM(speed, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(angVelocity, NDTVector, NCTVectorPosition, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(posFlags, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(time, NDTInteger, NCTSmallUnsigned, 0, 4);
    }

    {
        GET_FORMAT(MessageAskForEnableRopeAttach);
        PUSH_FORMAT_ITEM(entity, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageAskForSlingLoadingAction);
        PUSH_FORMAT_ITEM(heli, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForRopeCut);
        PUSH_FORMAT_ITEM(rope, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(length, NDTFloat, NCTNone, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdateAnimationsVehicle);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(animations, NDTFloatArray, NCTFloatMostly0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(animationsAnimSpeeds, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUpdateAnimationsMan);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(animations, NDTFloatArray, NCTFloatMostly0To1, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(animationsAnimSpeeds, NDTFloatArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(headXRotWantedCont, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headYRotWantedCont, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headXRotWantedPan, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(headYRotWantedPan, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(leanZRotWanted, NDTFloat, NCTFloatM1ToP1, 0.00, 4);
        PUSH_FORMAT_ITEM(deployedDirAzimuth, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
        PUSH_FORMAT_ITEM(deployedDirAltitude, NDTFloat, NCTFloatMPIToPPI, 0.00, 4);
    }

    {
        GET_FORMAT(MessageUpdatePersonGear);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdatePersonWeapons, 4);
    }

    {
        GET_FORMAT(MessageUpdatePersonWeapons);
        PUSH_FORMAT_ITEM(initialUpdate, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(currentWeapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(weapons, NDTObjectArray, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(loadedMagsHash, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(targetAimed, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(laserTargetOn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(laserTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(backpack, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(slotMgr, NDTObject, NCTNone, NetworkMessageUpdateSlotMgr, 4);
    }

    {
        GET_FORMAT(MessageAskUpdatePersonWeapons);
        PUSH_FORMAT_ITEM(person, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdatePersonWeapons, 4);
    }

    {
        GET_FORMAT(MessageUpdateTransportGear);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdateTransportWeapons, 4);
    }

    {
        GET_FORMAT(MessageUpdateTransportWeapons);
        PUSH_FORMAT_ITEM(initialUpdate, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(currentWeapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(weapons, NDTObjectArray, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(loadedMagsHash, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(targetAimed, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(laserTargetOn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(laserTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazineSlotsID, NDTIntArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskUpdateTransportWeapons);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdateTransportWeapons, 4);
    }

    {
        GET_FORMAT(MessageUpdateTurretGear);
        PUSH_FORMAT_ITEM(objectCreator, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectId, NDTInteger, NCTSmallUnsigned, 0, 4);
        PUSH_FORMAT_ITEM(objectPosition, NDTVector, NCTVectorPositionCamera, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(guaranteed, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdateTurretWeapons, 4);
    }

    {
        GET_FORMAT(MessageUpdateTurretWeapons);
        PUSH_FORMAT_ITEM(initialUpdate, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(currentWeapon, NDTInteger, NCTDefault, 0, 4);
        PUSH_FORMAT_ITEM(weapons, NDTObjectArray, NCTNone, NetworkMessageNetWeaponInfo, 4);
        PUSH_FORMAT_ITEM(magazines, NDTObjectArray, NCTNone, NetworkMessageMagazine, 4);
        PUSH_FORMAT_ITEM(loadedMagsHash, NDTInteger, NCTNone, 0, 4);
        PUSH_FORMAT_ITEM(targetAimed, NDTFloat, NCTNone, 0.00, 4);
        PUSH_FORMAT_ITEM(laserTargetOn, NDTBool, NCTNone, 0, 1);
        PUSH_FORMAT_ITEM(laserTarget, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(magazineSlotsID, NDTIntArray, NCTDefault, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskUpdateTurretWeapons);
        PUSH_FORMAT_ITEM(vehicle, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(turret, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(gunner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(weapons, NDTObject, NCTNone, NetworkMessageUpdateTurretWeapons, 4);
    }

    {
        GET_FORMAT(MessageLoadVehicleInVehicle);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageUnloadVehicleInVehicle);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(cargo, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
    }

    {
        GET_FORMAT(MessageAskForEnableVehicleTransporting);
        PUSH_FORMAT_ITEM(transport, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(enable, NDTBool, NCTNone, 1, 1);
    }

    {
        GET_FORMAT(MessageTacticalPing);
        PUSH_FORMAT_ITEM(owner, NDTRef, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(position, NDTVector, NCTNone, vec3(0.00, 0.00, 0.00), 12);
        PUSH_FORMAT_ITEM(enabled, NDTBool, NCTNone, 1, 1);
        PUSH_FORMAT_ITEM(units, NDTRefArray, NCTNone, 0, 0 /* TODO: Add parsing for this def val */);
        PUSH_FORMAT_ITEM(type, NDTInteger, NCTNone, 0, 4);
    }

}
