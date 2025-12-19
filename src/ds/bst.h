#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

// Event data model
struct Event {
    int id;
    string name;
    string date;      // BST KEY
    int capacity;
    int currentParticipants;
};

// BST Node
struct BSTNode {
    Event data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Event e);
};

class BST {
private:
    BSTNode* root;

    // Helper functions
    BSTNode* insert(BSTNode* node, Event e);
    BSTNode* search(BSTNode* node, string date);
    BSTNode* deleteNode(BSTNode* node, string date);
    BSTNode* findMin(BSTNode* node);
    void inorder(BSTNode* node);

public:
    BST();

    void insertEvent(Event e);
    bool searchEvent(string date);
    void deleteEvent(string date);
    void displayEvents();
    bool hasSlot(string date);
    bool incrementParticipant(string date);

};

#endif
