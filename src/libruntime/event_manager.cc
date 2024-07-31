#include "event_manager.h"

using namespace LibRuntime;

std::vector<tTJSVariantClosure> EventManager::continuous_handlers;
std::vector<NativeInstances::WindowNativeInstance*> EventManager::window_instances;
bool EventManager::is_event_enabled = true;

bool EventManager::init() {
    return true;
}

void EventManager::add_continuous_handler(tTJSVariantClosure clo) {
    auto iter = std::find(continuous_handlers.begin(), continuous_handlers.end(), clo);
    if (iter != continuous_handlers.end()) return;  //ハンドラがすでにある場合は追加しない

    continuous_handlers.push_back(clo);
    clo.AddRef();
}

void EventManager::remove_continuous_handler(tTJSVariantClosure clo) {
    auto iter = std::find(continuous_handlers.begin(), continuous_handlers.end(), clo);
    if (iter == continuous_handlers.end()) return;  //ハンドラが存在しない場合は何もしない

    continuous_handlers.erase(iter);
    clo.Release();
}

void EventManager::add_window_instance(NativeInstances::WindowNativeInstance *instance) {
    window_instances.push_back(instance);
}

void EventManager::remove_window_instance(const NativeInstances::WindowNativeInstance& instance) {
    auto iter = std::find(window_instances.begin(), window_instances.end(), instance);
    if (iter == window_instances.end()) return;  //インスタンスが存在しない場合は何もしない

    window_instances.erase(iter);
}

void EventManager::dispatch_continuous_event() {
    for (auto clo: continuous_handlers) {
        try {
            clo.FuncCall(0, nullptr, nullptr, nullptr, 0, nullptr, nullptr);
        } catch (...) {

        }
    }
}

void EventManager::dispatch_window_update_event() {
    for (auto window: window_instances) {
        window->update();
    }
}

void EventManager::dispatch_all_events() {
    dispatch_window_update_event();
    dispatch_continuous_event();
}