#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Event {
    int id;
    string name;
    string date;
    int capacity;
    int currentParticipants;
};

struct BSTNode {
    Event data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Event e);
};

class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, Event e);
    BSTNode* search(BSTNode* node, const string& date, const string& name);
    BSTNode* deleteNode(BSTNode* node, const string& date, const string& name);
    BSTNode* findMin(BSTNode* node);
    void inorder(BSTNode* node);

public:
    BST();

    void insertEvent(Event e);
    bool searchEvent(const string& date, const string& name);
    void deleteEvent(const string& date, const string& name);
    void displayEvents();
    bool hasSlot(const string& date, const string& name);
    bool incrementParticipant(const string& date, const string& name);
};

#endif
