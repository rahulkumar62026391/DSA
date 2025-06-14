#include<iostream>
using namespace std;

class A
{
    int a;
    double b;
    public:

    void display(int x)
    {
        a=x;
        cout<<" a : "<<a<<endl;
    }

    void display(double y)
    {
        b=y;
        cout<<" b : "<<b<<endl;
    }
};
int main()
{
    A obj;
    obj.display(5);
    obj.display(5.5);

    return 0;
}