
#include <iostream>
using namespace std;
class Complex
{
private:
	float real;//�Ǽ�
	float imag;//���
};
class SimpleData {
	Complex *arrayComplex;
	static int count;//��ü�� ������ ������ count++
public:
	SimpleData();
	SimpleData(int);
	SimpleData(const SimpleData&);
	~SimpleData();
	SimpleData& operator=(const SimpleData&);
	int operator++();
	operator float();//�迭�� �� ������ ���Ҽ� ũ���� ���� return
	static int Show();//count ���� �ʱ�ȭ
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