//7�� Ŭ���� ��� ����
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
    cout << "�а��� : ���� �Է�";
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
    cout << "pid: pname �Է� ";
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
    cout << "eno:�Է� ";
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
    void MoveDept(Dept* dname);//�μ� �̵�
    friend ostream& operator<<(ostream& os, Coder& coder);
    friend istream& operator >>(istream& is, Coder& coder);

};
ostream& operator<<(ostream& os, Coder& coder) {
    os << coder.language << coder.workYears << (Employee)coder;
    return os;
}
istream& operator >>(istream& is, Coder& coder) {
    is >> (Employee)coder;
    
    cout << "��� �Է�: �ڵ� ��� ";
    is >> coder.language >> coder.workYears;
    return is;
}

int main() {
    while (1)
    {
        Coder* codings[20];
        int numberCoders = 0;
        int select;
        //������ ��뿡 ���� �Է��� new Coder("�̸�", ...)���� ���� �����Ͽ� �Է�
        cout << "\n���� 1: ��ü 4�� �Է�(cin ���), 2. ��ü 10�� �Է�(������ ���), 3: ��ü ����(Dept �̸�)�� ���,4. ��ü ����(Coder workYears)�� ���, 5. ����" << endl;
        cin >> select;
        Coder cx;
        switch (select) {
        case 1://1: ��ü 4�� �Է�(cin ���)
            for (int i = 0; i < 4; i++) {
                string pid, pname, eno, dname, city, lang;
                double years;
                cin >> pid >> pname >> eno >> dname >> city >> lang;
                cin >> years;
                codings[i] = new Coder(pid, pname, eno, dname, city, lang, years);
            }
            break;
        case 2://2. ��ü 10�� �Է�(������ ���)
            cin >> cx;
            cout << "�Է¼���" << endl;
            cout << cx;
            break;

        case 3://3: ��ü ����(Dept �̸�)�� ���
            
            break;
        case 4://4. ��ü ����(Coder workYears)�� ���
            
            break;
        default:
            exit(0);
         
        }
    }
    system("pause");
    return 1;
}