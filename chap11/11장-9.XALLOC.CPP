// 11장-9.XALLOC.CPP 11.7 new를 사용한 메모리 할당
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define COUNT 50000
using namespace std;

int main() {
    char* hugeArray[COUNT];
    int count;
    try {
        for (count = 0; count < 1000000; count++) {
                hugeArray[count] = new char[0x7ffffffe];
                cout << "Memory allocated for element " << count << endl;          
        }
        cout << endl;
        cout << "All requested memory allocated..." << endl;
        cout << endl;

        for (int i = 0; i <count; count++) {
            delete hugeArray[i];
            cout << "Memory de-allocated for element " << count << endl;
        }
    }
    catch (const std::bad_alloc& e) {
        cout << "No more memory for element: " << e.what() << endl;
        for (int j = 0; j < count && j < count; j++) {
            delete hugeArray[j];
            cout << "Memory de-allocated for element " << j << endl;
        }
    }
    catch (const exception& e) {
        cout << "An exception occurred: " << e.what() << endl;
        for (int j = 0; j < count && j < count; j++) {
            delete hugeArray[j];
            cout << "Memory de-allocated for element " << j << endl;
        }
    }
    cin.get(); // 콘솔에서 일시 중지
    return 0;
}