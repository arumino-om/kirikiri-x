#pragma once
#include <iostream>
#include "tjsTypes.h"

namespace LibRuntime::Interfaces {
    class IConsole {
    public:
        virtual void write(const tjs_char *text) = 0;
        virtual void error(const tjs_char *text) = 0;
        virtual size_t readline(const tjs_char *&result) = 0;
    };

    class ConsoleFallbackImpl : public IConsole {
    public:
        void write(const tjs_char *text) {
            std::wcout << text;
        }

        void error(const tjs_char *text) {
            std::wcout << text;
        }

        size_t readline(const tjs_char *&result) {
            auto input_text = new std::wstring();
            std::getline(std::wcin, *input_text);

            result = new tjs_char[input_text->length()];
            wcscpy_s(const_cast<tjs_char*>(result), input_text->length(), input_text->c_str());
            return input_text->length();
        }
    };
}
