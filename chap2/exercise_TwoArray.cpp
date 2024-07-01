//1차원 list에 대한 행렬 덧셈, 곱셈
//2차원 행렬을 1차원 배열로 처리하면 getData()를 하나의 함수로 구현 가능
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 4
#define CCOLS 5
int getData(int[], int, int);//난수 생성하여 처리
bool showMatrix(int[], int, int);
bool addMatrix(int[], int, int[][COLS], int, int[][COLS], int);
bool getMatrix(int(*arr)[COLS], int rows);
bool multiplyMatrix(int[][COLS], int, int[][BCOLS], int, int[][CCOLS], int);
int main()
{
    srand(time(NULL));
    int a[ROWS][COLS]; int a1[ROWS][COLS]; int a2[ROWS][COLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];

    getMatrix(a, ROWS);
    showMatrix(a, ROWS);
    getMatrix(a1, ROWS);
    showMatrix(a1, ROWS);

    addMatrix(a, ROWS, a1, ROWS, a2, ROWS);
    showMatrix(a2, CROWS);
    getMatrix(b, BROWS);
    showMatrix(b, BROWS);
    multiplyMatrix(a, ROWS, b, BROWS, c, CROWS);
    showMatrix(c, CROWS);
    system("pause");
    return 1;
}
//int getMatrix(int(*arr)[], int rows, int cols)
bool getMatrix(int(*arr)[COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(arr + i) + j) = rand() % 10;
        }
    }
    return true;
}