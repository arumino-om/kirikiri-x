#include <vector>
#include <windows.h>
#include "console_impl.h"

void WindowsConsole::write(const tjs_char *text) {
    output(text, &std::cout);
}

void WindowsConsole::error(const tjs_char *text) {
    output(text, &std::cerr);
}

int WindowsConsole::convert_wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page) {
    int buffer_size = WideCharToMultiByte(code_page, 0, wtext, -1, nullptr, 0, nullptr, nullptr);
    if (buffer_size == 0) return 0;

    mbtext = new char[buffer_size];
    if (mbtext == nullptr) return -1;

    WideCharToMultiByte(code_page, 0, wtext, -1, mbtext, buffer_size, nullptr, nullptr);

    return 1;
}

void WindowsConsole::output(const tjs_char *text, std::ostream *out_stream) {
    char *mbtext = nullptr;
    int convert_result = convert_wide2mb(text, mbtext, CP_ACP);

    switch (convert_result) {
        case -1:
            std::cerr << "[ERROR][WindowsConsole] Failed to allocate memory for mbtext." << std::endl;
            break;

        case 0:
            std::cout << "[Debug][WindowsConsole] Buffer size is 0." << std::endl;
            break;

        case 1:
            (*out_stream) << mbtext;
            delete mbtext;
            break;
    }
}