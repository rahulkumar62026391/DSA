#include<iostream>
using namespace std;

class Base
{
    public:
    virtual void vir_fun()=0;

};

class Derived: public Base
{
public:
void vir_fun() override
{
   cout<<"Derived virtual function."<<endl;
}
};

int main()
{
    Base *ptr;
    Derived d;
    ptr=&d;
    // Base *ptr=new Derived;
    // Derived * ptr2;
    // ptr2=&d;
    ptr-> vir_fun();
    // ptr2->vir_fun();
    return 0;
}