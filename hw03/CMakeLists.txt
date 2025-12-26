cmake_minimum_required(VERSION 3.10)
project(HW03)
# агрументы в project - имя проекта
set(CMAKE_CXX_STANDARD 17)
# включаем поддержку c++17
option(BUILD_TESTS "Build Google Tests" OFF)
# опция для сборки тестов
add_library(my_lib my_lib.cpp)
# создаем библиотеку из my_lib.cpp
add_executable(hw03 task.cc)
target_link_libraries(hw03 PRIVATE my_lib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
# если опция BUILD_TESTS включена, то включаем поддержку тестов и добавляем поддиректорию tests
# генераторы в Cmake