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
    static int count;
    float r;    // 복소수의 실수부
    float i;    // 복소수의 허수부
    //생성자 구현
public:
    Complex();
    Complex(float, float);
    Complex(Complex&);
    // overloading된 member 함수
    void AddComplex(Complex c);
    void AddComplexComplex(Complex* pc);
    void AddComplexComplex(int a, int b = 0);
    static int GetCount();
    Complex& Add(Complex&);
    Complex& Multiply(Complex&);
    void Print(char*)const;
    ~Complex();

    float getR() const { return r; }
    float getI() const { return i; }
    friend void Print(Complex& c);
};
// overloading된 non-member 함수
Complex& Multiply(Complex& c1, Complex& c2) {
    float temp_r = c1.getR() * c2.getR() - c1.getI() * c2.getI();
    float temp_i = c1.getR() * c2.getI() + c1.getI() * c2.getR();

    // 임시 객체를 가리키는 참조 반환
    Complex* result = new Complex(temp_r, temp_i);
    return *result;
}

Complex& Multiply(Complex& c, int n) {
    // 곱셈 결과를 저장할 임시 객체 생성
    float temp_r = c.getR() * n;
    float temp_i = c.getI() * n;

    // 임시 객체를 가리키는 참조 반환
    Complex result(temp_r, temp_i);
    return result;
}



int Complex::count = 0;
void Complex::AddComplex(Complex c) {
    r += c.r;
    i += c.i;
}
void Complex::AddComplexComplex(Complex* pc) {
    if (pc != nullptr) {
        r += pc->r;
        i += pc->i;
    }
    else {
        // 포인터가 nullptr인 경우 예외 처리 또는 오류 메시지를 출력할 수 있음
        // 여기서는 단순히 메시지를 출력하도록 함
        cout << "Error: Null pointer provided." << endl;
    }
}
void Complex::AddComplexComplex(int a, int b) {
    r += a;
    i += b;
}
int Complex::GetCount() {
    return count;
}
Complex& Complex::Add(Complex& other) {
    r += other.r;
    i += other.i;
    return *this; // 첫 번째 복소수 객체를 반환
}
Complex& Complex::Multiply(Complex& other) {
    // 곱셈 결과를 임시 변수에 저장하여 연산 후에 현재 객체에 복사
    float temp_r = r * other.r - i * other.i;
    float temp_i = r * other.i + i * other.r;

    r = temp_r;
    i = temp_i;

    return *this; // 첫 번째 복소수 객체를 반환
}
void Complex::Print(char* label) const {
    cout << label << ": " << r << " + " << i << "i" << endl;
}
Complex::~Complex() {
    // 별도의 정리 작업이 필요 없으므로 비워둡니다.
}
// 전역 함수로 operator+를 구현



// overloading된 non-member 함수의 다른 예
void Print(Complex& c) {
    cout << c.r << "+" << c.i << "i" << endl;
}
void Print(int n) {
    cout << n << endl;
}
void Print(char* string) {
    cout << string << endl;
}
void Print() {
    cout << endl;
}


// main 함수는 방금 정의된 overloading된 함수를 이용한다.
//d = a + b + c; 함수로 구현 코드 >(d = a.Add(b)).Add(c)
void main() {
    int count = 0;
    cout << "count = " << Complex::GetCount() << endl;;
    Complex x; x.AddComplexComplex(3, 1);//operator +()를 사용한 코드로 변경한 실습 시행
    Complex y(1., 2.);
    Complex z(y);
    Complex result, result2;
    Complex newResult;
    cout << "count = " << Complex::GetCount() << endl;;
    int n = 4;
    Print((char*)"Sum of the complex numbers:");
    cout << "x = "; Print(x);//cout <<x;를 사용한 실습으로 수정하기
    cout << "y = "; Print(y);
    cout << "n = "; Print(n);
    // 두 복소수의 합: Add()함수의 첫 번째 version
    result = x.Add(y);
    Print((char*)"----");
    result.Print((char*)"x+y = ");
    // 복소수와 실수의 합: Add ()함수의 세 번째 version
    result2 = (x.Add(y)).Add(z);

    // 다른 두 함수를 이용하여 두 곱을 계산한다.
    result2.Print((char*)"x + y + z = ");

    Complex product1, product2;
    product1 = x.Multiply(y);
    Print((char*)"----");
    product1.Print((char*)"x*y = ");
    // 복소수와 실수의 합: Multiply ()함수의 세 번째 version
    product2 = (x.Multiply(y)).Multiply(z);

    // 다른 두 함수를 이용하여 두 곱을 계산한다.
    product2.Print((char*)"x + y + z = ");
    cout << "count = " << product2.GetCount() << endl;;
    newResult = product2;
    newResult.Print((char*)"치환문 newResult = product2;");
    system("pause");
}