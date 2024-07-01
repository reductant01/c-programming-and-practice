// 11-5.XALLOC2.CPP  11.7 new를 사용한 메모리 할당
#include <new>
#include <iostream>
#include <cstring>
using namespace std;
/*
1. 내용
   본 source code는 new를 사용한 메모리 할당에 대한 예외 처리부분을 실습해보는 내용이다.

2. 방법
   가) 주석 1을 해제하여 메모리 할당 예외 발생을 보여주는 출력 값을 확인해보자.
   나) main함수에 bu, second, bubu 객체에 주석을 해보고 메모리 공간이 부족할 때와 충분할 때를 출력 값을 통하여 비교해보자.
*/
class BigClass{
public:
    char bigText[900000000];
    //10KByte text
};
//pointer를 이용한 Bigclass를 사용하는 class
class BigUser{
private:
    BigClass * pBig;
    static long totalMemory;

public:
    //기본 생성자
    BigUser(){
        cout << "Entering the default constructor..." << endl;
        pBig = new BigClass;
        totalMemory += sizeof(*pBig);
        cout << "Default constructor:" << sizeof(*pBig)
              << "bytes used for a total of" << totalMemory << endl;
    }
    //copy 생성자!!!
    BigUser(const BigUser & bu){
        cout << "Entering the copy constructor..." << endl;
        pBig = new BigClass;
        totalMemory += sizeof(*pBig);
        
        cout << "Copy constructor executed:" << sizeof(*pBig)
              << "bytes used for a total of" << totalMemory << endl;
    }
    //소멸자
    ~BigUser(){
        totalMemory -= sizeof(*pBig);
        //optionally add this code:
        /*cout << "Destructor: " << sizeof(*pBig)
                << "bytes freed" << endl;*/
        delete pBig;
    }

    void Fake(){
        cout << "Fake called" << endl;
    }
};

long BigUser::totalMemory = 0;
//BigUser 객체를 사용 및 전달하는 global 함수
BigUser GlobalUserFunction(BigUser bu){
    BigUser bu2;
    cout << "GlobalUserFunction called" << endl;

    bu.Fake();
    bu2.Fake();

    return bu2;
}

void main(){
    //throw문이 사용되지 않았다, 그러나 catch문이 실행되는 것을 확인
    try{
        BigUser bu, secondBu, bubu;

        BigUser bu1;
        //BigUser 객체를 사용 및 전달하는 global 함수
        BigUser bu2 = GlobalUserFunction(bu1);
        //두개의 BigUser 객체 사용
      
        bu2.Fake();
    }
    catch (bad_alloc exc){
        cout << "new에서 예외 발생: "  <<exc.what() << endl;
    }
	system("pause");
}