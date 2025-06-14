//Compile time overring(method hiding)
#include<iostream>
using namespace std;

class A
{
    public:
    void display()
    {
        cout<<"You are in Base Class."<<endl;
    }
};

class B:public A{
    public:
    void display()
    {
        cout<<"You are in derived class."<<endl;
    }
};

int main()
{
    A objA;
    objA.display();

    B objB;
    objB.display();

    return 0;
}