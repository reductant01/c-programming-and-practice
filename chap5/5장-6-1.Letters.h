//5장-6-1.Letters.h   5.5 class 데이터와 class 함수

// class Letters의 정의
class Letters {
private:
    // private 데이터:
    char ch;//private data member can be accessed within member functions
    static int num;//클래스 멤버

public:
    Letters (char c);
    ~Letters ();
    char Value ();

    //클래스 메소드
    static int Number (){//static 함수는 cpp file에 정의할 수 없다
		//cout << ch;//왜 오류가 발생하는지를 알아야 한다
        return num;
    }
};