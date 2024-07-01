// 10-6.STA2-USE.CPP  10.3 상속과 polymorphism을 사용하여 genericity 표현

#include <iostream>
using namespace std;
#include "10-4.STACK2.h"
//generic인 것으로부터 유도된 정수 class를 정의
class IntObject : public GenericObject{
public:
    int data;
    IntObject(int num):
    data(num)
    {}
};

class doubleObject : public GenericObject{
public:
    double data;
    doubleObject(double num):
    data(num)
    {}
};

class floatObject : public GenericObject{
public:
    float data;
    floatObject(float num):
    data(num)
    {}
};

void main(){
	//*
    //주석 1
    //generic stack을 정의
    Stack genericStack_1;

    //그 stack에 값들을 추가
    genericStack_1.Push(new IntObject(500));
    genericStack_1.Push(new IntObject(1992));
    genericStack_1.Push(new IntObject(33));
    genericStack_1.Push(new IntObject(1024));

    //stack에서 하나씩 꺼내면서 출력한다.
    //Pop 함수가 GenericObject에 대한 pointer를 return하기 때문에
    //그 객체를 접근하기 위해서 타입 변환이 필요하다.
    cout<<"-----int type stack"<<endl;
    while(! genericStack_1.Empty()){
        cout<< ((IntObject*)genericStack_1.Pop())->data << endl;
    }
    //*/
	//*
    //주석 2
    Stack genericStack_2;
    genericStack_2.Push(new doubleObject(500.812));
    genericStack_2.Push(new doubleObject(1992.835));
    genericStack_2.Push(new doubleObject(33.877));
    genericStack_2.Push(new doubleObject(1024.809));

    cout<<endl<<"-----double type stack"<<endl;
    while(! genericStack_2.Empty()){
        cout << ((doubleObject*)genericStack_2.Pop())->data << endl;
    }
    //*/
	/*
    //주석 3
    Stack genericStack_3;
    genericStack_3.Push(new floatObject(500.887));
    genericStack_3.Push(new floatObject(1992.811));
    genericStack_3.Push(new floatObject(33.899));
    genericStack_3.Push(new floatObject(1024.851));

    cout<<endl<<"-----float type stack"<<endl;
    while(! genericStack_3.Empty()){
        cout << ((floatObject*)genericStack_3.Pop())->data << endl;
    }
    */
	/*
    //주석 4
    cout<<endl<<"-----float type stack"<<endl;
    while(! genericStack_3.Empty()){
        //오류 발생
        cout << genericStack_3.Pop()->data << endl; 
    }
    */
    system("pause");
}