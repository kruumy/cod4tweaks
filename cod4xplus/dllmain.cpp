#include <Windows.h>
#include <iostream>
#include <string>
#include "game/structs.hpp"
#include "game/functions.hpp"
#include "game/dvars.hpp"
#include "utils/console.hpp"
#include "utils/cmdparser.hpp"
#include "modules/handleargs.hpp"
#include "deps/MinHook.h"
#include "utils/MinHookObject.hpp"
#include "game/globals.hpp"


DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    utils::console::Init();
    std::cout << "Console Initialized" << std::endl;
    modules::handleargs::ApplyArgs(utils::cmdparser(reinterpret_cast<char*>(GetCommandLineA())));
    std::cout << "Arguments Applied" << std::endl;

    while (true)
    {
        if (game::globals::cg_Entities)
        {
            for (size_t i = 0; i < *game::globals::cg_maxPlayers; i++)
            {
                if (game::globals::cg_Entities[i].isAlive)
                {
                    std::cout << game::globals::clientInfo[i].name << " - " << game::globals::cg_Entities[i].clientNum << " - " << game::globals::cg_Entities[i].lerpOrigin[0] << ", " << game::globals::cg_Entities[i].lerpOrigin[1] << ", " << game::globals::cg_Entities[i].lerpOrigin[2] << std::endl;
                }
                
            }
        }
        
        Sleep(100);
    }



    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        HANDLE hThread = CreateThread(NULL, 0, ThreadProc, lpReserved, 0, NULL);
        if (hThread == NULL)
        {
            MessageBox(NULL, L"Failed Creating Thread", L"Error", MB_OK);
            return FALSE;
        }
    }

    return TRUE;
}