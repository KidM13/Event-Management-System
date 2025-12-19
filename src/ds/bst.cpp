#include "bst.h"
#include <iostream>

BSTNode::BSTNode(Event e) {
    data = e;
    left = right = nullptr;
}

BST::BST() {
    root = nullptr;
}

// Insert helper
BSTNode* BST::insert(BSTNode* node, Event e) {
    if (node == nullptr)
        return new BSTNode(e);

    if (e.date < node->data.date)
        node->left = insert(node->left, e);
    else if (e.date > node->data.date)
        node->right = insert(node->right, e);

    return node;
}

void BST::insertEvent(Event e) {
    root = insert(root, e);
}

// Search helper
BSTNode* BST::search(BSTNode* node, string date) {
    if (node == nullptr || node->data.date == date)
        return node;

    if (date < node->data.date)
        return search(node->left, date);
    else
        return search(node->right, date);
}

bool BST::searchEvent(string date) {
    return search(root, date) != nullptr;
}

// Find minimum (used in delete)
BSTNode* BST::findMin(BSTNode* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// Delete helper
BSTNode* BST::deleteNode(BSTNode* node, string date) {
    if (node == nullptr)
        return node;

    if (date < node->data.date)
        node->left = deleteNode(node->left, date);
    else if (date > node->data.date)
        node->right = deleteNode(node->right, date);
    else {
        // Case 1 & 2
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        BSTNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data.date);
    }
    return node;
}

void BST::deleteEvent(string date) {
    root = deleteNode(root, date);
}

// Inorder traversal
void BST::inorder(BSTNode* node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    cout << "ID: " << node->data.id
         << " | Name: " << node->data.name
         << " | Date: " << node->data.date
         << " | Capacity: " << node->data.capacity << endl;
    inorder(node->right);
}

void BST::displayEvents() {
    inorder(root);
}

bool BST::hasSlot(string date) {
    BSTNode* node = search(root, date);
    if (node == nullptr)
        return false;

    return node->data.currentParticipants < node->data.capacity;
}

bool BST::incrementParticipant(string date) {
    BSTNode* node = search(root, date);
    if (node == nullptr)
        return false;

    if (node->data.currentParticipants < node->data.capacity) {
        node->data.currentParticipants++;
        return true;
    }
    return false;
}

