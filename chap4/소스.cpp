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
    //Student() {}
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent() const;
    ~Student(); // Destructor 추가
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

void showStudents(string message, const Student* students[], int numStudents) {
    //void showStudent();를 사용한 객체 출력
    cout << message << ": " << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i]->showStudent(); // 각 학생 객체의 정보 출력
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
    int numStudents = 5;
    Student student1("Hong Gildong", 23, "houston");
    Student student2("hello", 22, "newyork");
    Student student3("houston", 13, "houston");
    Student student4("hong", 19, "busan");
    Student student5("kim", 33, "jeju");
    Student* students[5] = { &student1,&student2,&student3,&student4 ,&student5 };
    // 각 학생 정보 출력
    showStudents("Before Sort:", students, numStudents);

    student1.updateStudentCity("Busan");
    student1.showStudent();
    
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);

    system("pause");
    return 0;
}