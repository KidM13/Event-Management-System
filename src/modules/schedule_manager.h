#ifndef SCHEDULE_MANAGER_H
#define SCHEDULE_MANAGER_H

#include "../ds/queue.h"
#include "event_manager.h"
#include "participant_manager.h"
#include <string>

using namespace std;

// Schedule-specific undo actions
enum ScheduleActionType {
    REGISTER,
    CANCEL,
    WAITLIST
};

struct ScheduleAction {
    ScheduleActionType type;
    int participantId;
    string date;
    string eventName;
};

// Simple stack for schedule undo
struct ScheduleStackNode {
    ScheduleAction action;
    ScheduleStackNode* next;
};

class ScheduleStack {
private:
    ScheduleStackNode* top;

public:
    ScheduleStack();
    bool isEmpty() const;
    void push(const ScheduleAction& action);
    ScheduleAction pop();
};

class ScheduleManager {
private:
    EventManager& eventManager;
    ParticipantManager& participantManager;

    Queue waitList;              // waiting participants
    ScheduleStack undoStack;     // schedule undo only

public:
    ScheduleManager(
        EventManager& em,
        ParticipantManager& pm
    );

    bool registerParticipantForEvent(
        int participantId,
        const string& date,
        const string& eventName
    );

    bool cancelRegistration(
        int participantId,
        const string& date,
        const string& eventName
    );

    void processWaitList(
        const string& date,
        const string& eventName
    );

    void undoLastScheduleAction();
};

#endif
