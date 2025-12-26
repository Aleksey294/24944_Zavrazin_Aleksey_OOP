#include "../my_lib.h"
#include <gtest/gtest.h>
#include <limits>
#include <sstream>

// ==================== ТЕСТЫ ДЛЯ pow ====================
TEST(PowTest, PositiveExponent) {
    EXPECT_EQ(my_lib::pow<int>(3, 2), 9);
    EXPECT_EQ(my_lib::pow<int>(2, 3), 8);
}

TEST(PowTest, PositiveExponentDouble) {
    EXPECT_DOUBLE_EQ(my_lib::pow<double>(2.5, 2), 6.25);
    EXPECT_DOUBLE_EQ(my_lib::pow<double>(3.0, 3), 27.0);
}

TEST(PowTest, ZeroExponent) {
    EXPECT_EQ(my_lib::pow<int>(5, 0), 1);
    EXPECT_EQ(my_lib::pow<int>(0, 0), 1); // 0^0 - математически неопределено!
}

TEST(PowTest, ZeroBase) {
    EXPECT_EQ(my_lib::pow<int>(0, 5), 0);
}

TEST(PowTest, NegativeBase) {
    EXPECT_EQ(my_lib::pow<int>(-2, 2), 4);
    EXPECT_EQ(my_lib::pow<int>(-2, 3), -8);
}

TEST(PowTest, NegativeExponent) {
    EXPECT_DOUBLE_EQ(my_lib::pow<double>(2.0, -1), 0.5);
    EXPECT_DOUBLE_EQ(my_lib::pow<double>(2.0, -2), 0.25);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ pow
TEST(PowTest, BREAK_ZeroToNegativePower) {
    // 0^(-1) = 1/0 - ДЕЛЕНИЕ НА НОЛЬ!
    EXPECT_ANY_THROW(my_lib::pow<double>(0.0, -1));
}

TEST(PowTest, BREAK_HugeExponent) {
    // Огромная степень - переполнение
    int result = my_lib::pow<int>(2, 100);
    // Результат непредсказуем из-за переполнения
    (void)result;
}

TEST(PowTest, BREAK_NegativeBaseNegativeExponent) {
    // (-2)^(-3) может вызвать проблемы
    double result = my_lib::pow<double>(-2.0, -3);
    EXPECT_DOUBLE_EQ(result, -0.125);
}

TEST(PowTest, BREAK_VeryLargeBase) {
    int max = std::numeric_limits<int>::max();
    // Переполнение гарантировано
    my_lib::pow<int>(max, 2);
}

TEST(PowTest, BREAK_ExtremeNegativeExponent) {
    // Очень маленькое число
    my_lib::pow<double>(2.0, -1000);
}


// ==================== ТЕСТЫ ДЛЯ pv ====================
TEST(PvTest, IntVector) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    testing::internal::CaptureStdout();
    my_lib::pv(vec);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 4 5 \n");
}

TEST(PvTest, EmptyVector) {
    std::vector<int> vec;
    testing::internal::CaptureStdout();
    my_lib::pv(vec);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n");
}

TEST(PvTest, StringVector) {
    std::vector<std::string> vec = {"hello", "world"};
    testing::internal::CaptureStdout();
    my_lib::pv(vec);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "hello world \n");
}

// 🔥 ПОПЫТКИ СЛОМАТЬ pv
TEST(PvTest, BREAK_VeryLargeVector) {
    // Огромный вектор
    std::vector<int> vec(1000000, 42);
    testing::internal::CaptureStdout();
    my_lib::pv(vec);
    std::string output = testing::internal::GetCapturedStdout();
    // Проверяем, что функция не упала
    EXPECT_FALSE(output.empty());
}

TEST(PvTest, BREAK_SpecialCharacters) {
    std::vector<std::string> vec = {"", "\n", "\t", " ", "\"quote\"", "\\slash\\"};
    testing::internal::CaptureStdout();
    my_lib::pv(vec);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}


// ==================== ТЕСТЫ ДЛЯ add ====================
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(my_lib::add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(my_lib::add(-2, -3), -5);
}

TEST(AddTest, MixedSigns) {
    EXPECT_EQ(my_lib::add(-5, 10), 5);
}

TEST(AddTest, WithZero) {
    EXPECT_EQ(my_lib::add(0, 0), 0);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ add
TEST(AddTest, BREAK_IntegerOverflow) {
    int max = std::numeric_limits<int>::max();
    // Переполнение - undefined behavior
    int result = my_lib::add(max, 1);
    // Результат непредсказуем
    (void)result;
}

TEST(AddTest, BREAK_MaxPlusMax) {
    int max = std::numeric_limits<int>::max();
    my_lib::add(max, max); // Гарантированное переполнение
}

TEST(AddTest, BREAK_MinPlusNegative) {
    int min = std::numeric_limits<int>::min();
    my_lib::add(min, -1); // Переполнение в отрицательную сторону
}


// ==================== ТЕСТЫ ДЛЯ sub ====================
TEST(SubTest, PositiveNumbers) {
    EXPECT_EQ(my_lib::sub(5, 2), 3);
}

TEST(SubTest, NegativeResult) {
    EXPECT_EQ(my_lib::sub(2, 5), -3);
}

TEST(SubTest, NegativeNumbers) {
    EXPECT_EQ(my_lib::sub(-5, -2), -3);
}

TEST(SubTest, WithZero) {
    EXPECT_EQ(my_lib::sub(0, 0), 0);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ sub
TEST(SubTest, BREAK_IntegerUnderflow) {
    int min = std::numeric_limits<int>::min();
    my_lib::sub(min, 1); // Переполнение
}

TEST(SubTest, BREAK_MinMinusMax) {
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();
    my_lib::sub(min, max); // Экстремальное переполнение
}

TEST(SubTest, BREAK_MaxMinusNegativeMax) {
    int max = std::numeric_limits<int>::max();
    my_lib::sub(max, -max); // Попытка получить > MAX
}


// ==================== ТЕСТЫ ДЛЯ mul ====================
TEST(MulTest, PositiveNumbers) {
    EXPECT_EQ(my_lib::mul(3, 4), 12);
}

TEST(MulTest, WithZero) {
    EXPECT_EQ(my_lib::mul(0, 5), 0);
}

TEST(MulTest, NegativeNumbers) {
    EXPECT_EQ(my_lib::mul(-3, 4), -12);
    EXPECT_EQ(my_lib::mul(-3, -4), 12);
}

TEST(MulTest, WithOne) {
    EXPECT_EQ(my_lib::mul(5, 1), 5);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ mul
TEST(MulTest, BREAK_HugeMultiplication) {
    int max = std::numeric_limits<int>::max();
    my_lib::mul(max, 2); // Переполнение
}

TEST(MulTest, BREAK_MaxTimesMax) {
    int max = std::numeric_limits<int>::max();
    my_lib::mul(max, max); // Огромное переполнение
}

TEST(MulTest, BREAK_MinTimesMinusOne) {
    int min = std::numeric_limits<int>::min();
    // INT_MIN * (-1) может не поместиться в int!
    my_lib::mul(min, -1);
}

TEST(MulTest, BREAK_LargeNegativeMultiplication) {
    int min = std::numeric_limits<int>::min();
    my_lib::mul(min, min); // Переполнение с отрицательными
}


// ==================== ТЕСТЫ ДЛЯ divide ====================
TEST(DivideTest, NormalDivision) {
    EXPECT_EQ(my_lib::divide(10, 2), 5);
}

TEST(DivideTest, DivideByZero) {
    EXPECT_THROW(my_lib::divide(10, 0), std::runtime_error);
    EXPECT_THROW(my_lib::divide(0, 0), std::runtime_error);
}

TEST(DivideTest, ZeroDividedByNumber) {
    EXPECT_EQ(my_lib::divide(0, 5), 0);
}

TEST(DivideTest, NegativeNumbers) {
    EXPECT_EQ(my_lib::divide(-10, 2), -5);
    EXPECT_EQ(my_lib::divide(-10, -2), 5);
}

TEST(DivideTest, WithRemainder) {
    EXPECT_EQ(my_lib::divide(10, 3), 3);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ divide
TEST(DivideTest, BREAK_MinDividedByMinusOne) {
    int min = std::numeric_limits<int>::min();
    // INT_MIN / (-1) вызывает переполнение! Результат > INT_MAX
    my_lib::divide(min, -1);
}

TEST(DivideTest, BREAK_MaxDividedByMinusOne) {
    int max = std::numeric_limits<int>::max();
    EXPECT_EQ(my_lib::divide(max, -1), -max);
}

TEST(DivideTest, BREAK_DivideByVerySmallNumber) {
    int max = std::numeric_limits<int>::max();
    // Деление на 1 или -1
    my_lib::divide(max, 1);
    my_lib::divide(max, -1);
}

TEST(DivideTest, BREAK_NegativeZero) {
    // В некоторых системах -0 может существовать
    EXPECT_THROW(my_lib::divide(10, 0), std::runtime_error);
    EXPECT_THROW(my_lib::divide(-10, 0), std::runtime_error);
}


// ==================== ТЕСТЫ ДЛЯ operat ====================
TEST(OperatTest, Addition) {
    EXPECT_EQ(my_lib::operat(2, 3, '+'), 5);
    EXPECT_EQ(my_lib::operat(-2, -3, '+'), -5);
}

TEST(OperatTest, Subtraction) {
    EXPECT_EQ(my_lib::operat(5, 3, '-'), 2);
    EXPECT_EQ(my_lib::operat(-5, -3, '-'), -2);
}

TEST(OperatTest, Multiplication) {
    EXPECT_EQ(my_lib::operat(3, 4, '*'), 12);
    EXPECT_EQ(my_lib::operat(-3, -4, '*'), 12);
}

TEST(OperatTest, Division) {
    EXPECT_EQ(my_lib::operat(6, 2, '/'), 3);
}

TEST(OperatTest, DivisionByZero) {
    EXPECT_THROW(my_lib::operat(10, 0, '/'), std::runtime_error);
}

TEST(OperatTest, InvalidOperator) {
    EXPECT_THROW(my_lib::operat(1, 2, '%'), std::invalid_argument);
    EXPECT_THROW(my_lib::operat(1, 2, '&'), std::invalid_argument);
}

// 🔥 ПОПЫТКИ СЛОМАТЬ operat
TEST(OperatTest, BREAK_NullCharOperator) {
    EXPECT_THROW(my_lib::operat(1, 2, '\0'), std::invalid_argument);
}

TEST(OperatTest, BREAK_NumericCharOperator) {
    EXPECT_THROW(my_lib::operat(1, 2, '0'), std::invalid_argument);
    EXPECT_THROW(my_lib::operat(1, 2, '1'), std::invalid_argument);
}

TEST(OperatTest, BREAK_SpecialCharOperators) {
    EXPECT_THROW(my_lib::operat(1, 2, '\n'), std::invalid_argument);
    EXPECT_THROW(my_lib::operat(1, 2, '\t'), std::invalid_argument);
    EXPECT_THROW(my_lib::operat(1, 2, ' '), std::invalid_argument);
}

TEST(OperatTest, BREAK_AllOperationsWithExtremes) {
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    
    // Попытки переполнения через operat
    my_lib::operat(max, 1, '+');
    my_lib::operat(min, -1, '+');
    my_lib::operat(min, 1, '-');
    my_lib::operat(max, max, '*');
    my_lib::operat(min, -1, '/');
}

TEST(OperatTest, BREAK_CaseSensitiveOperators) {
    // Проверяем, что заглавные буквы не работают
    EXPECT_THROW(my_lib::operat(1, 2, 'A'), std::invalid_argument);
    EXPECT_THROW(my_lib::operat(1, 2, 'X'), std::invalid_argument);
}


// ==================== ТЕСТЫ ДЛЯ shuffle ====================
TEST(ShuffleTest, NormalShuffle) {
    char s[] = "abc";
    int p[] = {2, 0, 1};
    my_lib::shuffle(3, s, p);
    EXPECT_STREQ(s, "bca");
}

TEST(ShuffleTest, ReverseOrder) {
    char s[] = "hello";
    int p[] = {4, 3, 2, 1, 0};
    my_lib::shuffle(5, s, p);
    EXPECT_STREQ(s, "olleh");
}

TEST(ShuffleTest, SameOrder) {
    char s[] = "test";
    int p[] = {0, 1, 2, 3};
    my_lib::shuffle(4, s, p);
    EXPECT_STREQ(s, "test");
}

TEST(ShuffleTest, SingleCharacter) {
    char s[] = "a";
    int p[] = {0};
    my_lib::shuffle(1, s, p);
    EXPECT_STREQ(s, "a");
}

// 🔥 ПОПЫТКИ СЛОМАТЬ shuffle
TEST(ShuffleTest, BREAK_OutOfBoundsIndices) {
    char s[] = "abc";
    int p[] = {5, 10, 99}; // Индексы за границами!
    // Это вызовет undefined behavior
    my_lib::shuffle(3, s, p);
}

TEST(ShuffleTest, BREAK_NegativeIndices) {
    char s[] = "abc";
    int p[] = {-1, 0, 1}; // Отрицательный индекс!
    my_lib::shuffle(3, s, p);
}

TEST(ShuffleTest, BREAK_DuplicateIndices) {
    char s[] = "abc";
    int p[] = {0, 0, 0}; // Все на одну позицию!
    my_lib::shuffle(3, s, p);
    // Результат: "aaa" - потеря данных
}

TEST(ShuffleTest, BREAK_ZeroLength) {
    char s[] = "";
    int p[] = {};
    my_lib::shuffle(0, s, p); // Пустой массив
}

TEST(ShuffleTest, BREAK_VeryLongString) {
    char s[1001];
    int p[1000];
    for (int i = 0; i < 1000; i++) {
        s[i] = 'a';
        p[i] = i;
    }
    s[1000] = '\0';
    my_lib::shuffle(1000, s, p);
}

TEST(ShuffleTest, BREAK_NullTerminatorInMiddle) {
    char s[] = "ab\0cd";
    int p[] = {4, 3, 2, 1, 0};
    my_lib::shuffle(5, s, p); // Нулевой символ в середине
}

TEST(ShuffleTest, BREAK_SpecialCharacters) {
    char s[] = "\n\t\r\0 ";
    int p[] = {4, 3, 2, 1, 0};
    my_lib::shuffle(5, s, p);
}
