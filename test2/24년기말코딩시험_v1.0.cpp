#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/*
* ����ó���� ���� Ŭ���� ����:
* TableEmpty <- EmptyException <- ExceptionError
* TableOverflow <- OverflowException <- ExceptionError
* ���� �߻��ÿ� catch ������ �ش� ����Ŭ�������� ���: virtual print()
*/

class ExceptionError {
public:
	virtual void Print() const = 0;
};

class EmptyException : public ExceptionError {
public:
	virtual void Print() const override {
		cout << "empty ���� �߻�" << endl;
	}
};

class TableEmpty : public EmptyException {
public:
	void Print() const override {
		cout << "TableEmpty ���� �߻�" << endl;
	}
};

class OverflowException : public ExceptionError {
public:
	virtual void Print() const override {
		cout << "overflow ���� �߻�" << endl;
	}
};

class TableOverflow : public OverflowException {
public:
	void Print() const override {
		cout << "TableOverflow ���� �߻�" << endl;
	}
};


/*
* Ŭ���� ������ ������ ����� ��� private�̴�
* ��� Ŭ���� -> virtual print() => ������ ����� ���
* �� ��ü�� ��� ���� =>> name="***" city="***"
* Person(string name) -> Employee(string company, int salary) -> Manager(string role) -> JobStudent(int workHour)
* Person -> Student(	string school, double gpa) -> GraduateStudent(string project) -> JobStudent(int workHour)

*/

class Person {
private:
	string name;

public:
	Person(const string& name) : name(name) {}
	virtual void Print() const {
		cout << "name=\"" << name << "\"";
	}
	string getName() const { return name; }
};

class Employee : public Person {
private:
	string company;
	int salary;

public:
	Employee(const string& name, const string& company, int salary)
		: Person(name), company(company), salary(salary) {}

	void Print() const override {
		Person::Print();
		cout << " company=\"" << company << "\" salary=\"" << salary << "\"" << endl;
	}
};

class Manager : public Employee {
private:
	string role;

public:
	Manager(const string& name, const string& company, int salary, const string& role)
		: Employee(name, company, salary), role(role) {}

	void Print() const override {
		Employee::Print();
		cout << " role=\"" << role << "\"" << endl;
	}
};

class JobStudent : public Manager {
private:
	int workHour;

public:
	JobStudent(const string& name, const string& company, int salary, const string& role, int workHour)
		: Manager(name, company, salary, role), workHour(workHour) {}

	void Print() const override {
		Manager::Print();
		cout << " workHour=\"" << workHour << "\"" << endl;
	}
};

class Student : public Person {
private:
	string school;
	double gpa;

public:
	Student(const string& name, const string& school, double gpa)
		: Person(name), school(school), gpa(gpa) {}

	void Print() const override {
		Person::Print();
		cout << " school=\"" << school << "\" gpa=\"" << gpa << "\"" << endl;
	}
};

class GraduateStudent : public Student {
private:
	string project;

public:
	GraduateStudent(const string& name, const string& school, double gpa, const string& project)
		: Student(name, school, gpa), project(project) {}

	void Print() const override {
		Student::Print();
		cout << " project=\"" << project << "\"" << endl;
	}
};

class JobStudentGS : public GraduateStudent {
private:
	int workHour;

public:
	JobStudentGS(const string& name, const string& school, double gpa, const string& project, int workHour)
		: GraduateStudent(name, school, gpa, project), workHour(workHour) {}

	void Print() const override {
		GraduateStudent::Print();
		cout << " workHour=\"" << workHour << "\"" << endl;
	}
};

/*
* ���ο� ���ڵ� ����, �̸��� �־����� �ش� ���ڵ� ����-> ������ true, ������ false
* �̸��� �־����� �ش� ���ڵ� �˻� => no ��� �Լ�
* => ���� throw ==>> isEmpty(), isFull() ���
* STL => X
*/

template <class T>
class RecordTable {
private:
	int top;
	T** data;
	int capacity;

public:
	RecordTable(int capacity) : capacity(capacity), top(-1) {
		data = new T * [capacity];
	}

	~RecordTable() {
		delete[] data;
	}

	void Add(T& object) {
		if (!IsFull()) {
			data[++top] = &object;
		}
		else
			throw TableOverflow();
	}

	T* Delete(const string& name) {
		for (int i = 0; i <= top; ++i) {
			if (data[i]->getName() == name) {
				T* removed = data[i];
				for (int j = i; j < top; ++j) {
					data[j] = data[j + 1];
				}
				--top;
				return removed;
			}
		}
		return nullptr;
	}


	T* Search(const string& name) {
		for (int i = 0; i <= top; ++i) {
			if (data[i]->getName() == name) {
				return data[i];
			}
		}
		throw TableEmpty();
	}

	void Print() const {
		if (IsEmpty()) {
			throw TableEmpty();
		}
		for (int i = 0; i <= top; ++i) {
			data[i]->Print();
		}
	}


	bool IsFull() const {
		return top >= capacity - 1;
	}

	bool IsEmpty() const {
		return top == -1;
	}
};

//Ŭ�������� 2�� ��ü�� �ʱ�ȭ

void makePeople(Person* people[], int numPeople) {
	people[0] = new Employee("0", "CompanyA", 50000);
	people[1] = new Employee("1", "CompanyB", 60000);
	people[2] = new Manager("2", "CompanyC", 70000, "Sales");
	people[3] = new Manager("3", "CompanyD", 80000, "HR");
	people[4] = new JobStudent("4", "CompanyE", 90000, "IT", 20);
	people[5] = new JobStudent("5", "CompanyF", 100000, "Marketing", 30);
	people[6] = new Student("6", "SchoolA", 3.8);
	people[7] = new Student("7", "SchoolB", 3.6);
	people[8] = new GraduateStudent("8", "SchoolC", 3.9, "AI Project");
	people[9] = new GraduateStudent("9", "SchoolD", 4.0, "ML Project");
	people[10] = new JobStudentGS("10", "SchoolE", 3.7, "Robotics Project", 25);
	people[11] = new JobStudentGS("11", "SchoolF", 3.5, "Data Science Project", 15);
}

int main() {
	/*
	* 12���� person ��ü�� �ʱ�ȭ�ϴ� �迭�� �����
	* ���ڵ� ���̺��� �ִ� 7�̴�
	* ��ü �迭�� ���ڵ� ���̺� ������ �Ŀ� search, print�� �Ŀ� delete�ϴ� �׽�Ʈ�� �� ������ �ٽ� add�� �ݺ��Ѵ�.
	* add�ÿ��� ���ڵ� ���̺� ������ �� ���� ������ �ݺ��Ѵ�.
	* try block: ����  throw
	* catch block => ���� �߻� Ŭ���� �̸� ���
	*/

	const int numPeople = 12;
	const int tableCapacity = 7;

	RecordTable<Person> table(tableCapacity);
	Person* people[numPeople];
	makePeople(people, numPeople);

	int nextPerson = 0;
	int select;

	while (true) {
		cout << "\n���� 1: add, 2: delete, 3: search, 4: print, 5: ����" << endl;
		cin >> select;

		switch (select) {
		case 1: // Add - �迭�� ��ü�� Add �ݺ�
			try {
				while (true) {
					if (table.IsFull()) {
						throw TableOverflow(); // ���̺��� ���� �� ��� ���� �߻�
					}
					table.Add(*people[nextPerson]);
					nextPerson = (nextPerson + 1) % numPeople; // nextPerson�� �迭�� ���� �����ϸ� ó������ ���ư����� ����
				}
			}
			catch (TableOverflow & ex) {
				ex.Print();
			}
			break;

		case 2: // Delete - �̸��� �־��� ��ü ����
			try {
				string name;
				cout << "������ �̸��� �Է��ϼ���: ";
				cin >> name;
				Person* removed = table.Delete(name);
				if (removed != nullptr) {
					cout << name << " ���� �Ϸ�" << endl;
					removed->Print();
				}
				else {
					cout << name << " �� ã�� �� �����ϴ�" << endl;
				}
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;


		case 3: // Search - �̸��� �־��� ��ü �˻�
			try {
				string name;
				cout << "�˻��� �̸��� �Է��ϼ���: ";
				cin >> name;
				Person* p = table.Search(name);
				p->Print();
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;

		case 4: // Print - ����� ��ü ��� ���
			try {
				table.Print();
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;

		case 5: // ����
			return 0;

		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}

	return 0;

}
