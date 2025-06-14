#include<iostream>
using namespace std;

namespace first{
void show(){
    cout<<"Hello"<<endl;
}
}

namespace second{
    void show(){
        cout<<"Welcome"<<endl;
    }
}

int main(){

    cout<<"Using first namespace :"<<endl;
    first::show();
    cout<<"Using second namespace :"<<endl;
    second::show();
    return 0;
}
