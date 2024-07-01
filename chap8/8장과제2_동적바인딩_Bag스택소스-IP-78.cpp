#include <iostream>
#include <string>

using namespace std;
const int N = 20;


class Dept {
    string dname;
    string city;
    friend ostream& operator<<(ostream&, Dept&);
public:
    void show() {
        std::cout << "Dept" << *this;
    }
};
ostream& operator<<(ostream& os, Dept& dept) {
    os << "Department Name: " << dept.dname << ", City: " << dept.city;
    return os;
}
class Person {
private:
    string pid;
    string pname;
    friend ostream& operator<<(ostream&, Person&);
public:
    virtual void show() {
        std::cout << *this;
    }


};
class Employee : protected Person {
private:
    string eid;
    Dept* dept;
    friend ostream& operator<<(ostream&, Employee&);
public:
    void show();


};
class Student : private Person {
private:
    string sid;
    Dept* dept;
    friend ostream& operator<<(ostream&, Student&);
public:
    void show();

};
class Coder : private Employee {
private:
    string language;
    double workYears;
public:
    void show();

    int operator > (Coder&);//
    Coder(string language, double workYears, string eno, string dept, string city, string pid, string pname);
    friend ostream& operator<<(ostream&, Coder&);

};
class WorkStudent : private Employee, private Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, WorkStudent&);
public:
    void show();

};
/*
* �����Ͽ� ����
ostream& operator << (ostream& s, ColorRect cr) {
    //Rectangle�� ��ó�� ColorRect�� ���
    s << (Rectangle)cr;

    //Ư�� ������(color)�� ���
    s << "\tColor = " << cr.Color() << endl;
    return s;
}
*/

class Bag {
public:
    Bag(int MaxSize = DefaultSize); // ������
    ~Bag(); // �Ҹ���
    virtual void Add(Person&); // bag�� �� ���Ҹ� ���� ��ҿ� �����Ѵ�.
    virtual Person* Delete(); // bag���κ��� �ƹ� ���Ҹ�                                      // �����Ѵ�.
    // bag�� �� ���� TRUE�� return�ϰ� �׷��� ������ FALSE�� return�Ѵ�.
    bool IsFull();
    // bag�� ������� TRUE�� return�ϰ� �׷��� ������ FALSE�� return�Ѵ�.
    bool IsEmpty();
protected:
    Person* array;
    int MaxSize; // �迭�� ũ��
    int top; // ���Ҹ� �����ϰ� �ִ� �迭���� ���� ū index ��ġ
};
void Vag::Add(Person& p) {
    array[top++] = p;
}
class Stack : public Bag {
    static int count;
public:
    Stack(int MaxSize = DefaultSize); // ������
    ~Stack(); // �Ҹ���
    void Add(person&); // stack�� top�� ���Ҹ� �߰��Ѵ�.
    Person* Delete(String&); // stack�� top ���Ҹ� �����Ѵ�.
    static int GetCountCoder();
};
void Stack::Add(Person&)
Stack::Stack(int MaxStackSize) : Bag(MaxStackSize) { }
// Stack�� ���� �����ڴ� Bag�� ���� �����ڸ� ȣ���Ѵ�.

Stack::~Stack() { }
// Bag�� ���� �Ҹ��ڴ� Stack �� ���ŵ� �� �ڵ������� ȣ��ȴ�.
// �迭 array�� �����ǵ��� �ؾ� �Ѵ�

int* Stack::Delete(int& x) {
    if (IsEmpty()) { Empty(); return 0; }
    x = array[top--];
    return &x;
}
void ShowAll(Person* p[], int nSteps) {

}

int main() {
    Dept cpp("C++", "Busan"); Dept c("C", "Masan"); Dept java("Java", "Jeju");

    Stack* st = new Stack(N);

    cout << "coder ���� = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents ���� = " << TableWorkStudent::GetCountWorkStudent() << endl;

    Coder coderSet[N] = {};
    WorkStudent workerSet[N] = {};
    Person* peopleSet[N];
    peopleSet[0] = new Person("P001", "Alice");
    peopleSet[1] = new Employee("E001", "P002", "Bob", &cpp);
    peopleSet[2] = new Student("S001", "P003", "Charlie", &c);
    peopleSet[3] = new Coder("C++", 5.5, "E002", "P004", "David", &cpp);
    peopleSet[4] = new WorkStudent(1500, 3.8, "E003", "P005", "Emily", &java);
    ShowAll(peopleSet, N);
    for ()
    {
        st->Add(coderSet[i]);
    }

    Coder* cx = new Coder("C++", 5.5, "E002", "P004", "David", &cpp);
    WorkStudent* wsx = new WorkStudent(1500, 3.8, "E003", "P005", "Emily", &java);

    cout << "Coder �˻� ��� = " << tc->Search(cx);//pid, eid, lanuage�� ���ƾ��Ѵ�
    cout << "WorkStudent �˻� ��� = " << tws->Search(wsx);//pid, eid, sid�� ���ƾ� �Ѵ� 

    cout << "Coder ����" << tc->show();//show()�� ����Ͽ� ���
    cout << "WorkStudent ����" << tws->show();//show()�� ����Ͽ� ���

    cout << "Coder ����2" << *tc;//operator<<()�� ����Ͽ� ���
    cout << "WorkStudent ����2" << *tws;//operator<<()�� ����Ͽ� ���

    cout << "coder ���� = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents ���� = " << TableWorkStudent::GetCountWorkStudent() << endl;

    delete tc;
    delete tws;
    return 0;
}
