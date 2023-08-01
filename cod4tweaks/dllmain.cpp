#include "std_include.hpp"

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{   

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