//7��-12 baseDerived.cpp - subclass ��ü�� size, default �����ڿ� ���� �ʱ� �� ����
//����� �ǹ̸� �����ϱ� ���� �ڵ� 
#include <iostream>
using namespace std;
class Base{
public:
    int first;
    int second;
	int GetFourth() { 
		cout << "Base::fourth = ";
		return fourth; }
protected:
    int third;
private:
    int fourth;
};
	
class Derived : protected Base{
private:
    int fifth;
public:
	void show() {
		cout << "third = " << third << endl;;
		//cout << fourth;//Base::fourth�� ���� ����-�ذ� �����?
		//cout<<fourth;
		cout << GetFourth() << endl;
	}
};
void main() {
	//������ ��ü���� ũ�⸦ Ȯ���Ͽ� ����� �ǹ̸� ����
    cout<<"Size of Base : "<<sizeof(Base)<<endl;
    cout<<"Size of Derived : "<<sizeof(Derived)<<endl;
	Derived d;
	cout << "sizeof(d)= " << sizeof(d) << endl;;
	//cout << d.first;//first�� protected�� �����
	d.show();//�����ڰ� ���ǵ��� �ʾ� ���͸��� ���
	system("pause");
}