#include <iostream>
#include <cstdlib>
#include "QueueF.h"

using namespace std;

// Inserts an element at the end (back) of the queue in O(n) time: traverses from front to rear and places it at the end --> O(1)
void Queue::enqueue(int elem) {
    nodoQ *nuevo = new nodoQ;
    
    nuevo->val = elem;
    nuevo->next = NULL;
    
    if (Last != nullptr) {
        Last->next = nuevo;
        Last = nuevo;
    } else {
        Front = Last = nuevo;
    }
    nItems++;        
}

// Removes the element at the front of the queue and returns its value in O(1) time
// Case Front = Last, there is only one node in the queue

void Queue::dequeue() {
    if (Front == nullptr) {
        cout << "Warning... empty queue!!" << endl;
        return;
    }
    
    nodoQ *q = Front;
    if (Front == Last) {
        Front = Last = NULL;
    } else {
        Front = Front->next;
    }
    delete q;
    nItems--;    
}

// Returns the element at the front of the queue, takes O(1) time
int Queue::front() {
    if (Front == nullptr) {
        cout << "front::Warning... empty queue!!" << endl;
        return -1;
    }
    return Front->val;
}

// Returns the element at the end of the queue, takes O(1) time
int Queue::last() {
    if (Last == nullptr) {
        cout << "last::Warning... empty queue!!" << endl;
        return -1;
    }
    return Last->val;
}

// Returns the number of elements in the queue in O(1) time
int Queue::size() {
    return nItems;
}

// Displays the queue
void Queue::display() {
    if (Front == nullptr) {
        cout << "Empty queue!" << endl;
        return;
    }

    cout << "Queue:" << endl;
    nodoQ *p = Front;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Execute: ./queuef <n> <seed>" << endl;
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    int seed = atoi(argv[2]);
    srand(seed);

    Queue queue_q;
    queue_q.display();
    queue_q.enqueue(1);
    queue_q.display();
    for (int i = 0; i < n; i++) {
        queue_q.enqueue(rand() % n);
    }
    cout << "After inserting " << n << " random elements: " << endl;
    queue_q.display();
    cout << "Queue size: " << queue_q.size() << endl;
    cout << "Front = " << queue_q.front() << endl;
    cout << "Last = " << queue_q.last() << endl;

    queue_q.dequeue();
    queue_q.display();
    queue_q.dequeue();
    queue_q.enqueue(77);
    queue_q.dequeue();
    cout << "Queue size: " << queue_q.size() << endl;
    cout << "Front = " << queue_q.front() << endl;
    cout << "Last = " << queue_q.last() << endl;

    cout << "###### End of program ######" << endl;

    return EXIT_SUCCESS;
}
