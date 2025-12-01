#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Simple structure to represent a patient
struct Patient {
    string name;
    int age;
};

// Function to display the list of waiting patients
void displayQueue(queue<Patient> q) {
    if (q.empty()) {
        cout << "No patients are waiting.\n";
        return;
    }

    cout << "Patients in the queue:\n";
    int position = 1;
    while (!q.empty()) {
        Patient p = q.front();
        cout << position << ". " << p.name << " (Age: " << p.age << ")\n";
        q.pop();
        position++;
    }
    cout << endl;
}

int main() {
    queue<Patient> patientQueue;
    int choice;

    cout << "=== Welcome to the Clinic Patient Tracker ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Check-in a new patient\n";
        cout << "2. Assign patient to doctor\n";
        cout << "3. Show waiting patients\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                // Patient check-in
                Patient newPatient;
                cout << "Enter patient name: ";
                getline(cin, newPatient.name);
                cout << "Enter patient age: ";
                cin >> newPatient.age;
                cin.ignore();

                patientQueue.push(newPatient);
                cout << "Patient \"" << newPatient.name << "\" added to the queue.\n";
                break;
            }

            case 2: {
                // Assign next patient to doctor
                if (patientQueue.empty()) {
                    cout << "No patients in the queue to assign.\n";
                } else {
                    Patient nextPatient = patientQueue.front();
                    patientQueue.pop();
                    cout << "Assigning \"" << nextPatient.name << "\" (Age: " << nextPatient.age << ") to the doctor.\n";
                }
                break;
            }

            case 3: {
                // Display current queue
                displayQueue(patientQueue);
                break;
            }

            case 0:
                cout << "Exiting the system. Have a good day!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
