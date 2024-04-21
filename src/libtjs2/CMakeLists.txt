cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBTJS2_SOURCES)
list(REMOVE_ITEM LIBTJS2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tjsDateWordMap.cc)

add_library(libtjs2 STATIC ${LIBTJS2_SOURCES}
        encodings/CharacterSet.cpp
        encodings/CharacterSet.h
        encodings/cp932_uni.cpp
        encodings/cp932_uni.h
        encodings/uni_cp932.cpp
        encodings/uni_cp932.h)
target_link_libraries(libtjs2 onig)