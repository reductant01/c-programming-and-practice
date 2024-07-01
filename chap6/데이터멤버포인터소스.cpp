#include <iostream>
#include <stdlib.h>
using namespace std;
class Part {
	int pid;
	char *pname;
public: 
	Part() {
		pid = 0;
		pname = new char[4];
		strcpy(this->pname, "");
	}
	Part(int pid, char *pname) : pid(pid) { 
		this->pname = new char[sizeof(pname)+1];
		strcpy(this->pname, pname); }
	friend ostream& operator<<(ostream& , Part&);
	~Part() { delete[] pname; }
	Part& operator=(const Part&);
};
class Product {
	Part* items[10];
	int top;
public: 
	void Add(Part&);
	Product() { top = 0; }
	Part& Delete();
};
Part& Product::Delete() {
	return *items[--top];
}
void Product::Add(Part& px) {
	items[top++] = &px;
}
Part& Part::operator=(const Part& other) {
	if (this != &other) {
		pid = other.pid;
		delete[] pname;
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
	}
	return *this;
}
ostream& operator<<(ostream& os, Part& p) {
	os << "pid = " << p.pid << ", p = " << p.pname << endl;
	return os;
}

int main() {
	Product pa;
	{
		Part p1(22, "nice");
		Part p3;
		cout << p1;

		Part p2(10, "good");
		p1 = p2;
		pa.Add(p2);
		pa.Add(p1);
		p3 = pa.Delete();

		cout << p3;
	}
	system("pause");
	
	return 1;
}
/*
class Part {
	int pid;
	char* pname;
public:
	Part() {
		pid = 0;
		pname = new char[4];
		strcpy(this->pname, "");
	}
	Part(int pid, char* pname) : pid(pid) {
		this->pname = new char[sizeof(pname) + 1];
		strcpy(this->pname, pname);
	}
	friend ostream& operator<<(ostream&, Part&);
	~Part() { delete[]pname; }
};
ostream& operator<<(ostream& os, Part& p) {
	os << "pid = " << p.pid << ", p = " << p.pname << endl;
	return os;
}
int main() {
	Part p1;
	cout << p1;

	Part p2(10, "good");
	p1 = p2;


	cout << p1;
	system("pause");

	return 1;
}

*/
/*
class Part {
	int pid;
	char pname[10];
public:

};

int main() {
	Part p1;
	cout << p1;

	Part p2(10, "good");
	p1 = p2;


	cout << p1;
	system("pause");

	return 1;
}
*/