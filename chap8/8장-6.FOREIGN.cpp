#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
public:
    Person(const string& n) : name(n) { }

    void show() {
        cout << "Person::show() " << name << endl;
    }

    // 동적 binding을 사용하는 virtual 함수
    virtual void Print() {
        cout << "\n\tPerson::내 이름은 " << name << endl;
    }
};

class Foreigner : public Person {
public:
    Foreigner(const string& n) : Person(n) { }

    void show() {
        cout << "\tForeigner::show() " << name << endl;
    }

    void Print() {
        // Foreigner을 위한 이름은 ...
        cout << "\n\tForeigner::My name is " << name << endl;
    }
};

int main() {
    Person* man;
    Person* woman;

    // 초기화
    man = new Person("John");
    woman = new Foreigner("Paola");

    // 이름들을 인쇄한다.
    cout << "\nPrints the name of the man:";
    man->Print();

    cout << "\nPrints the name of the woman (a foreigner):";
    woman->Print(); //Foreigner의 print실행되는것 확인하기 (print가 virtual의 동적으로 설정되었기 때문이다)

    cout << endl;
    man->show();
    woman->show(); //Person의 show가 실행되는것 확인하기, Person::show가 virtual이었다면 Foreigner::show가 실행되었을것이다
    woman->Person::show();

    // 변수 man에 class Person에서 유도된 class Foreigner의
    // 한 객체에 대한 pointer를 치환하는 것은 가능하다.
    man = new Foreigner("Mario");

    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:";
    man->Print(); //Foreigner의 print실행되는것 확인하기
    man->show();
    woman->show();
    woman->Person::show();

    // 메모리 해제
    delete man;
    delete woman;

    return 0;
}
