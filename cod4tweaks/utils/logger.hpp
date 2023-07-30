#pragma once

namespace utils::logger
{
    bool IsInitialized = false;
    template<typename... Args>
    void info(const char* Format, Args... args)
    {
        if (!IsInitialized)
        {
            AllocConsole();
            HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
            FILE* console_output;
            freopen_s(&console_output, "CONOUT$", "w", stdout);
            IsInitialized = true;
            info("Initialized Logger");
        }
        printf("[cod4tweaks] ");
        printf(Format, args...);
        printf("\n");
    }

}