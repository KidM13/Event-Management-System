#include "participant_manager.h"
#include <iostream>

using namespace std;


void ParticipantManager::loadParticipants(
    const vector<Participant>& list
) {
    for (const Participant& p : list) {
        participants.insert(p.id, p.name);
    }
}



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

vector<Participant> ParticipantManager::getAllParticipants() const {
    return participants.toVector();
}


void ParticipantManager::showAllParticipants() {
    participants.display();
}


