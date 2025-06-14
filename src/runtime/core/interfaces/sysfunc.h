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
        virtual unsigned long long get_tick_time() = 0;
        virtual ttstr get_uuid() = 0;
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

        unsigned long long get_tick_time() override {
            //NOTE: 各プラットフォーム毎で実装する
            return 0;
        }

        ttstr get_uuid() override {
            //NOTE: 各プラットフォーム毎で実装する
            return TJS_W("00000000-0000-0000-0000-000000000000");
        }
    };
}

