# Event-Management-System

## Overview
This project is a **console-based Event Management System** implemented in **C++** using fundamental **data structures**.

The system allows users to:
- Create, update, delete, and search events
- Register participants
- Schedule participants to events with waitlisting
- Undo scheduling actions
- Persist data using text files

The project demonstrates the practical use of:
- Binary Search Tree (BST)
- Hash Table
- Queue
- Stack
- Modular system design

---


## Build and Run Instructions

### Prerequisites
- C++ compiler with **C++17** support
- Git

---

## Windows (MinGW / MSYS2 / Git Bash)

### 1. Install Compiler
Install **MinGW-w64** and ensure `g++` is added to your system `PATH`.

Verify installation:
bash
g++ --version

- compile the from the project root directory means

cd Event_management_system
```

g++ src/main.cpp src/modules/*.cpp src/ds/*.cpp -o event_manager

```

- then run the program

./event_manager

## Linux (GCC)

- install GCC
  
sudo apt update

sudo apt install g++

Verify installation:
bash
g++ --version

- compile the from the project root directory means

cd Event_management_system

```
g++ src/main.cpp src/modules/*.cpp src/ds/*.cpp -o event_manager
```

- then run the program

./event_manager




## Notes

This project is intended for learning purposes and focuses on
clear implementation of data structures rather than advanced libraries.
