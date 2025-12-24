#ifndef QUEUE_H
#define QUEUE_H

#include "../models/participant.h"

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
