#include "systemgui_impl.h"
#include <gtk/gtk.h>

int LinuxSystemGUI::show_message_box(const std::wstring &message, const std::wstring &title,
                                     LibRuntime::Interfaces::MessageBoxType type) {
    // ダイアログの動作確認用コード．後でちゃんとした実装に塗り替える．
    auto dialog = gtk_message_dialog_new(NULL, GtkDialogFlags::GTK_DIALOG_MODAL, GtkMessageType::GTK_MESSAGE_INFO, GtkButtonsType::GTK_BUTTONS_OK, "hello");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    return 0;
}