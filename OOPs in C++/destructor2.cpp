#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Parent class constructor is called"<<endl;
    }

    ~A()
    {
        cout<<"Parent class destructor called"<<endl;
    }
};

class B:public A
{

    public:
    B()
    {
        cout<<"Child class constructor is called"<<endl;
    }
    ~B()
    {
        cout<<"Child class destructor called"<<endl;
    }

};

int main()
{
    A objA;

    B objB; 

    return 0;
}