//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;
class Dept {
    string dname;
    string city;
public:
    Dept(){}
    Dept(string dname, string city): dname(dname), city(city) {}
    friend ostream& operator<<(ostream& os, Dept&);
    friend istream& operator >>(istream& is, Dept& dept);
};
istream& operator>>(istream& is, Dept& dept) {
    cout << "학과명 : 도시 입력";
    cin >> dept.dname >> dept.city;
    return is;
}
ostream& operator<<(ostream& os, Dept&dept) {
    
    os << dept.dname << dept.city;
    return os;
}
class Person {
private:
    string pid;
    string pname;
public:
    Person(){}
    Person(string pid, string pname): pid(pid), pname(pname){}
    friend ostream& operator<<(ostream& os, Person& person);
    friend istream& operator >>(istream& is, Person& person);

};
ostream& operator<<(ostream& os, Person& person) {
   
    os << person.pid << person.pname;
    return os;
}
istream& operator >>(istream& is, Person& person) {
    cout << "pid: pname 입력 ";
    is >> person.pid >> person.pname;
    return is;
}
class Employee : protected Person {
private:
    string eno;
    Dept* dept;
public:
    Employee(){}
    Employee(string pid, string pname, string eno, string dname, string city) : Person(pid, pname), eno(eno) {
        dept = new Dept(dname, city);
    }
    
    void MoveDept(Dept* dname);
    friend ostream& operator<<(ostream& os, Employee&);
    friend istream& operator >>(istream& is, Employee& employee);
    ~Employee() { delete dept; }
};
ostream& operator<<(ostream& os, Employee& employee) {
    os << employee.eno << (*employee.dept) << (Person)employee;
    return os;
}
istream& operator >>(istream& is, Employee& employee) {
    is >> (Person)employee;
    cout << "eno:입력 ";
    is >> employee.eno;
    employee.dept = new Dept();
    is >> *(employee.dept);
    return is;
}
class Coder : private Employee {
private:
    string language;
    double workYears;
public:
    Coder() {}
    Coder(string pid, string pname, string eno, string dname, string city, string lang, double years) : Employee(pid, pname, eno, dname, city), language(lang), workYears(years) {}
    int operator > (Coder&);//
    Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
    void MoveDept(Dept* dname);//부서 이동
    friend ostream& operator<<(ostream& os, Coder& coder);
    friend istream& operator >>(istream& is, Coder& coder);

};
ostream& operator<<(ostream& os, Coder& coder) {
    os << coder.language << coder.workYears << (Employee)coder;
    return os;
}
istream& operator >>(istream& is, Coder& coder) {
    is >> (Employee)coder;
    
    cout << "언어 입력: 코딩 경력 ";
    is >> coder.language >> coder.workYears;
    return is;
}

int main() {
    while (1)
    {
        Coder* codings[20];
        int numberCoders = 0;
        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        cout << "\n선택 1: 객체 4개 입력(cin 사용), 2. 객체 10개 입력(생성자 사용), 3: 객체 정렬(Dept 이름)과 출력,4. 객체 정렬(Coder workYears)과 출력, 5. 종료" << endl;
        cin >> select;
        Coder cx;
        switch (select) {
        case 1://1: 객체 4개 입력(cin 사용)
            for (int i = 0; i < 4; i++) {
                string pid, pname, eno, dname, city, lang;
                double years;
                cin >> pid >> pname >> eno >> dname >> city >> lang;
                cin >> years;
                codings[i] = new Coder(pid, pname, eno, dname, city, lang, years);
            }
            break;
        case 2://2. 객체 10개 입력(생성자 사용)
            cin >> cx;
            cout << "입력성공" << endl;
            cout << cx;
            break;

        case 3://3: 객체 정렬(Dept 이름)과 출력
            
            break;
        case 4://4. 객체 정렬(Coder workYears)과 출력
            
            break;
        default:
            exit(0);
         
        }
    }
    system("pause");
    return 1;
}