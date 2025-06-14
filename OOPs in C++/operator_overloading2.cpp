#include<iostream>
using namespace std;

class Increment
{
    int a;
    public:
    Increment(int x)
    {
        a=x;
    }
    void operator +()
    {
        a=a+1;
    }
    void display()
    {
        cout<<a<<endl;
    }
};
int main()
{
    Increment i(10);
    i.display();
    +i;
    i.display();
    return 0;
}