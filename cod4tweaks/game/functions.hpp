#pragma once

#include "structs.hpp"
#include <cstdint>
#include <Windows.h>

namespace game::functions
{

    //Dvar_FindMalleableVar
    typedef game::structs::dvar_s* (__cdecl* Dvar_FindMalleableVar_t)();
    const Dvar_FindMalleableVar_t Dvar_FindMalleableVar_Internal = reinterpret_cast<Dvar_FindMalleableVar_t>(0x56B5D0);
    game::structs::dvar_s* Dvar_FindMalleableVar(const char* dvar);

    //CL_Vid_Restart_f
    typedef int (*CL_Vid_Restart_f_t)();
    const CL_Vid_Restart_f_t CL_Vid_Restart_f = reinterpret_cast<CL_Vid_Restart_f_t>(0x0046A180);
    
    //R_InitGraphicsApi
    typedef HWND (*R_InitGraphicsApi_t)();
    const R_InitGraphicsApi_t R_InitGraphicsApi = reinterpret_cast<R_InitGraphicsApi_t>(0x005F4CC0);

    //Cbuf_AddText
    typedef void (*Cbuf_AddText_t)(); // __usercall const char* text <eax>, int local_client_num <ecx>
    const Cbuf_AddText_t Cbuf_AddText_Internal = reinterpret_cast<Cbuf_AddText_t>(0x4F8D90);
    void Cbuf_AddText(const char* text, int local_client_num);

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
    game::structs::dvar_s* Dvar_RegisterString_Wrapped(const char* dvar_name, const char* description, const char* default_value, std::uint16_t flags);

    //Dvar_RegisterEnum
    typedef game::structs::dvar_s* (__cdecl* Dvar_RegisterEnum_t)(const char* dvar_name, game::structs::dvar_type type_enum, std::uint16_t flags, const char* description, std::int32_t default_index, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t enumSize, const char** enum_data);
    const Dvar_RegisterEnum_t Dvar_RegisterEnum = reinterpret_cast<Dvar_RegisterEnum_t>(0x56C130);
    game::structs::dvar_s* Dvar_RegisterEnum_Wrapped(const char* dvar_name, const char* description, std::int32_t default_value, std::int32_t enum_size, const char** enum_data, std::uint16_t flags);
}