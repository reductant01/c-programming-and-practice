// 10-3.STA1-USE.CPP   10.2 macro로 genericity를 표현
#include <iostream>
#include "10-1.STACK1.h" //macro 사용
using namespace std;
// class Stack의 instance 예제
void main (){
    Stack intStack;
    //Stack floatStack; //#define Type float 사용시 오류 확인
// main()에서 두 개의 stack을 동시에 만들고자 하는 실습
    intStack.Push (50.0);
    intStack.Push (19.92);
    intStack.Push (3.3);
    intStack.Push (10.24);
    intStack.Push(1024);   //입력 가능?  이유 확인 필요
	cout<<"Number of stack = "<<intStack.Number()<<endl;
    // stack을 비우면서 요소를 출력
    while (! intStack.Empty ())
        cout << intStack.Pop () << endl;
	if (intStack.Empty()) cout<<"Stack is Empty"<<endl;
	system("pause");
} 