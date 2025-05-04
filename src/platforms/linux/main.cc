#include "libruntime.h"
#include "sysfunc_impl.h"
#include "system_ui_impl.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");  // これを設定しないと、日本語出力時に文字化けする
    LibRuntime::KrkrRuntime::sysfunc = new UnixSysFunc;
    LibRuntime::KrkrRuntime::system_ui = new LinuxSystemUI;
    LibRuntime::KrkrRuntime::start_runtime(argc, argv);
}
