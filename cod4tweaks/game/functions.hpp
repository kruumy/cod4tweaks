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
    typedef HWND (*R_InitGraphicsApi_t)();
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

    //Dvar_RegisterString
    typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterString_t)(const char* dvar_name, game::structs::dvar_type type_string, std::uint16_t flags, const char* description, const char* default_value, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t null4, std::int32_t null5);
    const Dvar_RegisterString_t Dvar_RegisterString = reinterpret_cast<Dvar_RegisterString_t>(0x56C130);
    game::structs::dvar_s* Dvar_RegisterString_Wrapped(const char* dvar_name, const char* description, const char* default_value, std::uint16_t flags)
    {
        const auto dvar = game::functions::Dvar_FindMalleableVar(dvar_name);
        if (!dvar)
        {
            return game::functions::Dvar_RegisterString(dvar_name, game::structs::string, flags, description, default_value, 0, 0, 0, 0, 0);
        }
        else
        {
            return dvar;
        }
    }

    //Dvar_RegisterEnum
    typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterEnum_t)(const char* dvar_name, game::structs::dvar_type type_enum, std::uint16_t flags, const char* description, std::int32_t default_index, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t enumSize, const char** enum_data);
    const Dvar_RegisterEnum_t Dvar_RegisterEnum = reinterpret_cast<Dvar_RegisterEnum_t>(0x56C130);
    game::structs::dvar_s* Dvar_RegisterEnum_Wrapped(const char* dvar_name, const char* description, std::int32_t default_value, std::int32_t enum_size, const char** enum_data, std::uint16_t flags)
    {
        const auto dvar = game::functions::Dvar_FindMalleableVar(dvar_name);
        if (!dvar)
        {
            return game::functions::Dvar_RegisterEnum(dvar_name, game::structs::enumeration, flags, description, default_value, 0, 0, 0, enum_size, enum_data);
        }
        else
        {
            return dvar;
        }
    }

    //Dvar_RegisterInt
    typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterInt_t)(const char* dvarName, game::structs::dvar_type typeInt, std::uint16_t flags, const char* description, std::int32_t defaultValue, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t minValue, std::int32_t maxValue);
    const Dvar_RegisterInt_t Dvar_RegisterInt = reinterpret_cast<Dvar_RegisterInt_t>(0x56C130);
    game::structs::dvar_s* Dvar_RegisterInt_Wrapped(const char* dvar_name, const char* description, std::int32_t default_value, std::int32_t min_value, std::int32_t max_value, std::uint16_t flags)
    {
        const auto dvar = game::functions::Dvar_FindMalleableVar(dvar_name);
        if (!dvar)
        {
            return game::functions::Dvar_RegisterInt(dvar_name, game::structs::dvar_type::integer, flags, description, default_value, 0, 0, 0, min_value, max_value);
        }
        else
        {
            return dvar;
        }
    }

    //Dvar_RegisterBool
    typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterBool_t)(const char* dvar_name, game::structs::dvar_type type_bool, std::uint16_t flags, const char* description, std::int32_t default_value, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t null4, std::int32_t null5);
    const Dvar_RegisterBool_t Dvar_RegisterBool = reinterpret_cast<Dvar_RegisterBool_t>(0x56C130);
    game::structs::dvar_s* Dvar_RegisterBool_Wrapped(const char* dvar_name, const char* description, std::int32_t default_value, std::uint16_t flags)
    {
        const auto dvar = game::functions::Dvar_FindMalleableVar(dvar_name);
        if (!dvar)
        {
            return game::functions::Dvar_RegisterBool(dvar_name, game::structs::boolean, flags, description, default_value, 0, 0, 0, 0, 0);
        }
        else
        {
            return dvar;
        }
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
        data->args = nullptr;
        data->description = nullptr;
        data->function = callback;
        data->next = *game::globals::cmd_ptr;
        *game::globals::cmd_ptr = data;
    }
    void Cmd_AddCommand(const char* name, const char* args, const char* description, void(*callback)(), game::structs::cmd_function_s* data)
    {
        data->name = name;
        data->args = args;
        data->description = description;
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
    typedef void (__cdecl* CG_Respawn_t)(); // int localClientNum  esi 
    const CG_Respawn_t CG_Respawn = reinterpret_cast<CG_Respawn_t>(0x00445FA0);
    
    //CG_Obituary
    typedef void (__cdecl* CG_Obituary_t)(); // int localClientNum  esi, entityState_s*
    const CG_Obituary_t CG_Obituary = reinterpret_cast<CG_Obituary_t>(0x00435620);

    //ClientSpawn
    typedef void(__cdecl* ClientSpawn_t)(game::structs::gentity_s* ent, const float* spawn_origin, const float* spawn_angles);
    const  ClientSpawn_t ClientSpawn = reinterpret_cast<ClientSpawn_t>(0x004AAE40);

    //PlayerCmd_giveWeapon
    typedef void(__cdecl* PlayerCmd_giveWeapon_t)(void* entref); // scr_entref_t*
    const  PlayerCmd_giveWeapon_t PlayerCmd_giveWeapon = reinterpret_cast<PlayerCmd_giveWeapon_t>(0x004AB9C0);

    //R_SetMaterial
    typedef int(__cdecl* R_SetMaterial_t)(game::structs::GfxCmdBufContext* context, game::structs::GfxDrawSurf* drawSurf); // MaterialTechniqueType techType <esi>
    const  R_SetMaterial_t R_SetMaterial = reinterpret_cast<R_SetMaterial_t>(0x00648F10);
}
