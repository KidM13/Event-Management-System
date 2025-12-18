# Data Structures in Event Management System

## 1. Binary Search Tree (BST)
- **Purpose**: Store events sorted by date or name.
- **Operations**: Insert, Delete, Search, Traverse.
- **Use Case**: Quickly find events or sort them chronologically.
- **Complexity**:
  - Insertion/Search/Delete: O(log n) average, O(n) worst-case.

## 2. Queue
- **Purpose**: Manage waiting lists for events.
- **Operations**: Enqueue, Dequeue, Peek.
- **Use Case**: Maintain first-come-first-served registration order.
- **Complexity**:
  - All operations: O(1).

## 3. Stack
- **Purpose**: Undo the last scheduling action.
- **Operations**: Push, Pop, Peek.
- **Use Case**: Reverse last operation (add/update/delete event).
- **Complexity**:
  - All operations: O(1).

## 4. Hash Table
- **Purpose**: Fast participant lookup by ID or name.
- **Operations**: Insert, Search, Delete.
- **Use Case**: Quickly check or update participant information.
- **Complexity**:
  - Insertion/Search/Delete: O(1) average, O(n) worst-case.
