#include <vector>
#include <windows.h>
#include <cstddef>
#include <cstring>
#include "console_impl.h"

void WindowsConsole::write(const tjs_char *text) {
    char *mbtext = nullptr;
    int convert_result = convert_wide2mb(text, mbtext, CP_ACP);
    if (convert_result == -1 || convert_result == 0) return;
    std::cout << mbtext;
}

void WindowsConsole::error(const tjs_char *text) {
    char *mbtext = nullptr;
    int convert_result = convert_wide2mb(text, mbtext, CP_ACP);
    if (convert_result == -1 || convert_result == 0) return;
    std::cerr << mbtext;
}

size_t WindowsConsole::readline(const tjs_char *&result) {
    // wcin で受け取ると色々痛い目に合ったので、cinで受け取ってwchar_tに変換する
    auto input_text = new std::string();
    std::getline(std::cin, *input_text);

    // for debug
    std::byte bytes[input_text->length()];
    std::memcpy(bytes, input_text->data(), input_text->length());

    for (auto &b: bytes) {
        std::cout << std::hex << std::to_integer<int>(b) << ' ';
    }
    std::cout << std::endl;

    int buffer_size = MultiByteToWideChar(CP_ACP, 0, input_text->c_str(), -1, nullptr, 0);
    result = new tjs_char[buffer_size];

    MultiByteToWideChar(CP_ACP, 0, input_text->c_str(), -1, const_cast<tjs_char*>(result), buffer_size);
    return buffer_size;
}

int WindowsConsole::convert_wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page) {
    int buffer_size = WideCharToMultiByte(code_page, 0, wtext, -1, nullptr, 0, nullptr, nullptr);
    if (buffer_size == 0) return 0;

    mbtext = new char[buffer_size];
    if (mbtext == nullptr) return -1;

    WideCharToMultiByte(code_page, 0, wtext, -1, mbtext, buffer_size, nullptr, nullptr);

    return 1;
}