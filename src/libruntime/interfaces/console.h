#pragma once
#include <iostream>
#include <string>
#include "tjsTypes.h"

namespace LibRuntime::Interfaces {
    class IConsole {
    public:
        virtual void write(const std::wstring &text) = 0;
        virtual void error(const std::wstring &text) = 0;
        virtual std::wstring readline() = 0;
    };

    class ConsoleFallbackImpl : public IConsole {
    public:
        void write(const std::wstring &text) override {
            std::wcout << text;
        }

        void error(const std::wstring &text) override {
            std::wcerr << text;
        }

        std::wstring readline() override {
            std::wstring result;
            std::getline(std::wcin, result);
            return result;
        }
    };
}
