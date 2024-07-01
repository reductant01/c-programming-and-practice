// 10-9.RunSpeaking.cpp  10.5.1 RunSpeaking 함수의 재검토
#include <iostream>
#include <stdlib.h>
#include "time.h"
using namespace std;
/*
실습 5
 1) 내용
  본 source code는 template을 이용하여 다양한 데이터 타입의 객체들을 다루는 방법을 알아보는 것이다.
 2) 방법
  가. 주석 1의 RunSpeaking()과 주석 2의 RunSpeaking()의 source code를 비교하고 차이점을 알아보자.
  나. 주석 1과 2를 하나씩 주석 해제하고 실행해보고 template의 개념을 이해해보자.
  다. Animal class를 제거한 후에 template 함수가 동작하도록 수정하는 실습을 해보자.
*/
//class Point의 interface는 inline 함수로 정의된다.
class Point{
public:
    Point(int xp=0, int yp = 0):
    xPos(xp), yPos(yp)
    {}

     int x_Coor()
    {return xPos;}

    int y_Coor()
    {return yPos;}

    void x_Coor(int px)
    {xPos = px;}

    void y_Coor(int py)
    {yPos = py;}

    void operator += (Point p){
        xPos += p.xPos;
        yPos += p.yPos;
    }
private:
      int xPos, yPos;
};

class Animal{
public:
Animal(Point p = Point());
    //virtual ~Animal();
    virtual void Speak();
    //virtual void Speak() = 0;
    void JumpBy(int x_coord, int y_coord);
    void MoveTo(Point newPosition);

protected:
    Point position;
    void MoveOutput();
   };

Animal::Animal(Point p):
position(p)
{}

void Animal::Speak(){
    cout<<"Animal::Speak() -> The animal is making his verse"<<endl;
}

void Animal::JumpBy(int x_coord, int y_coord){
    position += Point(x_coord, y_coord);
}

void Animal::MoveTo(Point newPosition){
    position = newPosition;
}

void Animal::MoveOutput(){
    cout<<"Animal::MoveOutPut()-> x = " << position.x_Coor()<<", y = "<<position.y_Coor()<<"  ";
}


class Cow : public Animal{
public:
    Cow(Point p = Point(10, 10));
    void Speak();
};

class Dog : public Animal{
public:
    Dog(Point p = Point(20, 20));
    void Speak();
};


Cow::Cow(Point p):
Animal(p){}

void Cow::Speak(){
    MoveOutput();
    cout<<"Cow::Speak() ->moo"<<endl;
}

Dog::Dog(Point p):
Animal(p){}

void Dog::Speak(){
    MoveOutput();
    cout<<"Dog::Speak()->arf"<<endl;
}
//8장에서 사용했던 RunSpeaking() 함수
//Animal에 대한 참조를 사용한 polymorphic global 함수
// 주석 1, 주석 2에 대하여 각각 해제하여 실행 확인한다. 상호 대신하여 coding이 가능함을 실행하여 확인
/* 주석 1
void RunSpeaking(Animal& aml, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        aml.JumpBy(x_coord, y_coord);
        aml.Speak();
    }
}
*/
//10장에서 새로 정의한 RunSpeaking() 함수
//Template를 사용한 genericity있는 global함수
//* 주석 2
template <class T>
void RunSpeaking(T& data, int nSteps){
    srand((unsigned)time(NULL));
    for(int temp=0; temp < nSteps;++temp){
        int x_coord = (1 + rand() % 5) - 2;
        int y_coord = (1 + rand() % 5) - 2;

        data.JumpBy(x_coord, y_coord);
        data.Speak();
    }
}
//*/

void main(){
    Animal* mixedFlock[10];

    mixedFlock[0] = new Cow();
    mixedFlock[1] = new Dog();
    mixedFlock[2] = new Dog(Point (12,24));
    mixedFlock[3] = new Dog(Point (2,12));
    mixedFlock[4] = new Dog(Point (22,24));
    mixedFlock[5] = new Cow(Point (7,7));
    mixedFlock[6] = new Cow(Point (7,11));
    mixedFlock[7] = new Cow(Point (11,13));
    mixedFlock[8] = new Animal(Point (1,1));
    mixedFlock[9] = new Dog(Point (7,19));

    for(int temp=0; temp< 10; temp++)
        RunSpeaking(*mixedFlock[temp], 1);
        system("pause");
}
