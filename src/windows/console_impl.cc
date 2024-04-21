#include "console_impl.h"

void WindowsConsole::write(const tjs_char *text) {
    int mbsize = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)text, -1, NULL, 0, NULL, NULL);
    auto mbstr = new char[mbsize];
    WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)text, -1, mbstr, mbsize, NULL, NULL);
    std::cout << mbstr;
}

void WindowsConsole::error(const tjs_char *text) {
    int mbsize = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)text, -1, nullptr, 0, NULL, NULL);
    auto mbstr = new char[mbsize];
    WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)text, -1, mbstr, mbsize, NULL, NULL);
    std::cerr << mbstr;
}

size_t WindowsConsole::readline(tjs_string &result) {
    //TODO: 絵文字が入力できないのをなんとかしたい
    std::wstring readresult;
    std::getline(std::wcin, readresult);

    std::u16string res((const char16_t*)readresult.c_str());
    result = res;
    return result.length();
}

