#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
using namespace std;

class Student {
public:
	char* name;
	int age;
	char* city;
	// Student() {}
	Student(const char* name, int age, const char* city);
	Student(Student&);
	void swap(Student* b);
	void showStudent() const;
	~Student();
	int compareStudents(const Student* b);
	void updateStudentCity(const char* city);
};

void Student::updateStudentCity(const char* city) {
	// city ������ �Ҵ��ϱ� ���� ������ �������� �Ҵ�� city �޸𸮸� �����մϴ�.
	delete[] this->city;

	// city ������ ���̸� ���մϴ�.
	int length = strlen(city) + 1;

	// city ������ ������ ���ο� �޸𸮸� �Ҵ��մϴ�.
	this->city = new char[length];

	// city ������ �����մϴ�.
	strcpy(this->city, city);
}

int Student::compareStudents(const Student* b) {
	return strcmp(this->name, b->name);
}

void Student::showStudent() const {
	printf("[%s, %d, %s]\n", name, age, city);
}

// Constructor ����
Student::Student(const char* name, int age, const char* city) {
	// �̸� ���� �Ҵ�
	int nameLength = strlen(name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, name);

	// ���� ���� �Ҵ�
	this->age = age;

	// ���� ���� �Ҵ�
	int cityLength = strlen(city) + 1;
	this->city = new char[cityLength];
	strcpy(this->city, city);
}

Student::Student(Student& s) { // ���� ������
	// �̸� ����
	int nameLength = strlen(s.name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, s.name);

	// ���� ����
	this->age = s.age;

	// ���� ����
	int cityLength = strlen(s.city) + 1;
	this->city = new char[cityLength];
	strcpy(this->city, s.city);
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

void Student::swap(Student* b) {
	// �̸� ��ȯ
	char* tempName = this->name;
	this->name = b->name;
	b->name = tempName;

	// ���� ��ȯ
	int tempAge = this->age;
	this->age = b->age;
	b->age = tempAge;

	// ���� ��ȯ
	char* tempCity = this->city;
	this->city = b->city;
	b->city = tempCity;
}


void showStudents(string message, Student* students[], int numStudents) {
	//void showStudent();�� ����� ��ü ���
	cout << message << ":: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		students[i]->showStudent();
	}
	cout << endl;
}

void showStudents2(string message, const Student* students, int numStudents) {
	//void showStudent();�� ����� ��ü ���
	cout << message << ":: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		students[i].showStudent();
	}
	cout << endl;
}

void selectionSortStudents(Student* students[], int numStudents) {
	for (int i = 0; i < numStudents - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < numStudents; ++j) {
			// �л� �̸��� ���Ͽ� �����մϴ�.
			if (students[j]->compareStudents(students[minIndex]) < 0) {
				minIndex = j;
			}
		}
		// ���� �ε����� �ּҰ��� ��ȯ�մϴ�.
		if (minIndex != i) {
			students[i]->swap(students[minIndex]);
		}
	}
}

int main() {
	// �л� ��ü �ʱ�ȭ
	Student student1("hong", 23, "houston");
	Student student2("park", 22, "newyork");
	Student student3("houston", 13, "houston");
	Student student4("lee", 19, "busan");
	Student student5("kim", 33, "jeju");

	Student* students[] = { &student1,&student2,&student3,&student4 ,&student5 };
	int numStudents = sizeof(students) / sizeof(students[0]);

	showStudents("������ ", students, 5);
	student1.updateStudentCity("Busan");
	showStudents("������ ", students, 1);
	//student1.showStudent();
	selectionSortStudents(students, numStudents);
	showStudents("������ ", students, numStudents);
	
	//������ �ʿ��ϴ� 
	Student* sset[] = { //�Ҹ��ڰ� ȣ��ȴ�
	 new Student("ȫ�浿", 20, "New York"),
	 new Student("Alice", 22, "Los Angeles"),
	 new Student("Bob", 21, "Chicago"),
	 new Student("Emily", 19, "San Francisco"),
	 new Student("Michael", 23, "Seattle")
	};

	int numsset = sizeof(sset) / sizeof(sset[0]);

	showStudents("sset[] ������ ", sset, numsset);
	selectionSortStudents(sset, numStudents);
	showStudents("sset[] ������ ", sset, numsset);

	Student sset2[] = {
		   {"kim John", 20, "New York"},
		   {"lee Alice", 22, "Los Angeles"},
		   {"hong Bob", 21, "Chicago"},
		   {"park Emily", 19, "San Francisco"},
		   {"choi Michael", 23, "Seattle"}
	};
	int numsset2 = sizeof(sset2) / sizeof(sset2[0]);
	
	showStudents2("sset2[] ������ ", sset2, numsset2);
	selectionSortStudents(sset, numStudents);
	showStudents2("sset2[] ������ ", sset2, numsset2);

	system("pause");
	return 0;
}
