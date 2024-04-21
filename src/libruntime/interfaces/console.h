#pragma once
#include <iostream>
#include "tjsTypes.h"
#include "encodings/CharacterSet.h"

namespace LibRuntime::Interfaces {
    class IConsole {
    public:
        virtual void write(const tjs_char *text) = 0;
        virtual void error(const tjs_char *text) = 0;
        virtual size_t readline(tjs_string &result) = 0;
    };

    class ConsoleFallbackImpl : public IConsole {
    public:
        void write(const tjs_char *text) {
            const tjs_string text_string(text);
            std::string out;
            TVPUtf16ToUtf8(out, text_string);
            std::cout << out;
        }

        void error(const tjs_char *text) {
            const tjs_string text_string(text);
            std::string out;
            TVPUtf16ToUtf8(out, text_string);
            std::cerr << out;
        }

        size_t readline(tjs_string &result) {
            auto input_text = new std::string();
            std::getline(std::cin, *input_text);

            auto out = new std::u16string();
            TVPUtf8ToUtf16(*out, *input_text);

            result = *out;

            delete input_text;
            delete out;
            return out->length();
        }
    };
}
