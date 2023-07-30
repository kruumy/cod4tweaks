#pragma once

namespace utils::logger
{
    bool IsInitialized = false;
    template<typename... Args>
    using format_string_t = std::format_string<Args...>;
    template<typename... Args>
    void info(format_string_t<Args...> fmt, Args &&...args)
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
        printf(fmt.get().data(), std::forward<Args>(args)...);
        printf("\n");
    }

}