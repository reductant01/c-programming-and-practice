
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Type>
class Bag
{
	template<class Type> //추가: 19.6.18
	friend ostream& operator<<(ostream&, Bag<Type>&);
public:
	Bag(int MaxSize = DefaultSize); // constructor
	virtual ~Bag(); // destructor

	virtual void Add(const Type&); // insert element into bag
	virtual Type* Delete(); // delete element from bag

	virtual bool IsFull();  // return TRUE if the bag is full; FALSE otherwise
	virtual bool IsEmpty(); // return TRUE if the bag is empty; FALSE otherwise
protected:
	virtual void Full(); //  action when bag is full
	virtual void Empty(); // action when bag is empty

	Type* array;
	int MaxSize; // size of array
	int top; // highest position in array that contains an element
};



template <class KeyType>
class Stack : public Bag<KeyType> {
	// objects: A finite ordered list with zero or more elements.
public:
	Stack(int MaxStackSize = DefaultSize);
	// Create an empty stack whose maximum size is \fIMaxStackSize\fR
	~Stack();
	bool IsFull();
	// if number of elements in the stack is equal to the maximum size of
	//   the stack, throw(FullStackError); otherwise, return FALSE (0)

	void Add(const KeyType& item);
	// if IsFull(), then StackFull(); else insert item into the top of the stack.

	bool IsEmpty();
	// if number of elements in the stack is equal to 0, throw(EmptyStackError) else return FALSE (0).

	KeyType* Delete();
	// if IsEmpty(), then StackEmpty(); else remove and return the topmost element of the stack
	bool IsEmpty();
	bool IsFull();
private:
	void Full();
	void Empty();

};

class Person {
private:
	char id[10];
	char name[20];
};
class Student : public Person {
private:
	char sid[10];
	char dept[10];
};
class Employee : public Person {
	char eid[10];
	char job[20];
};
ostream& operator << (ostream&, Person&);
class Student : public Person {

};
ostream& operator << (ostream&, Student&);
class Employee : public Person {

};
ostream& operator << (ostream&, Employee&);
int main() {
	Stack<Person> st;
	//st에 Student 객체, Employee 객체를 저장한다.
	/*
	Recording* R[20], item;

	R[0] = new Recording("LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[1] = new Recording("RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");
	*/
	for (int i = 0; i < 20; i++) {
		st.push();
	}
	for (int i = 0; i < 20; i++) {
		cout << st.pop();
	}
	system("pause");
	return 1;
}

