// choices.cpp -- array a2ariations
//STL - vector 실습

//STL:: vector, pair, set, map, stack, queue, priority_queue, bitset
#include <iostream>
#include <vector> // STL C++98
#include <array> // C++11
using namespace std;
void print_a2(vector<double> a2)
{
	cout << " a2의 원소 : ";
	for (int i = 0; i < a2.size(); i++)
		cout << a2[i] << " ";
}
int main()
{
	using namespace std;
	// C, original C++
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
	// C++98 STL
	vector<double> a2(4); // create vector with 4 elements
	// no simple way to initialize in C98
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;
	// C++11 -- create and initialize array object
	array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
	array<double, 4> a4;
	a4 = a3; // valid for array objects of same size
	// use array notation
	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	// misdeed
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
	cout << a2.size() << endl;
	cout << a2.capacity() << endl;
	a2.push_back(1);
	a2.push_back(2);
	a2.push_back(3);
	print_a2(a2); // 1 2 3

	cout << "\n\n a2의 1번째 위치에 4 삽입\n";
	a2.insert(a2.begin() + 1, 4);
	print_a2(a2); // 1 4 2 3

	cout << "\n\n a2의 마지막 원소 삭제\n";
	a2.pop_back();
	print_a2(a2); // 1 4 2


	cout << "\n\n a2의 맨 뒤에 6 삽입\n";
	a2.push_back(6);
	print_a2(a2); // 1 4 2 6
	// ************** iterator
	vector<double>::iterator iter;
	// vector 반복자 iter는 v의 시작점을 가리킴
	iter = a2.begin();

	cout << endl <<
		&iter << endl;
	cout << *iter << endl;
	// 임의 접근
	cout << iter[1] << endl;

	iter += 2; // += 연산 사용
	cout << &iter << endl;
	cout << *iter << endl;

	// 반복
	for (iter = a2.begin(); iter != a2.end(); iter++) {
		cout << *iter << endl;
	}
	cout << "\n\n a2의 원소 전체 clear!\n";
	a2.clear();
	print_a2(a2); // empty


	system("pause");
	return 0;
}