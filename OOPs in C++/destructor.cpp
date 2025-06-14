#include<iostream>
using namespace std;

int count=0;
class A
{
    public:
    A()
    {
        count++;
        cout<<"Object created,id : "<<count<<endl;
    }
    ~A()
    {
        cout<<"Object destroyed,id : "<<count<<endl;
        count--;
    }
};

int main()
{
    cout<<"Entering in main block : "<<endl;
    A a1,a2;

    cout<<"Entering first block : "<<endl;
    {
        A a3;
    }

    cout<<"Entering second block : "<<endl;
    {
        A a4;
    }

    cout<<"Returning to main block : "<<endl;

    return 0;
}