cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBTJS2_SOURCES)
list(REMOVE_ITEM LIBTJS2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tjsDateWordMap.cc)

add_library(libtjs2 STATIC ${LIBTJS2_SOURCES} coreutils/cp932_uni.cpp coreutils/cp932_uni.h coreutils/uni_cp932.cpp coreutils/uni_cp932.h)
target_link_libraries(libtjs2 onig)