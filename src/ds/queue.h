#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

// Participant data model
struct Participant {
    int id;
    string name;
};

struct QueueNode {
    Participant data;
    QueueNode* next;

    QueueNode(Participant p);
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue();

    bool isEmpty();
    void enqueue(Participant p);
    Participant dequeue();
    Participant peek();
};

#endif
