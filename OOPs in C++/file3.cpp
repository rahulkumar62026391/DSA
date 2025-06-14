#include <fstream>
#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
};

int main() {
    Student s1 = {1, "John"};

    // Writing to file
    ofstream fout("data.dat", ios::binary);
    fout.write((char*)&s1, sizeof(s1));
    fout.close();

    // Reading from file
    Student s2;
    ifstream fin("data.dat", ios::binary);
    fin.read((char*)&s2, sizeof(s2));
    fin.close();

    // Display output
    cout << "Roll: " << s2.roll << endl;
    cout << "Name: " << s2.name << endl;

    return 0;
}
