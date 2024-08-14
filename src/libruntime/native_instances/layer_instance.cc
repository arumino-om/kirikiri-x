#include <algorithm>
#include <tjs.h>
#include <tjsNative.h>
#include "layer_instance.h"
#include "window_instance.h"
#include "../native_classes/window.h"
#include "../native_classes/layer.h"
#include "../rendering/layer_tree.h"

using namespace LibRuntime::NativeInstances;

LayerNativeInstance::LayerNativeInstance() {

}

tjs_error LayerNativeInstance::Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) {
    if (numparams < 2) return TJS_E_BADPARAMCOUNT;

    // ウィンドウのオブジェクトを取得
    auto window = param[0]->AsObjectClosure();
    if (window.Object == nullptr) return TJS_E_INVALIDPARAM;

    // 親レイヤーのオブジェクトを取得
    auto parent_layer = param[1]->AsObjectClosure();
    if (parent_layer.Object == nullptr) {
        // 親レイヤーがNullの場合は，自身がプライマリレイヤーとなる
        WindowNativeInstance *window_instance;
        auto nis_result = window.ObjThis->NativeInstanceSupport(TJS_NIS_GETINSTANCE, NativeClasses::WindowNativeClass::ClassID, reinterpret_cast<iTJSNativeInstance **>(&window_instance));
        if (TJS_FAILED(nis_result)) return TJS_E_INVALIDPARAM;

        auto layer_tree = window_instance->get_layer_tree();
        if (layer_tree == nullptr) return TJS_E_INVALIDPARAM;
        layer_tree->add_primary_layer(this);
    } else {
        // 親レイヤーがある場合は，親レイヤーの子に自身を登録
        LayerNativeInstance *parent_layer_instance;
        auto nis_result = parent_layer.ObjThis->NativeInstanceSupport(TJS_NIS_GETINSTANCE, NativeClasses::LayerNativeClass::ClassID, reinterpret_cast<iTJSNativeInstance **>(&parent_layer_instance));
        if (TJS_FAILED(nis_result)) return TJS_E_INVALIDPARAM;

        parent_layer_instance->add_children(this);
        _parent_layer = parent_layer;
    }

    _owner_window = window;

    return TJS_S_OK;
}

void LayerNativeInstance::Invalidate() {
    tTJSNativeInstance::Invalidate();
}

void LayerNativeInstance::add_children(LayerNativeInstance *child) {
    if (std::find(_children.begin(), _children.end(), child) != _children.end()) return;
    _children.push_back(child);
}

void LayerNativeInstance::remove_children(LayerNativeInstance *child) {
    auto iter = std::find(_children.begin(), _children.end(), child);
    if (iter == _children.end()) return;
    _children.erase(iter);
}

void LayerNativeInstance::render(SDL_Renderer *renderer) {

}
