add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)
include(GoogleTest)

add_executable(test_book test_book.cpp)
target_link_libraries(test_book PRIVATE book gtest gtest_main)
gtest_discover_tests(test_book)
