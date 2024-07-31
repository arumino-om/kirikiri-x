#include "window_instance.h"
#include "../window_manager.h"

using namespace LibRuntime::NativeInstances;

WindowNativeInstance::WindowNativeInstance() {

}

tjs_error TJS_INTF_METHOD WindowNativeInstance::Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) {
    this->window = SDL_CreateWindow(TJS_N("Window"), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 300, 0);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    WindowManager::register_window(this);
    return TJS_S_OK;
}

void TJS_INTF_METHOD WindowNativeInstance::Invalidate() {
    for (auto &obj : objects) {
        obj.Release();
    }
    objects.clear();

    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    WindowManager::unregister_window(this);
}

void WindowNativeInstance::add_object(tTJSVariantClosure clo) {
    if (objects.end() != std::find(objects.begin(), objects.end(), clo)) return;

    objects.push_back(clo);
    clo.AddRef();
}

void WindowNativeInstance::remove_object(tTJSVariantClosure clo) {
    auto it = std::find(objects.begin(), objects.end(), clo);
    if (it == objects.end()) return;

    clo.Release();
    objects.erase(it);
}

void WindowNativeInstance::update() {
    
}
