// 10장-15.STA4-USE.CPP  10.4.2 template argument
#include "10장-14.STACK4.cpp"
#include <iostream>
// default 크기를 갖는 template class Stack의  instance 예
using namespace std;
void main (){
	// 정수 stack의 정의(default된 크기를 가짐)
    Stack <int> intStack;
	// double 정수들의 작은 stack을 정의
    Stack <double, 4> miniStack;
	intStack.Push(10);
	miniStack.Push(1.234);
	intStack.Pop();
	miniStack.Pop();
	system("pause");
}