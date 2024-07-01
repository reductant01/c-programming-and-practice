
#include <iostream>

using namespace std;
class Complex {
private:
	float real;
	float imaginary;
public:
	Complex() { real = 0.0; imaginary = 0.0; }
	Complex(float r, float i) : real(r), imaginary(i) { }
	Complex& Add(const Complex&);
	Complex& Multiply(const Complex&);
	void ShowComplex(Complex a, Complex b, Complex c) const {
		cout << "complex number a = " << a.real << " + " << a.imaginary << "i" << endl;
		cout << "complex number b = " << b.real << " + " << b.imaginary << "i" << endl;
		cout << "complex number c = " << c.real << " + " << c.imaginary << "i" << endl;
		cout << "complex number result = " << real << " + " << imaginary << "i" << endl;
	}
};

Complex& Complex::Add(const Complex& other) {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex& Complex::Multiply(const Complex& other) {
	float temp_real = real * other.real - imaginary * other.imaginary;
	float temp_imaginary = real * other.imaginary + imaginary * other.real;
	real = temp_real;
	imaginary = temp_imaginary;
	return *this;
}

enum Menu { ADD, MULTIPLY, CASCADE, EXIT };

int main() {
	Complex number[10] = { Complex(1,2),Complex(1,3),Complex(1,4),Complex(1,5),Complex(1,6),
	Complex(2,2), Complex(3,3), Complex(4,2), Complex(5,6), Complex(6,7), };
	cout << "0.Add, 1.MULTIPLY, 2.CASCADE, 3.EXIT " << endl;
	Complex resultAdd;
	Complex resultProduct;
	Complex resultCascaded;
	int choice = -1;
	do {
		cout << "select Menu Number: ";
		cin >> choice;
		switch (static_cast<Menu>(choice)) {
		case ADD:
			cout << "c0 = c0 + C1 + c2 :" << endl;
				resultAdd = number[0];
                resultAdd.Add(number[1]);
                resultAdd.Add(number[2]);
			resultAdd.ShowComplex(number[0], number[1], number[2]);
			break;
		case MULTIPLY:
			cout << "c3 = c3 * c4 * c5" << endl;
                resultProduct = number[3];
                resultProduct.Multiply(number[4]);
                resultProduct.Multiply(number[5]);
			resultProduct.ShowComplex(number[3], number[4], number[5]);

			break;
		case CASCADE:
			cout << "c6 = (c6 + c7) * c8" << endl;
				resultCascaded = number[6];
				resultCascaded.Add(number[7]);
                resultCascaded.Multiply(number[8]);
			resultCascaded.ShowComplex(number[6], number[7], number[8]);
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
		case EXIT:
			return 1;
		}
	} while (true);
	system("pause");
	return 0;
}
