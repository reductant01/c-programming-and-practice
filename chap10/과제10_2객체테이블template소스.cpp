#include <iostream>
#include <string>

using namespace std;

// Default size for the Bag and Stack
const int DefaultSize = 100;

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
    Coupes(const string& color, float weight, float engine_capacity, float price, int passengers, const string& model)
        : Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers), model(model) {}

    virtual void show() override {
        Cars::show();
        std::cout << "  , Model: " << model << endl;
    }
};

class Vans : public Cars, public Trucks {
    string style;

public:
    Vans(const string& color, float weight, float engine_capacity, float price, int passengers, float cargo_capacity, const string& style)
        : Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers),
        Trucks(color, weight, engine_capacity, price, cargo_capacity), style(style) {}

    virtual void show() override {
        Cars::show();
        std::cout << "  , Cargo_capacity: " << cargo_capacity << ", Style: " << style << endl;
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

// Cow Ŭ������ Animal Ŭ������ ���
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

// MilkCow Ŭ������ Cow Ŭ������ ���
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

// Dog Ŭ������ Animal Ŭ������ ���
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

const int tableMaxSize = 20;

template <typename T>
class RecordTable {
    int top;
    T* data[tableMaxSize];
    int capacity;
public:
    RecordTable(int numberRecords = tableMaxSize) : capacity(numberRecords), top(0) {
    }

    int Add(T* item) {
        if (top < capacity) {
            data[top++] = item;
            return 1;
        }
        return 0;
    }

    T* Delete(string color) {
        for (int i = 0; i < top; ++i) {
            if (data[i]->getColor() == color) {
                T* item = data[i];
                for (int j = i; j < top - 1; ++j) {
                    data[j] = data[j + 1];
                }
                top--;
                return item;
            }
        }
        return nullptr;
    }

    T* Search(string color) {
        for (int i = 0; i < top; ++i) {
            if (data[i]->getColor() == color) {
                return data[i];
            }
        }
        return nullptr;
    }

    void Print() {
        for (int i = 0; i < top; ++i) {
            data[i]->show();
        }
    }
};

template <typename T>
void ShowAll(T* data[], int count) {
    for (int i = 0; i < count; ++i) {
        data[i]->show();
    }
}

int main() {
    int select;
    const int N = 5;
    RecordTable<Vehicles>* rt = new RecordTable<Vehicles>();
    Vehicles* vehicle;
    Vehicles* vehicles[N];

    while (1) {
        cout << "\n���� 1: member ��ü �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1: // table�� ��ü 5�� �Է�
            vehicles[0] = new Coupes("Red", 1200.0f, 1.8f, 20000.0f, 4, "Model X");
            vehicles[1] = new Vans("Blue", 2500.0f, 2.5f, 30000.0f, 2, 1000.0f, "Style A");
            vehicles[2] = new Motorcycles("Green", 200.0f, 0.6f, 7000.0f, 180.0f);
            vehicles[3] = new Cars("Black", 1300.0f, 1.6f, 2400.23f, 4);
            vehicles[4] = new Trucks("Yellow", 3000.0f, 8.0f, 40000.0f, 500.0f);
            for (int i = 0; i < N; i++) {
                rt->Add(vehicles[i]);
            }
            break;
        case 2:
            // table�� ��� ��ü ����ϱ�
            rt->Print();
            break;
        case 3:
            // table���� ��ü ã��
            vehicle = rt->Search("Yellow");
            if (vehicle == nullptr) {
                cout << "Yellow�� �������� �ʴ´�" << endl;
            }
            else {
                vehicle->show();
            }
            break;
        case 4:
            // table���� ��ü �����ϱ�
            vehicle = rt->Delete("Black");
            if (vehicle == nullptr) {
                cout << "������ records�� �������� �ʴ´�" << endl;
            }
            else {
                cout << "������ records " << endl;
                vehicle->show();
            }
            break;
        case 5:
            // ����
            exit(0);
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }

        // ��� Vehicles ��ü�� �����͸� ���
        ShowAll(vehicles, N);
    }

    const int numAnimals = 10;
    RecordTable<Animal>* rt_animals = new RecordTable<Animal>();
    Animal* animal;
    Animal* animals[numAnimals];

    while (1) {
        cout << "\n���� 1: member ��ü 10�� �Է�, 2.table ���, 3: table ��ü ã��, 4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1: // table�� ��ü 10�� �Է�
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

            for (int i = 0; i < numAnimals; i++) {
                rt_animals->Add(animals[i]);
            }
            break;
        case 2:
            // table�� ��� ��ü ����ϱ�
            rt_animals->Print();
            break;
        case 3:
            // table���� ��ü ã��
            animal = rt_animals->Search("Gray");
            if (animal == nullptr) {
                cout << "Gray�� �������� �ʴ´�" << endl;
            }
            else {
                animal->show();
            }
            break;
        case 4:
            // table���� ��ü �����ϱ�
            animal = rt_animals->Delete("Gray");
            if (animal == nullptr) {
                cout << "������ records�� �������� �ʴ´�" << endl;
            }
            else {
                cout << "������ records " << endl;
                animal->show();
            }
            break;
        case 5:
            // ����
            exit(0);
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }

        // ��� Animal ��ü�� �����͸� ���
        ShowAll(animals, numAnimals);
    }

    return 0;
}
