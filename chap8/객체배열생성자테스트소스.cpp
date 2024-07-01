#include <iostream>
using namespace std;
class A {
	string name;
public:
	A(){}
	A(string name) :name(name){}
	friend ostream& operator<<(ostream& os, A& a) {
		os << a.name;
		return os;
	}
};
int main() {
	A* p;
	p = new A[10];
	A q("kim");
	A r("no");
	//p[0] = new A("hong");
	p[0] = q;
	p[1] = r;
	cout << p[0]<<endl<<p[1]<<endl;
	delete[] p;
	system("pause");
	return 1;
}