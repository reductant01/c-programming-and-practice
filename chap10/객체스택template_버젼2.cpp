// ��ü ���� template
/*
* stack�� ������ ����� *data[50];�� �ϴ� ��� > int, float, double���� �������� �ʴ�
* 
*/
#include <iostream>
#include <string>
using namespace std;
class Person {
    string pid;
    string pname;
public:
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) {}
    friend ostream& operator<<(ostream&, Person& p);
};
class Student : public Person {
    string deptName;
public:
    Student(string pid, string pname, string deptName) :Person(pid, pname), deptName(deptName) {}
};
ostream& operator<<(ostream& os, Person& p) {
    cout << "|" << p.pid << "|" << p.pname << "|" << endl;
    return os;
}
template <class T>
class Stack {
    T *data[50];
    int nElements;
public:
    Stack() : nElements(0) {}//Person�� default �����ڰ� �ʿ��ϴ� 

    void Push(T *elem);
    T* Pop();
    int Number();
    int Empty();
};


template <class T>
void Stack <T>::Push(T *elem) {
    //if(T == int){}
    data[nElements] = elem;
    nElements++;
}

template <class T>
T* Stack <T>::Pop() {
    nElements--;
    return data[nElements];
}

template <class T>
int Stack <T>::Number() {
    return nElements;
}

template <class T>
int Stack <T>::Empty() {
    return (nElements == 0);
}


void main() {
    Stack <int> intStack;
    /*
    intStack.Push(50);
    intStack.Push(19);
    intStack.Push(3);
    intStack.Push(10);
    intStack.Push('aa');

    cout << "-----int type stack" << endl;
    while (!intStack.Empty()) {
        cout << intStack.Pop() << endl;
    }
    */
    Stack <double> doubleStack;
    /*
    doubleStack.Push(500.8);
    doubleStack.Push(1992.8);
    doubleStack.Push(33.8);
    doubleStack.Push(1024.8);

    cout << "-----double type stack" << endl;
    while (!doubleStack.Empty()) {
        cout << doubleStack.Pop() << endl;
    }
    */
    Stack <string> stringStack;

    stringStack.Push(new string("500"));
    stringStack.Push(new string("1992"));
    stringStack.Push(new string("33"));

    cout << "-----string type stack" << endl;
    while (!stringStack.Empty()) {
        cout << *stringStack.Pop() << endl;
    }
    Stack <Person> personStack;

    personStack.Push(new Person("p1", "hong"));
    personStack.Push(new Person("p2", "song"));
    personStack.Push(new Person("p3", "ong"));
    personStack.Push(new Person("p4", "han"));
    Person *p = new Person("p6", "unkown");
    personStack.Push(p);
    Student *q = new Student("p7", "Gam", "DB");
    personStack.Push(q);
    personStack.Push(new Student("p5", "kim", "com"));//void Stack <T>::Push(T elem) {
    cout << "-----string type stack" << endl;
    while (!personStack.Empty()) {
        cout << *personStack.Pop() << endl;
    }
    system("pause");
}

