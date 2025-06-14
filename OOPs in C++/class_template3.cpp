#include<iostream>
using namespace std;

template<class T1,class T2>

class A
{
    T1 a;
    T2 b;
    public:

    void display(T1 x)
    {
        a=x;
        cout<<"a : "<<a<<endl;
    }

    void display(T1 x, T2 y)
    {
        a=x;
        b=y;
        cout<<"a : "<<a<<" b : "<<b<<endl;
    }
};

int main()
{
    A<int,int> obj1;
    A<int,double> obj2;
    A<double,double> obj3;

    obj1.display(5);
    obj2.display(5,7.5);
    obj3.display(5.5,7.2);


    return 0;
}