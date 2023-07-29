#pragma once
#include <d3d9.h>

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

	struct GfxImageLoadDef
	{
		char levelCount;
		char flags;
		__int16 dimensions[3];
		int format;
		int resourceSize;
		char data[1];
	};

	enum MaterialVertexDeclType
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
		VERTDECL_STATICMODELCACHE = 0xF,
		VERTDECL_COUNT = 0x10,
	};

	struct gfxVertexSteamsUnk
	{
		unsigned int stride;
		IDirect3DVertexBuffer9* vb;
		unsigned int offset;
	};

	struct GfxCmdBufPrimState
	{
		IDirect3DDevice9* device;
		IDirect3DIndexBuffer9* indexBuffer;
		MaterialVertexDeclType vertDeclType;
		gfxVertexSteamsUnk streams[2];
		IDirect3DVertexDeclaration9* vertexDecl;
	};

	enum MaterialTechniqueType
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
		TECHNIQUE_LIT_END = 0x15,
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
		TECHNIQUE_COUNT = 0x22
	};

#pragma pack(push, 4)
	struct MaterialPass
	{
		struct MaterialVertexDeclaration* vertexDecl;
		struct MaterialVertexShader* vertexShader;
		struct MaterialPixelShader* pixelShader;
		char perPrimArgCount;
		char perObjArgCount;
		char stableArgCount;
		char customSamplerFlags;
		struct MaterialShaderArgument* args;
	};
#pragma pack(pop)

	struct MaterialTechnique
	{
		const char* name;
		unsigned __int16 flags;
		unsigned __int16 passCount;
		struct MaterialPass passArray[1];
	};

	enum MaterialWorldVertexFormat : char
	{
		MTL_WORLDVERT_TEX_1_NRM_1 = 0x0,
		MTL_WORLDVERT_TEX_2_NRM_1 = 0x1,
		MTL_WORLDVERT_TEX_2_NRM_2 = 0x2,
		MTL_WORLDVERT_TEX_3_NRM_1 = 0x3,
		MTL_WORLDVERT_TEX_3_NRM_2 = 0x4,
		MTL_WORLDVERT_TEX_3_NRM_3 = 0x5,
		MTL_WORLDVERT_TEX_4_NRM_1 = 0x6,
		MTL_WORLDVERT_TEX_4_NRM_2 = 0x7,
		MTL_WORLDVERT_TEX_4_NRM_3 = 0x8,
		MTL_WORLDVERT_TEX_5_NRM_1 = 0x9,
		MTL_WORLDVERT_TEX_5_NRM_2 = 0xA,
		MTL_WORLDVERT_TEX_5_NRM_3 = 0xB,
	};

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

	struct MaterialTechniqueSet
	{
		char* name;
		MaterialWorldVertexFormat worldVertFormat;
		bool hasBeenUploaded;
		char unused[1];
		MaterialTechniqueSet* remappedTechniqueSet;
		MaterialTechnique* techniques[34];
	};

#pragma pack(push, 4)
	struct MaterialInfo
	{
		const char* name;
		char gameFlags;
		char sortKey;
		char textureAtlasRowCount;
		char textureAtlasColumnCount;
		GfxDrawSurf drawSurf;
		unsigned int surfaceTypeBits;
		unsigned __int16 hashIndex;
	};
#pragma pack(pop)

	struct WaterWritable
	{
		float floatTime;
	};

	struct complex_s
	{
		float real;
		float imag;
	};

	typedef struct
	{
		WaterWritable writable;
		complex_s* H0;
		float* wTerm;
		int M;
		int N;
		float Lx;
		float Lz;
		float gravity;
		float windvel;
		float winddir[2];
		float amplitude;
		float codeConstant[4];
		struct GfxImage* image;
	} water_t;

	union GfxTexture
	{
		IDirect3DBaseTexture9* basemap;
		IDirect3DTexture9* map;
		IDirect3DVolumeTexture9* volmap;
		IDirect3DCubeTexture9* cubemap;
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


	union MaterialTextureDefInfo
	{
		GfxImage* image;	
		water_t* water;
	};

	struct MaterialTextureDef
	{
		unsigned int nameHash;
		char nameStart;
		char nameEnd;
		char samplerState;
		char semantic;
		MaterialTextureDefInfo u;
	};

	struct MaterialConstantDef
	{
		int nameHash;
		char name[12];
		vec4_t literal;
	};

	struct GfxStateBits
	{
		unsigned int loadBits[2];
	};

	struct Material
	{
		MaterialInfo info;
		char stateBitsEntry[34];
		char textureCount;
		char constantCount;
		char stateBitsCount;
		char stateFlags;
		char cameraRegion;
		MaterialTechniqueSet* techniqueSet;
		MaterialTextureDef* textureTable;
		MaterialConstantDef* constantTable;
		GfxStateBits* stateBitsTable;
	};

	struct MaterialStreamRouting
	{
		char source;
		char dest;
	};

	struct MaterialVertexStreamRouting
	{
		MaterialStreamRouting data[16];
		void* decl[16];
	};

	struct MaterialVertexDeclaration
	{
		char streamCount;
		bool hasOptionalSource;
		bool isLoaded;
		MaterialVertexStreamRouting routing;
	};

	struct MaterialArgumentCodeConst
	{
		unsigned __int16 index;
		char firstRow;
		char rowCount;
	};

	union MaterialArgumentDef
	{
		const float* literalConst;
		MaterialArgumentCodeConst codeConst;
		unsigned int codeSampler;
		unsigned int nameHash;
	};

	struct MaterialShaderArgument
	{
		unsigned __int16 type;
		unsigned __int16 dest;
		MaterialArgumentDef u;
	};



	enum GfxDepthRangeType
	{
		GFX_DEPTH_RANGE_SCENE = 0x0,
		GFX_DEPTH_RANGE_VIEWMODEL = 0x2,
		GFX_DEPTH_RANGE_FULL = 0xFFFFFFFF,
	};

	struct GfxPixelShaderLoadDef
	{
		unsigned int* program;
		unsigned __int16 programSize;
		unsigned __int16 loadForRenderer;
	};

	struct MaterialPixelShaderProgram
	{
		void* ps;
		GfxPixelShaderLoadDef loadDef;
	};

	struct MaterialPixelShader
	{
		const char* name;
		MaterialPixelShaderProgram prog;
	};

	struct GfxVertexShaderLoadDef
	{
		unsigned int* program;
		unsigned __int16 programSize;
		unsigned __int16 loadForRenderer;
	};

	struct MaterialVertexShaderProgram
	{
		void* vs;
		GfxVertexShaderLoadDef loadDef;
	};

	struct MaterialVertexShader
	{
		const char* name;
		MaterialVertexShaderProgram prog;
	};

	struct GfxViewport
	{
		int x;
		int y;
		int width;
		int height;
	};

	enum GfxRenderTargetId
	{
		R_RENDERTARGET_SAVED_SCREEN = 0x0,
		R_RENDERTARGET_FRAME_BUFFER = 0x1,
		R_RENDERTARGET_SCENE = 0x2,
		R_RENDERTARGET_RESOLVED_POST_SUN = 0x3,
		R_RENDERTARGET_RESOLVED_SCENE = 0x4,
		R_RENDERTARGET_FLOAT_Z = 0x5,
		R_RENDERTARGET_DYNAMICSHADOWS = 0x6,
		R_RENDERTARGET_PINGPONG_0 = 0x7,
		R_RENDERTARGET_PINGPONG_1 = 0x8,
		R_RENDERTARGET_SHADOWCOOKIE = 0x9,
		R_RENDERTARGET_SHADOWCOOKIE_BLUR = 0xA,
		R_RENDERTARGET_POST_EFFECT_0 = 0xB,
		R_RENDERTARGET_POST_EFFECT_1 = 0xC,
		R_RENDERTARGET_SHADOWMAP_SUN = 0xD,
		R_RENDERTARGET_SHADOWMAP_SPOT = 0xE,
		R_RENDERTARGET_COUNT = 0xF,
		R_RENDERTARGET_NONE = 0x10,
	};

	struct GfxCmdBufState
	{
		char refSamplerState[16];
		unsigned int samplerState[16];
		GfxTexture* samplerTexture[16];
		GfxCmdBufPrimState prim;
		Material* material;
		MaterialTechniqueType techType;
		MaterialTechnique* technique;
		MaterialPass* pass;
		unsigned int passIndex;
		GfxDepthRangeType depthRangeType;
		float depthRangeNear;
		float depthRangeFar;
		unsigned __int64 vertexShaderConstState[32];
		unsigned __int64 pixelShaderConstState[256];
		char alphaRef;
		unsigned int refStateBits[2];
		unsigned int activeStateBits[2];
		MaterialPixelShader* pixelShader;
		MaterialVertexShader* vertexShader;
		GfxViewport viewport;
		GfxRenderTargetId renderTargetId;
		Material* origMaterial;
		MaterialTechniqueType origTechType;
	};

	struct GfxMatrix
	{
		float m[4][4];
	};


	struct GfxCodeMatrices
	{
		GfxMatrix matrix[32];
	};


	struct FxCodeMeshData
	{
		unsigned int triCount;
		unsigned __int16* indices;
		unsigned __int16 argOffset;
		unsigned __int16 argCount;
		unsigned int pad;
	};

	struct GfxViewParms
	{
		GfxMatrix viewMatrix;
		GfxMatrix projectionMatrix;
		GfxMatrix viewProjectionMatrix;
		GfxMatrix inverseViewProjectionMatrix;
		float origin[4];
		float axis[3][3];
		float depthHackNearClip;
		float zNear;
		float zFar;
	};

	struct GfxPlacement
	{
		float quat[4];
		float origin[3];
	};

	struct GfxScaledPlacement
	{
		GfxPlacement base;
		float scale;
	};

	union GfxColor
	{
		unsigned int packed;
		char array[4];
	};

	struct GfxParticleCloud
	{
		GfxScaledPlacement placement;
		float endpos[3];
		GfxColor color;
		float radius[2];
		unsigned int pad[2];
	};

	struct GfxVertexBufferState
	{
		volatile int used;
		int total;
		IDirect3DVertexBuffer9* buffer;
		char* verts;
	};

	struct GfxMeshData
	{
		unsigned int indexCount;
		unsigned int totalIndexCount;
		unsigned __int16* indices;
		GfxVertexBufferState vb;
		unsigned int vertSize;
	};

	union PackedUnitVec
	{
		unsigned int packed;
		char array[4];
	};

	union PackedTexCoords
	{
		unsigned int packed;
	};

	union PackedLightingCoords
	{
		unsigned int packed;
		char array[4];
	};

	struct GfxSModelCachedVertex
	{
		float xyz[3];
		GfxColor color;
		PackedTexCoords texCoord;
		PackedUnitVec normal;
		PackedUnitVec tangent;
		PackedLightingCoords baseLighting;
	};

	struct GfxModelLightingPatch
	{
		unsigned __int16 modelLightingIndex;
		char primaryLightWeight;
		char colorsCount;
		char groundLighting[4];
		unsigned __int16 colorsWeight[8];
		unsigned __int16 colorsIndex[8];
	};

	struct GfxBackEndPrimitiveData
	{
		int hasSunDirChanged;
	};

	struct GfxEntity
	{
		unsigned int renderFxFlags;
		float materialTime;
	};

	struct FxMarkMeshData
	{
		unsigned int triCount;
		unsigned __int16* indices;
		unsigned __int16 modelIndex;
		char modelTypeAndSurf;
		char pad0;
		unsigned int pad1;
	};

	struct GfxFog
	{
		int startTime;
		int finishTime;
		GfxColor color;
		float fogStart;
		float density;
	};


	struct GfxCmdHeader
	{
		unsigned __int16 id;
		unsigned __int16 byteCount;
	};

	struct GfxCmdArray
	{
		char* cmds;
		int usedTotal;
		int usedCritical;
		GfxCmdHeader* lastCmd;
	};

	enum ShadowType
	{
		SHADOW_NONE = 0x0,
		SHADOW_COOKIE = 0x1,
		SHADOW_MAP = 0x2,
	};

	struct GfxSceneDef
	{
		int time;
		float floatTime;
		float viewOffset[3];
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

	struct GfxDrawSurfListInfo
	{
		GfxDrawSurf* drawSurfs;
		unsigned int drawSurfCount;
		MaterialTechniqueType baseTechType;
		struct GfxViewInfo* viewInfo;
		float viewOrigin[4];
		GfxLight* light;
		int cameraView;
	};

	struct __declspec(align(16)) ShadowCookie
	{
		GfxMatrix shadowLookupMatrix;
		float boxMin[3];
		float boxMax[3];
		GfxViewParms* shadowViewParms;
		float fade;
		unsigned int sceneEntIndex;
		__declspec(align(1)) GfxDrawSurfListInfo casterInfo;
		__declspec(align(1)) GfxDrawSurfListInfo receiverInfo;
	};

	struct __declspec(align(16)) ShadowCookieList
	{
		ShadowCookie cookies[24];
		unsigned int cookieCount;
	};

	struct PointLightPartition
	{
		GfxLight light;
		GfxDrawSurfListInfo info;
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

	struct GfxGlow
	{
		bool enabled;
		float bloomCutoff;
		float bloomDesaturation;
		float bloomIntensity;
		float radius;
	};

	struct GfxSunShadowProjection
	{
		float viewMatrix[4][4];
		float switchPartition[4];
		float shadowmapScale[4];
	};

	struct GfxSunShadowBoundingPoly
	{
		float snapDelta[2];
		int pointCount;
		float points[9][2];
		int pointIsNear[9];
	};

	struct __declspec() GfxSunShadowPartition
	{
		GfxViewParms shadowViewParms;
		int partitionIndex;
		GfxViewport viewport;
		__declspec(align(1)) GfxDrawSurfListInfo info;
		GfxSunShadowBoundingPoly boundingPoly;
	};

	struct GfxSunShadow
	{
		GfxMatrix lookupMatrix;
		GfxSunShadowProjection sunProj;
		GfxSunShadowPartition partition[2];
	};

	struct GfxQuadMeshData
	{
		float x;
		float y;
		float width;
		float height;
		GfxMeshData meshData;
	};

	struct __declspec() GfxSpotShadow
	{
		GfxViewParms shadowViewParms;
		GfxMatrix lookupMatrix;
		char shadowableLightIndex;
		char pad[3];
		GfxLight* light;
		float fade;
		__declspec(align(1)) GfxDrawSurfListInfo info;
		GfxViewport viewport;
		GfxImage* image;
		GfxRenderTargetId renderTargetId;
		float pixelAdjust[4];
		int clearScreen;
		GfxMeshData* clearMesh;
	};

	struct __declspec(align(8)) GfxCmdBufInput
	{
		float consts[58][4];
		GfxImage* codeImages[27];
		char codeImageSamplerStates[27];
		struct GfxBackEndData* data;
	};

	struct GfxViewInfo
	{
		GfxViewParms viewParms;
		GfxSceneDef sceneDef;
		GfxViewport sceneViewport;
		GfxViewport displayViewport;
		GfxViewport scissorViewport;
		ShadowType dynamicShadowType;
		__declspec(align(16)) ShadowCookieList shadowCookieList;
		int localClientNum;
		int isRenderingFullScreen;
		bool needsFloatZ;
		GfxLight shadowableLights[255];
		unsigned int shadowableLightCount;
		PointLightPartition pointLightPartitions[4];
		GfxMeshData pointLightMeshData[4];
		int pointLightCount;
		unsigned int emissiveSpotLightIndex;
		GfxLight emissiveSpotLight;
		int emissiveSpotDrawSurfCount;
		GfxDrawSurf* emissiveSpotDrawSurfs;
		unsigned int emissiveSpotLightCount;
		float blurRadius;
		float frustumPlanes[4][4];
		GfxDepthOfField dof;
		GfxFilm film;
		GfxGlow glow;
		const void* cmds;
		GfxSunShadow sunShadow;
		unsigned int spotShadowCount;
		__declspec() GfxSpotShadow spotShadows[4];
		GfxQuadMeshData* fullSceneViewMesh;
		__declspec(align(1)) GfxDrawSurfListInfo litInfo;
		__declspec(align(1)) GfxDrawSurfListInfo decalInfo;
		__declspec(align(1)) GfxDrawSurfListInfo emissiveInfo;
		struct GfxCmdBufInput input;
	};

	struct trDebugString_t
	{
		float xyz[3];
		float color[4];
		float scale;
		char text[96];
	};

	struct trDebugLine_t
	{
		float start[3];
		float end[3];
		float color[4];
		int depthTest;
	};

	struct GfxDebugPoly
	{
		float color[4];
		int firstVert;
		int vertCount;
	};

	struct GfxDebugPlume
	{
		float origin[3];
		float color[4];
		int score;
		int startTime;
		int duration;
	};

	struct DebugGlobals
	{
		float(*verts)[3];
		int vertCount;
		int vertLimit;
		GfxDebugPoly* polys;
		int polyCount;
		int polyLimit;
		trDebugString_t* strings;
		int stringCount;
		int stringLimit;
		trDebugString_t* externStrings;
		int externStringCount;
		int externMaxStringCount;
		trDebugLine_t* lines;
		int lineCount;
		int lineLimit;
		trDebugLine_t* externLines;
		int externLineCount;
		int externMaxLineCount;
		GfxDebugPlume* plumes;
		int plumeCount;
		int plumeLimit;
	};

	struct __declspec(align(16)) GfxBackEndData // align by 16
	{
		char surfsBuffer[131072];
		FxCodeMeshData codeMeshes[2048];
		unsigned int primDrawSurfsBuf[65536];
		GfxViewParms viewParms[28]; // GfxViewParms either has pad or zFar
		char primaryLightTechType[13][256];
		float codeMeshArgs[256][4];
		GfxParticleCloud clouds[256];
		GfxDrawSurf drawSurfs[32768];
		GfxMeshData codeMesh;
		GfxSModelCachedVertex smcPatchVerts[8192];
		unsigned __int16 smcPatchList[256];
		unsigned int smcPatchCount;
		unsigned int smcPatchVertsUsed;
		GfxModelLightingPatch modelLightingPatchList[4096];
		volatile int modelLightingPatchCount;
		GfxBackEndPrimitiveData prim;
		unsigned int shadowableLightHasShadowMap[8];
		unsigned int frameCount;
		int drawSurfCount;
		volatile int surfPos;
		volatile int gfxEntCount;
		GfxEntity gfxEnts[128];
		volatile int cloudCount;
		volatile int codeMeshCount;
		volatile int codeMeshArgsCount;
		volatile int markMeshCount;
		FxMarkMeshData markMeshes[1536];
		GfxMeshData markMesh;
		GfxVertexBufferState* skinnedCacheVb;
		int IDirect3DQuery9; //IDirect3DQuery9 *endFence
		char* tempSkinBuf;
		volatile int tempSkinPos;
		int IDirect3DIndexBuffer9; // IDirect3DIndexBuffer9 *preTessIb
		int viewParmCount;
		GfxFog fogSettings;
		GfxCmdArray* commands;
		unsigned int viewInfoIndex;
		unsigned int viewInfoCount;
		GfxViewInfo* viewInfo;
		const void* cmds;
		GfxLight sunLight;
		int hasApproxSunDirChanged;
		volatile int primDrawSurfPos;
		unsigned int* staticModelLit;
		DebugGlobals debugGlobals;
		unsigned int drawType;
	};


	

	enum GfxViewportBehavior
	{
		GFX_USE_VIEWPORT_FOR_VIEW = 0x0,
		GFX_USE_VIEWPORT_FULL = 0x1,
	};

	enum GfxViewMode
	{
		VIEW_MODE_NONE = 0x0,
		VIEW_MODE_3D = 0x1,
		VIEW_MODE_2D = 0x2,
		VIEW_MODE_IDENTITY = 0x3,
	};

	struct __declspec(align(16)) GfxCmdBufSourceState
	{
		GfxCodeMatrices matrices;
		GfxCmdBufInput input;
		GfxViewParms viewParms;
		GfxMatrix shadowLookupMatrix;
		unsigned __int16 constVersions[90];
		unsigned __int16 matrixVersions[8];
		float eyeOffset[4];
		unsigned int shadowableLightForShadowLookupMatrix;
		GfxScaledPlacement* objectPlacement;
		GfxViewParms* viewParms3D;
		unsigned int depthHackFlags;
		GfxScaledPlacement skinnedPlacement;
		int cameraView;
		GfxViewMode viewMode;
		GfxSceneDef sceneDef;
		GfxViewport sceneViewport;
		float materialTime;
		GfxViewportBehavior viewportBehavior;
		int renderTargetWidth;
		int renderTargetHeight;
		bool viewportIsDirty;
		unsigned int shadowableLightIndex;
	};

	struct GfxCmdBufContext
	{
		GfxCmdBufSourceState* source;
		GfxCmdBufState* state;
	};
}
