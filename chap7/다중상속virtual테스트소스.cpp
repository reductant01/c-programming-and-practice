//수업 시간에 연습 코딩 실습
//virtual 상속시에 생성자 문제를 해결하는 것이 필요하다 
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string pname;
public:
    Person() {}
    Person(string pname) : pname(pname) {}
    friend ostream& operator <<(ostream& os, Person& person);
    virtual void print(){}

};

ostream& operator <<(ostream& os, Person& person) {
   
    os<< person.pname;
    return os;
}
class Employee : virtual public Person {
private:
    string eno;
public:
    Employee() {}
    Employee(string eno, string pname) : Person(pname), eno(eno) {
    }
    void print() { cout << "Emp"; }
    friend ostream& operator<<(ostream& os, Employee&);

};
ostream& operator<<(ostream& os, Employee& employee) {
    os << employee.eno << (Person)employee;
    return os;
}

class Student : virtual public Person {
private:
    string sno;
public:
    Student() {}
    Student(string sno, string pname):Person(pname),sno(sno) {}
    friend ostream& operator<<(ostream& os, Student& st);

};
ostream& operator<<(ostream& os, Student& st) {
    os << st.sno << (Person)st;
    return os;
}
class WorkStudent : public Student, public Employee {
    string cowork;
public:
    WorkStudent() {}
    WorkStudent(string cowork, string sno, string eno, string pname): Student(sno, pname), Employee(eno, pname), cowork(cowork){}
    int operator >(WorkStudent&);
};
int WorkStudent::operator >(WorkStudent&) {

}
class Designer : public Employee {
    string design;
};
void swap(Person* p[], int i, int j) {
    Person* temp;
    temp = p[i]; p[i] = p[j]; p[j] = temp;
}

int main() {
    while (1)
    {
        Person* workstudents[20];//Person 선언으로 변경하는 문제 해결 필요 
        Person* designers[20];
        int select;
        Person* p;
        WorkStudent cx;
        cout << "\n선택 1: WorkStudent 객체 10개 입력과 출력, 2: WorkStudent객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력, 3. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: WorkStudent 객체 10개 입력과 출력
            workstudents[0] = new WorkStudent("p1", "hong", "E1", "Coding");
            workstudents[1] = new WorkStudent("p2", "hee", "E2", "Coding");
            workstudents[2] = new WorkStudent("p3", "kim", "E3", "Test");
            workstudents[3] = new WorkStudent("p4", "lee", "E4", "Test");
            workstudents[4] = new WorkStudent("p5", "ko", "E5", "Design");
            workstudents[5] = new WorkStudent("p6", "choi", "E6", "Design");
            workstudents[6] = new WorkStudent("p7", "han", "E7", "Sales");
            workstudents[7] = new WorkStudent("p8", "na", "E8", "Sales");
            workstudents[8] = new WorkStudent("p9", "you", "E9", "Account");
            workstudents[9] = new WorkStudent("p10", "song", "E10", "Production");
            for (int i = 0; i < 10; i++)
            {
                cout <<(* workstudents[i]) << endl;
            }
            break;
        case 2:
            break;
            designers[0] = new Designer();

        case 3://3: WorkStudent객체 정렬
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    Person* p = workstudents[i];
                    WorkStudent* cp = dynamic_cast<WorkStudent*>(p);
                    Person* q = workstudents[j];
                    WorkStudent* cq = dynamic_cast<WorkStudent*>(q);

                    if (*cp > *cq) swap(workstudents, i, j);
                }
            for (int i = 0; i < 10; i++)
            {
                //cout<<workstudents[i];
            }
            break;
        case 4:
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                //designers의 정렬
                }
            for (int i = 0; i < 10; i++)
            {
                //cout<<designers[i];
            }
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}