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

    // ���� binding�� ����ϴ� virtual �Լ�
    virtual void Print() {
        cout << "\n\tPerson::�� �̸��� " << name << endl;
    }
};

class Foreigner : public Person {
public:
    Foreigner(const string& n) : Person(n) { }

    void show() {
        cout << "\tForeigner::show() " << name << endl;
    }

    void Print() {
        // Foreigner�� ���� �̸��� ...
        cout << "\n\tForeigner::My name is " << name << endl;
    }
};

int main() {
    Person* man;
    Person* woman;

    // �ʱ�ȭ
    man = new Person("John");
    woman = new Foreigner("Paola");

    // �̸����� �μ��Ѵ�.
    cout << "\nPrints the name of the man:";
    man->Print();

    cout << "\nPrints the name of the woman (a foreigner):";
    woman->Print(); //Foreigner�� print����Ǵ°� Ȯ���ϱ� (print�� virtual�� �������� �����Ǿ��� �����̴�)

    cout << endl;
    man->show();
    woman->show(); //Person�� show�� ����Ǵ°� Ȯ���ϱ�, Person::show�� virtual�̾��ٸ� Foreigner::show�� ����Ǿ������̴�
    woman->Person::show();

    // ���� man�� class Person���� ������ class Foreigner��
    // �� ��ü�� ���� pointer�� ġȯ�ϴ� ���� �����ϴ�.
    man = new Foreigner("Mario");

    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:";
    man->Print(); //Foreigner�� print����Ǵ°� Ȯ���ϱ�
    man->show();
    woman->show();
    woman->Person::show();

    // �޸� ����
    delete man;
    delete woman;

    return 0;
}
