#include <iostream>
#include <string>
using namespace std;
// �߻� Ŭ���� Animal
class Animal {
protected:
    double weight;
    string color;
protected:
    Animal(double w, const string& c) : weight(w), color(c) {}
public:
    // ���� ���� �Լ�
    virtual void show() const = 0;

    // ���� �Ҹ���
    virtual ~Animal() {}

    void showAnimal() const {
        cout << "Weight: " << weight << ", Color: " << color << ", ";
    }
};

// Cow Ŭ������ Animal Ŭ������ ���
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

// MilkCow Ŭ������ Cow Ŭ������ ���
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

// Dog Ŭ������ Animal Ŭ������ ���
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

// Animal ��ü �迭�� ��� ����� ����ϴ� �Լ�
void showAll(Animal* animals[], int numAnimals) {
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->show();
    }
}

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // 3���� Cow ��ü, 3���� MilkCow ��ü, 4���� Dog ��ü�� �ʱ�ȭ
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

    // ��� Animal ��ü�� �����͸� ���
    showAll(animals, numAnimals);

    // ���� �Ҵ�� �޸� ����
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}