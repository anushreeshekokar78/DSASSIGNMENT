#include <iostream>
#include <string>
using namespace std;

// Define a structure to store student details
struct Student {
    string name;
    int rollNo;
    string div;
    string year;
};

// Function for Linear Search
// It will check each student one by one until a match is found
void linearSearch(Student students[], int n, string searchName, int searchRoll, string searchDiv) {
    bool found = false;

    for (int i = 0; i < n; i++) {
       
        if (students[i].name == searchName && 
            students[i].rollNo == searchRoll && 
            students[i].div == searchDiv) 
        {
            cout << "\n Student Found!" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll No: " << students[i].rollNo << endl;
            cout << "Division: " << students[i].div << endl;
            cout << "Year: " << students[i].year << endl;
            found = true;
            break;
        }
    }

   
    if (!found) {
        cout << "\n Student Not Found!" << endl;
    }
}

int main() {
    int n, choice;

    cout << "Enter number of students: ";
    cin >> n;

    Student students[50];  

    cout << "\n--- Enter Student Details ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Enter Name: ";
        cin >> students[i].name;   
        cout << "Enter Roll No: ";
        cin >> students[i].rollNo; 
        cout << "Enter Division (like A/B/C/X): ";
        cin >> students[i].div;   
        cout << "Enter Year (SY/TY/BTech): ";
        cin >> students[i].year;   
    }

    // Menu-driven program using switch-case
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Search Student (Linear Search)" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string searchName, searchDiv;
                int searchRoll;

                cout << "\nEnter Name to search: ";
                cin >> searchName;
                cout << "Enter Roll No to search: ";
                cin >> searchRoll;
                cout << "Enter Division to search: ";
                cin >> searchDiv;

                // Call search function
                linearSearch(students, n, searchName, searchRoll, searchDiv);
                break;
            }

            case 2:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 2); 

    return 0;
}
// 
// Time Complexity = O(n), Space Complexity = O(n)
