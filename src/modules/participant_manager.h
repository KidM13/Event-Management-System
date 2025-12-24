#ifndef PARTICIPANT_MANAGER_H
#define PARTICIPANT_MANAGER_H

#include "../ds/hash.h"
#include <string>

using namespace std;



class ParticipantManager {
private:
    HashTable participants;

public:
    bool registerParticipant(int id, const string& name);
    bool removeParticipant(int id);

    bool participantExists(int id);
    Participant* getParticipant(int id);

    void showAllParticipants();
};

#endif
