
/*
 template class 실습용 코드 - 기존 코드를 보지 않고(책도 보지 않고) 아래 코드를 작성하는 훈련
 - 기억이 나지 않으면 책을 보고 공부한 후에 책을 덮고 보지 않은 상태에서 아래 코드 완성하기 훈련
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define Num 10
#define SIZE 100
template <class T>
class Stack
{
private:
	int nElements;
	T* data;
	int top;
public:
	Stack(int s = SIZE);
	~Stack() { delete[] data; }
	bool Empty() { return top == 0; }
	bool Full() { return top == nElements; }
	bool push(const T& item);
	bool pop(T& item);
};

Stack::Stack(int s = SIZE) : nElements(s), top(0)
{
	data = new T[nElements];
}


bool Stack::push(item)
{
	if (top < nElements)
	{
		cout << "Stack::push() = " << item << endl;
		data[top++] = item;
		return true;
	}
	else
		return false;
}


bool Stack::pop(item)
{
	if (top > 0)
	{
		item = data[--top];
		return true;
	}
	else
		return false;
}

class Recording
	// a recording with a composite key
{
public:
	Recording();
	Recording(char* label, char* idNum, char* title, char* composer, char* artist);
	char IdNum[7];
	char Title[30];
	char Composer[30];
	char Artist[30];
	char Label[7];
	void Print(ostream&) const;
};
Recording::Recording()
{
	IdNum[0] = 0;
	Title[0] = 0;
	Composer[0] = 0;
	Artist[0] = 0;
	Label[0] = 0;
}

Recording::Recording(char* label, char* idNum, char* title, char* composer, char* artist)
{
	strcpy(Label, label); strcpy(IdNum, idNum);
	strcpy(Title, title); strcpy(Composer, composer);
	strcpy(Artist, artist);
}
void Recording::Print(ostream& stream) const
{
	stream << Label << '|' << IdNum << '|' << Title << '|'
		<< Composer << '|' << Artist;
}
ostream& operator << (ostream&, Recording&);
ostream& operator << (ostream& stream, Recording& rec)
{
	rec.Print(stream);
	return stream;
}

int main()
{
	Stack<Recording> st;
	int n = 20;
	Recording* R[20], item;

	R[0] = new Recording("LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[1] = new Recording("RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");
	R[2] = new Recording("WAR", "23699", "Touchstone", "Corea", "Corea");
	R[3] = new Recording("ANG", "3795", "Symphony No. 9", "Beethoven", "Giulini");
	R[4] = new Recording("COL", "38358", "Nebraska", "Springsteen", "Springsteen");
	R[5] = new Recording("DG", "18807", "Symphony No. 9", "Beethoven", "Karajan");
	R[6] = new Recording("MER", "75016", "Coq d'or Suite", "Rimsky-Korsakov", "Leinsdorf");
	R[7] = new Recording("COL", "31809", "Symphony No. 9", "Dvorak", "Bernstein");
	R[8] = new Recording("DG", "139201", "Violin Concerto", "Beethoven", "Ferras");
	R[9] = new Recording("FF", "245", "Good News", "Sweet Honey in the Rock", "Sweet Honey in the Rock");
	R[10] = new Recording("1LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[11] = new Recording("1RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");
	R[12] = new Recording("1WAR", "23699", "Touchstone", "Corea", "Corea");
	R[13] = new Recording("1ANG", "3795", "Symphony No. 9", "Beethoven", "Giulini");
	R[14] = new Recording("1COL", "38358", "Nebraska", "Springsteen", "Springsteen");
	R[15] = new Recording("1DG", "18807", "Symphony No. 9", "Beethoven", "Karajan");
	R[16] = new Recording("1MER", "75016", "Coq d'or Suite", "Rimsky-Korsakov", "Leinsdorf");
	R[17] = new Recording("1COL", "31809", "Symphony No. 9", "Dvorak", "Bernstein");
	R[18] = new Recording("1DG", "139201", "Violin Concerto", "Beethoven", "Ferras");
	R[19] = new Recording("1FF", "245", "Good News", "Sweet Honey in the Rock", "Sweet Honey in the Rock");
	for (int i = 0; i < n; i++)
	{
		st.push(R[i]);
	}
	cout << st;
	for (int i = 0; i < n; i++)
	{
		st.pop(item);
		cout << item;
	}

	cout << "Bye\n";
	system("pause");
	return 0;
}