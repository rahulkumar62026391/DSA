#include <iostream>
using namespace std;

struct Node {
    int value;
    int priority;
};

const int MAX = 100;
int size = 0;

void push(Node pq[], int value, int priority) {
    if (size >= MAX) {
        cout << "Queue is full!" << endl;
        return;
    }

    //Lower value( in priority) has higher priority

    int i = size - 1;
    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].value = value;
    pq[i + 1].priority = priority;
    size++;
}

void top(Node pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
         return;
    }
    cout << "Top:" << pq[0].value<<endl;
   
}

void pop(Node pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }

    int temp=pq[0].value;

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    cout<<temp<<" is removed successfully!"<<endl;
}

// Print all elements in the queue 
void printQueue(Node pq[]) {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Priority Queue:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Value: " << pq[i].value << ", Priority: " << pq[i].priority << endl;
    }
}

void empty() {
   if (size == 0)
   { 
    cout << "Queue is empty!" << endl;
   }else{
    cout<<"Queue is not empty!"<<endl;
   }
}

int main() {
    Node pq[MAX];

    push(pq, 10, 4);
    push(pq, 5, 2);
    push(pq, 20, 5);
    push(pq, 7, 1);

    printQueue(pq); 
    
    top(pq);

    pop(pq);

    printQueue(pq);

    return 0;
}
