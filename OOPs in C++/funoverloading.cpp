#include<iostream>
using namespace std;

void area(int a)
{
    cout<<"Area of square = "<<a*a<<endl;
}

void area(int l,int b)
{
    cout<<"Area of rectange = "<<l*b<<endl;
}

int main(){

    area(5);
    area(5,10);

    return 0;
}