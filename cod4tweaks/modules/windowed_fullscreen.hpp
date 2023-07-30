#pragma once
#include <Windows.h>

namespace modules::windowed_fullscreen
{
    void GetMainMonitorResolution(int& width, int& height);
    void WindowFullscreen(HWND Hwnd, int width, int height);
    void WindowFullscreen(HWND Hwnd);
    void WindowFullscreen();
}