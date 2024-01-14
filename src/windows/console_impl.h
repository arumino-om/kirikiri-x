#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "interfaces/console.h"

class WindowsConsole : public LibRuntime::Interfaces::IConsole {
public:
    WindowsConsole();
    ~WindowsConsole();
    void write(const std::wstring &text) override;
    void error(const std::wstring &text) override;
    std::wstring readline() override;

private:
    constexpr static int MAX_INPUT_BUFFER_SIZE = 5;
    HANDLE stdout_handle = nullptr;
    HANDLE stdin_handle = nullptr;
    HANDLE stderr_handle = nullptr;
};
