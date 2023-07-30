#include "functions.hpp"
#include "globals.hpp"

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

game::structs::dvar_s* game::functions::Dvar_RegisterEnum_Wrapped(const char* dvar_name, const char* description, std::int32_t default_value, std::int32_t enum_size, const char** enum_data, std::uint16_t flags)
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

void game::functions::Cmd_AddCommand(const char* name, void(*callback)(), game::structs::cmd_function_s* data)
{
    data->name = name;
    data->args = nullptr;		 
    data->description = nullptr; 
    data->function = callback;
    data->next = *game::globals::cmd_ptr;

    *game::globals::cmd_ptr = data;
}

void game::functions::Cmd_AddCommand(const char* name, const char* args, const char* description, void(*callback)(), game::structs::cmd_function_s* data)
{
    data->name = name;
    data->args = args;
    data->description = description;
    data->function = callback;
    data->next = *game::globals::cmd_ptr;

    *game::globals::cmd_ptr = data;
}

