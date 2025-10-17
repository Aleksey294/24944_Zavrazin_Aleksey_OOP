cmake_minimum_required(VERSION 3.10)
project(HW04)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build tests" ON)

add_library(book book.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE book)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
