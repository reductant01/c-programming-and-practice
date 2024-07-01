//학번:
//이름:
//인증번호:
//상기 3가지 미기재시 채점 대상 제외 
//private은 수정 불가하다, string은 include하여 사용 가능하다
class Dept {
private:
    string dname;
    char* city;
public:
    operator<<(ostream&, Dept&);
    operator>>(istream&, Dept&);
};

class Emp {
private:
    string* ename;
    Dept* dept;

public:
    friend Emp& changeName(Emp&);
    operator<<(ostream&, Dept&);
    operator>>(istream&, Dept&);
};
class Stack {
private:
    Emp* items[20];
    int top; //top 변수는 현재 저장된 객체의 마지막 색인 번호: 0부터 시작한다.
public:
    void push(Emp&);//중복 체크하여 같으면 입력하지 않는다. 중복은 ename만으로 체크한다
    Emp& pop();
};

Emp& changeName(Emp& e) {
    //e.ename을 변경한다
}
int main() {
    while (1)
    {
        Stack s2;

        int select;
        cout << "\n선택 1: Push, 2. PoP, 3: 스택 모든 객체 출력,4. Pop한 객체의 이름 변경, 5. 종료" << endl;
        
        cin >> select;
        switch (select) {
        case 1:
            //화면에서 입력받는데 operator>>()를 사용한다.
            for () {//최소 3회 이상
                Emp e = new Emp();
                cin >> e;
                s2.push(e);
            }
            break;
        case 2:
            for () { //최소 3회 이상
                Emp e2 = s2.pop();
                cout << e2; //Emp 출력은 Dept 출력까지 처리해야 한다 
            }
            break;

        case 3:// 스택 출력 > Emp 출력 > Dept 출력
            cout << s2;
            break;
        case 4:
            Emp e3 = s2.pop();
            Emp e4;
            e4 = changeName(e3);
            break;

        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 1;
    //프로그램 종료시에 run-time이 없도록 소멸자 구현과 delete 호출 사용
}


