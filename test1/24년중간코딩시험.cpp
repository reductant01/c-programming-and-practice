/*
* SortStudents(), SwapStudents()은 직접 구현해야 한다 - C++의 algorithm에 있는 library 함수를 사용하지 않아야 한다
* SortStudents()는 클래스의 메소드로 구현된 a.SwapStudents(b)을 사용해야 한다.
* AddStudent(ts, sset2)는 TableStudent의 ts.AddStudent()을 호출하여 구현한다
* {  }이 종료되면 new에 의해 할당된 메모리는 반환되어야 한다.
*/

#include <iostream>
#include <cstring> //strcpy, strcmp는 class StringData에서만 사용되어야 한다 

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
    cout << "소멸자 호출" << endl;

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
    // 출력 형태 참조할 것 
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
    // 출력 형태
    //     --------------------------
    //     | 홍      | 22  |  부산  |
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

        //sset2 배열을 ts객체로 입력하는 함수를 만들어 구현한다
        AddStudents(ts, sset2);//중복 레코드는 입력하지 않는다 
        cout << "busan도시 검색 결과 = " << ts->SearchStudent(sx) << endl; //ts->SearchStudent(sx)는 tx.SearchStudent(sx)를 호출하여 구현해야 한다 
        SortStudents(ts);//정렬 순서: city > name > age - library의 sort()함수를 사용하지 말고 직접 구현해야 한다 - 클래스 함수가 아니다
        //객체들의 비교는 operator>()를 사용: student s1,s2의 비교는 s1 > s2로 한다. student의 city c1, c2 비교는 c1> c2를 사용한다 
        cout << "SortStudents() result = \n" << *ts << endl;
        cout << "the number of objects = " << Student::GetCount() << endl;
        delete ts;// {}이 종료되기 전에 반환되어야 한다
    }
    system("pause");
    return 0;
}