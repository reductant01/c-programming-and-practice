// 10-1.STACK1.H   10.2 macro로 genericity를 표현
#include<iostream>
#define TYPE double
/*
실습 1
 1) 내용
  본 source code는 macro를 이용하여 generic class 선언 방법과 macro가 어떻게 처리 되는지에 대해 알아보는 예제이다.
 2) 방법
  가. class Stack의 선언 부분을 확인해보자.
  나. class Stack의 member함수 정의 부분을 확인해보자.
  다. macro 선언을 확인하고 실행을 통하여 출력 결과를 확인해보자.
*/
class Stack{
    TYPE data [50];
    int nElements;
public:
    Stack () : nElements (0) { }
    // 한 요소를 stack에 추가
    void Push (TYPE elem);
    // stack으로부터 한 요소를 얻음
    TYPE Pop ();
    // stack에 있는 실제 요소의 수
    int Number ();
    // stack이 비었나?
    int Empty ();
} ;

