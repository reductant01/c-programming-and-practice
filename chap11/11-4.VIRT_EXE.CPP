// 11-4.VIRT_EXE.CPP   11.6 예외 class의 계층 구조
/*
 1) 내용
  본 source code는 예외 class 계층 구조를 이용하여 날짜를 출력하는 program에서 발생할 수 있는 예외 사항 처리에 대해 알아보는 예제이다.
 2) 방법
  가. 각 class의 상속 관계를 확인해보자.
  나. main에서 각 Date 객체에 대한 SetDate 함수를 수행했을 때 catch 문에서 err.Print()의 동적 binding을 살펴보는 실습이다.
*/
#include <iostream>
using namespace std;

class RangeError{
public:
    virtual void Print() = 0;
};

class MonthRange : public RangeError{
public:
    void Print(){
        cout<<"Generic error in the range of the month"<<endl;
    }
};

class MonthTooBig : public MonthRange{
public:
    void Print(){
        cout<<"Month is too big (december is the last)"<<endl;
    }
};
class NegativeMonth : public MonthRange{
public:
    void Print(){
        cout<<"Month is negative"<<endl;
    }
};

class DayRange : public RangeError{
public:
    void Print(){
        cout<<"Generic error in the value of the day"<<endl;
    }
};

class DayTooBig : public DayRange{
public:
    void Print(){
        cout<<"Day is too big"<<endl;
    }
};

class DayTooBigForMonth : public DayTooBig{
public:
    void Print(){
        cout<<"Day is too big for the specific month"<<endl;
    }
};

class NegativeDay : public DayRange{
public:
    void Print(){
        cout<<"Day is negative"<<endl<<endl;
    }
};

class Date{
private:
    int month;
    int day;
    int year;

public:
    void SetDate(int s_month, int s_day, int s_year){
        if(s_month > 12)
            throw MonthTooBig();
        if(s_month <= 0)
            throw NegativeMonth();
        if(s_month == 2 && s_day > 29)
            throw DayTooBigForMonth();
        if(s_day > 31 || s_month == 2 && s_day == 29)
            throw DayTooBig();
        if(s_day <= 0)
            throw NegativeDay();

        month = s_month;
        day = s_day;
        year = s_year;
    }

    void Print(){
        cout << month << '.' << day << '.' << year << endl;
    }
};

void main(){
    try{
        Date d1, d2, d3, d4, d5, d6;
        /*
        cout << "d1.SetDate(-13, 29, 2017);" << endl;
        d1.SetDate(-13, 29, 2019);
        d1.Print();
        */
        cout << "d2.SetDate(4, 31, 2017);" << endl;
        d2.SetDate(4,31,2017);
        d2.Print();

        cout << "d3.SetDate(0, 13, 2017);" << endl;
        d3.SetDate(0, 13, 2017);
        d3.Print();
		
        cout << "d4.SetDate(2, 31, 2017);" << endl;
        d4.SetDate(2, 31, 2017);
        d4.Print();

        cout << "d5.SetDate(5, 32, 2017);" << endl;
        d5.SetDate(5, 32, 2017);
        d5.Print();

        cout << "d6.SetDate(5, 0, 2017);" << endl;
        d6.SetDate(5, 0, 2017);
        d6.Print();
    }
    catch(RangeError &error){
        error.Print();
    }
    system("pause");
}