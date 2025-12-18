# Event-Management-System

This is a C++ command line based event management system developed as a
Data Structures and Algorithms semester project.

The system allows users to manage events such as adding new events,
searching events by ID, and viewing stored event information.
The main focus of the project is to apply data structures in a practical way.

## How the system works

- Events are stored in memory using a Binary Search Tree (BST)
- Each event has an ID, name, date, and capacity
- The event ID is used as the key for searching
- Data is loaded from a CSV file when the program starts
- Data is saved back to the CSV file when the program exits

No database is used. File handling is done using simple CSV files.

## Main functionalities

- Add a new event
- Search an event by ID
- Display stored events
- Save and load event data from file

## How to run

The project is written in C++ and can be compiled using any standard compiler.

Example using g++:

g++ src/*.cpp -I include -o event_system
to run it use
./event_system

## Notes

This project is intended for learning purposes and focuses on
clear implementation of data structures rather than advanced libraries.
