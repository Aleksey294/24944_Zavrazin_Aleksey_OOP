cmake_minimum_required(VERSION 3.10)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0  # или main для последней версии
)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(test_my_lib test_my_lib.cpp)
target_link_libraries(test_my_lib PRIVATE my_lib GTest::gtest_main)
gtest_discover_tests(test_my_lib)
