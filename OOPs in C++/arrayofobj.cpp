#include<iostream>
using namespace std;

class A
{
    int id;
    public:
    void getData()
    {
        cout<<"Enter ID :";
        cin>>id;
    }
    void putData()
    {
        cout<<id<<endl;
    }
};
int main()
{
    cout<<"Object without pointer"<<endl;
    A obj1;
    obj1.getData();
    obj1.putData(); 

    cout<<"Array of object without pointer"<<endl;
    int size=3;
    A obj2[size];

    for(int i=0;i<size;i++)
    {
        obj2[i].getData();
    }

    for(int j=0;j<size;j++)
    {
        cout<<"ID of obj "<<j+1<<" : ";
        obj2[j].putData();
    }

    cout<<"Object using pointer"<<endl;
    A *obj3=new A;
    // A *obj3=new A();
    // (*obj3).getData();
    // (*obj3).putData();

        obj3->getData();
        obj3->putData();

    cout<<"Array of objects using pointer"<<endl;
    A *obj4=new A[size];
    A *temp=obj4;

    for(int i=0;i<size;i++)
    {
        // (*obj4).getData();
            obj4->getData();
            obj4++;
    }
    for(int j=0;j<size;j++)
    {
        cout<<"ID of obj "<<j+1<<" : ";
        // (*temp).putData();
            temp->putData();
            temp++;
    }

    return 0;
}