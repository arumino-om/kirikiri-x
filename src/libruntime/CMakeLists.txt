cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBRUNTIME_SOURCES)
include_directories(../libsdl2/include)
add_library(libruntime STATIC ${LIBRUNTIME_SOURCES} interfaces/filesystem.h messages.cc messages.h interfaces/console.h graphics.cc graphics.h native_objects/minimal.cc native_objects/minimal.h)
target_link_libraries(libruntime libtjs2)