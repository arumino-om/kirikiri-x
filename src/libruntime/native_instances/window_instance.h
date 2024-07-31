#pragma once
#include <SDL.h>
#include <tjs.h>
#include <tjsError.h>
#include <tjsNative.h>

namespace LibRuntime::NativeInstances {
    class WindowNativeInstance : public tTJSNativeInstance {
    public:
        WindowNativeInstance();
        tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) override;
        void TJS_INTF_METHOD Invalidate() override;

        void add_object(tTJSVariantClosure clo);
        void remove_object(tTJSVariantClosure clo);
        void update();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        std::vector<tTJSVariantClosure> objects;
    };
}