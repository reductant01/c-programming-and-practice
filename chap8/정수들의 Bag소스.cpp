//�������� Bag Ŭ���� ������ ���
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

#define DefaultSize 10
class Bag {
public:
    Bag(int MaxSize = DefaultSize); //������
    ~Bag(); // �Ҹ���
    virtual void Add(int); // ���� �ϳ��� bag�� ����
    virtual int Delete(); //bag���� ���� �ϳ��� ����
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();
    friend ostream& operator<< (ostream& stream, Bag b);
protected:
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ
    int arr[DefaultSize];
    int MaxSize; // �迭�� ũ��
    int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);      //������
    ~Set();      // �Ҹ���
                 //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
    void Add(int);
    int Delete();
    friend ostream& operator<< (ostream& stream, Set s);
};


Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
    cout << "Bag::������ ȣ��" << endl;
    top = 0;
}

Bag::~Bag() {
    cout << "~Bag()ȣ���" << endl;
}

bool Bag::IsFull() {
    if (top == MaxSize - 1)
        return true;
    else
        return false;
}

bool Bag::IsEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}

void Bag::Full() {
    cout << "Data structure is full" << endl;
}

void Bag::Empty() {
    cout << "Data structure is empty" << endl;
}

void Bag::Add(int x) {
    if (IsFull())
        Full();
    else {
        arr[top] = x;
        cout << "BAG�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
        top++;
    }
}

int Bag::Delete() {
    if (IsEmpty()) {
        Empty();
        return -1;
    }
    int deletePos = top / 2;
    for (int index = deletePos; index < top; index++)
        arr[index] = arr[index + 1];
    top--;
    return arr[deletePos];
}

int Bag::Top() {
    return top;
}
//�ּ� 1
//
ostream& operator<<(ostream& stream, Bag b) {
    cout << "ostream& operator<<(ostream& stream, Bag b) " << endl;
    for (int i = 0; i < b.Top(); i++) {
        stream << b.arr[i] << endl;
    }
    return stream;
}
//

Set::Set(int MaxBagSize) : Bag(MaxBagSize) {}

Set::~Set() {
}

void Set::Add(int x) {
    if (IsFull())
        Full();
    else {
        for (int i = 0; i < MaxSize; i++) {
            if (!(arr[i] == x)) {
                arr[top] = x;
                cout << "SET�� " << arr[top] << "�� �߰��Ǿ����ϴ�" << endl;
                top++;
                return;
            }
            else {
                cout << "�ߺ��� �� �Դϴ�" << endl;
                return;
            }
        }
    }
   
}

int Set::Delete() {
    if (IsEmpty()) {
        Empty();
        return -1;
    }
    int deletePos = top / 2;

    for (int index = deletePos; index < top; index++)
        arr[index] = arr[index + 1];
    top--;
    return arr[deletePos];
}
//�ּ� 1

ostream& operator<<(ostream& stream, Set s) {
    cout << "ostream& operator<<(ostream& stream, Set s) " << endl;
    for (int i = 0; i < s.Top(); i++) {
        stream << s.arr[i] << endl;
    }
    return stream;
}

int main() {
    Set s;
    int select;
    srand(time(NULL));
    while (1)
    {

        cout << "\n���� 1: ���� �����Ͽ� �Է�, 2.set ��� ����, 3.set���� �˻�, 4. ����" << endl;
        cin >> select;

        switch (select) {
        case 1://1: ���� ����
            
            for (int i = 0; i < 10; i++) {
                s.Add(rand() % 100);
            }

            break;
        case 2:
            cout << s;
            break;

        case 3://

            for (int i = 0; i < 10; i++)
            {
                cout << s.Delete();
            }
            break;
        
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}