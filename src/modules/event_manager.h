#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "../ds/bst.h"

class EventManager {
private:
    BST eventTree;

public:
    void addEvent(int id, string name, string date, int capacity);
    void removeEvent(string date);
    void searchEvent(string date);
    void showAllEvents();
    bool eventExists(string date);
    bool hasAvailableSlot(string date);
    void incrementParticipantCount(string date);
};

#endif
