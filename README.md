# Digital Library Management System

A menu-driven **Digital Library Management System built in C** as a Programming Fundamentals project.

The system manages student library cards, memberships, book issuing and returns, fines, reading bonuses, and student summary reports through a console-based interface.

## Overview

The project was developed to apply core C programming concepts to a practical management system.

Instead of implementing each operation as a separate program, the system combines multiple operations into a single interactive workflow where users can register or identify themselves, manage books, calculate fines, and view their current library status.

## Features

* **Student ID Management**

  * Supports existing student IDs
  * Automatically registers valid existing-range IDs when they are first used
  * Generates new library card IDs for new users

* **Membership Management**

  * Student Membership — 25% discount
  * Regular Membership — 15% discount
  * Premium Membership — 35% discount
  * No Membership — 0% discount

* **Book Management**

  * Issue books to students
  * Track currently issued books
  * Enforce a maximum of 10 issued books per student
  * Return multiple books at once

* **Fine Calculation**

  * Calculates late-return fines after 15 days
  * Applies damage fines for damaged books
  * Maintains accumulated fines for each student

* **Reading Bonus**

  * Students who complete at least 3 books within 15 days can unlock a reading bonus
  * Displays bonus course and enrollment information

* **Student Summary**

  * Displays student ID
  * Shows currently issued books
  * Displays membership type
  * Calculates applicable discounts
  * Calculates total payable amount including applicable card fees

* **Input Validation**

  * Handles invalid numeric input
  * Prevents invalid book quantities
  * Validates membership selections
  * Prevents returning more books than currently issued

## Technical Implementation

The system is implemented using standard C and uses:

* Functions and function prototypes
* Arrays for storing student records and system state
* `#define` constants for configurable limits and fees
* `if/else` and `switch` control structures
* `for` and `do-while` loops
* Input validation using `scanf()` and input-buffer handling
* Modular functions for individual system operations

### Data Model

Student information is maintained through parallel arrays:

* `studentIDs[]` — stores student/library card IDs
* `issuedBooks[]` — tracks the number of currently issued books
* `studentFines[]` — stores accumulated fines
* `memberTypes[]` — stores membership selections

The system currently supports up to **200 student records** and a maximum of **10 books per student**.

## Program Flow

```text
Start
  │
  ├── Display Library Rules
  │
  └── Main Menu
       │
       ├── Issue Books
       │    ├── Validate Student ID
       │    ├── Register/Issue Card if required
       │    ├── Select Membership
       │    └── Issue Books
       │
       ├── Return Book
       │    ├── Validate Student ID
       │    ├── Enter Books Returned
       │    ├── Calculate Late Fine
       │    ├── Calculate Damage Fine
       │    └── Update Student Record
       │
       ├── Reading Bonus Award
       │    └── Check Books Completed
       │
       ├── Student Summary Report
       │    ├── Membership Discount
       │    ├── Total Fine
       │    └── Total Payable
       │
       └── Exit
```

## Rules Implemented

| Rule                      |        Value |
| ------------------------- | -----------: |
| Maximum books per student |           10 |
| Maximum student records   |          200 |
| Standard borrowing period |      15 days |
| Late fine                 |   Rs. 50/day |
| Damage fine               | Rs. 200/book |
| New card fee              |      Rs. 500 |
| Reading bonus threshold   |      3 books |

## What I Learned

This project helped me strengthen my understanding of:

* Designing a program around multiple interacting functions
* Managing related data using arrays
* Passing data through function parameters
* Designing menu-driven console applications
* Validating user input
* Implementing business rules through conditional logic
* Performing calculations based on user state
* Breaking a larger problem into smaller functions

## Limitations

The current version is a **console-based, in-memory system**. Student records are stored in arrays during program execution and are not persisted to a file or database.

Future versions could introduce:

* Structures (`struct`) for cleaner record management
* File handling for persistent data
* A searchable book catalogue
* Individual book IDs
* User authentication
* Separate librarian and student roles
* Database integration
* A graphical or web-based interface

## Project Context

**Course:** Programming Fundamentals
**Language:** C
**Project Type:** Console-based management system
**Development Focus:** C programming fundamentals and problem solving

## Author

**Arooba Kinza**
BS Computer Science — DHA Suffa University

---

> This project represents an early-stage implementation of a real-world management system using core C programming concepts.
> clone: 
