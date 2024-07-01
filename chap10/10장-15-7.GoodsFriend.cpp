//10장-15-7.Goods.cpp [PRATA2005] 10.4.3 template을 이용한 Container class 표현
//friend function template - the bound template friends
#include <iostream>
using namespace std;
//declare template function before the class definition
template <typename T> void showCounter();
template <typename T> void display(T &);

template <typename T>
class Goods
{
private:
	T item;
	static int counter;
public:
	Goods(const T& i) : item(i) { counter++; }
	~Goods() { counter--; }
	friend void showCounter<T>();//bound template friends
	//friend void display<>(Goods<T>&);//bound template friends with template specialization -> Goods<T>&로 부터 유추할 수 있어서 <T>를 생략
	friend void display<T>(Goods<T>&);//bound template friend
};


template <typename T>
int Goods<T>::counter = 0;
//template friend function definition
template <typename T>
void showCounter()
{
	cout << "counter: " << Goods<T>::counter << "; " << endl;
	//cout << "double counter: " << Goods<double>::counter << endl;
}
template <typename T>
void display(Goods<T>& g)
{
	cout << "display():: " << g.item << endl;
}

int main()
{
	Goods<int> gi1(10);
	showCounter<int>();
	showCounter<int>();
	Goods<int> gi2(20);
	showCounter<int>();
	Goods<double> gd(10.5);
	showCounter<double>();
	display(gi1);
	display(gd);
	system("pause");
	return 0;
}