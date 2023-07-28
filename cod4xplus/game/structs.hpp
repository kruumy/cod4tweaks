#pragma once

#define	MAX_STRING_CHARS	1024
#define	MAX_PLAYERS_IN_GAME	64

namespace game::structs
{
	typedef float vec_t;
	typedef vec_t vec2_t[2];
	typedef vec_t vec3_t[3];
	typedef vec_t vec4_t[4];

	typedef struct entity_s
	{
		__int32 currentValid; //0x0000 
		char _0x0004[24];
		vec3_t lerpOrigin; //0x001C 
		vec3_t lerpAngles; //0x0028 
		char _0x0034[64];
		vec3_t oldOrigin; //0x0074 
		char _0x0080[76];
		__int32 clientNum; //0x00CC 
		__int32 eType; //0x00D0 
		unsigned long eFlags; //0x00D4 
		char _0x00D8[12];
		vec3_t newOrigin; //0x00E4 
		char _0x00F0[160];
		__int32 weapon; //0x0190 
		char _0x0194[44];
		__int32 isAlive; //0x01C0 
		char _0x01C4[24];
	}entity_t;

	typedef struct lerpFrame_s
	{
		float yawAngle;
		int yawing;
		float pitchAngle;
		int pitching;
		int animationNumber;
		void* animation; // animation_t*
		int animationTime;
		float oldFramePos[3];
		float animSpeedScale;
		int oldFrameSnapshotTime;
	}lerpFrame_t;

	typedef struct clientControllers_s
	{
		vec3_t angles[6];
		vec3_t tag_origin_angles;
		vec3_t tag_origin_offset;
	}clientControllers_t;

	enum team_t
	{
		TEAM_FREE = 0x0,
		TEAM_AXIS = 0x1,
		TEAM_ALLIES = 0x2,
		TEAM_SPECTATOR = 0x3,
		TEAM_NUM_TEAMS = 0x4,
	};

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
		void* pXAnimTree; // XAnimTree_s*
		int iDObjWeapon;
		char weaponModel;
		char pad[3];
		int stanceTransitionTime;
		int turnAnimEndTime;
		char turnAnimType;
		char pad2[3];
		int attachedVehEntNum;
		int attachedVehSeat;
		unsigned char hideWeapon;
		unsigned char usingKnife;
	}clientInfo_t;
#pragma pack(pop)


	enum dvar_flags : unsigned short
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

	enum dvar_type : signed char
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
		bool(__cdecl* domainFunc)(dvar_s*, DvarValue);
		dvar_s* hashNext;
	};


}
