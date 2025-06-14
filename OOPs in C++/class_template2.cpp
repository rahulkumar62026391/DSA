#include<iostream>
using namespace std;

template<class T>

class A
{
    T a;
    T b;
    public:

    void display(T x)
    {
        a=x;
        cout<<"a : "<<a<<endl;
    }

    void display(T x,T y)
    {
        a=x;
        b=y;
        cout<<"a : "<<a<<" b : "<<b<<endl; 
    }

};

int main()
{
    A<int> obj1;

    obj1.display(5);
    obj1.display(10,15);

    return 0;
}