#include <iostream>
using namespace std;

class Person {
protected:
    const char* name;
public:
    Person(const char* n) : name(n) {}
    virtual void Print() {
        cout << "\tPerson::Print(): name is " << name << endl;
    }
    virtual void Print(const char* ch) {
        cout << "\tPerson::Print(const char* ch): name is " << ch << endl;
    }
    void Display() {
        cout << "Person::Display(): name = " << name << endl;
    }
};

class Foreigner : public Person {
    const char* nation;
public:
    Foreigner(const char* name, const char* country) : Person(name), nation(country) {}
    virtual void Print() {
        cout << "\tForeigner::virtual_Print():name = " << name << endl;
    }
    void Print(const char* ch) {
        Person::Print(ch);
        cout << "\tForeigner::Print(const char* ch): name = " << ch << endl;
    }
    virtual void show() {
        cout << "\tForeigner::virtual_Show(): name = " << name << endl;
    }
    virtual void Display() {
        cout << "Foreigner::Display(): nation = " << nation << endl;
    }
};

class ChinaForeigner : public Foreigner {
    int level;
public:
    ChinaForeigner(const char* n, const char* country, int level) : Foreigner(n, country), level(level) {}
    void Print() {
        cout << "\tChinaForeigner::Print(): name - " << name << endl;
    }
    void show() {
        cout << "\tChinaForeigner::virtual_Show(): level = " << level << endl;
    }
    void Display() {
        cout << "ChinaForeigner::Display(): level = " << level << endl;
    }
};

int main() {
    Person* wp;
    Person* wf;
    Person* wc;
    Foreigner fp("hong", "busan");

    wp = new Person("John");
    wf = new Foreigner("elintoo", "Korea");
    wc = new ChinaForeigner("chailyn", "China", 2);
    fp.Print(); // 참조변수가 아니므로 정적 바인딩한다 
    cout << "Prints the name : " << endl;
    wp->Print();
    wf->Print();
    wc->Print();
    wc->Person::Print();
    cout << "After wp = wf;" << endl;
    wp = wf;
    wp->Print();
    wp->Display();
    cout << "After wp = wc;" << endl;
    wp = wc;
    wp->Print();
    wf->Print("Sera");
    wc->Print("Sera");
    cout << "wp = new Foreigner(Mario);" << endl;
    wp = new Foreigner("Mario", "France");
    cout << endl << "Re-prints the name of the man after the new assignment:" << endl;
    wp->Print();
    Foreigner* foreigner;
    foreigner = new ChinaForeigner("Hong", "china", 1);
    foreigner->Display();

    delete wp;
    delete wf;
    delete wc;
    delete foreigner;

    return 0;
}
