#include<iostream>
using namespace std;

template<class T>

void display1(T a)
{
    cout<<"a: "<<a<<endl;
}

template<class T1,class T2>

void display2(T1 x,T2 y)
{
    cout<<"x: "<<x<<" y:"<<y<<endl;
}

int main()
{
    display1(40);
    display2(4,10);

    return 0;
}