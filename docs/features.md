# Features of Event Management System

## Event Management
- Add, update, and delete events.
- Search and sort events by date or name.
- Display all events in sorted order.

## Participant Management
- Register new participants for events.
- Remove participants from events.
- Lookup participant details quickly using Hash Table.

## Schedule Management
- Manage waiting lists for events using Queue.
- Undo the last schedule change using Stack.

## File Persistence
- All data is saved to text files:
  - `events.txt` → Stores event details
  - `participants.txt` → Stores participant details
  - `logs.txt` → Stores system logs and actions
- Ensures data is preserved between sessions.

## Reports
- Generate event reports (participants, schedule, availability).
- Easy to extend for custom report generation.
