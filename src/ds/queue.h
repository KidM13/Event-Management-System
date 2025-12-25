#ifndef QUEUE_H
#define QUEUE_H

#include "../models/participant.h"


struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int d) : data(d), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue();

    bool isEmpty() const;

    void enqueue(int participantId);
    int dequeue();
    int peek() const;
};

#endif
