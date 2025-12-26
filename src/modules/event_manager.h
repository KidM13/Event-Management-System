#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "../ds/bst.h"
#include <string>

using namespace std;

class EventManager {
private:
    BST eventTree;

public:
    // Event lifecycle
    bool addEvent(int id, const string& name, const string& date, int capacity);
    bool removeEvent(const string& date,const string& name);

    // Searching (RETURN bool)
    bool searchEventHybrid(const string& date, const string& name);
    bool searchByDate(const string& date);
    bool searchByName(const string& name);

    // Display
    void showAllEvents();

    //load event
    void loadEvents(const vector<Event>& events);
    vector<Event> getAllEvents() const;

    // Validation
    bool eventExists(const string& date, const string& name);
    bool hasAvailableSlot(const string& date, const string& name);

    // Participant ↔ Event binding
    bool addParticipantToEvent(const string& date,
                               const string& name,
                               int participantId);

    bool removeParticipantFromEvent(const string& date,
                                    const string& name,
                                    int participantId);

    // Update
    bool updateEvent(
            const string& oldDate,
            const string& oldName,
            const string& newName,
            const string& newDate,
            int newCapacity
    );

};

#endif
