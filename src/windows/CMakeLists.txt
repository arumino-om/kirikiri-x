cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} WINDOWS_SOURCES)

add_executable(krkrs_win ${WINDOWS_SOURCES})
target_link_libraries(krkrs_win PUBLIC onig libtjs2)