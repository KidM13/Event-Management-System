#include <iostream>
#include "modules/event_manager.h"
#include "modules/participant_manager.h"

using namespace std;

int main() {
    EventManager eventManager;
    ParticipantManager participantManager(eventManager);

    int choice;

    do {
        cout << "\n===== Event Management System =====\n";
        cout << "1. Add Event\n";
        cout << "2. Remove Event\n";
        cout << "3. Search Event\n";
        cout << "4. Display All Events\n";
        cout << "5. Register Participant\n";
        cout << "6. Process Waiting List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int id, capacity;
                string name, date;

                cout << "Enter Event ID: ";
                cin >> id;
                cin.ignore();

                cout << "Enter Event Name: ";
                getline(cin, name);

                cout << "Enter Event Date (YYYY-MM-DD): ";
                cin >> date;

                cout << "Enter Capacity: ";
                cin >> capacity;

                eventManager.addEvent(id, name, date, capacity);
                break;
            }

            case 2: {
                string date;
                cout << "Enter Event Date to remove: ";
                cin >> date;
                eventManager.removeEvent(date);
                break;
            }

            case 3: {
                string date;
                cout << "Enter Event Date to search: ";
                cin >> date;
                eventManager.searchEvent(date);
                break;
            }

            case 4:
                eventManager.showAllEvents();
                break;

            case 5: {
                int pid;
                string pname, eventDate;

                cout << "Enter Participant ID: ";
                cin >> pid;
                cin.ignore();

                cout << "Enter Participant Name: ";
                getline(cin, pname);

                cout << "Enter Event Date to register for: ";
                cin >> eventDate;

                participantManager.registerParticipant(pid, pname, eventDate);
                break;
            }

            case 6: {
                string eventDate;
                cout << "Enter Event Date to process waiting list: ";
                cin >> eventDate;

                participantManager.processWaitingList(eventDate);
                break;
            }

            case 0:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
