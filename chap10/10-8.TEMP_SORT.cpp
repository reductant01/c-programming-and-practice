// 10-8.TEMP_SORT.CPP 10.5 template 함수
#include <iostream>
using namespace std;

template <class T>
void sort (T *ele, int num){
    cout << "sort() 수행" << endl << endl;
    for (int temp = 0; temp < num; temp++){
        int temp2 = temp;
        for (int temp3 = temp + 1; temp3 < num; temp3++)
            if (ele[temp3] < ele[temp2]){
                temp2 = temp3;
            }
        T arg = ele[temp]; 
        ele[temp] = ele[temp2]; 
        ele[temp2] = arg;
    }
}
template <class T>
void print (T *ele, int num){
    for(int i=0; i<num; i++){
        cout << ele[i] << " ";
    }
    cout << endl << endl;
}
class Number {
    double num;
public:
    Number(double num2) : num(num2) { }
    double Value() {
        return num;
    }
    bool operator < (Number numBer2) {
        return num < numBer2.Value();
    }
    friend ostream& operator<<(ostream& os, Number& num);
};
ostream& operator<<(ostream& os, Number& num) {
    os << num.num;
    return os;

}
void main (){
    int arr1[10] = {5, 6, 1, 7, 9, 3, 2, 0, 4, 8};
    float arr2[10] = {4.1, 1.2, 5.0, 6.3, 2.3, 0.4, 7.7, 8.5, 3.1, 9.0};
    char* str[10] = { "kim" };
    cout << "sort() 호출 전 " << endl;
    print(arr1, 10);
    sort(arr1, 10);
    cout << "sort() 호출 후 " << endl;
    print(arr1, 10);
    sort(str, 10);//연산자 지원 여부 확인 필요 
    print(str, 10);
    Number data[10] ={ Number(1.1),Number(2.2), Number(3.1),Number(4.2),Number(5.1),Number(6.2),Number(1.3),Number(2.4),Number(1.6),Number(2.5) };
    sort(data, 10);
    print(data, 10);
    system("pause");
}