cmake_minimum_required(VERSION 3.27)
project(Event_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/ds)
include_directories(src/modules)

add_executable(Event_Management_System
        src/ds/bst.cpp
        src/ds/bst.h
        src/ds/hash.cpp
        src/ds/hash.h
        src/ds/queue.cpp
        src/ds/queue.h
        src/ds/stack.cpp
        src/ds/stack.h
        src/modules/event_manager.cpp
        src/modules/event_manager.h
        src/modules/file_manager.cpp
        src/modules/file_manager.h
        src/modules/participant_manager.cpp
        src/modules/participant_manager.h
        src/modules/schedule_manager.cpp
        src/modules/schedule_manager.h
        src/main.cpp)
