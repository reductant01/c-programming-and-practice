//학번:
//이름:
//인증번호:
//상기 3가지 미기재시 채점 대상 제외 
//private은 변경 불가함
class Dept {
private:
    string dname;//include string 사용 가능
    char* city;
};
class Employee {
private:
	char * ename;
	Dept *dept;
};

int main() {
    while (1)
    {
        Employee *guests[5];

        int select;
        cout << "\n선택 1: 입력, 2. 출력, 3: 정렬, 4. 정렬결과 출력, 5. 검색, 6.종료" << endl;

        cin >> select;
        switch (select) {
        case 1:
            //화면에서 입력받는데 operator>>()를 사용한다.
            for () {
                Employee e = new Employee();
                cin >> e;
                guests[i] = e;
            }
            break;
        case 2:// guests[]를 출력한다.
            for () {
                Employee *e = guests[i];
                cout << *e;
            }

            break;

        case 3:
            //guests[] 를 정렬한 결과를 guests[]에 보관
            // 정렬시에  Employee의 operator>()를 사용해야 한다. main()에서 스트링 비교하는 것을 금지한다. 
            // 알고리즘 헤더를 사용하거나 직접 구현
            break;
        case 4://정렬 결과 출력: case3으로 정렬한 후에 출력이다 따라서 case와 같은 코드 사용
            for () {
                Employee* e = guests[i];
                cout << *e;
            }
        case 5://입력받은 ename을 갖는 employee를 guests[]에서 찾는다
            string ename;
            cin >> ename;
            //guests[]에서 ename을 갖는 Employee를 출력한다.
            cout << e;
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


