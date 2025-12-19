add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)
# добавляем googletest в проект
include(GoogleTest)
# включаем модуль GoogleTest
add_executable(test_my_lib test_my_lib.cpp)
# создаем исполняемый файл для тестов из test_my_lib.cpp
target_link_libraries(test_my_lib PRIVATE my_lib gtest gtest_main)
# линкуем библиотеку my_lib и googletest с исполняемым файлом тестов
gtest_discover_tests(test_my_lib)
# автоматически находим и регистрируем тесты в test_my_lib