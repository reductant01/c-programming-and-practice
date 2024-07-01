// 10장-19.RUNSPEAK.CPP  10.5.1 RunSpeaking 함수의 재검토
#include <iostream>
#include <stdlib.h>
//#include "10-11.ANIMAL.h"
#include "10-24.COW_DOG.h"
using namespace std;

template <class T>
void RunSpeaking (T ele, int nSteps){
    for (int num = 0; num < nSteps; ++num){
        int temp1 = rand()/100;
        int temp2 = rand()/100;
        ele.JumpBy(temp1, temp2);
        ele.Speak ();
    }
}
void main(){
    Cow cow (Point (20, 10));
    Dog dog (Point (10, 20));
    RunSpeaking (cow, 5);
    RunSpeaking (dog, 28);
	system("pause");
}