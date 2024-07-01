#include <iostream>
#include <string>
using namespace std;
// 추상 클래스 Animal
class Animal {
protected:
    double weight;
    string color;
protected:
    Animal(double w, const string& c) : weight(w), color(c) {}
public:
    // 순수 가상 함수
    virtual void show() const = 0;

    // 가상 소멸자
    virtual ~Animal() {}

    void showAnimal() const {
        cout << "Weight: " << weight << ", Color: " << color << ", ";
    }
};

// Cow 클래스는 Animal 클래스를 상속
class Cow : public Animal {
private:
    int id;
    string owner;
    int age;
public:
    Cow(double weight, string color, int id, string owner, int age) :
        Animal(weight, color), id(id), owner(owner), age(age) {}
    virtual void show() const {
        showAnimal();
        cout << "ID: " << id << ", Owner: " << owner << ", Age: " << age << endl;
    }
};

// MilkCow 클래스는 Cow 클래스를 상속
class MilkCow : public Cow {
private:
    int milkProduct;
public:
    MilkCow(double weight, string color, int id, string owner, int age, int milkProduct) :
        Cow(weight, color, id, owner, age), milkProduct(milkProduct) {}
    virtual void show() const {
        Cow::show();
        cout << "Milk Production: " << milkProduct << " liters/day" << endl;
    }

};

// Dog 클래스는 Animal 클래스를 상속
class Dog : public Animal {
private:
    int id;
    string owner;
    int age;
public:
    Dog(double weight, string color, int id, string owner, int age) :
        Animal(weight, color), id(id), owner(owner), age(age) {}

    virtual void show() const {
        showAnimal();
        cout << "ID: " << id << ", Owner: " << owner << ", Age: " << age << endl;
    }
};

// Animal 객체 배열의 모든 멤버를 출력하는 함수
void showAll(Animal* animals[], int numAnimals) {
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->show();
    }
}

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // 3개의 Cow 객체, 3개의 MilkCow 객체, 4개의 Dog 객체를 초기화
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

    // 모든 Animal 객체의 데이터를 출력
    showAll(animals, numAnimals);

    // 동적 할당된 메모리 해제
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}