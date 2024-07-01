 //7장-11 classDefine.cpp
// private, public derivation의 차이를 이해하는 것이 필요하다
#include <iostream>
using namespace std;

class A{
private:
    int a1;
protected:
    int a2;
public:
    int a3;
	A(int i = 0, int j = 0, int k = 0):a1(i), a2(j), a3(k) {}
	
	void virtual show() {//overriding
	//void show() {//overloading
		cout<<"A::show() -> a1 ="<<a1<<", a2 = "<<a2<<", a3 = "<<a3<<endl;
	}
};
//ostream& operator<<(ostream& s, A a); 구현
class B : private A{
//class B : public A { //public유도
private:
    int b1;
protected:
    int b2;
public:
    int b3;
	B(int i = 0, int j = 0, int k = 0): A(i+10,j+10,k+10) {b1 = i; b2 = j; b3 = k;}
	void show() {//overloading
		A::show();//code reuse 사용예
		cout<<"B::show()->b1 ="<<b1<<", b2 = "<<b2<<", b3 = "<<b3<<endl;
	}
};
//ostream& operator<<(ostream& s, B b); 구현
class C: private B{ //main에서 타입 변환이 안되는 문제를 이해하는 것이 필요
	//class C : public B {
private:
    int c1;
protected:
    int c2;
public:
    int c3;
	C(int i = 0, int j = 0, int k = 0):B(i+20,j+20,k+20) {c1 = i; c2 = j; c3 = k;}
	void show() {
		B::show();//code reuse 사용예
		cout<<"C::show()-> c1 ="<<c1<<", c2 = "<<c2<<", c3 = "<<c3<<endl;
	}
};
//ostream& operator<<(ostream& s, C c); 구현
int main(void){
    A * ax = new A(1,2,3);
	cout<<"ax ::"<<endl;
	ax.show();
    B *bx = new B(4,5,6);
	cout <<"bx = ::"<<endl;
	bx.show();
    C *cx = new C (7,8,9);
	cout<<"cx = ::"<<endl;
	cx.show();
	//access 할 수 없는 기본 class A로 변환은 허용되지 않는다 - protected 상속에 대하여
	//ax = bx;//오류: class B : protected A{}으로 비허용
	cout << "After ax = bx;" << endl;
	ax.show();
	//ax = (A)bx;//오류: class B : protected A{}으로 선언할 때
	cout << "ax = (A)bx;" << endl;
	//bx = cx;//B의 생성자를 main에서 호출할 수 없다 
	bx = dynamic_cast<B*>(cx);
	bx = (B)cx;
	cout << "bx == cx " << endl;
	ax.show();
	bx.show();
	cx.show();
	cout << "bx = (B)cx" << endl;
	bx = (B)cx;
	ax.show();
	bx.show();
	cx.show();
	B bx1(11, 22, 33);
	bx = bx1;
	bx.show();
	cout << "cx.B::show()" << endl;
	cx.B::show();
	system("pause");
	return 1;
}
