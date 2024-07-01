// 6-4.OVERLOAD.CPP
// overloading된 member function 호출과 non-member 함수 호출의 차이를 실습
#include <iostream>
using namespace std;
/*
실습 4
1)내용
 Complex의 member함수 Add()와 non-member함수 Multiple()의 선언 및 호출 방법을 통하여 함수 Overloading에 대해 이해해보자.

2)방법
 가. Complex의 member함수 Add()와 non-member 함수 Multiple()의 선언형태를 확인해보자.
 나. main함수에서 Add와 Multiple 함수 호출 방식을 확인해보자.
 다. 각 호출방식에 따른 출력결과를 통해 어떤 함수가 호출되었는지 확인해보자.
*/
// public member를 가진 class 
class Complex {
private:
    static int count;
    float r;    // 복소수의 실수부
    float i;    // 복소수의 허수부
public:
    //생성자 구현
    Complex();
    Complex(float, float);
    Complex(Complex&);
    // overloading된 member 함수
    void SetComplex(Complex c);
    void  SetComplex(Complex* pc);
    void SetComplex(int a, int b = 0); //SetComplex(5)와 같이 b가 생략될 경우를 위함
    static int GetCount();
    Complex& operator +(Complex&);
    Complex& operator *(Complex&);
    Complex& operator =(Complex&); //왜 &가 쓰이는지 질문
    ~Complex();
    friend ostream& operator<<(ostream& stream, Complex&); //질문하기
};


int Complex::count = 0;

Complex::Complex() : r(0.0), i(0.0) {
    count++; // 객체가 생성될 때마다 count 증가
}

Complex::Complex(float real, float imag) : r(real), i(imag) {
    count++; // 객체가 생성될 때마다 count 증가
}

Complex::Complex(Complex& other) : r(other.r), i(other.i) {
    count++; // 객체가 생성될 때마다 count 증가
}

void Complex::SetComplex(Complex c) {
    this->r = c.r; // 다른 객체의 실수부를 현재 객체에 설정
    this->i = c.i; // 다른 객체의 허수부를 현재 객체에 설정
}

void Complex::SetComplex(Complex* pc) {
    if (pc != nullptr) {
        this->r = pc->r; // 포인터로 전달된 객체의 실수부를 현재 객체에 설정
        this->i = pc->i; // 포인터로 전달된 객체의 허수부를 현재 객체에 설정
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
    float real_part = this->r + other.r; // 실수부 덧셈
    float imag_part = this->i + other.i; // 허수부 덧셈
    Complex* result = new Complex(real_part, imag_part); // 새로운 객체 생성
    return *result; // 결과 객체 반환
}

Complex& Complex::operator*(Complex& other) {
    float real_part = (this->r * other.r) - (this->i * other.i); // 실수부 곱셈
    float imag_part = (this->r * other.i) + (this->i * other.r); // 허수부 곱셈
    Complex* result = new Complex(real_part, imag_part); // 새로운 객체 생성
    return *result; // 결과 객체 반환
}

Complex& Complex::operator=(Complex& other) {
    this->r = other.r; // 실수부 복사
    this->i = other.i; // 허수부 복사
    return *this; // 복사된 객체 반환
}

Complex::~Complex() {

}

ostream& operator<<(ostream& stream, Complex& c) {
    stream << c.r << " + " << c.i << "i" << endl;
    return stream;
}


void main() {
    cout << "count = " << Complex::GetCount() << endl;;
    Complex x; x.SetComplex(3, 1);//operator +()를 사용한 코드로 변경한 실습 시행
    Complex y(1., 2.);
    Complex z(y);
    Complex result, result2;
    Complex newResult;
    cout << "count = " << Complex::GetCount() << endl;;

    cout << "x = " << x << "y = " << y;

    // 두 복소수의 합: Add()함수의 첫 번째 version
    result = x + y;
    cout << "x+y = " << result;
    result2 = x + y + z;
    cout << "x + y + z = " << result2;

    Complex product1, product2;
    product1 = x * y;
    cout << "x*y = " << product1;
    // 복소수와 실수의 합: Multiply ()함수의 세 번째 version
    product2 = x * y * z;
    cout << "x + y + z = " << product2;
    cout << "count = " << product2.GetCount() << endl;;
    newResult = product2;
    cout << "치환문 newResult = product2 = " << newResult;
    system("pause");
}