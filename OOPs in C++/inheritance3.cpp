#include<iostream>
using namespace std;

class A{
    public:
    void displayA(){
    cout<<"Inside A"<<endl;
    }
};

class B :public A{
    public:
    void displayB(){
    cout<<"Inside B"<<endl;
    }
};

class C : public B{
    public:
    void displayC(){
    cout<<"Inside C"<<endl;
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
    c.displayB();
    c.displayA();
    return 0;
}