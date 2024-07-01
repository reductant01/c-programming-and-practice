// 10��-5.STACK2.CPP 10.3 ��Ӱ� polymorphism�� ����Ͽ� genericity ǥ��
#include "10��-4.STACK2.h"
// generic ��ü���� stack�� ���� member �Լ� ����
void Stack :: Push (GenericObject * elem){
    data [nElements] = elem;
    nElements ++;
}

GenericObject * Stack :: Pop (){ //Pop()�� base class�� �����Ѵ� 
    nElements --;
    return data [nElements];
}

int Stack :: Number (){
    return nElements;
}

int Stack :: Empty (){
    return (nElements == 0);
}