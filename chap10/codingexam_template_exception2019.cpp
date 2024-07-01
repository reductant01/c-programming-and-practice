//coding exam : chapter 10-11, 19.6.18
//학번:
//이름:
//Github ID:
#include <iostream>
#include <stdlib.h>

using namespace std;
const int DefaultSize = 4;

class String {
public:
	//default constructor
	String();
	//copy constructor
	String(const String&);
	//create from C string
	String(const char*);
	//destructor
	~String();
	//assignment
	String& operator = (const String&);
	//less than
	int operator < (const String &)const;
	//greater than
	int operator > (const String &)const;
	//less than or equal to
	int operator <= (const String &)const;
	//greater than or equal to
	int operator >= (const String &)const;
	//inequality
	int operator != (const String &) const;
	//equality
	int operator == (const String &) const;
	//return a copy of string
	char * str() const;
	//conversion to char*
	operator char* ();
protected:
	char * string;
	unsigned int MaxLength;
	friend ostream & operator << (ostream & stream, String & str);
};

ostream & operator << (ostream & stream, String & str);

inline ostream & operator << (ostream & stream, String & str) {
	stream << str.string; return stream;
}
inline int String::operator > (const String& str) const {
	return !(*this <= str);
}
inline int String::operator >= (const String& str) const {
	return !(*this < str);
}
inline int String::operator != (const String& str) const {
	return !(*this == str);
}
String::String() {
	string = new char[20];
	MaxLength = 0;
}
// copy constructor
String::String(const String& str) {
	string = new char[strlen(str.string) + 1];
	strcpy(string, str.string);
	MaxLength = strlen(string);
}
// create from C string
String::String(const char * str) {
	string = new char[strlen(str) + 1];
	strcpy(string, str);
	MaxLength = strlen(string);
}
String::~String() {
	if (string != 0) delete string;
	MaxLength = 0;
	string = 0;
}

String::operator char * () {
	cout << "operator char*():: " << string << endl;
	return string;
}

//assignment
String & String::operator = (const String & str) {
	if (strlen(str.string) >= MaxLength) {
		delete string;
		string = new char[strlen(str.string) + 1];
		strcpy(string, str.string);
		MaxLength = strlen(string);
	}
	cout << "operator = () is called" << "::string = " << string << endl;
	strcpy(string, str.string);
	return *this;
}
int String::operator < (const String & str) const {
	// less than, lexicographic
	return strcmp(string, str.string) < 0;
}
int String::operator <= (const String & str)const {
	return strcmp(string, str.string) <= 0;
}
int String::operator == (const String & str)const {
	return strcmp(string, str.string) <= 0;
}
// return a copy of the string
char * String::str() const {
	return string;
}

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

	Type *array;
	int MaxSize; // size of array
	int top; // highest position in array that contains an element
};

template <class Type>
Bag<Type>::Bag(int MaxBagSize) : MaxSize(MaxBagSize)
{
	array = new Type[MaxSize];
	top = -1;
}

template <class Type>
Bag<Type>::~Bag()
{
	delete[] array;
}

template <class Type>
inline bool Bag<Type>::IsFull()
{
	if (top == MaxSize - 1) return TRUE;
	else return FALSE;
}

template <class Type>
inline bool Bag<Type>::IsEmpty()
{
	if (top == -1) return TRUE;
	else return FALSE;
}

template <class Type>
inline void Bag<Type>::Full()
{
	throw(FullBagError);
}

template <class Type>
inline void Bag<Type>::Empty()
{
	throw(EmptyBagError);
}

template <class Type>
void Bag<Type>::Add(const Type& x)
{
	if (IsFull()) Full();
	else array[++top] = x;
}

template <class Type>
Type* Bag<Type>::Delete()
{
	Type x;
	if (IsEmpty()) { Empty(); return 0; }
	int deletePos = top / 2;
	x = array[deletePos];
	for (int index = deletePos; index < top; index++)
		array[index] = array[index + 1];   //compact upper half of array
	top--;
	return &x;
}


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

template <class KeyType>
Stack<KeyType>::Stack(int MaxStackSize) : MaxSize(MaxStackSize)
{
	stack = new KeyType[MaxSize];
	top = -1;
}

template <class KeyType>
inline bool  Stack<KeyType>::IsFull()
{
	if (top == MaxSize - 1) return TRUE;
	else return FALSE;
}

template <class KeyType>
inline bool  Stack<KeyType>::IsEmpty()
{
	if (top == -1) return TRUE;
	else return FALSE;
}

template <class KeyType>
void Stack<KeyType>::Add(const KeyType& x)
// add x to the stack
{
	if (IsFull()) StackFull();
	if (IsDuplicate()) StackDuplicate();//coding is required
	else stack[++top] = x;
}

template <class KeyType>
KeyType* Stack<KeyType>::Delete()
// remove and return top element from stack
{
	if (IsEmpty()) { StackEmpty(); return 0; }
	x = stack[top--];
	return &x;
}
template <class Type>
inline void Stack<Type>::Full()
{
	throw(FullStackError);
}

template <class Type>
inline void Stack<Type>::Empty()
{
	throw(EmptyStackError);
}
IsDuplicate()
{
	//	int operator == (const String &) const; 사용할 것
	//coding is required
}
StackDuplicate() {
	//coding is required
	throw(DuplicateStackError);
}
class SizeError {
public:
	virtual void ErrorPrint() = 0;
};
class BagSizeError : public SizeError {
	void ErrorPrint() {
		cout << "Size Error in the Bag" << endl;
	}
};
class EmptyBagError : public BagSizeError {
	void ErrorPrint() {
		cout << "Empty Error in the Bag" << endl;
	}
};
class FullBagError : public BagSizeError {
	void ErrorPrint() {
		cout << "Full Error in the Bag" << endl;
	}
};
class StackSizeError : public SizeError {
	void ErrorPrint() {
		cout << "Size Error in the Stack" << endl;
	}
};
class EmptyStackError : public StackSizeError {
	void ErrorPrint() {
		cout << "Empty Error in the Stack" << endl;
	}
};
class FullStackError : public StackSizeError {
	void ErrorPrint() {
		cout << "Full Error in the Stack" << endl;
	}
};
class DuplicateStackError : public StackSizeError {
	// coding is required
};
int main() {
	Stack<String> sx;
	Bag<String> bx;
	int act;
	cout << "1. Bag, 2. Stack, 0. Exit" << endl;
	cin >> act;
	while (!act)
	{
		if (act == 1) //Bag
		{
			cout << " The bag is ";
			cout << bx << endl;
			try {
				int modeBagAct;
				//random number
				if (randomNumber == 0) {//add to Bag
					cout << "input to string" << endl;
					cin >> st;
					bx.Add(st);
				}
				else {//delete from Bag
					cout << "Output from Bag" << endl;
					st = bx.Delete();
					cout << "Output string is " << st << endl;			
				}
			}
			catch (BagSizeError &error) {
				error.ErrorPrint();
			}
		}
		else //Stack
		{
			cout << " The Stack is ";
			cout << sx << endl;
			try {
				int modeStackAct;
				//random number
				if (randomNumber == 0) {//add to Stack
					cout << "input to string" << endl;
					cin >> st;
					sx.Add(st);
				}
				else {//delete from Stack
					cout << "Output from Stack" << endl;
					st = bx.Delete();
					cout << "Output string is " << st << endl;
				}
			}
			catch (StackSizeError &error) {
				error.ErrorPrint();
			}
		}
		cout << "1. Bag, 2. Stack, 0. Exit" << endl;
		cin >> act;
	}
	system("pause");
	return 1;
}
//coding 시험 취지
/*
template <class T>
class Stack: public Set<t>;
push(), pop()을 template function으로 코딩하는 시험
stack full -> throw
stack empty -> throw
stack push(item) 중복 발생 -> throw
*/