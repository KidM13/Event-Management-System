#ifndef PARTICIPANT_MANAGER_H
#define PARTICIPANT_MANAGER_H

#include <string>
#include "../ds/queue.h"
#include "event_manager.h"

using std::string;

class ParticipantManager {
private:
    Queue waitingList;
    EventManager& eventManager;

public:
    ParticipantManager(EventManager& em);

    void registerParticipant(
            int participantId,
            const string& participantName,
            const string& eventDate
    );

    void processWaitingList(const string& eventDate);
};

#endif
