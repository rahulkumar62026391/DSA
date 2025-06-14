#include<iostream>
using namespace std;

class Area{
    int l;
    int b;
    int area;

    public:
    Area(){
       l=10;
       b=5;
       area=l*b;
    }

    void display(){
        cout<<"Area : "<<area<<endl;
    }

};

int main(){

    Area a;
    a.display();

    return 0;
}