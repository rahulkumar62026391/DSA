#include <iostream>
using namespace std;

class B;  // Forward declaration

class A {
private:
    int a;

public:
    A()
    {
        a=5;
    }

    friend class B;  // B is A's friend

    void showA(B& objB);  // Only declare the function here
};

class B {
private:
    int b;

public:
    B(){
        b=10;
    }

    friend class A;  // A is B's friend
    void showB(A& objA);   // B accessing A
};

// NOW define showA, AFTER full B is known
void A::showA(B& objB) {
    cout << "Private data b of class B is " << objB.b << endl;
}

void B::showB(A& objA) {
    cout << "Private data a of class A is " << objA.a << endl;
}

int main() {
    A objA;
    B objB;

    objA.showA(objB);  // A accesses B
    objB.showB(objA);  // B accesses A

    return 0;
}
