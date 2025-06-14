#include<iostream>
using namespace std;

//int num=100;

int main(){

    //Sum of two number
    
    // double a,b;
    // cout<<"Enter 1st element:";
    // cin>>a;

    // cout<<"Enter 1st element:";
    // cin>>b;

    // cout<<"Sum of two element is "<<a+b;

    //Product of two numbers

    // double x,y;

    // cout<<"Enter 1st element:";
    // cin>>x;

    // cout<<"Enter 1st element:";
    // cin>>y;

    // cout<<"Product of two element is "<<x*y;

    //To print global and local variable

    // int num=10;

    // cout<<num<<endl; //To print local variable

    // cout<<::num<<endl;  //To print global variable

    //Afetr changing global variable

    // ::num=50;
    // cout<<::num;


    int n,sum=0;

    cout<<"Enter n :";
    cin>>n;

   // sum=(n*(n+1))/2;  //Using formula

  //cout<<sum;
    
    for(int i=1;i<=n;i++){  //Using for loop
        sum+=i;
    }

    cout<<sum;

    return 0;
}