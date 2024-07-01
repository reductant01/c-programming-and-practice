11/*
* 클래스 상속, template, 예외처리 구현
*/
#include <iostream>
#include <ctime>
using namespace std;

class ExceptionError {
public:
	virtual void Print() = 0;
};

class OverflowException : public ExceptionError {
public:
	void Print() {
		cout << "overflow 예외 발생" << endl;
	}
};

class BagOverflowException : public OverflowException {
public:
	void Print() {
		cout << "bag overflow 예외 발생" << endl;
	}
};

class StackOverflowException : public OverflowException {
public:
	void Print() {
		cout << "stack overflow 예외 발생" << endl;
	}
};

class EmptyException : public ExceptionError {
public:
	void Print() {
		cout << "empty 예외 발생" << endl;
	}
};

class BagEmptyException : public ExceptionError {
public:
	void Print() {
		cout << "Bag Empty  예외 발생" << endl;
	}
};

class StackEmptyException : public ExceptionError {
public:
	void Print() {
		cout << "Stack Empty  예외 발생" << endl;
	}
};

class Vehicles {
protected:
	string color;
	float weight;
	float engine_capacity;
	float price;

public:
	Vehicles(const string& c, float w, float e, float p)
		: color(c), weight(w), engine_capacity(e), price(p) {}

	virtual void show() {
		std::cout << "Color: " << color << ", Weight: " << weight
			<< ", Engine Capacity: " << engine_capacity << ", Price: " << price << endl;
	}

	string getColor() const { return color; }
};

class Cars : virtual public Vehicles {
protected:
	int passengers;
public:
	Cars(const string& c, float w, float e, float p, int pass)
		: Vehicles(c, w, e, p), passengers(pass) {}

	virtual void show() override {
		Vehicles::show();
		std::cout << "  , Passengers: " << passengers << endl;
	}
};

class Trucks : virtual public Vehicles {
protected:
	float cargo_capacity;
public:
	Trucks(const string& color, float weight, float engine_capacity, float price, float cargo_capacity)
		: Vehicles(color, weight, engine_capacity, price), cargo_capacity(cargo_capacity) {}

	virtual void show() override {
		Vehicles::show();
		std::cout << "  , Cargo Capacity: " << cargo_capacity << endl;
	}
};

class Motorcycles : public Vehicles {
protected:
	float max_speed;
public:
	Motorcycles(const string& color, float weight, float engine_capacity, float price, float max_speed)
		: Vehicles(color, weight, engine_capacity, price), max_speed(max_speed) {}

	virtual void show() override {
		Vehicles::show();
		std::cout << "  , Max Speed: " << max_speed << endl;
	}
};

class Coupes : public Cars {
	string model;
public:
	Coupes(const string& color, float weight, float engine_capacity, float price, int passengers)
		: Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers), model("") {}

	Coupes(const string& color, float weight, float engine_capacity, float price, int passengers, const string& model)
		: Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers), model(model) {}

	virtual void show() override {
		Cars::show();
		std::cout << "  , Model: " << model << endl;
	}
};

class Vans : public Cars, public Trucks {
	string kinds;

public:
	Vans(const string& color, float weight, float engine_capacity, float price, int passengers, float cargo_capacity)
		: Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers),
		Trucks(color, weight, engine_capacity, price, cargo_capacity), kinds("") {}

	Vans(const string& color, float weight, float engine_capacity, float price, int passengers, float cargo_capacity, const string& kinds)
		: Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers),
		Trucks(color, weight, engine_capacity, price, cargo_capacity), kinds(kinds) {}

	virtual void show() override {
		Cars::show();
		std::cout << "  , Cargo_capacity: " << cargo_capacity << ", Kinds: " << kinds << endl;
	}

};

class Animal {
protected:
	double weight;
	string color;

public:
	Animal(double w, const string& c) : weight(w), color(c) {}

	virtual void show() const = 0;

	string getColor() const { return color; }
};

// Cow 클래스는 Animal 클래스를 상속
class Cow : public Animal {
private:
	int id;
	string owner;
	int age;

public:
	Cow(double w, string c, int i, string o, int a) : Animal(w, c), id(i), owner(o), age(a) {}

	void show() const override {
		std::cout << "Cow: " << id << ", Owner: " << owner << ", Color: " << color << ", Weight: " << weight << ", Age: " << age << endl;
	}
};

// MilkCow 클래스는 Cow 클래스를 상속
class MilkCow : public Cow {
private:
	int milkProduct;

public:
	MilkCow(double w, string c, int i, string o, int a, int milk) : Cow(w, c, i, o, a), milkProduct(milk) {}

	void show() const override {
		Cow::show();
		std::cout << "  , Milk production: " << milkProduct << endl;
	}
};

// Dog 클래스는 Animal 클래스를 상속
class Dog : public Animal {
private:
	int id;
	string owner;
	int age;

public:
	Dog(double w, string c, int i, string o, int a) : Animal(w, c), id(i), owner(o), age(a) {}

	void show() const override {
		std::cout << "Dog: " << id << ", Owner: " << owner << ", Color: " << color << ", Weight: " << weight << ", Age: " << age << endl;
	}
};

const int DefaultSize = 100;

template <class T>
class Bag {
public:
	Bag(int MaxSize = DefaultSize);
	~Bag();
	virtual void Push(T& object);
	virtual T* Pop();
	virtual void Dump();
	bool IsFull();
	bool IsEmpty();
protected:
	T** array;
	int MaxSize;
	int top;
};

template <class T>
Bag<T>::Bag(int MaxSize) : MaxSize(MaxSize), top(-1) {
	array = new T * [MaxSize];
}

template <class T>
Bag<T>::~Bag() {
	delete[] array;
}

template <class T>
void Bag<T>::Push(T& object) {
	if (!IsFull()) {
		array[++top] = &object;
	}
	else
		throw BagOverflowException();
}

template <class T>
T* Bag<T>::Pop() {
	if (!IsEmpty()) {
		return array[top--];
	}
	else {
		throw BagEmptyException();
	}
}

template <class T>
void Bag<T>::Dump() {
	if (!IsEmpty())
		for (int i = 0; i < top; i++)
			cout << array[i];
	else
		throw BagEmptyException();
}


template <class T>
bool Bag<T>::IsFull() {
	return top >= MaxSize - 1;
}

template <class T>
bool Bag<T>::IsEmpty() {
	return top == -1;
}

template <class T>
class Stack : public Bag<T> {
	static int count;
public:
	Stack(int MaxSize = DefaultSize);
	~Stack();
	void Push(T& object) override;
	void Dump();
	T* Pop() override;
	static int GetCountCoder() { return count; }
};

template <class T>
int Stack<T>::count = 0;

template <class T>
Stack<T>::Stack(int MaxSize) : Bag<T>(MaxSize) {
	count++;
}

template <class T>
Stack<T>::~Stack() {
	count--;
}

template <class T>
void Stack<T>::Push(T& object) {
	if (!this->IsFull()) {
		this->array[++this->top] = &object;
	}
	else {
		throw StackOverflowException();
	}
}

template <class T>
T* Stack<T>::Pop() {
	if (!this->IsEmpty()) {
		return this->array[this->top--];
	}
	else {
		throw StackEmptyException();
	}
}

template <class T>
void Stack<T>::Dump() {
	if (!this->IsEmpty()) {
		for (int i = 0; i <= this->top; i++) {
			this->array[i]->show();
		}
	}
	else {
		throw StackEmptyException();
	}
}

template <class T>
void ShowAll(T* objects[], const int count) {
	for (int i = 0; i < count; ++i) {
		objects[i]->show();
	}
	cout << endl;
}

void makeAnimals(Animal* animals[], int numAnimals);
void makeVehicles(Vehicles* vehicles[], int numVehicles);
int main() {
	const int numAnimals = 5;
	const int numVehicles = 5;

	Stack<Vehicles> stVehicles(numVehicles);
	Stack<Animal> stAnimals(numAnimals);

	Vehicles* vehicles[numVehicles];
	Animal* animals[numAnimals];


	makeAnimals(animals, numAnimals);
	makeVehicles(vehicles, numVehicles);

	ShowAll(vehicles, numVehicles);
	ShowAll(animals, numAnimals);

	int nextAnimal = 0, nextVehicle = 0;

	Vehicles* v;
	Animal* ax;
	int select;
	while (1)
	{
		cout << "\n선택 1: push(차량), 2. pop(차량), 3: dump(차량스택), 4.push(동물), 5. pop(동물), 6. dump(동물스택), 7. 종료" << endl;
		cin >> select;
		switch (select) {
		case 1://push

			try {
				for (int i = 0; i < numVehicles; i++)
				{
					v = vehicles[nextVehicle++];
					stVehicles.Push(*v);
				}
			}
			catch (StackOverflowException so) {
				//cout << "스택 full::" << endl;
				so.Print();
			}
			break;
		case 2://pop
			try {
				for (int i = 0; i < numAnimals; i++)
				{
					v = stVehicles.Pop();
					v->show();
				}
			}
			catch (StackEmptyException se)
			{
				//cout << "스택 empty::" << endl;
				se.Print();
			}
			break;

		case 3://dump
			try {
				stVehicles.Dump();
			}
			catch (StackEmptyException se) {
				//cout << "스택 empty::" << endl;
				se.Print();
			}
			break;
		case 4://push
			try {
				for (int i = 0; i < numAnimals; i++)
				{
					ax = animals[nextAnimal++];
					stAnimals.Push(*ax);
				}
			}
			catch (StackOverflowException so) {
				//cout << "스택 full::" << endl;
				so.Print();
			}
			break;
		case 5://pop
			try {
				for (int i = 0; i < numAnimals; i++)
				{
					ax = stAnimals.Pop();
					ax->show();
				}
			}
			catch (StackEmptyException se) {
				//cout << "스택 empty::" << endl;
				se.Print();
			}
			break;

		case 6://dump
			try {
				stAnimals.Dump();
			}
			catch (StackEmptyException se) {
				//cout << "스택 empty::" << endl;
				se.Print();
			}
			break;

		default:
			exit(0);
		}
	}
	system("pause");
	return 1;
}
void makeAnimals(Animal* animals[], int numAnimals) {
	animals[0] = new Cow(500, "Brown", 101, "John Doe", 5);
	animals[1] = new Cow(520, "Black", 102, "Alice Smith", 4);
	animals[2] = new Cow(480, "White", 103, "Bob Johnson", 6);

	animals[3] = new MilkCow(530, "Brown", 104, "Charlie Rose", 3, 20);
	animals[4] = new MilkCow(510, "Spotted", 105, "Diana Ross", 5, 25);
	animals[5] = new MilkCow(495, "White", 106, "Emily Clark", 4, 22);

	animals[6] = new Dog(30, "Black", 201, "Jane Smith", 3);
	animals[7] = new Dog(28, "Brown", 202, "Emily Davis", 2);
	animals[8] = new Dog(35, "White", 203, "Frank White", 4);
	animals[9] = new Dog(32, "Gray", 204, "Grace Lee", 5);

}
void makeVehicles(Vehicles* vehicles[], int numVehicles) {
	vehicles[0] = new Coupes("Red", 1200, 1.8, 20000, 4);
	vehicles[1] = new Vans("Blue", 2500, 2.5, 30000, 2, 1000);
	vehicles[2] = new Motorcycles("Green", 200, 0.6, 7000, 180);
	vehicles[3] = new Cars("Black", 1300., 6., 2400.23, 4);
	vehicles[4] = new Trucks("Yellow", 3000.0, 8., 4000.0, 500);
	vehicles[5] = new Coupes("RedBlue", 1200, 1.8, 20000, 4);
	vehicles[6] = new Vans("BlueWhite", 2500, 2.5, 30000, 2, 1000);
	vehicles[7] = new Motorcycles("DarkGreen", 200, 0.6, 7000, 180);
	vehicles[8] = new Cars("Lightblack", 1300., 6., 2400.23, 4);
	vehicles[9] = new Trucks("YellowRed", 3000.0, 8., 4000.0, 500);
}