
#include <iostream>
using namespace std;

class SimpleData {
	int value;
	static int count;//��ü�� ������ ������ count++
public:
	SimpleData();
	SimpleData(int);
	SimpleData(const SimpleData&);
	~SimpleData();
	SimpleData& operator=(const SimpleData&);
	int operator++();
	static int Show();//count ���� �ʱ�ȭ
	friend ostream& operator << (ostream& stream, SimpleData&);
};

void main() {
	SimpleData sd1;
	SimpleData sd2(10);
	SimpleData sd3(sd2);
	SimpleData::Show();
	sd1.Show();
	SimpleData sd4 = sd2;
	sd3 = sd2;
	cout << endl;
	cout << sd4;
	system("pause");
}