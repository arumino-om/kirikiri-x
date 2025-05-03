
add_compile_definitions(UNICODE)

add_library(win32_impl STATIC
        console_impl.cc
        console_impl.h
        filesystem_impl.cc
        filesystem_impl.h
        localfile_stream.cpp
        localfile_stream.h
        system_ui_impl.cc
        system_ui_impl.h
        sysfunc_impl.cc
        sysfunc_impl.h
)

if (MSVC)
    #        add_compile_options("/utf-8")
    add_compile_options("/std:c++20")
    target_compile_definitions(win32_impl PRIVATE IS_MSVC=1)
endif()

target_link_libraries(win32_impl PRIVATE pathcch rpcrt4 comctl32 runtime) # Uses in PathCchCombine()