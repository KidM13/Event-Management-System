#include <iostream>

#include "modules/event_manager.h"
#include "modules/participant_manager.h"
#include "modules/schedule_manager.h"
#include "modules/file_manager.h"

using namespace std;

void showMenu() {
    cout << "\n===== Event Management System =====\n";
    cout << "1. Add Event\n";
    cout << "2. Remove Event\n";
    cout << "3. Show All Events\n";
    cout << "4. Register Participant\n";
    cout << "5. Schedule Participant to Event\n";
    cout << "6. Undo Last Action\n";
    cout << "7. Generate Event Report\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

int main() {
    // Core managers
    EventManager eventManager;
    ParticipantManager participantManager;
    ScheduleManager scheduleManager(eventManager, participantManager);

    // File manager with explicit paths
    FileManager fileManager(
        "data/events.txt",
        "data/participants.txt",
        "data/logs.txt"
    );

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            int id, capacity;
            string name, date;

            cout << "Event ID: ";
            cin >> id;
            cin.ignore();

            cout << "Event Name: ";
            getline(cin, name);

            cout << "Event Date (YYYY-MM-DD): ";
            getline(cin, date);

            cout << "Capacity: ";
            cin >> capacity;

            eventManager.addEvent(id, name, date, capacity);
            fileManager.log("Event added: " + name);
            break;
        }

        case 2: {
            string name, date;
            cin.ignore();

            cout << "Event Name: ";
            getline(cin, name);

            cout << "Event Date: ";
            getline(cin, date);

            eventManager.removeEvent(date, name);
            fileManager.log("Event removed: " + name);
            break;
        }

        case 3:
            eventManager.showAllEvents();
            break;

        case 4: {
            int pid;
            string pname;

            cout << "Participant ID: ";
            cin >> pid;
            cin.ignore();

            cout << "Participant Name: ";
            getline(cin, pname);

            participantManager.registerParticipant(pid, pname);
            fileManager.log("Participant registered: " + pname);
            break;
        }

        case 5: {
            int pid;
            string name, date;

            cout << "Participant ID: ";
            cin >> pid;
            cin.ignore();

            cout << "Event Name: ";
            getline(cin, name);

            cout << "Event Date: ";
            getline(cin, date);

            scheduleManager.registerParticipantForEvent(pid, date, name);
            break;
        }

        case 6:
            scheduleManager.undoLastScheduleAction();
            fileManager.log("Undo last action");
            break;

        case 7:
            fileManager.generateEventReport(eventManager);
            cout << "Event report generated.\n";
            break;

        case 0:
            cout << "Exiting system...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
