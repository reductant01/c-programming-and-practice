//8 �����̳� Ŭ���� - ��ü�� ���� 
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
int Dept::operator >(Dept& d) {
    int num = 0;
    if (this->dname.compare(d.dname) == 1) num = 1;
    else if (this->dname.compare(d.dname) == -1)num = -1;
    else num = 0;
    cout << "this = " << this->dname << "d.dname = " << d.dname << " num = " << num << endl;
    return num;
}
istream& operator>>(istream& is, Dept& dept) {
    cout << "�а��� : ���� �Է�";
    cin >> dept.dname >> dept.city;
    return is;
}
ostream& operator<<(ostream& os, Dept& dept) {

    os << ", �μ��� = " << dept.dname << ", �μ����� = " << dept.city;
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
    virtual bool operator==(Person&);

};
bool Person::operator==(Person& p) {
    if (pid.compare(p.pid) == 0 && pname.compare(p.pname) == 0) return true;
    else return false;
}
ostream& operator<<(ostream& os, Person& person) {

    os << ", ���ι�ȣ = " << person.pid << ", �̸� = " << person.pname;
    return os;
}
istream& operator >>(istream& is, Person& person) {
    cout << "pid: pname �Է� ";
    is >> person.pid >> person.pname;
    return is;
}
class Employee : virtual public Person {
private:
    string eno;
    Dept* dept;
public:
    Employee() :Person() {}
    int operator >(Employee&);
    Employee(string pid, string pname, string eno, string dname, string city) : Person(pid, pname), eno(eno) {
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
    os << ", �����ȣ = " << employee.eno << (*employee.dept) << (Person)employee;//upcasting���� �Է��� ���� ���� - ���� ����
    return os;
}

istream& operator >>(istream& is, Employee& employee) {
    Person p = (Person)employee;
    is >> p;
    cout << "eno:�Է� ";
    is >> employee.eno;
    cout << "eno = " << employee.eno << endl;
    //employee.pid = p.pid;//���� ó���� �ȵ� 
    return is;
}
class Coder : public Employee {
private:
    string language;
    double workYears;
public:
    Coder() :Employee() {}
    Coder(string pid, string pname, string eno, string dname, string city, string lang, double years) : Person(pid, pname), Employee(pid, pname, eno, dname, city), language(lang), workYears(years) {}
    int operator > (Coder&);//

    friend ostream& operator<<(ostream& os, Coder& coder);
    friend istream& operator >>(istream& is, Coder& coder);

};
int Coder::operator > (Coder& cd) {
    return (Employee(*this) > (Employee)cd);
}
ostream& operator<<(ostream& os, Coder& coder) {
    os << "language = " << coder.language << ", ���߰�� = " << coder.workYears << (Employee)coder;
    return os;
}
istream& operator >>(istream& is, Coder& coder) {
    is >> (Employee)coder;

    cout << "��� �Է�: �ڵ� ��� ";
    is >> coder.language >> coder.workYears;
    return is;
}
class Student : virtual public Person {//virtual�� Person() �����ڸ� ȣ������ ����
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
    os << "�й� = " << student.sid << (*student.dname) << (Person)student;
    return os;
}
class PartTimeStudent : public Employee, public Student {
private:
    double salary;
    double grade;
public:
    PartTimeStudent(double salary, double grade, string sid, string dept, string city, string eno, string edept, string ecity, string pid, string pname) :
        Person(pid, pname), Employee(pid, pname, eno, edept, ecity), Student(sid, dept, city, pid, pname), salary(salary), grade(grade) {
        //Person() �����ڸ� ���������� ���� ȣ���� �Ŀ� Employee()�� Student() �����ڸ� �ҷ��� �Ѵ� 
    }
    friend ostream& operator<<(ostream& os, PartTimeStudent& worker);
    int operator < (PartTimeStudent&);
    void print();
};
void PartTimeStudent::print() {
    cout << (PartTimeStudent)(*this);
}
int PartTimeStudent::operator < (PartTimeStudent& pts) {
    int eResult = Employee(*this) < (Employee)pts;
    if (eResult == 0) {
        return (Student(*this) < (Student)pts);

    }
    else return eResult;
}
ostream& operator<<(ostream& os, PartTimeStudent& worker) {
    os << "�޿� = " << worker.salary << ", �г� = " << worker.grade << (Employee)worker << (Student)worker;
    return os;
}
//hard-coding�� �ذ��ϴ� ����� �ʿ� 
void swap(Person* p[], int i, int j) {
    Person* temp;
    temp = p[i]; p[i] = p[j]; p[j] = temp;
}
#define DefaultSize 10
class Bag {
public:
    Bag(int MaxSize = DefaultSize); //������
    ~Bag(); // �Ҹ���
    virtual void Add(Person *); // ���� �ϳ��� bag�� ����
    virtual Person* Delete(); //bag���� ���� �ϳ��� ����
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();
    friend ostream& operator<< (ostream& stream, Bag b);
protected:
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ
    Person* arr[DefaultSize];
    int MaxSize; // �迭�� ũ��
    int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);      //������
    ~Set();      // �Ҹ���
                 //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
    void Add(Person*);
    Person* Delete();
    friend ostream& operator<< (ostream& stream, Set s);
};


Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
    cout << "Bag::������ ȣ��" << endl;
    top = 0;
}

Bag::~Bag() {
    cout << "~Bag()ȣ���" << endl;
}

bool Bag::IsFull() {
    if (top == MaxSize - 1)
        return true;
    else
        return false;
}

bool Bag::IsEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}

void Bag::Full() {
    cout << "Data structure is full" << endl;
}

void Bag::Empty() {
    cout << "Data structure is empty" << endl;
}

void Bag::Add(Person * x) {
    if (IsFull())
        Full();
    else {
        arr[top] = x;
        cout << "BAG�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
        top++;
    }
}

Person* Bag::Delete() {
    //if (IsEmpty()) {
     //   Empty();
       // return x;
    //}
    int deletePos = top / 2;
    Person *x = arr[--top];
    for (int index = deletePos; index < top; index++)
        arr[index] = arr[index + 1];
    //top--;
    return x;
}

int Bag::Top() {
    return top;
}
//�ּ� 1
//
ostream& operator<<(ostream& stream, Bag b) {
    cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
    for (int i = 0; i < b.Top(); i++) {
        stream << b.arr[i] << endl;
    }
    return stream;
}
//

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(Person* x) {
    arr[top] = x;
    cout << "SET�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
    top++;
    

    /*
    if (IsFull())
        Full();
    else {
        for (int i = 0; i < MaxSize; i++) {
            if (!(arr[i] == x)) {
                arr[top] = x;
                cout << "SET�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
                top++;
                return;
            }
            else {
                cout << "�ߺ��� �� �Դϴ�" << endl;
                return;
            }
        }
    }
    */
}

Person* Set::Delete() {
    //if (IsEmpty()) {
     //   Empty();
     //   return x;
    //}
    //int deletePos = top / 2;
    Person *x = arr[--top];
    //for (int index = deletePos; index < top; index++)
    //    arr[index] = arr[index + 1];
    //top--;
    return x;
}
//�ּ� 1

ostream& operator<<(ostream& stream, Set s) {
    cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
    for (int i = 0; i < s.Top(); i++) {
        stream << s.arr[i] << endl;
    }
    return stream;
}

int main() {
    Person* codings[20];//Person �������� �����ϴ� ���� �ذ� �ʿ� 
    Person* workStudents[10];
    Set s;
    int select;
    Person* p;
    Coder cx;
    while (1)
    {
   
        cout << "\n���� 1: Coder ��ü 10�� �Է°� ���, 2. PartTimeStudent ��ü 10�� �Է°� ���, 3: Coder��ü ����,4. partTimeStudents ��ü ����, 5. Bag �׽�Ʈ, 6. ����" << endl;
        cin >> select;

        switch (select) {
        case 1://1: Coder ��ü 10�� �Է°� ���
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
        case 2://2. PartTimeStudent ��ü 10�� �Է°� ���
            workStudents[0] = new PartTimeStudent(200.1, 3.4, "s001", "computer", "busan", "e901", "sales", "jeju", "23001", "hong");
            workStudents[1] = new PartTimeStudent(100.1, 2.4, "s002", "DB", "busan", "e801", "sales", "jeju", "23001", "hong");
            workStudents[2] = new PartTimeStudent(300.1, 3.4, "s003", "Java", "busan", "e001", "design", "jeju", "23001", "hong");
            workStudents[3] = new PartTimeStudent(20.1, 4.4, "s004", "���", "busan", "e091", "����", "jeju", "23001", "hong");
            workStudents[4] = new PartTimeStudent(255.1, 1.4, "s005", "����", "busan", "e081", "ȸ��", "jeju", "23001", "hong");
            workStudents[5] = new PartTimeStudent(400.1, 2.4, "s006", "�Ƿ�", "busan", "e301", "����", "jeju", "23001", "hong");
            workStudents[6] = new PartTimeStudent(900.1, 3.3, "s007", "����", "busan", "e501", "�Ǹ�", "jeju", "23001", "hong");
            workStudents[7] = new PartTimeStudent(800.1, 3.1, "s008", "ȭ��", "busan", "e801", "����", "jeju", "23001", "hong");
            workStudents[8] = new PartTimeStudent(2055.1, 3.3, "s009", "ȭ��", "busan", "e011", "����", "jeju", "23001", "hong");
            workStudents[9] = new PartTimeStudent(660.1, 3.8, "s010", "���", "busan", "e041", "����", "jeju", "23001", "hong");

            for (int i = 0; i < 10; i++)
            {
                Person* p = workStudents[i];
                PartTimeStudent* cp = dynamic_cast<PartTimeStudent*>(p);
                cout << (*cp) << endl;
            }
            break;

        case 3://3: Coder��ü ����(Dept �̸��� ����)�� ���
            for (int i = 0; i < 10; i++)
                for (int j = i + 1; j < 10; j++)
                {
                    Person* p = codings[i];
                    Person* q = codings[j];
                    Coder* cp = dynamic_cast<Coder*>(p);
                    Coder* cq = dynamic_cast<Coder*>(q);
                    int result = (*cp > * cq);
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
        case 4://4. partTimeStudents ��ü ����(eno > sid)�� ���
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
        case 5:
       
            //subclass ��ü�� ������ ����� �����ϵ��� �Ʒ� ���� ����
         
            for (int i = 0; i < 10; i++) {
                Person* p = workStudents[i];
                PartTimeStudent* cp = dynamic_cast<PartTimeStudent*>(p);
                cout << (*cp) << endl;
                s.Add(cp);
            }
              
            for (int i = 0; i < 5; i++)
            {
                Person *p = s.Delete();
                PartTimeStudent *pts = dynamic_cast<PartTimeStudent*>(p);
                pts->print();
               // cout << "Delete::" << s.Delete() << endl;//���� ���ε� ó���ϵ��� ����
            }
             break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}