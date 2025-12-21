#include "participant_manager.h"
#include <iostream>

using namespace std;

ParticipantManager::ParticipantManager(EventManager& em)
        : eventManager(em) {}

void ParticipantManager::registerParticipant(
        int participantId,
        const string& participantName,
        const string& eventDate,
        const string& eventName
) {
    if (!eventManager.eventExists(eventDate, eventName)) {
        cout << "Event does not exist.\n";
        return;
    }

    if (eventManager.hasAvailableSlot(eventDate, eventName)) {
        eventManager.incrementParticipantCount(eventDate, eventName);
        cout << "Participant registered successfully.\n";
    } else {
        waitingList.enqueue({participantId, participantName});
        cout << "Event full. Added to waiting list.\n";
    }
}

void ParticipantManager::processWaitingList(
        const string& eventDate,
        const string& eventName
) {
    if (!eventManager.eventExists(eventDate, eventName)) {
        cout << "Event does not exist.\n";
        return;
    }

    if (waitingList.isEmpty()) {
        cout << "Waiting list empty.\n";
        return;
    }

    if (!eventManager.hasAvailableSlot(eventDate, eventName)) {
        cout << "No available slots.\n";
        return;
    }

    Participant p = waitingList.dequeue();
    eventManager.incrementParticipantCount(eventDate, eventName);

    cout << "Participant moved from waiting list:\n";
    cout << "ID: " << p.id << " Name: " << p.name << endl;
}
