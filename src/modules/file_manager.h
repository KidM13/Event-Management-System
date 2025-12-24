#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

using namespace std;

struct FileParticipant {
    int id;
    string name;
};

struct FileEvent {
    int id;
    string name;
    string date;
    int capacity;
};

class FileManager {
private:
    string eventsFile;
    string participantsFile;
    string logsFile;

public:
    // Constructor sets correct relative paths
    FileManager();

    // Events
    vector<FileEvent> loadEvents();
    void saveEvent(const FileEvent& event);

    // Participants
    vector<FileParticipant> loadParticipants();
    void saveParticipant(const FileParticipant& participant);

    // Logs
    void log(const string& message);
};

#endif
