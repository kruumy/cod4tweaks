#include "functions.hpp"

game::structs::dvar_s* game::functions::Dvar_FindMalleableVar(const char* dvar)
{
    __asm mov edi, dvar
    return Dvar_FindMalleableVar_Internal();
}
void game::functions::Cbuf_AddText(const char* text, int local_client_num)
{
    const static uint32_t Cbuf_AddText_func = (uint32_t)Cbuf_AddText_Internal;
    __asm
    {
        mov		ecx, local_client_num;
        mov		eax, text;
        call	Cbuf_AddText_func;
    }
}

game::structs::dvar_s* game::functions::Dvar_RegisterString_Wrapped(const char* dvar_name, const char* description, const char* default_value, std::uint16_t flags)
{
    const auto dvar = Dvar_FindMalleableVar(dvar_name);
    if (!dvar)
    {
        return Dvar_RegisterString(dvar_name, game::structs::string, flags, description, default_value, 0, 0, 0, 0, 0);
    }
    else
    {
        return dvar;
    }

    
}

