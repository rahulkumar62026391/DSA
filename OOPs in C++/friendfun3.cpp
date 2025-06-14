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
    friend void sum(A obj1,B obj2);
};

class B
{
    int b;
    public:
    B(int y)
    {
        b=y;
    }
    friend void sum(A obj1,B obj2);
};

void sum(A obj1,B obj2)
{
    int sum=obj1.a+obj2.b;
    cout<<"Sum is "<<sum<<endl;
}

int main()
{
    A obj1(5);
    B obj2(10);

    sum(obj1,obj2);

    return 0;
}