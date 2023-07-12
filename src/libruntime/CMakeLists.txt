cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBRUNTIME_SOURCES)
add_library(libruntime STATIC ${LIBRUNTIME_SOURCES} interfaces/filesystem.h messages.cc messages.h interfaces/console.h graphics.cc graphics.h)
target_link_libraries(libruntime libtjs2)