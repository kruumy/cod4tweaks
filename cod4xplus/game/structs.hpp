#pragma once


#define	MAX_STRING_CHARS	1024	

namespace game::structs
{
	enum trType_t
	{
		TR_STATIONARY = 0x0,
		TR_INTERPOLATE = 0x1,
		TR_LINEAR = 0x2,
		TR_LINEAR_STOP = 0x3,
		TR_SINE = 0x4,
		TR_GRAVITY = 0x5,
		TR_ACCELERATE = 0x6,
		TR_DECELERATE = 0x7,
		TR_PHYSICS = 0x8,
		TR_FIRST_RAGDOLL = 0x9,
		TR_RAGDOLL = 0x9,
		TR_RAGDOLL_GRAVITY = 0xA,
		TR_RAGDOLL_INTERPOLATE = 0xB,
		TR_LAST_RAGDOLL = 0xB,
	};
	struct trajectory_t
	{
		trType_t trType;
		int trTime;
		int trDuration;
		float trBase[3];
		float trDelta[3];
	};

	struct LerpEntityStateEarthquake
	{
		float scale;
		float radius;
		int duration;
	};

	struct LerpEntityStateLoopFx
	{
		float cullDist;
		int period;
	};

	struct LerpEntityStateCustomExplode
	{
		int startTime;
	};

	struct LerpEntityStateTurret
	{
		float gunAngles[3];
	};

	struct LerpEntityStateExplosion
	{
		float innerRadius;
		float magnitude;
	};

	struct LerpEntityStateBulletHit
	{
		float start[3];
	};

	struct LerpEntityStatePrimaryLight
	{
		char colorAndExp[4];
		float intensity;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
	};

	struct LerpEntityStatePlayer
	{
		float leanf;
		int movementDir;
	};

	struct LerpEntityStateVehicle
	{
		float bodyPitch;
		float bodyRoll;
		float steerYaw;
		int materialTime;
		float gunPitch;
		float gunYaw;
		int teamAndOwnerIndex;
	};

	struct LerpEntityStateMissile
	{
		int launchTime;
	};

	struct LerpEntityStateSoundBlend
	{
		float lerp;
	};

	struct LerpEntityStateExplosionJolt
	{
		float innerRadius;
		float impulse[3];
	};

	struct LerpEntityStatePhysicsJitter
	{
		float innerRadius;
		float minDisplacement;
		float maxDisplacement;
	};

	struct LerpEntityStateAnonymous
	{
		int data[7];
	};

	union LerpEntityStateTypeUnion
	{
		LerpEntityStateTurret turret;
		LerpEntityStateLoopFx loopFx;
		LerpEntityStatePrimaryLight primaryLight;
		LerpEntityStatePlayer player;
		LerpEntityStateVehicle vehicle;
		LerpEntityStateMissile missile;
		LerpEntityStateSoundBlend soundBlend;
		LerpEntityStateBulletHit bulletHit;
		LerpEntityStateEarthquake earthquake;
		LerpEntityStateCustomExplode customExplode;
		LerpEntityStateExplosion explosion;
		LerpEntityStateExplosionJolt explosionJolt;
		LerpEntityStatePhysicsJitter physicsJitter;
		LerpEntityStateAnonymous anonymous;
	};

	struct LerpEntityState
	{
		int eFlags;
		trajectory_t pos;
		trajectory_t apos;
		LerpEntityStateTypeUnion u;
	};

	struct EntHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	struct entityShared_t
	{
		char linked;
		char bmodel;
		char svFlags;
		int clientMask[2];
		char inuse;
		int broadcastTime;
		float mins[3];
		float maxs[3];
		int contents;
		float absmin[3];
		float absmax[3];
		float currentOrigin[3];
		float currentAngles[3];
		EntHandle ownerNum;
		int eventTime;
	};

	struct entityState_s
	{
		int number;
		int eType;
		LerpEntityState lerp;
		int time2;
		int otherEntityNum;
		int attackerEntityNum;
		int groundEntityNum;
		int loopSound;
		int surfType;
		int index;
		int clientNum;
		int iHeadIcon;
		int iHeadIconTeam;
		int solid;
		unsigned int eventParm;
		int eventSequence;
		int events[4];
		int eventParms[4];
		int weapon;
		int weaponModel;
		int legsAnim;
		int torsoAnim;
		int indexUnion1;
		int indexUnion2;
		float fTorsoPitch;
		float fWaistPitch;
		unsigned int partBits[4];
	};

	struct $C96EA5EC2ACBB9C0BF22693F316ACC67
	{
		char r;
		char g;
		char b;
		char a;
	};


	union hudelem_color_t
	{
		$C96EA5EC2ACBB9C0BF22693F316ACC67 __s0;
		int rgba;
	};

	enum he_type_t
	{
		HE_TYPE_FREE = 0x0,
		HE_TYPE_TEXT = 0x1,
		HE_TYPE_VALUE = 0x2,
		HE_TYPE_PLAYERNAME = 0x3,
		HE_TYPE_MAPNAME = 0x4,
		HE_TYPE_GAMETYPE = 0x5,
		HE_TYPE_MATERIAL = 0x6,
		HE_TYPE_TIMER_DOWN = 0x7,
		HE_TYPE_TIMER_UP = 0x8,
		HE_TYPE_TENTHS_TIMER_DOWN = 0x9,
		HE_TYPE_TENTHS_TIMER_UP = 0xA,
		HE_TYPE_CLOCK_DOWN = 0xB,
		HE_TYPE_CLOCK_UP = 0xC,
		HE_TYPE_WAYPOINT = 0xD,
		HE_TYPE_COUNT = 0xE,
	};

	struct hudelem_s
	{
		he_type_t type;
		float x;
		float y;
		float z;
		int targetEntNum;
		float fontScale;
		int font;
		int alignOrg;
		int alignScreen;
		hudelem_color_t color;
		hudelem_color_t fromColor;
		int fadeStartTime;
		int fadeTime;
		int label;
		int width;
		int height;
		int materialIndex;
		int offscreenMaterialIdx;
		int fromWidth;
		int fromHeight;
		int scaleStartTime;
		int scaleTime;
		float fromX;
		float fromY;
		int fromAlignOrg;
		int fromAlignScreen;
		int moveStartTime;
		int moveTime;
		int time;
		int duration;
		float value;
		int text;
		float sort;
		hudelem_color_t glowColor;
		int fxBirthTime;
		int fxLetterTime;
		int fxDecayStartTime;
		int fxDecayDuration;
		int soundID;
		int flags;
	};


	struct $15067B6A14D88D7E1E730369692C3A81
	{
		hudelem_s current[31];
		hudelem_s archival[31];
	};

	enum OffhandSecondaryClass
	{
		PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
		PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
		PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
	};

	enum ViewLockTypes
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	};

	struct SprintState
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	};

	struct MantleState
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};

	enum objectiveState_t
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_DONE = 0x3,
		OBJST_CURRENT = 0x4,
		OBJST_FAILED = 0x5,
		OBJST_NUMSTATES = 0x6,
	};

	struct objective_t
	{
		objectiveState_t state;
		float origin[3];
		int entNum;
		int teamNum;
		int icon;
	};

	enum ActionSlotType
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	};

	struct ActionSlotParam_SpecifyWeapon
	{
		unsigned int index;
	};

	struct ActionSlotParam
	{
		ActionSlotParam_SpecifyWeapon specifyWeapon;
	};


	struct playerState_s
	{
		int commandTime;
		int pm_type;
		int bobCycle;
		int pm_flags;
		int weapFlags;
		int otherFlags;
		int pm_time;
		float origin[3];
		float velocity[3];
		float oldVelocity[2];
		int weaponTime;
		int weaponDelay;
		int grenadeTimeLeft;
		int throwBackGrenadeOwner;
		int throwBackGrenadeTimeLeft;
		int weaponRestrictKickTime;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		float delta_angles[3];
		int groundEntityNum;
		float vLadderVec[3];
		int jumpTime;
		float jumpOriginZ;
		int legsTimer;
		int legsAnim;
		int torsoTimer;
		int torsoAnim;
		int legsAnimDuration;
		int torsoAnimDuration;
		int damageTimer;
		int damageDuration;
		int flinchYawAnim;
		int movementDir;
		int eFlags;
		int eventSequence;
		int events[4];
		unsigned int eventParms[4];
		int oldEventSequence;
		int clientNum;
		int offHandIndex;
		OffhandSecondaryClass offhandSecondary;
		unsigned int weapon;
		int weaponstate;
		unsigned int weaponShotCount;
		float fWeaponPosFrac;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		int viewmodelIndex;
		float viewangles[3];
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		float viewAngleClampBase[2];
		float viewAngleClampRange[2];
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int stats[5];
		int ammo[128];
		int ammoclip[128];
		unsigned int weapons[4];
		unsigned int weaponold[4];
		unsigned int weaponrechamber[4];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		ViewLockTypes viewlocked;
		int viewlocked_entNum;
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int iCompassPlayerInfo;
		int radarEnabled;
		int locationSelectionInfo;
		SprintState sprintState;
		float fTorsoPitch;
		float fWaistPitch;
		float holdBreathScale;
		int holdBreathTimer;
		float moveSpeedScaleMultiplier;
		MantleState mantleState;
		float meleeChargeYaw;
		int meleeChargeDist;
		int meleeChargeTime;
		int perks;
		ActionSlotType actionSlotType[4];
		ActionSlotParam actionSlotParam[4];
		int entityEventSequence;
		int weapAnim;
		float aimSpreadScale;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		int hudElemLastAssignedSoundID;
		objective_t objective[16];
		char weaponmodels[128];
		int deltaTime;
		int killCamEntity;
		$15067B6A14D88D7E1E730369692C3A81 hud;
	};

	enum sessionState_t
	{
		SESS_STATE_PLAYING = 0x0,
		SESS_STATE_DEAD = 0x1,
		SESS_STATE_SPECTATOR = 0x2,
		SESS_STATE_INTERMISSION = 0x3,
	};
	enum clientConnected_t
	{
		CON_DISCONNECTED = 0x0,
		CON_CONNECTING = 0x1,
		CON_CONNECTED = 0x2,
	};
	struct usercmd_s
	{
		int serverTime;
		int buttons;
		int angles[3];
		char weapon;
		char offHandIndex;
		char forwardmove; //buttonsVertical
		char rightmove; //buttonsHorizontal
		float meleeChargeYaw;
		char meleeChargeDist;
		char selectedLocation[2];
	};
	struct playerTeamState_t
	{
		int location;
	};

	enum team_t
	{
		TEAM_FREE = 0x0,
		TEAM_AXIS = 0x1,
		TEAM_ALLIES = 0x2,
		TEAM_SPECTATOR = 0x3,
		TEAM_NUM_TEAMS = 0x4,
	};


	struct clientState_s
	{
		int clientIndex;
		team_t team;
		int modelindex;
		int attachModelIndex[6];
		int attachTagIndex[6];
		char name[16];
		float maxSprintTimeMultiplier;
		int rank;
		int prestige;
		int perks;
		int attachedVehEntNum;
		int attachedVehSlotIndex;
	};

	struct clientSession_t
	{
		sessionState_t sessionState;
		int forceSpectatorClient;
		int killCamEntity;
		int status_icon;
		int archiveTime;
		int score;
		int deaths;
		int kills;
		int assists;
		unsigned __int16 scriptPersId;
		clientConnected_t connected;
		usercmd_s cmd;
		usercmd_s oldcmd;
		int localClient;
		int predictItemPickup;
		char newnetname[16];
		int maxHealth;
		int enterTime;
		playerTeamState_t teamState;
		int voteCount;
		int teamVoteCount;
		float moveSpeedScaleMultiplier;
		int viewmodelIndex;
		int noSpectate;
		int teamInfo;
		clientState_s cs;
		int psOffsetTime;
	};

	struct gclient_s
	{
		playerState_s ps;
		clientSession_t sess;
		int spectatorClient;
		int noclip;
		int ufo;
		int bFrozen;
		int lastCmdTime;
		int buttons;
		int oldbuttons;
		int latched_buttons;
		int buttonsSinceLastFrame;
		float oldOrigin[3];
		float fGunPitch;
		float fGunYaw;
		int damage_blood;
		float damage_from[3];
		int damage_fromWorld;
		int accurateCount;
		int accuracy_shots;
		int accuracy_hits;
		int inactivityTime;
		int inactivityWarning;
		int lastVoiceTime;
		int switchTeamTime;
		float currentAimSpreadScale;
		struct gentity_s* persistantPowerup;
		int portalID;
		int dropWeaponTime;
		int sniperRifleFiredTime;
		float sniperRifleMuzzleYaw;
		int PCSpecialPickedUpCount;
		EntHandle useHoldEntity;
		int useHoldTime;
		int useButtonDone;
		int iLastCompassPlayerInfoEnt;
		int compassPingTime;
		int damageTime;
		float v_dmg_roll;
		float v_dmg_pitch;
		float swayViewAngles[3];
		float swayOffset[3];
		float swayAngles[3];
		float vLastMoveAng[3];
		float fLastIdleFactor;
		float vGunOffset[3];
		float vGunSpeed[3];
		int weapIdleTime;
		int lastServerTime;
		int lastSpawnTime;
		unsigned int lastWeapon;
		bool previouslyFiring;
		bool previouslyUsingNightVision;
		bool previouslySprinting;
		int hasRadar;
		int lastStand;
		int lastStandTime;
	};

	struct turretInfo_s
	{
		int inuse;
		int flags;
		int fireTime;
		float arcmin[2];
		float arcmax[2];
		float dropPitch;
		int stance;
		int prevStance;
		int fireSndDelay;
		float userOrigin[3];
		float playerSpread;
		float pitchCap;
		int triggerDown;
		char fireSnd;
		char fireSndPlayer;
		char stopSnd;
		char stopSndPlayer;
	};

	struct scr_vehicle_s
	{
		/*vehicle_pathpos_t pathPos;
		vehicle_physic_t phys;
		int entNum;
		__int16 infoIdx;
		int flags;
		int team;
		VehicleMoveState moveState;
		__int16 waitNode;
		float waitSpeed;
		VehicleTurret turret;
		VehicleJitter jitter;
		VehicleHover hover;
		int drawOnCompass;
		unsigned __int16 lookAtText0;
		unsigned __int16 lookAtText1;
		int manualMode;
		float manualSpeed;
		float manualAccel;
		float manualDecel;
		float manualTime;
		float speed;
		float maxDragSpeed;
		float turningAbility;
		int hasTarget;
		int hasTargetYaw;
		int hasGoalYaw;
		int stopAtGoal;
		int stopping;
		int targetEnt;
		EntHandle lookAtEnt;
		float targetOrigin[3];
		float targetOffset[3];
		float targetYaw;
		float goalPosition[3];
		float goalYaw;
		float prevGoalYaw;
		float yawOverShoot;
		int yawSlowDown;
		float nearGoalNotifyDist;
		float joltDir[2];
		float joltTime;
		float joltWave;
		float joltSpeed;
		float joltDecel;
		int playEngineSound;
		EntHandle idleSndEnt;
		EntHandle engineSndEnt;
		float idleSndLerp;
		float engineSndLerp;
		VehicleTags boneIndex;
		int turretHitNum;
		float forcedMaterialSpeed;*/
	};

	struct item_ent_t
	{
		int ammoCount;
		int clipAmmoCount;
		int index;
	};

	struct __declspec(align(4)) trigger_ent_t
	{
		int threshold;
		int accumulate;
		int timestamp;
		int singleUserEntIndex;
		bool requireLookAt;
	};

	struct mover_ent_t
	{
		float decelTime;
		float aDecelTime;
		float speed;
		float aSpeed;
		float midTime;
		float aMidTime;
		float pos1[3];
		float pos2[3];
		float pos3[3];
		float apos1[3];
		float apos2[3];
		float apos3[3];
	};

	struct corpse_ent_t
	{
		int deathAnimStartTime;
	};

	enum MissileStage
	{
		MISSILESTAGE_SOFTLAUNCH = 0x0,
		MISSILESTAGE_ASCENT = 0x1,
		MISSILESTAGE_DESCENT = 0x2,
	};

	enum MissileFlightMode
	{
		MISSILEFLIGHTMODE_TOP = 0x0,
		MISSILEFLIGHTMODE_DIRECT = 0x1,
	};

	struct missile_ent_t
	{
		float time;
		int timeOfBirth;
		float travelDist;
		float surfaceNormal[3];
		team_t team;
		float curvature[3];
		float targetOffset[3];
		MissileStage stage;
		MissileFlightMode flightMode;
	};

	union $73EC31463AB2E2014DA76FFB3C0281FF
	{
		item_ent_t item[2];
		trigger_ent_t trigger;
		mover_ent_t mover;
		corpse_ent_t corpse;
		missile_ent_t missile;
	};

	struct tagInfo_s
	{
		struct gentity_s* parent;
		struct gentity_s* next;
		unsigned __int16 name;
		int index;
		float axis[4][3];
		float parentInvAxis[4][3];
	};

	struct gentity_s
	{
		entityState_s s;
		entityShared_t r;
		gclient_s* client;
		turretInfo_s* pTurretInfo;
		scr_vehicle_s* scr_vehicle;
		unsigned __int16 model;
		char physicsObject;
		char takedamage;
		char active;
		char nopickup;
		char handler;
		char team;
		unsigned __int16 classname;
		unsigned __int16 target;
		unsigned __int16 targetname;
		unsigned int attachIgnoreCollision;
		int spawnflags;
		int flags;
		int eventTime;
		int freeAfterEvent;
		int unlinkAfterEvent;
		int clipmask;
		int processedFrame;
		gentity_s* parent;
		int nextthink;
		int health;
		int maxHealth;
		int damage;
		int count;
		gentity_s* chain;
		$73EC31463AB2E2014DA76FFB3C0281FF ___u30;
		tagInfo_s* tagInfo;
		gentity_s* tagChildren;
		unsigned __int16 attachModelNames[19];
		unsigned __int16 attachTagNames[19];
		int useCount;
		gentity_s* nextFree;
	};

	enum netadrtype_t
	{
		NA_BOT = 0x0,
		NA_BAD = 0x1,
		NA_LOOPBACK = 0x2,
		NA_BROADCAST = 0x3,
		NA_IP = 0x4,
		NA_IPX = 0x5,
		NA_BROADCAST_IPX = 0x6,
	};


	struct netadr_t
	{
		netadrtype_t type;
		char ip[4];
		unsigned __int16 port;
		char ipx[10];
	};



	enum dvar_flags : unsigned short
	{
		none = 0x0,
		saved = 0x1,
		user_info = 0x2, // sent to server on connect or change
		server_info = 0x4, // sent in response to front end requests
		replicated = 0x8,
		write_protected = 0x10,
		latched = 0x20,
		read_only = 0x40,
		cheat_protected = 0x80,
		temp = 0x100,
		no_restart = 0x400, // do not clear when a cvar_restart is issued
		user_created = 0x4000, // created by a set command
	};

	enum DvarType
	{
		DVAR_TYPE_BOOL = 0x0,
		DVAR_TYPE_FLOAT = 0x1,
		DVAR_TYPE_FLOAT_2 = 0x2,
		DVAR_TYPE_FLOAT_3 = 0x3,
		DVAR_TYPE_FLOAT_4 = 0x4,
		DVAR_TYPE_INT = 0x5,
		DVAR_TYPE_ENUM = 0x6,
		DVAR_TYPE_STRING = 0x7,
		DVAR_TYPE_COLOR = 0x8,
		DVAR_TYPE_COUNT = 0x9,
	};
	struct DvarValueStringBuf
	{
		const char* pad;
		char string[12];
	};
	union DvarLimits
	{
		struct
		{
			int stringCount;
			const char** strings;
		} enumeration;

		struct
		{
			int min;
			int max;
		} integer;

		struct
		{
			float min;
			float max;
		} value;

		struct
		{
			float min;
			float max;
		} vector;
	};
	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		DvarValueStringBuf stringBuf;
		char color[4];
	};
	struct dvar_s
	{
		const char* name;
		const char* description;
		unsigned __int16 flags;
		char type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		dvar_s* next;
		dvar_s* hashNext;
	};

	struct clSnapshot_t
	{
		int valid;
		int snapFlags;
		int serverTime;
		int messageNum;
		int deltaNum;
		int ping;
		int cmdNum;
		playerState_s ps;
		int numEntities;
		int numClients;
		int parseEntitiesNum;
		int parseClientsNum;
		int serverCommandNum;
	};

	struct gameState_t
	{
		int stringOffsets[2442];
		char stringData[131072];
		int dataCount;
	};

	enum StanceState
	{
		CL_STANCE_STAND = 0x0,
		CL_STANCE_CROUCH = 0x1,
		CL_STANCE_PRONE = 0x2,
	};

	struct ClientArchiveData
	{
		int serverTime;
		float origin[3];
		float velocity[3];
		int bobCycle;
		int movementDir;
		float viewangles[3];
	};

	struct outPacket_t
	{
		int p_cmdNumber;
		int p_serverTime;
		int p_realtime;
	};

	struct clientActive_t
	{
		bool usingAds;
		int timeoutcount;
		clSnapshot_t snap;
		bool alwaysFalse;
		int serverTime;
		int oldServerTime;
		int oldFrameServerTime;
		int serverTimeDelta;
		int oldSnapServerTime;
		int extrapolatedSnapshot;
		int newSnapshots;
		gameState_t gameState;
		char mapname[64];
		int parseEntitiesNum;
		int parseClientsNum;
		int mouseDx[2];
		int mouseDy[2];
		int mouseIndex;
		bool stanceHeld;
		StanceState stance;
		StanceState stancePosition;
		int stanceTime;
		int cgameUserCmdWeapon;
		int cgameUserCmdOffHandIndex;
		float cgameFOVSensitivityScale;
		float cgameMaxPitchSpeed;
		float cgameMaxYawSpeed;
		float cgameKickAngles[3];
		float cgameOrigin[3];
		float cgameVelocity[3];
		float cgameViewangles[3];
		int cgameBobCycle;
		int cgameMovementDir;
		int cgameExtraButtons;
		int cgamePredictedDataServerTime;
		float viewangles[3];
		int serverId;
		int skelTimeStamp;
		volatile int skelMemPos;
		char skelMemory[262144];
		char* skelMemoryStart;
		bool allowedAllocSkel;
		__declspec(align(4)) usercmd_s cmds[128];
		int cmdNumber;
		ClientArchiveData clientArchive[256];
		int clientArchiveIndex;
		outPacket_t outPackets[32];
		clSnapshot_t snapshots[32];
		entityState_s entityBaselines[1024];
		entityState_s parseEntities[2048];
		clientState_s parseClients[2048];
		int corruptedTranslationFile;
		char translationVersion[256];
		float vehicleViewYaw;
		float vehicleViewPitch;
	};

	struct clientLogo_t
	{
		int startTime;
		int duration;
		int fadein;
		int fadeout;
		void* material[2];// Material*
	};

	struct serverInfo_t
	{
		struct netadr_t adrr;
		char allowAnonymous;
		char bPassword;
		char pure;
		char consoleDisabled;
		char netType;
		char clients;
		char maxClients;
		char dirty;
		char friendlyfire;
		char killcam;
		char hardware;
		char mod;
		char voice;
		char punkbuster;
		char requestCount;
		bool unk;
		__int16 unk2;
		__int16 minPing;
		__int16 maxPing;
		__int16 ping;
		char pad_0x002C[0x5]; //0x002C
		char hostName[32];
		char mapName[32];
		char game[24];
		char gameType[16];
		char pad_0x0099[0x3]; //0x0099
	}; //Size=0x009C

	struct __declspec(align(4)) vidConfig_t
	{
		unsigned int sceneWidth;
		unsigned int sceneHeight;
		unsigned int displayWidth;
		unsigned int displayHeight;
		unsigned int displayFrequency;
		int isFullscreen;
		float aspectRatioWindow;
		float aspectRatioScenePixel;
		float aspectRatioDisplayPixel;
		unsigned int maxTextureSize;
		unsigned int maxTextureMaps;
		bool deviceSupportsGamma;
	};

	struct trDebugLine_t
	{
		float start[3];
		float end[3];
		float color[4];
		int depthTest;
	};

	struct clientDebugLineInfo_t
	{
		int max;
		int num;
		trDebugLine_t* lines;
		int* durations;
	};

	struct trDebugString_t
	{
		float xyz[3];
		float color[4];
		float scale;
		char text[96];
	};


	struct clientDebugStringInfo_t
	{
		int max;
		int num;
		trDebugString_t* strings;
		int* durations;
	};

	struct clientDebug_t
	{
		int prevFromServer;
		int fromServer;
		clientDebugStringInfo_t clStrings;
		clientDebugStringInfo_t svStringsBuffer;
		clientDebugStringInfo_t svStrings;
		clientDebugLineInfo_t clLines;
		clientDebugLineInfo_t svLinesBuffer;
		clientDebugLineInfo_t svLines;
	};

	
	
	struct clientStatic_t
	{
		int quit;
		int hunkUsersStarted;
		char servername[256];
		int rendererStarted;
		int soundStarted;
		int uiStarted;
		int frametime;
		int realtime;
		int realFrametime;
		clientLogo_t logo;
		float mapCenter[3];
		int numlocalservers;
		serverInfo_t localServers[128];
		int ui_displayedServerAmount;
		int ui_totalServerAmount;
		int ui_someothercrap;
		int waitglobalserverresponse;
		int numglobalservers;
		serverInfo_t globalServers[20000];
		int numfavoriteservers;
		serverInfo_t favoriteServers[128];
		int pingUpdateSource;
		netadr_t updateServer;
		char updateChallenge[1024];
		char updateInfoString[1024];
		netadr_t authorizeServer;
		void* whiteMaterial; // Material*
		void* consoleMaterial; // Material*
		void* consoleFont; // Font_s*
		char autoupdateServerNames[5][64];
		netadr_t autoupdateServer;
		vidConfig_t vidConfig;
		clientDebug_t debug;
		int download;
		char downloadTempName[256];
		char downloadName[256];
		int downloadNumber;
		int downloadBlock;
		int downloadCount;
		int downloadSize;
		char downloadList[1024];
		int downloadRestart;
		int gameDirChanged;
		int wwwDlDisconnected;
		int wwwDlInProgress;
		int downloadFlags;
		char originalDownloadName[64];
		float debugRenderPos[3];
	};

	struct netProfilePacket_t
	{
		int iTime;
		int iSize;
		int bFragment;
	};

	struct netProfileStream_t
	{
		netProfilePacket_t packets[60];
		int iCurrPacket;
		int iBytesPerSecond;
		int iLastBPSCalcTime;
		int iCountedPackets;
		int iCountedFragments;
		int iFragmentPercentage;
		int iLargestPacket;
		int iSmallestPacket;
	};

	struct netProfileInfo_t
	{
		netProfileStream_t send;
		netProfileStream_t recieve;
	};

	enum netsrc_t
	{
		NS_CLIENT1 = 0x0,
		NS_SERVER = 0x1,
		NS_MAXCLIENTS = 0x1,
		NS_PACKET = 0x2,
	};


	struct netchan_t
	{
		int outgoingSequence;
		netsrc_t sock;
		int dropped;
		int incomingSequence;
		netadr_t remoteAddress;
		int qport;
		int fragmentSequence;
		int fragmentLength;
		char* fragmentBuffer;
		int fragmentBufferSize;
		int unsentFragments;
		int unsentFragmentStart;
		int unsentLength;
		char* unsentBuffer;
		int unsentBufferSize;
		netProfileInfo_t prof;
	};


	struct clientConnection_t
	{
		int qport;
		int clientNum;
		int lastPacketSentTime;
		int lastPacketTime;
		netadr_t serverAddress;
		int connectTime;
		int connectPacketCount;
		char serverMessage[256];
		int challenge;
		int checksumFeed;
		int reliableSequence;
		int reliableAcknowledge;
		char reliableCommands[128][1024];
		int serverMessageSequence;
		int serverCommandSequence;
		int lastExecutedServerCommand;
		char serverCommands[128][1024];
		bool isServerRestarting;
		int lastClientArchiveIndex;
		char demoName[64];
		int demorecording;
		int demoplaying;
		int isTimeDemo;
		int demowaiting;
		int firstDemoFrameSkipped;
		int demofile;
		int timeDemoLog;
		int timeDemoFrames;
		int timeDemoStart;
		int timeDemoPrev;
		int timeDemoBaseTime;
		netchan_t netchan;
		char netchanOutgoingBuffer[2048];
		char netchanIncomingBuffer[131072];
		netProfileInfo_t OOBProf;
		char statPacketsToSend;
		int statPacketSendTime[7];
	};

	enum DemoType
	{
		DEMO_TYPE_NONE = 0x0,
		DEMO_TYPE_CLIENT = 0x1,
		DEMO_TYPE_SERVER = 0x2,
	};

	enum CubemapShot
	{
		CUBEMAPSHOT_NONE = 0x0,
		CUBEMAPSHOT_RIGHT = 0x1,
		CUBEMAPSHOT_LEFT = 0x2,
		CUBEMAPSHOT_BACK = 0x3,
		CUBEMAPSHOT_FRONT = 0x4,
		CUBEMAPSHOT_UP = 0x5,
		CUBEMAPSHOT_DOWN = 0x6,
		CUBEMAPSHOT_COUNT = 0x7,
	};

	struct snapshot_s
	{
		int snapFlags;
		int ping;
		int serverTime;
		playerState_s ps;
		int numEntities;
		int numClients;
		entityState_s entities[512];
		clientState_s clients[64];
		int serverCommandSequence;
	};

	struct GfxSkinCacheEntry
	{
		unsigned int frameCount;
		int skinnedCachedOffset;
		unsigned __int16 numSkinnedVerts;
		unsigned __int16 ageCount;
	};

	struct cpose_t
	{
		unsigned __int16 lightingHandle;
		char eType;
		char eTypeUnion;
		char localClientNum;
		int cullIn;
		char isRagdoll;
		int ragdollHandle;
		int killcamRagdollHandle;
		int physObjId;
		float origin[3];
		float angles[3];
		GfxSkinCacheEntry skinCacheEntry;
		//$EAE81CC4C8A7A2F7E95AA09AC9F9F9C0 ___u12;
		char pad[0x24];
	};

	struct centity_s
	{
		cpose_t pose;
		LerpEntityState currentState;
		entityState_s nextState;
		bool nextValid;
		bool bMuzzleFlash;
		bool bTrailMade;
		int previousEventSequence;
		int miscTime;
		float lightingOrigin[3];
		void* tree; // XAnimTree_s
	};

	struct playerEntity_t
	{
		float fLastWeaponPosFrac;
		int bPositionToADS;
		float vPositionLastOrg[3];
		float fLastIdleFactor;
		float vLastMoveOrg[3];
		float vLastMoveAng[3];
	};

	struct GfxDepthOfField
	{
		float viewModelStart;
		float viewModelEnd;
		float nearStart;
		float nearEnd;
		float farStart;
		float farEnd;
		float nearBlur;
		float farBlur;
	};

	struct GfxFilm
	{
		bool enabled;
		float brightness;
		float contrast;
		float desaturation;
		bool invert;
		float tintDark[3];
		float tintLight[3];
	};

	struct GfxImageLoadDef
	{
		char levelCount;
		char flags;
		__int16 dimensions[3];
		int format;
		int resourceSize;
		char data[1];
	};

	union GfxTexture
	{
		void* basemap; // IDirect3DBaseTexture9*
		void* map; // IDirect3DTexture9*
		void* volmap; // IDirect3DVolumeTexture9*
		void* cubemap; // IDirect3DCubeTexture9* 
		GfxImageLoadDef* loadDef;
		void* data;
	};

	enum MapType
	{
		MAPTYPE_NONE = 0x0,
		MAPTYPE_INVALID1 = 0x1,
		MAPTYPE_INVALID2 = 0x2,
		MAPTYPE_2D = 0x3,
		MAPTYPE_3D = 0x4,
		MAPTYPE_CUBE = 0x5,
		MAPTYPE_COUNT = 0x6,
	};

	struct Picmip
	{
		char platform[2];
	};

	struct CardMemory
	{
		int platform[2];
	};
	struct GfxImage
	{
		MapType mapType;
		GfxTexture texture;
		Picmip picmip;
		bool noPicmip;
		char semantic;
		char track;
		CardMemory cardMemory;
		unsigned __int16 width;
		unsigned __int16 height;
		unsigned __int16 depth;
		char category;
		bool delayLoadPixels;
		const char* name;
	};

	struct __declspec(align(4)) GfxLightImage
	{
		GfxImage* image;
		char samplerState;
	};

	struct GfxLightDef
	{
		const char* name;
		GfxLightImage attenuation;
		int lmapLookupStart;
	};

	struct GfxLight
	{
		char type;
		char canUseShadowMap;
		char unused[2];
		float color[3];
		float dir[3];
		float origin[3];
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		int exponent;
		unsigned int spotShadowIndex;
		GfxLightDef* def;
	};

	struct GfxGlow
	{
		bool enabled;
		float bloomCutoff;
		float bloomDesaturation;
		float bloomIntensity;
		float radius;
	};

	struct GfxViewport
	{
		int x;
		int y;
		int width;
		int height;
	};

	struct refdef_s
	{
		unsigned int x;
		unsigned int y;
		unsigned int width;
		unsigned int height;
		float tanHalfFovX;
		float tanHalfFovY;
		float vieworg[3];
		float viewaxis[3][3];
		float viewOffset[3];
		int time;
		float zNear;
		float blurRadius;
		GfxDepthOfField dof;
		GfxFilm film;
		GfxGlow glow;
		GfxLight primaryLights[255];
		GfxViewport scissorViewport;
		bool useScissorViewport;
		int localClientNum;
	};

	struct score_t
	{
		int client;
		int score;
		int ping;
		int deaths;
		int team;
		int kills;
		int rank;
		int assists;
		void* hStatusIcon; // Material*
		void* hRankIcon; // Material*
	};

	enum InvalidCmdHintType
	{
		INVALID_CMD_NONE = 0x0,
		INVALID_CMD_NO_AMMO_BULLETS = 0x1,
		INVALID_CMD_NO_AMMO_FRAG_GRENADE = 0x2,
		INVALID_CMD_NO_AMMO_SPECIAL_GRENADE = 0x3,
		INVALID_CMD_NO_AMMO_FLASH_GRENADE = 0x4,
		INVALID_CMD_STAND_BLOCKED = 0x5,
		INVALID_CMD_CROUCH_BLOCKED = 0x6,
		INVALID_CMD_TARGET_TOO_CLOSE = 0x7,
		INVALID_CMD_LOCKON_REQUIRED = 0x8,
		INVALID_CMD_NOT_ENOUGH_CLEARANCE = 0x9,
	};

	struct viewDamage_t
	{
		int time;
		int duration;
		float yaw;
	};

	struct shellshock_t
	{
		void* parms; //shellshock_parms_t
		int startTime;
		int duration;
		int loopEndTime;
		float sensitivity;
		float viewDelta[2];
		int hasSavedScreen;
	};

	struct $F6DFD6D87F75480A1EF1906639406DF5
	{
		int time;
		int duration;
	};


	struct scr_animtree_t
	{
		void* anims; //XAnim_s
	};

	struct snd_alias_list_t
	{
		/*const char *aliasName;
		snd_alias_t *head;
		int count;*/
	};

	struct animScriptCommand_t
	{
		__int16 bodyPart[2];
		__int16 animIndex[2];
		__int16 animDuration[2];
		snd_alias_list_t* soundAlias;
	};

	struct animScriptCondition_t
	{
		int index;
		unsigned int value[2];
	};

	struct animScriptItem_t
	{
		int numConditions;
		animScriptCondition_t conditions[10];
		int numCommands;
		animScriptCommand_t commands[8];
	};

	struct animScript_t
	{
		int numItems;
		animScriptItem_t* items[128];
	};

	struct __declspec(align(8)) animation_s
	{
		char name[64];
		int initialLerp;
		float moveSpeed;
		int duration;
		int nameHash;
		int flags;
		__int64 movetype;
		int noteType;
	};

	struct __declspec(align(8)) animScriptData_t
	{
		animation_s animations[512];
		unsigned int numAnimations;
		animScript_t scriptAnims[1][43];
		animScript_t scriptCannedAnims[1][43];
		animScript_t scriptStateChange[1][1];
		animScript_t scriptEvents[21];
		animScriptItem_t scriptItems[2048];
		int numScriptItems;
		scr_animtree_t animTree;
		unsigned __int16 torsoAnim;
		unsigned __int16 legsAnim;
		unsigned __int16 turningAnim;
		snd_alias_list_t* (__cdecl* soundAlias)(const char*);
		int(__cdecl* playSoundAlias)(int, snd_alias_list_t*);
	};
	struct $0867E0FC4F8157A276DAB76B1612E229
	{
		scr_animtree_t tree;
		int torso; //scr_anim_s
		int legs; //scr_anim_s
		int turning; //scr_anim_s
	};

	struct lerpFrame_t
	{
		float yawAngle;
		int yawing;
		float pitchAngle;
		int pitching;
		int animationNumber;
		void* animation; //animation_s
		int animationTime;
		float oldFramePos[3];
		float animSpeedScale;
		int oldFrameSnapshotTime;
	};

	struct clientControllers_t
	{
		float angles[6][3];
		float tag_origin_angles[3];
		float tag_origin_offset[3];
	};

	struct __declspec(align(4)) clientInfo_t
	{
		int infoValid;
		int nextValid;
		int clientNum;
		char name[16];
		team_t team;
		team_t oldteam;
		int rank;
		int prestige;
		int perks;
		int score;
		int location;
		int health;
		char model[64];
		char attachModelNames[6][64];
		char attachTagNames[6][64];
		lerpFrame_t legs;
		lerpFrame_t torso;
		float lerpMoveDir;
		float lerpLean;
		float playerAngles[3];
		int leftHandGun;
		int dobjDirty;
		clientControllers_t control;
		unsigned int clientConditions[10][2];
		void* pXAnimTree; //XAnimTree_s
		int iDObjWeapon;
		char weaponModel;
		int stanceTransitionTime;
		int turnAnimEndTime;
		char turnAnimType;
		int attachedVehEntNum;
		int attachedVehSlotIndex;
		bool hideWeapon;
		bool usingKnife;
	};


	struct bgs_t
	{
		animScriptData_t animScriptData;
		$0867E0FC4F8157A276DAB76B1612E229 generic_human;
		int time;
		int latestSnapshotTime;
		int frametime;
		int anim_user;
		void* (__cdecl* GetXModel)(const char*); // XModel*
		void* CreateDObj; //void(__cdecl* CreateDObj)(DObjModel_s*, unsigned __int16, XAnimTree_s*, int, int, clientInfo_t*);
		unsigned __int16 AttachWeapon; //unsigned __int16 (__cdecl *AttachWeapon)(DObjModel_s *, unsigned __int16, clientInfo_t *);
		void* DObj; //DObj_s *(__cdecl *GetDObj)(int, int);
		void(__cdecl* SafeDObjFree)(int, int);
		void* (__cdecl* AllocXAnim)(int);
		clientInfo_t clientinfo[64];
	};

	struct visionSetVars_t
	{
		bool glowEnable;
		float glowBloomCutoff;
		float glowBloomDesaturation;
		float glowBloomIntensity0;
		float glowBloomIntensity1;
		float glowRadius0;
		float glowRadius1;
		float glowSkyBleedIntensity0;
		float glowSkyBleedIntensity1;
		bool filmEnable;
		float filmBrightness;
		float filmContrast;
		float filmDesaturation;
		bool filmInvert;
		float filmLightTint[3];
		float filmDarkTint[3];
	};

	enum visionSetLerpStyle_t
	{
		VISIONSETLERP_UNDEFINED = 0x0,
		VISIONSETLERP_NONE = 0x1,
		VISIONSETLERP_TO_LINEAR = 0x2,
		VISIONSETLERP_TO_SMOOTH = 0x3,
		VISIONSETLERP_BACKFORTH_LINEAR = 0x4,
		VISIONSETLERP_BACKFORTH_SMOOTH = 0x5,
	};

	struct visionSetLerpData_t
	{
		int timeStart;
		int timeDuration;
		visionSetLerpStyle_t style;
	};

	struct $BE9F66374A020A9809EEAF403416A176
	{
		float aimSpreadScale;
	};

	struct hudElemSoundInfo_t
	{
		int lastPlayedTime;
	};

	struct cg_s
	{
		int clientNum;
		int localClientNum;
		DemoType demoType;
		CubemapShot cubemapShot;
		int cubemapSize;
		int renderScreen;
		int latestSnapshotNum;
		int latestSnapshotTime;
		snapshot_s* snap;
		snapshot_s* nextSnap;
		snapshot_s activeSnapshots[2];
		float frameInterpolation;
		int frametime;
		int time;
		int oldTime;
		int physicsTime;
		int mapRestart;
		int renderingThirdPerson;
		playerState_s predictedPlayerState;
		centity_s predictedPlayerEntity;
		playerEntity_t playerEntity;
		int predictedErrorTime;
		float predictedError[3];
		float landChange;
		int landTime;
		float heightToCeiling;
		refdef_s refdef;
		float refdefViewAngles[3];
		float lastVieworg[3];
		float swayViewAngles[3];
		float swayAngles[3];
		float swayOffset[3];
		int iEntityLastType[1024];
		void* pEntityLastXModel[1024]; // XModel*
		float zoomSensitivity;
		bool isLoading;
		char objectiveText[1024];
		char scriptMainMenu[256];
		int scoresRequestTime;
		int numScores;
		int teamScores[4];
		int teamPings[4];
		int teamPlayers[4];
		score_t scores[64];
		int scoreLimit;
		int showScores;
		int scoreFadeTime;
		int scoresTop;
		int scoresOffBottom;
		int scoresBottom;
		int drawHud;
		int crosshairClientNum;
		int crosshairClientLastTime;
		int crosshairClientStartTime;
		int identifyClientNum;
		int cursorHintIcon;
		int cursorHintTime;
		int cursorHintFade;
		int cursorHintString;
		int lastClipFlashTime;
		InvalidCmdHintType invalidCmdHintType;
		int invalidCmdHintTime;
		int lastHealthPulseTime;
		int lastHealthLerpDelay;
		int lastHealthClient;
		float lastHealth;
		float healthOverlayFromAlpha;
		float healthOverlayToAlpha;
		int healthOverlayPulseTime;
		int healthOverlayPulseDuration;
		int healthOverlayPulsePhase;
		bool healthOverlayHurt;
		int healthOverlayLastHitTime;
		float healthOverlayOldHealth;
		int healthOverlayPulseIndex;
		int proneBlockedEndTime;
		int lastStance;
		int lastStanceChangeTime;
		int lastStanceFlashTime;
		int voiceTime;
		unsigned int weaponSelect;
		int weaponSelectTime;
		unsigned int weaponLatestPrimaryIdx;
		int prevViewmodelWeapon;
		int equippedOffHand;
		viewDamage_t viewDamage[8];
		int damageTime;
		float damageX;
		float damageY;
		float damageValue;
		float viewFade;
		int weapIdleTime;
		int nomarks;
		int v_dmg_time;
		float v_dmg_pitch;
		float v_dmg_roll;
		float fBobCycle;
		float xyspeed;
		float kickAVel[3];
		float kickAngles[3];
		float offsetAngles[3];
		float gunPitch;
		float gunYaw;
		float gunXOfs;
		float gunYOfs;
		float gunZOfs;
		float vGunOffset[3];
		float vGunSpeed[3];
		float viewModelAxis[4][3];
		float rumbleScale;
		float compassNorthYaw;
		float compassNorth[2];
		void* compassMapMaterial; // Material*
		float compassMapUpperLeft[2];
		float compassMapWorldSize[2];
		int compassFadeTime;
		int healthFadeTime;
		int ammoFadeTime;
		int stanceFadeTime;
		int sprintFadeTime;
		int offhandFadeTime;
		int offhandFlashTime;
		shellshock_t shellshock;
		$F6DFD6D87F75480A1EF1906639406DF5 testShock;
		int holdBreathTime;
		int holdBreathInTime;
		int holdBreathDelay;
		float holdBreathFrac;
		float radarProgress;		// correct offset
		float selectedLocation[2];
		SprintState sprintStates;	// 5 ints
		//int packetAnalysisFrameCount;
		//char bitsSent[100][13];
		//int entBitsUsed[10][18];
		//int numEntsSent[10][18];
		//int numEntFields[10][18]; ?? // 7 inbetween selectedLocation and bgs
		//int numSnapshots;
		//int adsViewErrorDone;
		//int inKillCam;
		int _unk01;
		int _unk02;
		bgs_t bgs;	// first name root
		cpose_t viewModelPose;
		visionSetVars_t visionSetPreLoaded[4];
		char visionSetPreLoadedName[4][64];
		visionSetVars_t visionSetFrom[2];
		visionSetVars_t visionSetTo[2];
		visionSetVars_t visionSetCurrent[2];
		visionSetLerpData_t visionSetLerpData[2];
		char visionNameNaked[64];
		char visionNameNight[64];
		int extraButtons;
		int lastActionSlotTime;
		bool playerTeleported;
		int stepViewStart;
		float stepViewChange;
		$BE9F66374A020A9809EEAF403416A176 lastFrame;
		hudElemSoundInfo_t hudElemSound[32];
		int vehicleFrame;
	}; // should be right


	struct Message
	{
		int startTime;
		int endTime;
	};

	struct MessageLine
	{
		int messageIndex;
		int textBufPos;
		int textBufSize;
		int typingStartTime;
		int lastTypingSoundTime;
		int flags;
	};

	struct MessageWindow
	{
		MessageLine* lines;
		Message* messages;
		char* circularTextBuffer;
		int textBufSize;
		int lineCount;
		int padding;
		int scrollTime;
		int fadeIn;
		int fadeOut;
		int textBufPos;
		int firstLineIndex;
		int activeLineCount;
		int messageIndex;
	};

	struct field_t
	{
		int cursor;
		int scroll;
		int drawWidth;
		int widthInPixels;
		float charHeight;
		int fixedSize;
		char buffer[256];
	};


	struct MessageBuffer
	{
		char gamemsgText[4][2048];
		MessageWindow gamemsgWindows[4];
		MessageLine gamemsgLines[4][12];
		Message gamemsgMessages[4][12];
		char miniconText[4096];
		MessageWindow miniconWindow;
		MessageLine miniconLines[100];
		Message miniconMessages[100];
		char errorText[1024];
		MessageWindow errorWindow;
		MessageLine errorLines[5];
		Message errorMessages[5];
	};

	struct Console
	{
		int initialized;
		MessageWindow consoleWindow;
		MessageLine consoleLines[1024];
		Message consoleMessages[1024];
		char consoleText[32768];
		char textTempLine[512];
		unsigned int lineOffset;
		int displayLineOffset;
		int prevChannel;
		bool outputVisible;
		int fontHeight;
		int visibleLineCount;
		int visiblePixelWidth;
		float screenMin[2];
		float screenMax[2];
		MessageBuffer messageBuffer[1];
		float color[4];
	};

	struct cachedSnapshot_t
	{
		int archivedFrame;
		int time;
		int num_entities;
		int first_entity;
		int num_clients;
		int first_client;
		int usesDelta;
	};

	struct statData_t
	{
		unsigned char bytedata[2000];
		int longdata[1547];
	};

	enum clientConnectState_t 
	{
		CS_FREE,		// can be reused for a new connection
		CS_ZOMBIE,		// client has been disconnected, but don't reuse
		// connection for a couple seconds
		CS_CONNECTED,		// has been assigned to a client_t, but no gamestate yet
		CS_PRIMED,		// gamestate has been sent, but client hasn't sent a usercmd
		CS_ACTIVE		// client is fully in game
	};

	struct stats_t
	{
		int checksum;
		statData_t data;
	};


	struct reliableCommands_t 
	{
		char command[MAX_STRING_CHARS];
		int cmdTime;
		int cmdType;
	};

	typedef int		fileHandle_t;


	struct clientSnapshot_t 
	{//(0x2146c);
		playerState_s	ps;			//0x2146c
		int		num_entities;
		int		num_clients;		// (0x2f68)
		int		first_entity;		// (0x2f6c)into the circular sv_packet_entities[]
		int		first_client;
		// the entities MUST be in increasing state number
		// order, otherwise the delta compression will fail
		unsigned int	messageSent;		// (0x243e0 | 0x2f74) time the message was transmitted
		unsigned int	messageAcked;		// (0x243e4 | 0x2f78) time the message was acked
		int		messageSize;		// (0x243e8 | 0x2f7c)   used to rate drop packets
		int		serverTime;
	} ;//size: 0x2f84


#pragma pack(push, 1)
	struct voices_t
	{
		char num;
		char data[256];
		int dataLen;
	};
#pragma pack(pop)

	struct client_t
	{
		clientConnectState_t state;
		int sendAsActive;
		int deltaMessage;
		bool rateDelayed;
		netchan_t netchan;
		float predictedOrigin[3];
		int predictedOriginServerTime;
		const char* dropReason;
		char userinfo[1024];
		reliableCommands_t reliableCommands[128];
		int reliableSequence;
		int reliableAcknowledge;
		int reliableSent;
		int messageAcknowledge;
		int gamestateMessageNum;
		int challenge;
		usercmd_s lastUsercmd;
		int lastClientCommand;
		char lastClientCommandString[1024];
		gentity_s* gentity;
		char shortname[16];
		int wwwDl_var01;
		char downloadName[64];
		fileHandle_t download;
		int downloadSize;
		int downloadCount;
		int downloadClientBlock;
		int downloadCurrentBlock;
		int downloadXmitBlock;
		unsigned char* downloadBlocks[8];
		int downloadBlockSize[8];
		bool downloadEOF;
		int downloadSendTime;
		char wwwDownloadURL[256];
		bool wwwDownload;
		bool wwwDownloadStarted;
		bool wwwDl_var02;
		bool wwwDl_var03;
		int nextReliableTime;
		int floodprotect;
		int lastPacketTime;
		int lastConnectTime;
		int nextSnapshotTime;
		int timeoutCount;
		clientSnapshot_t frames[32];
		int ping;
		int rate;
		int snapshotMsec;
		int unknown6;
		int pureAuthentic;
		unsigned char unsentBuffer[131072];
		unsigned char fragmentBuffer[2048];
		char pbguid[33];
		unsigned char pad;
		unsigned __int16 clscriptid;
		int canNotReliable;
		int serverId;
		voices_t voicedata[40];
		int unsentVoiceData;
		unsigned char mutedClients[64];
		unsigned char hasVoip;
		stats_t stats;
		unsigned char receivedstats;
		unsigned char pad2[2];
	};


	struct archivedEntityShared_t
	{
		int svFlags;
		int clientMask[2];
		float absmin[3];
		float absmax[3];
	};

	struct archivedEntity_t
	{
		entityState_s s;
		archivedEntityShared_t r;
	};

	struct archivedSnapshot_t
	{
		int start;
		int size;
	};

	struct cachedClient_t
	{
		int playerStateExists;
		clientState_s cs;
		playerState_s ps;
	};

	struct challenge_t
	{
		netadr_t adr;
		int challenge;
		int time;
		int pingTime;
		int firstTime;
		int firstPing;
		bool connected;
		char guid[36];
	};

	struct tempBanSlot_t
	{
		int banTime;
		char guid[32];
	};


	struct serverStatic_t
	{
		cachedSnapshot_t cachedSnapshotFrames[512];
		archivedEntity_t cachedSnapshotEntities[0x4000];
		bool initialized;
		int time;
		int snapFlagServerBit;
		client_t clients[64];
		int numSnapshotEntities;
		int numSnapshotClients;
		int nextSnapshotEntities;
		int nextSnapshotClients;
		entityState_s snapshotEntities[0x2A000];
		clientState_s snapshotClients[0x20000];
		int nextArchivedSnapshotFrames;
		archivedSnapshot_t archivedSnapshotFrames[1200];
		unsigned char archivedSnapshotBuffer[0x2000000];
		int nextArchivedSnapshotBuffer;
		int nextCachedSnapshotEntities;
		int nextCachedSnapshotClients;
		int nextCachedSnapshotFrames;
		cachedClient_t cachedSnapshotClients[0x1000];
		int nextHeartbeatTime;
		int nextStatusResponseTime;
		challenge_t challenges[1024];
		netadr_t redirectAddress;
		netadr_t authorizeAddress;
		char OOBProf[1504];
		tempBanSlot_t tempBans[16];
		int field_14850;
		float mapCenter[3];
		char field_14860[112];
	};

}
