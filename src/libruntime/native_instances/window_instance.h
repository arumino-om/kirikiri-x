#include <SDL.h>
#include <tjs.h>
#include <tjsError.h>
#include <tjsNative.h>

namespace LibRuntime::NativeInstances {
    class WindowNativeInstance : public tTJSNativeInstance {
    public:
        WindowNativeInstance();
        tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj);
        // void TJS_INTF_METHOD Invalidate();

        void add_object(tTJSVariantClosure clo);
    private:
        SDL_Window *window;

        std::vector<tTJSVariantClosure> objects;
    };
}