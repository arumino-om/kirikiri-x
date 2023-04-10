cmake_minimum_required(VERSION 3.13)

add_compile_options(-fpermissive)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBTJS2_SOURCES)
list(REMOVE_ITEM LIBTJS2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tjsDateWordMap.cc)
add_library(libtjs2 STATIC ${LIBTJS2_SOURCES})