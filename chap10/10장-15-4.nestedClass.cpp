//10장-15-4.nestedClass.cpp [PRATA2005] 10.4.3 template을 이용한 Container class 표현
#include <iostream>
using namespace std;
using std::endl;
template <typename T>
class outer
{
private:
	template <typename V> // nested template class member
	class inner
	{
	private:
	   V data;
	public:
	   inner(V v = 0) : data(v) {}
	   void show() const { cout <<"inner::show() = "<<data<< endl; }
	   V accessData() const { return data; }
	};
	   inner<T> ix; // inner template object's instantiation
	   inner<int> iy; // template object
public:
	   outer( T t, int i) : ix(t), iy(i) {}
	   template<typename U> U display(U u, T t) 
             { return (iy.accessData() + ix.accessData()) * u / t; }
	   void ShowOuter() const {
		   cout<<"outer::ShowOuter():ix.show() and n.show() is called => ";
		   ix.show();
		   iy.show();
	   }
};
int main()
{
	outer<double> ox(3.5, 3);
	ox.ShowOuter();
	cout << ox.display(10, 2.3) << endl;
	cout <<"Done\n";
	system("pause");
	return 0;
}