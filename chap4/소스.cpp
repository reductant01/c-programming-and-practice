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
    ~Student(); // Destructor �߰�
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

void showStudents(string message, const Student* students[], int numStudents) {
    //void showStudent();�� ����� ��ü ���
    cout << message << ": " << endl;
    for (int i = 0; i < numStudents; ++i) {
        students[i]->showStudent(); // �� �л� ��ü�� ���� ���
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
    int numStudents = 5;
    Student student1("Hong Gildong", 23, "houston");
    Student student2("hello", 22, "newyork");
    Student student3("houston", 13, "houston");
    Student student4("hong", 19, "busan");
    Student student5("kim", 33, "jeju");
    Student* students[5] = { &student1,&student2,&student3,&student4 ,&student5 };
    // �� �л� ���� ���
    showStudents("Before Sort:", students, numStudents);

    student1.updateStudentCity("Busan");
    student1.showStudent();
    
    selectionSortStudents(students, numStudents);
    showStudents("After Sort", students, numStudents);

    system("pause");
    return 0;
}