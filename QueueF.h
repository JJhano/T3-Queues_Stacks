#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {
private:
    struct nodeQueue {
        int val;
        nodeQueue* next;
    };
    typedef struct nodeQueue nodoQ;

    int nItems;     // element counter
    nodoQ* Front;       // pointer to the FRONT of the queue, where dequeue happens
    nodoQ* Last;       // pointer to the END of the queue, where enqueue happens

public:
    Queue();
    Queue(int num);
    ~Queue();

    void enqueue(int);
    void dequeue();
    int front();
    int last();
    int size();
    bool empty();
    void display();
};
// Class constructor... creates an empty queue
Queue::Queue() {
    cout << "Creating an empty queue..." << endl;
    Front = Last = NULL;
    nItems = 0;
}

// Class constructor... creates the queue with one element
Queue::Queue(int num) {
    Front = Last = new nodoQ;
    Front->val = num;
    Front->next = NULL;
    nItems = 1;
}

// Class destructor, frees memory of all nodeQ
Queue::~Queue() {
    nodoQ* p;
    while (Front != nullptr) {
        p = Front;
        Front = Front->next;
        delete p;
    }
}
