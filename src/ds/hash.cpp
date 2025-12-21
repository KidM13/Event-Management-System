#include "hash.h"
#include <iostream>

using namespace std;

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int id) const {
    return id % TABLE_SIZE;
}

// Insert participant
void HashTable::insert(int id, const string& name) {
    int index = hashFunction(id);

    Participant* newNode = new Participant;
    newNode->id = id;
    newNode->name = name;
    newNode->next = table[index];

    table[index] = newNode;
}

// Remove participant
bool HashTable::remove(int id) {
    int index = hashFunction(id);
    Participant* curr = table[index];
    Participant* prev = nullptr;

    while (curr != nullptr) {
        if (curr->id == id) {
            if (prev == nullptr) {
                table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

// Search participant
Participant* HashTable::search(int id) const {
    int index = hashFunction(id);
    Participant* curr = table[index];

    while (curr != nullptr) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

// Display table
void HashTable::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Participant* curr = table[i];
        while (curr != nullptr) {
            cout << "[" << curr->id << ", " << curr->name << "] -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}



