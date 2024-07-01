#include <iostream>
using namespace std;

class Base {
public:
	virtual Base* GetNumber() {
		cout << "Base Å¬·¡½º";
		return this;
	}
};

class Subclass : public Base {
public:
	virtual Subclass* GetNumber() {
		cout << "Subclass";
		return this;
	}
};

int main() {
	Base* b = new Subclass();
	b->GetNumber();
	system("pause");
	return 1;
}