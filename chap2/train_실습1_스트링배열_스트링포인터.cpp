#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
char  *strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };
strcpy(strings[0],strings[1]); ������ ����? ������? ������ > ��Ʈ�� ���ͷ��� �����Ͱ� ����Ų��
char  (*strings)[10] = { "apple", "banana", "orange", "grape", "kiwi" };>> �����Ͱ� �迭�� ����Ų��
*/
void updateString(char* stArray, char *str) {
    strcpy(stArray, str);
}
int main() {
    
    char stArray[10] = "hello";
    char* stPointer = "good";

    strcpy(stArray, "morning");
    //
    strcpy(stPointer, "bad morning");
    // stPointer�� �������� �Ҵ��� �Ŀ� ���ڿ� ����
    stPointer = (char*)malloc(strlen("bad") + 1);
    strcpy(stPointer, "bad");

    printf("stArray: %s\n", stArray);
    printf("stPointer: %s\n", stPointer);

    updateString(stArray, "�ȳ�");
    //updateString(stPointer, "nice");//���� �߻� 

    system("pause");
    return 0;
}