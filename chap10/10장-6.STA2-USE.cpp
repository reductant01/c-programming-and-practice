// 10��-6.STA2-USE.CPP 10.3 ��Ӱ� polymorphism�� ����Ͽ� genericity ǥ��
#include <iostream>
#include "10��-4.STACK2.h"
using namespace std;
// generic�� �����κ��� ������ ���� class�� ����
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
    // stack���� �ϳ��� �����鼭 ����Ѵ�.
    // Pop �Լ��� GenericObject�� ���� pointer�� return�ϱ� ������ �� ��ü�� �����ϱ� ���ؼ� Ÿ�� ��ȯ�� �ʿ��ϴ�.
    while (! genericStack.Empty ())
        cout << ((IntObject *) genericStack.Pop()) -> data << endl;//subclass�� type casting�Ѵ� 
    // stack�� ���鼭 ��Ҹ� ���
	if (genericStack.Empty()) cout<<"Stack is Empty"<<endl;
	system("pause");
}