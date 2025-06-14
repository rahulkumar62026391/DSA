#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
    try
    {
        throw invalid_argument("Invalid Argument.");
    }
    catch(exception& e)
    {
        cout<< e.what() << '\n';
    }
    
}