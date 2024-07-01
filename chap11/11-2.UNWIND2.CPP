// 11-2.UNWIND2.CPP 11.4 stack unwinding
#include <iostream>
using namespace std;
/*
 1) 내용
  본 source code는 예외적인 상황이 발생되었을 때 정적 할당한 자원과 동적 할당한 자원을 언제 해제하는지 알아보는 예제이다.
 2) 방법
  가. SetDate가 잘못된 데이터를 입력받았을 때 어떤 구문을 수행하는지 확인해보자.
  나. 정적 할당으로 자원을 생성하고 예외적인 상황에 의해서 갑자기 종료될 때 자원해제가 이루어지는지 확인해보자.
  다. 동적 할당으로 자원을 생성하고 예외적인 상황에 의해서 갑자기 종료될 때 자원해제가 이루어지는지 확인해보자.
*/
class Date{
private:
    int month;
    int day;
    int year;
public:
    Date(){
        cout << "Default date built" << endl;
    }
    ~Date(){
        cout << "Destructor called" << endl;
    }
    void SetDate(int s_month, int s_day, int s_year){
        if(s_month > 12)
            throw("Month too big!");
        if(s_day > 31)
            throw("Day too big!");

        month = s_month;
        day = s_day;
        year = s_year;
    }

    void Print(){
        cout << "Month.Day.Year:" << month << "." << day << "." << year << endl;
    }
};

void main() {
        //주석 1-첫번째 경우: compiler가 자동적으로 자원을 해제시켜줌
		/*
        // Date d1, d2;
        try{
            Date d1, d2;
            d1.SetDate(06, 04, 2019);
            d1.Print();

            d2.SetDate(15,04,2019);
            d2.Print();
        }
        catch(const char* description){
            cout << "Exception: " << description << endl;
        }
        */

        // 주석 2-    //두번째 경우: 동적 할당을 사용할 경우 delete 문이 실행되지 않는 것을 실행 결과로서 확인
	    //*
        Date *d1, *d2;
        try{
            d1 = new Date;
            d2 = new Date;

            d1->SetDate(06, 04, 2019);
            d1->Print();

            d2->SetDate(15,04,2019);
            d2->Print();

            delete d1;    
            delete d2;    
        }
        catch(const char* description){
            cout << "Exception: "<< description << endl;
            delete d1;
            delete d2;
        }
		//*/
        system("pause");
}