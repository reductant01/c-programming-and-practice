//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;
class Dept {
    string dname;
    string city;
public:
    Dept() {}
    Dept(string dname, string city) : dname(dname), city(city) {}
    friend ostream& operator<<(ostream& os, Dept&);
    friend istream& operator >>(istream& is, Dept& dept);
    int operator >(Dept&);
};
int Dept::operator >(Dept&d) {
    int num = 0;
    if (this->dname.compare(d.dname) == 1) num = 1;
    else if (this->dname.compare(d.dname) == -1)num = -1;
    else num = 0;
    cout << "this = " <<this->dname << "d.dname = " <<d.dname << " num = " << num <<endl;
    return num;
}
istream& operator>>(istream& is, Dept& dept) {
    cout << "학과명 : 도시 입력";
    cin >> dept.dname >> dept.city;
    return is;
}
ostream& operator<<(ostream& os, Dept& dept) {

    os << ", 부서명 = "<<dept.dname << ", 부서도시 = "<<dept.city;
    return os;
}
class Person {
private:
    string pid;
    string pname;
public:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
    friend ostream& operator<<(ostream& os, Person& person);
    friend istream& operator >>(istream& is, Person& person);
    virtual void print() { cout << "person"; }

};
ostream& operator<<(ostream& os, Person& person) {

    os << ", 개인번호 = " << person.pid << ", 이름 = " << person.pname;
    return os;
}
istream& operator >>(istream& is, Person& person) {
    cout << "pid: pname 입력 ";
    is >> person.pid >> person.pname;
    return is;
}
class Employee : virtual public Person {
private:
    string eno;
    Dept* dept;
public:
    Employee():Person(){}
    int operator >(Employee&);
    Employee(string pid, string pname, string eno, string dname, string city) : Person(pid, pname),eno(eno) {
       dept = new Dept(dname, city);
    }
    int operator < (Employee&);
    friend ostream& operator<<(ostream& os, Employee&);
    friend istream& operator >>(istream& is, Employee& employee);
    void print() { cout << "emp"; }

};
int Employee::operator >(Employee& emp) {
    return ((*(this->dept)) > (*(emp.dept)));
}
int Employee::operator <(Employee& emp) {
    return this->eno.compare(emp.eno);  
}
ostream& operator<<(ostream& os, Employee& employee) {
    os << ", 사원번호 = "<<employee.eno << (*employee.dept) << (Person)employee;//upcasting으로 입력이 되지 않음 - 과제 제외
    return os;
}

istream& operator >>(istream& is, Employee& employee) {
    Person p = (Person)employee;
    is >> p;
    cout << "eno:입력 ";
    is >> employee.eno;
    cout << "eno = " << employee.eno << endl;
    //employee.pid = p.pid;//접근 처리가 안됨 
    return is;
}
class Coder : public Employee {
private:
    string language;
    double workYears;
public:
    Coder():Employee(){}
    Coder(string pid, string pname, string eno, string dname, string city, string lang, double years) : Employee(pid, pname, eno, dname, city), language(lang), workYears(years) {}
    int operator > (Coder&);//

    friend ostream& operator<<(ostream& os, Coder& coder);
    friend istream& operator >>(istream& is, Coder& coder);

};
int Coder::operator > (Coder& cd) {
    return (Employee(*this) > (Employee)cd);
}
ostream& operator<<(ostream& os, Coder& coder) {
    os << "language = " <<coder.language << ", 개발경력 = " << coder.workYears << (Employee)coder;
    return os;
}
istream& operator >>(istream& is, Coder& coder) {
    is >> (Employee)coder;

    cout << "언어 입력: 코딩 경력 ";
    is >> coder.language >> coder.workYears;
    return is;
}
class Student : virtual public Person {//virtual은 Person() 생성자를 호출하지 않음
private:
    string sid;
    Dept* dname;
public:
    Student(string sid, string dept, string city, string pid, string pname) : Person(pid, pname), sid(sid) {
        
        dname = new Dept(dept, city);
    }
    friend ostream& operator<<(ostream& os, Student& student);
    int operator < (Student&);
};
int Student::operator < (Student& s) {
    return this->sid.compare(s.sid);
}

ostream& operator<<(ostream& os, Student& student) {
    os << "학번 = " << student.sid << (*student.dname) << (Person)student;
    return os;
}
class PartTimeStudent : public Employee, public Student {
private:
    double salary;
    double grade;
public:
    PartTimeStudent(double salary, double grade, string sid, string dept, string city, string eno, string edept, string ecity, string pid, string pname):
        Employee(pid, pname, eno, edept, ecity), Student(sid,dept, city, pid, pname), salary(salary),grade(grade){
        //Person() 생성자를 인위적으로 먼저 호출한 후에 Employee()와 Student() 생성자를 불러야 한다 
    }
    friend ostream& operator<<(ostream& os, PartTimeStudent& worker);
    int operator < (PartTimeStudent&);

};
int PartTimeStudent::operator < (PartTimeStudent& pts) {
    int eResult = Employee(*this) < (Employee)pts;
    if (eResult == 0) {
        return (Student(*this) < (Student)pts);

    }
    else return eResult;
}
ostream& operator<<(ostream& os, PartTimeStudent& worker) {
    os << "급여 = " << worker.salary << ", 학년 = " << worker.grade << (Employee)worker<<(Student)worker;
    return os;
}
//hard-coding을 해결하는 방법이 필요 
void swap(Person *p[], int i, int j) {
    Person* temp;
    temp = p[i]; p[i] = p[j]; p[j] = temp;
}

int main() {
    while (1)
    {
        Person* codings[20];//Person 선언으로 변경하는 문제 해결 필요 
        Person* workStudents[10];
        int select;
        Person* p;
        Coder cx;
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            codings[0] = new Coder("p1", "hong", "E1", "Coding", "Busan", "C++", 1.2);
            codings[1] = new Coder("p2", "hee", "E2", "Coding", "Busan", "C++", 1.2);
            codings[2] = new Coder("p3", "kim", "E3", "Test", "Busan", "JAVA", 1.2);
            codings[3] = new Coder("p4", "lee", "E4", "Test", "Busan", "C#", 1.2);
            codings[4] = new Coder("p5", "ko", "E5", "Design", "Busan", "GO", 1.2);
            codings[5] = new Coder("p6", "choi", "E6", "Design", "Busan", "GO", 1.2);
            codings[6] = new Coder("p7", "han", "E7", "Sales", "Busan", "PYTHON", 1.2);
            codings[7] = new Coder("p8", "na", "E8", "Sales", "Busan", "C", 1.2);
            codings[8] = new Coder("p9", "you", "E9", "Account", "Busan", "C++", 1.2);
            codings[9] = new Coder("p10", "song", "E10", "Production", "Busan", "C#", 1.2);
            for (int i = 0; i < 10; i++)
            {
                Person* p = codings[i];               
                Coder* cp = dynamic_cast<Coder*>(p);
                cout << (*cp) << endl;
            }
            break;
        case 2://2. PartTimeStudent 객체 10개 입력과 출력
            workStudents[0] = new PartTimeStudent(200.1, 3.4, "s001", "computer", "busan", "e901", "sales", "jeju", "23001", "hong");
            workStudents[1] = new PartTimeStudent(100.1, 2.4, "s002", "DB", "busan", "e801", "sales", "jeju", "23001", "hong");
            workStudents[2] = new PartTimeStudent(300.1, 3.4, "s003", "Java", "busan", "e001", "design", "jeju", "23001", "hong");
            workStudents[3] = new PartTimeStudent(20.1, 4.4, "s004", "기계", "busan", "e091", "영업", "jeju", "23001", "hong");
            workStudents[4] = new PartTimeStudent(255.1, 1.4, "s005", "전기", "busan", "e081", "회계", "jeju", "23001", "hong");
            workStudents[5] = new PartTimeStudent(400.1, 2.4, "s006", "의류", "busan", "e301", "생산", "jeju", "23001", "hong"); 
            workStudents[6] = new PartTimeStudent(900.1, 3.3, "s007", "전자", "busan", "e501", "판매", "jeju", "23001", "hong");
            workStudents[7] = new PartTimeStudent(800.1, 3.1, "s008", "화공", "busan", "e801", "자재", "jeju", "23001", "hong");
            workStudents[8] = new PartTimeStudent(2055.1, 3.3, "s009", "화학", "busan", "e011", "전장", "jeju", "23001", "hong");
            workStudents[9] = new PartTimeStudent(660.1, 3.8, "s010", "산업", "busan", "e041", "엔진", "jeju", "23001", "hong");
           
            for (int i = 0; i < 10; i++)
            {
                Person* p = workStudents[i];
                PartTimeStudent* cp = dynamic_cast<PartTimeStudent*>(p);
                cout << (*cp) << endl;                
            }
            break;

        case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    Person* p = codings[i];
                    Person* q = codings[j];
                    Coder* cp = dynamic_cast<Coder*>(p);
                    Coder* cq = dynamic_cast<Coder*>(q);
                    int result = (*cp > *cq);
                    cout << "result = " << result << endl;
                    if (result == 1)
                     swap(codings, i, j);
                }
            for (int i = 0; i < 10; i++)
            {
                Person* p = codings[i];
                Coder* cp = dynamic_cast<Coder*>(p);
                cout << (*cp) << endl;                
            }
            break;
        case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    Person* p = workStudents[i];
                    Person* q = workStudents[j];
                    PartTimeStudent* cp = dynamic_cast<PartTimeStudent*>(p);
                    PartTimeStudent* cq = dynamic_cast<PartTimeStudent*>(q);
                    int result2 = (*cp < *cq);
                 
                    cout << "result = " << result2 << endl;
                    if (result2 == -1)
                        swap(workStudents, i, j);
                }
                   
            for (int i = 0; i < 10; i++)
            {
                Person* p = workStudents[i];
                PartTimeStudent* cp = dynamic_cast<PartTimeStudent*>(p);
                cout << (*cp) << endl;                
            }
            break;
        
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}