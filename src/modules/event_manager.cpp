#include "event_manager.h"
#include <iostream>

using namespace std;

void EventManager::addEvent(
    int id,
    const string& name,
    const string& date,
    int capacity
) {
    Event e;
    e.id = id;
    e.name = name;
    e.date = date;
    e.capacity = capacity;

    eventTree.insertEvent(e);
}

void EventManager::removeEvent(
    const string& date,
    const string& name
) {
    eventTree.deleteEvent(date, name);
}

bool EventManager::eventExists(
    const string& date,
    const string& name
) {
    return eventTree.findEvent(date, name) != nullptr;
}

bool EventManager::hasAvailableSlot(
    const string& date,
    const string& name
) {
    Event* e = eventTree.findEvent(date, name);
    if (!e) return false;

    return e->participants.size() < e->capacity;
}

bool EventManager::addParticipantToEvent(
    const string& date,
    const string& name,
    int participantId
) {
    Event* e = eventTree.findEvent(date, name);
    if (!e) return false;

    if ((int)e->participants.size() >= e->capacity)
        return false;

    e->participants.push_back(participantId);
    return true;
}

bool EventManager::removeParticipantFromEvent(
    const string& date,
    const string& name,
    int participantId
) {
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

void EventManager::showAllEvents() {
    eventTree.displayEvents();
}

