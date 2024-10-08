#pragma once
#include "tjsNative.h"

namespace LibRuntime::NativeClasses {
    /**
     * 動作確認に必要な最小限の機能を実装したクラス。
     */
    class MinimalNativeClass : public tTJSNativeClass {
    public:
        MinimalNativeClass();

        static tjs_uint32 ClassID;
        tTJSNativeInstance *CreateNativeInstance() override;
    };
}