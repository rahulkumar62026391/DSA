#include<iostream>
#include<math.h>
using namespace std;

// int square(int num){
//     return num*num;
// }

// int cube(int num){
//     return num*num*num;
// }

// int main(){
//    cout<< square(10)<<endl;
//    cout<< cube(5)<<endl;

// }
class Exponent{
    double a;

public:
    Exponent(int nm){
        this->a=nm;
    }

double square(){
    double squ=a*a;
    return squ;
}
double cube(){
    double cub=a*a*a;
    return cub;
}

double squareroot(){
    double squrt=sqrt(a);
    return squrt;
}

double cuberoot(){
        double cubrt=cbrt(a);
        return cubrt;
    }
};
int main(){
    Exponent a(64);
    cout<<a.square()<<endl;
    cout<<a.cube()<<endl;
    cout<<a.squareroot()<<endl;
    cout<<a.cuberoot()<<endl;
    return 0;
}