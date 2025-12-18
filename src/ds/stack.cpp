#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::push(const Action& action) {
    StackNode* newNode = new StackNode;
    newNode->action = action;
    newNode->next = top;
    top = newNode;
}

Action Stack::pop() {
    if (isEmpty()) {
        cerr << "Stack underflow: No action to undo." << endl;
        return Action{ADD_EVENT, -1}; // invalid action
    }

    StackNode* temp = top;
    Action poppedAction = temp->action;

    top = top->next;
    delete temp;

    return poppedAction;
}

Action Stack::peek() const {
    if (isEmpty()) {
        cerr << "Stack is empty." << endl;
        return Action{ADD_EVENT, -1};
    }

    return top->action;
}
