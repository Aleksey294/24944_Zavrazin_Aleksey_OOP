cmake_minimum_required(VERSION 3.10)
project(HW04)

set(CMAKE_CXX_STANDARD 17)

# Исполняемый файл основной программы
add_executable(task task.cpp)

# Опция для сборки тестов
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
