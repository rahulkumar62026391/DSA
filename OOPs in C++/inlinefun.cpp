#include<iostream>
using namespace std;

class Square
{
    int a;
    public:
    Square(int x)
    {
        a=x;
    }

    void area()
    {
        cout<<"Area : "<<a*a<<endl;
    }

    inline void perimeter()
    {
        cout<<"Perimeter : "<<4*a<<endl;
    }

};

inline void diagonal(int y)
{
    cout<<"Diagonal : "<<1.414*y<<endl;
}

int main()
{
    Square s(5);
    s.area();
    s.perimeter();
    diagonal(5);

    return 0;
}