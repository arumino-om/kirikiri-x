#pragma once
#include <tjs.h>
#include <tjsNative.h>

namespace LibRuntime::NativeClasses {
    /**
     * 短形情報を保持するクラス
     */
    class RectNativeClass : public tTJSNativeClass {
    public:
        RectNativeClass();

        static tjs_uint32 ClassID;
        tTJSNativeInstance *CreateNativeInstance() override;
    };
}