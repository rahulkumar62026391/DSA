#include<iostream>
using namespace std;

template<class T>

T add(T a,T b)
{
    T sum = a + b;
    return sum;
}

int main()
{

    cout<<add<int>(4,16)<<endl;
    cout<<add<double>(5.5,10.7)<<endl;

    return 0;
}