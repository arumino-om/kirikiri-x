#pragma once
#include <windows.h>

class WindowsUtils {
public:
    static int wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page);
};
