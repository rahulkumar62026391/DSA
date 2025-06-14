#include<iostream>
using namespace std;

class Complex{
    int real;
    int img;

    public:
   // Complex(){}
    Complex(int rl,int im){
        real=rl;
        img=im;
    }

    Complex operator + (Complex &other){
        Complex temp(0,0);
        temp.real=real+other.real;
        temp.img=img+other.img;
        return temp;
    }

    void display(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
};

int main(){
    Complex c1(5,7);
    Complex c2(4,5);

    c1.display();
    c2.display();

    Complex sum=c1 + c2;
    sum.display();

    return 0;
}