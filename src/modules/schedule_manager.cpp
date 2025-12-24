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

bool ScheduleManager::registerParticipantForEvent(
    int participantId,
    const string& date,
    const string& eventName
) {
    if (!participantManager.participantExists(participantId))
        return false;

    if (!eventManager.eventExists(date, eventName))
        return false;

    if (eventManager.hasAvailableSlot(date, eventName)) {
        eventManager.addParticipantToEvent(
            date, eventName, participantId
        );

        undoStack.push({
            REGISTER, participantId, date, eventName
        });
        return true;
    }

    // event full → waitlist
    waitList.enqueue(participantId);

    undoStack.push({
        WAITLIST, participantId, date, eventName
    });
    return true;
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

    int nextParticipant = waitList.dequeue();
    eventManager.addParticipantToEvent(
        date, eventName, nextParticipant
    );
}

void ScheduleManager::undoLastScheduleAction() {
    if (undoStack.isEmpty()) {
        cerr << "No schedule action to undo\n";
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
            break;

        case CANCEL:
            eventManager.addParticipantToEvent(
                action.date,
                action.eventName,
                action.participantId
            );
            break;

        case WAITLIST:
            // skipped intentionally
            break;
    }
}
