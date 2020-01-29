#pragma once
#include "networkmessage.h"

typedef void(*CleanupMsgFn)(unsigned char*);
typedef unsigned char*(*CreateMsgFn)();

struct MessageMsgFormatItem {
    std::string _name;
    void* _specs;

    MessageMsgFormatItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgFormat {
    int _index;
    std::vector<MessageMsgFormatItem*> _items;

    MessageMsgFormat() {};
    ~MessageMsgFormat();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayer {
    int _player;
    std::string _name;
    bool _server;
    bool _vonDisabled;
    int _vonCodecQuality;
    bool _battlEye;
    int64_t _steamServerId;
    bool _steamSecure;
    int _sigVerRequired;
    std::string _regURL;
    bool _isJip;

    MessagePlayer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMessages {

    MessageMessages() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerState {
    int _serverState;

    MessageServerState() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageClientState {
    int _clientState;

    MessageClientState() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerClientState {
    int _dpnid;
    int _clientState;

    MessagePlayerClientState() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLogin {
    int _dpnid;
    int _playerid;
    int _inaddr;
    int64_t _uid;
    int64_t _steamID;
    int64_t _ownerSteamID;
    std::vector<char> _steamSessionTicket;
    std::string _name;
    std::string _face;
    std::string _glasses;
    std::string _speaker;
    float _pitch;
    std::string _squad;
    int _unitId;
    std::string _fullname;
    std::string _email;
    std::string _icq;
    std::string _remark;
    int _filesCount;
    int _clientState;
    int _version;
    int _build;
    bool _headlessClient;
    bool _isJip;
    std::string _userId;
    bool _userGuest;
    std::string _cloudId;
    int _level;
    bool _isVIP;

    MessageLogin() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLogout {
    int _dpnid;

    MessageLogout() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSquad {
    std::string _id;
    std::string _nick;
    std::string _name;
    std::string _email;
    std::string _web;
    std::string _picture;
    std::string _title;
    int _unitId;

    MessageSquad() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicVariable {
    std::string _name;
    std::vector<char> _value;

    MessagePublicVariable() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTeamMemberSetVariable {
    int _id;
    int _creator;
    std::string _name;
    std::vector<char> _value;

    MessageTeamMemberSetVariable() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLogMsgOnServer {
    std::string _text;
    bool _logInConsole;

    MessageLogMsgOnServer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageChat {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::string _name;
    std::string _text;

    MessageChat() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChat {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::string _text;
    std::vector<Sentence> _sentence;
    std::string _wordsClass;

    MessageRadioChat() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChatWave {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::string _senderName;
    std::string _wave;

    MessageRadioChatWave() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetSpeaker {
    int _player;
    bool _on;
    int _creator;
    int _id;

    MessageSetSpeaker() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMissionHeader {
    std::string _gameType;
    std::string _island;
    LocalizedString _name;
    LocalizedString _description;
    int64_t _steamId;
    std::string _fileName;
    std::string _fileDir;
    int _fileSizeL;
    int _fileSizeH;
    int _fileCRC;
    int _respawn;
    float _respawnDelay;
    float _respawnVehicleDelay;
    float _bodyMinTime;
    float _bodyMaxTime;
    float _bodyLimit;
    int _bodyManagerMode;
    float _wreckMinTime;
    float _wreckMaxTime;
    float _wreckLimit;
    int _wreckManagerMode;
    float _minPlayerDistance;
    bool _teamSwitchEnabled;
    std::string _diffName;
    bool _disabledAI;
    bool _enableAIDisable;
    bool _aiKills;
    bool _updateOnly;
    bool _hasMissionParams;
    bool _noCopy;
    int _diffGroupIndicators;
    int _diffFriendlyTags;
    int _diffEnemyTags;
    int _diffDetectedMines;
    int _diffCommands;
    int _diffWaypoints;
    int _diffWeaponInfo;
    int _diffStanceIndicator;
    bool _diffReducedDamage;
    bool _diffStaminaBar;
    bool _diffWeaponCrosshair;
    bool _diffVisionAid;
    bool _diffSquadRadar;
    bool _diffThirdPersonView;
    bool _diffCameraShake;
    bool _diffScoreTable;
    bool _diffDeathMessages;
    bool _diffVonID;
    int _diffMapContent;
    bool _diffMiniMapAllowed;
    bool _diffAutomaticReporting;
    bool _diffMultipleSaves;
    int _diffTacticalPing;
    std::vector<std::string> _addOns;
    Time _estimatedEndTime;
    LocalizedString _titleParam1;
    std::vector<float> _valuesParam1;
    std::vector<LocalizedString> _textsParam1;
    float _defValueParam1;
    LocalizedString _titleParam2;
    std::vector<float> _valuesParam2;
    std::vector<LocalizedString> _textsParam2;
    float _defValueParam2;
    std::vector<float> _sizesParamArray;
    std::vector<LocalizedString> _textsParamArray;
    std::vector<float> _valuesParamArray;
    std::vector<LocalizedString> _titleParamArray;
    std::vector<float> _defaultParamArray;
    int _rtdServerForced;
    std::string _missionStatsID;
    std::vector<int> _dlcs;
    bool _skipLobby;
    std::string _fileNameReal;
    std::string _serverStatsId;
    bool _unsafeCVL;

    MessageMissionHeader() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerRole {
    int _index;
    int _side;
    int _group;
    int _unit;
    int _unitIndexInGroup;
    std::string _vehicle;
    std::vector<int> _turret;
    bool _leader;
    int _player;
    int _flags;
    std::string _description;
    std::string _unitName;
    int _lifeState;

    MessagePlayerRole() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSelectPlayer {
    int _player;
    int _creator;
    int _id;
    vec3 _position;
    bool _respawn;

    MessageSelectPlayer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAttachPerson {
    NetworkId _person;
    NetworkId _unit;

    MessageAttachPerson() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTransferFile {
    int _datamask;
    std::vector<std::string> _filenames;
    std::vector<char> _data;
    int _totSize;
    int _offset;
    int _totSegments;
    int _curSegment;

    MessageTransferFile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskMissionFile {
    bool _valid;

    MessageAskMissionFile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTransferMissionFile {
    std::string _path;
    std::vector<char> _data;
    int _totSize;
    int _offset;
    int _totSegments;
    int _curSegment;

    MessageTransferMissionFile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTransferFileToServer {
    int _datamask;
    std::vector<std::string> _filenames;
    std::vector<char> _data;
    int _totSize;
    int _offset;
    int _totSegments;
    int _curSegment;

    MessageTransferFileToServer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDamage {
    NetworkId _who;
    NetworkId _owner;
    vec3 _modelPos;
    float _val;
    float _valRange;
    std::string _ammo;
    std::string _weapon;
    vec3 _originDir;

    MessageAskForDamage() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetDamage {
    NetworkId _who;
    float _dammage;
    bool _handleScore;
    bool _ignoreHitPoints;
    bool _immidiateEffect;

    MessageAskForSetDamage() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetSkill {
    NetworkId _vehicle;
    float _skill;
    int _type;

    MessageAskForSetSkill() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForGetIn {
    NetworkId _soldier;
    NetworkId _vehicle;
    int _position;
    NetworkId _turret;
    int _cargoIndex;
    bool _isFastMoveIn;

    MessageAskForGetIn() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAssignAs {
    NetworkId _soldier;
    NetworkId _vehicle;
    int _position;
    NetworkId _turret;
    int _cargoIndex;
    bool _unassign;

    MessageAskForAssignAs() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForMoveOutTo {
    NetworkId _soldier;
    NetworkId _vehicle;
    vec3 _pos;

    MessageAskForMoveOutTo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForRemoveVehicleFromGroup {
    NetworkId _group;
    NetworkId _vehicle;

    MessageAskForRemoveVehicleFromGroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForGetOut {
    NetworkId _soldier;
    NetworkId _vehicle;
    NetworkId _turret;
    bool _parachute;
    bool _eject;

    MessageAskForGetOut() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskWaitForGetOut {
    NetworkId _vehicle;
    NetworkId _unit;

    MessageAskWaitForGetOut() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForChangePosition {
    NetworkId _soldier;
    NetworkId _vehicle;
    int _type;
    NetworkId _turret;
    int _cargoIndex;

    MessageAskForChangePosition() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSelectWeapon {
    NetworkId _vehicle;
    NetworkId _turret;
    int _weapon;

    MessageAskForSelectWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAmmo {
    NetworkId _vehicle;
    NetworkId _turret;
    int _weapon;
    int _burst;

    MessageAskForAmmo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAddImpulse {
    NetworkId _vehicle;
    vec3 _force;
    vec3 _torque;

    MessageAskForAddImpulse() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForMoveVector {
    NetworkId _vehicle;
    vec3 _pos;

    MessageAskForMoveVector() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForMoveMatrix {
    NetworkId _vehicle;
    vec3 _pos;
    matrix3x3 _orient;

    MessageAskForMoveMatrix() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForJoinGroup {
    NetworkId _join;
    NetworkId _group;
    bool _silent;

    MessageAskForJoinGroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForJoinUnits {
    NetworkId _join;
    std::vector<NetworkId> _units;
    bool _silent;
    int _id;

    MessageAskForJoinUnits() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageExplosionDamageEffects {
    NetworkId _owner;
    NetworkId _directHit;
    int _componentIndex;
    float _hit;
    float _indirectHit;
    float _indirectHitRange;
    float _explosive;
    float _explosionEffectsRadius;
    std::string _type;
    std::string _weapon;
    vec3 _pos;
    vec3 _surfNormal;
    vec3 _inSpeed;
    vec3 _outSpeed;
    float _dustness;
    vec3 _explosionDir;
    bool _enemyDamage;
    float _energyFactor;
    float _explosionFactor;
    float _damage;

    MessageExplosionDamageEffects() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageFireWeapon {
    NetworkId _vehicle;
    NetworkId _gunner;
    NetworkId _target;
    vec3 _pos;
    vec3 _dir;
    int _weapon;
    int _magazineCreator;
    int _magazineId;
    int _burstLeft;
    int _ammoLeft;
    std::string _magazineName;
    float _visible;

    MessageFireWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMagazine {
    std::string _type;
    int _ammo;
    float _reload;
    float _reloadDuration;
    float _reloadMagazine;
    float _reloadMagazineTotal;
    int _creator;
    int _id;
    int _pylon;

    MessageMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNetWeaponInfo {
    std::string _weapon;
    int _weaponId;
    int _weaponCreator;
    std::string _optics;
    int _opticsId;
    int _opticsCreator;
    std::string _muzzle;
    int _muzzleId;
    int _muzzleCreator;
    std::string _flashlight;
    int _flashlightId;
    int _flashlightCreator;
    std::string _underBarrel;
    int _underBarrelId;
    int _underBarrelCreator;
    int64_t _notemptyprimaryMag; // indicates if the Object was actually sent or not
    MessageMagazine _primaryMag;
    int64_t _notemptysecondaryMag; // indicates if the Object was actually sent or not
    MessageMagazine _secondaryMag;

    MessageNetWeaponInfo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateEntityAIWeapons {
    bool _initialUpdate;
    int _currentWeapon;
    std::vector<MessageNetWeaponInfo*> _weapons;
    std::vector<MessageMagazine*> _magazines;
    int _loadedMagsHash;
    float _targetAimed;
    bool _laserTargetOn;
    NetworkId _laserTarget;

    MessageUpdateEntityAIWeapons() {};
    ~MessageUpdateEntityAIWeapons();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateWeapons {
    NetworkId _vehicle;
    NetworkId _turret;
    NetworkId _gunner;
    MessageUpdateEntityAIWeapons _weapons;

    MessageUpdateWeapons() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddWeapon {
    NetworkId _vehicle;
    int64_t _notemptyweaponInfo; // indicates if the Object was actually sent or not
    MessageNetWeaponInfo _weaponInfo;

    MessageAddWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveWeapon {
    NetworkId _vehicle;
    std::string _weapon;

    MessageRemoveWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddWeaponCargo {
    NetworkId _vehicle;
    int64_t _notemptyweaponInfo; // indicates if the Object was actually sent or not
    MessageNetWeaponInfo _weaponInfo;

    MessageAddWeaponCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveWeaponCargo {
    NetworkId _vehicle;
    int64_t _notemptyweaponInfo; // indicates if the Object was actually sent or not
    MessageNetWeaponInfo _weaponInfo;

    MessageRemoveWeaponCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddItemCargo {
    NetworkId _vehicle;
    std::string _item;
    int _creator;
    int _itemId;
    int _itemType;
    int _ammo;
    std::string _opticsName;
    int _opticsCreator;
    int _opticsId;
    std::string _muzzleName;
    int _muzzleCreator;
    int _muzzleId;
    std::string _flashlightName;
    int _flashlightCreator;
    int _flashlightId;
    std::string _underBarrelName;
    int _underBarrelCreator;
    int _underBarrelId;
    int64_t _notemptyprimaryMag; // indicates if the Object was actually sent or not
    MessageMagazine _primaryMag;
    int64_t _notemptysecondaryMag; // indicates if the Object was actually sent or not
    MessageMagazine _secondaryMag;
    NetworkId _supplyEnt;

    MessageAddItemCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveItemCargo {
    NetworkId _vehicle;
    int _creator;
    int _itemId;

    MessageRemoveItemCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageModifyMagazineAmmoInCargo {
    NetworkId _containerEnt;
    std::string _item;
    int _posInArray;
    int _newAmmo;

    MessageModifyMagazineAmmoInCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetUnitLoadOutFromClassName {
    NetworkId _vehicle;
    std::string _className;
    int _creator;
    int _firstItemId;
    NetworkId _uniformEnt;
    NetworkId _vestEnt;
    NetworkId _backpackEnt;

    MessageSetUnitLoadOutFromClassName() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMagazineString {
    std::string _name;
    int _ammoLeft;

    MessageMagazineString() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCountedString {
    std::string _name;
    int _count;

    MessageCountedString() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCountedWeaponsString {
    std::string _name;
    int _count;
    std::string _optics;
    std::string _muzzle;
    std::string _flashlight;
    std::string _underBarrel;
    MessageMagazineString _primaryMuzzleMag;
    MessageMagazineString _secondaryMuzzleMag;

    MessageCountedWeaponsString() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageContainerRawData {
    bool _isGeneric;
    std::string _className;
    bool _isBackpack;
    std::vector<MessageMagazineString*> _magazinesDef;
    std::vector<int> _magazinesCnt;
    std::vector<MessageCountedString*> _items;
    std::vector<MessageCountedWeaponsString*> _weapons;
    std::vector<MessageContainerRawData*> _containers;

    MessageContainerRawData() {};
    ~MessageContainerRawData();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetUnitLoadOutFromRawData {
    NetworkId _vehicle;
    int _creator;
    int _firstItemId;
    NetworkId _uniformEnt;
    int64_t _notemptyuniform; // indicates if the Object was actually sent or not
    MessageContainerRawData _uniform;
    NetworkId _vestEnt;
    int64_t _notemptyvest; // indicates if the Object was actually sent or not
    MessageContainerRawData _vest;
    NetworkId _backpackEnt;
    int64_t _notemptybackpack; // indicates if the Object was actually sent or not
    MessageContainerRawData _backpack;
    std::vector<NetworkId> _containersInContainers;

    MessageSetUnitLoadOutFromRawData() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAssignItemToSlot {
    NetworkId _vehicle;
    std::string _item;
    int _itemType;
    NetworkId _supplyEnt;

    MessageAssignItemToSlot() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUnAssignItemFromSlot {
    NetworkId _vehicle;
    int _itemType;

    MessageUnAssignItemFromSlot() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageOfferItemFromBody {
    NetworkId _fromBody;
    NetworkId _targetUnit;
    int _creator;
    int _itemId;
    NetworkId _supplyEnt;
    int _mode;

    MessageOfferItemFromBody() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLinkNewContainer {
    NetworkId _parent;
    NetworkId _from;
    std::string _item;
    int _itemType;
    NetworkId _supplyEnt;
    int _targetType;

    MessageLinkNewContainer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReplaceContainer {
    NetworkId _targetSoldier;
    NetworkId _fromSupply;
    std::string _item;
    int _itemType;
    NetworkId _supplyEnt;
    int _targetType;

    MessageReplaceContainer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddMagazineCargo {
    NetworkId _vehicle;
    int _creator;
    int64_t _notemptymagazine; // indicates if the Object was actually sent or not
    MessageMagazine _magazine;
    int _firstMagId;
    int _count;

    MessageAddMagazineCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddBackpackCargo {
    NetworkId _vehicle;
    NetworkId _backpack;

    MessageAddBackpackCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveBackpackCargo {
    NetworkId _vehicle;
    NetworkId _backpack;

    MessageRemoveBackpackCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveMagazineCargo {
    NetworkId _vehicle;
    std::string _type;
    int _ammo;

    MessageRemoveMagazineCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddMagazine {
    NetworkId _vehicle;
    int64_t _notemptymagazine; // indicates if the Object was actually sent or not
    MessageMagazine _magazine;

    MessageAddMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoveMagazine {
    NetworkId _vehicle;
    std::string _type;
    int _ammo;

    MessageRemoveMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVehicleInit {
    NetworkId _subject;
    std::string _init;

    MessageVehicleInit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVehicleDestroyed {
    NetworkId _killed;
    NetworkId _killer;
    NetworkId _shotInstigator;
    bool _handleScore;
    std::string _ammo;
    std::string _weapon;

    MessageVehicleDestroyed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageStoreCreatedSite {
    NetworkId _site;

    MessageStoreCreatedSite() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDeleteCreatedSite {
    NetworkId _site;

    MessageDeleteCreatedSite() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRunInitSitesScript {
    NetworkId _site;

    MessageRunInitSitesScript() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMarker {
    vec3 _position;
    std::string _name;
    std::string _text;
    std::vector<float> _linePointCoodinates;
    int _markerType;
    std::string _type;
    std::string _colorName;
    float _alpha;
    std::string _fillName;
    float _a;
    float _b;
    float _angle;
    bool _drawBorder;
    NetworkId _owner;

    MessageMarker() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMarkerCreate {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    MessageMarker _marker;

    MessageMarkerCreate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMarkerDelete {
    std::string _name;

    MessageMarkerDelete() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMarkerUpdate {
    std::string _name;
    vec3 _newPos;
    float _angle;

    MessageMarkerUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetFlagOwner {
    NetworkId _owner;
    NetworkId _carrier;

    MessageSetFlagOwner() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetFlagCarrier {
    NetworkId _owner;
    NetworkId _carrier;

    MessageSetFlagCarrier() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVTarget {
    NetworkId _vehicle;
    NetworkId _receiver;
    NetworkId _target;

    MessageMsgVTarget() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVFire {
    NetworkId _vehicle;
    NetworkId _receiver;
    NetworkId _target;

    MessageMsgVFire() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVMove {
    NetworkId _vehicle;
    vec3 _destination;

    MessageMsgVMove() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVFormation {
    NetworkId _vehicle;

    MessageMsgVFormation() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVSimpleCommand {
    NetworkId _vehicle;
    NetworkId _receiver;
    int _cmd;
    bool _fakeCmd;

    MessageMsgVSimpleCommand() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVLoad {
    NetworkId _vehicle;
    NetworkId _receiver;
    int _weapon;

    MessageMsgVLoad() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVAzimut {
    NetworkId _vehicle;
    float _azimut;

    MessageMsgVAzimut() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVStopTurning {
    NetworkId _vehicle;
    float _azimut;

    MessageMsgVStopTurning() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVFireFailed {
    NetworkId _vehicle;
    NetworkId _sender;

    MessageMsgVFireFailed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageChangeOwner {
    int _creator;
    int _id;
    int _owner;
    bool _disconnected;
    int _prevOwner;

    MessageChangeOwner() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlaySound {
    std::string _name;
    vec3 _position;
    vec3 _speed;
    float _volume;
    float _frequency;
    int _creator;
    int _soundId;
    float _distance;

    MessagePlaySound() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDeleteObject {
    int _creator;
    int _id;

    MessageDeleteObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDeleteCommand {
    int _creator;
    int _id;
    NetworkId _subgrp;

    MessageDeleteCommand() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;

    MessageCreateObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;

    MessageUpdateObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;

    MessageCreateVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;

    MessageUpdateVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;

    MessageUpdatePositionVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageEffects {
    std::string _condition;
    std::string _sound;
    std::string _voice;
    std::string _soundEnv;
    std::string _soundDet;
    std::string _track;
    int _titleType;
    int _titleEffect;
    std::string _title;

    MessageEffects() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateDetector {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    float _a;
    float _b;
    float _c;
    bool _swapped;
    int _behaviourFlags;
    float _angle;
    float _sinAngle;
    float _cosAngle;
    bool _rectangular;
    int _activationBy;
    int _activationType;
    bool _repeating;
    float _timeoutMin;
    float _timeoutMid;
    float _timeoutMax;
    bool _interruptable;
    int _action;
    int _assignedStatic;
    int _assignedVehicle;
    std::string _text;
    std::string _expCond;
    std::string _expActiv;
    std::string _expDesactiv;
    std::vector<int> _synchronizations;
    int __syncId;
    MessageEffects _effects;

    MessageCreateDetector() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateDetector {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    NetworkId _assignedGroup;

    MessageUpdateDetector() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateSupply {
    float _fuelCargo;
    float _repairCargo;
    float _ammoCargo;
    int _itemContainersCnt;
    int _backpacksCnt;
    NetworkId _alloc;
    NetworkId _parent;
    NetworkId _parentOwner;
    NetworkId _deadBody;
    bool _droppedFromBody;

    MessageUpdateSupply() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateFlag {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _flagOwner;
    NetworkId _flagOwnerWanted;
    std::string _flagTexture;
    int _flagSide;

    MessageUpdateFlag() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateShot {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    std::string _type;
    NetworkId _parent;
    float _timeToLive;
    vec3 _createPos;
    vec3 _createSpeed;
    matrix3x3 _createOrient;
    std::string _weapon;
    std::string _muzzle;

    MessageCreateShot() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateShot {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;

    MessageUpdateShot() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateCrater {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    float _timeToLive;
    float _size;
    std::string _effectsType;
    float _effectsTimeToLive;
    float _alpha;
    float _distToWater;

    MessageCreateCrater() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateCraterOnVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    float _timeToLive;
    float _size;
    std::string _effectsType;
    float _effectsTimeToLive;
    float _alpha;
    float _distToWater;
    NetworkId _vehicle;
    vec3 _pos;
    vec3 _dir;

    MessageCreateCraterOnVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateObjectDestructed {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    NetworkId _destroy;
    float _timeToLive;

    MessageCreateObjectDestructed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAICenter {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _side;
    float _skillCoef;
    float _precisionCoef;

    MessageCreateAICenter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAICenter {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    float _friends0;
    float _friends1;
    float _friends2;
    float _friends3;

    MessageUpdateAICenter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWaypoint {
    vec3 _position;
    float _placement;
    float _completitionRadius;
    int _id;
    int _idObject;
    int _housePos;
    int _type;
    int _combatMode;
    int _formation;
    int _speed;
    int _combat;
    bool _forceBehaviour;
    float _timeoutMin;
    float _timeoutMid;
    float _timeoutMax;
    std::string _description;
    std::string _expCond;
    std::string _expActiv;
    std::string _script;
    int _showWP;
    std::vector<int> _synchronizations;
    MessageEffects _effects;
    bool _visible;
    int _idWP;
    int _syncId;
    std::string _name;
    float _loiterRadius;
    int _loiterType;

    MessageWaypoint() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAIGroup {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _center;
    std::string _varName;
    int _id;
    std::vector<MessageWaypoint*> _waypoints;
    int _roleIndex;
    bool _clearIfEmpty;

    MessageCreateAIGroup() {};
    ~MessageCreateAIGroup();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUnitSlot {
    int _healthState;

    MessageUnitSlot() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIGroup {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _mainSubgroup;
    NetworkId _leader;
    int _semaphore;
    int _combatModeMinor;
    int _enemiesDetected;
    int _unknownsDetected;
    float _forceCourage;
    float _courage;
    bool _flee;
    int _waypointIndex;
    int _nextWaypointId;
    bool _attackEnabled;
    std::vector<MessageUnitSlot*> _unitSlots;
    bool _clearIfEmpty;

    MessageUpdateAIGroup() {};
    ~MessageUpdateAIGroup();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAISubgroup {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _group;

    MessageCreateAISubgroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAISubgroup {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _group;
    std::vector<NetworkId> _units;
    NetworkId _leader;
    int _mode;
    vec3 _wantedPosition;
    int _formation;
    int _speedMode;
    int _lastPrec;
    float _formationCoef;
    vec3 _direction;

    MessageUpdateAISubgroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAIBrain {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    std::string _name;
    std::string _firstName;
    std::string _lastName;
    std::string _face;
    std::string _glasses;
    std::string _speaker;
    float _pitch;
    int _rank;
    float _experience;
    float _initExperience;
    int _roleIndex;
    std::string _squadPicture;
    std::string _squadTitle;
    std::vector<int> _objectIdHistory;
    std::string _soundName;
    std::vector<float> _skillsArray;

    MessageCreateAIBrain() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateProfessionStats {
    int _skills;
    std::vector<std::string> _customSkills;
    std::vector<float> _modifiers;

    MessageUpdateProfessionStats() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIBrain {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    float _experience;
    float _ability;
    int _semaphore;
    int _combatModeMajor;
    Time _dangerUntil;
    int _captive;
    int _state;
    int _lifeState;
    int _disclosedStatus;
    bool _getInAllowed;
    bool _getInOrdered;
    std::vector<int> _objectIdHistory;
    NetworkId _remoteControlled;
    std::vector<NetworkId> _synchronizedObjects;
    MessageUpdateProfessionStats _professionStats;

    MessageUpdateAIBrain() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIBrainPath {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _house;
    int _housePos;
    vec3 _wantedPosition;
    int _planningMode;
    int _mode;

    MessageUpdateAIBrainPath() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAIUnit {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    std::string _name;
    std::string _firstName;
    std::string _lastName;
    std::string _face;
    std::string _glasses;
    std::string _speaker;
    float _pitch;
    int _rank;
    float _experience;
    float _initExperience;
    int _roleIndex;
    std::string _squadPicture;
    std::string _squadTitle;
    std::vector<int> _objectIdHistory;
    std::string _soundName;
    std::vector<float> _skillsArray;
    NetworkId _subgroup;
    int _id;

    MessageCreateAIUnit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIUnit {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    float _experience;
    float _ability;
    int _semaphore;
    int _combatModeMajor;
    Time _dangerUntil;
    int _captive;
    int _state;
    int _lifeState;
    int _disclosedStatus;
    bool _getInAllowed;
    bool _getInOrdered;
    std::vector<int> _objectIdHistory;
    NetworkId _remoteControlled;
    std::vector<NetworkId> _synchronizedObjects;
    MessageUpdateProfessionStats _professionStats;
    float _formationAngle;
    vec3 _formationPos;
    int _assignedTeam;

    MessageUpdateAIUnit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIUnitPath {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _house;
    int _housePos;
    vec3 _wantedPosition;
    int _planningMode;
    int _mode;

    MessageUpdateAIUnitPath() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAIAgent {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    std::string _name;
    std::string _firstName;
    std::string _lastName;
    std::string _face;
    std::string _glasses;
    std::string _speaker;
    float _pitch;
    int _rank;
    float _experience;
    float _initExperience;
    int _roleIndex;
    std::string _squadPicture;
    std::string _squadTitle;
    std::vector<int> _objectIdHistory;
    std::string _soundName;
    std::vector<float> _skillsArray;

    MessageCreateAIAgent() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIAgent {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _person;
    float _experience;
    float _ability;
    int _semaphore;
    int _combatModeMajor;
    Time _dangerUntil;
    int _captive;
    int _state;
    int _lifeState;
    int _disclosedStatus;
    bool _getInAllowed;
    bool _getInOrdered;
    std::vector<int> _objectIdHistory;
    NetworkId _remoteControlled;
    std::vector<NetworkId> _synchronizedObjects;
    MessageUpdateProfessionStats _professionStats;

    MessageUpdateAIAgent() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAIAgentPath {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _house;
    int _housePos;
    vec3 _wantedPosition;
    int _planningMode;
    int _mode;

    MessageUpdateAIAgentPath() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateCommand {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _subgroup;
    bool _enqueued;
    int _message;
    NetworkId _target;
    NetworkId _targetE;
    vec3 _destination;
    Time _time;
    NetworkId _join;
    int _intParam;
    std::string _strParam;
    int _discretion;
    int _context;
    float _precision;
    int _id;
    int _intParam2;

    MessageCreateCommand() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateCommand {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _destination;

    MessageUpdateCommand() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateVehicleAI {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;

    MessageUpdateVehicleAI() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateVehicleAIFull {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;

    MessageUpdateVehicleAIFull() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateVehicleBrain {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    int _remotePlayer;
    bool _reportRemoteTargets;
    bool _receiveRemoteTargets;
    bool _reportOwnPosition;

    MessageUpdateVehicleBrain() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTransport {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;

    MessageUpdateTransport() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAnimal {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    int _remotePlayer;
    bool _reportRemoteTargets;
    bool _receiveRemoteTargets;
    bool _reportOwnPosition;
    float _walkSpeedWanted;
    float _sideSpeedWanted;
    int _unitPosCommanded;
    int _unitPosScripted;
    NetworkId _flagCarrier;

    MessageUpdateAnimal() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionAnimal {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _headXRotWanted;
    float _headYRotWanted;
    float _lookXRotWanted;
    float _lookYRotWanted;
    float _headXRotWantedCont;
    float _headYRotWantedCont;
    std::string _move;

    MessageUpdatePositionAnimal() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateMan {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    int _remotePlayer;
    bool _reportRemoteTargets;
    bool _receiveRemoteTargets;
    bool _reportOwnPosition;
    float _hideBodyWanted;
    float _fatigueValue;
    float _walkSpeedWanted;
    float _sideSpeedWanted;
    int _unitPosCommanded;
    int _unitPosScripted;
    NetworkId _flagCarrier;
    bool _nvg;
    NetworkId _ladderBuilding;
    int _ladderIndex;
    float _ladderPosition;
    bool _irWanted;
    bool _lightWanted;
    NetworkId _groundContainer;
    int _healingActivated;
    bool _healingFlag;

    MessageUpdateMan() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionMan {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _gunXRotWanted;
    float _gunYRotWanted;
    float _headXRotWanted;
    float _headYRotWanted;
    float _lookXRotWanted;
    float _lookYRotWanted;
    std::string _move;
    std::string _gesture;
    bool _isPersonTurret;
    bool _isMobileSwitching;
    bool _isReloadingMagazine;

    MessageUpdatePositionMan() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTankOrCar {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;

    MessageUpdateTankOrCar() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTank {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;

    MessageUpdateTank() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionTank {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    bool _pilotBrake;
    float _timeAfterLastLandContact;
    float _rpmWanted;
    float _thrustLWanted;
    float _thrustRWanted;

    MessageUpdatePositionTank() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTurret {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _owner;
    NetworkId _gunner;
    bool _locked;
    float _crewHiddenWanted;
    bool _searchLightOn;
    int _personTurretDisabledFlag;
    NetworkId _fireTarget;

    MessageUpdateTurret() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateCar {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    std::string _plateNumber;
    float _scudState;

    MessageUpdateCar() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionCar {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    bool _pilotBrake;
    float _timeAfterLastLandContact;
    float _rpmWanted;
    float _thrustWanted;
    float _turnWanted;

    MessageUpdatePositionCar() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAirplane {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    int _pilotFlaps;
    bool _gearDamage;
    bool _pilotGear;
    bool _vtolMode;
    int _planeState;
    int _stopMode;
    int _stopResult;
    vec3 _stopPosition;
    bool _openCabinWanted;

    MessageUpdateAirplane() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionAirplane {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _thrustWanted;
    float _thrustVectorWanted;
    float _elevatorWanted;
    float _rudderWanted;
    float _aileronWanted;
    float _pilotBrake;
    float _pilotSpeed;

    MessageUpdatePositionAirplane() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateHelicopter {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    float _rotorSpeedWanted;
    int _state;
    float _pilotHeight;
    int _stopMode;
    int _stopResult;
    vec3 _stopPosition;
    bool _pilotSpeedHelper;
    bool _pilotHeightHelper;
    bool _pilotDirHelper;
    bool _pilotGear;
    bool _hoveringAutopilot;
    int _slingLoadingState;
    NetworkId _slingLoadedCargo;
    vec3 _slingLoadedCargoCenter;
    std::vector<NetworkId> _slingLoadingRopes;

    MessageUpdateHelicopter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionHelicopter {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _backRotorWanted;
    float _mainRotorWanted;
    float _cyclicForwardWanted;
    float _cyclicAsideWanted;
    float _rotorDiveWanted;
    float _bankWanted;
    float _diveWanted;
    float _pilotHeading;
    float _pilotDive;
    vec3 _pilotSpeed;

    MessageUpdatePositionHelicopter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateParachute {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    float _openState;

    MessageUpdateParachute() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateParaglide {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    float _deltaVertical;
    float _deltaHorizontal;

    MessageUpdateParaglide() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateShip {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    float _thrustLWanted;
    float _thrustRWanted;
    vec3 _stopPosition;
    int _stopState;
    float _sink;

    MessageUpdateShip() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionShip {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    bool _pilotBrake;
    float _timeAfterLastLandContact;
    float _rpmWanted;

    MessageUpdatePositionShip() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNetMuzzleInfo {
    std::string _weapon;
    std::string _muzzle;
    int64_t _notemptymagazine; // indicates if the Object was actually sent or not
    MessageMagazine _magazine;

    MessageNetMuzzleInfo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePersonInventoryDescriptor {
    int64_t _notemptyprimaryWeapon; // indicates if the Object was actually sent or not
    MessageCountedWeaponsString _primaryWeapon;
    int64_t _notemptysecondaryWeapon; // indicates if the Object was actually sent or not
    MessageCountedWeaponsString _secondaryWeapon;
    int64_t _notemptyhandgunWeapon; // indicates if the Object was actually sent or not
    MessageCountedWeaponsString _handgunWeapon;
    int64_t _notemptybinocular; // indicates if the Object was actually sent or not
    MessageCountedWeaponsString _binocular;
    std::string _itemMap;
    std::string _itemCompass;
    std::string _itemWatch;
    std::string _itemRadio;
    std::string _itemGPS;
    std::string _itemGoggles;
    std::string _itemHMD;
    std::string _itemHeadgear;
    int64_t _notemptyuniformDescriptor; // indicates if the Object was actually sent or not
    MessageContainerRawData _uniformDescriptor;
    int64_t _notemptyvestDescriptor; // indicates if the Object was actually sent or not
    MessageContainerRawData _vestDescriptor;
    int64_t _notemptybackpackDescriptor; // indicates if the Object was actually sent or not
    MessageContainerRawData _backpackDescriptor;

    MessagePersonInventoryDescriptor() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePathPoint {
    vec3 _pos;
    float _cost;

    MessagePathPoint() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateMotorcycle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    std::string _plateNumber;
    float _thrustWanted;
    float _turnWanted;

    MessageUpdateMotorcycle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionMotorcycle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    bool _pilotBrake;
    float _timeAfterLastLandContact;

    MessageUpdatePositionMotorcycle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForHideBody {
    NetworkId _vehicle;

    MessageAskForHideBody() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNetworkCommand {
    int _type;
    std::vector<char> _content;

    MessageNetworkCommand() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageIntegrityQuestion {
    int _id;
    int _type;
    std::string _name;
    int _offset;
    int _size;

    MessageIntegrityQuestion() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageIntegrityAnswer {
    int _id;
    int _type;
    int _answer;

    MessageIntegrityAnswer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateSeagull {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    vec3 _pilotSpeed;
    float _pilotHeading;
    float _pilotHeight;
    int _state;

    MessageUpdateSeagull() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionSeagull {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _rpmWanted;
    float _mainRotorWanted;
    float _cyclicForwardWanted;
    float _cyclicAsideWanted;
    float _wingDiveWanted;
    float _thrustWanted;

    MessageUpdatePositionSeagull() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerUpdate {
    int _dpnid;
    int _minPing;
    int _avgPing;
    int _maxPing;
    int _minBandwidth;
    int _avgBandwidth;
    int _maxBandwidth;
    int _desync;
    int _rights;
    bool _isJip;
    int _level;

    MessagePlayerUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateDamageVehicleAI {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _isDestroyed;
    float _dammage;
    std::vector<float> _hit;
    bool _isDead;

    MessageUpdateDamageVehicleAI() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateDamageObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _isDestroyed;
    float _dammage;

    MessageUpdateDamageObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateHelicopter {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    float _rotorSpeed;

    MessageCreateHelicopter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateClientInfo {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _cameraPosition;
    vec3 _cameraDirection;
    float _cameraFov;

    MessageUpdateClientInfo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageShowTarget {
    NetworkId _vehicle;
    NetworkId _target;

    MessageShowTarget() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageShowSuppressTarget {
    NetworkId _vehicle;
    NetworkId _target;
    vec3 _pos;

    MessageShowSuppressTarget() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSynchronization {
    NetworkId _group;
    int _synchronization;
    bool _active;

    MessageGroupSynchronization() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDetectorActivation {
    NetworkId _detector;
    bool _active;

    MessageDetectorActivation() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForCreateUnit {
    NetworkId _group;
    std::string _type;
    vec3 _position;
    std::string _init;
    float _skill;
    int _rank;

    MessageAskForCreateUnit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDeleteVehicle {
    NetworkId _vehicle;

    MessageAskForDeleteVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForReceiveUnitAnswer {
    NetworkId _from;
    NetworkId _to;
    int _answer;

    MessageAskForReceiveUnitAnswer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForGroupRespawn {
    NetworkId _person;
    NetworkId _killer;
    NetworkId _group;
    int _from;

    MessageAskForGroupRespawn() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupRespawnDone {
    NetworkId _person;
    NetworkId _killer;
    NetworkId _respawn;
    int _to;

    MessageGroupRespawnDone() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMissionParams {
    float _param1;
    float _param2;
    std::vector<float> _paramsArray;
    bool _updateOnly;
    std::vector<int> _disabledChatChannels;
    std::vector<int> _disabledVoNChannels;

    MessageMissionParams() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateMine {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _active;
    float _triggerTimerTime;

    MessageUpdateMine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForActivateMine {
    NetworkId _mine;
    bool _activate;

    MessageAskForActivateMine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDetectedMine {
    NetworkId _center;
    NetworkId _mine;
    bool _addMine;

    MessageAskForDetectedMine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDisposeObject {
    NetworkId _object;
    Time _minTime;
    Time _maxTime;

    MessageDisposeObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVehicleDamaged {
    NetworkId _damaged;
    NetworkId _killer;
    float _damage;
    std::string _ammo;

    MessageVehicleDamaged() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateFireplace {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    bool _burning;

    MessageUpdateFireplace() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForInflameFire {
    NetworkId _fireplace;
    bool _fire;

    MessageAskForInflameFire() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAnimationPhase {
    NetworkId _vehicle;
    std::string _animation;
    float _phase;
    bool _bySource;
    float _speedCoef;

    MessageAskForAnimationPhase() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageIncomingMissile {
    NetworkId _target;
    NetworkId _shot;
    NetworkId _owner;

    MessageIncomingMissile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLaunchedCounterMeasures {
    NetworkId _cm;
    NetworkId _testedSystem;
    int _count;

    MessageLaunchedCounterMeasures() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSharedMineUsed {
    NetworkId _user;
    NetworkId _mine;
    int _action;

    MessageSharedMineUsed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetShotParents {
    NetworkId _shot;
    NetworkId _newOwner;
    NetworkId _newInstigator;

    MessageSetShotParents() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWeaponLocked {
    NetworkId _target;
    NetworkId _gunner;
    bool _locked;

    MessageWeaponLocked() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageForceDeleteObject {
    NetworkId _object;

    MessageForceDeleteObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJoinIntoUnit {
    int _dpnid;
    int _roleIndex;
    NetworkId _unit;
    NetworkId _group;

    MessageJoinIntoUnit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAIStatsMPRowCreate {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _dpnid;
    int _role;
    std::string _name;
    int _side;

    MessageAIStatsMPRowCreate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAIStatsMPRowUpdate {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _killsInfantry;
    int _killsSoft;
    int _killsArmor;
    int _killsAir;
    int _killsPlayers;
    int _customScore;
    int _liveStats;
    int _killed;

    MessageAIStatsMPRowUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWeatherCreate {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _windSpeed;
    vec3 _gust;
    float _rainDensityWanted;
    float _worldOvercast;
    float _worldFog;
    float _worldFogDecay;
    float _worldFogBase;
    float _worldWind;
    float _lightningsWanted;
    float _worldTime;
    float _worldTimeMultip;
    int _wavesTimeWanted;

    MessageWeatherCreate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWeatherUpdate {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _windSpeed;
    vec3 _gust;
    float _rainDensityWanted;
    float _worldOvercast;
    float _worldFog;
    float _worldFogDecay;
    float _worldFogBase;
    float _worldWind;
    float _lightningsWanted;
    float _worldTime;
    float _worldTimeMultip;
    int _wavesTimeWanted;

    MessageWeatherUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMuteList {
    std::vector<int64_t> _list;

    MessageMuteList() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVoiceOn {
    int _dpnid;
    bool _voiceOn;

    MessageVoiceOn() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCleanupPlayer {
    int _dpnid;
    int _creator;
    int _id;

    MessageCleanupPlayer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLockGearItem {
    NetworkId _supply;
    NetworkId _user;
    int _itemID;

    MessageLockGearItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUnlockGearItem {
    NetworkId _supply;
    NetworkId _user;
    int _itemID;

    MessageUnlockGearItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskItem {
    NetworkId _from;
    NetworkId _to;
    int _creator;
    int _itemId;
    int _itemType;
    int _id;
    NetworkId _supplyEnt;
    int _actionContainer;
    int _actionMode;

    MessageAskItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskWeapon {
    NetworkId _from;
    NetworkId _to;
    int64_t _notemptyweaponInfo; // indicates if the Object was actually sent or not
    MessageNetWeaponInfo _weaponInfo;
    int _slots;
    int _actionContainer;

    MessageAskWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskMagazine {
    NetworkId _from;
    NetworkId _to;
    std::string _type;
    int _actionContainer;

    MessageAskMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskBackpack {
    NetworkId _from;
    NetworkId _to;
    std::string _name;

    MessageAskBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReplaceItem {
    NetworkId _from;
    NetworkId _to;
    int _itemId;
    int _itemCreator;
    int _actionMode;

    MessageReplaceItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageStorePendingItem {
    NetworkId _from;
    NetworkId _to;
    int _creator;
    int _itemId;

    MessageStorePendingItem() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReplaceWeapon {
    NetworkId _from;
    NetworkId _to;
    int64_t _notemptyweaponInfo; // indicates if the Object was actually sent or not
    MessageNetWeaponInfo _weaponInfo;
    int _actionContainer;

    MessageReplaceWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReplaceMagazine {
    NetworkId _from;
    NetworkId _to;
    MessageMagazine _magazine;
    bool _reload;
    int _actionContainer;

    MessageReplaceMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReplaceBackpack {
    NetworkId _from;
    NetworkId _to;
    NetworkId _backpack;

    MessageReplaceBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReturnWeapon {
    NetworkId _from;
    std::string _weapon;

    MessageReturnWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReturnMagazine {
    NetworkId _from;
    MessageMagazine _magazine;

    MessageReturnMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReturnBackpack {
    NetworkId _from;
    NetworkId _backpack;

    MessageReturnBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCancelTakeFlag {
    NetworkId _flag;

    MessageCancelTakeFlag() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolAskWeapon {
    int _creator;
    int _id;
    std::string _weapon;
    int _slot;
    bool _useBackpack;

    MessagePoolAskWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolAskMagazine {
    int _creator;
    int _id;
    std::string _type;
    int _slot;
    bool _useBackpack;

    MessagePoolAskMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolAskBackpack {
    int _creator;
    int _id;
    std::string _name;

    MessagePoolAskBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReplaceWeapon {
    int _creator;
    int _id;
    std::string _weapon;
    int _slot;
    bool _useBackpack;

    MessagePoolReplaceWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReplaceMagazine {
    int _creator;
    int _id;
    MessageMagazine _magazine;
    int _slot;
    bool _useBackpack;

    MessagePoolReplaceMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReplaceBackpack {
    int _creator;
    int _id;
    int _bagCreator;
    int _bagId;
    std::string _typeName;

    MessagePoolReplaceBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReturnWeapon {
    std::string _weapon;

    MessagePoolReturnWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReturnMagazine {
    MessageMagazine _magazine;

    MessagePoolReturnMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePoolReturnBackpack {
    int _creator;
    int _id;
    std::string _typeName;

    MessagePoolReturnBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskSetUnitLoadOutFromClassName {
    NetworkId _vehicle;
    std::string _className;

    MessageAskSetUnitLoadOutFromClassName() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskSetUnitLoadOutFromRawData {
    NetworkId _vehicle;
    int64_t _notemptydescriptor; // indicates if the Object was actually sent or not
    MessagePersonInventoryDescriptor _descriptor;

    MessageAskSetUnitLoadOutFromRawData() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateWeaponsInfo {
    NetworkId _unit;
    std::vector<std::string> _weapons;
    std::vector<MessageMagazine*> _magazines;
    NetworkId _backpack;

    MessageUpdateWeaponsInfo() {};
    ~MessageUpdateWeaponsInfo();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateWeaponSlotsData {
    std::string _mapName;
    std::string _compassName;
    std::string _watchesName;
    std::string _radioName;
    std::string _gpsName;
    std::string _headgearName;
    std::string _gogglesName;
    std::string _hmdName;
    std::string _uniformName;
    NetworkId _uniformEnt;
    std::string _vestName;
    NetworkId _vestEnt;
    NetworkId _backpack;

    MessageUpdateWeaponSlotsData() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateWeaponsPool {
    std::vector<std::string> _weapons;

    MessageUpdateWeaponsPool() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateMagazinesPool {
    std::vector<MessageMagazine*> _magazines;

    MessageUpdateMagazinesPool() {};
    ~MessageUpdateMagazinesPool();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateBackpacksPool {
    std::vector<int> _creators;
    std::vector<int> _ids;

    MessageUpdateBackpacksPool() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSite {
    vec3 _position;

    MessageSite() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateSlotMgr {
    std::string _mapName;
    int _mapId;
    int _mapCreator;
    std::string _compassName;
    int _compassId;
    int _compassCreator;
    std::string _watchesName;
    int _watchesId;
    int _watchesCreator;
    std::string _radioName;
    int _radioId;
    int _radioCreator;
    std::string _gpsName;
    int _gpsId;
    int _gpsCreator;
    std::string _headgearName;
    int _headgearId;
    int _headgearCreator;
    std::string _gogglesName;
    int _gogglesId;
    int _gogglesCreator;
    std::string _hmdName;
    int _hmdId;
    int _hmdCreator;
    std::string _uniformName;
    NetworkId _uniformEnt;
    std::string _vestName;
    NetworkId _vestEnt;

    MessageUpdateSlotMgr() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetRoleIndex {
    NetworkId _unit;
    int _roleIndex;

    MessageSetRoleIndex() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateSeagull {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    int _player;

    MessageCreateSeagull() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVLoadMagazine {
    NetworkId _vehicle;
    NetworkId _receiver;
    int _magazineCreator;
    int _magazineId;
    std::string _weapon;
    std::string _muzzle;

    MessageMsgVLoadMagazine() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVWatchTgt {
    NetworkId _vehicle;
    NetworkId _receiver;
    NetworkId _target;

    MessageMsgVWatchTgt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMsgVWatchPos {
    NetworkId _vehicle;
    NetworkId _receiver;
    vec3 _position;

    MessageMsgVWatchPos() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRevealTarget {
    int _to;
    NetworkId _group;
    NetworkId _target;

    MessageRevealTarget() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateDynSoundSource {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    std::string _soundName;

    MessageCreateDynSoundSource() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateDestructionEffects {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    NetworkId _object;
    NetworkId _owner;
    float _intensity;
    float _interval;
    float _fireIntensity;
    float _fireInterval;
    float _lifeTime;
    float _distToWater;

    MessageCreateDestructionEffects() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteMuteList {
    std::vector<int> _list;

    MessageRemoteMuteList() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForApplyDoDamage {
    NetworkId _who;
    NetworkId _owner;
    NetworkId _shotInstigator;
    std::string _ammo;
    std::string _weapon;
    float _damage;
    std::vector<float> _hits;
    bool _direct;

    MessageAskForApplyDoDamage() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForApplyBleeding {
    NetworkId _who;
    NetworkId _owner;
    float _value;
    int _type;

    MessageAskForApplyBleeding() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForStatsWrite {
    int _board;
    std::vector<XOnlineStat> _stats;
    int _boardTotal;
    std::vector<XOnlineStat> _statsTotal;

    MessageAskForStatsWrite() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLocalizedChat {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::string _name;
    std::vector<LocalizedString> _args;
    int _chatMessageType;

    MessageLocalizedChat() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateTurret {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    NetworkId _vehicle;
    std::vector<int> _path;

    MessageCreateTurret() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVoteMission {
    std::string _name;
    std::string _diff;

    MessageVoteMission() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVotingMissionProgress {
    std::vector<LocalizedString> _missions;
    std::vector<int> _missionVotes;
    std::string _diff;

    MessageVotingMissionProgress() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerBan {
    int _dpnid;
    std::vector<char> _content;

    MessagePlayerBan() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerBanSelf {
    int _dpnid;

    MessagePlayerBanSelf() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerTimeout {
    int _timeout;

    MessageServerTimeout() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAcceptedKey {
    std::string _name;
    std::vector<char> _content;

    MessageAcceptedKey() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAdditionalSignedFiles {
    std::vector<std::string> _list;

    MessageAdditionalSignedFiles() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDataSignatureAsk {
    int _index;
    int _level;

    MessageDataSignatureAsk() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDataSignatureAnswer {
    int _index;
    std::string _fileName;
    std::string _keyName;
    std::vector<char> _keyContent;
    std::vector<char> _signature;
    std::vector<char> _hash;
    int _version;
    int _level;

    MessageDataSignatureAnswer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageHackedData {
    int _type;
    std::string _filename;

    MessageHackedData() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateAITeam {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    std::string _typeName;
    std::string _name;

    MessageCreateAITeam() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAITeam {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    std::vector<NetworkId> _teamMembers;
    NetworkId _teamLeader;
    std::string _formation;

    MessageUpdateAITeam() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionTurret {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _gunStabilized;
    float _yRotWanted;
    float _xRotWanted;
    float _elevationWanted;

    MessageUpdatePositionTurret() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageStaticObjectDestructed {
    NetworkId _object;
    bool _now;
    bool _immediate;
    NetworkId _damagedVariant;

    MessageStaticObjectDestructed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskConnectVoice {
    int _publicAddr;
    int _privateAddr;
    int _voicePort;
    int _verNo;

    MessageAskConnectVoice() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageConnectVoiceDirect {
    int _dpnid;
    int _addr;
    int _port;
    bool _direct;

    MessageConnectVoiceDirect() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageConnectVoiceNatNeg {
    int _dpnid;
    int _cookie;
    int _clientIndex;

    MessageConnectVoiceNatNeg() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDisconnect {
    std::string _message;

    MessageDisconnect() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWaypointCreate {
    NetworkId _group;
    int _index;
    MessageWaypoint _waypoint;

    MessageWaypointCreate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWaypointUpdate {
    NetworkId _group;
    int _index;
    MessageWaypoint _waypoint;

    MessageWaypointUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWaypointDelete {
    NetworkId _group;
    int _index;
    int _idWP;

    MessageWaypointDelete() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageHCSetGroup {
    NetworkId _unit;
    NetworkId _group;
    int _team;
    std::string _name;

    MessageHCSetGroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageHCRemoveGroup {
    NetworkId _unit;
    NetworkId _group;

    MessageHCRemoveGroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageHCClearGroups {
    NetworkId _unit;

    MessageHCClearGroups() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMissionStats {
    int _toCreate;
    int _toUpdate;

    MessageMissionStats() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForFireWeapon {
    NetworkId _vehicle;
    NetworkId _turret;
    int _weapon;
    NetworkId _target;
    bool _forceLock;

    MessageAskForFireWeapon() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForGetInWantsPlayer {
    NetworkId _unit;
    bool _flag;

    MessageAskForGetInWantsPlayer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForOrderGetIn {
    NetworkId _unit;
    bool _flag;

    MessageAskForOrderGetIn() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAllowGetIn {
    NetworkId _unit;
    bool _flag;

    MessageAskForAllowGetIn() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAirportSetSide {
    int _airportId;
    int _side;

    MessageAskForAirportSetSide() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForArbitration {
    int64_t _sessionNonce;

    MessageAskForArbitration() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateDamageVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _isDestroyed;
    float _dammage;
    std::vector<float> _hit;

    MessageUpdateDamageVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageBattlEye {
    std::vector<char> _message;

    MessageBattlEye() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForTeamSwitch {
    int _player;
    NetworkId _from;
    NetworkId _to;
    NetworkId _killer;
    bool _respawn;

    MessageAskForTeamSwitch() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTeamSwitchResult {
    int _player;
    NetworkId _from;
    NetworkId _to;
    NetworkId _killer;
    bool _respawn;
    bool _result;

    MessageTeamSwitchResult() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageFinishTeamSwitch {
    int _player;
    NetworkId _from;
    NetworkId _to;
    NetworkId _killer;
    bool _respawn;
    NetworkId _fromGroup;
    NetworkId _fromLeader;

    MessageFinishTeamSwitch() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageKBReact {
    NetworkId _from;
    NetworkId _to;
    std::string _topic;
    std::string _message;
    std::vector<MessagePublicVariable*> _arguments;

    MessageKBReact() {};
    ~MessageKBReact();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjectSetVariable {
    NetworkId _object;
    std::string _name;
    std::vector<char> _value;

    MessageObjectSetVariable() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjectSetVariablesCollection {
    NetworkId _object;
    std::vector<int> _namesLength;
    std::vector<char> _names;
    std::vector<int> _valuesLength;
    std::vector<char> _value;

    MessageObjectSetVariablesCollection() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageWaypointsCopy {
    NetworkId _to;
    NetworkId _from;

    MessageWaypointsCopy() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAttachObject {
    NetworkId _obj;
    NetworkId _attachTo;
    int _memIndex;
    vec3 _pos;
    int _flags;

    MessageAttachObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDetachObject {
    NetworkId _obj;

    MessageDetachObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSetVariable {
    NetworkId _group;
    std::string _name;
    std::vector<char> _value;

    MessageGroupSetVariable() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCustomFile {
    std::vector<std::string> _filenames;
    int _typemask;
    int _crc;
    int _len;

    MessageCustomFile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCustomFileList {
    int _player;
    std::string _name;
    std::vector<MessageCustomFile*> _fileList;

    MessageCustomFileList() {};
    ~MessageCustomFileList();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCustomFilesWanted {
    int _player;
    std::vector<int> _filesWanted;

    MessageCustomFilesWanted() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDeleteCustomFiles {
    std::vector<std::string> _list;

    MessageDeleteCustomFiles() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerRoleUpdate {
    int _index;
    int _player;
    int _lifeState;

    MessagePlayerRoleUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNatNegResult {
    int _dpnid;
    bool _result;

    MessageNatNegResult() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateClientInfoDpid {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _cameraPosition;
    int _dpnid;

    MessageUpdateClientInfoDpid() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerTime {
    int _time;
    int _endTime;

    MessageServerTime() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateDoor {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;

    MessageUpdateDoor() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionDoor {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;

    MessageUpdatePositionDoor() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSetUnconsciousLeader {
    NetworkId _unit;
    NetworkId _group;

    MessageGroupSetUnconsciousLeader() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSelectLeader {
    NetworkId _unit;
    NetworkId _group;

    MessageGroupSelectLeader() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAssignTeam {
    NetworkId _unit;
    int _team;

    MessageAskForAssignTeam() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLoadedFromSave {

    MessageLoadedFromSave() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerDifficulty {
    std::string _forcedDifficulty;
    std::string _currentDifficulty;

    MessageServerDifficulty() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerAdmin {
    bool _admin;
    int _gameMaster;

    MessageServerAdmin() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTakeBackpack {
    NetworkId _backpack;
    NetworkId _soldier;

    MessageTakeBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAssemble {
    NetworkId _weapon;
    matrix3x3 _transform;
    vec3 _position;
    std::string _assembleBaseFrom;

    MessageAssemble() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDisAssemble {
    NetworkId _weapon;
    NetworkId _backpack;

    MessageDisAssemble() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskProcessDisAssemble {
    NetworkId _weapon;
    NetworkId _unit;

    MessageAskProcessDisAssemble() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageShowGroupDir {
    NetworkId _vehicle;
    vec3 _dir;

    MessageShowGroupDir() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetMaxHitZoneDamage {
    NetworkId _who;
    float _dammage;

    MessageAskForSetMaxHitZoneDamage() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForEnableVMode {
    NetworkId _vehicle;
    int _enable;

    MessageAskForEnableVMode() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForForceGunLight {
    NetworkId _vehicle;
    int _mode;

    MessageAskForForceGunLight() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForIRLaser {
    NetworkId _vehicle;
    bool _enable;

    MessageAskForIRLaser() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForVehicleDoorState {
    NetworkId _vehicle;
    int _doorIndex;
    bool _opened;

    MessageAskForVehicleDoorState() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForChangeSide {
    NetworkId _vehicle;
    int _side;

    MessageAskForChangeSide() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVehMPEventHandlers {
    NetworkId _vehicle;
    int _eventNum;
    std::vector<std::string> _handlers;

    MessageVehMPEventHandlers() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageVehMPEvent {
    int _eventNum;
    std::vector<char> _pars;

    MessageVehMPEvent() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageMissionMPEvent {
    int _eventNum;
    std::vector<char> _pars;

    MessageMissionMPEvent() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteEntityEvent {
    int _eventNum;
    NetworkId _entity;
    std::vector<char> _pars;

    MessageRemoteEntityEvent() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageClearWeaponCargo {
    NetworkId _vehicle;

    MessageClearWeaponCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageClearItemCargo {
    NetworkId _vehicle;

    MessageClearItemCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageClearMagazineCargo {
    NetworkId _vehicle;

    MessageClearMagazineCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageClearBackpackCargo {
    NetworkId _vehicle;

    MessageClearBackpackCargo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateClientCameraPosition {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _dpnid;

    MessageCreateClientCameraPosition() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateClientCameraPosition {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;

    MessageUpdateClientCameraPosition() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreatePlayerRuntime {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _dpid;

    MessageCreatePlayerRuntime() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePlayerRuntime {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _cameraType;
    int _opticsMode;

    MessageUpdatePlayerRuntime() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteControlled {
    NetworkId _whom;
    NetworkId _who;

    MessageAskRemoteControlled() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetRank {
    NetworkId _who;
    int _rank;

    MessageAskForSetRank() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForVehicleControl {
    NetworkId _copilot;
    NetworkId _vehicle;
    bool _unlockedControls;

    MessageAskForVehicleControl() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageOwnerChanged {
    int _creator;
    int _id;

    MessageOwnerChanged() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLastOperPos {
    int _to;
    NetworkId _brain;
    int _lastFieldPosX;
    int _lastFieldPosZ;
    int _x;
    int _z;
    int _type;
    int _clearance;
    NetworkId _houseOrRoad;
    int _posIndex;

    MessageLastOperPos() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageFileSignatureAsk {
    std::string _file;
    int _level;

    MessageFileSignatureAsk() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageFileSignatureAnswer {
    std::string _fileName;
    std::string _keyName;
    std::vector<char> _keyContent;
    std::vector<char> _signature;
    std::vector<char> _dataToHash;
    int _version;
    int _level;
    int _index;

    MessageFileSignatureAnswer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageChangeCreatorId {
    int _creator;

    MessageChangeCreatorId() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAllowCrewInImmobile {
    NetworkId _vehicle;
    bool _enable;

    MessageAskForAllowCrewInImmobile() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForPilotLight {
    NetworkId _vehicle;
    bool _enable;

    MessageAskForPilotLight() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateRadioChannel {
    int _channel;
    int _color;
    std::string _label;
    std::string _callSign;
    std::vector<NetworkId> _units;

    MessageCreateRadioChannel() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChannelLabel {
    int _channel;
    std::string _label;

    MessageRadioChannelLabel() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChannelCallSign {
    int _channel;
    std::string _callSign;

    MessageRadioChannelCallSign() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChannelUnits {
    int _channel;
    std::vector<NetworkId> _units;

    MessageRadioChannelUnits() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSendAUMsg {
    std::vector<char> _value;

    MessageSendAUMsg() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLockSupply {
    NetworkId _supply;
    NetworkId _user;

    MessageLockSupply() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUnlockSupply {
    NetworkId _supply;
    NetworkId _user;

    MessageUnlockSupply() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageReturnEquipment {
    NetworkId _to;
    NetworkId _from;
    std::vector<MessageNetWeaponInfo*> _weaponInfos;
    std::vector<MessageMagazine*> _magazines;
    NetworkId _backpack;

    MessageReturnEquipment() {};
    ~MessageReturnEquipment();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageServerInfo {
    std::string _hostname;
    int _flags;
    std::vector<std::string> _allowedLoadFileExtensions;
    std::vector<std::string> _allowedPreprocessFileExtensions;
    std::vector<std::string> _allowedHTMLloadExtensions;
    std::vector<int> _allowedVoteCmds;
    std::vector<int> _allowedVotedAdminCmds;
    std::vector<int> _allowedVoteCmdsMask;
    std::vector<int> _allowedVotedAdminCmdsMask;
    std::vector<std::string> _allowedHTMLloadURIs;
    int _vonCodec;

    MessageServerInfo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicVariableTo {
    std::string _name;
    std::vector<char> _value;
    int _player;

    MessagePublicVariableTo() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUavTerminalCreateConnection {
    NetworkId _owner;
    NetworkId _transport;

    MessageUavTerminalCreateConnection() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateInvisibleVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    int _remotePlayer;
    bool _reportRemoteTargets;
    bool _receiveRemoteTargets;
    bool _reportOwnPosition;

    MessageUpdateInvisibleVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRadioChatBroadcast {
    int _channel;
    NetworkId _sender;
    std::vector<NetworkId> _units;
    std::vector<Sentence> _sentence;
    std::string _wordsClass;

    MessageRadioChatBroadcast() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetObjectTexture {
    NetworkId _veh;
    int _index;
    std::string _name;

    MessageSetObjectTexture() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageForceFlagTexture {
    NetworkId _veh;
    std::string _name;

    MessageForceFlagTexture() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddSideScore {
    int _side;
    int _score;

    MessageAddSideScore() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetVisibility {
    NetworkId _object;
    bool _visible;

    MessageAskForSetVisibility() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForEnableSimulation {
    NetworkId _entity;
    bool _simulate;

    MessageAskForEnableSimulation() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForRemoveFromCenter {
    NetworkId _group;

    MessageAskForRemoveFromCenter() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForForceWeatherUpdate {
    bool _force;

    MessageAskForForceWeatherUpdate() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetPlanningMode {
    NetworkId _brain;
    int _mode;
    bool _replan;

    MessageAskForSetPlanningMode() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDisconnectUav {
    NetworkId _vehicle;

    MessageAskForDisconnectUav() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUavTerminalReleaseConnection {
    NetworkId _uav;

    MessageUavTerminalReleaseConnection() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetRemoveMode {
    NetworkId _entity;
    int _removeMode;

    MessageAskForSetRemoveMode() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetParticleClass {
    NetworkId _source;
    std::string _className;

    MessageSetParticleClass() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForCreateAndAddBackpack {
    std::string _backpackName;
    NetworkId _soldier;

    MessageAskForCreateAndAddBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDeleteBackpack {
    NetworkId _soldier;

    MessageAskForDeleteBackpack() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForDeleteGroup {
    NetworkId _group;

    MessageAskForDeleteGroup() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageStartWeaponDeploy {
    NetworkId _owner;
    vec3 _originalPosition;
    matrix3x3 _originalOrientation;
    vec3 _bipodPos;
    matrix3x3 _bipodOrientation;
    vec3 _playerPosition;
    float _horizontalLimit;
    int _mode;

    MessageStartWeaponDeploy() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageStopWeaponDeploy {
    NetworkId _owner;

    MessageStopWeaponDeploy() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionTankOrCar {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    bool _pilotBrake;
    float _timeAfterLastLandContact;

    MessageUpdatePositionTankOrCar() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteExecServer {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targets;
    bool _removeDuplicates;

    MessageAskRemoteExecServer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteExecServerNamed {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targets;
    bool _removeDuplicates;
    std::string _name;

    MessageAskRemoteExecServerNamed() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteExecClient {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targets;
    bool _removeDuplicates;
    int _origin;

    MessageAskRemoteExecClient() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecServer {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    int _playerID;
    int _repeatCnt;

    MessageRemoteExecServer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecClient {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;

    MessageRemoteExecClient() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecUnJIP {
    std::string _JIPID;

    MessageRemoteExecUnJIP() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNamespaceSetVariable {
    std::string _namespace;
    std::string _name;
    std::vector<char> _value;

    MessageNamespaceSetVariable() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteExecClientOne {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targets;
    bool _removeDuplicates;
    int _playerID;

    MessageAskRemoteExecClientOne() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetGroupIdentity {
    NetworkId _group;
    std::string _nameFormat;
    std::vector<std::string> _nameParts;

    MessageSetGroupIdentity() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecServerExt {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    int _playerID;
    std::vector<char> _targetGroupsSides;
    int _origin;

    MessageRemoteExecServerExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecClientExt {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targetGroupOrSide;
    int _origin;

    MessageRemoteExecClientExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecClientMulti {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    int _repeatCnt;

    MessageRemoteExecClientMulti() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetObjectMaterial {
    NetworkId _veh;
    int _index;
    std::string _name;

    MessageSetObjectMaterial() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjectSetVariableClient {
    std::string _name;
    std::vector<char> _object;
    std::vector<char> _value;

    MessageObjectSetVariableClient() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjectSetVariableExt {
    NetworkId _object;
    std::string _name;
    std::vector<char> _value;
    int _target;

    MessageObjectSetVariableExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjectSetVariableExtArray {
    NetworkId _object;
    std::string _name;
    std::vector<char> _value;
    std::vector<int> _targets;

    MessageObjectSetVariableExtArray() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSetVariableClient {
    std::string _name;
    std::vector<char> _group;
    std::vector<char> _value;

    MessageGroupSetVariableClient() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSetVariableExt {
    NetworkId _group;
    std::string _name;
    std::vector<char> _value;
    int _target;

    MessageGroupSetVariableExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageGroupSetVariableExtArray {
    NetworkId _group;
    std::string _name;
    std::vector<char> _value;
    std::vector<int> _targets;

    MessageGroupSetVariableExtArray() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTeamMemberSetVariableExt {
    int _id;
    int _creator;
    std::string _name;
    std::vector<char> _value;
    int _target;

    MessageTeamMemberSetVariableExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTeamMemberSetVariableExtArray {
    int _id;
    int _creator;
    std::string _name;
    std::vector<char> _value;
    std::vector<int> _targets;

    MessageTeamMemberSetVariableExtArray() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNamespaceSetVariableExt {
    std::string _namespace;
    std::string _name;
    std::vector<char> _value;
    int _target;

    MessageNamespaceSetVariableExt() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageNamespaceSetVariableExtArray {
    std::string _namespace;
    std::string _name;
    std::vector<char> _value;
    std::vector<int> _targets;

    MessageNamespaceSetVariableExtArray() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSetVisibility {
    NetworkId _object;
    bool _visible;

    MessageSetVisibility() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageSyncVarsInJIPQueue {
    NetworkId _id;
    NetworkId _idPrev;

    MessageSyncVarsInJIPQueue() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicKey {
    std::vector<char> _key;

    MessagePublicKey() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicKeyAck {
    std::vector<char> _key;

    MessagePublicKeyAck() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicKeyBE {
    std::vector<char> _key;

    MessagePublicKeyBE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePublicKeyAckBE {
    std::vector<char> _key;

    MessagePublicKeyAckBE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateEntitySimple {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    std::string _shapeName;
    std::string _className;

    MessageCreateEntitySimple() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageObjHideAnimSection {
    NetworkId _vehicle;
    std::string _animation;
    bool _hide;

    MessageObjHideAnimSection() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskRemoteExecServerNamedObjGrp {
    std::string _command;
    std::vector<char> _params;
    int _flags;
    int _originalCaller;
    std::vector<char> _targets;
    bool _removeDuplicates;
    NetworkId _objgrp;

    MessageAskRemoteExecServerNamedObjGrp() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRemoteExecUnJIPObjGrp {
    int _creator;
    int _id;

    MessageRemoteExecUnJIPObjGrp() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTransferFileAck {
    std::string _path;
    int _ackSegment;

    MessageTransferFileAck() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForEnableActiveSensors {
    NetworkId _vehicle;
    bool _enable;

    MessageAskForEnableActiveSensors() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForApplyObjectFlag {
    NetworkId _entity;
    bool _state;
    int _flag;

    MessageAskForApplyObjectFlag() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForceAIActiveSensors {
    NetworkId _transport;
    int _value;

    MessageAskForceAIActiveSensors() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskSetReportRemoteTargets {
    NetworkId _entity;
    bool _value;

    MessageAskSetReportRemoteTargets() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskSetReceiveRemoteTargets {
    NetworkId _entity;
    bool _value;

    MessageAskSetReceiveRemoteTargets() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskSetReportOwnPosition {
    NetworkId _entity;
    bool _value;

    MessageAskSetReportOwnPosition() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddEPEForce {
    NetworkId _vehicle;
    vec3 _force;
    vec3 _position;

    MessageAddEPEForce() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAddEPETorque {
    NetworkId _vehicle;
    vec3 _force;

    MessageAddEPETorque() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageBankCount {
    int _channel;
    int _sender;

    MessageBankCount() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePlayerBE {
    int _dpnid;

    MessagePlayerBE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForGetOutToPos {
    NetworkId _soldier;
    NetworkId _vehicle;
    NetworkId _turret;
    vec3 _pos;
    vec3 _dir;
    bool _broadcast;

    MessageAskForGetOutToPos() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDataHashCheckAsk {
    int _index;
    int _count;
    int _dataSizeDecompressed;

    MessageDataHashCheckAsk() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDataHashCheckAnswer {
    int _index;
    std::string _bankPrefix;
    std::vector<char> _quickHash;

    MessageDataHashCheckAnswer() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTransferDataHashCheck {
    int _ID;
    std::vector<char> _data;
    int _totSize;
    int _offset;
    int _totSegments;
    int _curSegment;

    MessageTransferDataHashCheck() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskCheckCmdPwd {
    int _id;
    int _hash;
    std::vector<char> _pwd;

    MessageAskCheckCmdPwd() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAcceptCheckCmdPwd {
    int _id;
    int _hash;

    MessageAcceptCheckCmdPwd() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDenyCheckCmdPwd {
    int _id;
    int _hash;

    MessageDenyCheckCmdPwd() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateCuratorCommander {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    int _remotePlayer;
    bool _reportRemoteTargets;
    bool _receiveRemoteTargets;
    bool _reportOwnPosition;
    std::vector<NetworkId> _assignedUnits;
    float _points;
    float _cameraCeiling;
    float _waypointCost;
    std::vector<float> _coeficients;
    NetworkId _assignedCuratorCommander;
    int _markersCounter;
    std::vector<float> _moveRadiuses;
    std::vector<float> _moveAreas;
    std::vector<int> _moveAreasIds;
    std::vector<float> _editRadiuses;
    std::vector<float> _editAreas;
    std::vector<int> _editAreasIds;
    bool _areasType;
    NetworkId _logicGroup;

    MessageUpdateCuratorCommander() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForJoinCuratorCommander {
    NetworkId _cCommander;
    NetworkId _cLogic;

    MessageAskForJoinCuratorCommander() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForJoinCuratorLogic {
    NetworkId _cCommander;
    NetworkId _cLogic;

    MessageAskForJoinCuratorLogic() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForChangeCuratorPoints {
    NetworkId _cLogic;
    float _points;

    MessageAskForChangeCuratorPoints() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAddCuratorEditableUnit {
    NetworkId _cLogic;
    NetworkId _unit;
    bool _crew;
    bool _unassign;

    MessageAskForAddCuratorEditableUnit() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForAddCuratorArea {
    NetworkId _cLogic;
    int _id;
    vec3 _worldPosition;
    float _radius;
    int _type;

    MessageAskForAddCuratorArea() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForRemoveCuratorArea {
    NetworkId _cLogic;
    int _id;
    int _type;

    MessageAskForRemoveCuratorArea() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForChangeCuratorCameraMoveCeiling {
    NetworkId _cLogic;
    float _height;

    MessageAskForChangeCuratorCameraMoveCeiling() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetCuratorActionCoef {
    NetworkId _cLogic;
    int _type;
    float _coef;

    MessageAskForSetCuratorActionCoef() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSetCuratorWaypointCost {
    NetworkId _cLogic;
    float _cost;

    MessageAskForSetCuratorWaypointCost() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForModifyCuratorAllowedAddons {
    NetworkId _cLogic;
    std::vector<std::string> _addons;
    bool _remove;

    MessageAskForModifyCuratorAllowedAddons() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForChangeCuratorEditAreaType {
    NetworkId _cLogic;
    bool _type;

    MessageAskForChangeCuratorEditAreaType() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForPingCurator {
    NetworkId _cLogic;
    NetworkId _player;

    MessageAskForPingCurator() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessagePolymorphPosition {
    NetworkId _object;
    vec3 _position;
    std::string _selectionName;

    MessagePolymorphPosition() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJointDOFs {
    int _linearX;
    int _linearY;
    int _linearZ;
    int _swing1;
    int _swing2;
    int _twist;

    MessageJointDOFs() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJointLimits {
    float _value;
    float _restitution;
    float _spring;
    float _damping;

    MessageJointLimits() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJointDrives {
    int _type;
    float _value;
    float _spring;
    float _damping;

    MessageJointDrives() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJointDescription {
    MessageJointDOFs _dofs;
    MessageJointLimits _linearLimit;
    MessageJointLimits _swing1Limit;
    MessageJointLimits _swing2Limit;
    MessageJointLimits _twistLowLimit;
    MessageJointLimits _twistHighLimit;
    MessageJointDrives _linearDriveX;
    MessageJointDrives _linearDriveY;
    MessageJointDrives _linearDriveZ;
    MessageJointDrives _angularSwingDrive;
    MessageJointDrives _angularTwistDrive;
    MessageJointDrives _angularSlerpDrive;

    MessageJointDescription() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageJointParameters {
    int _type;
    vec3 _connectionPos;
    MessagePolymorphPosition _connectFrom;
    MessagePolymorphPosition _connectTo;
    MessagePolymorphPosition _axisConnectFrom;
    MessagePolymorphPosition _axisConnectTo;
    MessagePolymorphPosition _dirConnectFrom;
    MessagePolymorphPosition _dirConnectTo;
    float _driveBySteering;
    MessageJointDescription _jointDescription;
    float _dampingFrom;
    float _dampingTo;
    float _breakForce;
    bool _collisionsEnabled;
    bool _alignOrientation;

    MessageJointParameters() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateJointConnection {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    MessageJointParameters _jp;
    NetworkId _object;
    NetworkId _neighbour;

    MessageCreateJointConnection() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAttachEPE {
    NetworkId _parent;
    NetworkId _child;
    MessageJointParameters _jointParams;

    MessageAttachEPE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageDetachEPE {
    NetworkId _parent;

    MessageDetachEPE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateSmokeEPE {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _smoke;

    MessageUpdateSmokeEPE() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageChangeVisibilityAI {
    NetworkId _object;
    bool _ifVis;
    bool _ifFire;
    bool _ifView;
    bool _ifGeo;
    float _updatePos;

    MessageChangeVisibilityAI() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateRagdollMan {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _ragdollMode;
    int _ragdollState;
    matrix3x3 _itemOrientPrimary;
    vec3 _itemPosPrimary;
    vec3 _itemSpeedPrimary;
    vec3 _itemAngVelocityPrimary;
    matrix3x3 _itemOrientSecondary;
    vec3 _itemPosSecondary;
    vec3 _itemSpeedSecondary;
    vec3 _itemAngVelocitySecondary;

    MessageUpdateRagdollMan() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRagdollRequested {
    NetworkId _who;
    vec3 _speed;

    MessageRagdollRequested() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRagdollSyncAll {
    NetworkId _who;
    std::vector<float> _positionX;
    std::vector<float> _positionY;
    std::vector<float> _positionZ;
    std::vector<float> _quaternionX;
    std::vector<float> _quaternionY;
    std::vector<float> _quaternionZ;
    std::vector<float> _quaternionW;

    MessageRagdollSyncAll() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageRagdollShotImpact {
    NetworkId _who;
    vec3 _force;
    vec3 _shotPos;

    MessageRagdollShotImpact() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateHelicopterRTD {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    float _rotorSpeed;

    MessageCreateHelicopterRTD() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateHelicopterRTD {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _fireTarget;
    NetworkId _curatorLogic;
    int _removeMode;
    int _knownForInfo;
    NetworkId _driver;
    bool _driverLocked;
    NetworkId _effCommander;
    std::vector<NetworkId> _manCargo;
    std::vector<char> _cargoLocked;
    NetworkId _comFireTarget;
    int _lock;
    float _driverHiddenWanted;
    float _fuel;
    bool _engineOff;
    bool _manualFire;
    int _respawnSide;
    bool _respawning;
    bool _respawnFlying;
    NetworkId _respawnUnit;
    float _respawnDelay;
    int _respawnCount;
    int _enableVisionMode;
    bool _allowCrewInImmobile;
    NetworkId _copilot;
    bool _unLockedControls;
    bool _enableCopilots;
    std::vector<char> _doors;
    bool _wheelsBlocked;
    bool _enableUavTerminalChangeWaypoints;
    std::vector<char> _damageEffectsFinished;
    int _crashSoundType;
    std::vector<NetworkId> _vehiclesTransported;
    bool _isDrowning;
    int _sensorsStates;
    float _rotorSpeedWanted;
    int _state;
    float _pilotHeight;
    int _stopMode;
    int _stopResult;
    vec3 _stopPosition;
    bool _pilotSpeedHelper;
    bool _pilotHeightHelper;
    bool _pilotDirHelper;
    bool _pilotGear;
    bool _hoveringAutopilot;
    int _slingLoadingState;
    NetworkId _slingLoadedCargo;
    vec3 _slingLoadedCargoCenter;
    std::vector<NetworkId> _slingLoadingRopes;
    float _customWeight;
    int _rotorsFullyDestroyed;

    MessageUpdateHelicopterRTD() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionHelicopterRTD {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;
    float _backRotorWanted;
    float _mainRotorWanted;
    float _cyclicForwardWanted;
    float _cyclicAsideWanted;
    float _rotorDiveWanted;
    float _bankWanted;
    float _diveWanted;
    float _pilotHeading;
    float _pilotDive;
    vec3 _pilotSpeed;

    MessageUpdatePositionHelicopterRTD() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageCreateRopeObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    int _list;
    std::string _type;
    std::string _shape;
    vec3 _position;
    matrix3x3 _orientation;
    std::string _name;
    int _idVehicle;
    int _idOfFirstStoredItem;
    int _idOfSupplyCreator;
    bool _callInit;
    NetworkId _hierParent;
    std::vector<float> _hit;
    int _flags;
    NetworkId _parent;
    vec3 _attachOffset;
    int _memoryPointIndex;
    std::vector<NetworkId> _toObjs;
    std::vector<float> _toAttachOffsetX;
    std::vector<float> _toAttachOffsetY;
    std::vector<float> _toAttachOffsetZ;
    float _length;
    int _segments;
    std::string _ropeStartType;
    std::string _ropeEndType;
    vec3 _ropeStartDownVector;
    vec3 _ropeEndDownVector;

    MessageCreateRopeObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateRopeObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    bool _canSmoke;
    float _destroyed;
    int _targetSide;
    float _EPEMass;
    vec3 _EPECom;
    NetworkId _ropeParentVehicle;
    int _flags;
    bool _pilotLight;
    bool _collisionLight;
    int64_t _notemptysupply; // indicates if the Object was actually sent or not
    MessageUpdateSupply _supply;
    NetworkId _assembleTo;
    std::vector<NetworkId> _winches;
    std::string _assembleBaseFrom;
    bool _vehicleTransportingDisabled;
    NetworkId _parentVehicle;
    float _ropeLength;
    std::vector<NetworkId> _toObjs;
    std::vector<float> _toAttachOffsetX;
    std::vector<float> _toAttachOffsetY;
    std::vector<float> _toAttachOffsetZ;
    vec3 _ropeStartDownVector;
    vec3 _ropeEndDownVector;

    MessageUpdateRopeObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePositionRopeObject {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    vec3 _position;
    matrix3x3 _orientation;
    vec3 _speed;
    vec3 _angVelocity;
    int _posFlags;
    int _time;

    MessageUpdatePositionRopeObject() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForEnableRopeAttach {
    NetworkId _entity;
    bool _enable;

    MessageAskForEnableRopeAttach() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForSlingLoadingAction {
    NetworkId _heli;
    NetworkId _cargo;

    MessageAskForSlingLoadingAction() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForRopeCut {
    NetworkId _rope;
    float _length;

    MessageAskForRopeCut() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAnimationsVehicle {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    std::vector<float> _animations;
    std::vector<float> _animationsAnimSpeeds;

    MessageUpdateAnimationsVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateAnimationsMan {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    std::vector<float> _animations;
    std::vector<float> _animationsAnimSpeeds;
    float _headXRotWantedCont;
    float _headYRotWantedCont;
    float _headXRotWantedPan;
    float _headYRotWantedPan;
    float _leanZRotWanted;
    float _deployedDirAzimuth;
    float _deployedDirAltitude;

    MessageUpdateAnimationsMan() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePersonWeapons {
    bool _initialUpdate;
    int _currentWeapon;
    std::vector<MessageNetWeaponInfo*> _weapons;
    std::vector<MessageMagazine*> _magazines;
    int _loadedMagsHash;
    float _targetAimed;
    bool _laserTargetOn;
    NetworkId _laserTarget;
    NetworkId _backpack;
    MessageUpdateSlotMgr _slotMgr;

    MessageUpdatePersonWeapons() {};
    ~MessageUpdatePersonWeapons();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdatePersonGear {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    MessageUpdatePersonWeapons _weapons;

    MessageUpdatePersonGear() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskUpdatePersonWeapons {
    NetworkId _person;
    NetworkId _gunner;
    MessageUpdatePersonWeapons _weapons;

    MessageAskUpdatePersonWeapons() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTransportWeapons {
    bool _initialUpdate;
    int _currentWeapon;
    std::vector<MessageNetWeaponInfo*> _weapons;
    std::vector<MessageMagazine*> _magazines;
    int _loadedMagsHash;
    float _targetAimed;
    bool _laserTargetOn;
    NetworkId _laserTarget;
    std::vector<int> _magazineSlotsID;

    MessageUpdateTransportWeapons() {};
    ~MessageUpdateTransportWeapons();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTransportGear {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    MessageUpdateTransportWeapons _weapons;

    MessageUpdateTransportGear() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskUpdateTransportWeapons {
    NetworkId _transport;
    NetworkId _gunner;
    MessageUpdateTransportWeapons _weapons;

    MessageAskUpdateTransportWeapons() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTurretWeapons {
    bool _initialUpdate;
    int _currentWeapon;
    std::vector<MessageNetWeaponInfo*> _weapons;
    std::vector<MessageMagazine*> _magazines;
    int _loadedMagsHash;
    float _targetAimed;
    bool _laserTargetOn;
    NetworkId _laserTarget;
    std::vector<int> _magazineSlotsID;

    MessageUpdateTurretWeapons() {};
    ~MessageUpdateTurretWeapons();
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUpdateTurretGear {
    int _objectCreator;
    int _objectId;
    vec3 _objectPosition;
    bool _guaranteed;
    MessageUpdateTurretWeapons _weapons;

    MessageUpdateTurretGear() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskUpdateTurretWeapons {
    NetworkId _vehicle;
    NetworkId _turret;
    NetworkId _gunner;
    MessageUpdateTurretWeapons _weapons;

    MessageAskUpdateTurretWeapons() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageLoadVehicleInVehicle {
    NetworkId _transport;
    NetworkId _cargo;

    MessageLoadVehicleInVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageUnloadVehicleInVehicle {
    NetworkId _transport;
    NetworkId _cargo;

    MessageUnloadVehicleInVehicle() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageAskForEnableVehicleTransporting {
    NetworkId _transport;
    bool _enable;

    MessageAskForEnableVehicleTransporting() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

struct MessageTacticalPing {
    NetworkId _owner;
    vec3 _position;
    bool _enabled;
    std::vector<NetworkId> _units;
    int _type;

    MessageTacticalPing() {};
    void queue_message(int to);
    void reencode_message(NetworkMessageRaw* src);
};

static unsigned char* CreateMessageMsgFormatItem() {
    return (unsigned char*)new MessageMsgFormatItem();
}

static void CleanupMessageMsgFormatItem(unsigned char* buf) {
    auto msg = (MessageMsgFormatItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgFormat() {
    return (unsigned char*)new MessageMsgFormat();
}

static void CleanupMessageMsgFormat(unsigned char* buf) {
    auto msg = (MessageMsgFormat*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayer() {
    return (unsigned char*)new MessagePlayer();
}

static void CleanupMessagePlayer(unsigned char* buf) {
    auto msg = (MessagePlayer*)buf;
    delete msg;
}

static unsigned char* CreateMessageMessages() {
    return (unsigned char*)new MessageMessages();
}

static void CleanupMessageMessages(unsigned char* buf) {
    auto msg = (MessageMessages*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerState() {
    return (unsigned char*)new MessageServerState();
}

static void CleanupMessageServerState(unsigned char* buf) {
    auto msg = (MessageServerState*)buf;
    delete msg;
}

static unsigned char* CreateMessageClientState() {
    return (unsigned char*)new MessageClientState();
}

static void CleanupMessageClientState(unsigned char* buf) {
    auto msg = (MessageClientState*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerClientState() {
    return (unsigned char*)new MessagePlayerClientState();
}

static void CleanupMessagePlayerClientState(unsigned char* buf) {
    auto msg = (MessagePlayerClientState*)buf;
    delete msg;
}

static unsigned char* CreateMessageLogin() {
    return (unsigned char*)new MessageLogin();
}

static void CleanupMessageLogin(unsigned char* buf) {
    auto msg = (MessageLogin*)buf;
    delete msg;
}

static unsigned char* CreateMessageLogout() {
    return (unsigned char*)new MessageLogout();
}

static void CleanupMessageLogout(unsigned char* buf) {
    auto msg = (MessageLogout*)buf;
    delete msg;
}

static unsigned char* CreateMessageSquad() {
    return (unsigned char*)new MessageSquad();
}

static void CleanupMessageSquad(unsigned char* buf) {
    auto msg = (MessageSquad*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicVariable() {
    return (unsigned char*)new MessagePublicVariable();
}

static void CleanupMessagePublicVariable(unsigned char* buf) {
    auto msg = (MessagePublicVariable*)buf;
    delete msg;
}

static unsigned char* CreateMessageTeamMemberSetVariable() {
    return (unsigned char*)new MessageTeamMemberSetVariable();
}

static void CleanupMessageTeamMemberSetVariable(unsigned char* buf) {
    auto msg = (MessageTeamMemberSetVariable*)buf;
    delete msg;
}

static unsigned char* CreateMessageLogMsgOnServer() {
    return (unsigned char*)new MessageLogMsgOnServer();
}

static void CleanupMessageLogMsgOnServer(unsigned char* buf) {
    auto msg = (MessageLogMsgOnServer*)buf;
    delete msg;
}

static unsigned char* CreateMessageChat() {
    return (unsigned char*)new MessageChat();
}

static void CleanupMessageChat(unsigned char* buf) {
    auto msg = (MessageChat*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChat() {
    return (unsigned char*)new MessageRadioChat();
}

static void CleanupMessageRadioChat(unsigned char* buf) {
    auto msg = (MessageRadioChat*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChatWave() {
    return (unsigned char*)new MessageRadioChatWave();
}

static void CleanupMessageRadioChatWave(unsigned char* buf) {
    auto msg = (MessageRadioChatWave*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetSpeaker() {
    return (unsigned char*)new MessageSetSpeaker();
}

static void CleanupMessageSetSpeaker(unsigned char* buf) {
    auto msg = (MessageSetSpeaker*)buf;
    delete msg;
}

static unsigned char* CreateMessageMissionHeader() {
    return (unsigned char*)new MessageMissionHeader();
}

static void CleanupMessageMissionHeader(unsigned char* buf) {
    auto msg = (MessageMissionHeader*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerRole() {
    return (unsigned char*)new MessagePlayerRole();
}

static void CleanupMessagePlayerRole(unsigned char* buf) {
    auto msg = (MessagePlayerRole*)buf;
    delete msg;
}

static unsigned char* CreateMessageSelectPlayer() {
    return (unsigned char*)new MessageSelectPlayer();
}

static void CleanupMessageSelectPlayer(unsigned char* buf) {
    auto msg = (MessageSelectPlayer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAttachPerson() {
    return (unsigned char*)new MessageAttachPerson();
}

static void CleanupMessageAttachPerson(unsigned char* buf) {
    auto msg = (MessageAttachPerson*)buf;
    delete msg;
}

static unsigned char* CreateMessageTransferFile() {
    return (unsigned char*)new MessageTransferFile();
}

static void CleanupMessageTransferFile(unsigned char* buf) {
    auto msg = (MessageTransferFile*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskMissionFile() {
    return (unsigned char*)new MessageAskMissionFile();
}

static void CleanupMessageAskMissionFile(unsigned char* buf) {
    auto msg = (MessageAskMissionFile*)buf;
    delete msg;
}

static unsigned char* CreateMessageTransferMissionFile() {
    return (unsigned char*)new MessageTransferMissionFile();
}

static void CleanupMessageTransferMissionFile(unsigned char* buf) {
    auto msg = (MessageTransferMissionFile*)buf;
    delete msg;
}

static unsigned char* CreateMessageTransferFileToServer() {
    return (unsigned char*)new MessageTransferFileToServer();
}

static void CleanupMessageTransferFileToServer(unsigned char* buf) {
    auto msg = (MessageTransferFileToServer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDamage() {
    return (unsigned char*)new MessageAskForDamage();
}

static void CleanupMessageAskForDamage(unsigned char* buf) {
    auto msg = (MessageAskForDamage*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetDamage() {
    return (unsigned char*)new MessageAskForSetDamage();
}

static void CleanupMessageAskForSetDamage(unsigned char* buf) {
    auto msg = (MessageAskForSetDamage*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetSkill() {
    return (unsigned char*)new MessageAskForSetSkill();
}

static void CleanupMessageAskForSetSkill(unsigned char* buf) {
    auto msg = (MessageAskForSetSkill*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForGetIn() {
    return (unsigned char*)new MessageAskForGetIn();
}

static void CleanupMessageAskForGetIn(unsigned char* buf) {
    auto msg = (MessageAskForGetIn*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAssignAs() {
    return (unsigned char*)new MessageAskForAssignAs();
}

static void CleanupMessageAskForAssignAs(unsigned char* buf) {
    auto msg = (MessageAskForAssignAs*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForMoveOutTo() {
    return (unsigned char*)new MessageAskForMoveOutTo();
}

static void CleanupMessageAskForMoveOutTo(unsigned char* buf) {
    auto msg = (MessageAskForMoveOutTo*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForRemoveVehicleFromGroup() {
    return (unsigned char*)new MessageAskForRemoveVehicleFromGroup();
}

static void CleanupMessageAskForRemoveVehicleFromGroup(unsigned char* buf) {
    auto msg = (MessageAskForRemoveVehicleFromGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForGetOut() {
    return (unsigned char*)new MessageAskForGetOut();
}

static void CleanupMessageAskForGetOut(unsigned char* buf) {
    auto msg = (MessageAskForGetOut*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskWaitForGetOut() {
    return (unsigned char*)new MessageAskWaitForGetOut();
}

static void CleanupMessageAskWaitForGetOut(unsigned char* buf) {
    auto msg = (MessageAskWaitForGetOut*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForChangePosition() {
    return (unsigned char*)new MessageAskForChangePosition();
}

static void CleanupMessageAskForChangePosition(unsigned char* buf) {
    auto msg = (MessageAskForChangePosition*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSelectWeapon() {
    return (unsigned char*)new MessageAskForSelectWeapon();
}

static void CleanupMessageAskForSelectWeapon(unsigned char* buf) {
    auto msg = (MessageAskForSelectWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAmmo() {
    return (unsigned char*)new MessageAskForAmmo();
}

static void CleanupMessageAskForAmmo(unsigned char* buf) {
    auto msg = (MessageAskForAmmo*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAddImpulse() {
    return (unsigned char*)new MessageAskForAddImpulse();
}

static void CleanupMessageAskForAddImpulse(unsigned char* buf) {
    auto msg = (MessageAskForAddImpulse*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForMoveVector() {
    return (unsigned char*)new MessageAskForMoveVector();
}

static void CleanupMessageAskForMoveVector(unsigned char* buf) {
    auto msg = (MessageAskForMoveVector*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForMoveMatrix() {
    return (unsigned char*)new MessageAskForMoveMatrix();
}

static void CleanupMessageAskForMoveMatrix(unsigned char* buf) {
    auto msg = (MessageAskForMoveMatrix*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForJoinGroup() {
    return (unsigned char*)new MessageAskForJoinGroup();
}

static void CleanupMessageAskForJoinGroup(unsigned char* buf) {
    auto msg = (MessageAskForJoinGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForJoinUnits() {
    return (unsigned char*)new MessageAskForJoinUnits();
}

static void CleanupMessageAskForJoinUnits(unsigned char* buf) {
    auto msg = (MessageAskForJoinUnits*)buf;
    delete msg;
}

static unsigned char* CreateMessageExplosionDamageEffects() {
    return (unsigned char*)new MessageExplosionDamageEffects();
}

static void CleanupMessageExplosionDamageEffects(unsigned char* buf) {
    auto msg = (MessageExplosionDamageEffects*)buf;
    delete msg;
}

static unsigned char* CreateMessageFireWeapon() {
    return (unsigned char*)new MessageFireWeapon();
}

static void CleanupMessageFireWeapon(unsigned char* buf) {
    auto msg = (MessageFireWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateWeapons() {
    return (unsigned char*)new MessageUpdateWeapons();
}

static void CleanupMessageUpdateWeapons(unsigned char* buf) {
    auto msg = (MessageUpdateWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddWeapon() {
    return (unsigned char*)new MessageAddWeapon();
}

static void CleanupMessageAddWeapon(unsigned char* buf) {
    auto msg = (MessageAddWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveWeapon() {
    return (unsigned char*)new MessageRemoveWeapon();
}

static void CleanupMessageRemoveWeapon(unsigned char* buf) {
    auto msg = (MessageRemoveWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddWeaponCargo() {
    return (unsigned char*)new MessageAddWeaponCargo();
}

static void CleanupMessageAddWeaponCargo(unsigned char* buf) {
    auto msg = (MessageAddWeaponCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveWeaponCargo() {
    return (unsigned char*)new MessageRemoveWeaponCargo();
}

static void CleanupMessageRemoveWeaponCargo(unsigned char* buf) {
    auto msg = (MessageRemoveWeaponCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddItemCargo() {
    return (unsigned char*)new MessageAddItemCargo();
}

static void CleanupMessageAddItemCargo(unsigned char* buf) {
    auto msg = (MessageAddItemCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveItemCargo() {
    return (unsigned char*)new MessageRemoveItemCargo();
}

static void CleanupMessageRemoveItemCargo(unsigned char* buf) {
    auto msg = (MessageRemoveItemCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageModifyMagazineAmmoInCargo() {
    return (unsigned char*)new MessageModifyMagazineAmmoInCargo();
}

static void CleanupMessageModifyMagazineAmmoInCargo(unsigned char* buf) {
    auto msg = (MessageModifyMagazineAmmoInCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetUnitLoadOutFromClassName() {
    return (unsigned char*)new MessageSetUnitLoadOutFromClassName();
}

static void CleanupMessageSetUnitLoadOutFromClassName(unsigned char* buf) {
    auto msg = (MessageSetUnitLoadOutFromClassName*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetUnitLoadOutFromRawData() {
    return (unsigned char*)new MessageSetUnitLoadOutFromRawData();
}

static void CleanupMessageSetUnitLoadOutFromRawData(unsigned char* buf) {
    auto msg = (MessageSetUnitLoadOutFromRawData*)buf;
    delete msg;
}

static unsigned char* CreateMessageAssignItemToSlot() {
    return (unsigned char*)new MessageAssignItemToSlot();
}

static void CleanupMessageAssignItemToSlot(unsigned char* buf) {
    auto msg = (MessageAssignItemToSlot*)buf;
    delete msg;
}

static unsigned char* CreateMessageUnAssignItemFromSlot() {
    return (unsigned char*)new MessageUnAssignItemFromSlot();
}

static void CleanupMessageUnAssignItemFromSlot(unsigned char* buf) {
    auto msg = (MessageUnAssignItemFromSlot*)buf;
    delete msg;
}

static unsigned char* CreateMessageOfferItemFromBody() {
    return (unsigned char*)new MessageOfferItemFromBody();
}

static void CleanupMessageOfferItemFromBody(unsigned char* buf) {
    auto msg = (MessageOfferItemFromBody*)buf;
    delete msg;
}

static unsigned char* CreateMessageLinkNewContainer() {
    return (unsigned char*)new MessageLinkNewContainer();
}

static void CleanupMessageLinkNewContainer(unsigned char* buf) {
    auto msg = (MessageLinkNewContainer*)buf;
    delete msg;
}

static unsigned char* CreateMessageReplaceContainer() {
    return (unsigned char*)new MessageReplaceContainer();
}

static void CleanupMessageReplaceContainer(unsigned char* buf) {
    auto msg = (MessageReplaceContainer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddMagazineCargo() {
    return (unsigned char*)new MessageAddMagazineCargo();
}

static void CleanupMessageAddMagazineCargo(unsigned char* buf) {
    auto msg = (MessageAddMagazineCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddBackpackCargo() {
    return (unsigned char*)new MessageAddBackpackCargo();
}

static void CleanupMessageAddBackpackCargo(unsigned char* buf) {
    auto msg = (MessageAddBackpackCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveBackpackCargo() {
    return (unsigned char*)new MessageRemoveBackpackCargo();
}

static void CleanupMessageRemoveBackpackCargo(unsigned char* buf) {
    auto msg = (MessageRemoveBackpackCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveMagazineCargo() {
    return (unsigned char*)new MessageRemoveMagazineCargo();
}

static void CleanupMessageRemoveMagazineCargo(unsigned char* buf) {
    auto msg = (MessageRemoveMagazineCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddMagazine() {
    return (unsigned char*)new MessageAddMagazine();
}

static void CleanupMessageAddMagazine(unsigned char* buf) {
    auto msg = (MessageAddMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoveMagazine() {
    return (unsigned char*)new MessageRemoveMagazine();
}

static void CleanupMessageRemoveMagazine(unsigned char* buf) {
    auto msg = (MessageRemoveMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageVehicleInit() {
    return (unsigned char*)new MessageVehicleInit();
}

static void CleanupMessageVehicleInit(unsigned char* buf) {
    auto msg = (MessageVehicleInit*)buf;
    delete msg;
}

static unsigned char* CreateMessageVehicleDestroyed() {
    return (unsigned char*)new MessageVehicleDestroyed();
}

static void CleanupMessageVehicleDestroyed(unsigned char* buf) {
    auto msg = (MessageVehicleDestroyed*)buf;
    delete msg;
}

static unsigned char* CreateMessageStoreCreatedSite() {
    return (unsigned char*)new MessageStoreCreatedSite();
}

static void CleanupMessageStoreCreatedSite(unsigned char* buf) {
    auto msg = (MessageStoreCreatedSite*)buf;
    delete msg;
}

static unsigned char* CreateMessageDeleteCreatedSite() {
    return (unsigned char*)new MessageDeleteCreatedSite();
}

static void CleanupMessageDeleteCreatedSite(unsigned char* buf) {
    auto msg = (MessageDeleteCreatedSite*)buf;
    delete msg;
}

static unsigned char* CreateMessageRunInitSitesScript() {
    return (unsigned char*)new MessageRunInitSitesScript();
}

static void CleanupMessageRunInitSitesScript(unsigned char* buf) {
    auto msg = (MessageRunInitSitesScript*)buf;
    delete msg;
}

static unsigned char* CreateMessageMarkerCreate() {
    return (unsigned char*)new MessageMarkerCreate();
}

static void CleanupMessageMarkerCreate(unsigned char* buf) {
    auto msg = (MessageMarkerCreate*)buf;
    delete msg;
}

static unsigned char* CreateMessageMarkerDelete() {
    return (unsigned char*)new MessageMarkerDelete();
}

static void CleanupMessageMarkerDelete(unsigned char* buf) {
    auto msg = (MessageMarkerDelete*)buf;
    delete msg;
}

static unsigned char* CreateMessageMarkerUpdate() {
    return (unsigned char*)new MessageMarkerUpdate();
}

static void CleanupMessageMarkerUpdate(unsigned char* buf) {
    auto msg = (MessageMarkerUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetFlagOwner() {
    return (unsigned char*)new MessageSetFlagOwner();
}

static void CleanupMessageSetFlagOwner(unsigned char* buf) {
    auto msg = (MessageSetFlagOwner*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetFlagCarrier() {
    return (unsigned char*)new MessageSetFlagCarrier();
}

static void CleanupMessageSetFlagCarrier(unsigned char* buf) {
    auto msg = (MessageSetFlagCarrier*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVTarget() {
    return (unsigned char*)new MessageMsgVTarget();
}

static void CleanupMessageMsgVTarget(unsigned char* buf) {
    auto msg = (MessageMsgVTarget*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVFire() {
    return (unsigned char*)new MessageMsgVFire();
}

static void CleanupMessageMsgVFire(unsigned char* buf) {
    auto msg = (MessageMsgVFire*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVMove() {
    return (unsigned char*)new MessageMsgVMove();
}

static void CleanupMessageMsgVMove(unsigned char* buf) {
    auto msg = (MessageMsgVMove*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVFormation() {
    return (unsigned char*)new MessageMsgVFormation();
}

static void CleanupMessageMsgVFormation(unsigned char* buf) {
    auto msg = (MessageMsgVFormation*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVSimpleCommand() {
    return (unsigned char*)new MessageMsgVSimpleCommand();
}

static void CleanupMessageMsgVSimpleCommand(unsigned char* buf) {
    auto msg = (MessageMsgVSimpleCommand*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVLoad() {
    return (unsigned char*)new MessageMsgVLoad();
}

static void CleanupMessageMsgVLoad(unsigned char* buf) {
    auto msg = (MessageMsgVLoad*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVAzimut() {
    return (unsigned char*)new MessageMsgVAzimut();
}

static void CleanupMessageMsgVAzimut(unsigned char* buf) {
    auto msg = (MessageMsgVAzimut*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVStopTurning() {
    return (unsigned char*)new MessageMsgVStopTurning();
}

static void CleanupMessageMsgVStopTurning(unsigned char* buf) {
    auto msg = (MessageMsgVStopTurning*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVFireFailed() {
    return (unsigned char*)new MessageMsgVFireFailed();
}

static void CleanupMessageMsgVFireFailed(unsigned char* buf) {
    auto msg = (MessageMsgVFireFailed*)buf;
    delete msg;
}

static unsigned char* CreateMessageChangeOwner() {
    return (unsigned char*)new MessageChangeOwner();
}

static void CleanupMessageChangeOwner(unsigned char* buf) {
    auto msg = (MessageChangeOwner*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlaySound() {
    return (unsigned char*)new MessagePlaySound();
}

static void CleanupMessagePlaySound(unsigned char* buf) {
    auto msg = (MessagePlaySound*)buf;
    delete msg;
}

static unsigned char* CreateMessageDeleteObject() {
    return (unsigned char*)new MessageDeleteObject();
}

static void CleanupMessageDeleteObject(unsigned char* buf) {
    auto msg = (MessageDeleteObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageDeleteCommand() {
    return (unsigned char*)new MessageDeleteCommand();
}

static void CleanupMessageDeleteCommand(unsigned char* buf) {
    auto msg = (MessageDeleteCommand*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateObject() {
    return (unsigned char*)new MessageCreateObject();
}

static void CleanupMessageCreateObject(unsigned char* buf) {
    auto msg = (MessageCreateObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateObject() {
    return (unsigned char*)new MessageUpdateObject();
}

static void CleanupMessageUpdateObject(unsigned char* buf) {
    auto msg = (MessageUpdateObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateVehicle() {
    return (unsigned char*)new MessageCreateVehicle();
}

static void CleanupMessageCreateVehicle(unsigned char* buf) {
    auto msg = (MessageCreateVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateVehicle() {
    return (unsigned char*)new MessageUpdateVehicle();
}

static void CleanupMessageUpdateVehicle(unsigned char* buf) {
    auto msg = (MessageUpdateVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionVehicle() {
    return (unsigned char*)new MessageUpdatePositionVehicle();
}

static void CleanupMessageUpdatePositionVehicle(unsigned char* buf) {
    auto msg = (MessageUpdatePositionVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateDetector() {
    return (unsigned char*)new MessageCreateDetector();
}

static void CleanupMessageCreateDetector(unsigned char* buf) {
    auto msg = (MessageCreateDetector*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateDetector() {
    return (unsigned char*)new MessageUpdateDetector();
}

static void CleanupMessageUpdateDetector(unsigned char* buf) {
    auto msg = (MessageUpdateDetector*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateFlag() {
    return (unsigned char*)new MessageUpdateFlag();
}

static void CleanupMessageUpdateFlag(unsigned char* buf) {
    auto msg = (MessageUpdateFlag*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateShot() {
    return (unsigned char*)new MessageCreateShot();
}

static void CleanupMessageCreateShot(unsigned char* buf) {
    auto msg = (MessageCreateShot*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateShot() {
    return (unsigned char*)new MessageUpdateShot();
}

static void CleanupMessageUpdateShot(unsigned char* buf) {
    auto msg = (MessageUpdateShot*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateCrater() {
    return (unsigned char*)new MessageCreateCrater();
}

static void CleanupMessageCreateCrater(unsigned char* buf) {
    auto msg = (MessageCreateCrater*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateCraterOnVehicle() {
    return (unsigned char*)new MessageCreateCraterOnVehicle();
}

static void CleanupMessageCreateCraterOnVehicle(unsigned char* buf) {
    auto msg = (MessageCreateCraterOnVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateObjectDestructed() {
    return (unsigned char*)new MessageCreateObjectDestructed();
}

static void CleanupMessageCreateObjectDestructed(unsigned char* buf) {
    auto msg = (MessageCreateObjectDestructed*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAICenter() {
    return (unsigned char*)new MessageCreateAICenter();
}

static void CleanupMessageCreateAICenter(unsigned char* buf) {
    auto msg = (MessageCreateAICenter*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAICenter() {
    return (unsigned char*)new MessageUpdateAICenter();
}

static void CleanupMessageUpdateAICenter(unsigned char* buf) {
    auto msg = (MessageUpdateAICenter*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAIGroup() {
    return (unsigned char*)new MessageCreateAIGroup();
}

static void CleanupMessageCreateAIGroup(unsigned char* buf) {
    auto msg = (MessageCreateAIGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIGroup() {
    return (unsigned char*)new MessageUpdateAIGroup();
}

static void CleanupMessageUpdateAIGroup(unsigned char* buf) {
    auto msg = (MessageUpdateAIGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageUnitSlot() {
    return (unsigned char*)new MessageUnitSlot();
}

static void CleanupMessageUnitSlot(unsigned char* buf) {
    auto msg = (MessageUnitSlot*)buf;
    delete msg;
}

static unsigned char* CreateMessageWaypoint() {
    return (unsigned char*)new MessageWaypoint();
}

static void CleanupMessageWaypoint(unsigned char* buf) {
    auto msg = (MessageWaypoint*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAISubgroup() {
    return (unsigned char*)new MessageCreateAISubgroup();
}

static void CleanupMessageCreateAISubgroup(unsigned char* buf) {
    auto msg = (MessageCreateAISubgroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAISubgroup() {
    return (unsigned char*)new MessageUpdateAISubgroup();
}

static void CleanupMessageUpdateAISubgroup(unsigned char* buf) {
    auto msg = (MessageUpdateAISubgroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAIBrain() {
    return (unsigned char*)new MessageCreateAIBrain();
}

static void CleanupMessageCreateAIBrain(unsigned char* buf) {
    auto msg = (MessageCreateAIBrain*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIBrain() {
    return (unsigned char*)new MessageUpdateAIBrain();
}

static void CleanupMessageUpdateAIBrain(unsigned char* buf) {
    auto msg = (MessageUpdateAIBrain*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIBrainPath() {
    return (unsigned char*)new MessageUpdateAIBrainPath();
}

static void CleanupMessageUpdateAIBrainPath(unsigned char* buf) {
    auto msg = (MessageUpdateAIBrainPath*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAIUnit() {
    return (unsigned char*)new MessageCreateAIUnit();
}

static void CleanupMessageCreateAIUnit(unsigned char* buf) {
    auto msg = (MessageCreateAIUnit*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIUnit() {
    return (unsigned char*)new MessageUpdateAIUnit();
}

static void CleanupMessageUpdateAIUnit(unsigned char* buf) {
    auto msg = (MessageUpdateAIUnit*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIUnitPath() {
    return (unsigned char*)new MessageUpdateAIUnitPath();
}

static void CleanupMessageUpdateAIUnitPath(unsigned char* buf) {
    auto msg = (MessageUpdateAIUnitPath*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAIAgent() {
    return (unsigned char*)new MessageCreateAIAgent();
}

static void CleanupMessageCreateAIAgent(unsigned char* buf) {
    auto msg = (MessageCreateAIAgent*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIAgent() {
    return (unsigned char*)new MessageUpdateAIAgent();
}

static void CleanupMessageUpdateAIAgent(unsigned char* buf) {
    auto msg = (MessageUpdateAIAgent*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAIAgentPath() {
    return (unsigned char*)new MessageUpdateAIAgentPath();
}

static void CleanupMessageUpdateAIAgentPath(unsigned char* buf) {
    auto msg = (MessageUpdateAIAgentPath*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateCommand() {
    return (unsigned char*)new MessageCreateCommand();
}

static void CleanupMessageCreateCommand(unsigned char* buf) {
    auto msg = (MessageCreateCommand*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateCommand() {
    return (unsigned char*)new MessageUpdateCommand();
}

static void CleanupMessageUpdateCommand(unsigned char* buf) {
    auto msg = (MessageUpdateCommand*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateVehicleAI() {
    return (unsigned char*)new MessageUpdateVehicleAI();
}

static void CleanupMessageUpdateVehicleAI(unsigned char* buf) {
    auto msg = (MessageUpdateVehicleAI*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateVehicleAIFull() {
    return (unsigned char*)new MessageUpdateVehicleAIFull();
}

static void CleanupMessageUpdateVehicleAIFull(unsigned char* buf) {
    auto msg = (MessageUpdateVehicleAIFull*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateVehicleBrain() {
    return (unsigned char*)new MessageUpdateVehicleBrain();
}

static void CleanupMessageUpdateVehicleBrain(unsigned char* buf) {
    auto msg = (MessageUpdateVehicleBrain*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTransport() {
    return (unsigned char*)new MessageUpdateTransport();
}

static void CleanupMessageUpdateTransport(unsigned char* buf) {
    auto msg = (MessageUpdateTransport*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAnimal() {
    return (unsigned char*)new MessageUpdateAnimal();
}

static void CleanupMessageUpdateAnimal(unsigned char* buf) {
    auto msg = (MessageUpdateAnimal*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionAnimal() {
    return (unsigned char*)new MessageUpdatePositionAnimal();
}

static void CleanupMessageUpdatePositionAnimal(unsigned char* buf) {
    auto msg = (MessageUpdatePositionAnimal*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateMan() {
    return (unsigned char*)new MessageUpdateMan();
}

static void CleanupMessageUpdateMan(unsigned char* buf) {
    auto msg = (MessageUpdateMan*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionMan() {
    return (unsigned char*)new MessageUpdatePositionMan();
}

static void CleanupMessageUpdatePositionMan(unsigned char* buf) {
    auto msg = (MessageUpdatePositionMan*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTankOrCar() {
    return (unsigned char*)new MessageUpdateTankOrCar();
}

static void CleanupMessageUpdateTankOrCar(unsigned char* buf) {
    auto msg = (MessageUpdateTankOrCar*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTank() {
    return (unsigned char*)new MessageUpdateTank();
}

static void CleanupMessageUpdateTank(unsigned char* buf) {
    auto msg = (MessageUpdateTank*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionTank() {
    return (unsigned char*)new MessageUpdatePositionTank();
}

static void CleanupMessageUpdatePositionTank(unsigned char* buf) {
    auto msg = (MessageUpdatePositionTank*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTurret() {
    return (unsigned char*)new MessageUpdateTurret();
}

static void CleanupMessageUpdateTurret(unsigned char* buf) {
    auto msg = (MessageUpdateTurret*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateCar() {
    return (unsigned char*)new MessageUpdateCar();
}

static void CleanupMessageUpdateCar(unsigned char* buf) {
    auto msg = (MessageUpdateCar*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionCar() {
    return (unsigned char*)new MessageUpdatePositionCar();
}

static void CleanupMessageUpdatePositionCar(unsigned char* buf) {
    auto msg = (MessageUpdatePositionCar*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAirplane() {
    return (unsigned char*)new MessageUpdateAirplane();
}

static void CleanupMessageUpdateAirplane(unsigned char* buf) {
    auto msg = (MessageUpdateAirplane*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionAirplane() {
    return (unsigned char*)new MessageUpdatePositionAirplane();
}

static void CleanupMessageUpdatePositionAirplane(unsigned char* buf) {
    auto msg = (MessageUpdatePositionAirplane*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateHelicopter() {
    return (unsigned char*)new MessageUpdateHelicopter();
}

static void CleanupMessageUpdateHelicopter(unsigned char* buf) {
    auto msg = (MessageUpdateHelicopter*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionHelicopter() {
    return (unsigned char*)new MessageUpdatePositionHelicopter();
}

static void CleanupMessageUpdatePositionHelicopter(unsigned char* buf) {
    auto msg = (MessageUpdatePositionHelicopter*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateParachute() {
    return (unsigned char*)new MessageUpdateParachute();
}

static void CleanupMessageUpdateParachute(unsigned char* buf) {
    auto msg = (MessageUpdateParachute*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateParaglide() {
    return (unsigned char*)new MessageUpdateParaglide();
}

static void CleanupMessageUpdateParaglide(unsigned char* buf) {
    auto msg = (MessageUpdateParaglide*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateShip() {
    return (unsigned char*)new MessageUpdateShip();
}

static void CleanupMessageUpdateShip(unsigned char* buf) {
    auto msg = (MessageUpdateShip*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionShip() {
    return (unsigned char*)new MessageUpdatePositionShip();
}

static void CleanupMessageUpdatePositionShip(unsigned char* buf) {
    auto msg = (MessageUpdatePositionShip*)buf;
    delete msg;
}

static unsigned char* CreateMessageMagazine() {
    return (unsigned char*)new MessageMagazine();
}

static void CleanupMessageMagazine(unsigned char* buf) {
    auto msg = (MessageMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageNetWeaponInfo() {
    return (unsigned char*)new MessageNetWeaponInfo();
}

static void CleanupMessageNetWeaponInfo(unsigned char* buf) {
    auto msg = (MessageNetWeaponInfo*)buf;
    delete msg;
}

static unsigned char* CreateMessageNetMuzzleInfo() {
    return (unsigned char*)new MessageNetMuzzleInfo();
}

static void CleanupMessageNetMuzzleInfo(unsigned char* buf) {
    auto msg = (MessageNetMuzzleInfo*)buf;
    delete msg;
}

static unsigned char* CreateMessageContainerRawData() {
    return (unsigned char*)new MessageContainerRawData();
}

static void CleanupMessageContainerRawData(unsigned char* buf) {
    auto msg = (MessageContainerRawData*)buf;
    delete msg;
}

static unsigned char* CreateMessageMagazineString() {
    return (unsigned char*)new MessageMagazineString();
}

static void CleanupMessageMagazineString(unsigned char* buf) {
    auto msg = (MessageMagazineString*)buf;
    delete msg;
}

static unsigned char* CreateMessageCountedString() {
    return (unsigned char*)new MessageCountedString();
}

static void CleanupMessageCountedString(unsigned char* buf) {
    auto msg = (MessageCountedString*)buf;
    delete msg;
}

static unsigned char* CreateMessageCountedWeaponsString() {
    return (unsigned char*)new MessageCountedWeaponsString();
}

static void CleanupMessageCountedWeaponsString(unsigned char* buf) {
    auto msg = (MessageCountedWeaponsString*)buf;
    delete msg;
}

static unsigned char* CreateMessagePersonInventoryDescriptor() {
    return (unsigned char*)new MessagePersonInventoryDescriptor();
}

static void CleanupMessagePersonInventoryDescriptor(unsigned char* buf) {
    auto msg = (MessagePersonInventoryDescriptor*)buf;
    delete msg;
}

static unsigned char* CreateMessagePathPoint() {
    return (unsigned char*)new MessagePathPoint();
}

static void CleanupMessagePathPoint(unsigned char* buf) {
    auto msg = (MessagePathPoint*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateMotorcycle() {
    return (unsigned char*)new MessageUpdateMotorcycle();
}

static void CleanupMessageUpdateMotorcycle(unsigned char* buf) {
    auto msg = (MessageUpdateMotorcycle*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionMotorcycle() {
    return (unsigned char*)new MessageUpdatePositionMotorcycle();
}

static void CleanupMessageUpdatePositionMotorcycle(unsigned char* buf) {
    auto msg = (MessageUpdatePositionMotorcycle*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForHideBody() {
    return (unsigned char*)new MessageAskForHideBody();
}

static void CleanupMessageAskForHideBody(unsigned char* buf) {
    auto msg = (MessageAskForHideBody*)buf;
    delete msg;
}

static unsigned char* CreateMessageNetworkCommand() {
    return (unsigned char*)new MessageNetworkCommand();
}

static void CleanupMessageNetworkCommand(unsigned char* buf) {
    auto msg = (MessageNetworkCommand*)buf;
    delete msg;
}

static unsigned char* CreateMessageIntegrityQuestion() {
    return (unsigned char*)new MessageIntegrityQuestion();
}

static void CleanupMessageIntegrityQuestion(unsigned char* buf) {
    auto msg = (MessageIntegrityQuestion*)buf;
    delete msg;
}

static unsigned char* CreateMessageIntegrityAnswer() {
    return (unsigned char*)new MessageIntegrityAnswer();
}

static void CleanupMessageIntegrityAnswer(unsigned char* buf) {
    auto msg = (MessageIntegrityAnswer*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateSeagull() {
    return (unsigned char*)new MessageUpdateSeagull();
}

static void CleanupMessageUpdateSeagull(unsigned char* buf) {
    auto msg = (MessageUpdateSeagull*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionSeagull() {
    return (unsigned char*)new MessageUpdatePositionSeagull();
}

static void CleanupMessageUpdatePositionSeagull(unsigned char* buf) {
    auto msg = (MessageUpdatePositionSeagull*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerUpdate() {
    return (unsigned char*)new MessagePlayerUpdate();
}

static void CleanupMessagePlayerUpdate(unsigned char* buf) {
    auto msg = (MessagePlayerUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateDamageVehicleAI() {
    return (unsigned char*)new MessageUpdateDamageVehicleAI();
}

static void CleanupMessageUpdateDamageVehicleAI(unsigned char* buf) {
    auto msg = (MessageUpdateDamageVehicleAI*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateDamageObject() {
    return (unsigned char*)new MessageUpdateDamageObject();
}

static void CleanupMessageUpdateDamageObject(unsigned char* buf) {
    auto msg = (MessageUpdateDamageObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateHelicopter() {
    return (unsigned char*)new MessageCreateHelicopter();
}

static void CleanupMessageCreateHelicopter(unsigned char* buf) {
    auto msg = (MessageCreateHelicopter*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateClientInfo() {
    return (unsigned char*)new MessageUpdateClientInfo();
}

static void CleanupMessageUpdateClientInfo(unsigned char* buf) {
    auto msg = (MessageUpdateClientInfo*)buf;
    delete msg;
}

static unsigned char* CreateMessageShowTarget() {
    return (unsigned char*)new MessageShowTarget();
}

static void CleanupMessageShowTarget(unsigned char* buf) {
    auto msg = (MessageShowTarget*)buf;
    delete msg;
}

static unsigned char* CreateMessageShowSuppressTarget() {
    return (unsigned char*)new MessageShowSuppressTarget();
}

static void CleanupMessageShowSuppressTarget(unsigned char* buf) {
    auto msg = (MessageShowSuppressTarget*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSynchronization() {
    return (unsigned char*)new MessageGroupSynchronization();
}

static void CleanupMessageGroupSynchronization(unsigned char* buf) {
    auto msg = (MessageGroupSynchronization*)buf;
    delete msg;
}

static unsigned char* CreateMessageDetectorActivation() {
    return (unsigned char*)new MessageDetectorActivation();
}

static void CleanupMessageDetectorActivation(unsigned char* buf) {
    auto msg = (MessageDetectorActivation*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForCreateUnit() {
    return (unsigned char*)new MessageAskForCreateUnit();
}

static void CleanupMessageAskForCreateUnit(unsigned char* buf) {
    auto msg = (MessageAskForCreateUnit*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDeleteVehicle() {
    return (unsigned char*)new MessageAskForDeleteVehicle();
}

static void CleanupMessageAskForDeleteVehicle(unsigned char* buf) {
    auto msg = (MessageAskForDeleteVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForReceiveUnitAnswer() {
    return (unsigned char*)new MessageAskForReceiveUnitAnswer();
}

static void CleanupMessageAskForReceiveUnitAnswer(unsigned char* buf) {
    auto msg = (MessageAskForReceiveUnitAnswer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForGroupRespawn() {
    return (unsigned char*)new MessageAskForGroupRespawn();
}

static void CleanupMessageAskForGroupRespawn(unsigned char* buf) {
    auto msg = (MessageAskForGroupRespawn*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupRespawnDone() {
    return (unsigned char*)new MessageGroupRespawnDone();
}

static void CleanupMessageGroupRespawnDone(unsigned char* buf) {
    auto msg = (MessageGroupRespawnDone*)buf;
    delete msg;
}

static unsigned char* CreateMessageMissionParams() {
    return (unsigned char*)new MessageMissionParams();
}

static void CleanupMessageMissionParams(unsigned char* buf) {
    auto msg = (MessageMissionParams*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateMine() {
    return (unsigned char*)new MessageUpdateMine();
}

static void CleanupMessageUpdateMine(unsigned char* buf) {
    auto msg = (MessageUpdateMine*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForActivateMine() {
    return (unsigned char*)new MessageAskForActivateMine();
}

static void CleanupMessageAskForActivateMine(unsigned char* buf) {
    auto msg = (MessageAskForActivateMine*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDetectedMine() {
    return (unsigned char*)new MessageAskForDetectedMine();
}

static void CleanupMessageAskForDetectedMine(unsigned char* buf) {
    auto msg = (MessageAskForDetectedMine*)buf;
    delete msg;
}

static unsigned char* CreateMessageDisposeObject() {
    return (unsigned char*)new MessageDisposeObject();
}

static void CleanupMessageDisposeObject(unsigned char* buf) {
    auto msg = (MessageDisposeObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageVehicleDamaged() {
    return (unsigned char*)new MessageVehicleDamaged();
}

static void CleanupMessageVehicleDamaged(unsigned char* buf) {
    auto msg = (MessageVehicleDamaged*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateFireplace() {
    return (unsigned char*)new MessageUpdateFireplace();
}

static void CleanupMessageUpdateFireplace(unsigned char* buf) {
    auto msg = (MessageUpdateFireplace*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForInflameFire() {
    return (unsigned char*)new MessageAskForInflameFire();
}

static void CleanupMessageAskForInflameFire(unsigned char* buf) {
    auto msg = (MessageAskForInflameFire*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAnimationPhase() {
    return (unsigned char*)new MessageAskForAnimationPhase();
}

static void CleanupMessageAskForAnimationPhase(unsigned char* buf) {
    auto msg = (MessageAskForAnimationPhase*)buf;
    delete msg;
}

static unsigned char* CreateMessageIncomingMissile() {
    return (unsigned char*)new MessageIncomingMissile();
}

static void CleanupMessageIncomingMissile(unsigned char* buf) {
    auto msg = (MessageIncomingMissile*)buf;
    delete msg;
}

static unsigned char* CreateMessageLaunchedCounterMeasures() {
    return (unsigned char*)new MessageLaunchedCounterMeasures();
}

static void CleanupMessageLaunchedCounterMeasures(unsigned char* buf) {
    auto msg = (MessageLaunchedCounterMeasures*)buf;
    delete msg;
}

static unsigned char* CreateMessageSharedMineUsed() {
    return (unsigned char*)new MessageSharedMineUsed();
}

static void CleanupMessageSharedMineUsed(unsigned char* buf) {
    auto msg = (MessageSharedMineUsed*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetShotParents() {
    return (unsigned char*)new MessageSetShotParents();
}

static void CleanupMessageSetShotParents(unsigned char* buf) {
    auto msg = (MessageSetShotParents*)buf;
    delete msg;
}

static unsigned char* CreateMessageWeaponLocked() {
    return (unsigned char*)new MessageWeaponLocked();
}

static void CleanupMessageWeaponLocked(unsigned char* buf) {
    auto msg = (MessageWeaponLocked*)buf;
    delete msg;
}

static unsigned char* CreateMessageForceDeleteObject() {
    return (unsigned char*)new MessageForceDeleteObject();
}

static void CleanupMessageForceDeleteObject(unsigned char* buf) {
    auto msg = (MessageForceDeleteObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageJoinIntoUnit() {
    return (unsigned char*)new MessageJoinIntoUnit();
}

static void CleanupMessageJoinIntoUnit(unsigned char* buf) {
    auto msg = (MessageJoinIntoUnit*)buf;
    delete msg;
}

static unsigned char* CreateMessageAIStatsMPRowCreate() {
    return (unsigned char*)new MessageAIStatsMPRowCreate();
}

static void CleanupMessageAIStatsMPRowCreate(unsigned char* buf) {
    auto msg = (MessageAIStatsMPRowCreate*)buf;
    delete msg;
}

static unsigned char* CreateMessageAIStatsMPRowUpdate() {
    return (unsigned char*)new MessageAIStatsMPRowUpdate();
}

static void CleanupMessageAIStatsMPRowUpdate(unsigned char* buf) {
    auto msg = (MessageAIStatsMPRowUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateSupply() {
    return (unsigned char*)new MessageUpdateSupply();
}

static void CleanupMessageUpdateSupply(unsigned char* buf) {
    auto msg = (MessageUpdateSupply*)buf;
    delete msg;
}

static unsigned char* CreateMessageWeatherCreate() {
    return (unsigned char*)new MessageWeatherCreate();
}

static void CleanupMessageWeatherCreate(unsigned char* buf) {
    auto msg = (MessageWeatherCreate*)buf;
    delete msg;
}

static unsigned char* CreateMessageWeatherUpdate() {
    return (unsigned char*)new MessageWeatherUpdate();
}

static void CleanupMessageWeatherUpdate(unsigned char* buf) {
    auto msg = (MessageWeatherUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageMuteList() {
    return (unsigned char*)new MessageMuteList();
}

static void CleanupMessageMuteList(unsigned char* buf) {
    auto msg = (MessageMuteList*)buf;
    delete msg;
}

static unsigned char* CreateMessageVoiceOn() {
    return (unsigned char*)new MessageVoiceOn();
}

static void CleanupMessageVoiceOn(unsigned char* buf) {
    auto msg = (MessageVoiceOn*)buf;
    delete msg;
}

static unsigned char* CreateMessageCleanupPlayer() {
    return (unsigned char*)new MessageCleanupPlayer();
}

static void CleanupMessageCleanupPlayer(unsigned char* buf) {
    auto msg = (MessageCleanupPlayer*)buf;
    delete msg;
}

static unsigned char* CreateMessageLockGearItem() {
    return (unsigned char*)new MessageLockGearItem();
}

static void CleanupMessageLockGearItem(unsigned char* buf) {
    auto msg = (MessageLockGearItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageUnlockGearItem() {
    return (unsigned char*)new MessageUnlockGearItem();
}

static void CleanupMessageUnlockGearItem(unsigned char* buf) {
    auto msg = (MessageUnlockGearItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskItem() {
    return (unsigned char*)new MessageAskItem();
}

static void CleanupMessageAskItem(unsigned char* buf) {
    auto msg = (MessageAskItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskWeapon() {
    return (unsigned char*)new MessageAskWeapon();
}

static void CleanupMessageAskWeapon(unsigned char* buf) {
    auto msg = (MessageAskWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskMagazine() {
    return (unsigned char*)new MessageAskMagazine();
}

static void CleanupMessageAskMagazine(unsigned char* buf) {
    auto msg = (MessageAskMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskBackpack() {
    return (unsigned char*)new MessageAskBackpack();
}

static void CleanupMessageAskBackpack(unsigned char* buf) {
    auto msg = (MessageAskBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageReplaceItem() {
    return (unsigned char*)new MessageReplaceItem();
}

static void CleanupMessageReplaceItem(unsigned char* buf) {
    auto msg = (MessageReplaceItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageStorePendingItem() {
    return (unsigned char*)new MessageStorePendingItem();
}

static void CleanupMessageStorePendingItem(unsigned char* buf) {
    auto msg = (MessageStorePendingItem*)buf;
    delete msg;
}

static unsigned char* CreateMessageReplaceWeapon() {
    return (unsigned char*)new MessageReplaceWeapon();
}

static void CleanupMessageReplaceWeapon(unsigned char* buf) {
    auto msg = (MessageReplaceWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageReplaceMagazine() {
    return (unsigned char*)new MessageReplaceMagazine();
}

static void CleanupMessageReplaceMagazine(unsigned char* buf) {
    auto msg = (MessageReplaceMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageReplaceBackpack() {
    return (unsigned char*)new MessageReplaceBackpack();
}

static void CleanupMessageReplaceBackpack(unsigned char* buf) {
    auto msg = (MessageReplaceBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageReturnWeapon() {
    return (unsigned char*)new MessageReturnWeapon();
}

static void CleanupMessageReturnWeapon(unsigned char* buf) {
    auto msg = (MessageReturnWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageReturnMagazine() {
    return (unsigned char*)new MessageReturnMagazine();
}

static void CleanupMessageReturnMagazine(unsigned char* buf) {
    auto msg = (MessageReturnMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageReturnBackpack() {
    return (unsigned char*)new MessageReturnBackpack();
}

static void CleanupMessageReturnBackpack(unsigned char* buf) {
    auto msg = (MessageReturnBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageCancelTakeFlag() {
    return (unsigned char*)new MessageCancelTakeFlag();
}

static void CleanupMessageCancelTakeFlag(unsigned char* buf) {
    auto msg = (MessageCancelTakeFlag*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolAskWeapon() {
    return (unsigned char*)new MessagePoolAskWeapon();
}

static void CleanupMessagePoolAskWeapon(unsigned char* buf) {
    auto msg = (MessagePoolAskWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolAskMagazine() {
    return (unsigned char*)new MessagePoolAskMagazine();
}

static void CleanupMessagePoolAskMagazine(unsigned char* buf) {
    auto msg = (MessagePoolAskMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolAskBackpack() {
    return (unsigned char*)new MessagePoolAskBackpack();
}

static void CleanupMessagePoolAskBackpack(unsigned char* buf) {
    auto msg = (MessagePoolAskBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReplaceWeapon() {
    return (unsigned char*)new MessagePoolReplaceWeapon();
}

static void CleanupMessagePoolReplaceWeapon(unsigned char* buf) {
    auto msg = (MessagePoolReplaceWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReplaceMagazine() {
    return (unsigned char*)new MessagePoolReplaceMagazine();
}

static void CleanupMessagePoolReplaceMagazine(unsigned char* buf) {
    auto msg = (MessagePoolReplaceMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReplaceBackpack() {
    return (unsigned char*)new MessagePoolReplaceBackpack();
}

static void CleanupMessagePoolReplaceBackpack(unsigned char* buf) {
    auto msg = (MessagePoolReplaceBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReturnWeapon() {
    return (unsigned char*)new MessagePoolReturnWeapon();
}

static void CleanupMessagePoolReturnWeapon(unsigned char* buf) {
    auto msg = (MessagePoolReturnWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReturnMagazine() {
    return (unsigned char*)new MessagePoolReturnMagazine();
}

static void CleanupMessagePoolReturnMagazine(unsigned char* buf) {
    auto msg = (MessagePoolReturnMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessagePoolReturnBackpack() {
    return (unsigned char*)new MessagePoolReturnBackpack();
}

static void CleanupMessagePoolReturnBackpack(unsigned char* buf) {
    auto msg = (MessagePoolReturnBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskSetUnitLoadOutFromClassName() {
    return (unsigned char*)new MessageAskSetUnitLoadOutFromClassName();
}

static void CleanupMessageAskSetUnitLoadOutFromClassName(unsigned char* buf) {
    auto msg = (MessageAskSetUnitLoadOutFromClassName*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskSetUnitLoadOutFromRawData() {
    return (unsigned char*)new MessageAskSetUnitLoadOutFromRawData();
}

static void CleanupMessageAskSetUnitLoadOutFromRawData(unsigned char* buf) {
    auto msg = (MessageAskSetUnitLoadOutFromRawData*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateWeaponsInfo() {
    return (unsigned char*)new MessageUpdateWeaponsInfo();
}

static void CleanupMessageUpdateWeaponsInfo(unsigned char* buf) {
    auto msg = (MessageUpdateWeaponsInfo*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateWeaponSlotsData() {
    return (unsigned char*)new MessageUpdateWeaponSlotsData();
}

static void CleanupMessageUpdateWeaponSlotsData(unsigned char* buf) {
    auto msg = (MessageUpdateWeaponSlotsData*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateWeaponsPool() {
    return (unsigned char*)new MessageUpdateWeaponsPool();
}

static void CleanupMessageUpdateWeaponsPool(unsigned char* buf) {
    auto msg = (MessageUpdateWeaponsPool*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateMagazinesPool() {
    return (unsigned char*)new MessageUpdateMagazinesPool();
}

static void CleanupMessageUpdateMagazinesPool(unsigned char* buf) {
    auto msg = (MessageUpdateMagazinesPool*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateBackpacksPool() {
    return (unsigned char*)new MessageUpdateBackpacksPool();
}

static void CleanupMessageUpdateBackpacksPool(unsigned char* buf) {
    auto msg = (MessageUpdateBackpacksPool*)buf;
    delete msg;
}

static unsigned char* CreateMessageMarker() {
    return (unsigned char*)new MessageMarker();
}

static void CleanupMessageMarker(unsigned char* buf) {
    auto msg = (MessageMarker*)buf;
    delete msg;
}

static unsigned char* CreateMessageSite() {
    return (unsigned char*)new MessageSite();
}

static void CleanupMessageSite(unsigned char* buf) {
    auto msg = (MessageSite*)buf;
    delete msg;
}

static unsigned char* CreateMessageEffects() {
    return (unsigned char*)new MessageEffects();
}

static void CleanupMessageEffects(unsigned char* buf) {
    auto msg = (MessageEffects*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateSlotMgr() {
    return (unsigned char*)new MessageUpdateSlotMgr();
}

static void CleanupMessageUpdateSlotMgr(unsigned char* buf) {
    auto msg = (MessageUpdateSlotMgr*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateEntityAIWeapons() {
    return (unsigned char*)new MessageUpdateEntityAIWeapons();
}

static void CleanupMessageUpdateEntityAIWeapons(unsigned char* buf) {
    auto msg = (MessageUpdateEntityAIWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetRoleIndex() {
    return (unsigned char*)new MessageSetRoleIndex();
}

static void CleanupMessageSetRoleIndex(unsigned char* buf) {
    auto msg = (MessageSetRoleIndex*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateSeagull() {
    return (unsigned char*)new MessageCreateSeagull();
}

static void CleanupMessageCreateSeagull(unsigned char* buf) {
    auto msg = (MessageCreateSeagull*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVLoadMagazine() {
    return (unsigned char*)new MessageMsgVLoadMagazine();
}

static void CleanupMessageMsgVLoadMagazine(unsigned char* buf) {
    auto msg = (MessageMsgVLoadMagazine*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVWatchTgt() {
    return (unsigned char*)new MessageMsgVWatchTgt();
}

static void CleanupMessageMsgVWatchTgt(unsigned char* buf) {
    auto msg = (MessageMsgVWatchTgt*)buf;
    delete msg;
}

static unsigned char* CreateMessageMsgVWatchPos() {
    return (unsigned char*)new MessageMsgVWatchPos();
}

static void CleanupMessageMsgVWatchPos(unsigned char* buf) {
    auto msg = (MessageMsgVWatchPos*)buf;
    delete msg;
}

static unsigned char* CreateMessageRevealTarget() {
    return (unsigned char*)new MessageRevealTarget();
}

static void CleanupMessageRevealTarget(unsigned char* buf) {
    auto msg = (MessageRevealTarget*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateDynSoundSource() {
    return (unsigned char*)new MessageCreateDynSoundSource();
}

static void CleanupMessageCreateDynSoundSource(unsigned char* buf) {
    auto msg = (MessageCreateDynSoundSource*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateDestructionEffects() {
    return (unsigned char*)new MessageCreateDestructionEffects();
}

static void CleanupMessageCreateDestructionEffects(unsigned char* buf) {
    auto msg = (MessageCreateDestructionEffects*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteMuteList() {
    return (unsigned char*)new MessageRemoteMuteList();
}

static void CleanupMessageRemoteMuteList(unsigned char* buf) {
    auto msg = (MessageRemoteMuteList*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForApplyDoDamage() {
    return (unsigned char*)new MessageAskForApplyDoDamage();
}

static void CleanupMessageAskForApplyDoDamage(unsigned char* buf) {
    auto msg = (MessageAskForApplyDoDamage*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForApplyBleeding() {
    return (unsigned char*)new MessageAskForApplyBleeding();
}

static void CleanupMessageAskForApplyBleeding(unsigned char* buf) {
    auto msg = (MessageAskForApplyBleeding*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForStatsWrite() {
    return (unsigned char*)new MessageAskForStatsWrite();
}

static void CleanupMessageAskForStatsWrite(unsigned char* buf) {
    auto msg = (MessageAskForStatsWrite*)buf;
    delete msg;
}

static unsigned char* CreateMessageLocalizedChat() {
    return (unsigned char*)new MessageLocalizedChat();
}

static void CleanupMessageLocalizedChat(unsigned char* buf) {
    auto msg = (MessageLocalizedChat*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateTurret() {
    return (unsigned char*)new MessageCreateTurret();
}

static void CleanupMessageCreateTurret(unsigned char* buf) {
    auto msg = (MessageCreateTurret*)buf;
    delete msg;
}

static unsigned char* CreateMessageVoteMission() {
    return (unsigned char*)new MessageVoteMission();
}

static void CleanupMessageVoteMission(unsigned char* buf) {
    auto msg = (MessageVoteMission*)buf;
    delete msg;
}

static unsigned char* CreateMessageVotingMissionProgress() {
    return (unsigned char*)new MessageVotingMissionProgress();
}

static void CleanupMessageVotingMissionProgress(unsigned char* buf) {
    auto msg = (MessageVotingMissionProgress*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerBan() {
    return (unsigned char*)new MessagePlayerBan();
}

static void CleanupMessagePlayerBan(unsigned char* buf) {
    auto msg = (MessagePlayerBan*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerBanSelf() {
    return (unsigned char*)new MessagePlayerBanSelf();
}

static void CleanupMessagePlayerBanSelf(unsigned char* buf) {
    auto msg = (MessagePlayerBanSelf*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerTimeout() {
    return (unsigned char*)new MessageServerTimeout();
}

static void CleanupMessageServerTimeout(unsigned char* buf) {
    auto msg = (MessageServerTimeout*)buf;
    delete msg;
}

static unsigned char* CreateMessageAcceptedKey() {
    return (unsigned char*)new MessageAcceptedKey();
}

static void CleanupMessageAcceptedKey(unsigned char* buf) {
    auto msg = (MessageAcceptedKey*)buf;
    delete msg;
}

static unsigned char* CreateMessageAdditionalSignedFiles() {
    return (unsigned char*)new MessageAdditionalSignedFiles();
}

static void CleanupMessageAdditionalSignedFiles(unsigned char* buf) {
    auto msg = (MessageAdditionalSignedFiles*)buf;
    delete msg;
}

static unsigned char* CreateMessageDataSignatureAsk() {
    return (unsigned char*)new MessageDataSignatureAsk();
}

static void CleanupMessageDataSignatureAsk(unsigned char* buf) {
    auto msg = (MessageDataSignatureAsk*)buf;
    delete msg;
}

static unsigned char* CreateMessageDataSignatureAnswer() {
    return (unsigned char*)new MessageDataSignatureAnswer();
}

static void CleanupMessageDataSignatureAnswer(unsigned char* buf) {
    auto msg = (MessageDataSignatureAnswer*)buf;
    delete msg;
}

static unsigned char* CreateMessageHackedData() {
    return (unsigned char*)new MessageHackedData();
}

static void CleanupMessageHackedData(unsigned char* buf) {
    auto msg = (MessageHackedData*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateAITeam() {
    return (unsigned char*)new MessageCreateAITeam();
}

static void CleanupMessageCreateAITeam(unsigned char* buf) {
    auto msg = (MessageCreateAITeam*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAITeam() {
    return (unsigned char*)new MessageUpdateAITeam();
}

static void CleanupMessageUpdateAITeam(unsigned char* buf) {
    auto msg = (MessageUpdateAITeam*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionTurret() {
    return (unsigned char*)new MessageUpdatePositionTurret();
}

static void CleanupMessageUpdatePositionTurret(unsigned char* buf) {
    auto msg = (MessageUpdatePositionTurret*)buf;
    delete msg;
}

static unsigned char* CreateMessageStaticObjectDestructed() {
    return (unsigned char*)new MessageStaticObjectDestructed();
}

static void CleanupMessageStaticObjectDestructed(unsigned char* buf) {
    auto msg = (MessageStaticObjectDestructed*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskConnectVoice() {
    return (unsigned char*)new MessageAskConnectVoice();
}

static void CleanupMessageAskConnectVoice(unsigned char* buf) {
    auto msg = (MessageAskConnectVoice*)buf;
    delete msg;
}

static unsigned char* CreateMessageConnectVoiceDirect() {
    return (unsigned char*)new MessageConnectVoiceDirect();
}

static void CleanupMessageConnectVoiceDirect(unsigned char* buf) {
    auto msg = (MessageConnectVoiceDirect*)buf;
    delete msg;
}

static unsigned char* CreateMessageConnectVoiceNatNeg() {
    return (unsigned char*)new MessageConnectVoiceNatNeg();
}

static void CleanupMessageConnectVoiceNatNeg(unsigned char* buf) {
    auto msg = (MessageConnectVoiceNatNeg*)buf;
    delete msg;
}

static unsigned char* CreateMessageDisconnect() {
    return (unsigned char*)new MessageDisconnect();
}

static void CleanupMessageDisconnect(unsigned char* buf) {
    auto msg = (MessageDisconnect*)buf;
    delete msg;
}

static unsigned char* CreateMessageWaypointCreate() {
    return (unsigned char*)new MessageWaypointCreate();
}

static void CleanupMessageWaypointCreate(unsigned char* buf) {
    auto msg = (MessageWaypointCreate*)buf;
    delete msg;
}

static unsigned char* CreateMessageWaypointUpdate() {
    return (unsigned char*)new MessageWaypointUpdate();
}

static void CleanupMessageWaypointUpdate(unsigned char* buf) {
    auto msg = (MessageWaypointUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageWaypointDelete() {
    return (unsigned char*)new MessageWaypointDelete();
}

static void CleanupMessageWaypointDelete(unsigned char* buf) {
    auto msg = (MessageWaypointDelete*)buf;
    delete msg;
}

static unsigned char* CreateMessageHCSetGroup() {
    return (unsigned char*)new MessageHCSetGroup();
}

static void CleanupMessageHCSetGroup(unsigned char* buf) {
    auto msg = (MessageHCSetGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageHCRemoveGroup() {
    return (unsigned char*)new MessageHCRemoveGroup();
}

static void CleanupMessageHCRemoveGroup(unsigned char* buf) {
    auto msg = (MessageHCRemoveGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageHCClearGroups() {
    return (unsigned char*)new MessageHCClearGroups();
}

static void CleanupMessageHCClearGroups(unsigned char* buf) {
    auto msg = (MessageHCClearGroups*)buf;
    delete msg;
}

static unsigned char* CreateMessageMissionStats() {
    return (unsigned char*)new MessageMissionStats();
}

static void CleanupMessageMissionStats(unsigned char* buf) {
    auto msg = (MessageMissionStats*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForFireWeapon() {
    return (unsigned char*)new MessageAskForFireWeapon();
}

static void CleanupMessageAskForFireWeapon(unsigned char* buf) {
    auto msg = (MessageAskForFireWeapon*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForGetInWantsPlayer() {
    return (unsigned char*)new MessageAskForGetInWantsPlayer();
}

static void CleanupMessageAskForGetInWantsPlayer(unsigned char* buf) {
    auto msg = (MessageAskForGetInWantsPlayer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForOrderGetIn() {
    return (unsigned char*)new MessageAskForOrderGetIn();
}

static void CleanupMessageAskForOrderGetIn(unsigned char* buf) {
    auto msg = (MessageAskForOrderGetIn*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAllowGetIn() {
    return (unsigned char*)new MessageAskForAllowGetIn();
}

static void CleanupMessageAskForAllowGetIn(unsigned char* buf) {
    auto msg = (MessageAskForAllowGetIn*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAirportSetSide() {
    return (unsigned char*)new MessageAskForAirportSetSide();
}

static void CleanupMessageAskForAirportSetSide(unsigned char* buf) {
    auto msg = (MessageAskForAirportSetSide*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForArbitration() {
    return (unsigned char*)new MessageAskForArbitration();
}

static void CleanupMessageAskForArbitration(unsigned char* buf) {
    auto msg = (MessageAskForArbitration*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateDamageVehicle() {
    return (unsigned char*)new MessageUpdateDamageVehicle();
}

static void CleanupMessageUpdateDamageVehicle(unsigned char* buf) {
    auto msg = (MessageUpdateDamageVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageBattlEye() {
    return (unsigned char*)new MessageBattlEye();
}

static void CleanupMessageBattlEye(unsigned char* buf) {
    auto msg = (MessageBattlEye*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForTeamSwitch() {
    return (unsigned char*)new MessageAskForTeamSwitch();
}

static void CleanupMessageAskForTeamSwitch(unsigned char* buf) {
    auto msg = (MessageAskForTeamSwitch*)buf;
    delete msg;
}

static unsigned char* CreateMessageTeamSwitchResult() {
    return (unsigned char*)new MessageTeamSwitchResult();
}

static void CleanupMessageTeamSwitchResult(unsigned char* buf) {
    auto msg = (MessageTeamSwitchResult*)buf;
    delete msg;
}

static unsigned char* CreateMessageFinishTeamSwitch() {
    return (unsigned char*)new MessageFinishTeamSwitch();
}

static void CleanupMessageFinishTeamSwitch(unsigned char* buf) {
    auto msg = (MessageFinishTeamSwitch*)buf;
    delete msg;
}

static unsigned char* CreateMessageKBReact() {
    return (unsigned char*)new MessageKBReact();
}

static void CleanupMessageKBReact(unsigned char* buf) {
    auto msg = (MessageKBReact*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjectSetVariable() {
    return (unsigned char*)new MessageObjectSetVariable();
}

static void CleanupMessageObjectSetVariable(unsigned char* buf) {
    auto msg = (MessageObjectSetVariable*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjectSetVariablesCollection() {
    return (unsigned char*)new MessageObjectSetVariablesCollection();
}

static void CleanupMessageObjectSetVariablesCollection(unsigned char* buf) {
    auto msg = (MessageObjectSetVariablesCollection*)buf;
    delete msg;
}

static unsigned char* CreateMessageWaypointsCopy() {
    return (unsigned char*)new MessageWaypointsCopy();
}

static void CleanupMessageWaypointsCopy(unsigned char* buf) {
    auto msg = (MessageWaypointsCopy*)buf;
    delete msg;
}

static unsigned char* CreateMessageAttachObject() {
    return (unsigned char*)new MessageAttachObject();
}

static void CleanupMessageAttachObject(unsigned char* buf) {
    auto msg = (MessageAttachObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageDetachObject() {
    return (unsigned char*)new MessageDetachObject();
}

static void CleanupMessageDetachObject(unsigned char* buf) {
    auto msg = (MessageDetachObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSetVariable() {
    return (unsigned char*)new MessageGroupSetVariable();
}

static void CleanupMessageGroupSetVariable(unsigned char* buf) {
    auto msg = (MessageGroupSetVariable*)buf;
    delete msg;
}

static unsigned char* CreateMessageCustomFile() {
    return (unsigned char*)new MessageCustomFile();
}

static void CleanupMessageCustomFile(unsigned char* buf) {
    auto msg = (MessageCustomFile*)buf;
    delete msg;
}

static unsigned char* CreateMessageCustomFileList() {
    return (unsigned char*)new MessageCustomFileList();
}

static void CleanupMessageCustomFileList(unsigned char* buf) {
    auto msg = (MessageCustomFileList*)buf;
    delete msg;
}

static unsigned char* CreateMessageCustomFilesWanted() {
    return (unsigned char*)new MessageCustomFilesWanted();
}

static void CleanupMessageCustomFilesWanted(unsigned char* buf) {
    auto msg = (MessageCustomFilesWanted*)buf;
    delete msg;
}

static unsigned char* CreateMessageDeleteCustomFiles() {
    return (unsigned char*)new MessageDeleteCustomFiles();
}

static void CleanupMessageDeleteCustomFiles(unsigned char* buf) {
    auto msg = (MessageDeleteCustomFiles*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerRoleUpdate() {
    return (unsigned char*)new MessagePlayerRoleUpdate();
}

static void CleanupMessagePlayerRoleUpdate(unsigned char* buf) {
    auto msg = (MessagePlayerRoleUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageNatNegResult() {
    return (unsigned char*)new MessageNatNegResult();
}

static void CleanupMessageNatNegResult(unsigned char* buf) {
    auto msg = (MessageNatNegResult*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateClientInfoDpid() {
    return (unsigned char*)new MessageUpdateClientInfoDpid();
}

static void CleanupMessageUpdateClientInfoDpid(unsigned char* buf) {
    auto msg = (MessageUpdateClientInfoDpid*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerTime() {
    return (unsigned char*)new MessageServerTime();
}

static void CleanupMessageServerTime(unsigned char* buf) {
    auto msg = (MessageServerTime*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateDoor() {
    return (unsigned char*)new MessageUpdateDoor();
}

static void CleanupMessageUpdateDoor(unsigned char* buf) {
    auto msg = (MessageUpdateDoor*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionDoor() {
    return (unsigned char*)new MessageUpdatePositionDoor();
}

static void CleanupMessageUpdatePositionDoor(unsigned char* buf) {
    auto msg = (MessageUpdatePositionDoor*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSetUnconsciousLeader() {
    return (unsigned char*)new MessageGroupSetUnconsciousLeader();
}

static void CleanupMessageGroupSetUnconsciousLeader(unsigned char* buf) {
    auto msg = (MessageGroupSetUnconsciousLeader*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSelectLeader() {
    return (unsigned char*)new MessageGroupSelectLeader();
}

static void CleanupMessageGroupSelectLeader(unsigned char* buf) {
    auto msg = (MessageGroupSelectLeader*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAssignTeam() {
    return (unsigned char*)new MessageAskForAssignTeam();
}

static void CleanupMessageAskForAssignTeam(unsigned char* buf) {
    auto msg = (MessageAskForAssignTeam*)buf;
    delete msg;
}

static unsigned char* CreateMessageLoadedFromSave() {
    return (unsigned char*)new MessageLoadedFromSave();
}

static void CleanupMessageLoadedFromSave(unsigned char* buf) {
    auto msg = (MessageLoadedFromSave*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerDifficulty() {
    return (unsigned char*)new MessageServerDifficulty();
}

static void CleanupMessageServerDifficulty(unsigned char* buf) {
    auto msg = (MessageServerDifficulty*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerAdmin() {
    return (unsigned char*)new MessageServerAdmin();
}

static void CleanupMessageServerAdmin(unsigned char* buf) {
    auto msg = (MessageServerAdmin*)buf;
    delete msg;
}

static unsigned char* CreateMessageTakeBackpack() {
    return (unsigned char*)new MessageTakeBackpack();
}

static void CleanupMessageTakeBackpack(unsigned char* buf) {
    auto msg = (MessageTakeBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageAssemble() {
    return (unsigned char*)new MessageAssemble();
}

static void CleanupMessageAssemble(unsigned char* buf) {
    auto msg = (MessageAssemble*)buf;
    delete msg;
}

static unsigned char* CreateMessageDisAssemble() {
    return (unsigned char*)new MessageDisAssemble();
}

static void CleanupMessageDisAssemble(unsigned char* buf) {
    auto msg = (MessageDisAssemble*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskProcessDisAssemble() {
    return (unsigned char*)new MessageAskProcessDisAssemble();
}

static void CleanupMessageAskProcessDisAssemble(unsigned char* buf) {
    auto msg = (MessageAskProcessDisAssemble*)buf;
    delete msg;
}

static unsigned char* CreateMessageShowGroupDir() {
    return (unsigned char*)new MessageShowGroupDir();
}

static void CleanupMessageShowGroupDir(unsigned char* buf) {
    auto msg = (MessageShowGroupDir*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetMaxHitZoneDamage() {
    return (unsigned char*)new MessageAskForSetMaxHitZoneDamage();
}

static void CleanupMessageAskForSetMaxHitZoneDamage(unsigned char* buf) {
    auto msg = (MessageAskForSetMaxHitZoneDamage*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForEnableVMode() {
    return (unsigned char*)new MessageAskForEnableVMode();
}

static void CleanupMessageAskForEnableVMode(unsigned char* buf) {
    auto msg = (MessageAskForEnableVMode*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForForceGunLight() {
    return (unsigned char*)new MessageAskForForceGunLight();
}

static void CleanupMessageAskForForceGunLight(unsigned char* buf) {
    auto msg = (MessageAskForForceGunLight*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForIRLaser() {
    return (unsigned char*)new MessageAskForIRLaser();
}

static void CleanupMessageAskForIRLaser(unsigned char* buf) {
    auto msg = (MessageAskForIRLaser*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForVehicleDoorState() {
    return (unsigned char*)new MessageAskForVehicleDoorState();
}

static void CleanupMessageAskForVehicleDoorState(unsigned char* buf) {
    auto msg = (MessageAskForVehicleDoorState*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForChangeSide() {
    return (unsigned char*)new MessageAskForChangeSide();
}

static void CleanupMessageAskForChangeSide(unsigned char* buf) {
    auto msg = (MessageAskForChangeSide*)buf;
    delete msg;
}

static unsigned char* CreateMessageVehMPEventHandlers() {
    return (unsigned char*)new MessageVehMPEventHandlers();
}

static void CleanupMessageVehMPEventHandlers(unsigned char* buf) {
    auto msg = (MessageVehMPEventHandlers*)buf;
    delete msg;
}

static unsigned char* CreateMessageVehMPEvent() {
    return (unsigned char*)new MessageVehMPEvent();
}

static void CleanupMessageVehMPEvent(unsigned char* buf) {
    auto msg = (MessageVehMPEvent*)buf;
    delete msg;
}

static unsigned char* CreateMessageMissionMPEvent() {
    return (unsigned char*)new MessageMissionMPEvent();
}

static void CleanupMessageMissionMPEvent(unsigned char* buf) {
    auto msg = (MessageMissionMPEvent*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteEntityEvent() {
    return (unsigned char*)new MessageRemoteEntityEvent();
}

static void CleanupMessageRemoteEntityEvent(unsigned char* buf) {
    auto msg = (MessageRemoteEntityEvent*)buf;
    delete msg;
}

static unsigned char* CreateMessageClearWeaponCargo() {
    return (unsigned char*)new MessageClearWeaponCargo();
}

static void CleanupMessageClearWeaponCargo(unsigned char* buf) {
    auto msg = (MessageClearWeaponCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageClearItemCargo() {
    return (unsigned char*)new MessageClearItemCargo();
}

static void CleanupMessageClearItemCargo(unsigned char* buf) {
    auto msg = (MessageClearItemCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageClearMagazineCargo() {
    return (unsigned char*)new MessageClearMagazineCargo();
}

static void CleanupMessageClearMagazineCargo(unsigned char* buf) {
    auto msg = (MessageClearMagazineCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageClearBackpackCargo() {
    return (unsigned char*)new MessageClearBackpackCargo();
}

static void CleanupMessageClearBackpackCargo(unsigned char* buf) {
    auto msg = (MessageClearBackpackCargo*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateClientCameraPosition() {
    return (unsigned char*)new MessageCreateClientCameraPosition();
}

static void CleanupMessageCreateClientCameraPosition(unsigned char* buf) {
    auto msg = (MessageCreateClientCameraPosition*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateClientCameraPosition() {
    return (unsigned char*)new MessageUpdateClientCameraPosition();
}

static void CleanupMessageUpdateClientCameraPosition(unsigned char* buf) {
    auto msg = (MessageUpdateClientCameraPosition*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreatePlayerRuntime() {
    return (unsigned char*)new MessageCreatePlayerRuntime();
}

static void CleanupMessageCreatePlayerRuntime(unsigned char* buf) {
    auto msg = (MessageCreatePlayerRuntime*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePlayerRuntime() {
    return (unsigned char*)new MessageUpdatePlayerRuntime();
}

static void CleanupMessageUpdatePlayerRuntime(unsigned char* buf) {
    auto msg = (MessageUpdatePlayerRuntime*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteControlled() {
    return (unsigned char*)new MessageAskRemoteControlled();
}

static void CleanupMessageAskRemoteControlled(unsigned char* buf) {
    auto msg = (MessageAskRemoteControlled*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetRank() {
    return (unsigned char*)new MessageAskForSetRank();
}

static void CleanupMessageAskForSetRank(unsigned char* buf) {
    auto msg = (MessageAskForSetRank*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForVehicleControl() {
    return (unsigned char*)new MessageAskForVehicleControl();
}

static void CleanupMessageAskForVehicleControl(unsigned char* buf) {
    auto msg = (MessageAskForVehicleControl*)buf;
    delete msg;
}

static unsigned char* CreateMessageOwnerChanged() {
    return (unsigned char*)new MessageOwnerChanged();
}

static void CleanupMessageOwnerChanged(unsigned char* buf) {
    auto msg = (MessageOwnerChanged*)buf;
    delete msg;
}

static unsigned char* CreateMessageLastOperPos() {
    return (unsigned char*)new MessageLastOperPos();
}

static void CleanupMessageLastOperPos(unsigned char* buf) {
    auto msg = (MessageLastOperPos*)buf;
    delete msg;
}

static unsigned char* CreateMessageFileSignatureAsk() {
    return (unsigned char*)new MessageFileSignatureAsk();
}

static void CleanupMessageFileSignatureAsk(unsigned char* buf) {
    auto msg = (MessageFileSignatureAsk*)buf;
    delete msg;
}

static unsigned char* CreateMessageFileSignatureAnswer() {
    return (unsigned char*)new MessageFileSignatureAnswer();
}

static void CleanupMessageFileSignatureAnswer(unsigned char* buf) {
    auto msg = (MessageFileSignatureAnswer*)buf;
    delete msg;
}

static unsigned char* CreateMessageChangeCreatorId() {
    return (unsigned char*)new MessageChangeCreatorId();
}

static void CleanupMessageChangeCreatorId(unsigned char* buf) {
    auto msg = (MessageChangeCreatorId*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAllowCrewInImmobile() {
    return (unsigned char*)new MessageAskForAllowCrewInImmobile();
}

static void CleanupMessageAskForAllowCrewInImmobile(unsigned char* buf) {
    auto msg = (MessageAskForAllowCrewInImmobile*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForPilotLight() {
    return (unsigned char*)new MessageAskForPilotLight();
}

static void CleanupMessageAskForPilotLight(unsigned char* buf) {
    auto msg = (MessageAskForPilotLight*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateRadioChannel() {
    return (unsigned char*)new MessageCreateRadioChannel();
}

static void CleanupMessageCreateRadioChannel(unsigned char* buf) {
    auto msg = (MessageCreateRadioChannel*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChannelLabel() {
    return (unsigned char*)new MessageRadioChannelLabel();
}

static void CleanupMessageRadioChannelLabel(unsigned char* buf) {
    auto msg = (MessageRadioChannelLabel*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChannelCallSign() {
    return (unsigned char*)new MessageRadioChannelCallSign();
}

static void CleanupMessageRadioChannelCallSign(unsigned char* buf) {
    auto msg = (MessageRadioChannelCallSign*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChannelUnits() {
    return (unsigned char*)new MessageRadioChannelUnits();
}

static void CleanupMessageRadioChannelUnits(unsigned char* buf) {
    auto msg = (MessageRadioChannelUnits*)buf;
    delete msg;
}

static unsigned char* CreateMessageSendAUMsg() {
    return (unsigned char*)new MessageSendAUMsg();
}

static void CleanupMessageSendAUMsg(unsigned char* buf) {
    auto msg = (MessageSendAUMsg*)buf;
    delete msg;
}

static unsigned char* CreateMessageLockSupply() {
    return (unsigned char*)new MessageLockSupply();
}

static void CleanupMessageLockSupply(unsigned char* buf) {
    auto msg = (MessageLockSupply*)buf;
    delete msg;
}

static unsigned char* CreateMessageUnlockSupply() {
    return (unsigned char*)new MessageUnlockSupply();
}

static void CleanupMessageUnlockSupply(unsigned char* buf) {
    auto msg = (MessageUnlockSupply*)buf;
    delete msg;
}

static unsigned char* CreateMessageReturnEquipment() {
    return (unsigned char*)new MessageReturnEquipment();
}

static void CleanupMessageReturnEquipment(unsigned char* buf) {
    auto msg = (MessageReturnEquipment*)buf;
    delete msg;
}

static unsigned char* CreateMessageServerInfo() {
    return (unsigned char*)new MessageServerInfo();
}

static void CleanupMessageServerInfo(unsigned char* buf) {
    auto msg = (MessageServerInfo*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicVariableTo() {
    return (unsigned char*)new MessagePublicVariableTo();
}

static void CleanupMessagePublicVariableTo(unsigned char* buf) {
    auto msg = (MessagePublicVariableTo*)buf;
    delete msg;
}

static unsigned char* CreateMessageUavTerminalCreateConnection() {
    return (unsigned char*)new MessageUavTerminalCreateConnection();
}

static void CleanupMessageUavTerminalCreateConnection(unsigned char* buf) {
    auto msg = (MessageUavTerminalCreateConnection*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateInvisibleVehicle() {
    return (unsigned char*)new MessageUpdateInvisibleVehicle();
}

static void CleanupMessageUpdateInvisibleVehicle(unsigned char* buf) {
    auto msg = (MessageUpdateInvisibleVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageRadioChatBroadcast() {
    return (unsigned char*)new MessageRadioChatBroadcast();
}

static void CleanupMessageRadioChatBroadcast(unsigned char* buf) {
    auto msg = (MessageRadioChatBroadcast*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetObjectTexture() {
    return (unsigned char*)new MessageSetObjectTexture();
}

static void CleanupMessageSetObjectTexture(unsigned char* buf) {
    auto msg = (MessageSetObjectTexture*)buf;
    delete msg;
}

static unsigned char* CreateMessageForceFlagTexture() {
    return (unsigned char*)new MessageForceFlagTexture();
}

static void CleanupMessageForceFlagTexture(unsigned char* buf) {
    auto msg = (MessageForceFlagTexture*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddSideScore() {
    return (unsigned char*)new MessageAddSideScore();
}

static void CleanupMessageAddSideScore(unsigned char* buf) {
    auto msg = (MessageAddSideScore*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetVisibility() {
    return (unsigned char*)new MessageAskForSetVisibility();
}

static void CleanupMessageAskForSetVisibility(unsigned char* buf) {
    auto msg = (MessageAskForSetVisibility*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForEnableSimulation() {
    return (unsigned char*)new MessageAskForEnableSimulation();
}

static void CleanupMessageAskForEnableSimulation(unsigned char* buf) {
    auto msg = (MessageAskForEnableSimulation*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForRemoveFromCenter() {
    return (unsigned char*)new MessageAskForRemoveFromCenter();
}

static void CleanupMessageAskForRemoveFromCenter(unsigned char* buf) {
    auto msg = (MessageAskForRemoveFromCenter*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForForceWeatherUpdate() {
    return (unsigned char*)new MessageAskForForceWeatherUpdate();
}

static void CleanupMessageAskForForceWeatherUpdate(unsigned char* buf) {
    auto msg = (MessageAskForForceWeatherUpdate*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetPlanningMode() {
    return (unsigned char*)new MessageAskForSetPlanningMode();
}

static void CleanupMessageAskForSetPlanningMode(unsigned char* buf) {
    auto msg = (MessageAskForSetPlanningMode*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDisconnectUav() {
    return (unsigned char*)new MessageAskForDisconnectUav();
}

static void CleanupMessageAskForDisconnectUav(unsigned char* buf) {
    auto msg = (MessageAskForDisconnectUav*)buf;
    delete msg;
}

static unsigned char* CreateMessageUavTerminalReleaseConnection() {
    return (unsigned char*)new MessageUavTerminalReleaseConnection();
}

static void CleanupMessageUavTerminalReleaseConnection(unsigned char* buf) {
    auto msg = (MessageUavTerminalReleaseConnection*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetRemoveMode() {
    return (unsigned char*)new MessageAskForSetRemoveMode();
}

static void CleanupMessageAskForSetRemoveMode(unsigned char* buf) {
    auto msg = (MessageAskForSetRemoveMode*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetParticleClass() {
    return (unsigned char*)new MessageSetParticleClass();
}

static void CleanupMessageSetParticleClass(unsigned char* buf) {
    auto msg = (MessageSetParticleClass*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForCreateAndAddBackpack() {
    return (unsigned char*)new MessageAskForCreateAndAddBackpack();
}

static void CleanupMessageAskForCreateAndAddBackpack(unsigned char* buf) {
    auto msg = (MessageAskForCreateAndAddBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDeleteBackpack() {
    return (unsigned char*)new MessageAskForDeleteBackpack();
}

static void CleanupMessageAskForDeleteBackpack(unsigned char* buf) {
    auto msg = (MessageAskForDeleteBackpack*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForDeleteGroup() {
    return (unsigned char*)new MessageAskForDeleteGroup();
}

static void CleanupMessageAskForDeleteGroup(unsigned char* buf) {
    auto msg = (MessageAskForDeleteGroup*)buf;
    delete msg;
}

static unsigned char* CreateMessageStartWeaponDeploy() {
    return (unsigned char*)new MessageStartWeaponDeploy();
}

static void CleanupMessageStartWeaponDeploy(unsigned char* buf) {
    auto msg = (MessageStartWeaponDeploy*)buf;
    delete msg;
}

static unsigned char* CreateMessageStopWeaponDeploy() {
    return (unsigned char*)new MessageStopWeaponDeploy();
}

static void CleanupMessageStopWeaponDeploy(unsigned char* buf) {
    auto msg = (MessageStopWeaponDeploy*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionTankOrCar() {
    return (unsigned char*)new MessageUpdatePositionTankOrCar();
}

static void CleanupMessageUpdatePositionTankOrCar(unsigned char* buf) {
    auto msg = (MessageUpdatePositionTankOrCar*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteExecServer() {
    return (unsigned char*)new MessageAskRemoteExecServer();
}

static void CleanupMessageAskRemoteExecServer(unsigned char* buf) {
    auto msg = (MessageAskRemoteExecServer*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteExecServerNamed() {
    return (unsigned char*)new MessageAskRemoteExecServerNamed();
}

static void CleanupMessageAskRemoteExecServerNamed(unsigned char* buf) {
    auto msg = (MessageAskRemoteExecServerNamed*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteExecClient() {
    return (unsigned char*)new MessageAskRemoteExecClient();
}

static void CleanupMessageAskRemoteExecClient(unsigned char* buf) {
    auto msg = (MessageAskRemoteExecClient*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecServer() {
    return (unsigned char*)new MessageRemoteExecServer();
}

static void CleanupMessageRemoteExecServer(unsigned char* buf) {
    auto msg = (MessageRemoteExecServer*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecClient() {
    return (unsigned char*)new MessageRemoteExecClient();
}

static void CleanupMessageRemoteExecClient(unsigned char* buf) {
    auto msg = (MessageRemoteExecClient*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecUnJIP() {
    return (unsigned char*)new MessageRemoteExecUnJIP();
}

static void CleanupMessageRemoteExecUnJIP(unsigned char* buf) {
    auto msg = (MessageRemoteExecUnJIP*)buf;
    delete msg;
}

static unsigned char* CreateMessageNamespaceSetVariable() {
    return (unsigned char*)new MessageNamespaceSetVariable();
}

static void CleanupMessageNamespaceSetVariable(unsigned char* buf) {
    auto msg = (MessageNamespaceSetVariable*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteExecClientOne() {
    return (unsigned char*)new MessageAskRemoteExecClientOne();
}

static void CleanupMessageAskRemoteExecClientOne(unsigned char* buf) {
    auto msg = (MessageAskRemoteExecClientOne*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetGroupIdentity() {
    return (unsigned char*)new MessageSetGroupIdentity();
}

static void CleanupMessageSetGroupIdentity(unsigned char* buf) {
    auto msg = (MessageSetGroupIdentity*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecServerExt() {
    return (unsigned char*)new MessageRemoteExecServerExt();
}

static void CleanupMessageRemoteExecServerExt(unsigned char* buf) {
    auto msg = (MessageRemoteExecServerExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecClientExt() {
    return (unsigned char*)new MessageRemoteExecClientExt();
}

static void CleanupMessageRemoteExecClientExt(unsigned char* buf) {
    auto msg = (MessageRemoteExecClientExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecClientMulti() {
    return (unsigned char*)new MessageRemoteExecClientMulti();
}

static void CleanupMessageRemoteExecClientMulti(unsigned char* buf) {
    auto msg = (MessageRemoteExecClientMulti*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetObjectMaterial() {
    return (unsigned char*)new MessageSetObjectMaterial();
}

static void CleanupMessageSetObjectMaterial(unsigned char* buf) {
    auto msg = (MessageSetObjectMaterial*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjectSetVariableClient() {
    return (unsigned char*)new MessageObjectSetVariableClient();
}

static void CleanupMessageObjectSetVariableClient(unsigned char* buf) {
    auto msg = (MessageObjectSetVariableClient*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjectSetVariableExt() {
    return (unsigned char*)new MessageObjectSetVariableExt();
}

static void CleanupMessageObjectSetVariableExt(unsigned char* buf) {
    auto msg = (MessageObjectSetVariableExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjectSetVariableExtArray() {
    return (unsigned char*)new MessageObjectSetVariableExtArray();
}

static void CleanupMessageObjectSetVariableExtArray(unsigned char* buf) {
    auto msg = (MessageObjectSetVariableExtArray*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSetVariableClient() {
    return (unsigned char*)new MessageGroupSetVariableClient();
}

static void CleanupMessageGroupSetVariableClient(unsigned char* buf) {
    auto msg = (MessageGroupSetVariableClient*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSetVariableExt() {
    return (unsigned char*)new MessageGroupSetVariableExt();
}

static void CleanupMessageGroupSetVariableExt(unsigned char* buf) {
    auto msg = (MessageGroupSetVariableExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageGroupSetVariableExtArray() {
    return (unsigned char*)new MessageGroupSetVariableExtArray();
}

static void CleanupMessageGroupSetVariableExtArray(unsigned char* buf) {
    auto msg = (MessageGroupSetVariableExtArray*)buf;
    delete msg;
}

static unsigned char* CreateMessageTeamMemberSetVariableExt() {
    return (unsigned char*)new MessageTeamMemberSetVariableExt();
}

static void CleanupMessageTeamMemberSetVariableExt(unsigned char* buf) {
    auto msg = (MessageTeamMemberSetVariableExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageTeamMemberSetVariableExtArray() {
    return (unsigned char*)new MessageTeamMemberSetVariableExtArray();
}

static void CleanupMessageTeamMemberSetVariableExtArray(unsigned char* buf) {
    auto msg = (MessageTeamMemberSetVariableExtArray*)buf;
    delete msg;
}

static unsigned char* CreateMessageNamespaceSetVariableExt() {
    return (unsigned char*)new MessageNamespaceSetVariableExt();
}

static void CleanupMessageNamespaceSetVariableExt(unsigned char* buf) {
    auto msg = (MessageNamespaceSetVariableExt*)buf;
    delete msg;
}

static unsigned char* CreateMessageNamespaceSetVariableExtArray() {
    return (unsigned char*)new MessageNamespaceSetVariableExtArray();
}

static void CleanupMessageNamespaceSetVariableExtArray(unsigned char* buf) {
    auto msg = (MessageNamespaceSetVariableExtArray*)buf;
    delete msg;
}

static unsigned char* CreateMessageSetVisibility() {
    return (unsigned char*)new MessageSetVisibility();
}

static void CleanupMessageSetVisibility(unsigned char* buf) {
    auto msg = (MessageSetVisibility*)buf;
    delete msg;
}

static unsigned char* CreateMessageSyncVarsInJIPQueue() {
    return (unsigned char*)new MessageSyncVarsInJIPQueue();
}

static void CleanupMessageSyncVarsInJIPQueue(unsigned char* buf) {
    auto msg = (MessageSyncVarsInJIPQueue*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicKey() {
    return (unsigned char*)new MessagePublicKey();
}

static void CleanupMessagePublicKey(unsigned char* buf) {
    auto msg = (MessagePublicKey*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicKeyAck() {
    return (unsigned char*)new MessagePublicKeyAck();
}

static void CleanupMessagePublicKeyAck(unsigned char* buf) {
    auto msg = (MessagePublicKeyAck*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicKeyBE() {
    return (unsigned char*)new MessagePublicKeyBE();
}

static void CleanupMessagePublicKeyBE(unsigned char* buf) {
    auto msg = (MessagePublicKeyBE*)buf;
    delete msg;
}

static unsigned char* CreateMessagePublicKeyAckBE() {
    return (unsigned char*)new MessagePublicKeyAckBE();
}

static void CleanupMessagePublicKeyAckBE(unsigned char* buf) {
    auto msg = (MessagePublicKeyAckBE*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateEntitySimple() {
    return (unsigned char*)new MessageCreateEntitySimple();
}

static void CleanupMessageCreateEntitySimple(unsigned char* buf) {
    auto msg = (MessageCreateEntitySimple*)buf;
    delete msg;
}

static unsigned char* CreateMessageObjHideAnimSection() {
    return (unsigned char*)new MessageObjHideAnimSection();
}

static void CleanupMessageObjHideAnimSection(unsigned char* buf) {
    auto msg = (MessageObjHideAnimSection*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateProfessionStats() {
    return (unsigned char*)new MessageUpdateProfessionStats();
}

static void CleanupMessageUpdateProfessionStats(unsigned char* buf) {
    auto msg = (MessageUpdateProfessionStats*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskRemoteExecServerNamedObjGrp() {
    return (unsigned char*)new MessageAskRemoteExecServerNamedObjGrp();
}

static void CleanupMessageAskRemoteExecServerNamedObjGrp(unsigned char* buf) {
    auto msg = (MessageAskRemoteExecServerNamedObjGrp*)buf;
    delete msg;
}

static unsigned char* CreateMessageRemoteExecUnJIPObjGrp() {
    return (unsigned char*)new MessageRemoteExecUnJIPObjGrp();
}

static void CleanupMessageRemoteExecUnJIPObjGrp(unsigned char* buf) {
    auto msg = (MessageRemoteExecUnJIPObjGrp*)buf;
    delete msg;
}

static unsigned char* CreateMessageTransferFileAck() {
    return (unsigned char*)new MessageTransferFileAck();
}

static void CleanupMessageTransferFileAck(unsigned char* buf) {
    auto msg = (MessageTransferFileAck*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForEnableActiveSensors() {
    return (unsigned char*)new MessageAskForEnableActiveSensors();
}

static void CleanupMessageAskForEnableActiveSensors(unsigned char* buf) {
    auto msg = (MessageAskForEnableActiveSensors*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForApplyObjectFlag() {
    return (unsigned char*)new MessageAskForApplyObjectFlag();
}

static void CleanupMessageAskForApplyObjectFlag(unsigned char* buf) {
    auto msg = (MessageAskForApplyObjectFlag*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForceAIActiveSensors() {
    return (unsigned char*)new MessageAskForceAIActiveSensors();
}

static void CleanupMessageAskForceAIActiveSensors(unsigned char* buf) {
    auto msg = (MessageAskForceAIActiveSensors*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskSetReportRemoteTargets() {
    return (unsigned char*)new MessageAskSetReportRemoteTargets();
}

static void CleanupMessageAskSetReportRemoteTargets(unsigned char* buf) {
    auto msg = (MessageAskSetReportRemoteTargets*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskSetReceiveRemoteTargets() {
    return (unsigned char*)new MessageAskSetReceiveRemoteTargets();
}

static void CleanupMessageAskSetReceiveRemoteTargets(unsigned char* buf) {
    auto msg = (MessageAskSetReceiveRemoteTargets*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskSetReportOwnPosition() {
    return (unsigned char*)new MessageAskSetReportOwnPosition();
}

static void CleanupMessageAskSetReportOwnPosition(unsigned char* buf) {
    auto msg = (MessageAskSetReportOwnPosition*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddEPEForce() {
    return (unsigned char*)new MessageAddEPEForce();
}

static void CleanupMessageAddEPEForce(unsigned char* buf) {
    auto msg = (MessageAddEPEForce*)buf;
    delete msg;
}

static unsigned char* CreateMessageAddEPETorque() {
    return (unsigned char*)new MessageAddEPETorque();
}

static void CleanupMessageAddEPETorque(unsigned char* buf) {
    auto msg = (MessageAddEPETorque*)buf;
    delete msg;
}

static unsigned char* CreateMessageBankCount() {
    return (unsigned char*)new MessageBankCount();
}

static void CleanupMessageBankCount(unsigned char* buf) {
    auto msg = (MessageBankCount*)buf;
    delete msg;
}

static unsigned char* CreateMessagePlayerBE() {
    return (unsigned char*)new MessagePlayerBE();
}

static void CleanupMessagePlayerBE(unsigned char* buf) {
    auto msg = (MessagePlayerBE*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForGetOutToPos() {
    return (unsigned char*)new MessageAskForGetOutToPos();
}

static void CleanupMessageAskForGetOutToPos(unsigned char* buf) {
    auto msg = (MessageAskForGetOutToPos*)buf;
    delete msg;
}

static unsigned char* CreateMessageDataHashCheckAsk() {
    return (unsigned char*)new MessageDataHashCheckAsk();
}

static void CleanupMessageDataHashCheckAsk(unsigned char* buf) {
    auto msg = (MessageDataHashCheckAsk*)buf;
    delete msg;
}

static unsigned char* CreateMessageDataHashCheckAnswer() {
    return (unsigned char*)new MessageDataHashCheckAnswer();
}

static void CleanupMessageDataHashCheckAnswer(unsigned char* buf) {
    auto msg = (MessageDataHashCheckAnswer*)buf;
    delete msg;
}

static unsigned char* CreateMessageTransferDataHashCheck() {
    return (unsigned char*)new MessageTransferDataHashCheck();
}

static void CleanupMessageTransferDataHashCheck(unsigned char* buf) {
    auto msg = (MessageTransferDataHashCheck*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskCheckCmdPwd() {
    return (unsigned char*)new MessageAskCheckCmdPwd();
}

static void CleanupMessageAskCheckCmdPwd(unsigned char* buf) {
    auto msg = (MessageAskCheckCmdPwd*)buf;
    delete msg;
}

static unsigned char* CreateMessageAcceptCheckCmdPwd() {
    return (unsigned char*)new MessageAcceptCheckCmdPwd();
}

static void CleanupMessageAcceptCheckCmdPwd(unsigned char* buf) {
    auto msg = (MessageAcceptCheckCmdPwd*)buf;
    delete msg;
}

static unsigned char* CreateMessageDenyCheckCmdPwd() {
    return (unsigned char*)new MessageDenyCheckCmdPwd();
}

static void CleanupMessageDenyCheckCmdPwd(unsigned char* buf) {
    auto msg = (MessageDenyCheckCmdPwd*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateCuratorCommander() {
    return (unsigned char*)new MessageUpdateCuratorCommander();
}

static void CleanupMessageUpdateCuratorCommander(unsigned char* buf) {
    auto msg = (MessageUpdateCuratorCommander*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForJoinCuratorCommander() {
    return (unsigned char*)new MessageAskForJoinCuratorCommander();
}

static void CleanupMessageAskForJoinCuratorCommander(unsigned char* buf) {
    auto msg = (MessageAskForJoinCuratorCommander*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForJoinCuratorLogic() {
    return (unsigned char*)new MessageAskForJoinCuratorLogic();
}

static void CleanupMessageAskForJoinCuratorLogic(unsigned char* buf) {
    auto msg = (MessageAskForJoinCuratorLogic*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForChangeCuratorPoints() {
    return (unsigned char*)new MessageAskForChangeCuratorPoints();
}

static void CleanupMessageAskForChangeCuratorPoints(unsigned char* buf) {
    auto msg = (MessageAskForChangeCuratorPoints*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAddCuratorEditableUnit() {
    return (unsigned char*)new MessageAskForAddCuratorEditableUnit();
}

static void CleanupMessageAskForAddCuratorEditableUnit(unsigned char* buf) {
    auto msg = (MessageAskForAddCuratorEditableUnit*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForAddCuratorArea() {
    return (unsigned char*)new MessageAskForAddCuratorArea();
}

static void CleanupMessageAskForAddCuratorArea(unsigned char* buf) {
    auto msg = (MessageAskForAddCuratorArea*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForRemoveCuratorArea() {
    return (unsigned char*)new MessageAskForRemoveCuratorArea();
}

static void CleanupMessageAskForRemoveCuratorArea(unsigned char* buf) {
    auto msg = (MessageAskForRemoveCuratorArea*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForChangeCuratorCameraMoveCeiling() {
    return (unsigned char*)new MessageAskForChangeCuratorCameraMoveCeiling();
}

static void CleanupMessageAskForChangeCuratorCameraMoveCeiling(unsigned char* buf) {
    auto msg = (MessageAskForChangeCuratorCameraMoveCeiling*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetCuratorActionCoef() {
    return (unsigned char*)new MessageAskForSetCuratorActionCoef();
}

static void CleanupMessageAskForSetCuratorActionCoef(unsigned char* buf) {
    auto msg = (MessageAskForSetCuratorActionCoef*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSetCuratorWaypointCost() {
    return (unsigned char*)new MessageAskForSetCuratorWaypointCost();
}

static void CleanupMessageAskForSetCuratorWaypointCost(unsigned char* buf) {
    auto msg = (MessageAskForSetCuratorWaypointCost*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForModifyCuratorAllowedAddons() {
    return (unsigned char*)new MessageAskForModifyCuratorAllowedAddons();
}

static void CleanupMessageAskForModifyCuratorAllowedAddons(unsigned char* buf) {
    auto msg = (MessageAskForModifyCuratorAllowedAddons*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForChangeCuratorEditAreaType() {
    return (unsigned char*)new MessageAskForChangeCuratorEditAreaType();
}

static void CleanupMessageAskForChangeCuratorEditAreaType(unsigned char* buf) {
    auto msg = (MessageAskForChangeCuratorEditAreaType*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForPingCurator() {
    return (unsigned char*)new MessageAskForPingCurator();
}

static void CleanupMessageAskForPingCurator(unsigned char* buf) {
    auto msg = (MessageAskForPingCurator*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateJointConnection() {
    return (unsigned char*)new MessageCreateJointConnection();
}

static void CleanupMessageCreateJointConnection(unsigned char* buf) {
    auto msg = (MessageCreateJointConnection*)buf;
    delete msg;
}

static unsigned char* CreateMessageAttachEPE() {
    return (unsigned char*)new MessageAttachEPE();
}

static void CleanupMessageAttachEPE(unsigned char* buf) {
    auto msg = (MessageAttachEPE*)buf;
    delete msg;
}

static unsigned char* CreateMessageDetachEPE() {
    return (unsigned char*)new MessageDetachEPE();
}

static void CleanupMessageDetachEPE(unsigned char* buf) {
    auto msg = (MessageDetachEPE*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateSmokeEPE() {
    return (unsigned char*)new MessageUpdateSmokeEPE();
}

static void CleanupMessageUpdateSmokeEPE(unsigned char* buf) {
    auto msg = (MessageUpdateSmokeEPE*)buf;
    delete msg;
}

static unsigned char* CreateMessagePolymorphPosition() {
    return (unsigned char*)new MessagePolymorphPosition();
}

static void CleanupMessagePolymorphPosition(unsigned char* buf) {
    auto msg = (MessagePolymorphPosition*)buf;
    delete msg;
}

static unsigned char* CreateMessageJointParameters() {
    return (unsigned char*)new MessageJointParameters();
}

static void CleanupMessageJointParameters(unsigned char* buf) {
    auto msg = (MessageJointParameters*)buf;
    delete msg;
}

static unsigned char* CreateMessageChangeVisibilityAI() {
    return (unsigned char*)new MessageChangeVisibilityAI();
}

static void CleanupMessageChangeVisibilityAI(unsigned char* buf) {
    auto msg = (MessageChangeVisibilityAI*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateRagdollMan() {
    return (unsigned char*)new MessageUpdateRagdollMan();
}

static void CleanupMessageUpdateRagdollMan(unsigned char* buf) {
    auto msg = (MessageUpdateRagdollMan*)buf;
    delete msg;
}

static unsigned char* CreateMessageRagdollRequested() {
    return (unsigned char*)new MessageRagdollRequested();
}

static void CleanupMessageRagdollRequested(unsigned char* buf) {
    auto msg = (MessageRagdollRequested*)buf;
    delete msg;
}

static unsigned char* CreateMessageRagdollSyncAll() {
    return (unsigned char*)new MessageRagdollSyncAll();
}

static void CleanupMessageRagdollSyncAll(unsigned char* buf) {
    auto msg = (MessageRagdollSyncAll*)buf;
    delete msg;
}

static unsigned char* CreateMessageRagdollShotImpact() {
    return (unsigned char*)new MessageRagdollShotImpact();
}

static void CleanupMessageRagdollShotImpact(unsigned char* buf) {
    auto msg = (MessageRagdollShotImpact*)buf;
    delete msg;
}

static unsigned char* CreateMessageJointDescription() {
    return (unsigned char*)new MessageJointDescription();
}

static void CleanupMessageJointDescription(unsigned char* buf) {
    auto msg = (MessageJointDescription*)buf;
    delete msg;
}

static unsigned char* CreateMessageJointDOFs() {
    return (unsigned char*)new MessageJointDOFs();
}

static void CleanupMessageJointDOFs(unsigned char* buf) {
    auto msg = (MessageJointDOFs*)buf;
    delete msg;
}

static unsigned char* CreateMessageJointDrives() {
    return (unsigned char*)new MessageJointDrives();
}

static void CleanupMessageJointDrives(unsigned char* buf) {
    auto msg = (MessageJointDrives*)buf;
    delete msg;
}

static unsigned char* CreateMessageJointLimits() {
    return (unsigned char*)new MessageJointLimits();
}

static void CleanupMessageJointLimits(unsigned char* buf) {
    auto msg = (MessageJointLimits*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateHelicopterRTD() {
    return (unsigned char*)new MessageCreateHelicopterRTD();
}

static void CleanupMessageCreateHelicopterRTD(unsigned char* buf) {
    auto msg = (MessageCreateHelicopterRTD*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateHelicopterRTD() {
    return (unsigned char*)new MessageUpdateHelicopterRTD();
}

static void CleanupMessageUpdateHelicopterRTD(unsigned char* buf) {
    auto msg = (MessageUpdateHelicopterRTD*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionHelicopterRTD() {
    return (unsigned char*)new MessageUpdatePositionHelicopterRTD();
}

static void CleanupMessageUpdatePositionHelicopterRTD(unsigned char* buf) {
    auto msg = (MessageUpdatePositionHelicopterRTD*)buf;
    delete msg;
}

static unsigned char* CreateMessageCreateRopeObject() {
    return (unsigned char*)new MessageCreateRopeObject();
}

static void CleanupMessageCreateRopeObject(unsigned char* buf) {
    auto msg = (MessageCreateRopeObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateRopeObject() {
    return (unsigned char*)new MessageUpdateRopeObject();
}

static void CleanupMessageUpdateRopeObject(unsigned char* buf) {
    auto msg = (MessageUpdateRopeObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePositionRopeObject() {
    return (unsigned char*)new MessageUpdatePositionRopeObject();
}

static void CleanupMessageUpdatePositionRopeObject(unsigned char* buf) {
    auto msg = (MessageUpdatePositionRopeObject*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForEnableRopeAttach() {
    return (unsigned char*)new MessageAskForEnableRopeAttach();
}

static void CleanupMessageAskForEnableRopeAttach(unsigned char* buf) {
    auto msg = (MessageAskForEnableRopeAttach*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForSlingLoadingAction() {
    return (unsigned char*)new MessageAskForSlingLoadingAction();
}

static void CleanupMessageAskForSlingLoadingAction(unsigned char* buf) {
    auto msg = (MessageAskForSlingLoadingAction*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForRopeCut() {
    return (unsigned char*)new MessageAskForRopeCut();
}

static void CleanupMessageAskForRopeCut(unsigned char* buf) {
    auto msg = (MessageAskForRopeCut*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAnimationsVehicle() {
    return (unsigned char*)new MessageUpdateAnimationsVehicle();
}

static void CleanupMessageUpdateAnimationsVehicle(unsigned char* buf) {
    auto msg = (MessageUpdateAnimationsVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateAnimationsMan() {
    return (unsigned char*)new MessageUpdateAnimationsMan();
}

static void CleanupMessageUpdateAnimationsMan(unsigned char* buf) {
    auto msg = (MessageUpdateAnimationsMan*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePersonGear() {
    return (unsigned char*)new MessageUpdatePersonGear();
}

static void CleanupMessageUpdatePersonGear(unsigned char* buf) {
    auto msg = (MessageUpdatePersonGear*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdatePersonWeapons() {
    return (unsigned char*)new MessageUpdatePersonWeapons();
}

static void CleanupMessageUpdatePersonWeapons(unsigned char* buf) {
    auto msg = (MessageUpdatePersonWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskUpdatePersonWeapons() {
    return (unsigned char*)new MessageAskUpdatePersonWeapons();
}

static void CleanupMessageAskUpdatePersonWeapons(unsigned char* buf) {
    auto msg = (MessageAskUpdatePersonWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTransportGear() {
    return (unsigned char*)new MessageUpdateTransportGear();
}

static void CleanupMessageUpdateTransportGear(unsigned char* buf) {
    auto msg = (MessageUpdateTransportGear*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTransportWeapons() {
    return (unsigned char*)new MessageUpdateTransportWeapons();
}

static void CleanupMessageUpdateTransportWeapons(unsigned char* buf) {
    auto msg = (MessageUpdateTransportWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskUpdateTransportWeapons() {
    return (unsigned char*)new MessageAskUpdateTransportWeapons();
}

static void CleanupMessageAskUpdateTransportWeapons(unsigned char* buf) {
    auto msg = (MessageAskUpdateTransportWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTurretGear() {
    return (unsigned char*)new MessageUpdateTurretGear();
}

static void CleanupMessageUpdateTurretGear(unsigned char* buf) {
    auto msg = (MessageUpdateTurretGear*)buf;
    delete msg;
}

static unsigned char* CreateMessageUpdateTurretWeapons() {
    return (unsigned char*)new MessageUpdateTurretWeapons();
}

static void CleanupMessageUpdateTurretWeapons(unsigned char* buf) {
    auto msg = (MessageUpdateTurretWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskUpdateTurretWeapons() {
    return (unsigned char*)new MessageAskUpdateTurretWeapons();
}

static void CleanupMessageAskUpdateTurretWeapons(unsigned char* buf) {
    auto msg = (MessageAskUpdateTurretWeapons*)buf;
    delete msg;
}

static unsigned char* CreateMessageLoadVehicleInVehicle() {
    return (unsigned char*)new MessageLoadVehicleInVehicle();
}

static void CleanupMessageLoadVehicleInVehicle(unsigned char* buf) {
    auto msg = (MessageLoadVehicleInVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageUnloadVehicleInVehicle() {
    return (unsigned char*)new MessageUnloadVehicleInVehicle();
}

static void CleanupMessageUnloadVehicleInVehicle(unsigned char* buf) {
    auto msg = (MessageUnloadVehicleInVehicle*)buf;
    delete msg;
}

static unsigned char* CreateMessageAskForEnableVehicleTransporting() {
    return (unsigned char*)new MessageAskForEnableVehicleTransporting();
}

static void CleanupMessageAskForEnableVehicleTransporting(unsigned char* buf) {
    auto msg = (MessageAskForEnableVehicleTransporting*)buf;
    delete msg;
}

static unsigned char* CreateMessageTacticalPing() {
    return (unsigned char*)new MessageTacticalPing();
}

static void CleanupMessageTacticalPing(unsigned char* buf) {
    auto msg = (MessageTacticalPing*)buf;
    delete msg;
}

static CleanupMsgFn CleanupNetworkMessage[] = {
    CleanupMessageMsgFormatItem,
    CleanupMessageMsgFormat,
    CleanupMessagePlayer,
    CleanupMessageMessages,
    CleanupMessageServerState,
    CleanupMessageClientState,
    CleanupMessagePlayerClientState,
    CleanupMessageLogin,
    CleanupMessageLogout,
    CleanupMessageSquad,
    CleanupMessagePublicVariable,
    CleanupMessageTeamMemberSetVariable,
    CleanupMessageLogMsgOnServer,
    CleanupMessageChat,
    CleanupMessageRadioChat,
    CleanupMessageRadioChatWave,
    CleanupMessageSetSpeaker,
    CleanupMessageMissionHeader,
    CleanupMessagePlayerRole,
    CleanupMessageSelectPlayer,
    CleanupMessageAttachPerson,
    CleanupMessageTransferFile,
    CleanupMessageAskMissionFile,
    CleanupMessageTransferMissionFile,
    CleanupMessageTransferFileToServer,
    CleanupMessageAskForDamage,
    CleanupMessageAskForSetDamage,
    CleanupMessageAskForSetSkill,
    CleanupMessageAskForGetIn,
    CleanupMessageAskForAssignAs,
    CleanupMessageAskForMoveOutTo,
    CleanupMessageAskForRemoveVehicleFromGroup,
    CleanupMessageAskForGetOut,
    CleanupMessageAskWaitForGetOut,
    CleanupMessageAskForChangePosition,
    CleanupMessageAskForSelectWeapon,
    CleanupMessageAskForAmmo,
    CleanupMessageAskForAddImpulse,
    CleanupMessageAskForMoveVector,
    CleanupMessageAskForMoveMatrix,
    CleanupMessageAskForJoinGroup,
    CleanupMessageAskForJoinUnits,
    CleanupMessageExplosionDamageEffects,
    CleanupMessageFireWeapon,
    CleanupMessageUpdateWeapons,
    CleanupMessageAddWeapon,
    CleanupMessageRemoveWeapon,
    CleanupMessageAddWeaponCargo,
    CleanupMessageRemoveWeaponCargo,
    CleanupMessageAddItemCargo,
    CleanupMessageRemoveItemCargo,
    CleanupMessageModifyMagazineAmmoInCargo,
    CleanupMessageSetUnitLoadOutFromClassName,
    CleanupMessageSetUnitLoadOutFromRawData,
    CleanupMessageAssignItemToSlot,
    CleanupMessageUnAssignItemFromSlot,
    CleanupMessageOfferItemFromBody,
    CleanupMessageLinkNewContainer,
    CleanupMessageReplaceContainer,
    CleanupMessageAddMagazineCargo,
    CleanupMessageAddBackpackCargo,
    CleanupMessageRemoveBackpackCargo,
    CleanupMessageRemoveMagazineCargo,
    CleanupMessageAddMagazine,
    CleanupMessageRemoveMagazine,
    CleanupMessageVehicleInit,
    CleanupMessageVehicleDestroyed,
    CleanupMessageStoreCreatedSite,
    CleanupMessageDeleteCreatedSite,
    CleanupMessageRunInitSitesScript,
    CleanupMessageMarkerCreate,
    CleanupMessageMarkerDelete,
    CleanupMessageMarkerUpdate,
    CleanupMessageSetFlagOwner,
    CleanupMessageSetFlagCarrier,
    CleanupMessageMsgVTarget,
    CleanupMessageMsgVFire,
    CleanupMessageMsgVMove,
    CleanupMessageMsgVFormation,
    CleanupMessageMsgVSimpleCommand,
    CleanupMessageMsgVLoad,
    CleanupMessageMsgVAzimut,
    CleanupMessageMsgVStopTurning,
    CleanupMessageMsgVFireFailed,
    CleanupMessageChangeOwner,
    CleanupMessagePlaySound,
    CleanupMessageDeleteObject,
    CleanupMessageDeleteCommand,
    CleanupMessageCreateObject,
    CleanupMessageUpdateObject,
    CleanupMessageCreateVehicle,
    CleanupMessageUpdateVehicle,
    CleanupMessageUpdatePositionVehicle,
    CleanupMessageCreateDetector,
    CleanupMessageUpdateDetector,
    CleanupMessageUpdateFlag,
    CleanupMessageCreateShot,
    CleanupMessageUpdateShot,
    CleanupMessageCreateCrater,
    CleanupMessageCreateCraterOnVehicle,
    CleanupMessageCreateObjectDestructed,
    CleanupMessageCreateAICenter,
    CleanupMessageUpdateAICenter,
    CleanupMessageCreateAIGroup,
    CleanupMessageUpdateAIGroup,
    CleanupMessageUnitSlot,
    CleanupMessageWaypoint,
    CleanupMessageCreateAISubgroup,
    CleanupMessageUpdateAISubgroup,
    CleanupMessageCreateAIBrain,
    CleanupMessageUpdateAIBrain,
    CleanupMessageUpdateAIBrainPath,
    CleanupMessageCreateAIUnit,
    CleanupMessageUpdateAIUnit,
    CleanupMessageUpdateAIUnitPath,
    CleanupMessageCreateAIAgent,
    CleanupMessageUpdateAIAgent,
    CleanupMessageUpdateAIAgentPath,
    CleanupMessageCreateCommand,
    CleanupMessageUpdateCommand,
    CleanupMessageUpdateVehicleAI,
    CleanupMessageUpdateVehicleAIFull,
    CleanupMessageUpdateVehicleBrain,
    CleanupMessageUpdateTransport,
    CleanupMessageUpdateAnimal,
    CleanupMessageUpdatePositionAnimal,
    CleanupMessageUpdateMan,
    CleanupMessageUpdatePositionMan,
    CleanupMessageUpdateTankOrCar,
    CleanupMessageUpdateTank,
    CleanupMessageUpdatePositionTank,
    CleanupMessageUpdateTurret,
    CleanupMessageUpdateCar,
    CleanupMessageUpdatePositionCar,
    CleanupMessageUpdateAirplane,
    CleanupMessageUpdatePositionAirplane,
    CleanupMessageUpdateHelicopter,
    CleanupMessageUpdatePositionHelicopter,
    CleanupMessageUpdateParachute,
    CleanupMessageUpdateParaglide,
    CleanupMessageUpdateShip,
    CleanupMessageUpdatePositionShip,
    CleanupMessageMagazine,
    CleanupMessageNetWeaponInfo,
    CleanupMessageNetMuzzleInfo,
    CleanupMessageContainerRawData,
    CleanupMessageMagazineString,
    CleanupMessageCountedString,
    CleanupMessageCountedWeaponsString,
    CleanupMessagePersonInventoryDescriptor,
    CleanupMessagePathPoint,
    CleanupMessageUpdateMotorcycle,
    CleanupMessageUpdatePositionMotorcycle,
    CleanupMessageAskForHideBody,
    CleanupMessageNetworkCommand,
    CleanupMessageIntegrityQuestion,
    CleanupMessageIntegrityAnswer,
    CleanupMessageUpdateSeagull,
    CleanupMessageUpdatePositionSeagull,
    CleanupMessagePlayerUpdate,
    CleanupMessageUpdateDamageVehicleAI,
    CleanupMessageUpdateDamageObject,
    CleanupMessageCreateHelicopter,
    CleanupMessageUpdateClientInfo,
    CleanupMessageShowTarget,
    CleanupMessageShowSuppressTarget,
    CleanupMessageGroupSynchronization,
    CleanupMessageDetectorActivation,
    CleanupMessageAskForCreateUnit,
    CleanupMessageAskForDeleteVehicle,
    CleanupMessageAskForReceiveUnitAnswer,
    CleanupMessageAskForGroupRespawn,
    CleanupMessageGroupRespawnDone,
    CleanupMessageMissionParams,
    CleanupMessageUpdateMine,
    CleanupMessageAskForActivateMine,
    CleanupMessageAskForDetectedMine,
    CleanupMessageDisposeObject,
    CleanupMessageVehicleDamaged,
    CleanupMessageUpdateFireplace,
    CleanupMessageAskForInflameFire,
    CleanupMessageAskForAnimationPhase,
    CleanupMessageIncomingMissile,
    CleanupMessageLaunchedCounterMeasures,
    CleanupMessageSharedMineUsed,
    CleanupMessageSetShotParents,
    CleanupMessageWeaponLocked,
    CleanupMessageForceDeleteObject,
    CleanupMessageJoinIntoUnit,
    CleanupMessageAIStatsMPRowCreate,
    CleanupMessageAIStatsMPRowUpdate,
    CleanupMessageUpdateSupply,
    CleanupMessageWeatherCreate,
    CleanupMessageWeatherUpdate,
    CleanupMessageMuteList,
    CleanupMessageVoiceOn,
    CleanupMessageCleanupPlayer,
    CleanupMessageLockGearItem,
    CleanupMessageUnlockGearItem,
    CleanupMessageAskItem,
    CleanupMessageAskWeapon,
    CleanupMessageAskMagazine,
    CleanupMessageAskBackpack,
    CleanupMessageReplaceItem,
    CleanupMessageStorePendingItem,
    CleanupMessageReplaceWeapon,
    CleanupMessageReplaceMagazine,
    CleanupMessageReplaceBackpack,
    CleanupMessageReturnWeapon,
    CleanupMessageReturnMagazine,
    CleanupMessageReturnBackpack,
    CleanupMessageCancelTakeFlag,
    CleanupMessagePoolAskWeapon,
    CleanupMessagePoolAskMagazine,
    CleanupMessagePoolAskBackpack,
    CleanupMessagePoolReplaceWeapon,
    CleanupMessagePoolReplaceMagazine,
    CleanupMessagePoolReplaceBackpack,
    CleanupMessagePoolReturnWeapon,
    CleanupMessagePoolReturnMagazine,
    CleanupMessagePoolReturnBackpack,
    CleanupMessageAskSetUnitLoadOutFromClassName,
    CleanupMessageAskSetUnitLoadOutFromRawData,
    CleanupMessageUpdateWeaponsInfo,
    CleanupMessageUpdateWeaponSlotsData,
    CleanupMessageUpdateWeaponsPool,
    CleanupMessageUpdateMagazinesPool,
    CleanupMessageUpdateBackpacksPool,
    CleanupMessageMarker,
    CleanupMessageSite,
    CleanupMessageEffects,
    CleanupMessageUpdateSlotMgr,
    CleanupMessageUpdateEntityAIWeapons,
    CleanupMessageSetRoleIndex,
    CleanupMessageCreateSeagull,
    CleanupMessageMsgVLoadMagazine,
    CleanupMessageMsgVWatchTgt,
    CleanupMessageMsgVWatchPos,
    CleanupMessageRevealTarget,
    CleanupMessageCreateDynSoundSource,
    CleanupMessageCreateDestructionEffects,
    CleanupMessageRemoteMuteList,
    CleanupMessageAskForApplyDoDamage,
    CleanupMessageAskForApplyBleeding,
    CleanupMessageAskForStatsWrite,
    CleanupMessageLocalizedChat,
    CleanupMessageCreateTurret,
    CleanupMessageVoteMission,
    CleanupMessageVotingMissionProgress,
    CleanupMessagePlayerBan,
    CleanupMessagePlayerBanSelf,
    CleanupMessageServerTimeout,
    CleanupMessageAcceptedKey,
    CleanupMessageAdditionalSignedFiles,
    CleanupMessageDataSignatureAsk,
    CleanupMessageDataSignatureAnswer,
    CleanupMessageHackedData,
    CleanupMessageCreateAITeam,
    CleanupMessageUpdateAITeam,
    CleanupMessageUpdatePositionTurret,
    CleanupMessageStaticObjectDestructed,
    CleanupMessageAskConnectVoice,
    CleanupMessageConnectVoiceDirect,
    CleanupMessageConnectVoiceNatNeg,
    CleanupMessageDisconnect,
    CleanupMessageWaypointCreate,
    CleanupMessageWaypointUpdate,
    CleanupMessageWaypointDelete,
    CleanupMessageHCSetGroup,
    CleanupMessageHCRemoveGroup,
    CleanupMessageHCClearGroups,
    CleanupMessageMissionStats,
    CleanupMessageAskForFireWeapon,
    CleanupMessageAskForGetInWantsPlayer,
    CleanupMessageAskForOrderGetIn,
    CleanupMessageAskForAllowGetIn,
    CleanupMessageAskForAirportSetSide,
    CleanupMessageAskForArbitration,
    CleanupMessageUpdateDamageVehicle,
    CleanupMessageBattlEye,
    CleanupMessageAskForTeamSwitch,
    CleanupMessageTeamSwitchResult,
    CleanupMessageFinishTeamSwitch,
    CleanupMessageKBReact,
    CleanupMessageObjectSetVariable,
    CleanupMessageObjectSetVariablesCollection,
    CleanupMessageWaypointsCopy,
    CleanupMessageAttachObject,
    CleanupMessageDetachObject,
    CleanupMessageGroupSetVariable,
    CleanupMessageCustomFile,
    CleanupMessageCustomFileList,
    CleanupMessageCustomFilesWanted,
    CleanupMessageDeleteCustomFiles,
    CleanupMessagePlayerRoleUpdate,
    CleanupMessageNatNegResult,
    CleanupMessageUpdateClientInfoDpid,
    CleanupMessageServerTime,
    CleanupMessageUpdateDoor,
    CleanupMessageUpdatePositionDoor,
    CleanupMessageGroupSetUnconsciousLeader,
    CleanupMessageGroupSelectLeader,
    CleanupMessageAskForAssignTeam,
    CleanupMessageLoadedFromSave,
    CleanupMessageServerDifficulty,
    CleanupMessageServerAdmin,
    CleanupMessageTakeBackpack,
    CleanupMessageAssemble,
    CleanupMessageDisAssemble,
    CleanupMessageAskProcessDisAssemble,
    CleanupMessageShowGroupDir,
    CleanupMessageAskForSetMaxHitZoneDamage,
    CleanupMessageAskForEnableVMode,
    CleanupMessageAskForForceGunLight,
    CleanupMessageAskForIRLaser,
    CleanupMessageAskForVehicleDoorState,
    CleanupMessageAskForChangeSide,
    CleanupMessageVehMPEventHandlers,
    CleanupMessageVehMPEvent,
    CleanupMessageMissionMPEvent,
    CleanupMessageRemoteEntityEvent,
    CleanupMessageClearWeaponCargo,
    CleanupMessageClearItemCargo,
    CleanupMessageClearMagazineCargo,
    CleanupMessageClearBackpackCargo,
    CleanupMessageCreateClientCameraPosition,
    CleanupMessageUpdateClientCameraPosition,
    CleanupMessageCreatePlayerRuntime,
    CleanupMessageUpdatePlayerRuntime,
    CleanupMessageAskRemoteControlled,
    CleanupMessageAskForSetRank,
    CleanupMessageAskForVehicleControl,
    CleanupMessageOwnerChanged,
    CleanupMessageLastOperPos,
    CleanupMessageFileSignatureAsk,
    CleanupMessageFileSignatureAnswer,
    CleanupMessageChangeCreatorId,
    CleanupMessageAskForAllowCrewInImmobile,
    CleanupMessageAskForPilotLight,
    CleanupMessageCreateRadioChannel,
    CleanupMessageRadioChannelLabel,
    CleanupMessageRadioChannelCallSign,
    CleanupMessageRadioChannelUnits,
    CleanupMessageSendAUMsg,
    CleanupMessageLockSupply,
    CleanupMessageUnlockSupply,
    CleanupMessageReturnEquipment,
    CleanupMessageServerInfo,
    CleanupMessagePublicVariableTo,
    CleanupMessageUavTerminalCreateConnection,
    CleanupMessageUpdateInvisibleVehicle,
    CleanupMessageRadioChatBroadcast,
    CleanupMessageSetObjectTexture,
    CleanupMessageForceFlagTexture,
    CleanupMessageAddSideScore,
    CleanupMessageAskForSetVisibility,
    CleanupMessageAskForEnableSimulation,
    CleanupMessageAskForRemoveFromCenter,
    CleanupMessageAskForForceWeatherUpdate,
    CleanupMessageAskForSetPlanningMode,
    CleanupMessageAskForDisconnectUav,
    CleanupMessageUavTerminalReleaseConnection,
    CleanupMessageAskForSetRemoveMode,
    CleanupMessageSetParticleClass,
    CleanupMessageAskForCreateAndAddBackpack,
    CleanupMessageAskForDeleteBackpack,
    CleanupMessageAskForDeleteGroup,
    CleanupMessageStartWeaponDeploy,
    CleanupMessageStopWeaponDeploy,
    CleanupMessageUpdatePositionTankOrCar,
    CleanupMessageAskRemoteExecServer,
    CleanupMessageAskRemoteExecServerNamed,
    CleanupMessageAskRemoteExecClient,
    CleanupMessageRemoteExecServer,
    CleanupMessageRemoteExecClient,
    CleanupMessageRemoteExecUnJIP,
    CleanupMessageNamespaceSetVariable,
    CleanupMessageAskRemoteExecClientOne,
    CleanupMessageSetGroupIdentity,
    CleanupMessageRemoteExecServerExt,
    CleanupMessageRemoteExecClientExt,
    CleanupMessageRemoteExecClientMulti,
    CleanupMessageSetObjectMaterial,
    CleanupMessageObjectSetVariableClient,
    CleanupMessageObjectSetVariableExt,
    CleanupMessageObjectSetVariableExtArray,
    CleanupMessageGroupSetVariableClient,
    CleanupMessageGroupSetVariableExt,
    CleanupMessageGroupSetVariableExtArray,
    CleanupMessageTeamMemberSetVariableExt,
    CleanupMessageTeamMemberSetVariableExtArray,
    CleanupMessageNamespaceSetVariableExt,
    CleanupMessageNamespaceSetVariableExtArray,
    CleanupMessageSetVisibility,
    CleanupMessageSyncVarsInJIPQueue,
    CleanupMessagePublicKey,
    CleanupMessagePublicKeyAck,
    CleanupMessagePublicKeyBE,
    CleanupMessagePublicKeyAckBE,
    CleanupMessageCreateEntitySimple,
    CleanupMessageObjHideAnimSection,
    CleanupMessageUpdateProfessionStats,
    CleanupMessageAskRemoteExecServerNamedObjGrp,
    CleanupMessageRemoteExecUnJIPObjGrp,
    CleanupMessageTransferFileAck,
    CleanupMessageAskForEnableActiveSensors,
    CleanupMessageAskForApplyObjectFlag,
    CleanupMessageAskForceAIActiveSensors,
    CleanupMessageAskSetReportRemoteTargets,
    CleanupMessageAskSetReceiveRemoteTargets,
    CleanupMessageAskSetReportOwnPosition,
    CleanupMessageAddEPEForce,
    CleanupMessageAddEPETorque,
    CleanupMessageBankCount,
    CleanupMessagePlayerBE,
    CleanupMessageAskForGetOutToPos,
    CleanupMessageDataHashCheckAsk,
    CleanupMessageDataHashCheckAnswer,
    CleanupMessageTransferDataHashCheck,
    CleanupMessageAskCheckCmdPwd,
    CleanupMessageAcceptCheckCmdPwd,
    CleanupMessageDenyCheckCmdPwd,
    CleanupMessageUpdateCuratorCommander,
    CleanupMessageAskForJoinCuratorCommander,
    CleanupMessageAskForJoinCuratorLogic,
    CleanupMessageAskForChangeCuratorPoints,
    CleanupMessageAskForAddCuratorEditableUnit,
    CleanupMessageAskForAddCuratorArea,
    CleanupMessageAskForRemoveCuratorArea,
    CleanupMessageAskForChangeCuratorCameraMoveCeiling,
    CleanupMessageAskForSetCuratorActionCoef,
    CleanupMessageAskForSetCuratorWaypointCost,
    CleanupMessageAskForModifyCuratorAllowedAddons,
    CleanupMessageAskForChangeCuratorEditAreaType,
    CleanupMessageAskForPingCurator,
    CleanupMessageCreateJointConnection,
    CleanupMessageAttachEPE,
    CleanupMessageDetachEPE,
    CleanupMessageUpdateSmokeEPE,
    CleanupMessagePolymorphPosition,
    CleanupMessageJointParameters,
    CleanupMessageChangeVisibilityAI,
    CleanupMessageUpdateRagdollMan,
    CleanupMessageRagdollRequested,
    CleanupMessageRagdollSyncAll,
    CleanupMessageRagdollShotImpact,
    CleanupMessageJointDescription,
    CleanupMessageJointDOFs,
    CleanupMessageJointDrives,
    CleanupMessageJointLimits,
    CleanupMessageCreateHelicopterRTD,
    CleanupMessageUpdateHelicopterRTD,
    CleanupMessageUpdatePositionHelicopterRTD,
    CleanupMessageCreateRopeObject,
    CleanupMessageUpdateRopeObject,
    CleanupMessageUpdatePositionRopeObject,
    CleanupMessageAskForEnableRopeAttach,
    CleanupMessageAskForSlingLoadingAction,
    CleanupMessageAskForRopeCut,
    CleanupMessageUpdateAnimationsVehicle,
    CleanupMessageUpdateAnimationsMan,
    CleanupMessageUpdatePersonGear,
    CleanupMessageUpdatePersonWeapons,
    CleanupMessageAskUpdatePersonWeapons,
    CleanupMessageUpdateTransportGear,
    CleanupMessageUpdateTransportWeapons,
    CleanupMessageAskUpdateTransportWeapons,
    CleanupMessageUpdateTurretGear,
    CleanupMessageUpdateTurretWeapons,
    CleanupMessageAskUpdateTurretWeapons,
    CleanupMessageLoadVehicleInVehicle,
    CleanupMessageUnloadVehicleInVehicle,
    CleanupMessageAskForEnableVehicleTransporting,
    CleanupMessageTacticalPing,
};
static CreateMsgFn CreateNetworkMessage[] = {
    CreateMessageMsgFormatItem,
    CreateMessageMsgFormat,
    CreateMessagePlayer,
    CreateMessageMessages,
    CreateMessageServerState,
    CreateMessageClientState,
    CreateMessagePlayerClientState,
    CreateMessageLogin,
    CreateMessageLogout,
    CreateMessageSquad,
    CreateMessagePublicVariable,
    CreateMessageTeamMemberSetVariable,
    CreateMessageLogMsgOnServer,
    CreateMessageChat,
    CreateMessageRadioChat,
    CreateMessageRadioChatWave,
    CreateMessageSetSpeaker,
    CreateMessageMissionHeader,
    CreateMessagePlayerRole,
    CreateMessageSelectPlayer,
    CreateMessageAttachPerson,
    CreateMessageTransferFile,
    CreateMessageAskMissionFile,
    CreateMessageTransferMissionFile,
    CreateMessageTransferFileToServer,
    CreateMessageAskForDamage,
    CreateMessageAskForSetDamage,
    CreateMessageAskForSetSkill,
    CreateMessageAskForGetIn,
    CreateMessageAskForAssignAs,
    CreateMessageAskForMoveOutTo,
    CreateMessageAskForRemoveVehicleFromGroup,
    CreateMessageAskForGetOut,
    CreateMessageAskWaitForGetOut,
    CreateMessageAskForChangePosition,
    CreateMessageAskForSelectWeapon,
    CreateMessageAskForAmmo,
    CreateMessageAskForAddImpulse,
    CreateMessageAskForMoveVector,
    CreateMessageAskForMoveMatrix,
    CreateMessageAskForJoinGroup,
    CreateMessageAskForJoinUnits,
    CreateMessageExplosionDamageEffects,
    CreateMessageFireWeapon,
    CreateMessageUpdateWeapons,
    CreateMessageAddWeapon,
    CreateMessageRemoveWeapon,
    CreateMessageAddWeaponCargo,
    CreateMessageRemoveWeaponCargo,
    CreateMessageAddItemCargo,
    CreateMessageRemoveItemCargo,
    CreateMessageModifyMagazineAmmoInCargo,
    CreateMessageSetUnitLoadOutFromClassName,
    CreateMessageSetUnitLoadOutFromRawData,
    CreateMessageAssignItemToSlot,
    CreateMessageUnAssignItemFromSlot,
    CreateMessageOfferItemFromBody,
    CreateMessageLinkNewContainer,
    CreateMessageReplaceContainer,
    CreateMessageAddMagazineCargo,
    CreateMessageAddBackpackCargo,
    CreateMessageRemoveBackpackCargo,
    CreateMessageRemoveMagazineCargo,
    CreateMessageAddMagazine,
    CreateMessageRemoveMagazine,
    CreateMessageVehicleInit,
    CreateMessageVehicleDestroyed,
    CreateMessageStoreCreatedSite,
    CreateMessageDeleteCreatedSite,
    CreateMessageRunInitSitesScript,
    CreateMessageMarkerCreate,
    CreateMessageMarkerDelete,
    CreateMessageMarkerUpdate,
    CreateMessageSetFlagOwner,
    CreateMessageSetFlagCarrier,
    CreateMessageMsgVTarget,
    CreateMessageMsgVFire,
    CreateMessageMsgVMove,
    CreateMessageMsgVFormation,
    CreateMessageMsgVSimpleCommand,
    CreateMessageMsgVLoad,
    CreateMessageMsgVAzimut,
    CreateMessageMsgVStopTurning,
    CreateMessageMsgVFireFailed,
    CreateMessageChangeOwner,
    CreateMessagePlaySound,
    CreateMessageDeleteObject,
    CreateMessageDeleteCommand,
    CreateMessageCreateObject,
    CreateMessageUpdateObject,
    CreateMessageCreateVehicle,
    CreateMessageUpdateVehicle,
    CreateMessageUpdatePositionVehicle,
    CreateMessageCreateDetector,
    CreateMessageUpdateDetector,
    CreateMessageUpdateFlag,
    CreateMessageCreateShot,
    CreateMessageUpdateShot,
    CreateMessageCreateCrater,
    CreateMessageCreateCraterOnVehicle,
    CreateMessageCreateObjectDestructed,
    CreateMessageCreateAICenter,
    CreateMessageUpdateAICenter,
    CreateMessageCreateAIGroup,
    CreateMessageUpdateAIGroup,
    CreateMessageUnitSlot,
    CreateMessageWaypoint,
    CreateMessageCreateAISubgroup,
    CreateMessageUpdateAISubgroup,
    CreateMessageCreateAIBrain,
    CreateMessageUpdateAIBrain,
    CreateMessageUpdateAIBrainPath,
    CreateMessageCreateAIUnit,
    CreateMessageUpdateAIUnit,
    CreateMessageUpdateAIUnitPath,
    CreateMessageCreateAIAgent,
    CreateMessageUpdateAIAgent,
    CreateMessageUpdateAIAgentPath,
    CreateMessageCreateCommand,
    CreateMessageUpdateCommand,
    CreateMessageUpdateVehicleAI,
    CreateMessageUpdateVehicleAIFull,
    CreateMessageUpdateVehicleBrain,
    CreateMessageUpdateTransport,
    CreateMessageUpdateAnimal,
    CreateMessageUpdatePositionAnimal,
    CreateMessageUpdateMan,
    CreateMessageUpdatePositionMan,
    CreateMessageUpdateTankOrCar,
    CreateMessageUpdateTank,
    CreateMessageUpdatePositionTank,
    CreateMessageUpdateTurret,
    CreateMessageUpdateCar,
    CreateMessageUpdatePositionCar,
    CreateMessageUpdateAirplane,
    CreateMessageUpdatePositionAirplane,
    CreateMessageUpdateHelicopter,
    CreateMessageUpdatePositionHelicopter,
    CreateMessageUpdateParachute,
    CreateMessageUpdateParaglide,
    CreateMessageUpdateShip,
    CreateMessageUpdatePositionShip,
    CreateMessageMagazine,
    CreateMessageNetWeaponInfo,
    CreateMessageNetMuzzleInfo,
    CreateMessageContainerRawData,
    CreateMessageMagazineString,
    CreateMessageCountedString,
    CreateMessageCountedWeaponsString,
    CreateMessagePersonInventoryDescriptor,
    CreateMessagePathPoint,
    CreateMessageUpdateMotorcycle,
    CreateMessageUpdatePositionMotorcycle,
    CreateMessageAskForHideBody,
    CreateMessageNetworkCommand,
    CreateMessageIntegrityQuestion,
    CreateMessageIntegrityAnswer,
    CreateMessageUpdateSeagull,
    CreateMessageUpdatePositionSeagull,
    CreateMessagePlayerUpdate,
    CreateMessageUpdateDamageVehicleAI,
    CreateMessageUpdateDamageObject,
    CreateMessageCreateHelicopter,
    CreateMessageUpdateClientInfo,
    CreateMessageShowTarget,
    CreateMessageShowSuppressTarget,
    CreateMessageGroupSynchronization,
    CreateMessageDetectorActivation,
    CreateMessageAskForCreateUnit,
    CreateMessageAskForDeleteVehicle,
    CreateMessageAskForReceiveUnitAnswer,
    CreateMessageAskForGroupRespawn,
    CreateMessageGroupRespawnDone,
    CreateMessageMissionParams,
    CreateMessageUpdateMine,
    CreateMessageAskForActivateMine,
    CreateMessageAskForDetectedMine,
    CreateMessageDisposeObject,
    CreateMessageVehicleDamaged,
    CreateMessageUpdateFireplace,
    CreateMessageAskForInflameFire,
    CreateMessageAskForAnimationPhase,
    CreateMessageIncomingMissile,
    CreateMessageLaunchedCounterMeasures,
    CreateMessageSharedMineUsed,
    CreateMessageSetShotParents,
    CreateMessageWeaponLocked,
    CreateMessageForceDeleteObject,
    CreateMessageJoinIntoUnit,
    CreateMessageAIStatsMPRowCreate,
    CreateMessageAIStatsMPRowUpdate,
    CreateMessageUpdateSupply,
    CreateMessageWeatherCreate,
    CreateMessageWeatherUpdate,
    CreateMessageMuteList,
    CreateMessageVoiceOn,
    CreateMessageCleanupPlayer,
    CreateMessageLockGearItem,
    CreateMessageUnlockGearItem,
    CreateMessageAskItem,
    CreateMessageAskWeapon,
    CreateMessageAskMagazine,
    CreateMessageAskBackpack,
    CreateMessageReplaceItem,
    CreateMessageStorePendingItem,
    CreateMessageReplaceWeapon,
    CreateMessageReplaceMagazine,
    CreateMessageReplaceBackpack,
    CreateMessageReturnWeapon,
    CreateMessageReturnMagazine,
    CreateMessageReturnBackpack,
    CreateMessageCancelTakeFlag,
    CreateMessagePoolAskWeapon,
    CreateMessagePoolAskMagazine,
    CreateMessagePoolAskBackpack,
    CreateMessagePoolReplaceWeapon,
    CreateMessagePoolReplaceMagazine,
    CreateMessagePoolReplaceBackpack,
    CreateMessagePoolReturnWeapon,
    CreateMessagePoolReturnMagazine,
    CreateMessagePoolReturnBackpack,
    CreateMessageAskSetUnitLoadOutFromClassName,
    CreateMessageAskSetUnitLoadOutFromRawData,
    CreateMessageUpdateWeaponsInfo,
    CreateMessageUpdateWeaponSlotsData,
    CreateMessageUpdateWeaponsPool,
    CreateMessageUpdateMagazinesPool,
    CreateMessageUpdateBackpacksPool,
    CreateMessageMarker,
    CreateMessageSite,
    CreateMessageEffects,
    CreateMessageUpdateSlotMgr,
    CreateMessageUpdateEntityAIWeapons,
    CreateMessageSetRoleIndex,
    CreateMessageCreateSeagull,
    CreateMessageMsgVLoadMagazine,
    CreateMessageMsgVWatchTgt,
    CreateMessageMsgVWatchPos,
    CreateMessageRevealTarget,
    CreateMessageCreateDynSoundSource,
    CreateMessageCreateDestructionEffects,
    CreateMessageRemoteMuteList,
    CreateMessageAskForApplyDoDamage,
    CreateMessageAskForApplyBleeding,
    CreateMessageAskForStatsWrite,
    CreateMessageLocalizedChat,
    CreateMessageCreateTurret,
    CreateMessageVoteMission,
    CreateMessageVotingMissionProgress,
    CreateMessagePlayerBan,
    CreateMessagePlayerBanSelf,
    CreateMessageServerTimeout,
    CreateMessageAcceptedKey,
    CreateMessageAdditionalSignedFiles,
    CreateMessageDataSignatureAsk,
    CreateMessageDataSignatureAnswer,
    CreateMessageHackedData,
    CreateMessageCreateAITeam,
    CreateMessageUpdateAITeam,
    CreateMessageUpdatePositionTurret,
    CreateMessageStaticObjectDestructed,
    CreateMessageAskConnectVoice,
    CreateMessageConnectVoiceDirect,
    CreateMessageConnectVoiceNatNeg,
    CreateMessageDisconnect,
    CreateMessageWaypointCreate,
    CreateMessageWaypointUpdate,
    CreateMessageWaypointDelete,
    CreateMessageHCSetGroup,
    CreateMessageHCRemoveGroup,
    CreateMessageHCClearGroups,
    CreateMessageMissionStats,
    CreateMessageAskForFireWeapon,
    CreateMessageAskForGetInWantsPlayer,
    CreateMessageAskForOrderGetIn,
    CreateMessageAskForAllowGetIn,
    CreateMessageAskForAirportSetSide,
    CreateMessageAskForArbitration,
    CreateMessageUpdateDamageVehicle,
    CreateMessageBattlEye,
    CreateMessageAskForTeamSwitch,
    CreateMessageTeamSwitchResult,
    CreateMessageFinishTeamSwitch,
    CreateMessageKBReact,
    CreateMessageObjectSetVariable,
    CreateMessageObjectSetVariablesCollection,
    CreateMessageWaypointsCopy,
    CreateMessageAttachObject,
    CreateMessageDetachObject,
    CreateMessageGroupSetVariable,
    CreateMessageCustomFile,
    CreateMessageCustomFileList,
    CreateMessageCustomFilesWanted,
    CreateMessageDeleteCustomFiles,
    CreateMessagePlayerRoleUpdate,
    CreateMessageNatNegResult,
    CreateMessageUpdateClientInfoDpid,
    CreateMessageServerTime,
    CreateMessageUpdateDoor,
    CreateMessageUpdatePositionDoor,
    CreateMessageGroupSetUnconsciousLeader,
    CreateMessageGroupSelectLeader,
    CreateMessageAskForAssignTeam,
    CreateMessageLoadedFromSave,
    CreateMessageServerDifficulty,
    CreateMessageServerAdmin,
    CreateMessageTakeBackpack,
    CreateMessageAssemble,
    CreateMessageDisAssemble,
    CreateMessageAskProcessDisAssemble,
    CreateMessageShowGroupDir,
    CreateMessageAskForSetMaxHitZoneDamage,
    CreateMessageAskForEnableVMode,
    CreateMessageAskForForceGunLight,
    CreateMessageAskForIRLaser,
    CreateMessageAskForVehicleDoorState,
    CreateMessageAskForChangeSide,
    CreateMessageVehMPEventHandlers,
    CreateMessageVehMPEvent,
    CreateMessageMissionMPEvent,
    CreateMessageRemoteEntityEvent,
    CreateMessageClearWeaponCargo,
    CreateMessageClearItemCargo,
    CreateMessageClearMagazineCargo,
    CreateMessageClearBackpackCargo,
    CreateMessageCreateClientCameraPosition,
    CreateMessageUpdateClientCameraPosition,
    CreateMessageCreatePlayerRuntime,
    CreateMessageUpdatePlayerRuntime,
    CreateMessageAskRemoteControlled,
    CreateMessageAskForSetRank,
    CreateMessageAskForVehicleControl,
    CreateMessageOwnerChanged,
    CreateMessageLastOperPos,
    CreateMessageFileSignatureAsk,
    CreateMessageFileSignatureAnswer,
    CreateMessageChangeCreatorId,
    CreateMessageAskForAllowCrewInImmobile,
    CreateMessageAskForPilotLight,
    CreateMessageCreateRadioChannel,
    CreateMessageRadioChannelLabel,
    CreateMessageRadioChannelCallSign,
    CreateMessageRadioChannelUnits,
    CreateMessageSendAUMsg,
    CreateMessageLockSupply,
    CreateMessageUnlockSupply,
    CreateMessageReturnEquipment,
    CreateMessageServerInfo,
    CreateMessagePublicVariableTo,
    CreateMessageUavTerminalCreateConnection,
    CreateMessageUpdateInvisibleVehicle,
    CreateMessageRadioChatBroadcast,
    CreateMessageSetObjectTexture,
    CreateMessageForceFlagTexture,
    CreateMessageAddSideScore,
    CreateMessageAskForSetVisibility,
    CreateMessageAskForEnableSimulation,
    CreateMessageAskForRemoveFromCenter,
    CreateMessageAskForForceWeatherUpdate,
    CreateMessageAskForSetPlanningMode,
    CreateMessageAskForDisconnectUav,
    CreateMessageUavTerminalReleaseConnection,
    CreateMessageAskForSetRemoveMode,
    CreateMessageSetParticleClass,
    CreateMessageAskForCreateAndAddBackpack,
    CreateMessageAskForDeleteBackpack,
    CreateMessageAskForDeleteGroup,
    CreateMessageStartWeaponDeploy,
    CreateMessageStopWeaponDeploy,
    CreateMessageUpdatePositionTankOrCar,
    CreateMessageAskRemoteExecServer,
    CreateMessageAskRemoteExecServerNamed,
    CreateMessageAskRemoteExecClient,
    CreateMessageRemoteExecServer,
    CreateMessageRemoteExecClient,
    CreateMessageRemoteExecUnJIP,
    CreateMessageNamespaceSetVariable,
    CreateMessageAskRemoteExecClientOne,
    CreateMessageSetGroupIdentity,
    CreateMessageRemoteExecServerExt,
    CreateMessageRemoteExecClientExt,
    CreateMessageRemoteExecClientMulti,
    CreateMessageSetObjectMaterial,
    CreateMessageObjectSetVariableClient,
    CreateMessageObjectSetVariableExt,
    CreateMessageObjectSetVariableExtArray,
    CreateMessageGroupSetVariableClient,
    CreateMessageGroupSetVariableExt,
    CreateMessageGroupSetVariableExtArray,
    CreateMessageTeamMemberSetVariableExt,
    CreateMessageTeamMemberSetVariableExtArray,
    CreateMessageNamespaceSetVariableExt,
    CreateMessageNamespaceSetVariableExtArray,
    CreateMessageSetVisibility,
    CreateMessageSyncVarsInJIPQueue,
    CreateMessagePublicKey,
    CreateMessagePublicKeyAck,
    CreateMessagePublicKeyBE,
    CreateMessagePublicKeyAckBE,
    CreateMessageCreateEntitySimple,
    CreateMessageObjHideAnimSection,
    CreateMessageUpdateProfessionStats,
    CreateMessageAskRemoteExecServerNamedObjGrp,
    CreateMessageRemoteExecUnJIPObjGrp,
    CreateMessageTransferFileAck,
    CreateMessageAskForEnableActiveSensors,
    CreateMessageAskForApplyObjectFlag,
    CreateMessageAskForceAIActiveSensors,
    CreateMessageAskSetReportRemoteTargets,
    CreateMessageAskSetReceiveRemoteTargets,
    CreateMessageAskSetReportOwnPosition,
    CreateMessageAddEPEForce,
    CreateMessageAddEPETorque,
    CreateMessageBankCount,
    CreateMessagePlayerBE,
    CreateMessageAskForGetOutToPos,
    CreateMessageDataHashCheckAsk,
    CreateMessageDataHashCheckAnswer,
    CreateMessageTransferDataHashCheck,
    CreateMessageAskCheckCmdPwd,
    CreateMessageAcceptCheckCmdPwd,
    CreateMessageDenyCheckCmdPwd,
    CreateMessageUpdateCuratorCommander,
    CreateMessageAskForJoinCuratorCommander,
    CreateMessageAskForJoinCuratorLogic,
    CreateMessageAskForChangeCuratorPoints,
    CreateMessageAskForAddCuratorEditableUnit,
    CreateMessageAskForAddCuratorArea,
    CreateMessageAskForRemoveCuratorArea,
    CreateMessageAskForChangeCuratorCameraMoveCeiling,
    CreateMessageAskForSetCuratorActionCoef,
    CreateMessageAskForSetCuratorWaypointCost,
    CreateMessageAskForModifyCuratorAllowedAddons,
    CreateMessageAskForChangeCuratorEditAreaType,
    CreateMessageAskForPingCurator,
    CreateMessageCreateJointConnection,
    CreateMessageAttachEPE,
    CreateMessageDetachEPE,
    CreateMessageUpdateSmokeEPE,
    CreateMessagePolymorphPosition,
    CreateMessageJointParameters,
    CreateMessageChangeVisibilityAI,
    CreateMessageUpdateRagdollMan,
    CreateMessageRagdollRequested,
    CreateMessageRagdollSyncAll,
    CreateMessageRagdollShotImpact,
    CreateMessageJointDescription,
    CreateMessageJointDOFs,
    CreateMessageJointDrives,
    CreateMessageJointLimits,
    CreateMessageCreateHelicopterRTD,
    CreateMessageUpdateHelicopterRTD,
    CreateMessageUpdatePositionHelicopterRTD,
    CreateMessageCreateRopeObject,
    CreateMessageUpdateRopeObject,
    CreateMessageUpdatePositionRopeObject,
    CreateMessageAskForEnableRopeAttach,
    CreateMessageAskForSlingLoadingAction,
    CreateMessageAskForRopeCut,
    CreateMessageUpdateAnimationsVehicle,
    CreateMessageUpdateAnimationsMan,
    CreateMessageUpdatePersonGear,
    CreateMessageUpdatePersonWeapons,
    CreateMessageAskUpdatePersonWeapons,
    CreateMessageUpdateTransportGear,
    CreateMessageUpdateTransportWeapons,
    CreateMessageAskUpdateTransportWeapons,
    CreateMessageUpdateTurretGear,
    CreateMessageUpdateTurretWeapons,
    CreateMessageAskUpdateTurretWeapons,
    CreateMessageLoadVehicleInVehicle,
    CreateMessageUnloadVehicleInVehicle,
    CreateMessageAskForEnableVehicleTransporting,
    CreateMessageTacticalPing,
};
