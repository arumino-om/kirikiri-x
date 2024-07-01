#include "libruntime.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");  // これを設定しないと、日本語出力時に文字化けする
    LibRuntime::KrkrRuntime::start_runtime(argc, argv);
}