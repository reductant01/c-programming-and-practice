//4-1. STREAM_IN_OUT.cpp  4.1 ���� scope�� ǥ�� �����
#include <iostream>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& stream, const Person& p);
private:
    int idNum;
    int age;
    //23.3.23 �߰��� �ڵ�
    char* name;//�̸� field�� �߰���
    char* address;
    char dept[20];

public:
    Person() { idNum = 0; age = 0; name = nullptr; address = nullptr; }
    Person(int, int, char*, char*, char*);
    ~Person();
};

void main() {
    Person p(941111, 20, "hong", "Busan", "CPP");
    cout << "����" << p << "�Դϴ�." << endl << endl; 

    Person s(981212, 30, "kim", "Masan", "Java");
    cout << "����" << s << "�Դϴ�." << endl << endl;
    system("pause");
}