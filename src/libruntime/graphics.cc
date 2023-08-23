#include "graphics.h"
#include "SDL.h"

using namespace LibRuntime;

bool Graphics::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    return true;
}