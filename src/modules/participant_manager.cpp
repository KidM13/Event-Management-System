#include "participant_manager.h"
#include <iostream>

using namespace std;

bool ParticipantManager::registerParticipant(
    int id,
    const string& name
) {
    if (participants.search(id) != nullptr) {
        return false; // already exists
    }

    participants.insert(id, name);
    return true;
}

bool ParticipantManager::removeParticipant(int id) {
    return participants.remove(id);
}

bool ParticipantManager::participantExists(int id) {
    return participants.search(id) != nullptr;
}

Participant* ParticipantManager::getParticipant(int id) {
    return participants.search(id);
}

void ParticipantManager::showAllParticipants() {
    participants.display();
}


