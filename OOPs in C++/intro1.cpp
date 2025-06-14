#include<iostream>
using namespace std;

class Student{
    private:
    int roll;
    string name;
    string course="MCA";
    public:
    Student(int roll,string name){
        this->roll=roll;
        this->name=name;
    }
    void display(){
        cout<<"Roll = "<<roll<<endl;
        cout<<"Name = "<<name<<endl;
        cout<<"Course = "<<course<<endl;
    }
};

int main(){

    Student s1(1,"Ravish");
    s1.display();
    return 0;
}