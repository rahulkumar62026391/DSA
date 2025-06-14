// It is method hiding not overring
#include<iostream>
using namespace std;

class Parent{
    int roll;
    string name;

    public:
    void info(int rl,string nm){
        roll=rl;
        name=nm;
    }

    void display(){
        cout<<"Roll : "<<roll<<endl;
        cout<<"Name : "<<name<<endl;
    }
    void print(){
        cout<<"I am Parent class."<<endl;
    }
};

class Child : public Parent{
    int roll;
    string name;
    public:
    void info(int rl,string nm){
        roll=rl;
        name=nm;
    }

    void display(){
        cout<<"Roll : "<<roll<<endl;
        cout<<"Name : "<<name<<endl;
    }
    void print(){
        cout<<"I am Child class."<<endl;
    }
};

int main(){

    Parent p;
    p.info(1,"Rahul");
    p.display();
    p.print();
    Child c;
    c.info(2,"Ravish");
    c.display();
    c.print();

    return 0;
}