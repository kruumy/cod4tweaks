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

game::structs::gentity_s* gSpawn();

utils::MinHookObject<game::functions::G_Spawn_t> hook(game::functions::G_Spawn, &gSpawn, true);

game::structs::gentity_s* gSpawn()
{
    std::cout << "G_spawn" << std::endl;
    return hook.GetOriginalFunc()();

}


DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    utils::console::Init();
    std::cout << "Console Initialized" << std::endl;
    modules::handleargs::ApplyArgs(utils::cmdparser(reinterpret_cast<char*>(GetCommandLineA())));
    std::cout << "Arguments Applied" << std::endl;




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