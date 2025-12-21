#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

struct Participant {
    int id;
    string name;
    Participant* next;   // for chaining
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Participant* table[TABLE_SIZE];

    int hashFunction(int id) const;

public:
    HashTable();

    void insert(int id, const string& name);
    bool remove(int id);
    Participant* search(int id) const;

    void display() const;
};

#endif
