#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "../ds/bst.h"

class EventManager {
private:
    BST eventTree;

public:
    void addEvent(int id, string name, string date, int capacity);
    void removeEvent(const string& date, const string& name);

    // OPTION 1 hybrid search
    bool searchEventHybrid(const string& date, const string& name);
    bool searchByDate(const string& date);
    bool searchByName(const string& name);

    void showAllEvents();
    bool eventExists(const string& date, const string& name);
    bool hasAvailableSlot(const string& date, const string& name);
    void incrementParticipantCount(const string& date, const string& name);
};

#endif
