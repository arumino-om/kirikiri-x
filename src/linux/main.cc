#include "libruntime.h"
#include "systemgui_impl.h"
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");  // これを設定しないと、日本語出力時に文字化けする

    gtk_init(&argc, &argv);
    LibRuntime::KrkrRuntime::system_gui = new LinuxSystemGUI();
    LibRuntime::KrkrRuntime::start_runtime();
}
