#include "queue.h"
#include <iostream>

QueueNode::QueueNode(Participant p) {
    data = p;
    next = nullptr;
}

Queue::Queue() {
    front = rear = nullptr;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::enqueue(Participant p) {
    QueueNode* newNode = new QueueNode(p);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Participant Queue::dequeue() {
    if (isEmpty()) {
        cout << "Waiting list is empty.\n";
        return {-1, ""};
    }

    QueueNode* temp = front;
    Participant p = temp->data;

    front = front->next;
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return p;
}

Participant Queue::peek() {
    if (isEmpty())
        return {-1, ""};

    return front->data;
}
