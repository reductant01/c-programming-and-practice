/*
* 다중상속 : Person - Employee - Coder, Person - Student, Coder + Student - CoderStudent 객체들을 stack에 넣는 구현
* 객체들의 집합을 갖는 테이블의 배열을 갖는 클래스 구현하기
*/
#include <iostream>
#include <string>
#include <algorithm>  // sort 함수가 정의된 헤더 파일

#define DefaultSize 50
#define tableMaxSize 20

using namespace std;

class Person { //추상 클래스로 구현한다
protected:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
public:
    string GetName() { return pname; }
    void SetName(char* str) { pname = str; }
    string pid;
    string pname;

    virtual void Print() {
        cout << "Person: " << pname << " (" << pid << ")" << endl;
    }
    virtual bool Equals(Person*) = 0;
    virtual ~Person() {}
    virtual int operator >(Person&) = 0;

};

class Employee : virtual public Person {
private:
    string eno;
    string role;
public:
    Employee() {}

    Employee(string pid, string pname, string eno, string role)
        : Person(pid, pname), eno(eno), role(role) { }

    virtual void Print() {
        cout << "Employee: " << pname << " (" << pid << "), eno: " << eno << ", role: " << role << endl;
    }

    virtual bool Equals(Person* p) {
        return (this->pname == p->pname);
    }

    virtual int operator >(Person& p) {
        return this->pname > p.GetName();
    }
};

class Coder : virtual public Employee {
private:
    string language;
public:
    Coder(string pid, string pname, string eno, string role, string language)
        : Employee(pid, pname, eno, role), language(language) { }

    void Print() override {
        Employee::Print();
        cout << ", language: " << language << endl;
    }
};


class Student : virtual public Person {
private:
    string sid;
    string major;
public:
    Student(string pid, string pname, string sid, string major)
        : Person(pid, pname), sid(sid), major(major) { }

    void Print() override {
        cout << "Student: " << pname << " (" << pid << "), sid: " << sid << ", major: " << major << endl;
    }

    virtual bool Equals(Person* p) {
        return (this->pname == p->pname);
    }

    virtual int operator >(Person& p) override {
        return this->pname > p.GetName();
    }
};

class CoderStudent : public Coder, public Student {
private:
    int cowork_year;
public:
    CoderStudent(string pid, string pname, string eno, string role, string language, string sid, string major, int cowork_year)
        : Person(pid, pname), Coder(pid, pname, eno, role, language), Student(pid, pname, sid, major), cowork_year(cowork_year) { }

    void Print() override {
        Coder::Print();
        Student::Print();
        cout << ", cowork year: " << cowork_year << endl;
    }

    virtual bool Equals(Person* p) {
        return (this->pname == p->pname);
    }

    virtual int operator >(Person& p) override {
        return this->pname > p.GetName();
    }
};


class RecordTable {
    int top;
    Person* data[tableMaxSize];
    int capacity;
public:
    RecordTable(int capacity) : top(0), capacity(capacity) {
        for (int i = 0; i < tableMaxSize; ++i) {
            data[i] = nullptr;
        }
    }

    int Add(Person* p) { // 정수 하나를 bag에 삽입
        if (top >= capacity) {
            cout << "Table is full" << endl;
            return -1;
        }
        data[top++] = p;
        return 0;
    }

    Person* Delete(const char* pname) {
        for (int i = 0; i < top; i++) {
            if (data[i]->pname == pname) {
                Person* deleted = data[i];
                for (int j = i; j < top - 1; j++) {
                    data[j] = data[j + 1];
                }
                top--;
                return deleted;
            }
        }
        return nullptr;
    }

    void Sort() {
        sort(data, data + top, [](Person* a, Person* b) {
            return *a > *b;
            });
    }

    Person* Search(const char* name) {
        for (int i = 0; i < top; i++) {
            if (data[i]->pname == name) {
                return data[i];
            }
        }
        return nullptr;
    }

    void Print() {
        for (int i = 0; i < top; i++) {
            data[i]->Print();
        }
    }
};

int main() {
    Person* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
    RecordTable table(30);//10개의 record sets, 각 set은 5개의 records
    int select;
    Person* p;
    int result;
    while (1)
    {
        cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
        cin >> select;
        switch (select) {
        case 1://table에 객체 30개 입력
            members[0] = new Coder("p1", "hong", "E1", "Coding", "C++");
            members[1] = new Coder("p2", "hee", "E2", "Coding", "C++");
            members[2] = new Coder("p3", "kim", "E3", "Test", "JAVA");
            members[3] = new Coder("p4", "lee", "E4", "Test", "C#");
            members[4] = new Coder("p5", "ko", "E5", "Design", "GO");
            members[5] = new Coder("p6", "choi", "E6", "Design", "GO");
            members[6] = new Coder("p7", "han", "E7", "Sales", "PYTHON");
            members[7] = new Coder("p8", "na", "E8", "Sales", "C");
            members[8] = new Coder("p9", "you", "E9", "Account", "C++");
            members[9] = new Coder("p10", "song", "E10", "Production", "C#");
            members[10] = new Student("s011", "hong", "S1", "Engineering");
            members[11] = new Student("s012", "ong", "S2", "Engineering");
            members[12] = new Student("s013", "dong", "S3", "Engineering");
            members[13] = new Student("s014", "fong", "S4", "Engineering");
            members[14] = new Student("s015", "tong", "S5", "Engineering");
            members[15] = new Student("s016", "nong", "S6", "Engineering");
            members[16] = new Student("s017", "mong", "S7", "Engineering");
            members[17] = new Student("s018", "kong", "S8", "Engineering");
            members[18] = new CoderStudent("s019", "long", "E33", "manager", "C++", "S9", "Engineering", 2);
            members[19] = new CoderStudent("s020", "pong", "E34", "manager", "C++", "S10", "Engineering", 3);
            members[20] = new CoderStudent("s021", "lim", "E35", "manager", "C++", "S11", "Engineering", 4);
            members[21] = new CoderStudent("s022", "mim", "E36", "manager", "C++", "S12", "Engineering", 5);
            members[22] = new CoderStudent("s023", "bim", "E37", "manager", "C++", "S13", "Engineering", 6);
            members[23] = new Student("s024", "dim", "S14", "Engineering");
            members[24] = new Student("s025", "rim", "S15", "Engineering");
            members[25] = new Student("s026", "qim", "S16", "Engineering");
            members[26] = new CoderStudent("s027", "fim", "E38", "manager", "C++", "S17", "Engineering", 7);
            members[27] = new CoderStudent("s028", "him", "E39", "manager", "C++", "S18", "Engineering", 8);
            members[28] = new CoderStudent("s029", "jim", "E40", "manager", "C++", "S19", "Engineering", 9);
            members[29] = new CoderStudent("s030", "jjj", "E41", "manager", "C++", "S20", "Engineering", 10);

            for (int i = 0; i < 30; i++) {
                table.Add(members[i]);
            }
            break;
        case 2:
            // table의 모든 객체 출력하기
            //table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

            table.Print();
            break;
        case 3:
            // table에서 객체 찾기

            p = table.Search("kim");
            if (p == nullptr) cout << "kim이 존재하지 않는다" << endl;
            else
                p->Print();
            break;
        case 4:
            //table에서 객체 삭제하기
            p = table.Delete("hong");
            cout << "삭제된 records ";
            p->Print();

            break;

        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}