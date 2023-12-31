#pragma once

namespace game::functions
{
	//Dvar_FindMalleableVar
	typedef game::structs::dvar_s* (__cdecl* Dvar_FindMalleableVar_t)();
	const Dvar_FindMalleableVar_t Dvar_FindMalleableVar_Internal = reinterpret_cast<Dvar_FindMalleableVar_t>(0x56B5D0);
	game::structs::dvar_s* Dvar_FindMalleableVar(const char* dvar)
	{
		__asm mov edi, dvar
		return Dvar_FindMalleableVar_Internal();
	}

	//CL_Vid_Restart_f
	typedef int (*CL_Vid_Restart_f_t)();
	const CL_Vid_Restart_f_t CL_Vid_Restart_f = reinterpret_cast<CL_Vid_Restart_f_t>(0x0046A180);

	//R_InitGraphicsApi
	typedef HWND(*R_InitGraphicsApi_t)();
	const R_InitGraphicsApi_t R_InitGraphicsApi = reinterpret_cast<R_InitGraphicsApi_t>(0x005F4CC0);

	//Cbuf_AddText
	typedef void (*Cbuf_AddText_t)(); // __usercall const char* text <eax>, int local_client_num <ecx>
	const Cbuf_AddText_t Cbuf_AddText_Internal = reinterpret_cast<Cbuf_AddText_t>(0x4F8D90);
	void Cbuf_AddText(const char* text, int local_client_num)
	{
		const static uint32_t Cbuf_AddText_func = (uint32_t)Cbuf_AddText_Internal;
		__asm
		{
			mov		ecx, local_client_num;
			mov		eax, text;
			call	Cbuf_AddText_func;
		}
	}

	//ClientConnect
	typedef char* (__cdecl* ClientConnect_t)(int clientNum, unsigned __int16 scriptPersID);
	const ClientConnect_t ClientConnect = reinterpret_cast<ClientConnect_t>(0x004AABC0);

	//R_EndFrame
	typedef void(__cdecl* R_BeginFrame_t)();
	const R_BeginFrame_t R_BeginFrame = reinterpret_cast<R_BeginFrame_t>(0x005F75A0);

	//R_EndFrame
	typedef void(__cdecl* R_EndFrame_t)();
	const R_EndFrame_t R_EndFrame = reinterpret_cast<R_EndFrame_t>(0x005F7680);

	//Material_RegisterHandle
	typedef game::structs::Material* (__cdecl* Material_RegisterHandle_t)(const char* fontName, int fontSize);
	const Material_RegisterHandle_t Material_RegisterHandle = reinterpret_cast<Material_RegisterHandle_t>(0x5F2A80);

	//Dvar_RegisterNew
	typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterNew_t)(const char* dvar_name, game::structs::dvar_type type, std::uint16_t flags, const char* description, int x, int y, int z, int w, int min, int max);
	const Dvar_RegisterNew_t Dvar_RegisterNew = reinterpret_cast<Dvar_RegisterNew_t>(0x56C130);

	//Dvar_RegisterString
	game::structs::dvar_s* Dvar_RegisterString(const char* dvar_name, const char* description, const char* default_value, std::uint16_t flags)
	{
		const auto dvar = game::functions::Dvar_FindMalleableVar(dvar_name);
		if (!dvar)
		{
			return Dvar_RegisterNew(dvar_name, game::structs::dvar_type::string, flags, description, reinterpret_cast<int>(default_value), 0, 0, 0, 0, 0);
		}
		else
		{
			return dvar;
		}
	}

	//Dvar_ReregisterInt
	typedef int(__cdecl* Dvar_ReregisterInt_t)(const char* dvar_name, game::structs::dvar_type type, const char* description, int x, int y, int z, int w, int min, int max); // game::structs::dvar_s* dvar <eax>, std::uint32_t flags <edi>, 
	const  Dvar_ReregisterInt_t Dvar_ReregisterInt_Internal = reinterpret_cast<Dvar_ReregisterInt_t>(0x56BFF0);
	void Dvar_ReregisterInt(game::structs::dvar_s* dvar, std::uint32_t flags, const char* dvar_name, game::structs::dvar_type dvar_type, const char* description, int x, int y, int z, int w, int min, int max)
	{
		// https://github.com/xoxor4d/iw3xo-dev/blob/develop/src/game/functions.cpp#L1110
		__asm
		{
			pushad;
			push	max;
			push	min;
			push	w;
			push	z;
			push	y;
			push	x;
			push	description;
			push	dvar_type;
			push	dvar_name;

			mov		edi, flags;
			mov		eax, [dvar];

			call	Dvar_ReregisterInt_Internal;
			add		esp, 24h;
			popad;
		}
	}
	game::structs::dvar_s* Dvar_ReregisterInt_Wrapped(const char* dvar_name, game::structs::dvar_type type, std::uint16_t flags, const char* description, int x, int y, int z, int w, int min, int max)
	{
		const auto dvar = Dvar_FindMalleableVar(dvar_name);
		if (!dvar)
		{
			return Dvar_RegisterNew(dvar_name, type, flags, description, x, y, z, w, min, max);
		}
		Dvar_ReregisterInt(dvar, flags, dvar_name, type, description, x, y, z, w, min, max);
		return dvar;
	}

	//Dvar_RegisterInt
	game::structs::dvar_s* Dvar_RegisterInt(const char* dvar_name, const char* description, std::int32_t default_value, int minValue, int maxValue, std::uint16_t flags)
	{
		return Dvar_ReregisterInt_Wrapped(dvar_name, game::structs::dvar_type::integer, flags, description, default_value, 0, 0, 0, minValue, maxValue);
	}

	//Dvar_RegisterBool
	game::structs::dvar_s* Dvar_RegisterBool(const char* dvar_name, const char* description, std::int32_t default_value, std::uint16_t flags)
	{
		return Dvar_ReregisterInt_Wrapped(dvar_name,game::structs::dvar_type::boolean, flags, description, default_value, 0,0,0,0,1 );
	}

	//Dvar_RegisterEnum
	game::structs::dvar_s* Dvar_RegisterEnum(const char* dvar_name, const char* description, std::int32_t default_value, std::int32_t enum_size, const char** enum_data, std::uint16_t flags)
	{
		return Dvar_ReregisterInt_Wrapped(dvar_name, game::structs::dvar_type::enumeration, flags, description, default_value, 0, 0, 0, enum_size, reinterpret_cast<int>(enum_data));
	}


	//DB_GetAllXAssetOfType
	typedef void(__cdecl* DB_GetAllXAssetOfType_t)(game::structs::XAssetType type, game::structs::XAssetHeader* assets, int maxCount);
	const DB_GetAllXAssetOfType_t DB_GetAllXAssetOfType = reinterpret_cast<DB_GetAllXAssetOfType_t>(0x00489950);

	//DB_EnumXAssets
	typedef void(__cdecl* DB_EnumXAssets_t)(game::structs::XAssetType type, void(__cdecl* func)(game::structs::XAssetHeader* __struct_ptr, void*), void* inData, bool includeOverride);
	const DB_EnumXAssets_t DB_EnumXAssets = reinterpret_cast<DB_EnumXAssets_t>(0x00489120);

	//DB_PrintAssetName
	typedef void(__cdecl* DB_PrintAssetName_t)(game::structs::XAssetHeader* header, void* data);
	const DB_PrintAssetName_t DB_PrintAssetName = reinterpret_cast<DB_PrintAssetName_t>(0x00488E30);

	//Com_Printf
	typedef void(__cdecl* Com_Printf_t)(int channel, const char* Format, ...);
	const Com_Printf_t Com_Printf = reinterpret_cast<Com_Printf_t>(0x004FCBC0);

	//Com_PrintMessage
	typedef void(__cdecl* Com_PrintMessage_t)(int channel, const char* msg, int error);
	const Com_PrintMessage_t Com_PrintMessage = reinterpret_cast<Com_PrintMessage_t>(0x004FCA50);

	//Com_Error
	typedef void(__cdecl* Com_Error_t)(int channel, const char* Format, ...);
	const Com_Error_t Com_Error = reinterpret_cast<Com_Error_t>(0x004FD330);

	//DB_FindXAssetHeader
	typedef game::structs::XAssetHeader* (__cdecl* DB_FindXAssetHeader_t)(game::structs::XAssetType type, const char* name);
	const DB_FindXAssetHeader_t DB_FindXAssetHeader = reinterpret_cast<DB_FindXAssetHeader_t>(0x00489570);

	//Cmd_ExecuteSingleCommand
	typedef void(__cdecl* Cmd_ExecuteSingleCommand_t)(int controller, int a2, const char* cmd);
	const Cmd_ExecuteSingleCommand_t Cmd_ExecuteSingleCommand = reinterpret_cast<Cmd_ExecuteSingleCommand_t>(0x4F9AB0);

	//Cmd_AddCommand, recreated because it is inlined in the binary
	void Cmd_AddCommand(const char* name, void(*callback)(), game::structs::cmd_function_s* data)
	{
		data->name = name;
		data->autocomplete1 = nullptr;
		data->autocomplete2 = nullptr;
		data->function = callback;
		data->next = *game::globals::cmd_ptr;
		*game::globals::cmd_ptr = data;
	}
	void Cmd_AddCommand(const char* name, const char* args, const char* description, void(*callback)(), game::structs::cmd_function_s* data)
	{
		data->name = name;
		data->autocomplete1 = args;
		data->autocomplete2 = description;
		data->function = callback;
		data->next = *game::globals::cmd_ptr;
		*game::globals::cmd_ptr = data;
	}

	//Con_Clear_f
	typedef void(__cdecl* Con_Clear_f_t)();
	const Con_Clear_f_t Con_Clear_f = reinterpret_cast<Con_Clear_f_t>(0x0045D050);

	//SV_AddTestClient
	typedef game::structs::gentity_s* (__cdecl* SV_AddTestClient_t)();
	const SV_AddTestClient_t SV_AddTestClient = reinterpret_cast<SV_AddTestClient_t>(0x0052D370);

	//CG_Respawn
	typedef void(__cdecl* CG_Respawn_t)(); // int localClientNum  esi
	const CG_Respawn_t CG_Respawn = reinterpret_cast<CG_Respawn_t>(0x00445FA0);

	//CG_Obituary
	typedef void(__cdecl* CG_Obituary_t)(); // int localClientNum  esi, entityState_s*
	const CG_Obituary_t CG_Obituary = reinterpret_cast<CG_Obituary_t>(0x00435620);

	//ClientSpawn
	typedef void(__cdecl* ClientSpawn_t)(game::structs::gentity_s* ent, const float* spawn_origin, const float* spawn_angles);
	const ClientSpawn_t ClientSpawn = reinterpret_cast<ClientSpawn_t>(0x004AAE40);

	//PlayerCmd_giveWeapon
	typedef void(__cdecl* PlayerCmd_giveWeapon_t)(void* entref); // scr_entref_t*
	const PlayerCmd_giveWeapon_t PlayerCmd_giveWeapon = reinterpret_cast<PlayerCmd_giveWeapon_t>(0x004AB9C0);

	//R_SetMaterial
	typedef int(__cdecl* R_SetMaterial_t)(); // MaterialTechniqueType techType <esi>
	const R_SetMaterial_t R_SetMaterial = reinterpret_cast<R_SetMaterial_t>(0x00648F10);

	//Jump_ApplySlowdown
	typedef void(__cdecl* Jump_ApplySlowdown_t)(game::structs::playerState_s* ps);
	const Jump_ApplySlowdown_t Jump_ApplySlowdown = reinterpret_cast<Jump_ApplySlowdown_t>(0x00407990);

	//CL_Connect_f
	typedef void(__cdecl* CL_Connect_f_t)();
	const CL_Connect_f_t CL_Connect_f = reinterpret_cast<CL_Connect_f_t>(0x00471050);

	//G_Spawn
	typedef game::structs::gentity_s* (__cdecl* G_Spawn_t)();
	const G_Spawn_t G_Spawn = reinterpret_cast<G_Spawn_t>(0x4E37F0);

	//CG_SetNextSnap
	typedef int(__cdecl* CG_SetNextSnap_t)(int localClientNum, game::structs::snapshot_s* snap);
	const CG_SetNextSnap_t CG_SetNextSnap = reinterpret_cast<CG_SetNextSnap_t>(0x0044D860);

	//DrawXModelSkinnedCached
	typedef void(*DrawXModelSkinnedCached_t)(int a1, int a2, int a3);
	const DrawXModelSkinnedCached_t DrawXModelSkinnedCached = reinterpret_cast<DrawXModelSkinnedCached_t>(0x646870);

	//iw3mvm_OnKeyEvent
	typedef char(*iw3mvm_OnKeyEvent_t)(int a1, int key, int a3, int a4);
	const iw3mvm_OnKeyEvent_t iw3mvm_OnKeyEvent = reinterpret_cast<iw3mvm_OnKeyEvent_t>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0x16550 : NULL);

	//iw3mvm_printf
	typedef char(*iw3mvm_printf_t)(int color, const char* Format, ...);
	const iw3mvm_printf_t iw3mvm_printf = reinterpret_cast<iw3mvm_printf_t>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0x1F10 : NULL);

	//iw3mvm_AddNode
	typedef char(*iw3mvm_AddNode_t)();
	const iw3mvm_AddNode_t iw3mvm_AddNode = reinterpret_cast<iw3mvm_AddNode_t>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0x9850 : NULL);

	//iw3mvm_PlayDolly
	typedef char(*iw3mvm_PlayDolly_t)();
	const iw3mvm_PlayDolly_t iw3mvm_PlayDolly = reinterpret_cast<iw3mvm_PlayDolly_t>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0x9590 : NULL);
	void iw3mvm_PlayDolly_Wrapped()
	{
		unsigned char* byte_10064B98 = reinterpret_cast<unsigned char*>(game::globals::hiw3mvm + 0x64B98);
		unsigned int* dword_100663D8 = reinterpret_cast<unsigned int*>(game::globals::hiw3mvm + 0x663D8);
		if (*game::globals::iw3mvm_isInDolly)
		{
			// stop dolly
			unsigned int v6 = *dword_100663D8;
			*game::globals::iw3mvm_isInDolly = false;
			if (*dword_100663D8 == 1)
			{
				v6 = 2;
			}
			*byte_10064B98 = 1;
			*dword_100663D8 = v6;
			iw3mvm_printf(4, "Stopped dolly!");
		}
		else
		{
			iw3mvm_PlayDolly();
		}
	}
	
	//iw3mvm_ClearNodes
	typedef char(*iw3mvm_ClearNodes_t)();
	const iw3mvm_ClearNodes_t iw3mvm_ClearNodes = reinterpret_cast<iw3mvm_ClearNodes_t>(game::globals::hiw3mvm ? game::globals::hiw3mvm + 0xBA20 : NULL);
	void iw3mvm_ClearNodes_Wrapped()
	{
		if (!*game::globals::iw3mvm_isInDolly)
		{
			iw3mvm_ClearNodes();
			iw3mvm_printf(3, "Nodes cleared!");
		}
	}

	//GetCalculatedFOV
	typedef double(*GetCalculatedFOV_t)();
	const GetCalculatedFOV_t GetCalculatedFOV = reinterpret_cast<GetCalculatedFOV_t>(0x004503A0);
	
}
