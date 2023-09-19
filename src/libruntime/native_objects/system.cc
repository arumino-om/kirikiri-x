#include "system.h"
#include "libruntime.h"
#include <tjs.h>

using namespace LibRuntime::NativeObjects;

tjs_uint32 SystemNativeClass::ClassID = -1;

SystemNativeClass::SystemNativeClass() : tTJSNativeClass(TJS_W("System"))  {
    TJS_BEGIN_NATIVE_MEMBERS(System)
    TJS_DECL_EMPTY_FINALIZE_METHOD
        // constructor
        TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL_NO_INSTANCE(System)
            return TJS_S_OK;
        TJS_END_NATIVE_CONSTRUCTOR_DECL(System)

        // methods
        TJS_BEGIN_NATIVE_METHOD_DECL(addContinuousHandler)
        TJS_END_NATIVE_STATIC_METHOD_DECL(addContinuousHandler)

        TJS_BEGIN_NATIVE_METHOD_DECL(assignMessage)
        TJS_END_NATIVE_STATIC_METHOD_DECL(assignMessage)

        TJS_BEGIN_NATIVE_METHOD_DECL(createAppLock)
        TJS_END_NATIVE_STATIC_METHOD_DECL(createAppLock)

        TJS_BEGIN_NATIVE_METHOD_DECL(createUUID)
        TJS_END_NATIVE_STATIC_METHOD_DECL(createUUID)

        TJS_BEGIN_NATIVE_METHOD_DECL(doCompact)
        TJS_END_NATIVE_STATIC_METHOD_DECL(doCompact)

        TJS_BEGIN_NATIVE_METHOD_DECL(dumpHeap)
        TJS_END_NATIVE_STATIC_METHOD_DECL(dumpHeap)

        TJS_BEGIN_NATIVE_METHOD_DECL(exit)
        TJS_END_NATIVE_STATIC_METHOD_DECL(exit)

        TJS_BEGIN_NATIVE_METHOD_DECL(getArgument)
        TJS_END_NATIVE_STATIC_METHOD_DECL(getArgument)

        TJS_BEGIN_NATIVE_METHOD_DECL(getKeyState)
        TJS_END_NATIVE_STATIC_METHOD_DECL(getKeyState)

        TJS_BEGIN_NATIVE_METHOD_DECL(getTickCount)
        TJS_END_NATIVE_STATIC_METHOD_DECL(getTickCount)

        TJS_BEGIN_NATIVE_METHOD_DECL(inform)
        TJS_END_NATIVE_STATIC_METHOD_DECL(inform)

        TJS_BEGIN_NATIVE_METHOD_DECL(readRegValue)
        TJS_END_NATIVE_STATIC_METHOD_DECL(readRegValue)

        TJS_BEGIN_NATIVE_METHOD_DECL(removeContinuousHandler)
        TJS_END_NATIVE_STATIC_METHOD_DECL(removeContinuousHandler)

        TJS_BEGIN_NATIVE_METHOD_DECL(setArgument)
        TJS_END_NATIVE_STATIC_METHOD_DECL(setArgument)

        TJS_BEGIN_NATIVE_METHOD_DECL(shellExecute)
        TJS_END_NATIVE_STATIC_METHOD_DECL(shellExecute)

        TJS_BEGIN_NATIVE_METHOD_DECL(showVersion)
        TJS_END_NATIVE_STATIC_METHOD_DECL(showVersion)

        TJS_BEGIN_NATIVE_METHOD_DECL(terminate)
        TJS_END_NATIVE_STATIC_METHOD_DECL(terminate)

        TJS_BEGIN_NATIVE_METHOD_DECL(toActualColor)
        TJS_END_NATIVE_STATIC_METHOD_DECL(toActualColor)

        TJS_BEGIN_NATIVE_METHOD_DECL(touchImages)
        TJS_END_NATIVE_STATIC_METHOD_DECL(touchImages)

        // properties
        //TODO:後で定義
    TJS_END_NATIVE_MEMBERS
}