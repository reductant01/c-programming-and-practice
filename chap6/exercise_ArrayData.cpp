
#include <iostream>
using namespace std;

class SimpleData {
	int *arraydata;
	int top;
	static int count;//��ü�� ������ ������ count++
public:
	SimpleData();
	SimpleData(int);
	SimpleData(const SimpleData&);
	~SimpleData();
	SimpleData& operator=(const SimpleData&);
	int operator++();
	static int Show();//count ���� �ʱ�ȭ
	SimpleData& addSimpleData(SimpleData&);
};
SimpleData::SimpleData(): top(10) 
{
	arraydata = new int[top];
}
void main() {
	SimpleData sd1;
	SimpleData sd2(20);
	SimpleData sd3(sd2);
	SimpleData::Show();
	sd1.Show();
	SimpleData sd4 = sd2;
	sd3 = sd2;
	SimpleData sd5 = sd1.addSimpleData(sd2);
	SimpleData sd6 = (sd5.addSimpleData(sd4)).addSimpleData(sd3);
	cout << endl;
	system("pause");
}