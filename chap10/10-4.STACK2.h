// 10-4.STACK2.H  10.3 ��Ӱ� polymorphism�� ����Ͽ� genericity ǥ��
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