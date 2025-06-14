#include<iostream>
using namespace std;

class Father{

    protected:
    string surname="Singh";
};

class Son1 :public Father{
    string name;

    public:
    Son1(string name){
        this->name=name;
    }

    void display(){
        cout<<"Name : "<<name<<" "<<surname<<endl;
    }
    

};

class Son2 : public Father{
    string name;

    public:

    Son2(string name){
        this->name=name;
    }

    void display(){
        cout<<"Name : "<<name<<" "<<surname<<endl;;
    }
};

int main(){
   Father father;

   Son1 son1("Krishna");
   son1.display();

   Son2 son2("Balram");
   son2.display();

    return 0;
}