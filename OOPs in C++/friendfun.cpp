#include<iostream>
using namespace std;

class Calculator
{
    int a=10;
    int b=20;

    public:
    friend void sum(Calculator obj1);

};

void sum(Calculator obj1)
{
    int sum1=obj1.a+obj1.b;
    cout<<"Sum is "<<sum1<<endl;
}

int main(){
    Calculator obj1;

    sum(obj1);

    return 0;
}