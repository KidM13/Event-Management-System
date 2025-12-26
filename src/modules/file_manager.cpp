#include "file_manager.h"
#include <fstream>
#include <iostream>

using namespace std;

FileManager::FileManager(
    const string& eventsPath,
    const string& participantsPath,
    const string& logsPath
) : eventsFile(eventsPath),
    participantsFile(participantsPath),
    logsFile(logsPath) {}

// -------------------- LOGS --------------------
void FileManager::log(const string& message) {
    ofstream file(logsFile, ios::app);
    if (!file.is_open()) return;

    file << message << endl;
    file.close();
}
// -------------------- EVENTS --------------------

vector<Event> FileManager::loadEvents() {
    vector<Event> events;
    ifstream file(eventsFile);

    if (!file.is_open())
        return events;

    int id, capacity;
    string name, date;

    while (file >> id >> name >> date >> capacity) {
        events.emplace_back(id, name, date, capacity);
    }

    file.close();
    return events;
}


void FileManager::saveEvents(const vector<Event>& events) {
    ofstream file(eventsFile);
    if (!file.is_open()) return;

    for (const auto& e : events) {
        file << e.id << " "
             << e.name << " "
             << e.date << " "
             << e.capacity << endl;
    }

    file.close();
}



// -------------------- PARTICIPANTS --------------------
vector<Participant> FileManager::loadParticipants() {
    vector<Participant> participants;
    ifstream file(participantsFile);

    if (!file.is_open())
        return participants;

    Participant p;
    while (file >> p.id >> p.name) {
        participants.push_back(p);
    }

    file.close();
    return participants;
}

void FileManager::saveParticipants(
    const vector<Participant>& participants
) {
    ofstream file(participantsFile);
    if (!file.is_open()) return;

    for (const auto& p : participants) {
        file << p.id << " " << p.name << endl;
    }

    file.close();
}

// -------------------- REPORT --------------------
void FileManager::generateEventReport(EventManager& eventManager) {
    ofstream file(logsFile, ios::app);
    if (!file.is_open()) return;

    file << "\n=== EVENT REPORT ===\n";

    auto events = eventManager.getAllEvents();
    for (const auto& e : events) {
        file << e.id << " "
             << e.name << " "
             << e.date << " "
             << e.capacity << "\n";
    }

    file << "====================\n";
    file.close();
}

