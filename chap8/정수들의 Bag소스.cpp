//정수들의 Bag 클래스 구현과 사용
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

#define DefaultSize 10
class Bag {
public:
    Bag(int MaxSize = DefaultSize); //생성자
    ~Bag(); // 소멸자
    virtual void Add(int); // 정수 하나를 bag에 삽입
    virtual int Delete(); //bag에서 정수 하나를 삭제
    bool IsFull();
    // bag이 포화상태이면 true, 그렇지 않으면 false를 반환
    bool IsEmpty();
    // bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
    int Top();
    friend ostream& operator<< (ostream& stream, Bag b);
protected:
    void Full(); // bag이 포화상태일 때의 조치
    void Empty(); // bag이 공백 상태일 때의 조치
    int arr[DefaultSize];
    int MaxSize; // 배열의 크기
    int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);      //생성자
    ~Set();      // 소멸자
                 //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
    void Add(int);
    int Delete();
    friend ostream& operator<< (ostream& stream, Set s);
};


Bag::Bag(int MaxBagSize) : MaxSize(MaxBagSize) {
    cout << "Bag::생성자 호출" << endl;
    top = 0;
}

Bag::~Bag() {
    cout << "~Bag()호출됨" << endl;
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
        cout << "BAG에 " << arr[top] << "이 추가되었습니다" << endl;
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
//주석 1
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
                cout << "SET에 " << arr[top] << "이 추가되었습니다" << endl;
                top++;
                return;
            }
            else {
                cout << "중복된 값 입니다" << endl;
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
//주석 1

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

        cout << "\n선택 1: 난수 생성하여 입력, 2.set 출력 정렬, 3.set에서 검색, 4. 종료" << endl;
        cin >> select;

        switch (select) {
        case 1://1: 난수 생성
            
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