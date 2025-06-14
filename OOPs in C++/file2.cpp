#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream filein("rahul.txt"); //ifstream → for reading
    string s;
    while(getline(filein,s))
    {
    cout<<s<<endl;
    }
    filein.close();

    return 0;
}
