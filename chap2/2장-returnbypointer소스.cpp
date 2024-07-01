#include <iostream>
//23.3.10 추가한 소스 코드
using namespace std;

// 2차원 배열을 return하는 함수
int** createArray(int rows, int cols) {
    int** arr = new int* [rows]; // 2차원 배열의 row를 동적으로 할당

    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols]; // 2차원 배열의 column을 동적으로 할당
    }

    return arr;
}
int ** add(int(*p)[4], int n, int(*q)[4], int m, int **arr);
/*
int  (*p)[3] addData(int(*a)[3], int n, int(*b)[3]);//함수 return 값으로 int[][] 사용 안됨
*/
int main() {
    int rows = 3, cols = 4;
    int** arr = createArray(rows, cols);
    int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    int b[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    int** c;
    c = (int**)a;
    arr = add(a, 3, b, 3, arr);
    // 2차원 배열의 값 초기화
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
           // arr[i][j] = i * j;
            printf("c[][] =  %d", c[i][j]);
        }
        printf("\n");
    }

    // 동적 할당한 메모리 해제
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    system("pause");
    return 0;
}
int** add(int(*p)[4], int rows, int(*q)[4], int rows2, int **arr) {
    //static int arr[3][4] = { 0 };
    //int **dp;
    //int *t = *arr;
    //dp = &t;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = p[i][j] + q[i][j];
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    return arr;
}
/*
int (*p)[] addData(int(*a)[3], int n, int(*b)[3]) {

}

*/