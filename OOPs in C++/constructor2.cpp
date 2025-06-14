#include<iostream>
using namespace std;

class A
{
    int a;
    public:
    // A() {}

    A()
    {
        a=0;
        cout<<"Default constructor is called with value : "<<a<<endl;
    }
    A(int x)
    {
        a=x;
        cout<<"Parameterized constructor is called with value : "<<a<<endl;
    }
    A(const A &obj)
    {
        a=obj.a;
        cout<<"Copy constructor is called with value : "<<a<<endl;
    }
    ~A()
    {
        cout<<"Destructor called with value : "<<a<<endl;
    }
};

int main()
{
    A obj1;
  //A obj1{};
    A obj2(5);
    A obj3=5;
    A obj4(obj2);
    A obj5=obj2;
    return 0;
}