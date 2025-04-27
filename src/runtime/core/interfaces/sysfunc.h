#pragma once
#include "tjs.h"
#include "tjsTypes.h"
#include <fstream>

#include "encodings/CharacterSet.h"

namespace LibRuntime::Interfaces {
    /**
     * その他のシステム関数
     */
    class ISysFunc {
    public:
        virtual void execute(const tjs_char *program, const tjs_char *params) = 0;
        virtual bool create_app_lock(const tjs_char *lockname) = 0;
        virtual void get_os_name(tjs_string &os_name) = 0;
    };

    /**
     * ISysFunc のフォールバック実装
     */
    class SysFuncFallbackImpl : public ISysFunc {
    public:
        void execute(const tjs_char *program, const tjs_char *params) override {
            tjs_string system_text;
            system_text += program;
            if (params != nullptr) {
                system_text += TJS_W(" ");
                system_text += params;
            }

            std::string narrow_text;
            TVPUtf16ToUtf8(narrow_text, system_text);
            system(narrow_text.c_str());
        }

        bool create_app_lock(const tjs_char *lockname) override {
            //NOTE: 各プラットフォーム毎で実装する
            return true;
        }

        void get_os_name(tjs_string &os_name) override {
            os_name = TJS_W("Unknown OS");
        }
    };
}

