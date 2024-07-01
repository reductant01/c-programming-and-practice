// 11장-3.BASIC3.CPP   11.3 예외 처리와 교정
// 기본적인 예외 처리－세 번째 예제: 정정 후 다시 시도
#include <iostream>
using namespace std;
class ZeroDivision { };
class Negative{
public:
    int* pValue;
    Negative (int* pn) :
    pValue (pn){ }
};

int divide (int& num1, int& num2){
    if (num2 == 0)
        throw ZeroDivision ();
    if (num1 < 0)
        throw Negative (&num1);
    if (num2 < 0)
        throw Negative (&num2);
    return (num1/num2);
}

int divideCheck (int& num1, int &num2){
    int num;
    try {
        num = divide (num1, num2);
    }
    catch (Negative neg){
        // 부호를 바꿈, 이것을 정정(correction)이라 부르는 것이다
          *neg.pValue = - *neg.pValue;
          // 사용자에게 경고
          cout << "A number was negative... reversing it to positive"<< endl;
          // 다시 시도
          num = divideCheck (num1, num2);
    }
    return num;
}

void main(){
    int num1, num2 ;

    cout << "This is a dividing machine for positive integers!"
          << endl << "(Input 0 as first value to end)" << endl           << endl ;
    cout << "Input two values: " ;

    cin >> num1 >> num2 ;
    while (num1 != 0){
	
	//while (cin>>num1>>num2) { //수정하여 동일한 효과를 갖도록 수정하는 코딩 실습
        try{
            int num3 = divideCheck (num1, num2);
            cout << num1 << " / " << num2 << " = " << num3 << endl;
        }
        catch (ZeroDivision){
            cout << "Error: Division by 0" << endl;
        }
        catch (Negative neg){
            // 예외상황 발생
            cout << "Ouch!" << endl;
            throw;    
        }
        // 새 값을 요청함
        cout << endl ;
        cout << "Input two values: " ;
        cin >> num1 >> num2 ;
    }
	system("pause");
}