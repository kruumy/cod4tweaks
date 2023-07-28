#include "console.hpp"
#include <iostream>
#include <Windows.h>

void utils::console::Init()
{
    AllocConsole();
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    FILE* console_output;
    freopen_s(&console_output, "CONOUT$", "w", stdout);
}
