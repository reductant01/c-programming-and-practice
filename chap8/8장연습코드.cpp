#define DefaultSize 10
#include <iostream>
//2018�� �ǽ� �ڵ�
using namespace std;
class Person;
class Bag {
public:
	Bag(int MaxSize = DefaultSize); //������
	~Bag(); // �Ҹ���
	virtual void Add(Person&); // ���� �ϳ��� bag�� ����
	virtual Person& Delete(Person&); //bag���� ���� �ϳ��� ����
	bool IsFull();
	// bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
	bool IsEmpty();
	// bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
	int Top();
	friend ostream& operator<< (ostream& stream, Bag b);
protected:
	void Full(); // bag�� ��ȭ������ ���� ��ġ
	void Empty(); // bag�� ���� ������ ���� ��ġ
	Person *arr;
	int MaxSize; // �迭�� ũ��
	int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
};

class Set : public Bag {
public:
	Set(int MaxSize = DefaultSize);      //������
	~Set();      // �Ҹ���
				 //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
	void Add(int);
	int *Delete(int&);
	friend ostream& operator<< (ostream& stream, Set s);
};
class Person {
protected:
	String name;
public:
	Person(char* n) : name(n)
	{ }
	// virtual void Print (){
	void Print() {
		cout << "Person::�� �̸��� " << name << endl;
	}
};

class Foreigner : public Person {
public:
	Foreigner(char* n) : Person(n)
	{ }

	void Print() {
		Person::Print();
		cout << "fid is " << fid << endl;
	}
private:
	int fid;
};

class Student : public Person {
public:
	Student(char * n) : Person(n)
	{ }

	void Print() {
		Person::Print();
		cout << "sid is " << sid << endl;
	}
private:
	int sid;
};

Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
	arr = new int[MaxSize];
	top = 0;
}

Bag::~Bag() {
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

void Bag::Add(Person& x) {
	if (IsFull())
		Full();
	else {
		arr[top] = x;
		cout << "BAG�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
		top++;
	}
}

Person& Bag::Delete(Person& x) {
	if (IsEmpty()) {
		Empty();
		return x;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index<top; index++)
		arr[index] = arr[index + 1];
	top--;
	return x;
}

int Bag::Top() {
	return top;
}
//�ּ� 1
//
ostream& operator<<(ostream& stream, Bag b) {
	cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
	for (int i = 0; i<b.Top(); i++) {
		stream << b.arr[i] << endl;
	}
	return stream;
}
//

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(Person x) {
	if (IsFull())
		Full();
	else {
		for (int i = 0; i<MaxSize; i++) {
			if (arr[i] != x) {
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
}

Person& Set::Delete(Person& x) {
	if (IsEmpty()) {
		Empty();
		return 0;
	}
	int deletePos = top / 2;
	x = arr[deletePos];
	for (int index = deletePos; index<top; index++)
		arr[index] = arr[index + 1];
	top--;
	return x;
}
//�ּ� 1

ostream& operator<<(ostream& stream, Set s) {
	cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
	for (int i = 0; i<s.Top(); i++) {
		stream << s.arr[i] << endl;
	}
	return stream;
}

void main() {
	Person* p[10];
	Set s;
	p[0] = new Foreigner("Tom");
	p[1] = new Student("Thomas");
	p[2] = new Student("Ashley");
	p[3] = new Student("Ryan");
	p[4] = new Student("Daniel");
	p[5] = new Foreigner("Matthew");
	p[6] = new Foreigner("Samuel");
	p[7] = new Foreigner("William");
	p[8] = new Person("Sophie");
	p[9] = new Student("Jessica");

	for (int i = 0; i < 10; i++)
		s.Add(p[i]);
	cout << s;
	for (int i = 0; i < 10; i++)
	{
		p[i]->Print();
		s.Delete(p[i]);
	}
	system("pause");
}