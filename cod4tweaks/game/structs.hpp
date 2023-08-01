#pragma once

// Most comes from https://github.com/callofduty4x/CoD4x_Client_pub & https://github.com/xoxor4d/iw3xo-dev
namespace game::structs
{
	typedef float vec_t;
	typedef vec_t vec2_t[2];
	typedef vec_t vec3_t[3];
	typedef vec_t vec4_t[4];
	typedef vec_t vec5_t[5];

	typedef enum
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_DONE = 0x3,
		OBJST_CURRENT = 0x4,
		OBJST_FAILED = 0x5,
		OBJST_NUMSTATES = 0x6,
	} objectiveState_t;

	typedef struct objective_s
	{
		objectiveState_t state;
		float origin[3];
		int entNum;
		int teamNum;
		int icon;
	} objective_t;

	typedef enum
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	} ViewLockTypes_t;

	typedef enum
	{
		PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
		PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
		PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
	} OffhandSecondaryClass_t;

	typedef struct
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	} mantleState_t;

	typedef struct
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	} sprintState_t;

	typedef enum
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	} ActionSlotType_t;

	typedef struct
	{
		unsigned int index;
	} ActionSlotParam_SpecifyWeapon_t;

	typedef enum
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
	} he_type_t;

	typedef struct
	{
		ActionSlotParam_SpecifyWeapon_t specifyWeapon;
	} ActionSlotParam_t;

	typedef struct
	{
		char r;
		char g;
		char b;
		char a;
	} hudelem_colorsplit_t;

	typedef union
	{
		hudelem_colorsplit_t split;
		int rgba;
	} hudelem_color_t;

	typedef struct hudelem_s
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
	} hudelem_t;

#define MAX_HUDELEMENTS 31

	typedef struct hudElemState_s
	{
		hudelem_t current[MAX_HUDELEMENTS];
		hudelem_t archival[MAX_HUDELEMENTS];
	} hudElemState_t;

	typedef struct playerState_s
	{
		int commandTime;
		int pm_type;
		int bobCycle;
		int pm_flags;
		int weapFlags;
		int otherFlags;
		int pm_time;
		vec3_t origin;
		vec3_t velocity;
		vec2_t oldVelocity;
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
		vec3_t delta_angles;
		int groundEntityNum;
		vec3_t vLadderVec;
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
		OffhandSecondaryClass_t offhandSecondary;
		unsigned int weapon;
		int weaponstate;
		unsigned int weaponShotCount;
		float fWeaponPosFrac;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		int viewmodelIndex;
		vec3_t viewangles;
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		vec2_t viewAngleClampBase;
		vec2_t viewAngleClampRange;
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
		ViewLockTypes_t viewlocked;
		int viewlocked_entNum;
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int iCompassPlayerInfo;
		int radarEnabled;
		int locationSelectionInfo;
		sprintState_t sprintState;
		float fTorsoPitch;
		float fWaistPitch;
		float holdBreathScale;
		int holdBreathTimer;
		float moveSpeedScaleMultiplier;
		mantleState_t mantleState;
		float meleeChargeYaw;
		int meleeChargeDist;
		int meleeChargeTime;
		int perks;
		ActionSlotType_t actionSlotType[4];
		ActionSlotParam_t actionSlotParam[4];
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
		hudElemState_t hud;
	} playerState_t;

	typedef enum
	{
		TEAM_FREE,
		TEAM_RED,
		TEAM_BLUE,
		TEAM_SPECTATOR,

		TEAM_NUM_TEAMS
	} team_t;

	typedef struct clientState_s
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
		int attachedVehSeat;
	} clientState_t;

	typedef enum
	{
		TR_STATIONARY,
		TR_INTERPOLATE,
		TR_LINEAR,
		TR_LINEAR_STOP,
		TR_SINE,
		TR_GRAVITY
	} trType_t;

	typedef struct
	{
		trType_t trType;
		int trTime;
		int trDuration;
		vec3_t trBase;
		vec3_t trDelta;
	} trajectory_t;

	typedef struct LerpEntityStatePhysicsJitter_s
	{
		float innerRadius;
		float minDisplacement;
		float maxDisplacement;
	} LerpEntityStatePhysicsJitter_t;

	typedef struct LerpEntityStatePlayer_s
	{
		float leanf;
		int movementDir;
	} LerpEntityStatePlayer_t;

	typedef struct LerpEntityStateLoopFx_s
	{
		float cullDist;
		int period;
	} LerpEntityStateLoopFx_t;

	typedef struct LerpEntityStateCustomExplode_s
	{
		int startTime;
	} LerpEntityStateCustomExplode_t;

	typedef struct LerpEntityStateTurret_s
	{
		float gunAngles[3];
	} LerpEntityStateTurret_t;

	typedef struct LerpEntityStateAnonymous_s
	{
		int data[7];
	} LerpEntityStateAnonymous_t;

	typedef struct LerpEntityStateExplosion_s
	{
		float innerRadius;
		float magnitude;
	} LerpEntityStateExplosion_t;

	typedef struct LerpEntityStateBulletHit_s
	{
		float start[3];
	} LerpEntityStateBulletHit_t;

	typedef struct LerpEntityStatePrimaryLight_s
	{
		char colorAndExp[4];
		float intensity;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
	} LerpEntityStatePrimaryLight_t;

	typedef struct LerpEntityStateMissile_s
	{
		int launchTime;
	} LerpEntityStateMissile_t;

	typedef struct LerpEntityStateSoundBlend_s
	{
		float lerp;
	} LerpEntityStateSoundBlend_t;

	typedef struct LerpEntityStateExplosionJolt_s
	{
		float innerRadius;
		float impulse[3];
	} LerpEntityStateExplosionJolt_t;

	typedef struct LerpEntityStateVehicle_s
	{
		float bodyPitch;
		float bodyRoll;
		float steerYaw;
		int materialTime;
		float gunPitch;
		float gunYaw;
		int team;
	} LerpEntityStateVehicle_t;

	typedef struct LerpEntityStateEarthquake_s
	{
		float scale;
		float radius;
		int duration;
	} LerpEntityStateEarthquake_t;

	typedef union
	{
		LerpEntityStateTurret_t turret;
		LerpEntityStateLoopFx_t loopFx;
		LerpEntityStatePrimaryLight_t primaryLight;
		LerpEntityStatePlayer_t player;
		LerpEntityStateVehicle_t vehicle;
		LerpEntityStateMissile_t missile;
		LerpEntityStateSoundBlend_t soundBlend;
		LerpEntityStateBulletHit_t bulletHit;
		LerpEntityStateEarthquake_t earthquake;
		LerpEntityStateCustomExplode_t customExplode;
		LerpEntityStateExplosion_t explosion;
		LerpEntityStateExplosionJolt_t explosionJolt;
		LerpEntityStatePhysicsJitter_t physicsJitter;
		LerpEntityStateAnonymous_t anonymous;
	} LerpEntityStateTypeUnion_t;

	typedef struct LerpEntityState_s
	{
		int eFlags;
		trajectory_t pos;
		trajectory_t apos;
		LerpEntityStateTypeUnion_t u;
	} LerpEntityState_t;

	typedef int clipHandle_t;

	typedef struct entityState_s
	{
		int number;
		int eType;

		LerpEntityState_t lerp;

		int time2;

		int otherEntityNum;
		int attackerEntityNum;

		int groundEntityNum;

		int loopSound;
		int surfType;

		clipHandle_t index;
		int clientNum;
		int iHeadIcon;
		int iHeadIconTeam;

		int solid;

		int eventParm;
		int eventSequence;

		int events[4];
		int eventParms[4];

		int weapon;
		int weaponModel;
		int legsAnim;
		int torsoAnim;

		union
		{
			int scale;
			int eventParm2;
			int helicopterStage;
		} un1;

		union
		{
			int hintString;
			int grenadeInPickupRange;
			int vehicleXModel;
		} un2;

		int fTorsoPitch;
		int fWaistPitch;
		int partBits[4];
	} entityState_t;

	typedef struct snapshot_s
	{
		int snapFlags;
		int ping;
		int serverTime;
		playerState_t ps;
		int numEntities;
		int numClients;
		entityState_t entities[512];
		clientState_t clients[64];
		int serverCommandNum;
	} snapshot_t;

	typedef enum
	{
		CUBEMAPSHOT_NONE = 0x0,
		CUBEMAPSHOT_RIGHT = 0x1,
		CUBEMAPSHOT_LEFT = 0x2,
		CUBEMAPSHOT_BACK = 0x3,
		CUBEMAPSHOT_FRONT = 0x4,
		CUBEMAPSHOT_UP = 0x5,
		CUBEMAPSHOT_DOWN = 0x6,
		CUBEMAPSHOT_COUNT = 0x7,
	} CubemapShot;

	typedef enum
	{
		DEMO_TYPE_NONE = 0x0,
		DEMO_TYPE_CLIENT = 0x1,
		DEMO_TYPE_SERVER = 0x2,
	} DemoType;

	typedef union
	{
		char* _1;
		uint16_t* _2;
		void* data;
	} XAnimIndices;

	typedef union
	{
		char _1[1];
		uint16_t _2[1];
	} XAnimDynamicIndices;

	typedef uint16_t ScriptString;

	typedef struct
	{
		ScriptString name;
		short pad;
		float time;
	} XAnimNotifyInfo;

	typedef struct
	{
		int16_t(*frames)[2];
		XAnimDynamicIndices indices;
	} XAnimDeltaPartQuatDataFrames;

	typedef union
	{
		XAnimDeltaPartQuatDataFrames frames;
		int16_t frame0[2];
	} XAnimDeltaPartQuatData;

	typedef union
	{
		char(*_1)[3];
		uint16_t(*_2)[3];
	} XAnimDynamicFrames;

	typedef struct
	{
		uint16_t size;
		short pad;
		XAnimDeltaPartQuatData u;
	} XAnimDeltaPartQuat;

	typedef struct
	{
		float mins[3];
		float size[3];
		XAnimDynamicFrames frames;
		XAnimDynamicIndices indices;
	} XAnimPartTransFrames;

	typedef union
	{
		XAnimPartTransFrames frames;
		float frame0[3];
	} XAnimPartTransData;

	typedef struct
	{
		uint16_t size;
		char smallTrans;
		char pad;
		XAnimPartTransData u;
	} XAnimPartTrans;

	typedef struct
	{
		XAnimPartTrans* trans;
		XAnimDeltaPartQuat* quat;
	} XAnimDeltaPart;

#pragma pack(push, 4)
	typedef struct
	{
		const char* name;
		uint16_t dataByteCount;
		uint16_t dataShortCount;
		uint16_t dataIntCount;
		uint16_t randomDataByteCount;
		uint16_t randomDataIntCount;
		uint16_t numframes;
		char boneCount[12];
		char notifyCount;
		char assetType;
		short pad;
		unsigned int randomDataShortCount;
		unsigned int indexCount;
		float framerate;
		float frequency;
		uint16_t* names;
		char* dataByte;
		int16_t* dataShort;
		int* dataInt;
		int16_t* randomDataShort;
		char* randomDataByte;
		int* randomDataInt;
		XAnimIndices indices;
		XAnimNotifyInfo* notify;
		XAnimDeltaPart* deltaPart;
	} XAnimParts;
#pragma pack(pop)

	typedef struct
	{
		uint16_t flags;
		uint16_t children;
	} XAnimParent;

	typedef union
	{
		XAnimParts* parts;
		XAnimParent animParent;
	} XAnimInfoUnion;

	typedef union
	{
		XAnimParts* parts;
		XAnimParent animParent;
	} XAnimEntryUnion;

	typedef struct
	{
		uint16_t numAnims;
		uint16_t parent;
		XAnimEntryUnion u;
	} XAnimEntry;

	typedef struct
	{
		const char* debugName;
		unsigned int size;
		const char** debugAnimNames;
		XAnimEntry entries[1];
	} XAnim_s;

#pragma pack(push, 4)
	typedef struct
	{
		XAnim_s* anims;
		uint16_t children;
		uint16_t pad;
	} XAnimTree_s;
#pragma pack(pop)

	typedef struct clientControllers_s
	{
		vec3_t angles[6];
		vec3_t tag_origin_angles;
		vec3_t tag_origin_offset;
	} clientControllers_t;

	typedef struct CEntPlayerInfo_s
	{
		clientControllers_t* control;
		byte tag[6];
	} CEntPlayerInfo_t;

	typedef struct CEntTurretAngles_s
	{
		float pitch;
		float yaw;
	} CEntTurretAngles_t;

	typedef struct CEntTurretInfo_s
	{
		union
		{
			CEntTurretAngles_t angles;
			const float* viewAngles;
		};

		float barrelPitch;
		byte playerUsing;
		byte tag_aim;
		byte tag_aim_animated;
		byte tag_flash;
	} CEntTurretInfo_t;

	typedef void FxEffect_t;

	typedef struct CEntFx_s
	{
		int triggerTime;
		FxEffect_t* effect;
	} CEntFx_t;

	typedef struct CEntVehicleInfo_s
	{
		short pitch;
		short yaw;
		short roll;
		short barrelPitch;
		float barrelRoll;
		short steerYaw;
		byte pad[2];
		float time;
		unsigned short wheelFraction[4];
		byte wheelBoneIndex[4];
		byte tag_body;
		byte tag_turret;
		byte tag_barrel;
		byte pad2;
	} CEntVehicleInfo_t;

	typedef union
	{
		CEntPlayerInfo_t player;
		CEntTurretInfo_t turret;
		CEntVehicleInfo_t vehicle;
		CEntFx_t fx;
		byte badsizepad[0x30];
	} CEntInfo_t;

	typedef struct cpose_s
	{
		unsigned short lightingHandle;
		byte eType;
		byte eTypeUnion;
		byte localClientNum;
		byte pad[3];
		int cullIn;
		byte isRagdoll;
		byte pad2[3];
		int ragdollHandle;
		int killcamRagdollHandle;
		int physObjId;
		vec3_t origin;
		vec3_t angles;
		CEntInfo_t centInfo;
	} cpose_t;

	typedef struct centity_s
	{
		cpose_t pose;
		LerpEntityState_t currentState;
		entityState_t nextState;
		byte nextValid;
		byte bMuzzleFlash;
		byte bTrailMade;
		byte pad;
		int previousEventSequence;
		int miscTime;
		vec3_t lightingOrigin;
		XAnimTree_s* tree;
	} centity_t;

	typedef struct
	{
		float fLastWeaponPosFrac;
		int bPositionToADS;
		float vPositionLastOrg[3];
		float fLastIdleFactor;
		float vLastMoveOrg[3];
		float vLastMoveAng[3];
	} playerEntity_t;

	typedef struct
	{
		float viewModelStart;
		float viewModelEnd;
		float nearStart;
		float nearEnd;
		float farStart;
		float farEnd;
		float nearBlur;
		float farBlur;
	} GfxDepthOfField;

#pragma pack(push, 4)
	struct MaterialPass
	{
		struct MaterialVertexDeclaration* vertexDecl;
		struct MaterialVertexShader* vertexShader;
		struct MaterialPixelShader* pixelShader;
		char perPrimArgCount;
		char perObjArgCount;
		char stableArgCount;
		char customSamplerFlagsOrprecompiledIndex;
		struct MaterialShaderArgument* args;
	};
#pragma pack(pop)

	typedef struct MaterialTechnique
	{
		const char* name;
		uint16_t flags;
		uint16_t passCount;
		struct MaterialPass passArray[1];
	} MaterialTechnique;

	typedef enum
	{
		TECHNIQUE_DEPTH_PREPASS = 0x0,
		TECHNIQUE_BUILD_FLOAT_Z = 0x1,
		TECHNIQUE_BUILD_SHADOWMAP_DEPTH = 0x2,
		TECHNIQUE_BUILD_SHADOWMAP_COLOR = 0x3,
		TECHNIQUE_UNLIT = 0x4,
		TECHNIQUE_EMISSIVE = 0x5,
		TECHNIQUE_EMISSIVE_SHADOW = 0x6,
		TECHNIQUE_LIT_BEGIN = 0x7,
		TECHNIQUE_LIT = 0x7,
		TECHNIQUE_LIT_SUN = 0x8,
		TECHNIQUE_LIT_SUN_SHADOW = 0x9,
		TECHNIQUE_LIT_SPOT = 0xA,
		TECHNIQUE_LIT_SPOT_SHADOW = 0xB,
		TECHNIQUE_LIT_OMNI = 0xC,
		TECHNIQUE_LIT_OMNI_SHADOW = 0xD,
		TECHNIQUE_LIT_INSTANCED = 0xE,
		TECHNIQUE_LIT_INSTANCED_SUN = 0xF,
		TECHNIQUE_LIT_INSTANCED_SUN_SHADOW = 0x10,
		TECHNIQUE_LIT_INSTANCED_SPOT = 0x11,
		TECHNIQUE_LIT_INSTANCED_SPOT_SHADOW = 0x12,
		TECHNIQUE_LIT_INSTANCED_OMNI = 0x13,
		TECHNIQUE_LIT_INSTANCED_OMNI_SHADOW = 0x14,
		TECHNIQUE_LIGHT_SPOT = 0x15,
		TECHNIQUE_LIGHT_OMNI = 0x16,
		TECHNIQUE_LIGHT_SPOT_SHADOW = 0x17,
		TECHNIQUE_FAKELIGHT_NORMAL = 0x18,
		TECHNIQUE_FAKELIGHT_VIEW = 0x19,
		TECHNIQUE_SUNLIGHT_PREVIEW = 0x1A,
		TECHNIQUE_CASE_TEXTURE = 0x1B,
		TECHNIQUE_WIREFRAME_SOLID = 0x1C,
		TECHNIQUE_WIREFRAME_SHADED = 0x1D,
		TECHNIQUE_SHADOWCOOKIE_CASTER = 0x1E,
		TECHNIQUE_SHADOWCOOKIE_RECEIVER = 0x1F,
		TECHNIQUE_DEBUG_BUMPMAP = 0x20,
		TECHNIQUE_DEBUG_BUMPMAP_INSTANCED = 0x21,
		TECHNIQUE_COUNT = 0x22,
		TECHNIQUE_TOTAL_COUNT = 0x23,
		TECHNIQUE_NONE = 0x24,
	} MaterialTechniqueType;

#pragma pack(push, 2)
	typedef struct MaterialTechniqueSet
	{
		const char* name;
		char worldVertFormat;
		char unused[3];
		struct MaterialTechniqueSet* remappedTechniqueSet;
		struct MaterialTechnique* techniques[TECHNIQUE_COUNT];
	} MaterialTechniqueSet;
#pragma pack(pop)

#pragma pack(push, 4)
	typedef struct
	{
		byte enabled;
		byte pad[3];
		float bloomCutoff;
		float bloomDesaturation;
		float bloomIntensity;
		float radius;
	} GfxGlow;
#pragma pack(pop)

#pragma pack(push, 4)
	typedef struct
	{
		byte enabled;
		byte pad[3];
		float brightness;
		float contrast;
		float desaturation;
		byte invert;
		byte pad2[3];
		float tintDark[3];
		float tintLight[3];
	} GfxFilm;
#pragma pack(pop)

#pragma pack(push, 4)
	typedef struct
	{
		struct GfxImage* image;
		char samplerState;
		byte pad[3];
	} GfxLightImage;
#pragma pack(pop)

	typedef struct
	{
		const char* name;
		GfxLightImage attenuation;
		int lmapLookupStart;
	} GfxLightDef;

	typedef struct
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
	} GfxLight;

	typedef struct refdef_s
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
		int field_4080;
		int field_4084;
		int field_4088;
		int field_408c;
		bool useScissorViewport;
		byte pad[3];
		int localClientNum;
	} refdef_t;

	typedef void xScriptString_t;
	typedef void xMaterial_t;
	typedef void xPhysPreset_t;

	typedef struct DObjAnimMat_s
	{
		float quat[4];
		float trans[3];
		float transWeight;
	} DObjAnimMat_t;

	typedef struct XSurfaceVertexInfo_s
	{
		short vertCount[4];
		unsigned short* vertsBlend;
	} XSurfaceVertexInfo_t;
	typedef unsigned short r_index16_t;
	typedef struct XSurface_s
	{
		char tileMode;
		byte deformed;
		unsigned short vertCount;
		unsigned short triCount;
		r_index16_t* triIndices;
		XSurfaceVertexInfo_t vertInfo;
	} XSurface_t;

	typedef struct XModelLodInfo_s
	{
		float dist;
		unsigned short numsurfs;
		unsigned short surfIndex;
		int partBits[4];
	} XModelLodInfo_t;

	typedef struct XModelCollSurf_s
	{
		float mins[3];
		float maxs[3];
		int boneIdx;
		int contents;
		int surfFlags;
	} XModelCollSurf_t;

	typedef struct XBoneInfo_s
	{
		float bounds[2][3];
		float offset[3];
		float radiusSquared;
	} XBoneInfo_t;

	typedef struct XModelHighMipBounds_s
	{
		float mins[3];
		float maxs[3];
	} XModelHighMipBounds_t;

	typedef struct XModelStreamInfo_s
	{
		XModelHighMipBounds_t* highMipBounds;
	} XModelStreamInfo_t;

	typedef struct PhysMass_s
	{
		float centerOfMass[3];
		float momentsOfInertia[3];
		float productsOfInertia[3];
	} PhysMass_t;

	typedef struct BrushWrapper_s
	{
		float mins[3];
		int contents;
		float maxs[3];
		unsigned int numsides;
		struct cbrushside_s* sides;
		short axialMaterialNum[2][3];
		char* baseAdjacentSide;
		short firstAdjacentSideOffsets[2][3];
		char edgeCount[2][3];
		char pad[2];
		int totalEdgeCount;
		struct cplane_s* planes;
	} BrushWrapper_t;

	typedef struct PhysGeomInfo_s
	{
		BrushWrapper_t* brush;
		int type;
		float orientation[3][3];
		float offset[3];
		float halfLengths[3];
	} PhysGeomInfo_t;

	typedef struct PhysGeomList_s
	{
		unsigned int count;
		PhysGeomInfo_t* geoms;
		PhysMass_t mass;
	} PhysGeomList_t;

	typedef struct
	{
		const char* name;
		char numBones;
		char numRootBones;
		char numsurfs;
		char field_7;
		xScriptString_t* boneNames;
		char* parentList;
		short* quats;
		float* trans;
		char* partClassification;
		DObjAnimMat_t* baseMat;
		XSurface_t* surfs;
		xMaterial_t** materialHandles;
		XModelLodInfo_t lodInfo[4];
		int field_88;
		int field_8C;
		int field_90;
		int field_94;
		XModelCollSurf_t* collSurfs;
		int numCollSurfs;
		int contents;
		XBoneInfo_t* boneInfo;
		float radius;
		vec3_t mins;
		vec3_t maxs;
		short numLods;
		short collLod;
		XModelStreamInfo_t streamInfo;
		int memUsage;
		char flags;
		char field_D1;
		char field_D2;
		char field_D3;
		xPhysPreset_t* physPreset;
		PhysGeomList_t* physGeoms;
	} XModel;

	struct GfxDrawSurfFields
	{
		unsigned __int64 objectId : 16;
		unsigned __int64 reflectionProbeIndex : 8;
		unsigned __int64 customIndex : 5;
		unsigned __int64 materialSortedIndex : 11;
		unsigned __int64 prepass : 2;
		unsigned __int64 primaryLightIndex : 8;
		unsigned __int64 surfType : 4;
		unsigned __int64 primarySortKey : 6;
		unsigned __int64 unused : 4;
	};

	union GfxDrawSurf
	{
		GfxDrawSurfFields fields;
		unsigned long long packed;
	};

	typedef struct
	{
		const char* name;
		char gameFlags;
		char sortKey;
		char textureAtlasRowCount;
		char textureAtlasColumnCount;
		GfxDrawSurf drawSurf;
		int surfaceTypeBits;
	} MaterialInfo;

	typedef union
	{
		struct GfxImage* image;
		struct water_t* water;
	} MaterialTextureDefInfo;

	typedef struct MaterialTextureDef_s
	{
		unsigned int nameHash;
		char nameStart;
		char nameEnd;
		char sampleState;
		char semantic;
		MaterialTextureDefInfo u;
	} MaterialTextureDef;

	typedef struct
	{
		int loadBits[2];
	} GfxStateBits;

	typedef struct Material_s
	{
		MaterialInfo info;
		char stateBitsEntry[TECHNIQUE_COUNT];
		char textureCount;
		char constantCount;
		char stateBitsCount;
		char stateFlags;
		char cameraRegion;
		char unk;
		struct MaterialTechniqueSet* techniqueSet;
		MaterialTextureDef* textureTable;
		struct MaterialConstantDef* constantTable;
		GfxStateBits* stateBitTable;
	} Material;

	typedef struct
	{
		int client;
		int score;
		int ping;
		int deaths;
		int team;
		int kills;
		int rank;
		int assists;
		Material* hStatusIcon;
		Material* hRankIcon;
	} score_t;

	typedef struct
	{
		int time;
		int duration;
		float yaw;
	} viewDamage_t;

	typedef struct
	{
		struct shellshock_parms_t* parms;
		int startTime;
		int duration;
		int loopEndTime;
		float sensitivity;
		float viewDelta[2];
		int hasSavedScreen;
	} shellshock_t;

	typedef struct
	{
		int time;
		int duration;
	} cgShockinfo_t;

	typedef struct
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	} SprintState;

#pragma pack(push, 8)
	typedef struct animation_s
	{
		char name[64];
		int initialLerp;
		float moveSpeed;
		int duration;
		int nameHash;
		int flags;
		int64_t movetype;
		int noteType;
	} animation_t;
#pragma pack(pop)

	typedef struct
	{
		int index;
		unsigned int value[2];
	} animScriptCondition_t;

	typedef struct _AILSOUNDINFO
	{
		signed int format;
		const void* data_ptr;
		unsigned int data_len;
		unsigned int rate;
		signed int bits;
		signed int channels;
		unsigned int samples;
		unsigned int block_size;
		const void* initial_ptr;
	} AILSOUNDINFO;

	typedef struct MssSound_s
	{
		AILSOUNDINFO ailInfo;
		void* data;
	} MssSound_t;

	typedef struct LoadedSound_s
	{
		const char* name;
		MssSound_t sounds;
	} LoadedSound_t;

	typedef struct SoundFileInfo_s
	{
		const char* sndfilename;
		MssSound_t ailsoundinfo;
	} SoundFileInfo_t;

	typedef struct StreamFileNamePacked_s
	{
		unsigned __int64 offset;
		unsigned __int64 length;
	} StreamFileNamePacked_t;

	typedef struct StreamFileNameRaw_s
	{
		const char* dir;
		const char* name;
	} StreamFileNameRaw_t;

	typedef union StreamFileInfo_s
	{
		StreamFileNameRaw_t raw;
		StreamFileNamePacked_t packed;
	} StreamFileInfo_t;

	typedef struct StreamFileName_s
	{
		StreamFileInfo_t info;
		unsigned __int16 isLocalized;
		unsigned __int16 fileIndex;
	} StreamFileName_t;

	typedef struct StreamedSound_s
	{
		StreamFileName_t filename;
		unsigned int totalMsec;
	} StreamedSound_t;

	typedef union SoundFileRef_s
	{
		LoadedSound_t* loadSnd;
		StreamedSound_t streamSnd;
	} SoundFileRef_t;

	typedef struct SoundFile_s
	{
		byte type;
		byte pad2[3];
		SoundFileRef_t sound;
		byte exists;
		byte pad[3];
	} SoundFile_t;

	typedef struct SndCurve_s
	{
		const char* filename;
		int knotCount;
		float knots[8][2];
	} SndCurve_t;

	typedef struct SpeakerLevels_s
	{
		int speaker;
		int numLevels;
		float levels[2];
	} SpeakerLevels_t;

	typedef struct ChannelMap_s
	{
		int entryCount;
		SpeakerLevels_t speakers[6];
	} ChannelMap_t;

	typedef struct SpeakerMap_s
	{
		byte isDefault;
		byte pad[3];
		const char* name;
		ChannelMap_t channelMaps[2][2];
	} SpeakerMap_t;

	typedef const struct snd_alias_s
	{
		const char* aliasName;
		const char* subtitle;
		const char* secondaryAliasName;
		const char* chainAliasName;
		SoundFile_t* soundFile;
		int sequence;
		float volMin;
		float volMax;
		float pitchMin;
		float pitchMax;
		float distMin;
		float distMax;
		int flags;
		float slavePercentage;
		float probability;
		float lfePercentage;
		float centerPercentage;
		int startDelay;
		SndCurve_t* volumeFalloffCurve;
		float envelopMin;
		float envelopMax;
		float envelopPercentage;
		SpeakerMap_t* speakerMap;
	} snd_alias_t;

	typedef struct snd_alias_list_s
	{
		const char* aliasName;
		snd_alias_t* head;
		int count;
	} snd_alias_list_t;

	typedef struct
	{
		int16_t bodyPart[2];
		int16_t animIndex[2];
		int16_t animDuration[2];
		snd_alias_list_t* soundAlias;
	} animScriptCommand_t;

	typedef struct
	{
		int numConditions;
		animScriptCondition_t conditions[10];
		int numCommands;
		animScriptCommand_t commands[8];
	} animScriptItem_t;

	typedef struct
	{
		int numItems;
		animScriptItem_t* items[128];
	} animScript_t;

	typedef struct scr_animtree_s
	{
		XAnim_s* anims;
	} scr_animtree_t;

#pragma pack(push, 8)
	typedef struct
	{
		animation_t animations[512];
		unsigned int numAnimations;
		animScript_t scriptAnims[1][43];
		animScript_t scriptCannedAnims[1][43];
		animScript_t scriptStateChange[1][1];
		animScript_t scriptEvents[21];
		animScriptItem_t scriptItems[2048];
		int numScriptItems;
		scr_animtree_t animTree;
		uint16_t torsoAnim;
		uint16_t legsAnim;
		uint16_t turningAnim;
		uint16_t pad;
		snd_alias_list_t* (__cdecl* soundAlias) (const char*);
		int(__cdecl* playSoundAlias) (int, snd_alias_list_t*);
		int pad2;
	} animScriptData_t;
#pragma pack(pop)

	typedef struct
	{
		int lastPlayedTime;
	} hudElemSoundInfo_t;

	typedef struct scr_animuabs_s
	{
		uint16_t index;
		uint16_t tree;
	} scr_animuabs_t;

	typedef union
	{
		scr_animuabs_t s;
		const char* linkPointer;
	} scr_animu_s;

	typedef struct scr_anim_s
	{
		scr_animu_s u;
	} scr_anim_t;

	typedef struct
	{
		scr_animtree_t tree;
		scr_anim_t torso;
		scr_anim_t legs;
		scr_anim_t turning;
	} bodyAnim_t;

	typedef struct lerpFrame_s
	{
		float yawAngle;
		int yawing;
		float pitchAngle;
		int pitching;
		int animationNumber;
		animation_t* animation;
		int animationTime;
		float oldFramePos[3];
		float animSpeedScale;
		int oldFrameSnapshotTime;
	} lerpFrame_t;

#pragma pack(push, 4)
	typedef struct clientInfo_s
	{
		int infoValid;
		int nextValid;
		int clientNum;
		char name[16];
		team_t team;
		team_t oldteam;
		int rank;
		int unk1;
		int unk2;
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
		XAnimTree_s* pXAnimTree;
		int iDObjWeapon;
		char weaponModel;
		char pad[3];
		int stanceTransitionTime;
		int turnAnimEndTime;
		char turnAnimType;
		char pad2[3];
		int attachedVehEntNum;
		int attachedVehSeat;
		byte hideWeapon;
		byte usingKnife;
		char pad3[2];
	} clientInfo_t;
#pragma pack(pop)

#pragma pack(push, 2)
	typedef struct DObjModel_s
	{
		XModel* model;
		uint16_t boneName;
		byte ignoreCollision;
		byte pad;
	} DObjModel_t;
#pragma pack(pop)

	typedef struct bgs_s
	{
		animScriptData_t animScriptData;
		bodyAnim_t generic_human;
		int time;
		int latestSnapshotTime;
		int frametime;
		int anim_user;
		XModel* (__cdecl* GetXModel) (const char*);
		void(__cdecl* CreateDObj) (DObjModel_t*, uint16_t, XAnimTree_s*, int, int,
			clientInfo_t*);
		uint16_t(__cdecl* AttachWeapon) (DObjModel_t*, uint16_t, clientInfo_t*);
		struct DObj_s* (__cdecl* GetDObj) (int, int);
		void(__cdecl* SafeDObjFree) (int, int);
		void* (__cdecl* AllocXAnim) (int);
		clientInfo_t clientinfo[64];
	} bgs_t;
#define MAX_CLIENTS 64
#pragma pack(push, 4)
	typedef struct
	{
		byte glowEnable;
		byte pad[3];
		float glowBloomCutoff;
		float glowBloomDesaturation;
		float glowBloomIntensity0;
		float glowBloomIntensity1;
		float glowRadius0;
		float glowRadius1;
		float glowSkyBleedIntensity0;
		float glowSkyBleedIntensity1;
		byte filmEnable;
		byte pad2[3];
		float filmBrightness;
		float filmContrast;
		float filmDesaturation;
		byte filmInvert;
		byte pad3[3];
		float filmLightTint[3];
		float filmDarkTint[3];
	} visionSetVars_t;
#pragma pack(pop)

	typedef enum
	{
		VISIONSETLERP_UNDEFINED = 0x0,
		VISIONSETLERP_NONE = 0x1,
		VISIONSETLERP_TO_LINEAR = 0x2,
		VISIONSETLERP_TO_SMOOTH = 0x3,
		VISIONSETLERP_BACKFORTH_LINEAR = 0x4,
		VISIONSETLERP_BACKFORTH_SMOOTH = 0x5,
	} visionSetLerpStyle_t;

	typedef struct
	{
		int timeStart;
		int timeDuration;
		visionSetLerpStyle_t style;
	} visionSetLerpData_t;

	typedef struct
	{
		float aimSpreadScale;
	} cgFrameInfo_t;

	typedef struct cg_s
	{
		int clientNum;
		int localClientNum;
		DemoType demoType;
		CubemapShot cubemapShot;
		int cubemapSize;
		int renderScreen;
		int latestSnapshotNum;
		int latestSnapshotTime;
		snapshot_t* snap;
		snapshot_t* nextSnap;
		snapshot_t activeSnapshots[2];
		float frameInterpolation;
		int frametime;
		int time;
		int oldTime;
		int physicsTime;
		int mapRestart;
		int renderingThirdPerson;
		playerState_t predictedPlayerState;
		centity_t predictedPlayerEntity;
		playerEntity_t playerEntity;
		int predictedErrorTime;
		float predictedError[3];
		float landChange;
		int landTime;
		float heightToCeiling;
		struct refdef_s refdef;
		float refdefViewAngles[3];
		float lastVieworg[3];
		float swayViewAngles[3];
		float swayAngles[3];
		float swayOffset[3];
		int iEntityLastType[1024];
		XModel* pEntityLastXModel[1024];
		float zoomSensitivity;
		byte isLoading;
		char objectiveText[1024];
		char scriptMainMenu[256];
		byte pad[3];
		int scoresRequestTime;
		int numScores;
		int teamScores[4];
		int teamPings[4];
		int teamPlayers[4];
		score_t scores[MAX_CLIENTS];
		int scoreLimit;
		int scoreFadeTime;
		int scoresTop;
		int scoresOffBottom;
		int scoresBottom;
		int bannerLines[1];
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
		int invalidCmdType;
		int invalidCmdBlinkTime;
		int lastHealthPulseTime;
		int lastHealthLerpDelay;
		int lastHealthClient;
		float lastHealth;
		float healthOverlayFromAlpha;
		float healthOverlayToAlpha;
		int healthOverlayPulseTime;
		int healthOverlayPulseDuration;
		int healthOverlayPulsePhase;
		byte healthOverlayHurt;
		byte pad2[3];
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
		Material* compassMapMaterial;
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
		cgShockinfo_t testShock;
		int holdBreathTime;
		int holdBreathInTime;
		int holdBreathDelay;
		float holdBreathFrac;
		float radarProgress;
		float selectedLocation[2];
		SprintState sprintStates;
		int adsViewErrorDone;
		int inKillCam;
		bgs_t bgs;
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
		byte playerTeleported;
		byte pad3[3];
		int stepViewStart;
		float stepViewChange;
		cgFrameInfo_t lastFrame;
		hudElemSoundInfo_t hudElemSound[32];
		int vehicleFrame;
	} cg_t;

	typedef struct
	{
		byte linked;
		byte bmodel;
		byte svFlags;
		byte pad1;
		int clientMask[2];
		byte inuse;
		byte pad2[3];
		int broadcastTime;
		vec3_t mins, maxs;
		int contents;
		vec3_t absmin, absmax;
		vec3_t currentOrigin;
		vec3_t currentAngles;
		uint16_t ownerNum;
		uint16_t pad3;
		int eventTime;
	} entityShared_t;

	struct gentity_s
	{
		entityState_t s;
		entityShared_t r;
		struct gclient_s* client;
		bool inuse;
	};

	struct GfxMatrix
	{
		float m[4][4];
	};

	struct GfxViewParms
	{
		struct GfxMatrix viewMatrix;
		struct GfxMatrix projectionMatrix;
		struct GfxMatrix viewProjectionMatrix;
		struct GfxMatrix inverseViewProjectionMatrix;
		float origin[4];
		float axis[3][3];
		float depthHackNearClip;
		int pad[2];
	};

	typedef union
	{
		unsigned int packed;
		uint8_t array[4];
	} GfxColor;

	struct GfxFog
	{
		int startTime;
		int finishTime;
		GfxColor color;
		float fogStart;
		float density;
	};

	struct Image_MemUsage
	{
		int total;
		int lightmap;
		int minspec;
	};

	struct trStatistics_t
	{
		int c_indexes;
		int c_fxIndexes;
		int c_viewIndexes;
		int c_shadowIndexes;
		int c_vertexes;
		int c_batches;
		float dc;
		Image_MemUsage c_imageUsage;
	};

	struct GfxLodRamp
	{
		float scale;
		float bias;
	};

	struct __declspec(align (4)) GfxLodParms
	{
		float origin[3];
		GfxLodRamp ramp[2];
	};

	struct GfxPlacement
	{
		vec4_t quat;
		vec3_t origin;
	};

	struct GfxScaledPlacement
	{
		struct GfxPlacement base;
		float scale;
	};

	struct r_globals_t
	{
		GfxViewParms identityViewParms;
		bool inFrame;
		bool registered;
		bool forbidDelayLoadImages;
		bool ignorePrecacheErrors;
		float viewOrg[3];
		float viewDir[3];
		unsigned int frontEndFrameCount;
		int totalImageMemory;
		Material* materialHashTable[2048];
		GfxFog fogSettings[5];
		int fogIndex;
		GfxColor color_axis;
		GfxColor color_allies;
		int team;
		trStatistics_t* stats;
		GfxLodParms lodParms;
		GfxLodParms correctedLodParms;
		bool hasAnyImageOverrides;
		bool useSunLightOverride;
		bool useSunDirOverride;
		bool useSunDirLerp;
		float sunLightOverride[3];
		float sunDirOverride[3];
		float sunDirOverrideTarget[3];
		int sunDirLerpBeginTime;
		int sunDirLerpEndTime;
		GfxScaledPlacement identityPlacement;
		GfxViewParms* debugViewParms;
		int endTime;
		bool distortion;
		bool drawSModels;
		bool drawXModels;
		bool drawBModels;
		const char* codeImageNames[27];
		unsigned int viewInfoCount;
		int sunShadowFull;
		float sunShadowmapScale;
		float sunShadowmapScaleNum;
		unsigned int sunShadowSize;
		float sunShadowPartitionRatio;
		int drawSunShadow;
		int skinnedCacheReachedThreshold;
		float waterFloatTime;
	};

#define MAX_TOKENIZE_STRINGS 8

	struct CmdArgs
	{
		int nesting;
		int localClientNum[MAX_TOKENIZE_STRINGS];
		int argshift[MAX_TOKENIZE_STRINGS];
		int argc[MAX_TOKENIZE_STRINGS];
		const char** argv[MAX_TOKENIZE_STRINGS];
	};

	typedef struct
	{
		Material* sortedMaterials[2048];
		int needSortMaterials;
		int materialCount;

		struct GfxImage* whiteImage;
		struct GfxImage* blackImage;
		struct GfxImage* black3dImage;
		struct GfxImage* blackCubeImage;
		struct GfxImage* grayImage;
		struct GfxImage* identityNormalMapImage;
		struct GfxImage* specularityImage;
		struct GfxImage* outdoorImage;
		struct GfxImage* pixelCostColorCodeImage;

		struct GfxLightDef* dlightDef;

		Material* defaultMaterial;
		Material* whiteMaterial;
		Material* additiveMaterial;
		Material* pointMaterial;
		Material* lineMaterial;
		Material* lineMaterialNoDepth;
		Material* clearAlphaStencilMaterial;
		Material* shadowClearMaterial;
		Material* shadowCookieOverlayMaterial;
		Material* shadowCookieBlurMaterial;
		Material* shadowCasterMaterial;
		Material* shadowOverlayMaterial;
		Material* depthPrepassMaterial;
		Material* glareBlindMaterial;
		Material* pixelCostAddDepthAlwaysMaterial;
		Material* pixelCostAddDepthDisableMaterial;
		Material* pixelCostAddDepthEqualMaterial;
		Material* pixelCostAddDepthLessMaterial;
		Material* pixelCostAddDepthWriteMaterial;
		Material* pixelCostAddNoDepthWriteMaterial;
		Material* pixelCostColorCodeMaterial;
		Material* stencilShadowMaterial;
		Material* stencilDisplayMaterial;
		Material* floatZDisplayMaterial;
		Material* colorChannelMixerMaterial;
		Material* frameColorDebugMaterial;
		Material* frameAlphaDebugMaterial;

		int usednullvar;

		struct GfxWorld_s* world;

		Material* feedbackReplaceMaterial;
		Material* feedbackBlendMaterial;
		Material* feedbackFilmBlendMaterial;
		Material* cinematicMaterial;
		Material* dofDownsampleMaterial;
		Material* dofNearCocMaterial;
		Material* smallBlurMaterial;
		Material* postFxDofMaterial;
		Material* postFxDofColorMaterial;
		Material* postFxColorMaterial;
		Material* postFxMaterial;
		Material* symmetricFilterMaterial[8];
		Material* shellShockBlurredMaterial;
		Material* shellShockFlashedMaterial;
		Material* glowConsistentSetupMaterial;
		Material* glowApplyBloomMaterial;

		int savedScreenTimes[32];
	} r_global_permanent_t;

	typedef void* xcommand_t;
	typedef struct cmd_function_s
	{
		struct cmd_function_s* next;
		const char* name;
		const char* autocomplete1;
		const char* autocomplete2;
		xcommand_t function;
	} cmd_function_t;

	typedef struct
	{
		int score;
		int deaths;
		int kills;
		int assists;
	} clientScoreboard_t;

	typedef enum
	{
		CON_DISCONNECTED,
		CON_CONNECTING,
		CON_CONNECTED
	} clientConnected_t;

#pragma pack(push, 1)
	typedef struct usercmd_s
	{
		int serverTime;
		int buttons;
		int angles[3];
		byte weapon;
		byte offHandIndex;
		byte field_16;
		byte field_17;
		int field_18;
		int field_1C;
	} usercmd_t;
#pragma pack(pop)

	typedef enum
	{
		SPECTATOR_NOT,
		SPECTATOR_FREE,
		SPECTATOR_FOLLOW,
		SPECTATOR_SCOREBOARD
	} spectatorState_t;

#define MAX_NETNAME 16
#define MAX_NAME_LENGTH 16

	typedef struct
	{
		team_t sessionTeam;
		int spectatorTime;
		spectatorState_t spectatorState;
		int spectatorClient_Unknown;
		int wins, losses;
		int playerType;
		int playerWeapon;

		int playerTagIndex;
		int playerSkin;

		int latchPlayerType;
		int latchPlayerWeapon;
		int latchPlayerItem;
		int latchPlayerSkin;
		char netname[MAX_NAME_LENGTH];
		int lastFollowedClient;
		int rank;
		int prestige;
		int perkIndex;
		int vehicleOwnerNum;
		int vehicleRideSlot;
		int PSOffsetTime;
		int spectatorClient;
	} clientSession_t;

	typedef struct
	{
		enum
		{
			STATE_PLAYING,
			STATE_DEAD,
			STATE_SPECTATOR,
			STATE_INTERMISSION
		} playerState;

		int unknownStateVar;
		int unknownStateVar2;
		int unknown[2];

		clientScoreboard_t scoreboard;
		bool initialSpawn;
		clientConnected_t connected;
		usercmd_t cmd;
		usercmd_t oldcmd;
		bool localClient;

		bool predictItemPickup;
		char netname[MAX_NETNAME];

		int maxHealth;
		int enterTime;
		int connectTime;

		int voteCount;
		int teamVoteCount;

		int moveSpeedScale;

		int viewModel;

		int clientCanSpectate;
		int freeaddr1;

		int clientState;
	} clientPersistant_t;

	struct gclient_s
	{
		playerState_t ps;
		clientPersistant_t pers;
		clientSession_t sess;
		bool noclip;
		bool ufo;
		bool freezeControls;
		int lastCmdTime;
		int buttons;
		int oldbuttons;
		int unk1;
		int latched_buttons;
		int wbuttons;
		int oldwbuttons;
		int latched_wbuttons;
		int damage_armor;
		int damage_blood;
		int damage_knockback;
		vec3_t damage_from;
		bool damage_fromWorld;
		int accurateCount;
		int accuracy_shots;
		int accuracy_hits;
		int inactivityTime;
		bool inactivityWarning;
		int playerTalkTime;
		int rewardTime;
		vec3_t unk;
		int airOutTime;
		int lastKillTime;
		int dummy34;
		bool fireHeld;
		gentity_s* hook;
		int switchTeamTime;
		int IMtooLazy[33];
	};

#define MAX_SPAWN_VARS 64
#define MAX_SPAWN_VARS_CHARS 2048
#define MAX_STRING_CHARS 1024
#define MAX_STRING_TOKENS 1024
#define MAX_TOKEN_CHARS 1024


	typedef struct
	{
		struct gclient_s* clients;
		struct gentity_s* gentities;
		int gentitySize;
		int num_entities;
		struct gentity_s* firstFreeEnt;
		struct gentity_s* lastFreeEnt;
		void* logFile;
		int initializing;
		int clientIsSpawning;
		objective_t objectives[16];
		int maxclients;
		int framenum;
		int time;
		int previousTime;
		int frameTime;
		int startTime;
		int teamScores[TEAM_NUM_TEAMS];
		int lastTeamLocationTime;
		bool bUpdateScoresForIntermission;
		byte teamHasRadar[TEAM_NUM_TEAMS];
		int manualNameChange;
		int numConnectedClients;
		int sortedClients[MAX_CLIENTS];
		char voteString[MAX_STRING_CHARS];
		char voteDisplayString[MAX_STRING_CHARS];
		int voteTime;
		int voteExecuteTime;
		int voteYes;
		int voteNo;
		int numVotingClients;
	} level_locals_t;

	typedef void FxEffectDef;

	typedef enum
	{
		WEAPTYPE_BULLET = 0x0,
		WEAPTYPE_GRENADE = 0x1,
		WEAPTYPE_PROJECTILE = 0x2,
		WEAPTYPE_BINOCULARS = 0x3,
		WEAPTYPE_NUM = 0x4,
	} weapType_t;

	typedef enum
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_MG = 0x1,
		WEAPCLASS_SMG = 0x2,
		WEAPCLASS_SPREAD = 0x3,
		WEAPCLASS_PISTOL = 0x4,
		WEAPCLASS_GRENADE = 0x5,
		WEAPCLASS_ROCKETLAUNCHER = 0x6,
		WEAPCLASS_TURRET = 0x7,
		WEAPCLASS_NON_PLAYER = 0x8,
		WEAPCLASS_ITEM = 0x9,
		WEAPCLASS_NUM = 0xA,
	} weapClass_t;

	typedef enum
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4,
	} PenetrateType;

	typedef enum
	{
		IMPACT_TYPE_NONE = 0x0,
		IMPACT_TYPE_BULLET_SMALL = 0x1,
		IMPACT_TYPE_BULLET_LARGE = 0x2,
		IMPACT_TYPE_BULLET_AP = 0x3,
		IMPACT_TYPE_SHOTGUN = 0x4,
		IMPACT_TYPE_GRENADE_BOUNCE = 0x5,
		IMPACT_TYPE_GRENADE_EXPLODE = 0x6,
		IMPACT_TYPE_ROCKET_EXPLODE = 0x7,
		IMPACT_TYPE_PROJECTILE_DUD = 0x8,
		IMPACT_TYPE_COUNT = 0x9,
	} ImpactType;

	typedef enum
	{
		WEAPINVENTORY_PRIMARY = 0x0,
		WEAPINVENTORY_OFFHAND = 0x1,
		WEAPINVENTORY_ITEM = 0x2,
		WEAPINVENTORY_ALTMODE = 0x3,
		WEAPINVENTORYCOUNT = 0x4,
	} weapInventoryType_t;
#define NUM_SCREENS 1
	typedef enum
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPECOUNT = 0x5,
	} weapFireType_t;

	typedef enum
	{
		OFFHAND_CLASS_NONE = 0x0,
		OFFHAND_CLASS_FRAG_GRENADE = 0x1,
		OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
		OFFHAND_CLASS_FLASH_GRENADE = 0x3,
		OFFHAND_CLASS_COUNT = 0x4,
	} OffhandClass;

	typedef enum
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3,
	} weapStance_t;

	typedef enum
	{
		VEH_ACTIVE_RETICLE_NONE = 0x0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
		VEH_ACTIVE_RETICLE_COUNT = 0x3,
	} activeReticleType_t;

	typedef enum
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3,
	} weaponIconRatioType_t;

	typedef enum
	{
		AMMO_COUNTER_CLIP_NONE = 0x0,
		AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
		AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
		AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
		AMMO_COUNTER_CLIP_ROCKET = 0x4,
		AMMO_COUNTER_CLIP_BELTFED = 0x5,
		AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
		AMMO_COUNTER_CLIP_COUNT = 0x7,
	} ammoCounterClipType_t;

	typedef enum
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2,
	} weapOverlayReticle_t;

	typedef enum
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3,
	} WeapOverlayInteface_t;

	typedef enum
	{
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_NONE = 0x3,
		WEAPPROJEXP_DUD = 0x4,
		WEAPPROJEXP_SMOKE = 0x5,
		WEAPPROJEXP_HEAVY = 0x6,
		WEAPPROJEXP_NUM = 0x7,
	} weapProjExposion_t;

	typedef enum
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_GROUND = 0x2,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x3,
		WEAPSTICKINESS_COUNT = 0x4,
	} WeapStickinessType;

	typedef enum
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_COUNT = 0x4,
	} guidedMissileType_t;

	typedef struct
	{
		const char* szInternalName;
		const char* szDisplayName;
		const char* szOverlayName;
		XModel* gunXModel[16];
		XModel* handXModel;
		const char* szXAnims[33];
		const char* szModeName;
		unsigned __int16 hideTags[8];
		unsigned __int16 notetrackSoundMapKeys[16];
		unsigned __int16 notetrackSoundMapValues[16];
		int playerAnimType;
		weapType_t weapType;
		weapClass_t weapClass;
		PenetrateType penetrateType;
		ImpactType impactType;
		weapInventoryType_t inventoryType;
		weapFireType_t fireType;
		OffhandClass offhandClass;
		weapStance_t stance;
		FxEffectDef* viewFlashEffect;
		FxEffectDef* worldFlashEffect;
		snd_alias_list_t* pickupSound;
		snd_alias_list_t* pickupSoundPlayer;
		snd_alias_list_t* ammoPickupSound;
		snd_alias_list_t* ammoPickupSoundPlayer;
		snd_alias_list_t* projectileSound;
		snd_alias_list_t* pullbackSound;
		snd_alias_list_t* pullbackSoundPlayer;
		snd_alias_list_t* fireSound;
		snd_alias_list_t* fireSoundPlayer;
		snd_alias_list_t* fireLoopSound;
		snd_alias_list_t* fireLoopSoundPlayer;
		snd_alias_list_t* fireStopSound;
		snd_alias_list_t* fireStopSoundPlayer;
		snd_alias_list_t* fireLastSound;
		snd_alias_list_t* fireLastSoundPlayer;
		snd_alias_list_t* emptyFireSound;
		snd_alias_list_t* emptyFireSoundPlayer;
		snd_alias_list_t* meleeSwipeSound;
		snd_alias_list_t* meleeSwipeSoundPlayer;
		snd_alias_list_t* meleeHitSound;
		snd_alias_list_t* meleeMissSound;
		snd_alias_list_t* rechamberSound;
		snd_alias_list_t* rechamberSoundPlayer;
		snd_alias_list_t* reloadSound;
		snd_alias_list_t* reloadSoundPlayer;
		snd_alias_list_t* reloadEmptySound;
		snd_alias_list_t* reloadEmptySoundPlayer;
		snd_alias_list_t* reloadStartSound;
		snd_alias_list_t* reloadStartSoundPlayer;
		snd_alias_list_t* reloadEndSound;
		snd_alias_list_t* reloadEndSoundPlayer;
		snd_alias_list_t* detonateSound;
		snd_alias_list_t* detonateSoundPlayer;
		snd_alias_list_t* nightVisionWearSound;
		snd_alias_list_t* nightVisionWearSoundPlayer;
		snd_alias_list_t* nightVisionRemoveSound;
		snd_alias_list_t* nightVisionRemoveSoundPlayer;
		snd_alias_list_t* altSwitchSound;
		snd_alias_list_t* altSwitchSoundPlayer;
		snd_alias_list_t* raiseSound;
		snd_alias_list_t* raiseSoundPlayer;
		snd_alias_list_t* firstRaiseSound;
		snd_alias_list_t* firstRaiseSoundPlayer;
		snd_alias_list_t* putawaySound;
		snd_alias_list_t* putawaySoundPlayer;
		snd_alias_list_t** bounceSound;
		FxEffectDef* viewShellEjectEffect;
		FxEffectDef* worldShellEjectEffect;
		FxEffectDef* viewLastShotEjectEffect;
		FxEffectDef* worldLastShotEjectEffect;
		Material* reticleCenter;
		Material* reticleSide;
		int iReticleCenterSize;
		int iReticleSideSize;
		int iReticleMinOfs;
		activeReticleType_t activeReticleType;
		float vStandMove[3];
		float vStandRot[3];
		float vDuckedOfs[3];
		float vDuckedMove[3];
		float vDuckedRot[3];
		float vProneOfs[3];
		float vProneMove[3];
		float vProneRot[3];
		float fPosMoveRate;
		float fPosProneMoveRate;
		float fStandMoveMinSpeed;
		float fDuckedMoveMinSpeed;
		float fProneMoveMinSpeed;
		float fPosRotRate;
		float fPosProneRotRate;
		float fStandRotMinSpeed;
		float fDuckedRotMinSpeed;
		float fProneRotMinSpeed;
		XModel* worldModel[16];
		XModel* worldClipModel;
		XModel* rocketModel;
		XModel* knifeModel;
		XModel* worldKnifeModel;
		Material* hudIcon;
		weaponIconRatioType_t hudIconRatio;
		Material* ammoCounterIcon;
		weaponIconRatioType_t ammoCounterIconRatio;
		ammoCounterClipType_t ammoCounterClip;
		int iStartAmmo;
		const char* szAmmoName;
		int iAmmoIndex;
		const char* szClipName;
		int iClipIndex;
		int iMaxAmmo;
		int iClipSize;
		int shotCount;
		const char* szSharedAmmoCapName;
		int iSharedAmmoCapIndex;
		int iSharedAmmoCap;
		int damage;
		int playerDamage;
		int iMeleeDamage;
		int iDamageType;
		int iFireDelay;
		int iMeleeDelay;
		int meleeChargeDelay;
		int iDetonateDelay;
		int iFireTime;
		int iRechamberTime;
		int iRechamberBoltTime;
		int iHoldFireTime;
		int iDetonateTime;
		int iMeleeTime;
		int meleeChargeTime;
		int iReloadTime;
		int reloadShowRocketTime;
		int iReloadEmptyTime;
		int iReloadAddTime;
		int iReloadStartTime;
		int iReloadStartAddTime;
		int iReloadEndTime;
		int iDropTime;
		int iRaiseTime;
		int iAltDropTime;
		int iAltRaiseTime;
		int quickDropTime;
		int quickRaiseTime;
		int iFirstRaiseTime;
		int iEmptyRaiseTime;
		int iEmptyDropTime;
		int sprintInTime;
		int sprintLoopTime;
		int sprintOutTime;
		int nightVisionWearTime;
		int nightVisionWearTimeFadeOutEnd;
		int nightVisionWearTimePowerUp;
		int nightVisionRemoveTime;
		int nightVisionRemoveTimePowerDown;
		int nightVisionRemoveTimeFadeInStart;
		int fuseTime;
		int aiFuseTime;
		int requireLockonToFire;
		int noAdsWhenMagEmpty;
		int avoidDropCleanup;
		float autoAimRange;
		float aimAssistRange;
		float aimAssistRangeAds;
		float aimPadding;
		float enemyCrosshairRange;
		int crosshairColorChange;
		float moveSpeedScale;
		float adsMoveSpeedScale;
		float sprintDurationScale;
		float fAdsZoomFov;
		float fAdsZoomInFrac;
		float fAdsZoomOutFrac;
		Material* overlayMaterial;
		Material* overlayMaterialLowRes;
		weapOverlayReticle_t overlayReticle;
		WeapOverlayInteface_t overlayInterface;
		float overlayWidth;
		float overlayHeight;
		float fAdsBobFactor;
		float fAdsViewBobMult;
		float fHipSpreadStandMin;
		float fHipSpreadDuckedMin;
		float fHipSpreadProneMin;
		float hipSpreadStandMax;
		float hipSpreadDuckedMax;
		float hipSpreadProneMax;
		float fHipSpreadDecayRate;
		float fHipSpreadFireAdd;
		float fHipSpreadTurnAdd;
		float fHipSpreadMoveAdd;
		float fHipSpreadDuckedDecay;
		float fHipSpreadProneDecay;
		float fHipReticleSidePos;
		int iAdsTransInTime;
		int iAdsTransOutTime;
		float fAdsIdleAmount;
		float fHipIdleAmount;
		float adsIdleSpeed;
		float hipIdleSpeed;
		float fIdleCrouchFactor;
		float fIdleProneFactor;
		float fGunMaxPitch;
		float fGunMaxYaw;
		float swayMaxAngle;
		float swayLerpSpeed;
		float swayPitchScale;
		float swayYawScale;
		float swayHorizScale;
		float swayVertScale;
		float swayShellShockScale;
		float adsSwayMaxAngle;
		float adsSwayLerpSpeed;
		float adsSwayPitchScale;
		float adsSwayYawScale;
		float adsSwayHorizScale;
		float adsSwayVertScale;
		int bRifleBullet;
		int armorPiercing;
		int bBoltAction;
		int aimDownSight;
		int bRechamberWhileAds;
		float adsViewErrorMin;
		float adsViewErrorMax;
		int bCookOffHold;
		int bClipOnly;
		int adsFireOnly;
		int cancelAutoHolsterWhenEmpty;
		int suppressAmmoReserveDisplay;
		int enhanced;
		int laserSightDuringNightvision;
		Material* killIcon;
		weaponIconRatioType_t killIconRatio;
		int flipKillIcon;
		Material* dpadIcon;
		weaponIconRatioType_t dpadIconRatio;
		int bNoPartialReload;
		int bSegmentedReload;
		int iReloadAmmoAdd;
		int iReloadStartAdd;
		const char* szAltWeaponName;
		unsigned int altWeaponIndex;
		int iDropAmmoMin;
		int iDropAmmoMax;
		int blocksProne;
		int silenced;
		int iExplosionRadius;
		int iExplosionRadiusMin;
		int iExplosionInnerDamage;
		int iExplosionOuterDamage;
		float damageConeAngle;
		int iProjectileSpeed;
		int iProjectileSpeedUp;
		int iProjectileSpeedForward;
		int iProjectileActivateDist;
		float projLifetime;
		float timeToAccelerate;
		float projectileCurvature;
		XModel* projectileModel;
		weapProjExposion_t projExplosion;
		FxEffectDef* projExplosionEffect;
		int projExplosionEffectForceNormalUp;
		FxEffectDef* projDudEffect;
		snd_alias_list_t* projExplosionSound;
		snd_alias_list_t* projDudSound;
		int bProjImpactExplode;
		WeapStickinessType stickiness;
		int hasDetonator;
		int timedDetonation;
		int rotate;
		int holdButtonToThrow;
		int freezeMovementWhenFiring;
		int lowAmmoWarningThreshold;
		float parallelBounce[29];
		float perpendicularBounce[29];
		FxEffectDef* projTrailEffect;
		float vProjectileColor[3];
		guidedMissileType_t guidedMissileType;
		float maxSteeringAccel;
		int projIgnitionDelay;
		FxEffectDef* projIgnitionEffect;
		snd_alias_list_t* projIgnitionSound;
		float fAdsAimPitch;
		float fAdsCrosshairInFrac;
		float fAdsCrosshairOutFrac;
		int adsGunKickReducedKickBullets;
		float adsGunKickReducedKickPercent;
		float fAdsGunKickPitchMin;
		float fAdsGunKickPitchMax;
		float fAdsGunKickYawMin;
		float fAdsGunKickYawMax;
		float fAdsGunKickAccel;
		float fAdsGunKickSpeedMax;
		float fAdsGunKickSpeedDecay;
		float fAdsGunKickStaticDecay;
		float fAdsViewKickPitchMin;
		float fAdsViewKickPitchMax;
		float fAdsViewKickYawMin;
		float fAdsViewKickYawMax;
		float fAdsViewKickCenterSpeed;
		float fAdsViewScatterMin;
		float fAdsViewScatterMax;
		float fAdsSpread;
		int hipGunKickReducedKickBullets;
		float hipGunKickReducedKickPercent;
		float fHipGunKickPitchMin;
		float fHipGunKickPitchMax;
		float fHipGunKickYawMin;
		float fHipGunKickYawMax;
		float fHipGunKickAccel;
		float fHipGunKickSpeedMax;
		float fHipGunKickSpeedDecay;
		float fHipGunKickStaticDecay;
		float fHipViewKickPitchMin;
		float fHipViewKickPitchMax;
		float fHipViewKickYawMin;
		float fHipViewKickYawMax;
		float fHipViewKickCenterSpeed;
		float fHipViewScatterMin;
		float fHipViewScatterMax;
		float fightDist;
		float maxDist;
		const char* accuracyGraphName[2];
		float(*accuracyGraphKnots[2])[2];
		float(*originalAccuracyGraphKnots[2])[2];
		int accuracyGraphKnotCount[2];
		int originalAccuracyGraphKnotCount[2];
		int iPositionReloadTransTime;
		float leftArc;
		float rightArc;
		float topArc;
		float bottomArc;
		float accuracy;
		float aiSpread;
		float playerSpread;
		float minTurnSpeed[2];
		float maxTurnSpeed[2];
		float pitchConvergenceTime;
		float yawConvergenceTime;
		float suppressTime;
		float maxRange;
		float fAnimHorRotateInc;
		float fPlayerPositionDist;
		const char* szUseHintString;
		const char* dropHintString;
		int iUseHintStringIndex;
		int dropHintStringIndex;
		float horizViewJitter;
		float vertViewJitter;
		const char* szScript;
		float fOOPosAnimLength[2];
		int minDamage;
		int minPlayerDamage;
		float fMaxDamageRange;
		float fMinDamageRange;
		float destabilizationRateTime;
		float destabilizationCurvatureMax;
		int destabilizeDistance;
		float locationDamageMultipliers[19];
		const char* fireRumble;
		const char* meleeImpactRumble;
		float adsDofStart;
		float adsDofEnd;
	} WeaponDef;

	typedef struct XZoneInfoInternal
	{
		char name[64];
		int flags;
	} XZoneInfoInternal_t;

	struct XBlock
	{
		char* data;
		unsigned int size;
	};

	struct XZoneMemory
	{
		struct XBlock blocks[9];
		int allocVertexBuffer;
		int allocIndexBuffer;
		int vertexBufferHandle;
		int indexBufferHandle;
	};

#pragma pack(push, 1)
	struct XZone
	{
		struct XZoneInfoInternal zoneinfo;
		int index;
		struct XZoneMemory zonememory;
		int zoneSize;
		int ff_dir;
	};
#pragma pack(pop)

	typedef enum
	{
		ASSET_TYPE_XMODELPIECES,
		ASSET_TYPE_PHYSPRESET,
		ASSET_TYPE_XANIMPARTS,
		ASSET_TYPE_XMODEL,
		ASSET_TYPE_MATERIAL,
		ASSET_TYPE_TECHNIQUE_SET,
		ASSET_TYPE_IMAGE,
		ASSET_TYPE_SOUND,
		ASSET_TYPE_SOUND_CURVE,
		ASSET_TYPE_SOUND_LOADED,
		ASSET_TYPE_CLIPMAP,
		ASSET_TYPE_CLIPMAP_PVS,
		ASSET_TYPE_COMWORLD,
		ASSET_TYPE_GAMEWORLD_SP,
		ASSET_TYPE_GAMEWORLD_MP,
		ASSET_TYPE_MAP_ENTS,
		ASSET_TYPE_GFXWORLD,
		ASSET_TYPE_LIGHT_DEF,
		ASSET_TYPE_UI_MAP,
		ASSET_TYPE_FONT,
		ASSET_TYPE_MENULIST,
		ASSET_TYPE_MENU,
		ASSET_TYPE_LOCALIZE_ENTRY,
		ASSET_TYPE_WEAPON,
		ASSET_TYPE_SNDDRIVER_GLOBALS,
		ASSET_TYPE_FX,
		ASSET_TYPE_IMPACT_FX,
		ASSET_TYPE_AITYPE,
		ASSET_TYPE_MPTYPE,
		ASSET_TYPE_CHARACTER,
		ASSET_TYPE_XMODELALIAS,
		ASSET_TYPE_RAWFILE,
		ASSET_TYPE_STRINGTABLE,
		ASSET_TYPE_COUNT
	} XAssetType;

	typedef struct
	{
		IDirect3DVertexBuffer9* d3dVb;
	} GfxVertexBuffer;

	typedef struct
	{
		struct GfxWorldVertex* vertices;
		GfxVertexBuffer worldVb;
	} GfxWorldVertexData;

	typedef struct
	{
		byte* data;
		GfxVertexBuffer layerVb;
	} GfxWorldVertexLayerData;

#pragma pack(push, 4)
	typedef struct
	{
		char name[64];
		float ambientScale;
		float ambientColor[3];
		float diffuseFraction;
		float sunLight;
		float sunColor[3];
		float diffuseColor[3];
		byte diffuseColorHasBeenSet;
		byte pad[3];
		float angles[3];
	} SunLightParseParams;
#pragma pack(pop)

	typedef struct
	{
		float origin[3];
		struct GfxImage* reflectionImage;
	} GfxReflectionProbe;
	typedef unsigned int raw_uint;
	typedef struct
	{
		int cellCount;
		struct cplane_s* planes;
		uint16_t* nodes;
		raw_uint* dpvsPlanesCells;
	} GfxWorldDpvsPlanes;

#pragma pack(push, 4)
	typedef struct
	{
		byte hasLightRegions;
		byte pad[3];
		unsigned int sunPrimaryLightIndex;
		uint16_t mins[3];
		uint16_t maxs[3];
		unsigned int rowAxis;
		unsigned int colAxis;
		uint16_t* rowDataStart;
		unsigned int rawRowDataSize;
		byte* rawRowData;
		unsigned int entryCount;
		struct GfxLightGridEntry* entries;
		unsigned int colorCount;
		struct GfxLightGridColors* colors;
	} GfxLightGrid;
#pragma pack(pop)

#pragma pack(push, 4)
	typedef struct
	{
		byte hasValidData;
		byte pad[3];
		Material* spriteMaterial;
		Material* flareMaterial;
		float spriteSize;
		float flareMinSize;
		float flareMinDot;
		float flareMaxSize;
		float flareMaxDot;
		float flareMaxAlpha;
		int flareFadeInTime;
		int flareFadeOutTime;
		float blindMinDot;
		float blindMaxDot;
		float blindMaxDarken;
		int blindFadeInTime;
		int blindFadeOutTime;
		float glareMinDot;
		float glareMaxDot;
		float glareMaxLighten;
		int glareFadeInTime;
		int glareFadeOutTime;
		float sunFxPosition[3];
	} sunflare_t;
#pragma pack(pop)

	typedef unsigned int raw_uint128;
	typedef unsigned char raw_byte;
	typedef uint16_t r_index_t;

	typedef struct
	{
		unsigned int smodelCount;
		unsigned int staticSurfaceCount;
		unsigned int litSurfsBegin;
		unsigned int litSurfsEnd;
		unsigned int decalSurfsBegin;
		unsigned int decalSurfsEnd;
		unsigned int emissiveSurfsBegin;
		unsigned int emissiveSurfsEnd;
		unsigned int unk;
		unsigned int lodDataCount;
		unsigned int surfaceCastsSunShadowCount;
		raw_byte* smodelVisData[3];
		raw_byte* surfaceVisData[3];
		raw_uint128* lodData;
		uint16_t* sortedSurfIndex;
		struct GfxStaticModelInst* smodelInsts;
		struct GfxSurface* surfaces;
		struct GfxCullGroup* cullGroups;
		struct GfxStaticModelDrawInst* smodelDrawInsts;
		union GfxDrawSurf* surfaceMaterials;
		raw_uint128* surfaceCastsSunShadow;
		volatile int usageCount;
	} GfxWorldDpvsStatic;
	typedef char raw_byte16;
	typedef struct
	{
		unsigned int dynEntClientWordCount[2];
		unsigned int dynEntClientCount[2];
		raw_uint* dynEntCellBits[2];
		raw_byte16* dynEntVisData[2][3];
	} GfxWorldDpvsDynamic;

#pragma pack(push, 4)
	typedef struct GfxWorld_s
	{
		const char* name;
		const char* baseName;
		int planeCount;
		int nodeCount;
		int indexCount;
		r_index_t* indices;
		int surfaceCount;
		int unk;
		int skySurfCount;
		int* skyStartSurfs;
		struct GfxImage* skyImage;
		byte skySamplerState;
		byte pad[3];
		unsigned int vertexCount;
		GfxWorldVertexData vd;
		unsigned int vertexLayerDataSize;
		GfxWorldVertexLayerData vld;
		SunLightParseParams sunParse;
		struct GfxLight* sunLight;
		float sunColorFromBsp[3];
		unsigned int sunPrimaryLightIndex;
		unsigned int primaryLightCount;
		int cullGroupCount;
		unsigned int reflectionProbeCount;
		GfxReflectionProbe* reflectionProbes;
		union GfxTexture* reflectionProbeTextures;
		GfxWorldDpvsPlanes dpvsPlanes;
		int cellBitsCount;
		struct GfxCell* cells;
		int lightmapCount;
		struct GfxLightmapArray* lightmaps;
		GfxLightGrid lightGrid;
		union GfxTexture* lightmapPrimaryTextures;
		union GfxTexture* lightmapSecondaryTextures;
		int modelCount;
		struct GfxBrushModel* models;
		vec3_t mins;
		vec3_t maxs;
		unsigned int checksum;
		int materialMemoryCount;
		struct MaterialMemory* materialMemory;
		sunflare_t sun;
		float outdoorLookupMatrix[4][4];
		struct GfxImage* outdoorImage;
		raw_uint* cellCasterBits;
		struct GfxSceneDynModel* sceneDynModel;
		struct GfxSceneDynBrush* sceneDynBrush;
		raw_uint* primaryLightEntityShadowVis;
		raw_uint* primaryLightDynEntShadowVis[2];
		raw_byte* primaryLightForModelDynEnt;
		struct GfxShadowGeometry* shadowGeom;
		struct GfxLightRegion* lightRegion;
		GfxWorldDpvsStatic dpvs;
		GfxWorldDpvsDynamic dpvsDyn;
	} GfxWorld;
#pragma pack(pop)

#pragma pack(push, 2)
	typedef struct
	{
		uint16_t letter;
		char x0;
		char y0;
		char dx;
		char pixelWidth;
		char pixelHeight;
		char pad;
		float s0;
		float t0;
		float s1;
		float t1;
	} Glyph;
#pragma pack(pop)

	typedef struct Font_s
	{
		const char* fontName;
		int pixelHeight;
		int glyphCount;
		Material* material;
		Material* glowMaterial;
		Glyph* glyphs;
	} Font_t;

	typedef union
	{
		int intVal;
		float floatVal;
		const char* string;
	} operandInternalDataUnion_t;

	typedef enum OperationEnum_t
	{
		OP_NOOP = 0,
		OP_RIGHTPAREN,
		OP_MULTIPLY,
		OP_DIVIDE,
		OP_MODULUS,
		OP_ADD,
		OP_SUBTRACT,
		OP_NOT,
		OP_LESSTHAN,
		OP_LESSTHANEQUALTO,
		OP_GREATERTHAN,
		OP_GREATERTHANEQUALTO,
		OP_EQUALS,
		OP_NOTEQUAL,
		OP_AND,
		OP_OR,
		OP_LEFTPAREN,
		OP_COMMA,
		OP_BITWISEAND,
		OP_BITWISEOR,
		OP_BITWISENOT,
		OP_BITSHIFTLEFT,
		OP_BITSHIFTRIGHT,
		OP_SIN,
		OP_COS,
		OP_MIN,
		OP_MAX,
		OP_MILLISECONDS,
		OP_DVARINT,
		OP_DVARBOOL,
		OP_DVARFLOAT,
		OP_DVARSTRING,
		OP_STAT,
		OP_UI_ACTIVE,
		OP_FLASHBANGED,
		OP_SCOPED,
		OP_SCOREBOARD_VISIBLE,
		OP_INKILLCAM,
		OP_PLAYER,
		OP_SELECTING_LOCATION,
		OP_TEAM,
		OP_OTHERTEAM,
		OP_MARINES,
		OP_OPFOR,
		OP_MENUISOPEN,
		OP_WRITINGDATA,
		OP_INLOBBY,
		OP_INPRIVATEPARTY,
		OP_PRIVATEPARTYHOST,
		OP_PRIVATEPARTYHOSTINLOBBY,
		OP_ALONEINPARTY,
		OP_ADSJAVELIN,
		OP_WEAPLOCKBLINK,
		OP_WEAPATTACKTOP,
		OP_WEAPATTACKDIRECT,
		OP_SECONDSASTIME,
		OP_TABLELOOKUP,
		OP_LOCSTRING,
		OP_LOCALVARINT,
		OP_LOCALVARBOOL,
		OP_LOCALVARFLOAT,
		OP_LOCALVARSTRING,
		OP_TIMELEFT,
		OP_SECONDSASCOUNTDOWN,
		OP_GAMEMSGWNDACTIVE,
		OP_INT,
		OP_STRING,
		OP_FLOAT,
		OP_GAMETYPENAME,
		OP_GAMETYPE,
		OP_GAMETYPEDESCRIPTION,
		OP_SCOREATRANK,
		OP_FRIENDSONLINE,
		OP_SPECTATINGCLIENT,
		OP_STATRANGEANYBITSSET,
		OP_KEYBINDING,
		OP_ACTIONSLOTUSABLE,
		OP_HUDFADE,
		OP_MAXRECOMMENDEDPLAYERS,
		OP_ACCEPTINGINVITE,
		OP_ISINTERMISSION,
		NUM_OPERATIONS
	} OperationEnum_t;

	typedef enum
	{
		VAL_INT = 0x0,
		VAL_FLOAT = 0x1,
		VAL_STRING = 0x2,
	} expDataType_t;

	typedef struct Operand_s
	{
		expDataType_t dataType;
		operandInternalDataUnion_t internals;
	} Operand_t;

	typedef union EntryInternalData_t
	{
		OperationEnum_t op;
		Operand_t operand;
	} EntryInternalData_t;

	typedef struct expressionEntry_s
	{
		int type;
		EntryInternalData_t data;
	} expressionEntry_t;

	typedef struct statement_s
	{
		int numEntries;
		expressionEntry_t** entries;
	} statement_t;

	typedef struct rectDef_s
	{
		float x;
		float y;
		float w;
		float h;
		int horzAlign;
		int vertAlign;
	} rectDef_t;

	typedef enum ItemDefType_t
	{
		ITEM_TYPE_TEXT = 0,
		ITEM_TYPE_BUTTON,
		ITEM_TYPE_RADIOBUTTON,
		ITEM_TYPE_CHECKBOX,
		ITEM_TYPE_EDITFIELD,
		ITEM_TYPE_COMBO,
		ITEM_TYPE_LISTBOX,
		ITEM_TYPE_MODEL,
		ITEM_TYPE_OWNERDRAW,
		ITEM_TYPE_NUMERICFIELD,
		ITEM_TYPE_SLIDER,
		ITEM_TYPE_YESNO,
		ITEM_TYPE_MULTI,
		ITEM_TYPE_DVARENUM,
		ITEM_TYPE_BIND,
		ITEM_TYPE_MENUMODEL,
		ITEM_TYPE_VALIDFILEFIELD,
		ITEM_TYPE_DECIMALFIELD,
		ITEM_TYPE_UPREDITFIELD,
		ITEM_TYPE_GAME_MESSAGE_WINDOW
	} ItemDefType_t;

	typedef struct windowDef_s
	{
		const char* name;
		rectDef_t rect;
		rectDef_t rectClient;
		const char* group;
		int style;
		int border;
		int ownerDraw;
		int ownerDrawFlags;
		float borderSize;
		int staticFlags;
		int dynamicFlags[NUM_SCREENS];
		int nextTime;
		vec4_t foreColor;
		vec4_t backColor;
		vec4_t borderColor;
		vec4_t outlineColor;
		Material* background;
	} windowDef_t;

	typedef enum ItemDefAlign_t
	{
		HUD_VERTICAL = 0,
		HUD_HORIZONTAL
	} ItemDefAlign_t;

	typedef enum ItemFontType_t
	{
		UI_FONT_DEFAULT = 0,
		UI_FONT_NORMAL,
		UI_FONT_BIG,
		UI_FONT_SMALL,
		UI_FONT_BOLD,
		UI_FONT_CONSOLE,
		UI_FONT_OBJECTIVE
	} ItemFontType_t;

	typedef enum ItemAlign_t
	{
		ITEM_ALIGN_LEGACY_LEFT = 0,
		ITEM_ALIGN_LEGACY_CENTER = 1,
		ITEM_ALIGN_LEGACY_RIGHT = 2,
		ITEM_ALIGN_TOP_LEFT = 4,
		ITEM_ALIGN_TOP_CENTER = 5,
		ITEM_ALIGN_TOP_RIGHT = 6,
		ITEM_ALIGN_MIDDLE_LEFT = 8,
		ITEM_ALIGN_MIDDLE_CENTER = 9,
		ITEM_ALIGN_MIDDLE_RIGHT = 10,
		ITEM_ALIGN_BOTTOM_LEFT = 12,
		ITEM_ALIGN_BOTTOM_CENTER = 13,
		ITEM_ALIGN_BOTTOM_RIGHT = 14
	} ItemAlign_t;

	typedef enum ItemTextStyle_t
	{
		ITEM_TEXTSTYLE_NORMAL = 0,
		ITEM_TEXTSTYLE_BLINK = 1,
		ITEM_TEXTSTYLE_SHADOWED = 3,
		ITEM_TEXTSTYLE_SHADOWEDMORE = 6,
		ITEM_TEXTSTYLE_MONOSPACE = 128
	} ItemTextStyle_t;

	typedef enum ItemMSGWindowMode_t
	{
		MODE_BOTTOMUP_ALIGN_TOP = 0,
		MODE_BOTTOMUP_ALIGN_BOTTOM,
		MODE_TOPDOWN_ALIGN_TOP,
		MODE_TOPDOWN_ALIGN_BOTTOM
	} ItemMSGWindowMode_t;

	typedef struct ItemKeyHandler_s
	{
		int key;
		const char* action;
		struct ItemKeyHandler_s* next;
	} ItemKeyHandler_t;

	typedef enum DvarFlag_t
	{
		DVAR_FLAG_ENABLEDVAR = 1 << 0,
		DVAR_FLAG_DISABLEDVAR = 1 << 1,
		DVAR_FLAG_SHOWDVAR = 1 << 2,
		DVAR_FLAG_HIDEDVAR = 1 << 3,
		DVAR_FLAG_FOCUSDVAR = 1 << 4
	} DvarFlag_t;

	typedef struct editFieldDef_s
	{
		float minVal;
		float maxVal;
		float defVal;
		float range;
		int maxChars;
		int maxCharsGotoNext;
		int maxPaintChars;
		int paintOffset;
	} editFieldDef_t;

	typedef struct multiDef_s
	{
		const char* cvarList[32];
		const char* cvarStr[32];
		float cvarValue[32];
		int count;
		int strDef;
	} multiDef_t;

	typedef struct columnInfo_s
	{
		int pos;
		int width;
		int maxChars;
		int alignment;
	} columnInfo_t;

	typedef struct listBoxDef_s
	{
		int startPos[NUM_SCREENS];
		int endPos[NUM_SCREENS];
		int drawPadding;
		int cursorPos[NUM_SCREENS];
		float elementWidth;
		float elementHeight;
		int elementStyle;
		int numColumns;
		columnInfo_t columnInfo[16];
		const char* doubleClick;
		int notselectable;
		int noScrollBars;
		int usePaging;
		vec4_t selectBorder;
		vec4_t disableColor;
		Material* selectIcon;
	} listBoxDef_t;

	union itemDefData_t
	{
		listBoxDef_t* listBox;
		editFieldDef_t* editField;
		multiDef_t* multi;
		const char* enumCvarName;
		void* data;
	};

	typedef struct itemDef_t
	{
		windowDef_t window;
		rectDef_t textRect;
		ItemDefType_t type;
		ItemDefType_t dataType;
		ItemDefAlign_t align;
		ItemFontType_t textFont;
		ItemAlign_t textAlign;
		float textAlignX;
		float textAlignY;
		float textScale;
		ItemTextStyle_t textStyle;
		int gameMsgWindowIndex;
		ItemMSGWindowMode_t gameMsgWindowMode;
		const char* text;
		int textSavegame;
		struct menuDef_t* parent;
		const char* mouseEnterText;
		const char* mouseExitText;
		const char* mouseEnter;
		const char* mouseExit;
		const char* action;
		const char* accept;
		const char* onFocus;
		const char* leaveFocus;
		const char* dvar;
		const char* dvarTest;
		ItemKeyHandler_t* onKey;
		const char* onDvar;
		DvarFlag_t dvarFlags;
		snd_alias_list_t* focusSound;
		float feeder;
		int cursorPos;
		itemDefData_t typeData;
		int imageTrack;
		statement_t visibleExp;
		statement_t textExp;
		statement_t materialExp;
		statement_t rectXExp;
		statement_t rectYExp;
		statement_t rectWExp;
		statement_t rectHExp;
		statement_t foreColorAExp;
	} itemDef_t;

	typedef struct menuDef_t
	{
		windowDef_t window;
		const char* font;
		int fullScreen;
		int itemCount;
		int fontIndex;
		int cursorItem;
		int fadeCycle;
		float fadeClamp;
		float fadeAmount;
		float fadeInAmount;
		float blurWorld;
		const char* onOpen;
		const char* onClose;
		const char* onESC;
		ItemKeyHandler_t* onKey;
		statement_t visibleExp;
		const char* allowedBinding;
		const char* soundLoop;
		int imageTrack;
		vec4_t focusColor;
		vec4_t disableColor;
		statement_t rectXExp;
		statement_t rectYExp;
		itemDef_t** items;
	} menuDef_t;

	typedef struct MenuList
	{
		const char* name;
		int menuCount;
		menuDef_t** menus;
	} MenuList;

	typedef struct
	{
		const char* value;
		const char* name;
	} LocalizeEntry;

	typedef struct
	{
		const char* name;
		struct FxImpactEntry* table;
	} FxImpactTable;

	typedef struct
	{
		const char* name;
		int len;
		const char* buffer;
	} RawFile;

	typedef struct
	{
		const char* name;
		int columnCount;
		int rowCount;
		const char** values;
	} StringTable;

	typedef union
	{
		XAnimParts* parts;
		XModel* model;
		Material* material;
		struct MaterialTechniqueSet* techniqueSet;
		snd_alias_list_t* sound;
		GfxWorld* gfxWorld;
		GfxLightDef* lightDef;
		Font_t* font;
		MenuList* menuList;
		menuDef_t* menu;
		LocalizeEntry* localize;
		WeaponDef* weapon;
		FxImpactTable* impactFx;
		RawFile* rawfile;
		StringTable* stringTable;
		void* data;
	} XAssetHeader;

	struct XAsset
	{
		XAssetType type;
		XAssetHeader header;
	};

	struct XAssetEntry
	{
		struct XAsset asset;
		char zoneIndex;
		bool inuse;
		uint16_t nextHash;
		uint16_t nextOverride;
		uint16_t usageFrame;
	};

	enum dvar_flags : std::uint16_t
	{
		none = 0x0,
		saved = 0x1,
		user_info = 0x2,
		server_info = 0x4,
		replicated = 0x8,
		write_protected = 0x10,
		latched = 0x20,
		read_only = 0x40,
		cheat_protected = 0x80,
		temp = 0x100,
		no_restart = 0x400,
		user_created = 0x4000,
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		char color[4];
	};

	enum class dvar_type : std::int8_t
	{
		boolean = 0,
		value = 1,
		vec2 = 2,
		vec3 = 3,
		vec4 = 4,
		integer = 5,
		enumeration = 6,
		string = 7,
		color = 8,
		rgb = 9
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

	struct dvar_s
	{
		const char* name;
		const char* description;
		dvar_flags flags;
		dvar_type type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		bool(__cdecl* domainFunc) (dvar_s*, DvarValue);
		dvar_s* hashNext;
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

	struct Message
	{
		int startTime;
		int endTime;
	};

	struct MessageWindow
	{
		struct MessageLine* lines;
		struct Message* messages;
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

	struct MessageBuffer
	{
		char gamemsgText[4][2048];
		struct MessageWindow gamemsgWindows[4];
		struct MessageLine gamemsgLines[4][12];
		struct Message gamemsgMessages[4][12];
		char miniconText[4096];
		struct MessageWindow miniconWindow;
		struct MessageLine miniconLines[100];
		struct Message miniconMessages[100];
		char errorText[1024];
		struct MessageWindow errorWindow;
		struct MessageLine errorLines[5];
		struct Message errorMessages[5];
	};

	struct Console
	{
		bool initialized;
		struct MessageWindow consoleWindow;
		struct MessageLine consoleLines[1024];
		struct Message consoleMessages[1024];
		char consoleText[32768];
		char textTempLine[512];
		unsigned int lineOffset;
		int displayLineOffset;
		int prevChannel;
		byte outputVisible;
		byte pad[3];
		int fontHeight;
		int visibleLineCount;
		int visiblePixelWidth;
		float screenMin[2];
		float screenMax[2];
		struct MessageBuffer messageBuffer[1];
		vec4_t color;
	};

	struct GfxCodeMatrices
	{
		struct GfxMatrix matrix[32];
	};

	struct GfxCmdBufInput
	{
		float consts[58][4];
		struct GfxImage* codeImages[27];
		char codeImageSamplerStates[27];
		struct GfxBackEndData* data;
	};

	struct GfxSceneDef
	{
		int time;
		float floatTime;
		float viewOffset[3];
	};

	typedef struct
	{
		int x;
		int y;
		int width;
		int height;
	} GfxViewport;

	struct GfxCmdBufSourceState
	{
		struct GfxCodeMatrices matrices;
		struct GfxCmdBufInput input;
		struct GfxViewParms viewParms;
		struct GfxMatrix shadowLookupMatrix;
		unsigned __int16 constVersions[90];
		unsigned __int16 matrixVersions[8];
		float eyeOffset[4];
		unsigned int shadowableLightForShadowLookupMatrix;
		struct GfxScaledPlacement* objectPlacement;
		struct GfxViewParms* viewParms3D;
		unsigned int depthHackFlags;
		struct GfxScaledPlacement skinnedPlacement;
		int cameraView;
		enum GfxViewMode viewMode;
		struct GfxSceneDef sceneDef;
		GfxViewport sceneViewport;
		float materialTime;
		enum GfxViewportBehavior viewportBehavior;
		int renderTargetWidth;
		int renderTargetHeight;
		byte viewportIsDirty;
		unsigned int shadowableLightIndex;
	};

	struct GfxCmdBufPrimStateStream
	{
		unsigned int stride;
		struct D3DVertexBuffer* vb;
		unsigned int offset;
	};

	typedef enum
	{
		VERTDECL_GENERIC = 0x0,
		VERTDECL_PACKED = 0x1,
		VERTDECL_WORLD = 0x2,
		VERTDECL_WORLD_T1N0 = 0x3,
		VERTDECL_WORLD_T1N1 = 0x4,
		VERTDECL_WORLD_T2N0 = 0x5,
		VERTDECL_WORLD_T2N1 = 0x6,
		VERTDECL_WORLD_T2N2 = 0x7,
		VERTDECL_WORLD_T3N0 = 0x8,
		VERTDECL_WORLD_T3N1 = 0x9,
		VERTDECL_WORLD_T3N2 = 0xA,
		VERTDECL_WORLD_T4N0 = 0xB,
		VERTDECL_WORLD_T4N1 = 0xC,
		VERTDECL_WORLD_T4N2 = 0xD,
		VERTDECL_POS_TEX = 0xE,
		VERTDECL_COUNT = 0xF,
	} MaterialVertexDeclType;

	struct GfxCmdBufPrimState
	{
		struct D3DDevice* device;
		struct D3DIndexBuffer* indexBuffer;
		MaterialVertexDeclType vertDeclType;
		struct GfxCmdBufPrimStateStream streams[2];
		struct D3DVertexDeclaration* vertexDecl;
	};

#pragma pack(push, 4)
	struct GfxCmdBufState
	{
		char refSamplerState[16];
		unsigned int samplerState[16];
		union GfxTexture* samplerTexture[16];
		struct GfxCmdBufPrimState prim;
		Material* material;
		MaterialTechniqueType techType;
		struct MaterialTechnique* technique;
		struct MaterialPass* pass;
		unsigned int passIndex;
		enum GfxDepthRangeType depthRangeType;
		float depthRangeNear;
		float depthRangeFar;
		uint64_t vertexShaderConstState[32];
		uint64_t pixelShaderConstState[256];
		byte alphaRef;
		char pad[3];
		unsigned int refStateBits[2];
		unsigned int activeStateBits[2];
		struct MaterialPixelShader* pixelShader;
		struct MaterialVertexShader* vertexShader;
		GfxViewport viewport;
		enum GfxRenderTargetId renderTargetId;
		Material* origMaterial;
		MaterialTechniqueType origTechType;
	};
#pragma pack(pop)
	
	struct fileInIwd_s
	{
		unsigned int pos;
		char* name;
		fileInIwd_s* next;
	};

	struct iwd_t
	{
		char iwdFilename[256];
		char iwdBasename[256];
		char iwdGamename[256];
		char* handle;
		int checksum;
		int pure_checksum;
		volatile int hasOpenFile;
		int numfiles;
		char referenced;
		unsigned int hashSize;
		fileInIwd_s** hashTable;
		fileInIwd_s* buildBuffer;
	};

	typedef struct fileInPack_s
	{
		unsigned long	pos;	// file info position in zip
		char* name;	// name of the file
		struct	fileInPack_s* next;	// next file in the hash
	} fileInPack_t;

#define	MAX_OSPATH 256	

	typedef struct TagunzFile__ { int unused; } unzFile__;
	typedef unzFile__* unzFile;

	typedef struct pack_t 
	{
		char pakFilename[MAX_OSPATH];
		char pakBasename[MAX_OSPATH];
		char pakGamename[MAX_OSPATH];
		unzFile	handle;
		int	checksum;	
		int	pure_checksum;
		int	hasOpenFile;
		int	numFiles;	
		int	referenced;	
		int	hashSize;	
		fileInPack_t** hashTable;	
		fileInPack_t* buildBuffer;
	} pack_t;

	typedef struct 
	{
		char	path[MAX_OSPATH];
		char	gamedir[MAX_OSPATH];
	} directory_t;

	typedef struct searchpath_s 
	{
		struct searchpath_s* next;
		pack_t* pack;
		directory_t* dir;
		bool bLocalized;
		int ignore;
		int ignorePureCheck;
		int language;
	} searchpath_t;
}
