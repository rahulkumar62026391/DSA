//Virtual inheritance or diamond problem
#include<iostream>
using namespace std;

class A
{
    int a;
    public:
    A()
    {
        a=10;
    }
    void display()
    {
        cout<<"Value of a : "<<a<<endl;
    }
};
class B:virtual public A
{

};
class C:virtual public A
{

};
class D:public B,public C
{
    
};
int main()
{
    A objA;
    objA.display();
    D objD;
    //objD.display();  //member 'display' is ambiguous when we do not inherit claas A to class B and class C with virtual keyword.
    objD.display();
    return 0;
}