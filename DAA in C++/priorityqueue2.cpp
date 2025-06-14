#include <iostream>
using namespace std;

const int MAX = 100;
int size = 0;  

void push(int pq[], int value) {
    if (size >= MAX) {
        cout << "Queue is full!" << endl;
        return;
    }

    //Higher value has higher priority
    int i = size - 1;
    // Shift smaller elements right to make space for value
    while (i >= 0 && pq[i] < value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

void top(int pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout<<"Top: "<<pq[0]<<endl;
}

void pop(int pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }

    int temp=pq[0];

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    cout<<temp<<" is removed successfully!"<<endl;
}

bool empty() {
    if (size == 0) {
    cout << "Queue is empty!" << endl;
   }else{
    cout<<"Queue is not empty."<<endl;
   }
}

void printQueue(int pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Priority Queue (Higher value has higher priority): ";
    for (int i = 0; i < size; i++) {
        cout << pq[i] << " ";
    }
    cout << endl;
}

int main() {
    int pq[MAX];  

    push(pq, 10);
    push(pq, 5);
    push(pq, 20);
    push(pq, 7);

    printQueue(pq);

    top(pq);

    pop(pq);

    printQueue(pq);

    return 0;
}
