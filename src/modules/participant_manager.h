#ifndef PARTICIPANT_MANAGER_H
#define PARTICIPANT_MANAGER_H

#include "../ds/queue.h"
#include "event_manager.h"

class ParticipantManager {
private:
    Queue waitingList;
    EventManager& eventManager;

public:
    ParticipantManager(EventManager& em);

    void registerParticipant(
            int participantId,
            const string& participantName,
            const string& eventDate,
            const string& eventName
    );

    void processWaitingList(
            const string& eventDate,
            const string& eventName
    );
};

#endif
