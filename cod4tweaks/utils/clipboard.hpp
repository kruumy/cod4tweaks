#pragma once

namespace utils::clipboard
{
    bool CopyToClipboard(const char* text)
    {
        if (OpenClipboard(nullptr))
        {
            HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strlen(text) + 1);
            if (hMem)
            {
                char* pMem = static_cast<char*>(GlobalLock(hMem));
                if (pMem)
                {
                    strcpy_s(pMem, strlen(text) + 1, text);
                    GlobalUnlock(hMem);
                    EmptyClipboard();
                    SetClipboardData(CF_TEXT, hMem);
                    CloseClipboard();
                    return true;
                }
                GlobalFree(hMem);
            }
            CloseClipboard();
        }

        return false;
    }


}