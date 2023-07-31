#pragma once

namespace utils::clipboard
{
    void CopyToClipboard(const char* text)
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
                }
            }
            CloseClipboard();
        }
    }
}