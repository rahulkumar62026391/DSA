#include<iostream>
using namespace std;

int main()
{
    int numerator,denominator;
    cout<<"Enter numerator : ";
    cin>>numerator;
    cout<<"Enter denominator : ";
    cin>>denominator;
    try
    {
        if(denominator==0)
        {
            throw 0;
        }

        float result=(float)numerator/denominator;
        cout<<result;
    }
    catch(int i)
    {
        cout<<"Division by 0 is not allowed !"<<endl; 
    }
    

    return 0;
}