#include<iostream>
using namespace std;

template<class T>

class A
{
    T a;
    T b;
    public:
    A(T x)
    {
        a=x;
        cout<<" a: "<<a<<endl;
    }

    A(T x,T y)
    {
        a=x;
        b=y;
        cout<<" a: "<<a<<" b: "<<b<<endl;
    }
};

int main()
{
    A<int> obj1(5);
    A<int> obj2(50,45);

    return 0;
}