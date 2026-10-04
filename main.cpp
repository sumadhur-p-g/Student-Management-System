#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

struct Student {
    int id;
    string name;
    int age;
    float marks;
};
void saveStudents(Student students[], int count) {

    ofstream file("students.txt");

    for (int i = 0; i < count; i++) {

        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].marks << endl;
    }

    file.close();
}
int loadStudents(Student students[]) {

    ifstream file("students.txt");

    int count = 0;

    while (count < 100 && file >> students[count].id)  {

        file.ignore();

        std::getline(file, students[count].name);

        file >> students[count].age;
        file >> students[count].marks;

        count++;

        
    }

    file.close();

    return count;
}

int main() {

    Student students[100];
    int count = loadStudents(students);
    int choice;

    do {
        cout << "\n====================================" << endl;
        cout << "      STUDENT MANAGEMENT SYSTEM     " << endl;
        cout << "====================================" << endl;

        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Class Statistics" << endl;
        cout << "7. Sort Students by Marks" << endl;
        cout << "8. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

    if (count >= 100) {
        cout << "\nStudent limit reached!" << endl;
        break;
    }

    int newID;
    bool duplicate = false;

    do {
        cout << "\nEnter Student ID: ";
        cin >> newID;

        if (newID <= 0) {
            cout << "Invalid ID. Please enter a positive number." << endl;
        }

    } while (newID <= 0);

    // Check duplicate ID
    for (int i = 0; i < count; i++) {

        if (students[i].id == newID) {
            duplicate = true;
            break;
        }
    }

    if (duplicate) {

        cout << "\nStudent ID already exists!" << endl;
        cout << "Please use a different ID." << endl;

        break;
    }

    students[count].id = newID;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, students[count].name);

    do {
        cout << "Enter Student Age: ";
        cin >> students[count].age;

        if (students[count].age < 1 || students[count].age > 100) {
            cout << "Invalid age. Please enter an age between 1 and 100." << endl;
        }

    } while (students[count].age < 1 || students[count].age > 100);

    do {
        cout << "Enter Student Marks: ";
        cin >> students[count].marks;

        if (students[count].marks < 0 || students[count].marks > 100) {
            cout << "Invalid marks. Please enter marks between 0 and 100." << endl;
        }

    } while (students[count].marks < 0 || students[count].marks > 100);

    count++;

    saveStudents(students, count);

    cout << "\nStudent added successfully!" << endl;

    break;
}


            case 2: {

    if (count == 0) {
        cout << "\nNo students available." << endl;
    }
    else {

        cout << "\n============================================================" << endl;
        cout << "                    STUDENT LIST" << endl;
        cout << "============================================================" << endl;

        cout << "\n"
             << "ID       "
             << "Name                 "
             << "Age    "
             << "Marks    "
             << "Grade    "
             << "Result" << endl;

        cout << "------------------------------------------------------------" << endl;

        for (int i = 0; i < count; i++) {

            string grade;

            if (students[i].marks >= 90) {
                grade = "A+";
            }
            else if (students[i].marks >= 80) {
                grade = "A";
            }
            else if (students[i].marks >= 70) {
                grade = "B";
            }
            else if (students[i].marks >= 60) {
                grade = "C";
            }
            else if (students[i].marks >= 50) {
                grade = "D";
            }
            else if (students[i].marks >= 40) {
                grade = "E";
            }
            else {
                grade = "F";
            }

            string result;

            if (students[i].marks >= 40) {
                result = "PASS";
            }
            else {
                result = "FAIL";
            }

            cout << students[i].id << "       "
                 << students[i].name << "                 "
                 << students[i].age << "      "
                 << students[i].marks << "       "
                 << grade << "       "
                 << result << endl;
        }

        cout << "------------------------------------------------------------" << endl;
    }

    break;
}


            case 3: {

                int searchID;
                bool found = false;

                cout << "\nEnter Student ID to search: ";
                cin >> searchID;

                for (int i = 0; i < count; i++) {

                    if (students[i].id == searchID) {

                        cout << "\n===== STUDENT FOUND =====" << endl;
                        cout << "ID: " << students[i].id << endl;
                        cout << "Name: " << students[i].name << endl;
                        cout << "Age: " << students[i].age << endl;
                        cout << "Marks: " << students[i].marks << endl;
                        if (students[i].marks >= 90) {
    cout << "Grade: A+" << endl;
}
else if (students[i].marks >= 80) {
    cout << "Grade: A" << endl;
}
else if (students[i].marks >= 70) {
    cout << "Grade: B" << endl;
}
else if (students[i].marks >= 60) {
    cout << "Grade: C" << endl;
}
else if (students[i].marks >= 50) {
    cout << "Grade: D" << endl;
}
else if (students[i].marks >= 40) {
    cout << "Grade: E" << endl;
}
else {
    cout << "Grade: F" << endl;
}

if (students[i].marks >= 40) {
    cout << "Result: PASS" << endl;
}
else {
    cout << "Result: FAIL" << endl;
}

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\nStudent not found." << endl;
                }

                break;
            }


            case 4: {

                int updateID;
                bool found = false;

                cout << "\nEnter Student ID to update: ";
                cin >> updateID;

                for (int i = 0; i < count; i++) {

                    if (students[i].id == updateID) {

                        cout << "\nStudent found!" << endl;

                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, students[i].name);

                        do {
    cout << "Enter new age: ";
    cin >> students[i].age;

    if (students[i].age < 1 || students[i].age > 100) {
        cout << "Invalid age. Please enter an age between 1 and 100." << endl;
    }

} while (students[i].age < 1 || students[i].age > 100);


do {
    cout << "Enter new marks: ";
    cin >> students[i].marks;

    if (students[i].marks < 0 || students[i].marks > 100) {
        cout << "Invalid marks. Please enter marks between 0 and 100." << endl;
    }

} while (students[i].marks < 0 || students[i].marks > 100);

saveStudents(students, count);
                

                        found = true;

                        cout << "\nStudent updated successfully!" << endl;

                        break;
                    }
                }

                if (!found) {
                    cout << "\nStudent not found." << endl;
                }

                break;
            }
            case 5: {

    int deleteID;
    bool found = false;

    cout << "\nEnter Student ID to delete: ";
    cin >> deleteID;

    for (int i = 0; i < count; i++) {

        if (students[i].id == deleteID) {

            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            saveStudents(students, count);
            found = true;

            cout << "\nStudent deleted successfully!" << endl;

            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found." << endl;
    }

    break;
}
            case 6: {

    if (count == 0) {
        cout << "\nNo students available." << endl;
        break;
    }

    float total = 0;
    float highest = students[0].marks;
    float lowest = students[0].marks;

    int passed = 0;
    int failed = 0;

    for (int i = 0; i < count; i++) {

        total = total + students[i].marks;

        if (students[i].marks > highest) {
            highest = students[i].marks;
        }

        if (students[i].marks < lowest) {
            lowest = students[i].marks;
        }

        if (students[i].marks >= 40) {
            passed++;
        }
        else {
            failed++;
        }
    }

    float average = total / count;

    cout << "\n========== CLASS STATISTICS ==========" << endl;

    cout << "Total Students: " << count << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Passed Students: " << passed << endl;
    cout << "Failed Students: " << failed << endl;

    break;
}
           case 7: {

    if (count == 0) {
        cout << "\nNo students available." << endl;
        break;
    }

    for (int i = 0; i < count - 1; i++) {

        for (int j = 0; j < count - i - 1; j++) {

            if (students[j].marks < students[j + 1].marks) {

                Student temp = students[j];

                students[j] = students[j + 1];

                students[j + 1] = temp;
            }
        }
    }

    cout << "\n===== STUDENTS SORTED BY MARKS =====" << endl;

    for (int i = 0; i < count; i++) {

        cout << "\nRank " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
    }

    break;
}


            case 8:

                cout << "\nThank you for using Student Management System!" << endl;

                break;


            default:

                cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}