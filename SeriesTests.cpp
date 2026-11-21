// Добавить в отдельный Google Test проект Visual Studio.
#include "SeriesTasks.h"
#include <gtest/gtest.h>

#include <vector>

// Series2: произведение десяти вещественных чисел.
TEST(Series2, TenTwos) {
    // Arrange
    const std::vector<double> numbers(10, 2.0);
    // Act
    const double result = lab5::series2(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 1024.0);
}

TEST(Series2, ContainsZero) {
    // Arrange
    const std::vector<double> numbers{1, 2, 3, 4, 5, 0, 7, 8, 9, 10};
    // Act
    const double result = lab5::series2(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(Series2, FractionalValues) {
    // Arrange
    const std::vector<double> numbers{0.5, 2, 1, 1, 1, 1, 1, 1, 1, 1};
    // Act
    const double result = lab5::series2(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 1.0);
}

// Series3: среднее арифметическое десяти вещественных чисел.
TEST(Series3, OneToTen) {
    // Arrange
    const std::vector<double> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Act
    const double result = lab5::series3(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 5.5);
}

TEST(Series3, SameValues) {
    // Arrange
    const std::vector<double> numbers(10, 4.5);
    // Act
    const double result = lab5::series3(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 4.5);
}

TEST(Series3, PositiveAndNegative) {
    // Arrange
    const std::vector<double> numbers{-5, -4, -3, -2, -1, 1, 2, 3, 4, 5};
    // Act
    const double result = lab5::series3(numbers);
    // Assert
    EXPECT_DOUBLE_EQ(result, 0.0);
}

// Series6: дробные части и их произведение.
TEST(Series6, BasicFractions) {
    // Arrange
    const std::vector<double> numbers{1.25, 2.5, 3.75};
    // Act
    const auto result = lab5::series6(numbers);
    // Assert
    ASSERT_EQ(result.first.size(), 3u);
    EXPECT_NEAR(result.first[0], 0.25, 1e-9);
    EXPECT_NEAR(result.first[1], 0.5, 1e-9);
    EXPECT_NEAR(result.first[2], 0.75, 1e-9);
    EXPECT_NEAR(result.second, 0.09375, 1e-9);
}

TEST(Series6, IntegerPartProducesZero) {
    // Arrange
    const std::vector<double> numbers{2.0, 1.4};
    // Act
    const auto result = lab5::series6(numbers);
    // Assert
    ASSERT_EQ(result.first.size(), 2u);
    EXPECT_DOUBLE_EQ(result.first[0], 0.0);
    EXPECT_NEAR(result.first[1], 0.4, 1e-9);
    EXPECT_DOUBLE_EQ(result.second, 0.0);
}

TEST(Series6, PreservesOrder) {
    // Arrange
    const std::vector<double> numbers{4.75, 1.25};
    // Act
    const auto result = lab5::series6(numbers);
    // Assert
    ASSERT_EQ(result.first.size(), 2u);
    EXPECT_NEAR(result.first[0], 0.75, 1e-9);
    EXPECT_NEAR(result.first[1], 0.25, 1e-9);
    EXPECT_NEAR(result.second, 0.1875, 1e-9);
}

// Series34: сумма при наличии двойки, иначе ноль.
TEST(Series34, SomeGroupsHaveTwo) {
    // Arrange
    const std::vector<std::vector<int>> groups{{1, 2, 3}, {2, 2, 2}, {1, 3, 4}};
    // Act
    const auto result = lab5::series34(groups);
    // Assert
    ASSERT_EQ(result.size(), 3u);
    EXPECT_EQ(result[0], 6);
    EXPECT_EQ(result[1], 6);
    EXPECT_EQ(result[2], 0);
}

TEST(Series34, NegativeNumbers) {
    // Arrange
    const std::vector<std::vector<int>> groups{{-5, 2, 1}, {-1, -2, -3}};
    // Act
    const auto result = lab5::series34(groups);
    // Assert
    ASSERT_EQ(result.size(), 2u);
    EXPECT_EQ(result[0], -2);
    EXPECT_EQ(result[1], 0);
}

TEST(Series34, ZerosAndTwo) {
    // Arrange
    const std::vector<std::vector<int>> groups{{0, 0, 2}, {0, 0, 0}};
    // Act
    const auto result = lab5::series34(groups);
    // Assert
    ASSERT_EQ(result.size(), 2u);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 0);
}
