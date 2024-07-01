// 6-4.OVERLOAD.CPP
// overloading�� member function ȣ��� non-member �Լ� ȣ���� ���̸� �ǽ�
#include <iostream>
using namespace std;
/*
�ǽ� 4
1)����
 Complex�� member�Լ� Add()�� non-member�Լ� Multiple()�� ���� �� ȣ�� ����� ���Ͽ� �Լ� Overloading�� ���� �����غ���.

2)���
 ��. Complex�� member�Լ� Add()�� non-member �Լ� Multiple()�� �������¸� Ȯ���غ���.
 ��. main�Լ����� Add�� Multiple �Լ� ȣ�� ����� Ȯ���غ���.
 ��. �� ȣ���Ŀ� ���� ��°���� ���� � �Լ��� ȣ��Ǿ����� Ȯ���غ���.
*/
// public member�� ���� class 
class Complex {
private:
    static int count;
    float r;    // ���Ҽ��� �Ǽ���
    float i;    // ���Ҽ��� �����
public:
    //������ ����
    Complex();
    Complex(float, float);
    Complex(Complex&);
    // overloading�� member �Լ�
    void SetComplex(Complex c);
    void  SetComplex(Complex* pc);
    void SetComplex(int a, int b = 0); //SetComplex(5)�� ���� b�� ������ ��츦 ����
    static int GetCount();
    Complex& operator +(Complex&);
    Complex& operator *(Complex&);
    Complex& operator =(Complex&); //�� &�� ���̴��� ����
    ~Complex();
    friend ostream& operator<<(ostream& stream, Complex&); //�����ϱ�
};


int Complex::count = 0;

Complex::Complex() : r(0.0), i(0.0) {
    count++; // ��ü�� ������ ������ count ����
}

Complex::Complex(float real, float imag) : r(real), i(imag) {
    count++; // ��ü�� ������ ������ count ����
}

Complex::Complex(Complex& other) : r(other.r), i(other.i) {
    count++; // ��ü�� ������ ������ count ����
}

void Complex::SetComplex(Complex c) {
    this->r = c.r; // �ٸ� ��ü�� �Ǽ��θ� ���� ��ü�� ����
    this->i = c.i; // �ٸ� ��ü�� ����θ� ���� ��ü�� ����
}

void Complex::SetComplex(Complex* pc) {
    if (pc != nullptr) {
        this->r = pc->r; // �����ͷ� ���޵� ��ü�� �Ǽ��θ� ���� ��ü�� ����
        this->i = pc->i; // �����ͷ� ���޵� ��ü�� ����θ� ���� ��ü�� ����
    }
}

void Complex::SetComplex(int a, int b) {
    r = a;
    i = b;
}

int Complex::GetCount() {
    return count;
}

Complex& Complex::operator+(Complex& other) {
    float real_part = this->r + other.r; // �Ǽ��� ����
    float imag_part = this->i + other.i; // ����� ����
    Complex* result = new Complex(real_part, imag_part); // ���ο� ��ü ����
    return *result; // ��� ��ü ��ȯ
}

Complex& Complex::operator*(Complex& other) {
    float real_part = (this->r * other.r) - (this->i * other.i); // �Ǽ��� ����
    float imag_part = (this->r * other.i) + (this->i * other.r); // ����� ����
    Complex* result = new Complex(real_part, imag_part); // ���ο� ��ü ����
    return *result; // ��� ��ü ��ȯ
}

Complex& Complex::operator=(Complex& other) {
    this->r = other.r; // �Ǽ��� ����
    this->i = other.i; // ����� ����
    return *this; // ����� ��ü ��ȯ
}

Complex::~Complex() {

}

ostream& operator<<(ostream& stream, Complex& c) {
    stream << c.r << " + " << c.i << "i" << endl;
    return stream;
}


void main() {
    cout << "count = " << Complex::GetCount() << endl;;
    Complex x; x.SetComplex(3, 1);//operator +()�� ����� �ڵ�� ������ �ǽ� ����
    Complex y(1., 2.);
    Complex z(y);
    Complex result, result2;
    Complex newResult;
    cout << "count = " << Complex::GetCount() << endl;;

    cout << "x = " << x << "y = " << y;

    // �� ���Ҽ��� ��: Add()�Լ��� ù ��° version
    result = x + y;
    cout << "x+y = " << result;
    result2 = x + y + z;
    cout << "x + y + z = " << result2;

    Complex product1, product2;
    product1 = x * y;
    cout << "x*y = " << product1;
    // ���Ҽ��� �Ǽ��� ��: Multiply ()�Լ��� �� ��° version
    product2 = x * y * z;
    cout << "x + y + z = " << product2;
    cout << "count = " << product2.GetCount() << endl;;
    newResult = product2;
    cout << "ġȯ�� newResult = product2 = " << newResult;
    system("pause");
}