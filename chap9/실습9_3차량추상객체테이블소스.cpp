//9-1 추상클래스 Shape 구현
/*
 1)내용
  본 source code는 추상 class의 concrete 클래스를 구현하고 shape 객체들을 stack에 push하고 pop하는 프로그램을 구현

 2)방법
  가. 추상클래스의 subclass의 생성자 함수, virtual 함수를 구현
  나. 테이블의 데이터 멤버가 추상 클래스의 객체들로 구성
  */
#include <iostream>

  // Abstract base class
class Point {
private:
    int x;
    int y;
};
class Shape {
protected:
    Point center;
    Shape(Point center);
public:
    virtual float calculateArea() = 0;
    virtual ~Shape() {} 
};

// Concrete derived classes
class Rectangle : public Shape {
private:
    float width;
    float height;
public:
    float calculateArea();
};

class Circle : public Shape {
private:
    float radius;
public:
    float calculateArea();
};

class Triangle : public Shape {
private:
    float base;
    float height;
public:
    float calculateArea();
};

// Function to calculate total area of shapes
float totalArea(const Shape* shapes[], int num) {

}
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

int main() {
    const int numShapes = 10;
    Shape* s;
    RecordTable* rt = new RecordTable();
    Shape* shapes[numShapes];
    while (1)
    {
        cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. 종료" << endl;
        cin >> select;
        switch (select) {
        case 1://table에 객체 30개 입력
            shapes[0] = new Rectangle(3.0f, 4.0f);
            shapes[1] = new Circle(5.0f);
            shapes[2] = new Triangle(3.0f, 4.0f);
            shapes[3] = new Rectangle(2.0f, 5.0f);
            shapes[4] = new Circle(2.0f);
            shapes[5] = new Triangle(5.0f, 6.0f);
            shapes[6] = new Rectangle(7.0f, 2.0f);
            shapes[7] = new Circle(1.0f);
            shapes[8] = new Triangle(4.0f, 3.0f);
            shapes[9] = new Rectangle(6.0f, 3.0f);

            for (int i = 0; i < 30; i++)
            {
                rt->Add(shapes[i]);

            }
            break;
        case 2:
            // table의 모든 객체 출력하기
            //table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.

            rt->Print();
            break;
        case 3:
            // table에서 객체 찾기

            s = rt->Search("kim");
            if (s == nullptr) cout << "kim이 존재하지 않는다" << endl;
            else
                cout << *s;
            break;
        case 4:
            //table에서 객체 삭제하기
            s = rt->Delete("hong");
            cout << "삭제된 records " << *s << endl;

            break;

        default:
            exit(0);

        }
    }
    return 0;
}