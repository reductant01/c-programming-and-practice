// 10-5.Polymorphism_Stack.h  10.4.3 template�� �̿��� Container class ǥ��
template <class T>
class Stack{
    T data[50];
    int nElements;
public:
    Stack():
        nElements(0)
    {}
    //stack�� �� ��Ҹ� �߰��Ѵ�.
    void Push(T elem);
    //stack���κ��� �� ��Ҹ� ��´�.
    T Pop();
    //stack�� ����Ǿ� �ִ� ��� ����
    int Number();
    //stack�� ����ִ°�?
    int Empty();
};
class Number { //Number ��ü�� ���� stack�� push�� ���������� �ǽ�
private:
    int data;
public:
    Number(int i) : data(i) {}
};
