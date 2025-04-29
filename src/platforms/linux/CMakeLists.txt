
add_library(linux_impl STATIC
        main.cc
        main.h
        console_impl.cc
        console_impl.h
        filesystem_impl.cc
        filesystem_impl.h
        localfile_stream.cpp
        localfile_stream.h
)

target_include_directories(linux_impl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(linux_impl PRIVATE runtime)