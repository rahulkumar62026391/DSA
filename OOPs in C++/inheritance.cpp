#include<iostream>
using namespace std;

class A{
    private:
    int x=10;

    protected:
    int y=20;

    public:
    int z=30;

    private:

    void display1A(){
        // cout<<x<<endl;
        // cout<<y<<endl;
        // cout<<z<<endl;
        cout<<"Inside 1A "<<endl;
    }

    protected:
    void display2A(){
       // cout<<x<<endl;
       // cout<<y<<endl;
        //cout<<z<<endl;
        cout<<"Inside 2A"<<endl;
    }

    public:
    void display3A(){
        // cout<<x<<endl;
        // cout<<y<<endl;
        // cout<<z<<endl;
        cout<<"Inside 3A"<<endl;
    }

};

class B : public A{
    public:
    void printB(){
    cout<<y<<endl;
    display2A();
    }

    

};

class C : protected A{
    public:
    void printC(){
    cout<<z<<endl;
    display3A();
    }

    
};

class D : private A{
    public:
    void printD(){
    cout<<z<<endl;
    display3A();
    }
};

class E : public D{
    public:
    void show(){
   //cout<<z<<endl;
    //display3A();
    }
};

int main(){

    B b;
     cout<<b.z<<endl;;
    // b.display3A();
    //b.printB();

    //A a;
   

    C c;
    //c.printC();
    //cout<<c.z<<endl;

    E e;
    //e.show();

    D d;
    //cout<<d.z<<endl;

    return 0;
}