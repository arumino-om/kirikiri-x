#pragma once
#include <tjs.h>

namespace LibRuntime::Interfaces {
    class IEnvironment {
    public:
        virtual ttstr get_env(const ttstr &envname) = 0;
        virtual void set_env(const ttstr &envname, const ttstr &value) = 0;
        virtual ttstr get_execution_path() = 0;
    };

    class EnvironmentFallbackImpl : public IEnvironment {
    public:
        ttstr get_env(const ttstr &envname) override {
            return {};
        };
        void set_env(const ttstr &envname, const ttstr &value) override {
            // 何もしない
        }
        ttstr get_execution_path() override {
            // 何もしない
            return {};
        };
    };
}