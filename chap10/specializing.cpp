template<class T>
class Array { /*...*/ };

template<class T> // primary template
void sort(Array<T>& v);

template<>        // specialization for T = int
void sort(Array<int>&);

// no need to write
// template<> void sort<int>(Array<int>&);

template<typename T>
struct A
{
    void f(T);         // member, declared in the primary template

    void h(T) {}       // member, defined in the primary template

    template<class X1> // member template
    void g1(T, X1);

    template<class X2> // member template
    void g2(T, X2);
};

// specialization of a member
template<>
void A<int>::f(int);

// member specialization OK even if defined in-class
template<>
void A<int>::h(int) {}

// out of class member template definition
template<class T>
template<class X1>
void A<T>::g1(T, X1) {}

// member template specialization
template<>
template<class X1>
void A<int>::g1(int, X1);

// member template specialization
template<>
template<>
void A<int>::g2<char>(int, char); // for X2 = char

// same, using template argument deduction (X1 = char)
template<>
template<>
void A<int>::g1(int, char);

template<class T1>
class A
{
    template<class T2>
    class B
    {
        template<class T3> // member template
        void mf1(T3);

        void mf2();        // non-template member
    };
};

// specialization
template<>        // for the specialized A
template<class X> // for the unspecialized B
class A<int>::B
{
    template<class T>
    void mf1(T);
};

// specialization
template<>        // for the specialized A
template<>        // for the specialized B
template<class T> // for the unspecialized mf1
void A<int>::B<double>::mf1(T t) {}

// ERROR: B<double> is specialized and is a member template, so its enclosing A
// must be specialized also
template<class Y>
template<>
void A<Y>::B<double>::mf2() {}
//************************
template <class  T>
class SortedArray //일반적인 template class
{
    ...
        if (data1 < data2) ...
};
//explicit specialization
template <> class Classname<specialized - type - name> { ... };

class Classname<specialized - type - name> { ... };//C++ 기존 version에서 사용하는 방법

template <> class SortedArray<const char char*> //explicit specialization 
{
    ...
        if (!strcmp(data1, data2)) // operator > 대신 사용

};
void main() {
    SortedArray<int> scores; // general definition을 사용
    SortedArray<const char*> dates; // specialized definition을 사용
}
//************************
// general template
template <class T1, class T2> class Pair { ... };

// partial specialization : T2 = int
template <class T1> class Pair<T1, int> { ... };

// complete explicit specialization : T1(int),  T2(int)
template <> class Pair<int, int> { ... };

Pair<double, double> p1; //  general Pair template instantiation을 사용
Pair<double, int> p2; // use Pair<T1, int> partial specialization 사용
Pair<int, int> p3; // use Pair<int, int> explicit specialization 사용
//************************

template<class T> // 일반적인 template version
class Feeb { ... };

template<class T*> // pointer partial specialization
class Feeb { ... }; // pointer를 지원하는 수정된 코드

// general template
template <class T1, class T2, class T3> class Trio { ... };

// partial specialization : T3(T2)
template <class T1, class T2> class Trio<T1, T2, T2> { ... };

// partial specialization : T3(T1*), T2(T1*)
template <class T1> class Trio<T1, T1*, T1*> { ... };

void main() {
    Feeb<char> fb1; // 일반적인 Feeb template의 instantiation 사용
    Feeb<char*> fb2; // Feeb T* specialization된 code 사용

    Trio<int, short, char*> t1; // 일반적인 template instantiation code 사용
    Trio<int, short> t2; // Trio<T1, T2, T2> partial specialization 사용
    Trio<char, char*, char*> t3; //Trio<T1, T1*, T1*> partial specialization 사용
}