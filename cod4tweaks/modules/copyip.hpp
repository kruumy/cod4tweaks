#pragma once

namespace modules::copyip
{
    void copyip_f(const char** argv, const size_t argc)
    {
        if (game::globals::current_server_ip && strnlen_s(game::globals::current_server_ip, 32) > 0)
        {
            utils::clipboard::CopyToClipboard(game::globals::current_server_ip);
            game::functions::Com_Printf(0,"Copied '%s' to clipboard successfully!", game::globals::current_server_ip);
        }
        else
        {
            game::functions::Com_Printf(0,"Failed copying ip to clipboard :(");
        }
    }

    const game::structs::cmd_function_s* copyip = game::commands::Register("copyip", &copyip_f);
}