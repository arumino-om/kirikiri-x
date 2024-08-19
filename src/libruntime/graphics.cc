#include "graphics.h"
#include "SDL.h"

using namespace LibRuntime;

bool Graphics::init() {
    return SDL_Init(SDL_INIT_VIDEO) > 0;
}

SDL_Window *Graphics::new_window(const char *title, int x, int y, int w, int h, Uint32 flags) {
    
    return SDL_CreateWindow(title, x, y, w, h, flags);
}