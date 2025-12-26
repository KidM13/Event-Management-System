#include "event_manager.h"
#include <iostream>

using namespace std;

/* ========= Event Lifecycle ========= */

void EventManager::addEvent(int id,
                            const string& name,
                            const string& date,
                            int capacity) {
    Event e(id, name, date, capacity);
    eventTree.insertEvent(e);
}

void EventManager::removeEvent(const string& date,
                               const string& name) {
    eventTree.deleteEvent(date, name);
}

/* ========= Searching ========= */

bool EventManager::searchByDate(const string& date) {
    bool found = eventTree.searchByDate(date);
    return found;
}

bool EventManager::searchByName(const string& name) {
    bool found = eventTree.searchByName(name);
    return found;
}

bool EventManager::searchEventHybrid(const string& date,
                                     const string& name) {
    // Exact search
    if (!date.empty() && !name.empty()) {
        Event* e = eventTree.findEvent(date, name);
        if (!e) return false;

        cout << "Event Found:\n";
        cout << "ID: " << e->id
             << " | Name: " << e->name
             << " | Date: " << e->date
             << " | Capacity: " << e->capacity
             << " | Registered: " << e->participants.size()
             << endl;
        return true;
    }

    // Date only
    if (!date.empty())
        return searchByDate(date);

    // Name only
    if (!name.empty())
        return searchByName(name);

    return false;
}

/* ========= Validation ========= */

bool EventManager::eventExists(const string& date,
                               const string& name) {
    return eventTree.findEvent(date, name) != nullptr;
}

bool EventManager::hasAvailableSlot(const string& date,
                                    const string& name) {
    Event* e = eventTree.findEvent(date, name);
    return e && e->participants.size() < e->capacity;
}

/* ========= Participant ↔ Event ========= */

bool EventManager::addParticipantToEvent(const string& date,
                                         const string& name,
                                         int participantId) {
    Event* e = eventTree.findEvent(date, name);
    if (!e) return false;

    if ((int)e->participants.size() >= e->capacity)
        return false;

    e->participants.push_back(participantId);
    return true;
}

bool EventManager::removeParticipantFromEvent(const string& date,
                                              const string& name,
                                              int participantId) {
    Event* e = eventTree.findEvent(date, name);
    if (!e) return false;

    for (auto it = e->participants.begin();
         it != e->participants.end(); ++it) {
        if (*it == participantId) {
            e->participants.erase(it);
            return true;
        }
    }
    return false;
}

/* ========= Display ========= */

void EventManager::showAllEvents() {
    eventTree.displayEvents();
}
