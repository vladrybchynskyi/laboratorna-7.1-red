#include <gtest/gtest.h>
#include "../labor7_1.hpp"



// Тестова функція Create
TEST(MatrixTest, CreateFunction) {
    const int rowCount = 3;
    const int colCount = 3;
    const int Low = -5;
    const int High = 5;

    int** p = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        p[i] = new int[colCount];
    }

    Create(p, rowCount, colCount, Low, High);
    
    // Перевірка, чи всі значення знаходяться в заданому діапазоні
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            EXPECT_GE(p[i][j], Low);
            EXPECT_LE(p[i][j], High);
        }
    }

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;
}

// Тестова функція Sort
TEST(MatrixTest, SortFunction) {
    const int rowCount = 3;
    const int colCount = 3;

    int** p = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        p[i] = new int[colCount];
    }

    // Встановимо значення для тестування
    p[0][0] = 1; p[0][1] = 3; p[0][2] = 2;
    p[1][0] = 4; p[1][1] = 5; p[1][2] = 6;
    p[2][0] = 7; p[2][1] = 8; p[2][2] = 9;

    Sort(p, rowCount, colCount);

    // Перевірка, чи масив відсортовано правильно
    EXPECT_GE(p[0][0], p[0][1]);
    EXPECT_GE(p[0][1], p[0][2]);
    EXPECT_GE(p[1][0], p[1][1]);
    EXPECT_GE(p[1][1], p[1][2]);
    EXPECT_GE(p[2][0], p[2][1]);
    EXPECT_GE(p[2][1], p[2][2]);

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;
}

// Тестова функція Calc
TEST(MatrixTest, CalcFunction) {
    const int rowCount = 3;
    const int colCount = 3;

    int** p = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        p[i] = new int[colCount];
    }

    // Встановимо значення для тестування
    p[0][0] = 0; p[0][1] = 3; p[0][2] = 2; // 0 і 3 кратні 3
    p[1][0] = 5; p[1][1] = 6; p[1][2] = -3; // 6 і -3 кратні 3
    p[2][0] = 4; p[2][1] = 9; p[2][2] = 12; // 9 і 12 кратні 3

    int S = 0, k = 0;
    Calc(p, rowCount, colCount, S, k);

    // Перевірка правильності підрахунків
    EXPECT_EQ(S, 0 + 3 + 6 + 0 + 9 + 12); // Сума
    EXPECT_EQ(k, 5); // Кількість

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;
}


