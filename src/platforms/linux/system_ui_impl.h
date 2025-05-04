#pragma once
#include <map>
#include <mutex>
#include <thread>
#include <gtk-4.0/gtk/gtk.h>

#include "interfaces/system_ui.h"

class LinuxSystemUI: public LibRuntime::Interfaces::ISystemUI {
public:
    LinuxSystemUI();
    ~LinuxSystemUI();
    void show_dialog(const ttstr& title, const ttstr& message) override;
    void show_version_dialog() override;

    static unsigned long generate_dialog_id();

private:
    static std::mutex dialog_present_status_mutex_;
    static std::map<unsigned long, bool> dialog_present_status_;
    static std::thread gtk_work_thread_;
    static GtkApplication* gtk_app_;
    static bool gtk_app_quit_required_;

    struct DialogData {
        std::string title;
        std::string message;
        unsigned long dialog_id;
    };
};
