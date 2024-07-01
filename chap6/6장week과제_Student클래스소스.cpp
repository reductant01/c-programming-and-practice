/*
* 6장 week과제1
* 5장 과제에 함수 오버로딩 + operator overloading을 추가로 구현하는 실습으로 진행 > 반복 숙달 훈련이 필요
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
	Student& operator=(Student& other);//deep copy로 구현,swap에서만 호출
public:
	Student() {}
	Student(const char* name, int age, const char* city);
	Student(Student&);
	void showStudent() const;
	~Student();
	void swap(Student* b);//operator=()를 사용하여 구현
	int operator >(const Student* b);//name 올림차순으로 정렬하는 데 사용
	void updateStudentCity(const char* city);
	static int GetCount();

	// Getter 함수들
	const char* getName() const { return name; }
	int getAge() const { return age; }
	const char* getCity() const { return city; }
};

int Student::count = 0;

// Constructor 구현
Student& Student::operator=(Student& other) {
	// 이름 교환
	char* tempName = name;
	name = other.name;
	other.name = tempName;

	// 나이 교환
	int tempAge = age;
	age = other.age;
	other.age = tempAge;

	// 도시 교환
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
	// 이름(name) 복사
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	// 나이(age) 설정
	this->age = age;

	// 도시(city) 복사
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);

	// 객체 생성 시 count 증가
	count++;
}

Student::Student(Student& s) { // 복사 생성자
	// 이름(name) 복사
	name = new char[strlen(s.name) + 1];
	strcpy(name, s.name);

	// 나이(age) 설정
	age = s.age;

	// 도시(city) 복사
	city = new char[strlen(s.city) + 1];
	strcpy(city, s.city);

	// 객체 생성 시 count 증가
	count++;
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


void Student::updateStudentCity(const char* city) {
	// 기존 도시 정보를 해제하고 새로운 도시 정보 할당 및 복사
	delete[] this->city;
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
}

void Student::showStudent() const {
	printf("[%s, %d, %s]\n\n", name, age, city);
}


void showStudents(string message, Student* students[], int numStudents) {
	//void showStudent();를 사용한 객체 출력
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
	//operator=()를 사용하여 맞교환
	(*this) = *b;
}

void selectionSortStudents(Student* students[], int numStudents) {
	for (int i = 0; i < numStudents - 1; ++i) {
		int minIndex = i; // 최솟값의 인덱스를 저장하는 변수
		for (int j = i + 1; j < numStudents; ++j) {
			// 현재 최솟값보다 작은 학생을 찾으면 최솟값의 인덱스를 업데이트
			if (students[minIndex] > students[j]) {
				minIndex = j;
			}
		}
		// 최솟값을 현재 위치로 이동
		if (minIndex != i) {
			students[i]->swap(students[minIndex]);
		}
	}
}

void selectionSortStudents(Student* students, int numStudents) {
	//구현해야함
}

void showStudents2(string message, const Student* students, int numStudents) {
	//void showStudent();를 사용한 객체 출력
	cout << message << ": " << endl;
	// 각 학생 객체의 정보 출력
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
	// 학생 객체 초기화
	Student student1("hong", 23, "houston");
	Student student2("park", 22, "newyork");
	Student student3("houston", 13, "houston");
	Student student4("lee", 19, "busan");
	Student student5("kim", 33, "jeju");
	Student student6;
	Student student7(student1);

	Student* students[] = { &student1,&student2,&student3,&student4,&student5,&student6,&student7 };
	int numStudents = sizeof(students) / sizeof(students[0]);

	showStudents("정렬전:", students, numStudents);
	student1.updateStudentCity("Busan");
	student1.showStudent();
	selectionSortStudents(students, numStudents);
	showStudents("정렬후", students, numStudents);
	//수정이 필요하다 
	{
		Student* sset[] = { //소멸자가 호출된다
		 &Student("홍길동", 20, "New York"),
		 &Student("Alice", 22, "Los Angeles"),
		 &Student("Bob", 21, "Chicago"),
		 &Student("Emily", 19, "San Francisco"),
		 &Student("Michael", 23, "Seattle")
		};
		cout << "the number of objects = " << Student::GetCount() << endl;
		int numsset = sizeof(sset) / sizeof(sset[0]);

		showStudents("sset[] 정렬전:", sset, numsset);
		selectionSortStudents(sset, numStudents);
		showStudents("sset[] 정렬후:", sset, numsset);
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
	showStudents2("sset2[] 정렬전:", sset2, numsset2);
	selectionSortStudents(sset2, numStudents);
	showStudents2("sset2[] 정렬후:", sset2, numsset2);

	system("pause");
	return 0;
}
