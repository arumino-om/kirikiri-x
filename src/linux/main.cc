#include "libruntime.h"

int main() {
    setlocale(LC_ALL, "");  // これを設定しないと、日本語出力時に文字化けする
    LibRuntime::KrkrRuntime::start_runtime();
}