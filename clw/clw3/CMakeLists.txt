cmake_minimum_required(VERSION 3.10)
project(CW03)
# агрументы в project - имя проекта
set(CMAKE_CXX_STANDARD 17)
# включаем поддержку c++17
option(BUILD_TESTS "Build Google Tests" ON)
# опция для сборки тестов
add_library(my_lib my_lib.cpp)
# создаем библиотеку из my_lib.cpp
add_executable(clw_3 clw_3.cc)
# создаем исполняемый файл из clw_3.cc
target_link_libraries(clw_3 PRIVATE my_lib)
# линкуем библиотеку my_lib с исполняемым файлом clw_3
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
# если опция BUILD_TESTS включена, то включаем поддержку тестов и добавляем поддиректорию tests
# генераторы в Cmake