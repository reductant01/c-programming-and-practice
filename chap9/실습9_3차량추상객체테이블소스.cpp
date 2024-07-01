//9-1 �߻�Ŭ���� Shape ����
/*
 1)����
  �� source code�� �߻� class�� concrete Ŭ������ �����ϰ� shape ��ü���� stack�� push�ϰ� pop�ϴ� ���α׷��� ����

 2)���
  ��. �߻�Ŭ������ subclass�� ������ �Լ�, virtual �Լ��� ����
  ��. ���̺��� ������ ����� �߻� Ŭ������ ��ü��� ����
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
    int Add(Shape*); // ���� �ϳ��� bag�� ����
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
        cout << "\n���� 1: member  ��ü 30�� �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1://table�� ��ü 30�� �Է�
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
            // table�� ��� ��ü ����ϱ�
            //table ������� ����ؾ� �Ѵ�: | *** | ???? | === |���� ����Ѵ�.

            rt->Print();
            break;
        case 3:
            // table���� ��ü ã��

            s = rt->Search("kim");
            if (s == nullptr) cout << "kim�� �������� �ʴ´�" << endl;
            else
                cout << *s;
            break;
        case 4:
            //table���� ��ü �����ϱ�
            s = rt->Delete("hong");
            cout << "������ records " << *s << endl;

            break;

        default:
            exit(0);

        }
    }
    return 0;
}