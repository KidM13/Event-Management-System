#ifndef HASH_H
#define HASH_H

#include <string>
#include "../models/participant.h"


using namespace std;

struct HashNode {
    Participant data;
    HashNode* next;

    HashNode(int id, const string& name)
        : data{id, name}, next(nullptr) {}
};




class HashTable {
private:
    static const int TABLE_SIZE = 10;
    HashNode* table[TABLE_SIZE];


    int hashFunction(int id) const;

public:
    HashTable();

    void insert(int id, const string& name);
    bool remove(int id);
    Participant* search(int id) const;

    void display() const;
};

#endif
