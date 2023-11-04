#include "windows_utils.h"

int WindowsUtils::wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page) {
    int buffer_size = WideCharToMultiByte(code_page, 0, wtext, -1, nullptr, 0, nullptr, nullptr);
    if (buffer_size == 0) return 0;

    mbtext = new char[buffer_size];
    if (mbtext == nullptr) return -1;

    WideCharToMultiByte(code_page, 0, wtext, -1, mbtext, buffer_size, nullptr, nullptr);

    return 1;
}
