#include<iostream>
using namespace std;

int main()
{

    try
    {
       int a,b;
       double quotient;
       cout<<"Enter a:";
       cin>>a;
       cout<<"Enter b:";
       cin>>b;
       if(b==0)
       {
        throw 0;
       }
       quotient=(double)a/b;
       cout<<quotient<<endl;

    }
    catch(int e)
    {
       cout<<"Division by Zero!";
    }
    return 0;
}