#include<iostream>
using namespace std;

// class Calculator{

// private:
// int num1;
// int num2;

// public:
// Calculator(int n1=0,int n2=0){
//     this->num1=n1;
//     this->num2=n2;
// }

// int sum(){
//     return this->num1 + this->num2;
// }

// int difference(){
//     return this->num1 - this->num2;
// }

// int product(){
//     return this->num1 * this->num2;
// }

// int quotient(){
//     return this->num1 / this->num2;
// }

// int modulus(){
//     return this->num1 % this->num2;
// }
// };

// class Calculator{

// public:
// int num1;
// int num2;

// int sum(){
//     return this->num1 + this->num2;
// }

// int difference(){
//     return this->num1 - this->num2;
// }
// int product(){
//     return this->num1 * this->num2;
// }

// int quotient(){
//     return this->num1 / this->num2;
// }

// int modulus(){
//     return this->num1 % this->num2;
// }
// };

class Calculator{

private:
int num1;
int num2;

public:
int sum(int x,int y){
    this->num1=x;
    this->num2=y;
    return this->num1 + this->num2;
}

int difference(int x,int y){
    this->num1=x;
    this->num2=y;
    return this->num1 - this->num2;
}
int product(int x,int y){
    this->num1=x;
    this->num2=y;
    return this->num1 * this->num2;
}

int quotient(int x,int y){
    this->num1=x;
    this->num2=y;
    return this->num1 / this->num2;
}

int modulus(int x, int y){
    this->num1=x;
    this->num2=y;
    return this->num1 % this->num2;
}
};

int main(){

//     int a=50;
//     int b=10;
// Calculator cal(a,b);

// cout<<"Sum of "<< a << " and "<< b <<" is "<<cal.sum()<<endl;
// cout<<"Difference of "<< a << " and "<< b <<" is "<<cal.difference()<<endl;
// cout<<"Product of "<< a << " and "<< b <<" is "<<cal.product()<<endl;
// cout<<"Quotient of "<< a << " and "<< b <<" is "<<cal.quotient()<<endl;
// cout<<"Modulus of "<< a << " and "<< b <<" is "<<cal.modulus()<<endl;


// Calculator cal;
// cal.num1=50;
// cal.num2=10;

// cout<<"Sum of "<< cal.num1 << " and "<< cal.num2 <<" is "<<cal.sum()<<endl;
// cout<<"Difference of "<< cal.num1 << " and "<< cal.num2 <<" is "<<cal.difference()<<endl;
// cout<<"Product of "<< cal.num1 << " and "<< cal.num2 <<" is "<<cal.product()<<endl;
// cout<<"Quotient of "<< cal.num1 << " and "<< cal.num2 <<" is "<<cal.quotient()<<endl;
// cout<<"Modulus of "<< cal.num1 << " and "<< cal.num2 <<" is "<<cal.modulus()<<endl;

Calculator cal;

cout<<"Sum is "<<cal.sum(50,10)<<endl;
cout<<"Difference is "<<cal.difference(50,10)<<endl;
cout<<"Product is "<<cal.product(50,10)<<endl;
cout<<"Quotient is "<<cal.quotient(50,10)<<endl;
cout<<"Modulus is "<<cal.modulus(50,10)<<endl;


    return 0;
}