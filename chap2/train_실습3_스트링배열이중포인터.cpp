#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
* 2�� ���� ���� 24.3.15��
* ��Ʈ�� �迭�� �Լ��� ������ �� ���������͸� ����ϴ� ���
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
        //arr[]�� p�� ����
        p[i] = (char*)malloc(10 * sizeof(char));
        strcpy(p[i], arr[i]);
    }

    for (i = 0; i < n; i++) {
        //�����Ѵ�
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
    char* strings[5] = { "������", "����", "��", "�����", "����" };

    int n = sizeof(strings) / sizeof(strings[0]);

    showData("������", strings, n);

    char** result = bubbleSort(strings, n);
    showData("������", result, n);
    freeMemory(result, n);
    system("pause");
    return 0;
}