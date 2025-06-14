//Run time overriding
#include<iostream>
using namespace std;

class A
{
    public:
    void show()
    {
        cout<<"You are in Base class."<<endl;
    }
    virtual void display()
    {
        cout<<"You are in Base class."<<endl;
    }
    void printA()
    {
        cout<<"You are in Base class."<<endl;
    }
};

class B: public A
{
    public:
    void show()
    {
        cout<<"You are in derived class."<<endl;
    }
    void display() override
    {
        cout<<"You are in derieved class."<<endl;
    }
    void printB()
    {
        cout<<"You are in derived class."<<endl;
    }
};
int main()
{
    A *ptr;
    B b;
    ptr=&b;
   
    ptr->show();
    ptr->display();

    ptr->printA();
    //ptr->printB();

    B *ptr2=(B*)ptr;
    ptr2->printB();




    // A *ptr=new B;
    // B *ptr2;
    // ptr2=&b;
    // ptr2->show();
    // ptr2->display();

    return 0;
}