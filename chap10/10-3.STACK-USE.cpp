// 10-3.STA1-USE.CPP   10.2 macro�� genericity�� ǥ��
#include <iostream>
#include "10-1.STACK1.h" //macro ���
using namespace std;
// class Stack�� instance ����
void main (){
    Stack intStack;
    //Stack floatStack; //#define Type float ���� ���� Ȯ��
// main()���� �� ���� stack�� ���ÿ� ������� �ϴ� �ǽ�
    intStack.Push (50.0);
    intStack.Push (19.92);
    intStack.Push (3.3);
    intStack.Push (10.24);
    intStack.Push(1024);   //�Է� ����?  ���� Ȯ�� �ʿ�
	cout<<"Number of stack = "<<intStack.Number()<<endl;
    // stack�� ���鼭 ��Ҹ� ���
    while (! intStack.Empty ())
        cout << intStack.Pop () << endl;
	if (intStack.Empty()) cout<<"Stack is Empty"<<endl;
	system("pause");
} 