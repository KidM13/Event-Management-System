#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

#include "../models/participant.h"
#include "event_manager.h"

using namespace std;

class FileManager {
private:
    string eventsFile;
    string participantsFile;
    string logsFile;

public:
    FileManager(
        const string& eventsPath,
        const string& participantsPath,
        const string& logsPath
    );

    // Logging
    void log(const string& message);

    //events data
    vector<Event> loadEvents();
    void saveEvents(const vector<Event>& events);



    vector<Participant> loadParticipants();
    void saveParticipants(const vector<Participant>& participants);

    // Reports
    void generateEventReport(EventManager& eventManager);
};

#endif
