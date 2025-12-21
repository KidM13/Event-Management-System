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
                string date, name;

                cout << "Enter Event Date (YYYY-MM-DD): ";
                cin >> date;
                cin.ignore();

                cout << "Enter Event Name: ";
                getline(cin, name);

                eventManager.removeEvent(date, name);
                break;
            }

            case 3: {
                string date, name;

                cout << "Enter Event Date (YYYY-MM-DD): ";
                cin >> date;
                cin.ignore();

                cout << "Enter Event Name: ";
                getline(cin, name);

                if (eventManager.searchEvent(date, name))
                    cout << "Event found.\n";
                else
                    cout << "Event not found.\n";
                break;
            }

            case 4:
                eventManager.showAllEvents();
                break;

            case 5: {
                int pid;
                string pname, eventDate, eventName;

                cout << "Enter Participant ID: ";
                cin >> pid;
                cin.ignore();

                cout << "Enter Participant Name: ";
                getline(cin, pname);

                cout << "Enter Event Date (YYYY-MM-DD): ";
                cin >> eventDate;
                cin.ignore();

                cout << "Enter Event Name: ";
                getline(cin, eventName);

                participantManager.registerParticipant(
                        pid, pname, eventDate, eventName
                );
                break;
            }

            case 6: {
                string eventDate, eventName;

                cout << "Enter Event Date (YYYY-MM-DD): ";
                cin >> eventDate;
                cin.ignore();

                cout << "Enter Event Name: ";
                getline(cin, eventName);

                participantManager.processWaitingList(
                        eventDate, eventName
                );
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
