#include "C:\OOP\clw\clw3\my_lib.h"
#include <gtest/gtest.h>

TEST(MyLibTest, Pow) {
    EXPECT_EQ(my_lib::pow<int>(3), 9);
    EXPECT_DOUBLE_EQ(my_lib::pow<double>(2.5), 6.25);
}

TEST(MyLibTest, Add) {
    EXPECT_EQ(my_lib::add(2, 3), 5);
}

TEST(MyLibTest, Sub) {
    EXPECT_EQ(my_lib::sub(5, 2), 3);
}

TEST(MyLibTest, Mul) {
    EXPECT_EQ(my_lib::mul(3, 4), 12);
}

TEST(MyLibTest, DivideNormal) {
    EXPECT_EQ(my_lib::divide(10, 2), 5);
}

TEST(MyLibTest, DivideByZero) {
    EXPECT_THROW(my_lib::divide(10, 0), std::runtime_error);
}

TEST(MyLibTest, Operat) {
    EXPECT_EQ(my_lib::operat(2, 3, '+'), 5);
    EXPECT_EQ(my_lib::operat(6, 2, '/'), 3);
    EXPECT_THROW(my_lib::operat(1, 2, '%'), std::invalid_argument);
}
