#include <iostream>
#include <string>

using namespace std;
const int N = 20;

class Dept {
    string dname;
    string city;
    friend ostream& operator<<(ostream&, Dept&);
public:
    Dept(string dname = "", string city = "") : dname(dname), city(city) {}
    virtual void show() {
        std::cout << *this << endl;
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
    Person(string pid = "", string pname = "") : pid(pid), pname(pname) {}
    virtual void show() {
        std::cout << *this << endl;
    }
    bool operator==(const Person*) const;
};
ostream& operator<<(ostream& os, Person& person) {
    os << "Person ID: " << person.pid << ", Person Name: " << person.pname;
    return os;
}
bool Person::operator==(const Person* other) const {
    return pid == other->pid && pname == other->pname;
}

class Employee : public virtual Person {
private:
    string eid;
    Dept* dept;
    friend ostream& operator<<(ostream&, Employee&);
public:
    Employee(string eid = "", string pid = "", string pname = "", Dept* dept = nullptr)
        : eid(eid), Person(pid, pname), dept(dept) {}
    void show() {
        std::cout << *this << endl;
    }
};
ostream& operator<<(ostream& os, Employee& employee) {
    employee.Person::show();
    os << ", Employee ID: " << employee.eid;
    if (employee.dept != nullptr) {
        os << ", " << *employee.dept;
    }
    return os;
}

class Student : public virtual Person {
private:
    string sid;
    Dept* dept;
    friend ostream& operator<<(ostream&, Student&);
public:
    Student(string sid = "", string pid = "", string pname = "", Dept* dept = nullptr)
        : sid(sid), Person(pid, pname), dept(dept) {}
    void show() {
        std::cout << *this << endl;
    };
};
ostream& operator<<(ostream& os, Student& student) {
    student.Person::show();
    os << ", Student ID: " << student.sid;
    if (student.dept != nullptr) {
        os << ", " << *student.dept;
    }
    return os;
}

class Coder : public Employee {
private:
    string language;
    double workYears;
public:
    void show() {
        std::cout << *this << endl;
    };
    int operator > (Coder& other) {
        return this->workYears > other.workYears;
    }
    Coder(string language = "", double workYears = 0.0, string eid = "", string pid = "", string pname = "", Dept* dept = nullptr)
        : Employee(eid, pid, pname, dept), language(language), workYears(workYears) {}
    friend ostream& operator<<(ostream&, Coder&);
};
ostream& operator<<(ostream& os, Coder& coder) {
    coder.Employee::show();
    os << ", Language: " << coder.language << ", Work Years: " << coder.workYears;
    return os;
}

class WorkStudent : public Employee, public Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, WorkStudent&);
public:
    WorkStudent(double salary = 0.0, double grade = 0.0, string eid = "", string pid = "", string pname = "", Dept* dept = nullptr)
        : Employee(eid, pid, pname, dept), Student("", pid, pname, dept), salary(salary), grade(grade) {}
    void show() {
        std::cout << *this << endl;
    }
};
ostream& operator<<(ostream& os, WorkStudent& ws) {
    ws.Employee::show();
    ws.Student::show();
    os << ", Salary: " << ws.salary << ", Grade: " << ws.grade;
    return os;
}

class TableObjects {
private:
    Person* table[N];
    int top; // 입력된 갯수
public:
    TableObjects() : top(0) {
        for (int i = 0; i < N; ++i) {
            table[i] = nullptr;
        }
    }
    virtual void show() const {
        // table 전체를 출력한다
        std::cout << *this << endl;
    }
    virtual void Add(const Person& st) {
        if (top < N) {
            table[top++] = new Person(st);
        }
        else {
            cout << "Table is full. Cannot add more elements." << endl;
        }
    }
    virtual bool Search(const Person* st) const {
        // operator==() 사용해야 한다 - 테이블에 주어진 객체가 있는지를 찾는다
        for (int i = 0; i < top; ++i) {
            if (*table[i] == st) {
                return true;
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& stream, const TableObjects& ts);
    virtual ~TableObjects() {
        for (int i = 0; i < top; ++i) {
            delete table[i];
        }
    }
};
ostream& operator<<(ostream& stream, const TableObjects& ts) {
    for (int i = 0; i < ts.top; ++i) {
        stream << *ts.table[i] << endl;
    }
    return stream;
}

class TableCoder : public TableObjects {
    static int countCoder;
public:
    TableCoder() {}
    void show() const {
        std::cout << *this << endl;
    }
    void Add(const Person& st) {
        // 테이블에 추가한다
        TableObjects::Add(st);
        ++countCoder;
    }
    bool Search(const Person* st) const {
        // operator==() 사용해야 한다 - 테이블에 주어진 객체가 있는지를 찾는다
        return TableObjects::Search(st);
    }
    friend ostream& operator<<(ostream& stream, const TableCoder& ts);
    static int GetCountCoder() {
        return countCoder;
    }
};
int TableCoder::countCoder = 0;

ostream& operator<<(ostream& stream, const TableCoder& ts) {
    ts.TableObjects::show();
    stream << ", Number of Coders: " << ts.countCoder;
    return stream;
}

class TableWorkStudent : public TableObjects {
    static int countWorkStudent;
public:
    TableWorkStudent() {}
    void show() const {
        std::cout << *this << endl;
    }
    void Add(const Person& st) {
        // 테이블에 추가한다
        TableObjects::Add(st);
        ++countWorkStudent;
    }
    bool Search(const Person* st) const {
        // operator==() 사용해야 한다 - 테이블에 주어진 객체가 있는지를 찾는다
        return TableObjects::Search(st);
    }
    friend ostream& operator<<(ostream& stream, const TableWorkStudent& ts);
    static int GetCountWorkStudent() {
        return countWorkStudent;
    }
};
int TableWorkStudent::countWorkStudent = 0;

ostream& operator<<(ostream& stream, const TableWorkStudent& ts) {
    // 테이블 모양으로 출력한다
    ts.TableObjects::show();
    stream << ", Number of WorkStudents: " << ts.countWorkStudent;
    return stream;
}

void ShowAll(Person* p[], int nSteps) {
    for (int i = 0; i < nSteps; ++i) {
        if (p[i] != nullptr) {
            p[i]->show();
            cout << endl;
        }
    }
}

class Bag {
public:
    Bag(int MaxSize); // 생성자
    ~Bag(); // 소멸자
    virtual void Add(Person&); // bag에 한 원소를 임의 장소에 삽입한다.
    virtual Person* Delete(); // bag으로부터 아무 원소를 삭제한다.
    bool IsFull() {
        // bag이 꽉 차면 TRUE를 return하고 그렇지 않으면 FALSE를 return한다.
        return top >= MaxSize;
    }
    bool IsEmpty() {
        // bag이 비었으면 TRUE를 return하고 그렇지 않으면 FALSE를 return한다.
        return top == 0;
    }
protected:
    Person* array;
    int MaxSize; // 배열의 크기
    int top; // 원소를 포함하고 있는 배열에서 가장 큰 index 위치
};
Bag::Bag(int MaxSize) : MaxSize(MaxSize), top(0) {
    array = new Person[MaxSize];
}
Bag::~Bag() {
    delete[] array;
}
void Bag::Add(Person& p) {
    if (!IsFull()) {
        array[top++] = p;
    }
    else {
        std::cout << "Bag is full. Cannot add more elements." << std::endl;
    }
}
Person* Bag::Delete() {
    if (IsEmpty()) {
        return nullptr;
    }
    return &array[--top];
}


class Stack : public Bag {
    static int count;
public:
    Stack(int MaxSize); // 생성자
    ~Stack(); // 소멸자
    void Add(Person&); // stack의 top에 원소를 추가한다
    Person* Delete(); // stack의 top 원소를 삭제한다.
    static int GetCountCoder() {
        return count;
    }
};
void Stack::Add(Person& p) {
    Bag::Add(p);
}
Stack::Stack(int MaxSize) : Bag(MaxSize) {
    // Stack을 위한 생성자는 Bag을 위한 생성자를 호출한다.
}
Stack::~Stack() {
    // Bag을 위한 소멸자는 Stack 이 제거될 때 자동적으로 호출된다.
    // 배열 array가 삭제되도록 해야 한다
}
Person* Stack::Delete() {
    return Bag::Delete();
}

int main() {
    Dept cpp("C++", "Busan"); Dept c("C", "Masan"); Dept java("Java", "Jeju");

    TableCoder* tc = new TableCoder();
    TableWorkStudent* tws = new TableWorkStudent();

    Stack* st = new Stack(N);

    cout << "coder 숫자 = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCountWorkStudent() << endl << endl;

    Coder coderSet[N] = {};
    WorkStudent workerSet[N] = {};
    Person* peopleSet[N] = { nullptr };
    peopleSet[0] = new Person("P001", "Alice");
    peopleSet[1] = new Employee("E001", "P002", "Bob", &cpp);
    peopleSet[2] = new Student("S001", "P003", "Charlie", &c);
    peopleSet[3] = new Coder("C++", 5.5, "E002", "P004", "David", &cpp);
    peopleSet[4] = new WorkStudent(1500, 3.8, "E003", "P005", "Emily", &java);
    ShowAll(peopleSet, N);
    for (int i = 0; i < N; ++i)
    {
        st->Add(coderSet[i]);
    }

    Coder* cx = new Coder("C++", 5.5, "E002", "P004", "David", &cpp);
    WorkStudent* wsx = new WorkStudent(1500, 3.8, "E003", "P005", "Emily", &java);

    cout << "Coder 검색 결과 = " << tc->Search(cx) << endl;//pid, eid, lanuage가 같아야한다
    cout << "WorkStudent 검색 결과 = " << tws->Search(wsx) << endl;//pid, eid, sid가 같아야 한다 

    cout << "Coder 집합";
    tc->show();//show()를 사용하여 출력
    cout << "WorkStudent 집합";
    tws->show();//show()를 사용하여 출력

    cout << "Coder 집합2" << *tc << endl;//operator<<()를 사용하여 출력
    cout << "WorkStudent 집합2" << *tws << endl;//operator<<()를 사용하여 출력

    cout << "coder 숫자 = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCountWorkStudent() << endl;

    delete tc;
    delete tws;
    return 0;
}
