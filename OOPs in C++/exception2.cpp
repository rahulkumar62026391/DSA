#include<iostream>
using namespace std;

int main()
{
    try
    {
        int a;
        cout<<"Enter a number:";
        cin>>a;
        if(a>10)
          {
            throw 1;
          }else{
            throw 1.1;
          }
    }
    catch(int e1)
    {
        cout<<"Caught: Number greater than 10."<<endl;
    }
    catch(double e2)
    {
        cout<<"Caught: Number lesser than 10."<<endl;
    }


    return 0;
}