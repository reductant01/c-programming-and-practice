/*
7�� class inheirtance ����
1) �������� ����
2) operator<<()�� ����
3) friend ��� 
*/
#include <iostream>
using namespace std;

class Person {
private:
	char pid[20];//�ֹι�ȣ
	char pname[20];
	int age;
public:


};
class Student : protected Person {};
ostream& operator<<(ostream& s, Person p); //����
class Student : protected Person {
private:
	char sid[20]; //�й�
	int studentYear; //�г�
	char deptName[20];
protected:
	char major[10]; //����
public:

};
ostream& operator<<(ostream& s, Student s); //����
class ITStudent  : private Student {
private:
	char codingSkills[20];//�ڵ� ���

public:

};
ostream& operator<<(ostream& s, ITStudent it); //����
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