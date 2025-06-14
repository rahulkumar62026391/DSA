#include<iostream>
using namespace std;

class A
{
    public:
    A()
    {
        cout<<"Constructor is called in class A"<<endl;
    }
    // ~A()
    // {
        // cout<<"Destructor is called in class A"<<endl;
    // }

    virtual ~A()
    {
         cout<<"Destructor is called in class A"<<endl;
    }
};
class B:public A
{
    public:
    B()
    {
        cout<<"Constructor is called in class B"<<endl;
    }
    ~B()
    {
        cout<<"Destructor is called in class B"<<endl;
    }
};

int main()
{
    A *ptr=new B;

    delete ptr;

    return 0;
}