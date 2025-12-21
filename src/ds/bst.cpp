#include "bst.h"
#include <iostream>

BSTNode::BSTNode(Event e) {
    data = e;
    left = right = nullptr;
}

BST::BST() : root(nullptr) {}

// Composite insert
BSTNode* BST::insert(BSTNode* node, Event e) {
    if (!node) return new BSTNode(e);

    if (e.date < node->data.date ||
        (e.date == node->data.date && e.name < node->data.name))
        node->left = insert(node->left, e);
    else
        node->right = insert(node->right, e);

    return node;
}

void BST::insertEvent(Event e) {
    root = insert(root, e);
}

// Composite search
BSTNode* BST::search(BSTNode* node, const string& date, const string& name) {
    if (!node) return nullptr;

    if (date == node->data.date && name == node->data.name)
        return node;

    if (date < node->data.date ||
        (date == node->data.date && name < node->data.name))
        return search(node->left, date, name);

    return search(node->right, date, name);
}

bool BST::searchEvent(const string& date, const string& name) {
    return search(root, date, name) != nullptr;
}

// OPTION 1: traversal search by date
bool BST::searchByDateTraversal(BSTNode* node, const string& date) {
    if (!node) return false;

    bool found = false;
    found |= searchByDateTraversal(node->left, date);

    if (node->data.date == date) {
        cout << "ID: " << node->data.id
             << " | Name: " << node->data.name
             << " | Date: " << node->data.date << endl;
        found = true;
    }

    found |= searchByDateTraversal(node->right, date);
    return found;
}

bool BST::searchByDate(const string& date) {
    return searchByDateTraversal(root, date);
}

// OPTION 1: traversal search by name
bool BST::searchByNameTraversal(BSTNode* node, const string& name) {
    if (!node) return false;

    bool found = false;
    found |= searchByNameTraversal(node->left, name);

    if (node->data.name == name) {
        cout << "ID: " << node->data.id
             << " | Name: " << node->data.name
             << " | Date: " << node->data.date << endl;
        found = true;
    }

    found |= searchByNameTraversal(node->right, name);
    return found;
}

bool BST::searchByName(const string& name) {
    return searchByNameTraversal(root, name);
}

// Delete (unchanged)
BSTNode* BST::findMin(BSTNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

BSTNode* BST::deleteNode(BSTNode* node, const string& date, const string& name) {
    if (!node) return nullptr;

    if (date < node->data.date ||
        (date == node->data.date && name < node->data.name))
        node->left = deleteNode(node->left, date, name);
    else if (date > node->data.date ||
             (date == node->data.date && name > node->data.name))
        node->right = deleteNode(node->right, date, name);
    else {
        if (!node->left) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        BSTNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data.date, temp->data.name);
    }
    return node;
}

void BST::deleteEvent(const string& date, const string& name) {
    root = deleteNode(root, date, name);
}

void BST::inorder(BSTNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << "ID: " << node->data.id
         << " | Name: " << node->data.name
         << " | Date: " << node->data.date << endl;
    inorder(node->right);
}

void BST::displayEvents() {
    inorder(root);
}

bool BST::hasSlot(const string& date, const string& name) {
    BSTNode* node = search(root, date, name);
    return node && node->data.currentParticipants < node->data.capacity;
}

bool BST::incrementParticipant(const string& date, const string& name) {
    BSTNode* node = search(root, date, name);
    if (!node) return false;
    if (node->data.currentParticipants < node->data.capacity) {
        node->data.currentParticipants++;
        return true;
    }
    return false;
}
