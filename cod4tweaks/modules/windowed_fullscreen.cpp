#include "windowed_fullscreen.hpp"

void modules::windowed_fullscreen::GetMainMonitorResolution(int& width, int& height)
{
    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);
}

void modules::windowed_fullscreen::WindowFullscreen(HWND Hwnd, int width, int height)
{
    MoveWindow(Hwnd, 0, 0, width, height, true);
    SetWindowLong(Hwnd, -16, 268435456U);
    SetWindowLong(Hwnd, 8, 8U);
    SetWindowPos(Hwnd, 0, 0, 0, width, height, 64U);
}


void modules::windowed_fullscreen::WindowFullscreen(HWND Hwnd)
{
    int width; int height;
    GetMainMonitorResolution(width,height);
    WindowFullscreen(Hwnd,width,height);
}

void modules::windowed_fullscreen::WindowFullscreen()
{
    HWND mainWindowHandle = FindWindow(nullptr, L"Call of Duty 4 X");
    WindowFullscreen(mainWindowHandle);
}
