//�й�:
//�̸�:
//������ȣ:
//��� 3���� �̱���� ä�� ��� ���� 
//private�� ���� �Ұ��ϴ�, string�� include�Ͽ� ��� �����ϴ�
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
    int top; //top ������ ���� ����� ��ü�� ������ ���� ��ȣ: 0���� �����Ѵ�.
public:
    void push(Emp&);//�ߺ� üũ�Ͽ� ������ �Է����� �ʴ´�. �ߺ��� ename������ üũ�Ѵ�
    Emp& pop();
};

Emp& changeName(Emp& e) {
    //e.ename�� �����Ѵ�
}
int main() {
    while (1)
    {
        Stack s2;

        int select;
        cout << "\n���� 1: Push, 2. PoP, 3: ���� ��� ��ü ���,4. Pop�� ��ü�� �̸� ����, 5. ����" << endl;
        
        cin >> select;
        switch (select) {
        case 1:
            //ȭ�鿡�� �Է¹޴µ� operator>>()�� ����Ѵ�.
            for () {//�ּ� 3ȸ �̻�
                Emp e = new Emp();
                cin >> e;
                s2.push(e);
            }
            break;
        case 2:
            for () { //�ּ� 3ȸ �̻�
                Emp e2 = s2.pop();
                cout << e2; //Emp ����� Dept ��±��� ó���ؾ� �Ѵ� 
            }
            break;

        case 3:// ���� ��� > Emp ��� > Dept ���
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
    //���α׷� ����ÿ� run-time�� ������ �Ҹ��� ������ delete ȣ�� ���
}


