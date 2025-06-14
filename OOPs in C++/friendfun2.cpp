#include <iostream>
using namespace std;
class Area;
class Volume
{
 int a=10;
 friend void getValue(Volume obj1,Area obj2);
};

class Area
{
    int b=10;
    friend void getValue(Volume obj1,Area obj2);
};

void getValue(Volume obj1 , Area obj2)
{
  cout<<"Volume : "<<obj1.a<< " | Area : " << obj2.b << endl;
}
int main(){

    Volume obj1;
    Area obj2;
    getValue(obj1,obj2);
    return 0;
}