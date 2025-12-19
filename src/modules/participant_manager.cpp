#include "participant_manager.h"
#include <iostream>

using namespace std;

void ParticipantManager::registerParticipant(
        int participantId,
        const string& participantName,
        const string& eventDate
) {
    // Check if event exists
    if (!eventManager.eventExists(eventDate)) {
        cout << "Event does not exist.\n";
        return;
    }

    // Check capacity
    if (eventManager.hasAvailableSlot(eventDate)) {
        eventManager.incrementParticipantCount(eventDate);
        cout << "Participant registered successfully.\n";
    } else {
        Participant p;
        p.id = participantId;
        p.name = participantName;

        waitingList.enqueue(p);
        cout << "Event is full. Participant added to waiting list.\n";
    }
}

void ParticipantManager::processWaitingList(const string& eventDate) {
    if (!eventManager.eventExists(eventDate)) {
        cout << "Event does not exist.\n";
        return;
    }

    if (waitingList.isEmpty()) {
        cout << "No participants in waiting list.\n";
        return;
    }

    if (!eventManager.hasAvailableSlot(eventDate)) {
        cout << "No available slots for this event.\n";
        return;
    }

    Participant p = waitingList.dequeue();
    eventManager.incrementParticipantCount(eventDate);

    cout << "Participant moved from waiting list to event:\n";
    cout << "ID: " << p.id << " Name: " << p.name << endl;
}

ParticipantManager::ParticipantManager(EventManager& em)
        : eventManager(em) {}
