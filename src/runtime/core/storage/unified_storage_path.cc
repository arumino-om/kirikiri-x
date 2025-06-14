#include "unified_storage_path.h"

using namespace LibRuntime::Storage;

UnifiedStoragePath::UnifiedStoragePath(const ttstr &media_name, const ttstr &domain_name, const ttstr &path) {
    this->media_name = media_name;
    this->domain_name = domain_name; 
    this->path = path;
}

UnifiedStoragePath::~UnifiedStoragePath() {
}

ttstr UnifiedStoragePath::get_media_name() const {
    return media_name;
}

ttstr UnifiedStoragePath::get_domain_name() const {
    return domain_name;
}

ttstr UnifiedStoragePath::get_path() const {
    return path;
}

void UnifiedStoragePath::set_media_name(const ttstr &media_name) {
    this->media_name = media_name;
}

void UnifiedStoragePath::set_domain_name(const ttstr &domain_name) {
    this->domain_name = domain_name;
}

void UnifiedStoragePath::set_path(const ttstr &path) {
    this->path = path;
}

ttstr UnifiedStoragePath::get_fullpath() const {
    return media_name + TJS_W("://") + domain_name + TJS_W("/") + path;
}

UnifiedStoragePath UnifiedStoragePath::parent_directory() const {
    tjs_int last_slash_index = -1;
    for (tjs_int i = path.length() - 1; i >= 0; i--) {
        if (path[i] == TJS_W('/')) {
            last_slash_index = i;
            break;
        }
    }
    if (last_slash_index == -1) {
        return UnifiedStoragePath(media_name, domain_name, TJS_W(""));
    }

    return UnifiedStoragePath(media_name, domain_name, path.AsStdString().substr(0, last_slash_index));
}

ttstr UnifiedStoragePath::filename() const {
    tjs_int last_slash_index = -1;
    for (tjs_int i = path.length() - 1; i >= 0; i--) {
        if (path[i] == TJS_W('/')) {
            last_slash_index = i;
            break;
        }
    }
    if (last_slash_index == -1) {
        return path;
    }
    auto filename = path.AsStdString().substr(last_slash_index + 1);
    return ttstr(filename.c_str());
}

ttstr UnifiedStoragePath::extension() const {
    auto filename = this->filename();
    tjs_int last_dot_index = -1;
    for (tjs_int i = filename.length() - 1; i >= 0; i--) {
        if (filename[i] == TJS_W('.')) {
            last_dot_index = i;
            break;
        }
    }
    if (last_dot_index == -1) {
        return ttstr();
    }
    return ttstr(filename.c_str() + last_dot_index);
}
