#include "queue.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::enqueue(int participantId) {
    QueueNode* newNode = new QueueNode(participantId);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Waiting list is empty\n";
        return -1;
    }

    QueueNode* temp = front;
    int participantId = temp->data;

    front = front->next;
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return participantId;
}

int Queue::peek() const {
    if (isEmpty())
        return -1;
    return front->data;
}
