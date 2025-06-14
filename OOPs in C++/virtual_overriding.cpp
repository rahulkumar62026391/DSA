#include<iostream>
using namespace std;

class Parent{

    public:
    virtual void display(){
        cout<<"I am Parent class."<<endl;
    }
};

class Child : public Parent{
    public:
    void display() override{
        cout<<"I am Child class."<<endl;
    }

};

int main(){

    Parent * ptr;
    Child child;
    ptr=&child;
    ptr->display();
    child.display();

    Parent parent;
    parent.display();

    return 0;
}