enable_testing()

add_executable(
    krkrx_test
    main.cc
)

target_link_libraries(
        krkrx_test
        GTest::gtest_main
        runtime
)