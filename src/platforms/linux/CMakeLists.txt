
add_library(linux_impl STATIC
        main.cc
        main.h
        sysfunc_impl.cpp
        sysfunc_impl.h
)

target_include_directories(linux_impl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(linux_impl PRIVATE runtime)