#include<iostream>
using namespace std;

class A
{
    public:
    void display()
    {
        cout<<"You are in class A."<<endl;
    }
};

int main()
{
    A *objA=new A;
    objA->display();

    delete objA;
    objA=nullptr;

    return 0;
}
