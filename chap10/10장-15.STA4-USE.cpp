// 10��-15.STA4-USE.CPP  10.4.2 template argument
#include "10��-14.STACK4.cpp"
#include <iostream>
// default ũ�⸦ ���� template class Stack��  instance ��
using namespace std;
void main (){
	// ���� stack�� ����(default�� ũ�⸦ ����)
    Stack <int> intStack;
	// double �������� ���� stack�� ����
    Stack <double, 4> miniStack;
	intStack.Push(10);
	miniStack.Push(1.234);
	intStack.Pop();
	miniStack.Pop();
	system("pause");
}