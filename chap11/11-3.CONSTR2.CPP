// 11-3.CONSTR2.CPP  11.5 생성자의 중지
#include <iostream>
using namespace std;
/*
1. 내용
   본 source code는 constructor에서 throw가 발생하면 어떻게 되는지를 알아보는 내용이다.
2. 방법
   가) program을 실행하여 num이 0일 때 DerivedClass constructor에서 throw가 발생하면 어떻게 되는 것인지 출력 결과를 통해서 알아보자
*/

class ZeroError
{ };
class Base{
protected:
    int value;
public:
    Base(int num) : value (num){
        cout << "Base class constructor called for "<< value << endl;
    }
    ~Base( ){
        cout << "Base class destructor called for "<< value << endl;
    }
};
class Derived: public Base{
public:
    Derived (int num) : Base (num){
        cout << "Entering the derived class constructor for "<< value << endl;
        if (num == 0)
            throw(new ZeroError); 
    }
    ~Derived( ){
         cout << "Derived class destructor called for "<< value << endl;
    }
};

void main( ){
    try {
        //Derived one(999);
        Derived two(0);
        //생성자에서 abort될 때 Base class 의 소멸자가 호출되는지를 확인하는 실습
        // …operations on the objects
    }
    catch (ZeroError*){
        cout << "Error: zero value!" << endl;
    }
	system("pause");
}