// 10-4.STACK2.H  10.3 상속과 polymorphism을 사용하여 genericity 표현
class GenericObject
{};

class Stack{
    GenericObject* data[50];
    int nElements;
public:
    Stack():
    nElements(0)
    {}
    void Push(GenericObject* elem);
    GenericObject* Pop();
    int Number();
    int Empty();
};