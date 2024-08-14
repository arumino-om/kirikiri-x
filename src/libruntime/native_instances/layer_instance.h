#pragma once
#include <tjs.h>
#include <tjsNative.h>
#include <SDL.h>

namespace LibRuntime::NativeInstances {
    class LayerNativeInstance : public tTJSNativeInstance {
    public:
        LayerNativeInstance();
        tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj);
        void TJS_INTF_METHOD Invalidate();

        void add_children(LayerNativeInstance *child);
        void remove_children(LayerNativeInstance *child);

        void render(SDL_Renderer *renderer);

    private:
        tTJSVariantClosure _owner_window;
        tTJSVariantClosure _parent_layer;
        std::vector<LayerNativeInstance *> _children;
    };
}
