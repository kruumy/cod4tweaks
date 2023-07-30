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
}