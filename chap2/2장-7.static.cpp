// 2장-7 static.cpp
#include <stdio.h>
#include <stdlib.h>
static int total = 0;   // static definition, internal linkage, static storage duration
void fcn(void);

void main() {
    fcn();
	fcn();
	fcn();
	printf("main():: total = %d\n", total);
	system("pause");
}

void fcn() {
    static int counter = 0;//static 변수로 데이터 영역에 저장된다 
    counter++;
	printf("fcn::counter = %d\n\n", counter);
	total += counter;
}