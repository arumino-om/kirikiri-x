cmake_minimum_required(VERSION 3.13)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBRUNTIME_SOURCES)
include_directories(../libsdl2/include)
add_library(libruntime STATIC ${LIBRUNTIME_SOURCES} interfaces/filesystem.h messages.cc messages.h interfaces/console.h graphics.cc graphics.h native_objects/minimal.cc native_objects/minimal.h
        native_objects/system.cc
        native_objects/system.h
        interfaces/system_gui.h)
target_link_libraries(libruntime libtjs2)