#include<iostream>
using namespace std;

class Details{

    string name;
    int age;
    double salary;

    public:
    void info(string nm){
         name=nm;
    }

    void info(int age){
        this->age=age;
    }

    void info(double slry){
        salary=slry;
    }

    void display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};



int main(){

    Details d;
    d.info("Rahul");
    d.info(21);
    d.info(50000.0);
    d.display();
    

    return 0;
}