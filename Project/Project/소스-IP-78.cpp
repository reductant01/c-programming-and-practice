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
            << ", Engine Capacity: " << engine_capacity << ", Price: " << price << endl ;
    }
};

class Cars : virtual public Vehicles {
protected:
    int passengers;
public:
    Cars(const string& c, float w, float e, float p, int pass) 
        : Vehicles(c,w,e,p), passengers(pass) {}
    
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
    
    // 순수 가상 함수
    virtual void show() const = 0;

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

const int tableMaxSize = 20;
class RecordTable {
    int top;
    Shape* data[tableMaxSize];
    int capacity;
public:
    RecordTable(int numberRecords) : capacity(numberRecords) {
    }
    int Add(Shape*); // 정수 하나를 bag에 삽입
    Shape* Delete(char*);
    void Sort();
    Shape* Search(char*);
    void Print();
};

void ShowAll(T* data[], int count) {
    for (int i = 0; i < count; ++i) {
        data[i]->show();
    }
}

int main() {
    const int N = 5;
    RecordTable<Vehicle>* rt = new RecordTable();
    Vehicles* vehicle;
    Vehicles* vehicles[N];
    while (1)
    {
        cout << "\n선택 1: member  객체 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
        cin >> select;
        switch (select) {
        case 1://table에 객체 30개 입력

            vehicles[0] = new Coupes("Red", 1200, 1.8, 20000, 4);
            vehicles[1] = new Vans("Blue", 2500, 2.5, 30000, 2, 1000);
            vehicles[2] = new Motorcycles("Green", 200, 0.6, 7000, 180);
            vehicles[3] = new Cars("black", 1300., 6., 2400.23, 4);
            vehicles[4] = new Trucks("Yellow", 3000.0, 8., 4000.0, 500);
            for (int i = 0; i < N; i++)
            {
                rt->Add(vehicles[i]);

            }
            break;
        case 2:
            // table의 모든 객체 출력하기
            //table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

            rt->Print();
            break;
        case 3:
            // table에서 객체 찾기

            vehicle = rt->Search("Yellow");
            if (vehicle == nullptr) cout << "Yellow이 존재하지 않는다" << endl;
            else
                cout << *s;
            break;
        case 4:
            //table에서 객체 삭제하기
            vehicle = rt->Delete("black");
            cout << "삭제된 records " << *s << endl;

            break;

        default:
            exit(0);

        }
        // Initialize vehicles

        // Show all vehicles
        ShowAll(vehicles, N);

        RecordTable<Animals>* rt = new RecordTable();

        while (1)
        {
            const int numAnimals = 10;
            Animals* animal;
            cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
            cin >> select;
            switch (select) {
            case 1://table에 객체 30개 입력
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

                for (int i = 0; i < 30; i++)
                {
                    rt->Add(animals[i]);

                }
                break;
            case 2:
                // table의 모든 객체 출력하기
                //table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

                rt->Print();
                break;
            case 3:
                // table에서 객체 찾기

                animal = rt->Search("Gray");
                if (animal == nullptr) cout << "Gray이 존재하지 않는다" << endl;
                else
                    cout << *animal;
                break;
            case 4:
                //table에서 객체 삭제하기
                animal = rt->Delete("Gray");
                cout << "삭제된 records " << *animal << endl;

                break;

            default:
                exit(0);

            }

            // 모든 Animal 객체의 데이터를 출력
            showAll(animals, numAnimals);
            // Push animals onto stack


            return 0;
        }