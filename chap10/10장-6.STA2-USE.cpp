// 10장-6.STA2-USE.CPP 10.3 상속과 polymorphism을 사용하여 genericity 표현
#include <iostream>
#include "10장-4.STACK2.h"
using namespace std;
// generic인 것으로부터 유도된 정수 class를 정의
class IntObject : public GenericObject{
public:
    int data;
    IntObject (int num) :
    data (num)
    { }
};

void main (){
    Stack genericStack;
    genericStack.Push (new IntObject (500));
    genericStack.Push (new IntObject (1992));
    genericStack.Push (new IntObject (33));
    genericStack.Push (new IntObject (1024));
	cout<<"Number of stack = "<<genericStack.Number()<<endl;
    // stack에서 하나씩 꺼내면서 출력한다.
    // Pop 함수가 GenericObject에 대한 pointer를 return하기 때문에 그 객체를 접근하기 위해서 타입 변환이 필요하다.
    while (! genericStack.Empty ())
        cout << ((IntObject *) genericStack.Pop()) -> data << endl;//subclass로 type casting한다 
    // stack을 비우면서 요소를 출력
	if (genericStack.Empty()) cout<<"Stack is Empty"<<endl;
	system("pause");
}