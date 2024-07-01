#include <iostream>
using namespace std;
class Student {
	//char name[20];
	char* name;
	int year;
	string dept;
public:
	Student(char *sname, int syear, char* sdept)// : name(name),syear(year),dept(dept){
	{
		name = new char[sizeof(sname)];
		strcpy(name, sname); 
		dept = string(sdept);
		//strcpy(dept, sdept);
		year = syear;
	}
	void show() {
		cout << "name = " << name << ", year = " << year << ", dept = " << dept << endl;
	}
	~Student() {
		delete[]name;
	}
};
int main() {
	Student* list[3];
	char sname[20];
	//char* sname;
	int syear;
	char dept[20];
	for (int i = 0; i < 3; i++) {
		cin >> sname >> syear >> dept;
		list[i] = new Student(sname, syear, dept);
	}
	for (int i = 0; i < 3; i++) {

		list[i]->show();
		
	}
	system("pause");
	return 1;
}