#include<iostream>
using namespace std;

int main()
{
    try
    {
         try
         {

        //    throw 5;
              throw 1.2;
         }
         catch(int e1)
         {
           cout<<"Inner int catch,a:"<<e1<<endl;
           throw e1;
         } 
         catch(double e2)
         {
            cout<<"Inner double catch,a:"<<e2<<endl;
            throw e2;
         }
    }
    catch(int e4)
    {
        cout<<"Outer int catch,a:"<<e4<<endl;
    }
    catch(double e5)
    {
        cout<<"Outer double catch,a"<<e5<<endl;
    }

    return 0;
}