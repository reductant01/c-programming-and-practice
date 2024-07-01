// 10-1.STACK1.H   10.2 macro�� genericity�� ǥ��
#include<iostream>
#define TYPE double
/*
�ǽ� 1
 1) ����
  �� source code�� macro�� �̿��Ͽ� generic class ���� ����� macro�� ��� ó�� �Ǵ����� ���� �˾ƺ��� �����̴�.
 2) ���
  ��. class Stack�� ���� �κ��� Ȯ���غ���.
  ��. class Stack�� member�Լ� ���� �κ��� Ȯ���غ���.
  ��. macro ������ Ȯ���ϰ� ������ ���Ͽ� ��� ����� Ȯ���غ���.
*/
class Stack{
    TYPE data [50];
    int nElements;
public:
    Stack () : nElements (0) { }
    // �� ��Ҹ� stack�� �߰�
    void Push (TYPE elem);
    // stack���κ��� �� ��Ҹ� ����
    TYPE Pop ();
    // stack�� �ִ� ���� ����� ��
    int Number ();
    // stack�� �����?
    int Empty ();
} ;

