#include "environment_impl.h"

#include <unistd.h>
#include <encodings/CharacterSet.h>
#include <linux/limits.h>


ttstr LinuxEnvironemnt::get_env(const ttstr &envname) {
    std::string envname_out;
    TVPUtf16ToUtf8(envname_out, envname.c_str());
    char *env = getenv(envname_out.c_str());
    return {env};
}

void LinuxEnvironemnt::set_env(const ttstr &envname, const ttstr &value) {
    std::string envname_out, value_out;
    TVPUtf16ToUtf8(envname_out, envname.c_str());
    TVPUtf16ToUtf8(value_out, value.c_str());
    setenv(envname_out.c_str(), value_out.c_str(), 1);
}

ttstr LinuxEnvironemnt::get_execution_path() {
    char dest[PATH_MAX] = {};
    readlink("/proc/self/exe", dest, PATH_MAX);
    return {dest};
}


