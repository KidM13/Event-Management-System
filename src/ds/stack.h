#ifndef STACK_H
#define STACK_H

// Types of actions that can be undone
enum ActionType {
    ADD_EVENT,
    DELETE_EVENT,
    UPDATE_EVENT
};

// Represents one undoable action
struct Action {
    ActionType type;
    int eventId;
};

// Stack node
struct StackNode {
    Action action;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;

public:
    Stack();

    bool isEmpty() const;
    void push(const Action& action);
    Action pop();
    Action peek() const;
};

#endif
