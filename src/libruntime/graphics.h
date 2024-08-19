#pragma once
#include <iostream>
#include <SDL.h>
#include "tjsTypes.h"

namespace LibRuntime {
    class Graphics {
    public:
        static bool init();
        static SDL_Window *new_window(const char *title, int x, int y, int w, int h, Uint32 flags);
    };
}
