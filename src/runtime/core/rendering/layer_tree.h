#pragma once
#include <vector>
#include <SDL.h>

namespace LibRuntime {
    namespace NativeInstances {
        class LayerNativeInstance;
    }

    namespace Rendering {
        class LayerTree {
        public:
            void add_primary_layer(NativeInstances::LayerNativeInstance *layer);
            void remove_primary_layer(NativeInstances::LayerNativeInstance *layer);
            void render(SDL_Renderer *renderer);
        private:
            std::vector<NativeInstances::LayerNativeInstance *> primary_layers;
        };
    }
}