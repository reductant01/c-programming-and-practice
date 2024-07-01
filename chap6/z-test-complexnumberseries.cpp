/*
* 2022. 4. 21. 중간고사 시험 문제- 제출 마감 시간은 plato 제출 마감 시간이 자동으로 설정되니 마감 5분전에 제출할 것
1. 기존 실습코드, github, 구글 등 모든 소스 코드 이용 가능함
2. 아래 제시된 코드 기반이 아니면 0점 처리
3. 동료 학생이 제공한 소스코드에 대한 표절 검사는 plato 등에 의해 시행
4. 3,4학년이 대리 시험 치르는 경우에 적발시 홈페이지 공지 및 대학본부에 징계 요청
   (과제 및 코딩 시험 결과의 일관성 검사로 의심학생 소환하여 대면 검사 시행함)
5. 소스코드와 실행 결과의 화면 덤프를 plato에 파일로 제출
*/
#include <iostream>
using namespace std;
class Complex {
    float real;
    float imag;
public:
    Complex() {}
    Complex(float re, float im) {
        real = re;
        imag = im;
    }
    Complex(const Complex&);
    float Re() {
        return real;
    }
    float Im() {
        return imag;
    }
    Complex& operator + (const Complex&);
    Complex& operator * (const Complex&);
    operator float();//복소수의 크기, magnitude를 return하는 연산자를 구현해야 한다 
    friend istream& operator >> (istream& s, Complex& c);
    friend ostream& operator << (ostream& s, Complex c);
    Complex PrintComplex(Complex);// operator<<()를 사용하여 출력하고 complex을 return하는 함수 구현
};

istream& operator >> (istream& s, Complex& c) {
    s >> c.real >> c.imag;
    return s;
}
ostream& operator << (ostream& s, Complex c) {
    s << c.real << " + " << c.imag << "i";
    return s;
}

class ComplexNumberSeries {

public:
    ComplexNumberSeries(int t = 0);
    Complex& SumComplex();   // Complex& operator + (const Complex&); 이용하여 구현
    //(2+3i) * (4+5i) = 8 + 10i + 12i + 15 i*i = -7 + 22i
    Complex& MultiplyComplex();   // Complex& operator * (const Complex&); 이용하여 구현
    Complex& Delete();
   
    friend ostream& operator << (ostream& s, ComplexNumberSeries&);//reuse: friend ostream& operator << (ostream& s, Complex c);
    static int numberTerms();//복소수 series의 항의 숫자(top)를 return한다.
    void addComplexNumber(Complex&);//pass된 complex를 series에 추가하고 top++
private:
    static int top;//Term의 갯수를 기록
    Complex* Term;
};
Complex PrintComplex(Complex c)
{
    Complex cmpl;
    cmpl = c;
    cout << cmpl;
    return cmpl;
}
int ComplexNumberSeries::top = 0;//top은 term이 추가되면 증가, 삭제되면 감소
int main() {
    int select;
    ComplexNumberSeries ax;
    Complex t;
    float magnitude;
    while (1)
    {
        cout << "\nSelect command 1: Add Complex number, 2: Delete first Complex number, 3. Display all,4. Sum, 5. Multiply, 6.Quit = > ";
        cin >> select;
        switch (select) {
        case 1://테스트 용 입력 값은 시험 시간에 전달함 - 지정된 입력 값을 사용하지 않을 때는 부정행위 간주 0점 처리
            cout << "Add a new Complex number" << endl;
            cin >> t;//add a new Complex number
            ax.addComplexNumber(t);
            break;

        case 2:
            cout << "Delete the first Complex" << endl;
            t = ax.Delete();
            cout << "The deleted Complex is : ";
            cout << t;
            magnitude = t;//변환연산자 호출
            cout << "Magnitude of complex number = " << magnitude << endl;
            break;

        case 3:
            cout << "Display all the Complexs: " << endl;
            cout << ax;//ax = (1.1 + 2.2i) + (3.3 + 4.4i) + 등으로 출력하게 구현
            break;

        case 4:
            cout << "Summarize all the Complexs: ";
            t = ax.SumComplex();//모든 complex 들의 sum
            cout << "The sumup Complex is : ";
            cout << t;
            break;
        case 5:
            cout << "Multiply all the Complexs(t = a * b * c * d): ";
            t = ax.MultiplyComplex();//모든 complex 들의 multiply
            cout << "The Multiply Complex numbers is : ";
            Complex cx = PrintComplex(t);
            cout << cx;
            break;
        default:
            exit(0);
            break;
        }//destructor 구현
    }
    system("pause");
    return 0;
}