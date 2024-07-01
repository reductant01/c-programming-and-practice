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
    virtual void show() = 0;
};

class Cars : virtual public Vehicles {
protected:
    int passengers;
public:

};

class Trucks : virtual public Vehicles {
protected:
    float cargo_capacity;
public:

};

class Motorcycles : public Vehicles {
protected:
    float max_speed;
public:

};

class Coupes : public Cars {
    string model;
public:

};

class Vans : public Trucks, public Cars {
    string style;
public:

class Animal {
 protected:
    double weight;
    string color;

public:
    // ���� ���� �Լ�
    virtual void show() const = 0;

};

// Cow Ŭ������ Animal Ŭ������ ���
class Cow : public Animal {
private:
    int id;
    string owner;
    int age;

public:

};

// MilkCow Ŭ������ Cow Ŭ������ ���
class MilkCow : public Cow {
private:
    int milkProduct;

public:

};

// Dog Ŭ������ Animal Ŭ������ ���
class Dog : public Animal {
private:
    int id;
    string owner;
    int age;

public:

};

const int tableMaxSize = 20;
class RecordTable {
    int top;
    Shape* data[tableMaxSize];
    int capacity;
public:
    RecordTable(int numberRecords) : capacity(numberRecords) {
    }
    int Add(Shape*); // ���� �ϳ��� bag�� ����
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
        cout << "\n���� 1: member  ��ü �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1://table�� ��ü 30�� �Է�

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
            // table�� ��� ��ü ����ϱ�
            //table ������� ����ؾ� �Ѵ�: | *** | ???? | === |���� ����Ѵ�.

            rt->Print();
            break;
        case 3:
            // table���� ��ü ã��

            vehicle = rt->Search("Yellow");
            if (vehicle == nullptr) cout << "Yellow�� �������� �ʴ´�" << endl;
            else
                cout << *s;
            break;
        case 4:
            //table���� ��ü �����ϱ�
            vehicle = rt->Delete("black");
            cout << "������ records " << *s << endl;

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
            cout << "\n���� 1: member  ��ü 30�� �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
            cin >> select;
            switch (select) {
            case 1://table�� ��ü 30�� �Է�
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
                // table�� ��� ��ü ����ϱ�
                //table ������� ����ؾ� �Ѵ�: | *** | ???? | === |���� ����Ѵ�.

                rt->Print();
                break;
            case 3:
                // table���� ��ü ã��

                animal = rt->Search("Gray");
                if (animal == nullptr) cout << "Gray�� �������� �ʴ´�" << endl;
                else
                    cout << *animal;
                break;
            case 4:
                //table���� ��ü �����ϱ�
                animal = rt->Delete("Gray");
                cout << "������ records " << *animal << endl;

                break;

            default:
                exit(0);

            }

            // ��� Animal ��ü�� �����͸� ���
            showAll(animals, numAnimals);
            // Push animals onto stack


            return 0;
        }