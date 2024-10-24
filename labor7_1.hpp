#ifndef labor7_1_HPP
#define labor7_1_HPP
void Create(int** p, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** p, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** p, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** p, const int col1, const int col2, const int rowCount, int i = 0);
void Calc(int** p, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);
#endif /*LABOR71_HPP */