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
    // ������ �Ҵ�� �޸� ����
    delete[] this->city;

    // ���ο� ���� ������ ������ �޸� �Ҵ�
    this->city = new char[strlen(city) + 1];

    // ���ο� ���� ������ ����
    strcpy(this->city, city);
}

int Student::compareStudents(const Student* b) {
    // �� �л��� ���̿� b �л��� ���̸� ��
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
    // name�� ���� ���ϱ�
    int nameLength = strlen(name) + 1; // NULL ���� ����

    // city�� ���� ���ϱ�
    int cityLength = strlen(city) + 1; // NULL ���� ����

    // name�� �޸� ���� �Ҵ� �� ���ڿ� ����
    this->name = new char[nameLength];
    strcpy(this->name, name);

    // city�� �޸� ���� �Ҵ� �� ���ڿ� ����
    this->city = new char[cityLength];
    strcpy(this->city, city);

    // ���� ����
    this->age = age;
}

Student::~Student() {

}



void Student::swap(Student* b) {
    // �л� ��ü ���� �����͸� ��ȯ�Ͽ� ��ü�� ��ġ�� ����
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
