cmake_minimum_required(VERSION 3.21)
project(kirikiri_x LANGUAGES C CXX)

# Add C/C++ definitions
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src/libtjs2)
add_subdirectory(src/libruntime)

# Kirikiri X Executable
if (UNIX)
    # Kirikiri X for Linux
    add_executable(krkrx src/linux/main.cc
            src/linux/sysfunc_impl.cpp
            src/linux/sysfunc_impl.h)
elseif (WIN32)
    # Kirikiri X for Windows
    add_compile_definitions(UNICODE)
    if (MSVC)
        add_compile_options("/source-charset:utf-8")
    endif()
    add_executable(krkrx WIN32
            src/windows/main.cc
            src/windows/filesystem_impl.cc
            src/windows/filesystem_impl.h
            src/windows/console_impl.cc
            src/windows/console_impl.h
            src/windows/localfile_stream.cpp
            src/windows/localfile_stream.h)
    target_link_libraries(krkrx PRIVATE pathcch)
endif (UNIX)

# Add the include directories
target_include_directories(krkrx PRIVATE src/libtjs2)
target_include_directories(krkrx PRIVATE src/libruntime)

# Add and link vcpkg packages
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(krkrx
        PRIVATE
        SDL2::SDL2main
        libtjs2
        libruntime
)
