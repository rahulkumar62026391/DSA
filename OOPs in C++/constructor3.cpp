#include<iostream>
using namespace std;

class A
{
    int a;
    public:
    A()
    {
        a=10;
        cout<<"Constructor is called in base class with value : "<<a<<endl;
    }

    ~A()
    {
        cout<<"Destructor is called in base class."<<endl;
    }
};

class B : public A
{
    int b;
    public:
    B()
    {
        b=20;
        cout<<"Constructor is called in derived class with value : "<<b<<endl;
    }

    ~B()
    {
        cout<<"Destructor is called in derived class."<<endl;
    }
};

int main()
{
    //A objA;
    B objB;

    return 0;
}