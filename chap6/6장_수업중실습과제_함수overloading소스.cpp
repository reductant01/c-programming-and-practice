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
    static int count;
    float r;    // ���Ҽ��� �Ǽ���
    float i;    // ���Ҽ��� �����
    //������ ����
public:
    Complex();
    Complex(float, float);
    Complex(Complex&);
    // overloading�� member �Լ�
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
// overloading�� non-member �Լ�
Complex& Multiply(Complex& c1, Complex& c2) {
    float temp_r = c1.getR() * c2.getR() - c1.getI() * c2.getI();
    float temp_i = c1.getR() * c2.getI() + c1.getI() * c2.getR();

    // �ӽ� ��ü�� ����Ű�� ���� ��ȯ
    Complex* result = new Complex(temp_r, temp_i);
    return *result;
}

Complex& Multiply(Complex& c, int n) {
    // ���� ����� ������ �ӽ� ��ü ����
    float temp_r = c.getR() * n;
    float temp_i = c.getI() * n;

    // �ӽ� ��ü�� ����Ű�� ���� ��ȯ
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
        // �����Ͱ� nullptr�� ��� ���� ó�� �Ǵ� ���� �޽����� ����� �� ����
        // ���⼭�� �ܼ��� �޽����� ����ϵ��� ��
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
    return *this; // ù ��° ���Ҽ� ��ü�� ��ȯ
}
Complex& Complex::Multiply(Complex& other) {
    // ���� ����� �ӽ� ������ �����Ͽ� ���� �Ŀ� ���� ��ü�� ����
    float temp_r = r * other.r - i * other.i;
    float temp_i = r * other.i + i * other.r;

    r = temp_r;
    i = temp_i;

    return *this; // ù ��° ���Ҽ� ��ü�� ��ȯ
}
void Complex::Print(char* label) const {
    cout << label << ": " << r << " + " << i << "i" << endl;
}
Complex::~Complex() {
    // ������ ���� �۾��� �ʿ� �����Ƿ� ����Ӵϴ�.
}
// ���� �Լ��� operator+�� ����



// overloading�� non-member �Լ��� �ٸ� ��
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


// main �Լ��� ��� ���ǵ� overloading�� �Լ��� �̿��Ѵ�.
//d = a + b + c; �Լ��� ���� �ڵ� >(d = a.Add(b)).Add(c)
void main() {
    int count = 0;
    cout << "count = " << Complex::GetCount() << endl;;
    Complex x; x.AddComplexComplex(3, 1);//operator +()�� ����� �ڵ�� ������ �ǽ� ����
    Complex y(1., 2.);
    Complex z(y);
    Complex result, result2;
    Complex newResult;
    cout << "count = " << Complex::GetCount() << endl;;
    int n = 4;
    Print((char*)"Sum of the complex numbers:");
    cout << "x = "; Print(x);//cout <<x;�� ����� �ǽ����� �����ϱ�
    cout << "y = "; Print(y);
    cout << "n = "; Print(n);
    // �� ���Ҽ��� ��: Add()�Լ��� ù ��° version
    result = x.Add(y);
    Print((char*)"----");
    result.Print((char*)"x+y = ");
    // ���Ҽ��� �Ǽ��� ��: Add ()�Լ��� �� ��° version
    result2 = (x.Add(y)).Add(z);

    // �ٸ� �� �Լ��� �̿��Ͽ� �� ���� ����Ѵ�.
    result2.Print((char*)"x + y + z = ");

    Complex product1, product2;
    product1 = x.Multiply(y);
    Print((char*)"----");
    product1.Print((char*)"x*y = ");
    // ���Ҽ��� �Ǽ��� ��: Multiply ()�Լ��� �� ��° version
    product2 = (x.Multiply(y)).Multiply(z);

    // �ٸ� �� �Լ��� �̿��Ͽ� �� ���� ����Ѵ�.
    product2.Print((char*)"x + y + z = ");
    cout << "count = " << product2.GetCount() << endl;;
    newResult = product2;
    newResult.Print((char*)"ġȯ�� newResult = product2;");
    system("pause");
}