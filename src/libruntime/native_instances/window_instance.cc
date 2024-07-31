#include "window_instance.h"

using namespace LibRuntime::NativeInstances;

WindowNativeInstance::WindowNativeInstance() {

}

tjs_error TJS_INTF_METHOD WindowNativeInstance::Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) {
    this->window = SDL_CreateWindow(TJS_N("Window"), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 300, 0);
    return TJS_S_OK;
}

void WindowNativeInstance::add_object(tTJSVariantClousre clo) {
    if (objects.end() != std::find(objects.begin(), objects.end(), clo)) return;

    objects.push_back(clo);
    clo.AddRef();
}