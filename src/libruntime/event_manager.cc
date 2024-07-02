#include "event_manager.h"

#include <tjsError.h>

using namespace LibRuntime;
std::vector<tTJSVariantClosure> continuous_handlers;

bool EventManager::init() {

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

void EventManager::call_event(int event_id) {
    // 継続的に呼び出されるハンドラ (event_id = 0)
    if (event_id == 0) {
        for (auto clo: continuous_handlers) {
            try {
                clo.FuncCall(0, nullptr, nullptr, nullptr, 0, nullptr, nullptr);
            } catch (...) {

            }
        }
    }
}