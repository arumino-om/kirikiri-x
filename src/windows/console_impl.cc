#include "console_impl.h"

WindowsConsole::WindowsConsole() {
    AllocConsole();

    this->stdin_handle = GetStdHandle(STD_INPUT_HANDLE);
    this->stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
}

WindowsConsole::~WindowsConsole() {
    FreeConsole();
}

void WindowsConsole::write(const std::wstring &text) {
    WriteConsoleW(this->stdout_handle, text.c_str(), (DWORD)text.length(), nullptr, nullptr);
}

void WindowsConsole::error(const std::wstring &text) {
    WriteConsoleW(this->stderr_handle, text.c_str(), (DWORD)text.length(), nullptr, nullptr);
}

std::wstring WindowsConsole::readline() {
    wchar_t input_buffer[WindowsConsole::MAX_INPUT_BUFFER_SIZE] = {};
    DWORD buffer_size = MAX_INPUT_BUFFER_SIZE * sizeof(wchar_t);
    DWORD written;

    auto result = ReadConsoleW(this->stdin_handle, input_buffer, buffer_size, &written, NULL);
    if (result == 0) {
        std::unique_ptr<std::wstring> error_string = std::make_unique<std::wstring>(L"ERROR OCCURRED WHEN READING CONSOLE!!!");
        error_string->append(std::to_wstring(GetLastError()));
        this->error(*error_string);
    } else {
        return std::wstring(input_buffer);
    }
}