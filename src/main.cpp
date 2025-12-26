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
    cout << "3. Search Event\n";
    cout << "4. Show All Events\n";
    cout << "5. Update Event\n";
    cout << "6. Register Participant\n";
    cout << "7. Schedule Participant to Event\n";
    cout << "8. Undo Last Action\n";
    cout << "9. Generate Event Report\n";
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

            case 3: {
                int searchChoice;
                string date, name;

                cout << "\n--- Search Event ---\n";
                cout << "1. Search by Date\n";
                cout << "2. Search by Name\n";
                cout << "3. Search by Date & Name\n";
                cout << "Choose: ";
                cin >> searchChoice;
                cin.ignore();

                bool found = false;

                switch (searchChoice) {
                    case 1:
                        cout << "Enter Event Date (YYYY-MM-DD): ";
                        getline(cin, date);
                        found = eventManager.searchByDate(date);
                        break;

                    case 2:
                        cout << "Enter Event Name: ";
                        getline(cin, name);
                        found = eventManager.searchByName(name);
                        break;

                    case 3:
                        cout << "Enter Event Date (YYYY-MM-DD): ";
                        getline(cin, date);

                        cout << "Enter Event Name: ";
                        getline(cin, name);

                        found = eventManager.searchEventHybrid(date, name);
                        break;

                    default:
                        cout << "Invalid search option.\n";
                        continue;
                }

                if (found)
                    cout << "Event found.\n";
                else
                    cout << "No matching event found.\n";

                break;
            }

            case 4:
            eventManager.showAllEvents();
            break;

            case 5: {
                string oldName, oldDate;
                string newName, newDate;
                int newCapacity;

                cin.ignore();

                cout << "Current Event Name: ";
                getline(cin, oldName);

                cout << "Current Event Date (YYYY-MM-DD): ";
                getline(cin, oldDate);

                cout << "New Event Name: ";
                getline(cin, newName);

                cout << "New Event Date (YYYY-MM-DD): ";
                getline(cin, newDate);

                cout << "New Capacity: ";
                cin >> newCapacity;

                if (eventManager.updateEvent(
                        oldDate, oldName,
                        newName, newDate,
                        newCapacity
                )) {
                    cout << "Event updated successfully.\n";
                } else {
                    cout << "Event not found. Update failed.\n";
                }

                break;
            }


            case 6: {
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

        case 7: {
            int pid;
            string name, date;

            cout << "Participant ID: ";
            cin >> pid;
            cin.ignore();

            cout << "Event Name: ";
            getline(cin, name);

            cout << "Event Date: ";
            getline(cin, date);

            if (!scheduleManager.registerParticipantForEvent(pid, date, name)) {
            cout << "Participant not registered. Please register first.\n";
            } else {
            cout << "Participant registered successfully.\n";
            }

            break;
        }

        case 8:
            scheduleManager.undoLastScheduleAction();
            fileManager.log("Undo last action");
            break;

        case 9:
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
