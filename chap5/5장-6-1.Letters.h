//5��-6-1.Letters.h   5.5 class �����Ϳ� class �Լ�

// class Letters�� ����
class Letters {
private:
    // private ������:
    char ch;//private data member can be accessed within member functions
    static int num;//Ŭ���� ���

public:
    Letters (char c);
    ~Letters ();
    char Value ();

    //Ŭ���� �޼ҵ�
    static int Number (){//static �Լ��� cpp file�� ������ �� ����
		//cout << ch;//�� ������ �߻��ϴ����� �˾ƾ� �Ѵ�
        return num;
    }
};