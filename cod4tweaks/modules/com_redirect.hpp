#pragma once

namespace modules::com_redirect
{
	void Com_PrintMessage(int channel, const char* msg, int error);
	utils::MinHookObject<game::functions::Com_PrintMessage_t> Com_PrintMessage_hk(game::functions::Com_PrintMessage, &Com_PrintMessage, true);
    void Com_PrintMessage(int channel, const char* msg, int error)
    {
        if (game::dvars::com_redirect && game::dvars::com_redirect->current.enabled)
        {
            utils::logger::info(msg);
        }
        else
        {
            Com_PrintMessage_hk.GetOriginalFunc()(0,msg,0);
        }
    }

    void Con_Clear_f();
    utils::MinHookObject<game::functions::Con_Clear_f_t> Con_Clear_f_hk(game::functions::Con_Clear_f, &Con_Clear_f, true);
    void Con_Clear_f()
    {
        if (game::dvars::com_redirect && game::dvars::com_redirect->current.enabled)
        {
            system("cls");
        }
        else
        {
            Con_Clear_f_hk.GetOriginalFunc()();
        }
    }
}