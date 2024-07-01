/*
* 6�� week����1
* 5�� ������ �Լ� �����ε� + operator overloading�� �߰��� �����ϴ� �ǽ����� ���� > �ݺ� ���� �Ʒ��� �ʿ�
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
	char* name;
	int age;
	char* city;
	static int count;
	Student& operator=(Student& other);//deep copy�� ����,swap������ ȣ��
public:
	Student() {}
	Student(const char* name, int age, const char* city);
	Student(Student&);
	void showStudent() const;
	~Student();
	void swap(Student* b);//operator=()�� ����Ͽ� ����
	int operator >(const Student* b);//name �ø��������� �����ϴ� �� ���
	void updateStudentCity(const char* city);
	static int GetCount();

	// Getter �Լ���
	const char* getName() const { return name; }
	int getAge() const { return age; }
	const char* getCity() const { return city; }
};

int Student::count = 0;

// Constructor ����
Student& Student::operator=(Student& other) {
	// �̸� ��ȯ
	char* tempName = name;
	name = other.name;
	other.name = tempName;

	// ���� ��ȯ
	int tempAge = age;
	age = other.age;
	other.age = tempAge;

	// ���� ��ȯ
	char* tempCity = city;
	city = other.city;
	other.city = tempCity;

	return *this;
}


int Student::operator >(const Student* b) {
	return strcmp(this->getName(), b->getName());
}


Student::Student() {
	count++;
}

Student::Student(const char* name, int age, const char* city) {
	// �̸�(name) ����
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	// ����(age) ����
	this->age = age;

	// ����(city) ����
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);

	// ��ü ���� �� count ����
	count++;
}

Student::Student(Student& s) { // ���� ������
	// �̸�(name) ����
	name = new char[strlen(s.name) + 1];
	strcpy(name, s.name);

	// ����(age) ����
	age = s.age;

	// ����(city) ����
	city = new char[strlen(s.city) + 1];
	strcpy(city, s.city);

	// ��ü ���� �� count ����
	count++;
}


// Destructor ����
Student::~Student() {
	cout << "�Ҹ��� ȣ��" << endl;

	if (name != nullptr) {
		free(name);
	}
	if (city != nullptr) {
		free(city);
	}
}


void Student::updateStudentCity(const char* city) {
	// ���� ���� ������ �����ϰ� ���ο� ���� ���� �Ҵ� �� ����
	delete[] this->city;
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
}

void Student::showStudent() const {
	printf("[%s, %d, %s]\n\n", name, age, city);
}


void showStudents(string message, Student* students[], int numStudents) {
	//void showStudent();�� ����� ��ü ���
	cout << message << ": " << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Student " << i + 1 << ":" << endl;
		cout << "Name: " << students[i]->getName() << endl;
		cout << "Age: " << students[i]->getAge() << endl;
		cout << "City: " << students[i]->getCity() << endl;
		cout << endl;
	}
	cout << endl;
}

void Student::swap(Student* b) {
	//operator=()�� ����Ͽ� �±�ȯ
	(*this) = *b;
}

void selectionSortStudents(Student* students[], int numStudents) {
	for (int i = 0; i < numStudents - 1; ++i) {
		int minIndex = i; // �ּڰ��� �ε����� �����ϴ� ����
		for (int j = i + 1; j < numStudents; ++j) {
			// ���� �ּڰ����� ���� �л��� ã���� �ּڰ��� �ε����� ������Ʈ
			if (students[minIndex] > students[j]) {
				minIndex = j;
			}
		}
		// �ּڰ��� ���� ��ġ�� �̵�
		if (minIndex != i) {
			students[i]->swap(students[minIndex]);
		}
	}
}

void selectionSortStudents(Student* students, int numStudents) {
	//�����ؾ���
}

void showStudents2(string message, const Student* students, int numStudents) {
	//void showStudent();�� ����� ��ü ���
	cout << message << ": " << endl;
	// �� �л� ��ü�� ���� ���
	for (int i = 0; i < numStudents; ++i) {
		cout << "Student " << i + 1 << ":" << endl;
		cout << "Name: " << students[i].getName() << endl;
		cout << "Age: " << students[i].getAge() << endl;
		cout << "City: " << students[i].getCity() << endl;
		cout << endl;
	}
	cout << endl;
}

int Student::GetCount() {
	cout << count << endl;
}


int main() {
	// �л� ��ü �ʱ�ȭ
	Student student1("hong", 23, "houston");
	Student student2("park", 22, "newyork");
	Student student3("houston", 13, "houston");
	Student student4("lee", 19, "busan");
	Student student5("kim", 33, "jeju");
	Student student6;
	Student student7(student1);

	Student* students[] = { &student1,&student2,&student3,&student4,&student5,&student6,&student7 };
	int numStudents = sizeof(students) / sizeof(students[0]);

	showStudents("������:", students, numStudents);
	student1.updateStudentCity("Busan");
	student1.showStudent();
	selectionSortStudents(students, numStudents);
	showStudents("������", students, numStudents);
	//������ �ʿ��ϴ� 
	{
		Student* sset[] = { //�Ҹ��ڰ� ȣ��ȴ�
		 &Student("ȫ�浿", 20, "New York"),
		 &Student("Alice", 22, "Los Angeles"),
		 &Student("Bob", 21, "Chicago"),
		 &Student("Emily", 19, "San Francisco"),
		 &Student("Michael", 23, "Seattle")
		};
		cout << "the number of objects = " << Student::GetCount() << endl;
		int numsset = sizeof(sset) / sizeof(sset[0]);

		showStudents("sset[] ������:", sset, numsset);
		selectionSortStudents(sset, numStudents);
		showStudents("sset[] ������:", sset, numsset);
	}
	cout << "the number of objects = " << Student::GetCount() << endl;
	Student sset2[] = {
		   {"kim John", 20, "New York"},
		   {"lee Alice", 22, "Los Angeles"},
		   {"hong Bob", 21, "Chicago"},
		   {"park Emily", 19, "San Francisco"},
		   {"choi Michael", 23, "Seattle"}
	};
	int numsset2 = sizeof(sset2) / sizeof(sset2[0]);
	showStudents2("sset2[] ������:", sset2, numsset2);
	selectionSortStudents(sset2, numStudents);
	showStudents2("sset2[] ������:", sset2, numsset2);

	system("pause");
	return 0;
}
