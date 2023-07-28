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

