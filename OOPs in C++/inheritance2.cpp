#include<iostream>
using namespace std;


class A
{
    public:

    void displayA(){
        cout<<"Inside A"<<endl;
    }
};

class B :virtual public A
{
public:

    void displayB(){
    cout<<"Inside B "<<endl;
    }
};

class C :virtual public A{
    public:

    void displayC(){
        cout<<"Inside C"<<endl;
    }
};

class D: public B,public C{
public:

void displayD(){
    cout<<"inside D"<<endl;
}
};

int main(){

    A a;
    a.displayA();

    cout<<endl;

    B b;
    b.displayB();
    b.displayA();

    cout<<endl;

    C c;
    c.displayC();
    c.displayA();

    cout<<endl;

    D d;
    d.displayD();
    d.displayB();
    d.displayC();
    d.displayA();

    return 0;
}