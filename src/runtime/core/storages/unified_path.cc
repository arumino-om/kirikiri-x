#include "unified_path.h"

using namespace LibRuntime::Storages;

UnifiedPath::UnifiedPath() {
    media = ttstr();
    domain = ttstr();
    path = ttstr();
}

UnifiedPath::UnifiedPath(const ttstr &media, const ttstr &domain, const ttstr &path) {
    this->media = media;
    this->domain = domain;
    this->path = path;
}


ttstr UnifiedPath::get_media() const {
    return media;
}

ttstr UnifiedPath::get_domain() const {
    return domain;
}

ttstr UnifiedPath::get_path() const {
    return path;
}

void UnifiedPath::set_media(const ttstr &media) {
    this->media = media;
}

void UnifiedPath::set_domain(const ttstr &domain) {
    this->domain = domain;
}

void UnifiedPath::set_path(const ttstr &path) {
    this->path = path;
}

ttstr UnifiedPath::get_fullpath() const {
    ttstr result;
    result += media;
    result += TJS_W("://");
    result += domain;
    result += TJS_W("/");
    result += path;
    return result;
}

UnifiedPath UnifiedPath::get_parent_path() const {
    for (auto i = path.length() - 1; i >= 0; i--) {
        if (path[i] == '/') {
            return {media, domain, path + i};
        }
    }
    return {};
}