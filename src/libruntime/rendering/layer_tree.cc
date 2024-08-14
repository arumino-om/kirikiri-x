#include "layer_tree.h"
#include "../native_instances/layer_instance.h"

using namespace LibRuntime::Rendering;

void LayerTree::add_primary_layer(NativeInstances::LayerNativeInstance *layer) {
    if (primary_layers.size() == 0) {
        primary_layers.push_back(layer);
        return;
    }
}

void LayerTree::remove_primary_layer(NativeInstances::LayerNativeInstance *layer) {
    std::erase(primary_layers, layer);
}

void LayerTree::render(SDL_Renderer *renderer) {
    for (auto layer : primary_layers) {
        layer->render(renderer);
    }
}