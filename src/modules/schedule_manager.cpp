#include "schedule_manager.h"
#include <iostream>

using namespace std;

/* ========= ScheduleStack ========= */

ScheduleStack::ScheduleStack() : top(nullptr) {}

bool ScheduleStack::isEmpty() const {
    return top == nullptr;
}

void ScheduleStack::push(const ScheduleAction& action) {
    ScheduleStackNode* node = new ScheduleStackNode{ action, top };
    top = node;
}

ScheduleAction ScheduleStack::pop() {
    if (isEmpty())
        throw runtime_error("Schedule undo stack empty");

    ScheduleStackNode* temp = top;
    ScheduleAction action = temp->action;
    top = top->next;
    delete temp;
    return action;
}

/* ========= ScheduleManager ========= */

ScheduleManager::ScheduleManager(
    EventManager& em,
    ParticipantManager& pm
) : eventManager(em), participantManager(pm) {}

RegisterResult ScheduleManager::registerParticipantForEvent(
        int participantId,
        const string& date,
        const string& eventName
) {
    if (!participantManager.participantExists(participantId))
        return PARTICIPANT_NOT_FOUND;

    if (!eventManager.eventExists(date, eventName))
        return EVENT_NOT_FOUND;

    // Case 1: Slot available → REGISTER
    if (eventManager.hasAvailableSlot(date, eventName)) {
        eventManager.addParticipantToEvent(date, eventName, participantId);

        undoStack.push({
                               REGISTER,
                               participantId,
                               date,
                               eventName
                       });

        return REGISTERED;
    }

    // Case 2: Event full → WAITLIST
    waitList.enqueue(participantId);

    undoStack.push({
                           WAITLIST,
                           participantId,
                           date,
                           eventName
                   });

    return EVENT_FULL;
}


bool ScheduleManager::cancelRegistration(
    int participantId,
    const string& date,
    const string& eventName
) {
    if (!eventManager.removeParticipantFromEvent(
            date, eventName, participantId
        ))
        return false;

    undoStack.push({
        CANCEL, participantId, date, eventName
    });

    processWaitList(date, eventName);
    return true;
}

void ScheduleManager::processWaitList(
    const string& date,
    const string& eventName
) {
    if (waitList.isEmpty())
        return;

    if (!eventManager.hasAvailableSlot(date, eventName))
        return;

    int nextParticipantId = waitList.dequeue();
    eventManager.addParticipantToEvent(date, eventName, nextParticipantId);


}

void ScheduleManager::undoLastScheduleAction() {
    if (undoStack.isEmpty()) {
        cout << "No action to undo.\n";
        return;
    }

    ScheduleAction action = undoStack.pop();

    switch (action.type) {

        case REGISTER:
            eventManager.removeParticipantFromEvent(
                    action.date,
                    action.eventName,
                    action.participantId
            );
            cout << "Undo: Registration removed.\n";
            break;

        case CANCEL:
            eventManager.addParticipantToEvent(
                    action.date,
                    action.eventName,
                    action.participantId
            );
            cout << "Undo: Registration restored.\n";
            break;
    }
}

