#include "event_manager.h"
#include <iostream>

void EventManager::addEvent(int id, string name, string date, int capacity) {
    Event e{ id, name, date, capacity, 0 };
    eventTree.insertEvent(e);
    cout << "Event added successfully.\n";
}

void EventManager::removeEvent(const string& date, const string& name) {
    eventTree.deleteEvent(date, name);
    cout << "Event removed if it existed.\n";
}

bool EventManager::searchEventHybrid(const string& date, const string& name) {
    if (!date.empty() && !name.empty())
        return eventTree.searchEvent(date, name);
    if (!date.empty())
        return eventTree.searchByDate(date);
    if (!name.empty())
        return eventTree.searchByName(name);

    return false;
}

bool EventManager::searchByDate(const string& date) {
    return eventTree.searchByDate(date);
}

bool EventManager::searchByName(const string& name) {
    return eventTree.searchByName(name);
}

void EventManager::showAllEvents() {
    eventTree.displayEvents();
}

bool EventManager::eventExists(const string& date, const string& name) {
    return eventTree.searchEvent(date, name);
}

bool EventManager::hasAvailableSlot(const string& date, const string& name) {
    return eventTree.hasSlot(date, name);
}

void EventManager::incrementParticipantCount(const string& date, const string& name) {
    eventTree.incrementParticipant(date, name);
}
