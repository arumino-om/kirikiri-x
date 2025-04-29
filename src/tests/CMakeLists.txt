enable_testing()

add_executable(
        krkrx_test
        main.cc
        core/native_instances/rect.cc
)

target_link_libraries(
        krkrx_test
        GTest::gtest_main
        runtime
)