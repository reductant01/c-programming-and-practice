/*
7장 class inheirtance 과제
1) 생성자의 재사용
2) operator<<()의 재사용
3) friend 사용 
*/
#include <iostream>
using namespace std;

class Person {
private:
	char pid[20];//주민번호
	char pname[20];
	int age;
public:


};
class Student : protected Person {};
ostream& operator<<(ostream& s, Person p); //구현
class Student : protected Person {
private:
	char sid[20]; //학번
	int studentYear; //학년
	char deptName[20];
protected:
	char major[10]; //전공
public:

};
ostream& operator<<(ostream& s, Student s); //구현
class ITStudent  : private Student {
private:
	char codingSkills[20];//코딩 언어

public:

};
ostream& operator<<(ostream& s, ITStudent it); //구현
int main(void) {
	ITStudent s1();
	cout << s1;
	ITStudent s2 = s1;
	cout << s2;
	ITStudent s3;
	s3 = s1;
	cout << s3;
	system("pause");
	return 1;
}