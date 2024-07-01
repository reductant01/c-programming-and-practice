#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 5
#define DCOLS 4

void showMatrix(int[], int, int);
int* createArray(int rows);
int * multiplyMatrix(int a[], int, int, int b[], int, int, int c[], int, int);//c = a * b를 계산하고 c를 return
bool freeMatrix(int[], int);
int main()
{
    srand(time(NULL));
    int* a = createArray(AROWS * ACOLS);
    int* b = createArray(BROWS * BCOLS);
    int* c = createArray(CROWS * CCOLS);
    int* d = createArray(DROWS * DCOLS);
    showMatrix(a, AROWS, ACOLS); showMatrix(b, BROWS, BCOLS);
    bool result;
    result = multiplyMatrix(multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS), CROWS, CCOLS, d, DROWS, DCOLS, a, AROWS, ACOLS);
    if (!result)
        printf(" a의 열과 b의 행의 숫자가 달라서 곱셈 계산 안된다");
    showMatrix(c, CROWS, CCOLS);

    freeMatrix(a, AROWS * ACOLS);
    freeMatrix(b, AROWS * ACOLS);
    freeMatrix(c, AROWS * ACOLS);
    system("pause");
    return 1;
}

void showMatrix(int* a, int r, int c) {
    printf(" matrix row = %d, col = %d\n", r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf(" %d", *a++);
        printf("\n");
    }
}
int * multiplyMatrix(int a[], int ar, int ac, int b[], int br, int bc, int c[], int cr, int cc) {
    if (ac != br)return 0;
    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < bc; j++) {
            int result = 0;
            for (int k = 0; k < ac; k++)
            {
                result += (*(a + i * ac + k)) * (*(b + j + bc * k));
            }
            *c++ = result;
        }
    }
    return c;

}
int* createArray(int count) {
    int* arr = (int *) calloc(count, sizeof(int)); // 2차원 배열의 row를 동적으로 할당

    for (int i = 0; i < count; ++i) {
        arr[i] = rand() % 100; // 2차원 배열의 column을 동적으로 할당
    }

    return arr;
}