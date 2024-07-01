#include <iostream>
using namespace std;

// Base 클래스 A
class A {
protected:
    int a;
public:
    A(int a) : a(a) {
        cout << "Constructor of A" << a << endl;
    }
    virtual ~A() {
        cout << "Destructor of A" << endl;
    }
    void show() const {
        cout << "I am class A" << "a=" << a << endl;
    }
};

// 클래스 B는 A를 가상 상속
class B : virtual public A { //virtual A를 쓰지 않으면 나중에 D클래스에는 A가 2개가 생성된다
protected:
    int b;
public:
    B(int a, int b) : A(a), b(b) {
        cout << "Constructor of B" << b << endl;
    }
    virtual ~B() {
        cout << "Destructor of B" << endl;
    }
    void show() const {
        cout << "I am class B" << "a=" << a << "b=" << b << endl;
    }
};

// 클래스 C는 A를 가상 상속
class C : virtual public A {
protected:
    int c;
public:
    C(int a, int c) : A(a), c(c) {
        cout << "Constructor of C" << c << endl;
    }
    virtual ~C() {
        cout << "Destructor of C" << endl;
    }
    void show() const {
        cout << "I am class C" << "a=" << a << "c=" << c << endl;
    }
};

// 클래스 D는 B와 C를 상속
class D : public B, public C {
    int d;
public:
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c), d(d) { //B와 C가 virtual A를 상속받기 때문에 A(a)를 꼭 넣어줘야한다
        cout << "Constructor of D" << endl;
    }
    ~D() {
        cout << "Destructor of D" << endl;
    }
    void show() const {
        cout << "I am class D" << "a=" << a << "b=" << a << "c=" << c << "d=" << d << endl;
    }
};

int main() {
    D d(1, 2, 3, 4);
    C c(5, 6);
    c.show();
    d.show();

    // A의 멤버 함수 호출
    d.C::show();
    int num;
    cin >> num;
    return 0;
}