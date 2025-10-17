cmake_minimum_required(VERSION 3.10)
project(CW03)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build Google Tests" ON)

add_library(my_lib my_lib.cpp)

add_executable(clw_3 clw_3.cc)
target_link_libraries(clw_3 PRIVATE my_lib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
