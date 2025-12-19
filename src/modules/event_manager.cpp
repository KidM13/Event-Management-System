#include "event_manager.h"
#include <iostream>

void EventManager::addEvent(int id, string name, string date, int capacity) {
    Event e;
    e.id = id;
    e.name = name;
    e.date = date;
    e.capacity = capacity;
    e.currentParticipants = 0;   // MUST be initialized


    eventTree.insertEvent(e);
    cout << "Event added successfully.\n";
}

void EventManager::removeEvent(string date) {
    eventTree.deleteEvent(date);
    cout << "Event removed if it existed.\n";
}

void EventManager::searchEvent(string date) {
    if (eventTree.searchEvent(date))
        cout << "Event found.\n";
    else
        cout << "Event not found.\n";
}

void EventManager::showAllEvents() {
    cout << "\n--- All Events (Sorted by Date) ---\n";
    eventTree.displayEvents();
}

bool EventManager::eventExists(string date) {
    return eventTree.searchEvent(date);
}

bool EventManager::hasAvailableSlot(string date) {
    return eventTree.hasSlot(date);
}

void EventManager::incrementParticipantCount(string date) {
    eventTree.incrementParticipant(date);
}
