#include "file_manager.h"
#include <fstream>
#include <iostream>

using namespace std;

FileManager::FileManager() {
    eventsFile = "data/events.txt";
    participantsFile = "data/participants.txt";
    logsFile = "data/logs.txt";
}

// -------------------- EVENTS --------------------
vector<FileEvent> FileManager::loadEvents() {
    vector<FileEvent> events;
    ifstream file(eventsFile);

    if (!file.is_open()) {
        return events;
    }

    FileEvent e;
    while (file >> e.id >> e.name >> e.date >> e.capacity) {
        events.push_back(e);
    }

    file.close();
    return events;
}

void FileManager::saveEvent(const FileEvent& event) {
    ofstream file(eventsFile, ios::app);
    if (!file.is_open()) return;

    file << event.id << " "
         << event.name << " "
         << event.date << " "
         << event.capacity << endl;

    file.close();
}

// -------------------- PARTICIPANTS --------------------
vector<FileParticipant> FileManager::loadParticipants() {
    vector<FileParticipant> participants;
    ifstream file(participantsFile);

    if (!file.is_open()) {
        return participants;
    }

    FileParticipant p;
    while (file >> p.id >> p.name) {
        participants.push_back(p);
    }

    file.close();
    return participants;
}

void FileManager::saveParticipant(const FileParticipant& participant) {
    ofstream file(participantsFile, ios::app);
    if (!file.is_open()) return;

    file << participant.id << " "
         << participant.name << endl;

    file.close();
}

// -------------------- LOGS --------------------
void FileManager::log(const string& message) {
    ofstream file(logsFile, ios::app);
    if (!file.is_open()) return;

    file << message << endl;
    file.close();
}
