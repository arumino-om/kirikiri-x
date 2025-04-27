cmake_minimum_required(VERSION 3.21)
project(kirikiri_x LANGUAGES C CXX)

# Define the C/C++ standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the subdirectories
add_subdirectory(src/third_party/oniguruma)
add_subdirectory(src/libsdl2 EXCLUDE_FROM_ALL)
add_subdirectory(src/runtime/tjs2)
add_subdirectory(src/runtime/core)

# Add the krkrx executable
if (UNIX)
    # Kirikiri X for Linux
    add_executable(krkrx src/platforms/linux/main.cc
            src/platforms/linux/sysfunc_impl.cpp
            src/platforms/linux/sysfunc_impl.h)
elseif (WIN32)
    # Kirikiri X for Windows
    add_compile_definitions(UNICODE)
    if (MSVC)
#        add_compile_options("/utf-8")
        add_compile_options("/std:c++20")
        add_compile_options("/source-charset:utf-8")
    endif()
    add_executable(krkrx WIN32 src/platforms/windows/main.cc src/platforms/windows/filesystem_impl.cc src/platforms/windows/filesystem_impl.h src/platforms/windows/console_impl.cc src/platforms/windows/console_impl.h
            src/platforms/windows/localfile_stream.cpp
            src/platforms/windows/localfile_stream.h)

    target_link_libraries(krkrx PUBLIC pathcch) # Uses in PathCchCombine()
endif (UNIX)

# Add the include directories
target_include_directories(krkrx PUBLIC src/runtime/tjs2)
target_include_directories(krkrx PUBLIC src/runtime/core)

# Link the SDL2
if(TARGET SDL2::SDL2main)
    target_link_libraries(krkrx PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(krkrx PUBLIC SDL2::SDL2)

# Link other required libraries
target_link_libraries(krkrx PUBLIC onig libtjs2 libruntime)
