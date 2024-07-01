//7장 클래스 상속 과제
#include <iostream>
#include <string>
using namespace std;
class Dept {
private:
    string dname;
    //char* dname;
    string city;
public:
    Dept(string, string);
    //❤️나중에 크기 비교할 때 getter쓰지 말고 operator 오버로딩을 사용할 것.
    int operator > (Dept& d) {
       // if ((this->dname)./*을 해보면 list가 나오는데 string을 이용해서 쓸 수 있는 function이 나옴.아마 compare함수가 있을 것.*/ > d.dname)
        return (this->dname.compare(d.dname));
    }
    ~Dept() {
        //delete[] dname;
    }
    friend ostream& operator<<(ostream&, Dept&);
};

Dept::Dept(string dname, string city): dname(dname), city(city) {
    //this->dname = new char[dname.length() + 1];
   //strcpy(this->dname, dname.c_str());
   // this->city = city;
}

class Person {
private:
    string pid;
    string pname;
public:
    Person() {}
    Person(string, string);
    friend ostream& operator<<(ostream&, Person&);
    //friend istream& operator>>(istream&, Person&);
};

Person::Person(string pid, string pname) {
    this->pid = pid;
    this->pname = pname;
}

ostream& operator<<(ostream& os, Person& p) {
    os << "id : " << p.pid << "이름 : " << p.pname;
    return os;
}

class Employee : virtual public Person {
private:
    string eno;
    Dept* dname;//❤️이건 포인터라서 객체를 만들어야 함...
protected:
    void MoveDept(Dept* dname);
public:
    Employee(string pid, string pname, string eid, string dept, string city) : Person(pid, pname), eno(eid) {
        //  Person(pid, pname);//❤️이걸 지우려면 : 뒤에 Person(pid, pname)을 기입. 콜론 뒤에 생성자가 가장 먼저 와야 함.
        dname = new Dept(dept, city);//❤️파라미터는 거기에 관련된 걸 넣으면 됨. 
    }
    friend ostream& operator<<(ostream&, Employee&);
    ~Employee() {//❤️new쓰면 소멸자는 바로 바로 써주자.
        delete dname;
    }
    int operator > (Employee&);
};

ostream& operator<<(ostream& os, Employee& emp) {
    os << "사원번호 = " << emp.eno << *(emp.dname) << (Person)emp;//❤️멤버변수가 아니기 때문에 eno가 아니라 emp.eno 이다. 그리고 마지막으로 Person도 출력을 해야하므로 Person으로 typecasting하기.
    return os;
}

class Student : virtual public Person {
private:
    string sid;
    Dept* dname;
};
class Coder : public Employee {
private:
    string language;
    //char* language;
    double workYears;
public:
    //Coder(char* language, double workYears, char* eno, Dept* dname, string pid, string pname);
    Coder(string pid, string pname, string eid, string deptname, string city, string language, double year) :Employee(pid, pname, eid, deptname, city), lanuage(language), workYears(year) {
        //this->language = new char[language.length() + 1];
       // strcpy(this->language, language.c_str());
    }
    int operator > (Coder& cd) {
        if (Employee(*this) > (Employee)cd) return 1; //또 Employee가서 > 오버로딩하고..!
    }
    ~Coder() {
      //  delete[] language;
    }
    friend ostream& operator<<(ostream&, Coder&);
};

ostream& operator<<(ostream& os, Coder& cd) {
    os << "코딩 언어 = " << cd.language << "코딩 경력 = " << cd.workYears << (Employee)cd << endl;//❤️Employee의 객체이므로 Employee의 오버로딩으로 넘어감.
    return os;
}
class PartTimeStudent : private Employee, private Student {
private:
    double salary;
    double grade;
public:
    PartTimeStudent(double sal, double gd) : Person(), salary(sal), grade(gd) {}
};
int main() {
    while (1)
    {
        Coder* codings[10]; //codings 안에는 Coder를 가리키는 포인터들이 즐비
        PartTimeStudent* workStudents[10]; //workStudents 안에는 PartTimeStudent를 가리키는 포인터들이 즐비

        int select;
        //생성자 사용에 의한 입력은 new Coder("이름", ...)으로 값을 지정하여 입력
        //객체 출력은 cout<<*codings[i]만을 사용한다.
        cout << "\n선택 1: Coder 객체 10개 입력과 출력, 2. PartTimeStudent 객체 10개 입력과 출력, 3: Coder객체 정렬(Dept 이름> 도시 순서로 정렬)과 출력,4. partTimeStudents 객체 정렬(eno > sid 순서로 정렬)과 출력, 5. 종료" << endl;

        cin >> select;
        switch (select) {
        case 1://1: Coder 객체 10개 입력과 출력
            codings[0] = new Coder("p1", "hong", "E1", "computer", "busan", "C++", 1.6);//❤️이렇게 해야 함. 이전 과제에서처럼 cin >> 말고
            codings[1] = new Coder("p2", "kim", "E2", "math", "seoul", "C++", 2.4);
            codings[2] = new Coder("p3", "lim", "E3", "english", "newyork", "C++", 0.8);
            codings[3] = new Coder("p4", "lee", "E4", "french", "cicago", "C++", 1.2);
            codings[4] = new Coder("p5", "park", "E5", "spanish", "paris", "C++", 2.3);
            codings[5] = new Coder("p6", "cho", "E6", "korean", "london", "C++", 5.7);
            codings[6] = new Coder("p7", "baek", "E7", "operate research", "daegu", "C++", 1.1);
            codings[7] = new Coder("p8", "kang", "E8", "statistic", "tokyo", "C++", 0.1);
            codings[8] = new Coder("p9", "joo", "E9", "algebra", "moscow", "C++", 4.2);
            codings[9] = new Coder("p10", "yu", "E10", "data structure", "roma", "C++", 2.8);
            for (int i = 0; i < 10; i++) {
                cout << *codings[i];
            }
            break;
            /*
            case 2://2. PartTimeStudent 객체 10개 입력과 출력
                workStudents[0] = new PartTimeStudent(); //case 1처럼 좀 노가다를 해서 대입해야 함.
                for (int i = 0; i < 10; i++) {
                       cout << workStudents[i];
               }
                break;

            case 3://3: Coder객체 정렬(Dept 이름과 도시)과 출력
                for(int i = 0; i < 10; i++)
                    for(int j = i + 1; j < 10; j++)
                        if(codings[i] > codings[j]) swap(codings, i, j)//swap함수도 만들어야 함. codings를 비교할 수 있는 오버로딩도 만들어야 해. 저기 들어가 있는 놈이 coder니까 coder에 들어가서 하면 됨.
                break;
            case 4://4. partTimeStudents 객체 정렬(eno > sid)과 출력

                break;

            default:
                exit(0);
                break;
            }
            */
        }
        system("pause");
        return 1;
    }

    /*
    이 문제에서 다중 상속을 사용하는데 문제가 발생할 수 있다.PartTimeStudent에서 Employee 클래스와 Student 클래스에서 가져오므로 Person의 멤버 변수인 pid와 pname이 중복될 수 있다.
        해결하기 위해선 Employee나 Student의 클래스에서 Person을 상속받을 때 derivation 유형 앞에 virtual이라는 키워드를 붙여주거나, 아니면 둘 다 virtual을 붙이고
        PartTimeStudent의 생성자를 정의할 때 Person()을 붙여주기.(사진 참고)
        */