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
	// city 정보를 할당하기 전에 이전에 동적으로 할당된 city 메모리를 해제합니다.
	delete[] this->city;

	// city 정보의 길이를 구합니다.
	int length = strlen(city) + 1;

	// city 정보를 저장할 새로운 메모리를 할당합니다.
	this->city = new char[length];

	// city 정보를 복사합니다.
	strcpy(this->city, city);
}

int Student::compareStudents(const Student* b) {
	return strcmp(this->name, b->name);
}

void Student::showStudent() const {
	printf("[%s, %d, %s]\n", name, age, city);
}

// Constructor 구현
Student::Student(const char* name, int age, const char* city) {
	// 이름 정보 할당
	int nameLength = strlen(name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, name);

	// 나이 정보 할당
	this->age = age;

	// 도시 정보 할당
	int cityLength = strlen(city) + 1;
	this->city = new char[cityLength];
	strcpy(this->city, city);
}

Student::Student(Student& s) { // 복사 생성자
	// 이름 복사
	int nameLength = strlen(s.name) + 1;
	this->name = new char[nameLength];
	strcpy(this->name, s.name);

	// 나이 복사
	this->age = s.age;

	// 도시 복사
	int cityLength = strlen(s.city) + 1;
	this->city = new char[cityLength];
	strcpy(this->city, s.city);
}


// Destructor 구현
Student::~Student() {
	cout << "소멸자 호출" << endl;

	if (name != nullptr) {
		free(name);
	}
	if (city != nullptr) {
		free(city);
	}
}

void Student::swap(Student* b) {
	// 이름 교환
	char* tempName = this->name;
	this->name = b->name;
	b->name = tempName;

	// 나이 교환
	int tempAge = this->age;
	this->age = b->age;
	b->age = tempAge;

	// 도시 교환
	char* tempCity = this->city;
	this->city = b->city;
	b->city = tempCity;
}


void showStudents(string message, Student* students[], int numStudents) {
	//void showStudent();를 사용한 객체 출력
	cout << message << ":: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		students[i]->showStudent();
	}
	cout << endl;
}

void showStudents2(string message, const Student* students, int numStudents) {
	//void showStudent();를 사용한 객체 출력
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
			// 학생 이름을 비교하여 정렬합니다.
			if (students[j]->compareStudents(students[minIndex]) < 0) {
				minIndex = j;
			}
		}
		// 현재 인덱스와 최소값을 교환합니다.
		if (minIndex != i) {
			students[i]->swap(students[minIndex]);
		}
	}
}

int main() {
	// 학생 객체 초기화
	Student student1("hong", 23, "houston");
	Student student2("park", 22, "newyork");
	Student student3("houston", 13, "houston");
	Student student4("lee", 19, "busan");
	Student student5("kim", 33, "jeju");

	Student* students[] = { &student1,&student2,&student3,&student4 ,&student5 };
	int numStudents = sizeof(students) / sizeof(students[0]);

	showStudents("정렬전 ", students, 5);
	student1.updateStudentCity("Busan");
	showStudents("변경후 ", students, 1);
	//student1.showStudent();
	selectionSortStudents(students, numStudents);
	showStudents("정렬후 ", students, numStudents);
	
	//수정이 필요하다 
	Student* sset[] = { //소멸자가 호출된다
	 new Student("홍길동", 20, "New York"),
	 new Student("Alice", 22, "Los Angeles"),
	 new Student("Bob", 21, "Chicago"),
	 new Student("Emily", 19, "San Francisco"),
	 new Student("Michael", 23, "Seattle")
	};

	int numsset = sizeof(sset) / sizeof(sset[0]);

	showStudents("sset[] 정렬전 ", sset, numsset);
	selectionSortStudents(sset, numStudents);
	showStudents("sset[] 정렬후 ", sset, numsset);

	Student sset2[] = {
		   {"kim John", 20, "New York"},
		   {"lee Alice", 22, "Los Angeles"},
		   {"hong Bob", 21, "Chicago"},
		   {"park Emily", 19, "San Francisco"},
		   {"choi Michael", 23, "Seattle"}
	};
	int numsset2 = sizeof(sset2) / sizeof(sset2[0]);
	
	showStudents2("sset2[] 정렬전 ", sset2, numsset2);
	selectionSortStudents(sset, numStudents);
	showStudents2("sset2[] 정렬후 ", sset2, numsset2);

	system("pause");
	return 0;
}
