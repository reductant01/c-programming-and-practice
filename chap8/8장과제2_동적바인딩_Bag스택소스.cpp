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
    int top; // �Էµ� ����
public:
    TableObjects() : top(0) {
        for (int i = 0; i < N; ++i) {
            table[i] = nullptr;
        }
    }
    virtual void show() const {
        // table ��ü�� ����Ѵ�
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
        // operator==() ����ؾ� �Ѵ� - ���̺� �־��� ��ü�� �ִ����� ã�´�
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
        // ���̺� �߰��Ѵ�
        TableObjects::Add(st);
        ++countCoder;
    }
    bool Search(const Person* st) const {
        // operator==() ����ؾ� �Ѵ� - ���̺� �־��� ��ü�� �ִ����� ã�´�
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
        // ���̺� �߰��Ѵ�
        TableObjects::Add(st);
        ++countWorkStudent;
    }
    bool Search(const Person* st) const {
        // operator==() ����ؾ� �Ѵ� - ���̺� �־��� ��ü�� �ִ����� ã�´�
        return TableObjects::Search(st);
    }
    friend ostream& operator<<(ostream& stream, const TableWorkStudent& ts);
    static int GetCountWorkStudent() {
        return countWorkStudent;
    }
};
int TableWorkStudent::countWorkStudent = 0;

ostream& operator<<(ostream& stream, const TableWorkStudent& ts) {
    // ���̺� ������� ����Ѵ�
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
    Bag(int MaxSize); // ������
    ~Bag(); // �Ҹ���
    virtual void Add(Person&); // bag�� �� ���Ҹ� ���� ��ҿ� �����Ѵ�.
    virtual Person* Delete(); // bag���κ��� �ƹ� ���Ҹ� �����Ѵ�.
    bool IsFull() {
        // bag�� �� ���� TRUE�� return�ϰ� �׷��� ������ FALSE�� return�Ѵ�.
        return top >= MaxSize;
    }
    bool IsEmpty() {
        // bag�� ������� TRUE�� return�ϰ� �׷��� ������ FALSE�� return�Ѵ�.
        return top == 0;
    }
protected:
    Person* array;
    int MaxSize; // �迭�� ũ��
    int top; // ���Ҹ� �����ϰ� �ִ� �迭���� ���� ū index ��ġ
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
    Stack(int MaxSize); // ������
    ~Stack(); // �Ҹ���
    void Add(Person&); // stack�� top�� ���Ҹ� �߰��Ѵ�
    Person* Delete(); // stack�� top ���Ҹ� �����Ѵ�.
    static int GetCountCoder() {
        return count;
    }
};
void Stack::Add(Person& p) {
    Bag::Add(p);
}
Stack::Stack(int MaxSize) : Bag(MaxSize) {
    // Stack�� ���� �����ڴ� Bag�� ���� �����ڸ� ȣ���Ѵ�.
}
Stack::~Stack() {
    // Bag�� ���� �Ҹ��ڴ� Stack �� ���ŵ� �� �ڵ������� ȣ��ȴ�.
    // �迭 array�� �����ǵ��� �ؾ� �Ѵ�
}
Person* Stack::Delete() {
    return Bag::Delete();
}

int main() {
    Dept cpp("C++", "Busan"); Dept c("C", "Masan"); Dept java("Java", "Jeju");

    TableCoder* tc = new TableCoder();
    TableWorkStudent* tws = new TableWorkStudent();

    Stack* st = new Stack(N);

    cout << "coder ���� = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents ���� = " << TableWorkStudent::GetCountWorkStudent() << endl << endl;

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

    cout << "Coder �˻� ��� = " << tc->Search(cx) << endl;//pid, eid, lanuage�� ���ƾ��Ѵ�
    cout << "WorkStudent �˻� ��� = " << tws->Search(wsx) << endl;//pid, eid, sid�� ���ƾ� �Ѵ� 

    cout << "Coder ����";
    tc->show();//show()�� ����Ͽ� ���
    cout << "WorkStudent ����";
    tws->show();//show()�� ����Ͽ� ���

    cout << "Coder ����2" << *tc << endl;//operator<<()�� ����Ͽ� ���
    cout << "WorkStudent ����2" << *tws << endl;//operator<<()�� ����Ͽ� ���

    cout << "coder ���� = " << TableCoder::GetCountCoder() << endl;
    cout << "workstudents ���� = " << TableWorkStudent::GetCountWorkStudent() << endl;

    delete tc;
    delete tws;
    return 0;
}
