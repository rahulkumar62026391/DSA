#include<iostream>
using namespace std;

class A
{
    int a;
    public:
    void getA(int x)
    {
        a=x;
    }
    // A(int x){
        // a=x;
    // }

    void displayA()
    {
        cout<<"Value of a :"<<a<<endl;
    }

    class B
    {
        int b;

        public:
        void getB(int y)
        {
            b=y;
        }
        // B (int y)
        // {
            // b=y;
        // }


        void displayB()
        {
            cout<<"Value of b :"<<b<<endl;
        }
    };
};

int main()
{
    // A objA(5);
    A objA;
    objA.getA(5);
    objA.displayA();

    // A::B objB(10);
    A::B objB;
    objB.getB(10);
    objB.displayB();

    return 0;
}