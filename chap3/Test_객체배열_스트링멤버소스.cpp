#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Student {
public:
    char* name;
    int age;
    char* city;
    //Student() {} //?
    Student(const char* name, int age, const char* city);
    void swap(Student* b);
    void showStudent();
    ~Student(); //?
    int compareStudents(const Student* b);
    void updateStudentCity(char* city);
};

void Student::updateStudentCity(char* city) {
    // 이전에 할당된 메모리 해제
    delete[] this->city;

    // 새로운 도시 정보를 저장할 메모리 할당
    this->city = new char[strlen(city) + 1];

    // 새로운 도시 정보를 복사
    strcpy(this->city, city);
}

int Student::compareStudents(const Student* b) {
    // 이 학생의 나이와 b 학생의 나이를 비교
    if (this->age < b->age)
        return -1;
    else if (this->age > b->age)
        return 1;
    else
        return 0;
}

void Student::showStudent() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
}

Student::Student(const char* name, int age, const char* city) {
    // name의 길이 구하기
    int nameLength = strlen(name) + 1; // NULL 문자 포함

    // city의 길이 구하기
    int cityLength = strlen(city) + 1; // NULL 문자 포함

    // name에 메모리 동적 할당 및 문자열 복사
    this->name = new char[nameLength];
    strcpy(this->name, name);

    // city에 메모리 동적 할당 및 문자열 복사
    this->city = new char[cityLength];
    strcpy(this->city, city);

    // 나이 설정
    this->age = age;
}

Student::~Student() {

}



void Student::swap(Student* b) {
    // 학생 객체 간에 포인터를 교환하여 객체의 위치를 변경
    Student temp = *this;
    *this = *b;
    *b = temp;
}

void showStudents(string message, Student* students[], int numStudents) {
    cout << message << endl;
    cout << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << (i + 1) << ":" << endl;
        students[i]->showStudent();
        cout << endl;
    }
    cout << endl;
}

void selectionSortStudents(Student* students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numStudents; ++j) {
            if (students[j]->compareStudents(students[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            students[i]->swap(students[minIndex]);
        }
    }
}

int main() {
    int numStudents = 5;

    Student* student1 = new Student("e", 25, "Changwon");
    Student* student2 = new Student("c", 22, "Daegu");
    Student* student3 = new Student("d", 24, "Seoul");
    Student* student4 = new Student("b", 21, "Ulsan");
    Student* student5 = new Student("a", 20, "Jinju");

    Student* students[5] = { student1, student2, student3, student4, student5 };

    showStudents("---Before Sort---", students, numStudents);
    
    student1->updateStudentCity("Busan");
    cout << "---After Update---\n\n";
    student1->showStudent();
    cout << endl;

    selectionSortStudents(students, numStudents);
    showStudents("---After Sort---", students, numStudents);

    system("pause");
    return 0;
}
