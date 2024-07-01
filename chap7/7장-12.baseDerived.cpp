//7장-12 baseDerived.cpp - subclass 객체의 size, default 생성자에 의한 초기 값 문제
//상속의 의미를 이해하기 위한 코드 
#include <iostream>
using namespace std;
class Base{
public:
    int first;
    int second;
	int GetFourth() { 
		cout << "Base::fourth = ";
		return fourth; }
protected:
    int third;
private:
    int fourth;
};
	
class Derived : protected Base{
private:
    int fifth;
public:
	void show() {
		cout << "third = " << third << endl;;
		//cout << fourth;//Base::fourth는 접근 못함-해결 방법은?
		//cout<<fourth;
		cout << GetFourth() << endl;
	}
};
void main() {
	//생성된 객체들의 크기를 확인하여 상속의 의미를 이해
    cout<<"Size of Base : "<<sizeof(Base)<<endl;
    cout<<"Size of Derived : "<<sizeof(Derived)<<endl;
	Derived d;
	cout << "sizeof(d)= " << sizeof(d) << endl;;
	//cout << d.first;//first가 protected로 변경됨
	d.show();//생성자가 정의되지 않아 엉터리값 출력
	system("pause");
}