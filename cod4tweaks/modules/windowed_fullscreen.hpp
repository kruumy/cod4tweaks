#pragma once

namespace modules::windowed_fullscreen
{
    void GetMainMonitorResolution(int& width, int& height)
    {
        width = GetSystemMetrics(SM_CXSCREEN);
        height = GetSystemMetrics(SM_CYSCREEN);
    }

    void WindowFullscreen(HWND Hwnd, int width, int height)
    {
        MoveWindow(Hwnd, 0, 0, width, height, true);
        SetWindowLong(Hwnd, -16, 268435456U);
        SetWindowLong(Hwnd, 8, 8U);
        SetWindowPos(Hwnd, 0, 0, 0, width, height, 64U);
    }

    void WindowFullscreen(HWND Hwnd)
    {
        int width; int height;
        GetMainMonitorResolution(width, height);
        WindowFullscreen(Hwnd, width, height);
    }

	typedef BOOL(__stdcall* ShowWindow_t)(HWND hWnd, int nCmdShow);
	BOOL __stdcall ShowWindow_hk(HWND hWnd, int nCmdShow);
	utils::MinHookObject<ShowWindow_t> hook(&ShowWindow, &ShowWindow_hk, true);

	BOOL __stdcall ShowWindow_hk(HWND hWnd, int nCmdShow)
	{
		const BOOL ret = hook.GetOriginalFunc()(hWnd, nCmdShow);
        if (game::dvars::r_windowedfullscreen && game::dvars::r_windowedfullscreen->latched.enabled)
        {
            WindowFullscreen(hWnd);
            game::dvars::r_windowedfullscreen->current.enabled = game::dvars::r_windowedfullscreen->latched.enabled;
            utils::logger::info("Set 0x%0X to windowed fullscreen",hWnd);
        }
        return ret;
	}
}