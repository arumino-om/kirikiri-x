#include <vector>
#include <windows.h>
#include <cstddef>
#include <cstring>
#include <string>
#include "console_impl.h"
#include "windows_utils.h"

void WindowsConsole::write(const tjs_char *text) {
    char *mbtext = nullptr;
    int convert_result = WindowsUtils::wide2mb(text, mbtext, CP_ACP);
    if (convert_result == -1 || convert_result == 0) return;
    std::cout << mbtext;
    delete mbtext;
}

void WindowsConsole::error(const tjs_char *text) {
    char *mbtext = nullptr;
    int convert_result = WindowsUtils::wide2mb(text, mbtext, CP_ACP);
    if (convert_result == -1 || convert_result == 0) return;
    std::cerr << mbtext;
    delete mbtext;
}

size_t WindowsConsole::readline(tjs_char *&result) {
    auto input_text = new std::string();
    std::getline(std::cin, *input_text);

    int buffer_size = MultiByteToWideChar(CP_ACP, 0, input_text->c_str(), -1, nullptr, 0);
    result = new tjs_char[buffer_size];

    MultiByteToWideChar(CP_ACP, 0, input_text->c_str(), -1, result, buffer_size);

    delete input_text;
    return buffer_size;
}