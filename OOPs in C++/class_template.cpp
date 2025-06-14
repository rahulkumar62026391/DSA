#include<iostream>
using namespace std;

template<class T>

class Sum
{
    T a;
    T b;

    public:
    void add(T x,T y)
    {
        a=x;
        b=y;
        cout<<a+b<<endl;
    }

};

int main()
{
    Sum<int> obj1;
    Sum<double> obj2;

    obj1.add(5,10);
    obj2.add(10.5,7.2);
    
    return 0;
}