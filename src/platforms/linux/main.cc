#include "libruntime.h"
#include "sysfunc_impl.h"
#include <SDL.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");  // これを設定しないと、日本語出力時に文字化けする

    SDL_Init(SDL_INIT_VIDEO);
    LibRuntime::KrkrRuntime::sysfunc = new UnixSysFunc;
    LibRuntime::KrkrRuntime::start_runtime(argc, argv);
    SDL_Quit();
}
