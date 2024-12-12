#pragma once
#include "tjs.h"
#include "tjsTypes.h"

namespace LibRuntime::Interfaces {
    class IFilePath {
    public:
        virtual bool get_current_directory(tjs_string &result) = 0;
        virtual bool set_current_directory(tjs_string &result) = 0;

        virtual bool get_home_directory(tjs_string &result) = 0;
        virtual bool get_exe_path(tjs_string &result) = 0;
    };

    class FilePathFallbackImpl : public IFilePath {
    public:
        bool get_current_directory(tjs_string &result) override {
            return false;
        }

        bool set_current_directory(tjs_string &result) override {
            return false;
        }

        bool get_home_directory(tjs_string &result) override {
            return false;
        }

        bool get_exe_path(tjs_string &result) override {
            return false;
        }
    };
}