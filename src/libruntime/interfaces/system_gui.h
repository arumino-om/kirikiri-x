#pragma once

namespace LibRuntime::Interfaces {
    enum class MessageBoxType {
        //NOTE: MSGTYPE 接頭辞をつけないと、ERRORが定数に置き換えられてしまう。(Windows環境下なら確定で起きるはず)
        //NOTE: wingdi.h 許すまじ

        MSGTYPE_NONE,
        MSGTYPE_INFO,
        MSGTYPE_WARNING,
        MSGTYPE_ERROR
    };

    /**
     * システム関連のGUIへアクセスするためのインターフェース
     */
    class ISystemGUI {
    public:
        virtual int show_message_box(const std::wstring &message, const std::wstring &title, MessageBoxType type) = 0;
    };

    /**
     * ISystemGUI のフォールバック実装
     */
    class SystemGUIFallbackImpl : public ISystemGUI {
    public:
        int show_message_box(const std::wstring &message, const std::wstring &title, LibRuntime::Interfaces::MessageBoxType type) override {
            // 完全にシステム依存のため、フォールバック実装は不可能。
            return -1;
        }
    };
}