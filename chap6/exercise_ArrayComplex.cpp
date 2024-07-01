
#include <iostream>
using namespace std;
class Complex
{
private:
	float real;//실수
	float imag;//허수
};
class SimpleData {
	Complex *arrayComplex;
	static int count;//객체가 생성될 때마다 count++
public:
	SimpleData();
	SimpleData(int);
	SimpleData(const SimpleData&);
	~SimpleData();
	SimpleData& operator=(const SimpleData&);
	int operator++();
	operator float();//배열의 각 원소의 복소수 크기의 합을 return
	static int Show();//count 값을 초기화
	friend ostream& operator << (ostream& stream, SimpleData&);
};

void main() {
	float d = 1.0;
	SimpleData sd1;
	SimpleData sd2(10);
	SimpleData sd3(sd2);
	SimpleData::Show();
	sd1.Show();
	SimpleData sd4 = sd2 = sd1;
	sd3 = sd2;
	d = d + sd2;
	cout << endl;
	cout << sd4;
	system("pause");
}