#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
char  *strings[10] = { "apple", "banana", "orange", "grape", "kiwi" };
strcpy(strings[0],strings[1]); 오류가 나나? 이유는? 오류다 > 스트링 리터럴을 포인터가 가리킨다
char  (*strings)[10] = { "apple", "banana", "orange", "grape", "kiwi" };>> 포인터가 배열을 가리킨다
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
    // stPointer를 동적으로 할당한 후에 문자열 복사
    stPointer = (char*)malloc(strlen("bad") + 1);
    strcpy(stPointer, "bad");

    printf("stArray: %s\n", stArray);
    printf("stPointer: %s\n", stPointer);

    updateString(stArray, "안녕");
    //updateString(stPointer, "nice");//오류 발생 

    system("pause");
    return 0;
}