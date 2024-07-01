#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* 2장 수업 과제 24.3.15일
* 스트링 배열을 함수로 전달할 때 이중포인터를 사용하는 방법
*/
void showData(char* message, char* data[5], int n) {
    printf("%s = ", message);
    for (int i = 0; i < n; i++)
        printf("%s, ", data[i]);
    printf("\n");
}
void swap(char* p[5], int i, int j) {
    char temp[10];
    strcpy(temp,p[i]);
    strcpy(p[i],p[j]);
    strcpy(p[j],temp);
}
char** bubbleSort(char* arr[5], int n) {

    int i, j;

    char** p = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        //arr[]을 p로 복사
        p[i] = (char*)malloc(10 * sizeof(char));
        strcpy(p[i], arr[i]);
    }

    for (i = 0; i < n; i++) {
        //정렬한다
        for (j = i+1; j < n; j++) {
            if (strcmp(p[i], p[j]) > 0)
                swap(p, i, j);
        }
    }
    return p;
}
void freeMemory(char** p, int n) {
    for (int i = 0; i < n; i++) {
        free(p[i]);  
    }
    free(p);  
}

int main() {
    char* strings[5] = { "복숭아", "포도", "감", "산딸기", "대추" };

    int n = sizeof(strings) / sizeof(strings[0]);

    showData("정렬전", strings, n);

    char** result = bubbleSort(strings, n);
    showData("정렬후", result, n);
    freeMemory(result, n);
    system("pause");
    return 0;
}