
#include <iostream>
using namespace std;

class SimpleData {
	int value;
	static int count;//객체가 생성될 때마다 count++
public:
	SimpleData();
	SimpleData(int);
	SimpleData(const SimpleData&);
	~SimpleData();
	SimpleData& operator=(const SimpleData&);
	int operator++();
	static int Show();//count 값을 초기화
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