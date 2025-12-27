#ifndef BST_H
#define BST_H

#include <string>
#include <vector>

using namespace std;

struct Event {
    int id;
    string name;
    string date;
    int capacity;
    vector<int> participants;

    Event(int eid, const string& ename,
          const string& edate, int cap)
            : id(eid), name(ename), date(edate), capacity(cap) {}
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
    //inorder traversal for the .txt files
    void inorderTraversal(BSTNode* node, vector<Event>& events) const;

    BSTNode* insert(BSTNode* node, Event e);
    BSTNode* search(BSTNode* node,
                    const string& date,
                    const string& name);
    BSTNode* deleteNode(BSTNode* node,
                        const string& date,
                        const string& name);
    BSTNode* findMin(BSTNode* node);
    void inorder(BSTNode* node);

    // UPDATED traversal helpers
    void searchByDateTraversal(BSTNode* node,const string& date,bool& found);
    void searchByNameTraversal(BSTNode* node,
                               const string& name,
                               bool& found);

public:
    BST();

    // Core operations
    void getAllEvents(vector<Event>& events) const;
    void insertEvent(Event e);
    void deleteEvent(const string& date,
                     const string& name);

    Event* findEvent(const string& date,
                     const string& name);

    // Searching + displaying
    bool searchByDate(const string& date);
    bool searchByName(const string& name);

    // Display
    void displayEvents();
};

#endif
