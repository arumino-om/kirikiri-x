
add_compile_definitions(UNICODE)
if (MSVC)
    #        add_compile_options("/utf-8")
    add_compile_options("/std:c++20")
    add_compile_options("/source-charset:utf-8")
endif()

add_library(win32_impl STATIC
        main.cc
        main.h
        console_impl.cc
        console_impl.h
        filesystem_impl.cc
        filesystem_impl.h
        localfile_stream.cpp
        localfile_stream.h
)


target_link_libraries(win32_impl PRIVATE pathcch runtime) # Uses in PathCchCombine()