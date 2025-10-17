add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)

include(GoogleTest)

add_executable(test_my_lib test_my_lib.cpp)
target_link_libraries(test_my_lib PRIVATE my_lib gtest gtest_main)

gtest_discover_tests(test_my_lib)
