#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/*
* 예외처리를 위한 클래스 계층:
* TableEmpty <- EmptyException <- ExceptionError
* TableOverflow <- OverflowException <- ExceptionError
* 예외 발생시에 catch 문에서 해당 예외클래스명을 출력: virtual print()
*/

class ExceptionError {
public:
	virtual void Print() const = 0;
};

class EmptyException : public ExceptionError {
public:
	virtual void Print() const override {
		cout << "empty 예외 발생" << endl;
	}
};

class TableEmpty : public EmptyException {
public:
	void Print() const override {
		cout << "TableEmpty 예외 발생" << endl;
	}
};

class OverflowException : public ExceptionError {
public:
	virtual void Print() const override {
		cout << "overflow 예외 발생" << endl;
	}
};

class TableOverflow : public OverflowException {
public:
	void Print() const override {
		cout << "TableOverflow 예외 발생" << endl;
	}
};


/*
* 클래스 계층의 데이터 멤버는 모두 private이다
* 모든 클래스 -> virtual print() => 데이터 멤버를 출력
* 각 객체의 출력 형태 =>> name="***" city="***"
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
* 새로운 레코드 삽입, 이름이 주어지면 해당 레코드 삭제-> 삭제시 true, 없으면 false
* 이름이 주어지면 해당 레코드 검색 => no 출력 함수
* => 예외 throw ==>> isEmpty(), isFull() 사용
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

//클래스별로 2개 객체를 초기화

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
	* 12개의 person 객체를 초기화하는 배열을 만든다
	* 레코드 테이블은 최대 7이다
	* 객체 배열을 레코드 테이블에 저장한 후에 search, print한 후에 delete하는 테스트를 한 다음에 다시 add를 반복한다.
	* add시에는 레코드 테이블에 저장할 수 있을 때까지 반복한다.
	* try block: 예외  throw
	* catch block => 예외 발생 클래스 이름 출력
	*/

	const int numPeople = 12;
	const int tableCapacity = 7;

	RecordTable<Person> table(tableCapacity);
	Person* people[numPeople];
	makePeople(people, numPeople);

	int nextPerson = 0;
	int select;

	while (true) {
		cout << "\n선택 1: add, 2: delete, 3: search, 4: print, 5: 종료" << endl;
		cin >> select;

		switch (select) {
		case 1: // Add - 배열의 객체를 Add 반복
			try {
				while (true) {
					if (table.IsFull()) {
						throw TableOverflow(); // 테이블이 가득 찬 경우 예외 발생
					}
					table.Add(*people[nextPerson]);
					nextPerson = (nextPerson + 1) % numPeople; // nextPerson이 배열의 끝에 도달하면 처음으로 돌아가도록 조정
				}
			}
			catch (TableOverflow & ex) {
				ex.Print();
			}
			break;

		case 2: // Delete - 이름이 주어진 객체 삭제
			try {
				string name;
				cout << "삭제할 이름을 입력하세요: ";
				cin >> name;
				Person* removed = table.Delete(name);
				if (removed != nullptr) {
					cout << name << " 삭제 완료" << endl;
					removed->Print();
				}
				else {
					cout << name << " 을 찾을 수 없습니다" << endl;
				}
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;


		case 3: // Search - 이름이 주어진 객체 검색
			try {
				string name;
				cout << "검색할 이름을 입력하세요: ";
				cin >> name;
				Person* p = table.Search(name);
				p->Print();
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;

		case 4: // Print - 저장된 객체 모두 출력
			try {
				table.Print();
			}
			catch (TableEmpty & ex) {
				ex.Print();
			}
			break;

		case 5: // 종료
			return 0;

		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}

	return 0;

}
