/*
* SortStudents(), SwapStudents()�� ���� �����ؾ� �Ѵ� - C++�� algorithm�� �ִ� library �Լ��� ������� �ʾƾ� �Ѵ�
* SortStudents()�� Ŭ������ �޼ҵ�� ������ a.SwapStudents(b)�� ����ؾ� �Ѵ�.
* AddStudent(ts, sset2)�� TableStudent�� ts.AddStudent()�� ȣ���Ͽ� �����Ѵ�
* {  }�� ����Ǹ� new�� ���� �Ҵ�� �޸𸮴� ��ȯ�Ǿ�� �Ѵ�.
*/

#include <iostream>
#include <cstring> //strcpy, strcmp�� class StringData������ ���Ǿ�� �Ѵ� 

using namespace std;

const int N = 10;

class StringData {
private:
    char* data;
public:
    StringData() {}
    StringData(const char* str);
    ~StringData();

    const char* GetData() const;
};

StringData::StringData(const char* str) {

    int length = strlen(str);

    data = new char[length + 1];
    strcpy(data, str);
};

StringData::~StringData() {
    cout << "�Ҹ��� ȣ��" << endl;

    if (data != nullptr) {
        delete[] data;
    }
};

const char* StringData::GetData() const {
    return data;
}


class Student {
private:
    StringData name;
    int age;
    StringData city;
    static int count;

public:
    Student() {}
    Student(const char* name, int age, const char* city);

    const char* GetName() const;
    const char* GetCity() const;
    const int GetAge() const;
    static int GetCount();
};


Student::Student(const char* name, int age, const char* city) {

    this->name = StringData(name);
    this->city = StringData(city);
    this->age = age;

    count++;
}

const char* Student::GetName() const {
    return name.GetData();
}

const char* Student::GetCity() const {
    return city.GetData();
}

const int Student::GetAge() const {
    return age;
};

int Student::GetCount() {
    return count;
}

int Student::count = 0;

ostream operator<<(ostream& stream, const Student& student) {
    // ��� ���� ������ �� 
}

class TableStudent {
private:
    Student table[N];
    int top;

public:
    TableStudent() {};

    const int GetTop() const;
    const char* GetName(int index) const;
    const char* GetCity(int index) const;
    const int GetAge(int index) const;

    SearchStudent(const Student& student) const;
    void AddStudent(const Student& student);
    friend ostream& operator<<(ostream& stream, const TableStudent& ts);
};

TableStudent::TableStudent() {
    top = 0;
};

const int TableStudent::GetTop() const {
    return top;
}

const char* TableStudent::GetName(int index) const {
    if (index < 0 || index >= top) {

        return nullptr;
    }
    return table[index].GetName();
}

const char* TableStudent::GetCity(int index) const {
    if (index < 0 || index >= top) {
        return nullptr;
    }
    return table[index].GetCity();
}

const int TableStudent::GetAge(int index) const {
    if (index < 0 || index >= top) {
        return -1;
    }
    return table[index].GetAge();
}

void TableStudent::AddStudent(const Student& student) {
    if (top < N) {
        table[top++] = student;
    }
}


ostream& operator<<(ostream& stream, const TableStudent& ts) {
    // ��� ����
    //     --------------------------
    //     | ȫ      | 22  |  �λ�  |
    //     --------------------------
}

static void AddStudents(TableStudent* ts, const Student sset2[]) {
    int size = sizeof(sset2) / sizeof(sset2[0]);
    for (int i = 0; i < size; ++i) {
        bool duplicate = false;
        for (int j = 0; j < ts->GetTop(); ++j) {
            if (strcmp(ts->GetName(j), sset2[i].GetName()) == 0 &&
                strcmp(ts->GetCity(j), sset2[i].GetCity()) == 0 &&
                ts->GetAge(j) == sset2[i].GetAge()) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            ts->AddStudent(sset2[i]);
        }
    }
}

int main() {
    {
        TableStudent* ts = new TableStudent();
        cout << "the number of objects = " << Student::GetCount() << endl;

        Student sx("Alice", 32, "Los Angeles");
        Student sset2[] = {
            {"kim John", 20, "New York"},
            {"Alice", 22, "Los Angeles"},
            {"hong", 23, "houston"},
            {"hong Bob", 21, "Chicago"},
            {"park Emily", 19, "San Francisco"},
            {"choi Michael", 23, "Seattle"},
            {"hong", 20, "New York"},
            {"Alice", 32, "Los Angeles"},
            {"park", 21, "Chicago"},
            {"Emily", 19, "San Francisco"},
            {"Alice", 22, "Los Angeles"},
            {"park", 23, "Seattle"},
            {"hong", 23, "houston"},
            {"park", 22, "New York"},
            {"lee", 13, "houston"},
            {"Alice", 22, "Los Angeles"},
            {"hong", 23, "houston"},
            {"lee", 19, "busan"},
            {"kim", 33, "jeju"}
        };

        //sset2 �迭�� ts��ü�� �Է��ϴ� �Լ��� ����� �����Ѵ�
        AddStudents(ts, sset2);//�ߺ� ���ڵ�� �Է����� �ʴ´� 
        cout << "busan���� �˻� ��� = " << ts->SearchStudent(sx) << endl; //ts->SearchStudent(sx)�� tx.SearchStudent(sx)�� ȣ���Ͽ� �����ؾ� �Ѵ� 
        SortStudents(ts);//���� ����: city > name > age - library�� sort()�Լ��� ������� ���� ���� �����ؾ� �Ѵ� - Ŭ���� �Լ��� �ƴϴ�
        //��ü���� �񱳴� operator>()�� ���: student s1,s2�� �񱳴� s1 > s2�� �Ѵ�. student�� city c1, c2 �񱳴� c1> c2�� ����Ѵ� 
        cout << "SortStudents() result = \n" << *ts << endl;
        cout << "the number of objects = " << Student::GetCount() << endl;
        delete ts;// {}�� ����Ǳ� ���� ��ȯ�Ǿ�� �Ѵ�
    }
    system("pause");
    return 0;
}