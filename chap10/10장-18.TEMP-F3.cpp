// 10Àå-18.TEMP-F3.CPP   10.5 template ÇÔ¼ö
#include <iostream>
using namespace std;

template <class T> T minn (T ele1, T ele2){
    if (ele1 < ele2)
        return ele1;
    else
        return ele1;
}
class Number{
    long num;
public:
    Number (long num2) : num (num2) { }
    long Value (){
        return num;
    }
    bool operator < (Number numBer2){
        return num < numBer2.Value ();
    }
} ;

void main (){
    Number nn1 = 12;
    Number nn2 = 18;
    Number nn3 = minn (nn1, nn2);
    cout << "min(<Number>, <Number>) = " << nn3.Value() << endl ;
	system("pause");
}