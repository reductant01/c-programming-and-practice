#include <iostream>
#include <string>

using namespace std;
const int N = 20;

class Dept {
    string dname;
    string city;
    friend ostream& operator<<(ostream&, Dept&);
public:
    Dept(string dname, string city) : dname(dname), city(city) {}
};

ostream& operator<<(ostream& os, Dept& dept) {
    os << "Dept Name: " << dept.dname << ", City: " << dept.city;
    return os;
}

class Person {
private:
    string pid;
    string pname;
    friend ostream& operator<<(ostream&, Person&);
public:
    Person(string pid, string pname) : pid(pid), pname(pname) {}
};

ostream& operator<<(ostream& os, Person& person) {
    os << "Person ID: " << person.pid << ", Name: " << person.pname;
    return os;
}

class Employee : protected Person {
private:
    string eno;
    Dept* dept;
    friend ostream& operator<<(ostream&, Employee&);
public:
    Employee(string eno, Dept* dept, string pid, string pname) : Person(pid, pname), eno(eno), dept(dept) {}

    string getEno() const { return eno; }
    Dept* getDept() const { return dept; }
};

ostream& operator<<(ostream& os, Employee& emp) {
    os << (Person&)emp;
    os << ", Employee No: " << emp.eno << ", Department: " << *(emp.dept);
    return os;
}

class Student : private Person {
private:
    string sid;
    Dept* dept;
    friend ostream& operator<<(ostream&, Student&);
public:
    Student(string sid, Dept* dept, string pid, string pname) : Person(pid, pname), sid(sid), dept(dept) {}
};

ostream& operator<<(ostream& os, Student& student) {
    os << (Person&)student;
    os << ", Student ID: " << student.sid << ", Department: " << *(student.dept);
    return os;
}

class Coder : private Employee {
private:
    string language;
    double workYears;
public:
    int operator > (Coder&);
    bool operator == (const Coder&) const;
    Coder(string language, double workYears, string eno, Dept* dept, string pid, string pname)
        : Employee(eno, dept, pid, pname), language(language), workYears(workYears) {}

    friend ostream& operator<<(ostream&, Coder&);
};

int Coder::operator > (Coder& other) {
    return this->workYears > other.workYears;
}

bool Coder::operator == (const Coder& other) const {
    return this->language == other.language && this->workYears == other.workYears &&
        this->getEno() == other.getEno() && this->getDept() == other.getDept();
}

ostream& operator<<(ostream& os, Coder& coder) {
    os << (Employee&)coder;
    os << ", Language: " << coder.language << ", Work Years: " << coder.workYears;
    return os;
}

class WorkStudent : private Employee, private Student {
private:
    double salary;
    double grade;
    friend ostream& operator<<(ostream&, WorkStudent&);
public:
    WorkStudent(double salary, double grade, string eno, Dept* dept, string sid, string pid, string pname)
        : Employee(eno, dept, pid, pname), Student(sid, dept, pid, pname), salary(salary), grade(grade) {}
};

ostream& operator<<(ostream& os, WorkStudent& ws) {
    os << (Employee&)ws;
    os << ", Salary: " << ws.salary << ", Grade: " << ws.grade;
    return os;
}

class TableCoder {
private:
    Coder* table[N];
    int top;
    static int count;
public:
    TableCoder() : top(0) {}

    void Add(const Coder& st) {
        if (top < N) {
            table[top] = new Coder(st);
            top++;
            count++;
        }
    }

    bool Search(Coder& st) {
        for (int i = 0; i < top; i++) {
            if (*table[i] == st) {
                return true;
            }
        }
        return false;
    }

    static int GetCount() {
        return count;
    }

    friend ostream& operator<<(ostream& stream, const TableCoder& ts);
};

int TableCoder::count = 0;

ostream& operator<<(ostream& stream, const TableCoder& ts) {
    for (int i = 0; i < ts.top; i++) {
        stream << *(ts.table[i]) << endl;
    }
    return stream;
}

class TableWorkStudent {
private:
    WorkStudent* table[N];
    int top;
    static int count;
public:
    TableWorkStudent() : top(0) {}

    void Add(const WorkStudent& ws) {
        if (top < N) {
            table[top] = new WorkStudent(ws);
            top++;
            count++;
        }
    }

    bool Search(Coder& st) {
        for (int i = 0; i < top; i++) {
            if (*(Coder*)table[i] == st) {
                return true;
            }
        }
        return false;
    }

    static int GetCount() {
        return count;
    }

    friend ostream& operator<<(ostream& stream, const TableWorkStudent& ts);
};

int TableWorkStudent::count = 0;

ostream& operator<<(ostream& stream, const TableWorkStudent& ts) {
    for (int i = 0; i < ts.top; i++) {
        stream << *(ts.table[i]) << endl;
    }
    return stream;
}

int main() {
    TableCoder* tc = new TableCoder();
    TableWorkStudent* tws = new TableWorkStudent();

    cout << "coder 숫자 = " << TableCoder::GetCount() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCount() << endl;

    Dept d1("Computer Science", "Seoul");
    Dept d2("Electrical Engineering", "Busan");

    Coder coderSet[] = {
        Coder("C++", 5, "E001", &d1, "P001", "Alice"),
        Coder("Java", 3, "E002", &d2, "P002", "Bob"),
        Coder("Python", 4, "E003", &d1, "P003", "Charlie"),
        Coder("JavaScript", 2, "E004", &d2, "P004", "David"),
        Coder("Ruby", 6, "E005", &d1, "P005", "Eve"),
        Coder("Go", 1, "E006", &d2, "P006", "Frank"),
        Coder("Swift", 3, "E007", &d1, "P007", "Grace"),
        Coder("Kotlin", 4, "E008", &d2, "P008", "Heidi"),
        Coder("PHP", 5, "E009", &d1, "P009", "Ivy"),
        Coder("Rust", 2, "E010", &d2, "P010", "Jack")
    };

    WorkStudent workerSet[] = {
        WorkStudent(2000.0, 3.8, "E011", &d1, "S001", "P011", "Kim"),
        WorkStudent(1800.0, 3.6, "E012", &d2, "S002", "P012", "Lee"),
        WorkStudent(2200.0, 3.9, "E013", &d1, "S003", "P013", "Park"),
        WorkStudent(1900.0, 3.7, "E014", &d2, "S004", "P014", "Choi"),
        WorkStudent(2100.0, 4.0, "E015", &d1, "S005", "P015", "Jung"),
        WorkStudent(1700.0, 3.5, "E016", &d2, "S006", "P016", "Kang"),
        WorkStudent(2300.0, 3.8, "E017", &d1, "S007", "P017", "Jo"),
        WorkStudent(2000.0, 3.6, "E018", &d2, "S008", "P018", "Yoon"),
        WorkStudent(2400.0, 3.9, "E019", &d1, "S009", "P019", "Han"),
        WorkStudent(1600.0, 3.7, "E020", &d2, "S010", "P020", "Lim")
    };

    for (int i = 0; i < 10; i++) {
        tc->Add(coderSet[i]);
        tws->Add(workerSet[i]);
    }

    Coder cx("Python", 4, "E003", &d1, "P003", "Charlie");
    WorkStudent wsx(2200.0, 3.9, "E013", &d1, "S003", "P013", "Park");

    cout << "Coder 검색 결과 = " << tc->Search(cx) << endl;
    cout << "WorkStudent 검색 결과 = " << tws->Search(cx) << endl;

    cout << "Coder 집합" << endl << *tc;
    cout << "WorkStudent 집합" << endl << *tws;

    cout << "coder 숫자 = " << TableCoder::GetCount() << endl;
    cout << "workstudents 숫자 = " << TableWorkStudent::GetCount() << endl;

    delete tc;
    delete tws;
    return 0;
}
