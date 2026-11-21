#include "pch.h"
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <deque>

// Объявления функций из STLTasks.cpp. Отдельный .h не нужен.
int STL1Iter2(std::istream& input);
int STL1Iter3(std::istream& input);
void STL1Iter6(const std::vector<char>& symbols, std::ostream& output);
void STL2Seq34(std::list<int>& L1, std::list<int>& L2);
void STL3Alg34(std::deque<int>& D);


TEST(STL1Iter2Tests, MixedNumbers)
{
    // Arrange — std::istringstream: чтение из строки.
    std::istringstream input("1.5 -2 0 3.7 -4 8");
    // Act
    int result = STL1Iter2(input);
    // Assert
    EXPECT_EQ(result, 3);
}

TEST(STL1Iter2Tests, NoPositiveNumbers)
{
    // Arrange
    std::istringstream input("-1 -2.5 0");
    // Act
    int result = STL1Iter2(input);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(STL1Iter2Tests, RealFile)
{
    // Arrange — std::ofstream: запись в файл.
    const char* name = "lab5_test_iter2.txt";
    std::ofstream file(name);
    ASSERT_TRUE(file.is_open());
    file << "-2 1.5 5 0";
    file.close();
    std::ifstream input(name); // Чтение из файла.
    ASSERT_TRUE(input.is_open());
    // Act
    int result = STL1Iter2(input);
    input.close();
    std::remove(name);
    // Assert
    EXPECT_EQ(result, 2);
}

TEST(STL1Iter3Tests, MixedWords)
{
    // Arrange
    std::istringstream input("apple banana orange cat school");
    // Act
    int result = STL1Iter3(input);
    // Assert
    EXPECT_EQ(result, 3);
}

TEST(STL1Iter3Tests, NoMatchingWords)
{
    // Arrange
    std::istringstream input("cat dog apple computer");
    // Act
    int result = STL1Iter3(input);
    // Assert
    EXPECT_EQ(result, 0);
}

TEST(STL1Iter3Tests, RealFile)
{
    // Arrange
    const char* name = "lab5_test_iter3.txt";
    std::ofstream file(name);
    ASSERT_TRUE(file.is_open());
    file << "banana\ncat\nplanet";
    file.close();
    std::ifstream input(name);
    ASSERT_TRUE(input.is_open());
    // Act
    int result = STL1Iter3(input);
    input.close();
    std::remove(name);
    // Assert
    EXPECT_EQ(result, 2);
}

TEST(STL1Iter6Tests, Characters)
{
    // Arrange — std::vector: динамический массив.
    std::vector<char> symbols = {'A', 'b', '3'};
    std::ostringstream output; // Запись в строку.
    // Act
    STL1Iter6(symbols, output);
    // Assert
    EXPECT_EQ(output.str(), "A b 3 ");
}

TEST(STL1Iter6Tests, OneCharacter)
{
    // Arrange
    std::vector<char> symbols = {'X'};
    std::ostringstream output;
    // Act
    STL1Iter6(symbols, output);
    // Assert
    EXPECT_EQ(output.str(), "X ");
}

TEST(STL1Iter6Tests, RealFile)
{
    // Arrange
    std::vector<char> symbols = {'a', 'b', 'c'};
    const char* name = "lab5_test_iter6.txt";
    std::ofstream output(name); // Запись в файл.
    ASSERT_TRUE(output.is_open());
    // Act
    STL1Iter6(symbols, output);
    output.close();
    std::ifstream input(name);
    ASSERT_TRUE(input.is_open());
    std::string result;
    std::getline(input, result); // Чтение строки с пробелами.
    input.close();
    std::remove(name);
    // Assert — проверяем содержимое файла.
    EXPECT_EQ(result, "a b c ");
}

// ===== Дополнительные тесты STL2Seq34 =====
TEST(STL2Seq34Tests, ThreeElements)
{
    // Arrange — std::list: двусвязный список.
    std::list<int> L1 = {1, 2, 3};
    std::list<int> L2 = {10, 20, 30};
    std::list<int> expected = {1, 10, 2, 20, 3, 30};
    // Act
    STL2Seq34(L1, L2);
    // Assert
    EXPECT_EQ(L2, expected);
    EXPECT_TRUE(L1.empty());
}

TEST(STL2Seq34Tests, OneElement)
{
    // Arrange
    std::list<int> L1 = {-5};
    std::list<int> L2 = {0};
    std::list<int> expected = {-5, 0};
    // Act
    STL2Seq34(L1, L2);
    // Assert
    EXPECT_EQ(L2, expected);
    EXPECT_TRUE(L1.empty());
}

// ===== Дополнительные тесты STL3Alg34 =====
TEST(STL3Alg34Tests, FourElements)
{
    // Arrange — std::deque: двусторонняя очередь.
    std::deque<int> D = {1, 3, 7, 9};
    std::deque<int> expected = {1, 3, 6, 2};
    // Act
    STL3Alg34(D);
    // Assert
    EXPECT_EQ(D, expected);
}

TEST(STL3Alg34Tests, NegativeAndZero)
{
    // Arrange
    std::deque<int> D = {-2, 0, 4, 9, 9, 9};
    std::deque<int> expected = {-2, 0, 4, 8, 0, -4};
    // Act
    STL3Alg34(D);
    // Assert
    EXPECT_EQ(D, expected);
}
