#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(char* arr[10], int n) { //char **arr�� ����. 
//void bubbleSort(char **arr[10], int n) { //char arr[][10]�� ����. 
//void bubbleSort(char (*arr)[10], int n) { //char arr[][10]�� ����.
}
/*
char  *strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };
strcpy(strings[0],strings[1]); ������ ����? ������? ������ > ��Ʈ�� ���ͷ��� �����Ͱ� ����Ų��
char  (*strings)[10] = { "apple", "banana", "orange", "grape", "kiwi" };>> �����Ͱ� �迭�� ����Ų��
*/
void showData(char* message, char(*data)[10], int n) {

}
int main() {
    //��Ʈ�� �迭 �ʱ�ȭ ��� 2���� ����
    //char strings[5][10] = { "apple", "banana", "orange", "grape", "kiwi" };//�ʱ�ȭ ���1
    char* strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };//�ʱ�ȭ ���2
    int i;
    int n = sizeof(strings) / sizeof(strings[0]);

    showData("������", strings, 5);

    bubbleSort(strings, 5);
    showData("����gn", strings, 5);

    system("pause");
    return 0;
}