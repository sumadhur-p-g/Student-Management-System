# Student Management System

A console-based Student Management System developed using **C++**. The project allows users to add, view, search, update, and delete student records while also providing class statistics and sorting functionality.

## Features

* Add new student records
* View all students
* Search students using Student ID
* Update student information
* Delete student records
* Calculate class statistics
* Sort students by marks
* Automatically assign grades and pass/fail status
* Store student data using file handling
* Validate student ID, age, and marks

## Technologies Used

* **Language:** C++
* **Concepts:** Structures, Arrays, Functions, Loops, Conditional Statements
* **File Handling:** `ifstream`, `ofstream`
* **Algorithm:** Bubble Sort
* **IDE:** Visual Studio Code
* **Compiler:** MinGW g++

## Student Information

Each student record contains:

* Student ID
* Name
* Age
* Marks
* Grade
* Pass/Fail Result

## Menu Options

```text
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Class Statistics
7. Sort Students by Marks
8. Exit
```

## Class Statistics

The system calculates:

* Total number of students
* Average marks
* Highest marks
* Lowest marks
* Number of passed students
* Number of failed students

## File Handling

Student records are stored in a `students.txt` file so that the data can be loaded when the program starts and saved when records are added, updated, or deleted.

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/sumadhur-p-g/Student-Management-System.git
```

### 2. Open the project folder

Open the folder in **Visual Studio Code**.

### 3. Compile the program

```bash
g++ main.cpp -o student
```

### 4. Run the program

On Windows:

```bash
.\student.exe
```

## What I Learned

Through this project, I practiced:

* C++ structures
* Arrays and loops
* Functions
* File handling
* Searching
* Sorting algorithms
* Input validation
* CRUD operations
* Basic problem solving
* Building a complete console-based application
