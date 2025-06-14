#pragma once
#include <iostream>
#include <tjs.h>
#include "encodings/CharacterSet.h"

namespace LibRuntime::Interfaces {
    class IEnvironment {
    public:
        virtual bool get_execution_path(ttstr &out) = 0;
        virtual bool get_personal_path(ttstr &out) = 0;
        virtual bool get_saved_games_path(ttstr &out) = 0;
        virtual bool get_platform_name(ttstr &out) = 0;
        virtual bool get_os_name(ttstr &os_name) = 0;
    };

    class EnvironmentFallbackImpl : public IEnvironment
    {
    public:
        bool get_execution_path(ttstr &out) override {
            return false;
        }

        bool get_personal_path(ttstr &out) override {
            return false;
        }

        bool get_saved_games_path(ttstr &out) override {
            return false;
        }

        bool get_platform_name(ttstr &out) override {
            out = TJS_W("Unknown Platform");
            return true;
        }

        bool get_os_name(ttstr &os_name) override {
            os_name = TJS_W("Unknown OS");
            return true;
        }
    };
}
