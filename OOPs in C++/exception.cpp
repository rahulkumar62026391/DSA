#include<iostream>
using namespace std;

int main()
{
    try
    {
        // throw 3.14;
        throw 5;
    }
    catch(int e1)
    {
       cout<<"Caught int: "<<e1<<endl;
    }
    catch(double e2)
    {
        cout<<"Caught double: "<<e2<<endl;
    }
    catch(...)
    {
        cout<<"Unknown error!"<<endl;
    }

    return 0;
}