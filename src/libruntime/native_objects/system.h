#pragma once
#include <tjsNative.h>

namespace LibRuntime::NativeObjects {
    /**
     * 動作確認に必要な最小限の機能を実装したクラス。
     */
    class SystemNativeClass : public tTJSNativeClass {
    public:
        SystemNativeClass();

        static tjs_uint32 ClassID;
        tTJSNativeInstance *CreateNativeInstance() override;
    };
}