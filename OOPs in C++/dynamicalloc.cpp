#include<iostream>
using namespace std;

int main()
{
    int *a=new int(5);
    int *b=new int;
    *b=10;
    cout<<"a : "<<*a<<endl;
    cout<<"b : "<<*b<<endl;

    delete a;
    a=nullptr;

    delete b;
    b=nullptr;

    int size=3;

    int *array=new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter value at index "<<i<<" : ";
        cin>>array[i]; 
    }

    for(int j=0;j<size;j++)
    {
        cout<<"Value at index "<<j<<" : "<<array[j]<<endl;
    }

    delete[] array;
    array=nullptr;
    return 0;
}