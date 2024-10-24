#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** p, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** p, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** p, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** p, const int col1, const int col2, const int rowCount, int i = 0);
void Calc(int** p, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main() {
    srand((unsigned)time(NULL)); 

    int Low = -21;
    int High = 24;

    int rowCount = 9;
    int colCount = 6;

    int** p = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        p[i] = new int[colCount];
    }

    Create(p, rowCount, colCount, Low, High);
    Print(p, rowCount, colCount);

    Sort(p, rowCount, colCount);
    Print(p, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(p, rowCount, colCount, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    
    Print(p, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;

    return 0;
}


void Create(int** p, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i >= rowCount) return; 
    if (j >= colCount) {
        Create(p, rowCount, colCount, Low, High, i + 1, 0); 
        return;
    }
    p[i][j] = Low + rand() % (High - Low + 1);
    Create(p, rowCount, colCount, Low, High, i, j + 1); 
}

void Print(int** p, const int rowCount, const int colCount, int i, int j) {
    if (i >= rowCount) return; 
    if (j >= colCount) {
        cout << endl;
        Print(p, rowCount, colCount, i + 1, 0); 
        return;
    }
    cout << setw(4) << p[i][j];
    Print(p, rowCount, colCount, i, j + 1); 
}


void Sort(int** p, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 >= colCount - 1) return; 
    if (i1 >= colCount - i0 - 1) {
        Sort(p, rowCount, colCount, i0 + 1, 0); 
        return;
    }
    if ((p[0][i1] < p[0][i1 + 1]) // Сортуємо за спаданням першого рядка
        || (p[0][i1] == p[0][i1 + 1] && p[1][i1] < p[1][i1 + 1]) // Сортуємо за спаданням другого рядка
        || (p[0][i1] == p[0][i1 + 1] && p[1][i1] == p[1][i1 + 1] && p[2][i1] > p[2][i1 + 1])) // Сортуємо за зростанням третього рядка
    {
        Change(p, i1, i1 + 1, rowCount); 
    }
    Sort(p, rowCount, colCount, i0, i1 + 1); 
}



void Change(int** p, const int col1, const int col2, const int rowCount, int i) {
    if (i >= rowCount) return; 
    int tmp = p[i][col1];
    p[i][col1] = p[i][col2];
    p[i][col2] = tmp;
    Change(p, col1, col2, rowCount, i + 1); 
}

void Calc(int** p, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i >= rowCount) return; 
    if (j >= colCount) {
        Calc(p, rowCount, colCount, S, k, i + 1, 0); 
        return;
    }
    if (p[i][j] % 3 == 0 && p[i][j] >= 0) { 
        S += p[i][j];
        k++;
        p[i][j] = 0;
    }
    Calc(p, rowCount, colCount, S, k, i, j + 1); 
}