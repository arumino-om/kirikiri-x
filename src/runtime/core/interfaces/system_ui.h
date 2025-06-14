#pragma once
#include "tjs.h"

namespace LibRuntime::Interfaces {
    /**
     * システムUI
     */
    class ISystemUI {
    public:
        virtual void show_dialog(const ttstr &title, const ttstr &message) = 0;
        virtual void show_version_dialog() = 0;
    };

    /**
     * ISystemUI のフォールバック実装
     */
    class SystemUIFallbackImpl : public ISystemUI {
    public:
        void show_dialog(const ttstr& title, const ttstr& message) override
        {
            // 何もしない
        }

        void show_version_dialog() override
        {
            // 何もしない
        }
    };
}

