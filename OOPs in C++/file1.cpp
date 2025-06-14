#include<iostream>
#include<fstream>
using namespace std;

int main()
{ 
    ofstream fileout("rahul.txt");  //ofstream -> for writing
    fileout<<"I am Rahul Kumar."<<endl;
    fileout<<"I am from Bihar.";
    fileout.close();
    
    return 0;
}