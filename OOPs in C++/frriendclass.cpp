#include<iostream>
using namespace std;

class B;

class A
{
    
    int a;
    public:
    A(int x)
    {
        a=x;
    }
    friend class B;
};

class B
{
    public:
    void showB(A objA)
    {
        cout<<"Private data a of class A is "<<objA.a<<endl;
    }
};

int main()
{
    A objA(5);
    B objB;
    objB.showB(objA);

    return 0;
}