#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(char* arr[10], int n) { //char **arr와 같다. 
//void bubbleSort(char **arr[10], int n) { //char arr[][10]와 같다. 
//void bubbleSort(char (*arr)[10], int n) { //char arr[][10]와 같다.
}
/*
char  *strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };
strcpy(strings[0],strings[1]); 오류가 나나? 이유는? 오류다 > 스트링 리터럴을 포인터가 가리킨다
char  (*strings)[10] = { "apple", "banana", "orange", "grape", "kiwi" };>> 포인터가 배열을 가리킨다
*/
void showData(char* message, char(*data)[10], int n) {

}
int main() {
    //스트링 배열 초기화 방법 2가지 구분
    //char strings[5][10] = { "apple", "banana", "orange", "grape", "kiwi" };//초기화 방법1
    char* strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };//초기화 방법2
    int i;
    int n = sizeof(strings) / sizeof(strings[0]);

    showData("정렬전", strings, 5);

    bubbleSort(strings, 5);
    showData("정렬gn", strings, 5);

    system("pause");
    return 0;
}