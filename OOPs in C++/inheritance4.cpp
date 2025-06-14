#include<iostream>
using namespace std;

class A
{
    private:
    int a;
    protected:
    int b;
    public:
    int c;

    A()
    {
        a=10;
        b=20;
        c=30;
    }
};
class B : public A
{
    public:
    // void displayB1()
    //{
    //  cout<<"Value of a using derived class B : "<<a<<endl;
    //}
   void displayB2()
   {
     cout<<"Value of b using derived class B : "<<b<<endl;
   }
   void displayB3()
   {
     cout<<"Value of c using derived class B : "<<c<<endl;
   }

};

class C : protected A
{
    public:
  //  void displayC1()
  // {
  //  cout<<"Value of a using derived class C : "<<a<<endl;
  //}
   void displayC2()
   {
     cout<<"Value of b using derived class C : "<<b<<endl;
   }
   void displayC3()
   {
     cout<<"Value of c using derived class C : "<<c<<endl;
   }

};

class D : private A
{
    public:
  //  void displayD1()
  //{
  // cout<<"Value of a using derived class D : "<<a<<endl;
  //}
   void displayD2()
   {
     cout<<"Value of b using derived class D : "<<b<<endl;
   }
   void displayD3()
   {
     cout<<"Value of c using derived class D : "<<c<<endl;
   }

};

int main()
{
    B objB;
    //objB.displayB1();
    objB.displayB2();
    objB.displayB3();

    C objC;
   //objC.displayC1();
    objC.displayC2();
    objC.displayC3();

    D objD;
    //objD.displayD1();
    objD.displayD2();
    objD.displayD3();


    return 0;
}