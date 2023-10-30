#pragma once

#ifdef ERROR
#undef ERROR
#endif

namespace LibRuntime::Interfaces {
    enum MessageBoxType {
        NONE,
        INFO,
        WARNING,
        ERROR
    };

    /**
     * システム関連のGUIへアクセスするためのインターフェース
     */
    class ISystemGUI {
    public:
        virtual int show_message_box(const wchar_t *message, const wchar_t *title, MessageBoxType type) = 0;
    };

    /**
     * ISystemGUI のフォールバック実装
     */
    class SystemGUIFallbackImpl : public ISystemGUI {
    public:
        int show_message_box(const wchar_t *message, const wchar_t *title, MessageBoxType type) override {
            return -1;
        }
    };
}