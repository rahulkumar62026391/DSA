#include<iostream>
using namespace std;

class Area{

    float l;
    float b;
    float area;

    public:

    Area(float a , float b){
        l=a;
        b=b;
        float area=l*b;
        this->area=area;
    }
    Area(float a){
        l=a;
        float area=a*a;
        this->area=area;
    }

    void display(){
        cout<<"Area : "<<area<<endl;
    }

};

int main(){

        Area a1(4,5);
        a1.display();

        Area a2(5);
        a2.display();


    return 0;
}