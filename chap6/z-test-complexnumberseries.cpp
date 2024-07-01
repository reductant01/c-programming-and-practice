/*
* 2022. 4. 21. �߰���� ���� ����- ���� ���� �ð��� plato ���� ���� �ð��� �ڵ����� �����Ǵ� ���� 5������ ������ ��
1. ���� �ǽ��ڵ�, github, ���� �� ��� �ҽ� �ڵ� �̿� ������
2. �Ʒ� ���õ� �ڵ� ����� �ƴϸ� 0�� ó��
3. ���� �л��� ������ �ҽ��ڵ忡 ���� ǥ�� �˻�� plato � ���� ����
4. 3,4�г��� �븮 ���� ġ���� ��쿡 ���߽� Ȩ������ ���� �� ���к��ο� ¡�� ��û
   (���� �� �ڵ� ���� ����� �ϰ��� �˻�� �ǽ��л� ��ȯ�Ͽ� ��� �˻� ������)
5. �ҽ��ڵ�� ���� ����� ȭ�� ������ plato�� ���Ϸ� ����
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
    operator float();//���Ҽ��� ũ��, magnitude�� return�ϴ� �����ڸ� �����ؾ� �Ѵ� 
    friend istream& operator >> (istream& s, Complex& c);
    friend ostream& operator << (ostream& s, Complex c);
    Complex PrintComplex(Complex);// operator<<()�� ����Ͽ� ����ϰ� complex�� return�ϴ� �Լ� ����
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
    Complex& SumComplex();   // Complex& operator + (const Complex&); �̿��Ͽ� ����
    //(2+3i) * (4+5i) = 8 + 10i + 12i + 15 i*i = -7 + 22i
    Complex& MultiplyComplex();   // Complex& operator * (const Complex&); �̿��Ͽ� ����
    Complex& Delete();
   
    friend ostream& operator << (ostream& s, ComplexNumberSeries&);//reuse: friend ostream& operator << (ostream& s, Complex c);
    static int numberTerms();//���Ҽ� series�� ���� ����(top)�� return�Ѵ�.
    void addComplexNumber(Complex&);//pass�� complex�� series�� �߰��ϰ� top++
private:
    static int top;//Term�� ������ ���
    Complex* Term;
};
Complex PrintComplex(Complex c)
{
    Complex cmpl;
    cmpl = c;
    cout << cmpl;
    return cmpl;
}
int ComplexNumberSeries::top = 0;//top�� term�� �߰��Ǹ� ����, �����Ǹ� ����
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
        case 1://�׽�Ʈ �� �Է� ���� ���� �ð��� ������ - ������ �Է� ���� ������� ���� ���� �������� ���� 0�� ó��
            cout << "Add a new Complex number" << endl;
            cin >> t;//add a new Complex number
            ax.addComplexNumber(t);
            break;

        case 2:
            cout << "Delete the first Complex" << endl;
            t = ax.Delete();
            cout << "The deleted Complex is : ";
            cout << t;
            magnitude = t;//��ȯ������ ȣ��
            cout << "Magnitude of complex number = " << magnitude << endl;
            break;

        case 3:
            cout << "Display all the Complexs: " << endl;
            cout << ax;//ax = (1.1 + 2.2i) + (3.3 + 4.4i) + ������ ����ϰ� ����
            break;

        case 4:
            cout << "Summarize all the Complexs: ";
            t = ax.SumComplex();//��� complex ���� sum
            cout << "The sumup Complex is : ";
            cout << t;
            break;
        case 5:
            cout << "Multiply all the Complexs(t = a * b * c * d): ";
            t = ax.MultiplyComplex();//��� complex ���� multiply
            cout << "The Multiply Complex numbers is : ";
            Complex cx = PrintComplex(t);
            cout << cx;
            break;
        default:
            exit(0);
            break;
        }//destructor ����
    }
    system("pause");
    return 0;
}