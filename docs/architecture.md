# Architecture of Event Management System

### Overview
- The Event Management System is a **C++ console-based application** that manages events, participants, and scheduling.
- Follows a **modular design** with clear separation between data structures, functional modules, and file handling.

### Folder Structure
- `event-management-system/`
  - `src/`
    - `ds/` → Data structure implementations (BST, Queue, Stack, Hash)
    - `modules/` → Functional modules built using data structures
    - `main.cpp` → CLI entry point
  - `data/` → File-based storage
    - `events.txt`
    - `participants.txt`
    - `logs.txt`
  - `docs/` → Project documentation

### Modules
- **Event Manager**
  - Handles creation, update, deletion, search, and sorting of events
  - Uses **BST** for storing events sorted by date
- **Participant Manager**
  - Manages registration and removal of participants
  - Uses **Hash Table** for fast participant lookup
- **Schedule Manager**
  - Manages event schedules and waiting lists
  - Uses **Queue** for waiting lists
  - Uses **Stack** to support undoing the last scheduling action
- **File Manager**
  - Centralized file I/O for reading/writing `events.txt`, `participants.txt`, and `logs.txt`
  - Ensures persistence of all system data

### Data Flow
- User inputs in CLI are handled by modules
- Modules update data structures
- File Manager persists changes to text files
- Stack tracks last action for undo functionality

### Data Structures Summary
- **BST** → Event sorting and fast retrieval by date/name
- **Queue** → Waiting lists for events
- **Stack** → Undo last schedule change
- **Hash Table** → Fast participant lookup
