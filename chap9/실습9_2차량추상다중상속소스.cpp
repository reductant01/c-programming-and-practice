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
    Vehicles() : color(""), weight(0), engine_capacity(0), price(0) {}
    Vehicles(string color, float weight, float engine_capacity, float price)
        : color(color), weight(weight), engine_capacity(engine_capacity), price(price) {}
public:
    virtual void show() const = 0;

    void showVehicle() const {
        cout << "Color: " << color << ", Weight: " << weight << ", Engine_capacity: " << engine_capacity << ", Price: " << price << endl;
    }
};

class Cars : virtual public Vehicles {
protected:
    int passengers;
public:
    Cars(string color, float weight, float engine_capacity, float price, int passengers)
        : Vehicles(color, weight, engine_capacity, price), passengers(passengers) {}
    virtual void show() const {
        showVehicle();
        cout << ", Passengers: " << passengers << endl;
    }
};

class Trucks : virtual public Vehicles {
protected:
    float cargo_capacity;
public:
    Trucks(string color, float weight, float engine_capacity, float price, float cargo_capacity)
        : Vehicles(color, weight, engine_capacity, price), cargo_capacity(cargo_capacity) {}

    virtual void show() const {
        showVehicle();
        cout << ", Cargo Capacity: " << cargo_capacity << endl;
    }
};

class Motorcycles : public Vehicles {
protected:
    float max_speed;
public:
    Motorcycles(string color, float weight, float engine_capacity, float price, float max_speed)
        : Vehicles(color, weight, engine_capacity, price), max_speed(max_speed) {}

    virtual void show() const {
        showVehicle();
        cout << ", Max Speed: " << max_speed << endl;
    }
};

class Coupes : public Cars {
    string Ccolor;
public:
    Coupes(string color, float weight, float engine_capacity, float price, int passengers)
        : Cars(color, weight, engine_capacity, price, passengers) {}

    virtual void show() const {
        Cars::show();
    }
};

class Vans : public Trucks, public Cars {
    string model;
public:
    Vans(string color, float weight, float engine_capacity, float price, int passengers, float cargo_capacity)
        : Vehicles(color, weight, engine_capacity, price), Cars(color, weight, engine_capacity, price, passengers), Trucks(color, weight, engine_capacity, price, cargo_capacity) {}

    virtual void show() const {
        Cars::show();
        cout << ", Cargo Capacity: " << cargo_capacity << endl; // Trucks::show()를 직접 정보 출력으로 대체
    }
};

class Bag {
public:
    Bag(int MaxSize = DefaultSize);
    ~Bag();
    virtual void Push(Vehicles& vehicle);
    virtual Vehicles* Pop();
    bool IsFull();
    bool IsEmpty();
protected:
    Vehicles** array;
    int MaxSize;
    int top;
};

Bag::Bag(int MaxSize) : MaxSize(MaxSize), top(-1) {
    array = new Vehicles * [MaxSize];
}

Bag::~Bag() {
    delete[] array;
}

void Bag::Push(Vehicles& vehicle) {
    if (!IsFull()) {
        array[++top] = &vehicle;
    }
}

Vehicles* Bag::Pop() {
    if (!IsEmpty()) {
        return array[top--];
    }
    return nullptr;
}

bool Bag::IsFull() {
    return top == MaxSize - 1;
}

bool Bag::IsEmpty() {
    return top == -1;
}

class Stack : public Bag {
    static int count;
public:
    Stack(int MaxSize = DefaultSize) : Bag(MaxSize) {}
    ~Stack() {}
    void Push(Vehicles& vehicle) override;
    Vehicles* Pop() override;
    static int GetCountCoder() { return count; }
};

int Stack::count = 0;

void Stack::Push(Vehicles& vehicle) {
    Bag::Push(vehicle);
    ++count;
}

Vehicles* Stack::Pop() {
    Vehicles* v = Bag::Pop();
    if (v) {
        --count;
    }
    return v;
}

void ShowAll(Vehicles* vehicles[], int N) {
    for (int i = 0; i < N; ++i) {
        vehicles[i]->show();
        cout << endl;
    }
}

int main() {
    const int N = 3;
    Stack st(N);
    Vehicles* vehicles[N];

    // Initialize vehicles
    vehicles[0] = new Coupes("Red", 1200, 1.8, 20000, 4);
    vehicles[1] = new Vans("Blue", 2500, 2.5, 30000, 2, 1000);
    vehicles[2] = new Motorcycles("Green", 200, 0.6, 7000, 180);

    // Show all vehicles
    ShowAll(vehicles, N);

    // Push vehicles onto stack
    for (int i = 0; i < N; ++i) {
        st.Push(*vehicles[i]);
    }

    // Pop vehicles from stack and show
    for (int i = 0; i < N; ++i) {
        Vehicles* v = st.Pop();
        if (v) {
            v->show();
        }
    }

    // Cleanup
    //for (int i = 0; i < N; ++i) {
   //     delete vehicles[i];
    //}
    int number;
    cin >> number;
    return 0;
}