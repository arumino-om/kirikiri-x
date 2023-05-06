cmake_minimum_required(VERSION 3.13)

add_compile_options(-fpermissive)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBRUNTIME_SOURCES)

add_library(libruntime STATIC ${LIBRUNTIME_SOURCES})