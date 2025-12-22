#include "bst.h"
#include <iostream>

using namespace std;

// BSTNode constructor
BSTNode::BSTNode(Event e)
    : data(e), left(nullptr), right(nullptr) {}

// BST constructor
BST::BST() : root(nullptr) {}


// Insert helper
//
BSTNode* BST::insert(BSTNode* node, Event e) {
    if (node == nullptr)
        return new BSTNode(e);

    // Primary key: date, Secondary key: name
    if (e.date < node->data.date ||
        (e.date == node->data.date && e.name < node->data.name)) {
        node->left = insert(node->left, e);
    } else {
        node->right = insert(node->right, e);
    }

    return node;
}

void BST::insertEvent(Event e) {
    root = insert(root, e);
}

// Search helper
BSTNode* BST::search(
    BSTNode* node,
    const string& date,
    const string& name
) {
    if (node == nullptr)
        return nullptr;

    if (date == node->data.date && name == node->data.name)
        return node;

    if (date < node->data.date ||
        (date == node->data.date && name < node->data.name)) {
        return search(node->left, date, name);
    }

    return search(node->right, date, name);
}

Event* BST::findEvent(const string& date, const string& name) {
    BSTNode* result = search(root, date, name);
    return result ? &result->data : nullptr;
}

// Find minimum node
BSTNode* BST::findMin(BSTNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete helper
BSTNode* BST::deleteNode(
    BSTNode* node,
    const string& date,
    const string& name
) {
    if (node == nullptr)
        return nullptr;

    if (date < node->data.date ||
        (date == node->data.date && name < node->data.name)) {
        node->left = deleteNode(node->left, date, name);
    } else if (date > node->data.date ||
               (date == node->data.date && name > node->data.name)) {
        node->right = deleteNode(node->right, date, name);
    } else {
        // Node found
        if (!node->left) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        BSTNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(
            node->right,
            temp->data.date,
            temp->data.name
        );
    }

    return node;
}

void BST::deleteEvent(const string& date, const string& name) {
    root = deleteNode(root, date, name);
}

//
// Inorder traversal
void BST::inorder(BSTNode* node) {
    if (!node) return;

    inorder(node->left);

    cout << "Event ID: " << node->data.id
         << " | Name: " << node->data.name
         << " | Date: " << node->data.date
         << " | Capacity: " << node->data.capacity
         << " | Registered: " << node->data.participants.size()
         << endl;

    inorder(node->right);
}

void BST::displayEvents() {
    inorder(root);
}

// Traversal searches
//
bool BST::searchByDateTraversal(
    BSTNode* node,
    const string& date
) {
    if (!node) return false;

    if (node->data.date == date)
        return true;

    return searchByDateTraversal(node->left, date) ||
           searchByDateTraversal(node->right, date);
}

bool BST::searchByNameTraversal(
    BSTNode* node,
    const string& name
) {
    if (!node) return false;

    if (node->data.name == name)
        return true;

    return searchByNameTraversal(node->left, name) ||
           searchByNameTraversal(node->right, name);
}

bool BST::searchByDate(const string& date) {
    return searchByDateTraversal(root, date);
}

bool BST::searchByName(const string& name) {
    return searchByNameTraversal(root, name);
}
