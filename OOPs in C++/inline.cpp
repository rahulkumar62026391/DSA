//Write a program that shows utility of line line finction.
#include<iostream>
using namespace std;

class Cube{
    int a;

    public:
    inline Cube(int x){
        a=x;
    }

    inline void greet(){
        cout<<"Hello"<<endl;
    }

    void area(){
        cout<<"Volume of Cube = "<<a*a*a<<endl;
    }

};

int main(){

    Cube cube(5);
    cube.greet();
    cube.area();


    return 0;
}