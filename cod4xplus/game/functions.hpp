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

    //Dvar_RegisterBool
    typedef game::structs::dvar_s* (*Dvar_RegisterBool_t)(const char* dvar_name, game::structs::DvarType type_bool, game::structs::dvar_flags flags, const char* description, std::int32_t default_value, std::int32_t null1, std::int32_t null2, std::int32_t null3, std::int32_t null4, std::int32_t null5);
    const Dvar_RegisterBool_t Dvar_RegisterBool = reinterpret_cast<Dvar_RegisterBool_t>(0x56C130);
    
    //CL_Vid_Restart_f
    typedef int (*CL_Vid_Restart_f_t)();
    const CL_Vid_Restart_f_t CL_Vid_Restart_f = reinterpret_cast<CL_Vid_Restart_f_t>(0x0046A180);
    
    //R_InitGraphicsApi
    typedef HWND (*R_InitGraphicsApi_t)();
    const R_InitGraphicsApi_t R_InitGraphicsApi = reinterpret_cast<R_InitGraphicsApi_t>(0x005F4CC0);

    //Cbuf_AddText
    typedef void (*Cbuf_AddText_t)();
    const Cbuf_AddText_t Cbuf_AddText_Internal = reinterpret_cast<Cbuf_AddText_t>(0x4F8D90);
    void Cbuf_AddText(const char* text, int local_client_num);

    //G_Spawn
    typedef game::structs::gentity_s* (__cdecl* G_Spawn_t)();
    const G_Spawn_t G_Spawn = reinterpret_cast<G_Spawn_t>(0x4E37F0);

    //ClientConnect
    typedef char* (__cdecl* ClientConnect_t)(int clientNum, unsigned __int16 scriptPersID);
    const ClientConnect_t ClientConnect = reinterpret_cast<ClientConnect_t>(0x004AABC0);

    //ClientEndFrame
    typedef void (__cdecl* ClientEndFrame_t)(game::structs::gentity_s* ent);
    const ClientEndFrame_t ClientEndFrame = reinterpret_cast<ClientEndFrame_t>(0x004A97E0);

}
