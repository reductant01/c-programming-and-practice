//�й�:
//�̸�:
//������ȣ:
//��� 3���� �̱���� ä�� ��� ���� 
//private�� ���� �Ұ���
class Dept {
private:
    string dname;//include string ��� ����
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
        cout << "\n���� 1: �Է�, 2. ���, 3: ����, 4. ���İ�� ���, 5. �˻�, 6.����" << endl;

        cin >> select;
        switch (select) {
        case 1:
            //ȭ�鿡�� �Է¹޴µ� operator>>()�� ����Ѵ�.
            for () {
                Employee e = new Employee();
                cin >> e;
                guests[i] = e;
            }
            break;
        case 2:// guests[]�� ����Ѵ�.
            for () {
                Employee *e = guests[i];
                cout << *e;
            }

            break;

        case 3:
            //guests[] �� ������ ����� guests[]�� ����
            // ���Ľÿ�  Employee�� operator>()�� ����ؾ� �Ѵ�. main()���� ��Ʈ�� ���ϴ� ���� �����Ѵ�. 
            // �˰��� ����� ����ϰų� ���� ����
            break;
        case 4://���� ��� ���: case3���� ������ �Ŀ� ����̴� ���� case�� ���� �ڵ� ���
            for () {
                Employee* e = guests[i];
                cout << *e;
            }
        case 5://�Է¹��� ename�� ���� employee�� guests[]���� ã�´�
            string ename;
            cin >> ename;
            //guests[]���� ename�� ���� Employee�� ����Ѵ�.
            cout << e;
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


