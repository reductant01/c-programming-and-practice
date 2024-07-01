#include <iostream>
using namespace std;

// Base Ŭ���� A
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

// Ŭ���� B�� A�� ���� ���
class B : virtual public A { //virtual A�� ���� ������ ���߿� DŬ�������� A�� 2���� �����ȴ�
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

// Ŭ���� C�� A�� ���� ���
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

// Ŭ���� D�� B�� C�� ���
class D : public B, public C {
    int d;
public:
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c), d(d) { //B�� C�� virtual A�� ��ӹޱ� ������ A(a)�� �� �־�����Ѵ�
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

    // A�� ��� �Լ� ȣ��
    d.C::show();
    int num;
    cin >> num;
    return 0;
}