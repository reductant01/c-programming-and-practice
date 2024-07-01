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
* 참조하여 구현
ostream& operator << (ostream& s, ColorRect cr) {
    //Rectangle인 것처럼 ColorRect을 출력
    s << (Rectangle)cr;

    //특정 데이터(color)를 출력
    s << "\tColor = " << cr.Color() << endl;
    return s;
}
*/

class Bag {
public:
    Bag(int MaxSize = DefaultSize); // 생성자
    ~Bag(); // 소멸자
    virtual void Add(Person&); // bag에 한 원소를 임의 장소에 삽입한다.
    virtual Person* Delete(); // bag으로부터 아무 원소를                                      // 삭제한다.
    // bag이 꽉 차면 TRUE를 return하고 그렇지 않으면 FALSE를 return한다.
    bool IsFull();
    // bag이 비었으면 TRUE를 return하고 그렇지 않으면 FALSE를 return한다.
    bool IsEmpty();
protected:
    Person* array;
    int MaxSize; // 배열의 크기
    int top; // 원소를 포함하고 있는 배열에서 가장 큰 index 위치
};
void Vag::Add(Person& p) {
    array[top++] = p;
}
class Stack : public Bag {
    static int count;
public:
    Stack(int MaxSize = DefaultSize); // 생성자
    ~Stack(); // 소멸자
    void Add(person&); // stack의 top에 원소를 추가한다.
    Person* Delete(String&); // stack의 top 원소를 삭제한다.
    static int GetCountCoder();
};
void Stack::Add(Person&)
Stack::Stack(int MaxStackSize) : Bag(MaxStackSize) { }
// Stack을 위한 생성자는 Bag을 위한 생성자를 호출한다.

Stack::~Stack() { }
// Bag을 위한 소멸자는 Stack 이 제거될 때 자동적으로 호출된다.
// 배열 array가 삭제되도록 해야 한다

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

    cout << "coder 숫자 = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCountWorkStudent() << endl;

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

    cout << "Coder 검색 결과 = " << tc->Search(cx);//pid, eid, lanuage가 같아야한다
    cout << "WorkStudent 검색 결과 = " << tws->Search(wsx);//pid, eid, sid가 같아야 한다 

    cout << "Coder 집합" << tc->show();//show()를 사용하여 출력
    cout << "WorkStudent 집합" << tws->show();//show()를 사용하여 출력

    cout << "Coder 집합2" << *tc;//operator<<()를 사용하여 출력
    cout << "WorkStudent 집합2" << *tws;//operator<<()를 사용하여 출력

    cout << "coder 숫자 = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCountWorkStudent() << endl;

    delete tc;
    delete tws;
    return 0;
}
