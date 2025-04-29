#pragma once
#include "./native_instances/layer_instance.h"

using namespace LibRuntime::NativeInstances;

namespace LibRuntime {
    class LayerManager {
    public:
        LayerManager(LayerNativeInstance *primary_layer) {};
        void add_child_layer(LayerNativeInstance *layer) {};
        void remove_child_layer(LayerNativeInstance *layer) {};

    private:
        LayerNativeInstance *primary_layer;
        std::vector<LayerNativeInstance*> layers;
    };
}