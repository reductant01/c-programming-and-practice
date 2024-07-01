#include <iostream>
using namespace std;
class Person {
	string name;
public:
	Person(string name) : name(name) {}
};
class Student : public Person{
	string sid;
public:
	Student(string name, string sid) : Person(name), sid(sid) {}
	//Student(const Student& other) : Person(other), sid(other.sid) {}

};
void swap(Person *data[], int i, int j) {
	Person* temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
int main() {
	Person *arr[10];
	arr[0] = new Student("hong", "s001");
	arr[1] = new Student("kim", "s001");
	int i = 0, j = 1;
	swap(arr, i, j);
	return 1;