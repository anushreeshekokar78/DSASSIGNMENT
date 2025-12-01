#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Simple structure to represent a passenger
struct Passenger {
    string name;
    int age;
};

int main() {
    queue<Passenger> passengerQueue;
    int choice;

    cout << "=== Welcome to the Ticket Agent Queue System ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new passenger to the queue\n";
        cout << "2. Show the passenger at the front of the queue\n";
        cout << "3. Remove the passenger at the front of the queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add new passenger
                Passenger p;
                cout << "Enter passenger name (single word): ";
                cin >> p.name;
                cout << "Enter passenger age: ";
                cin >> p.age;

                passengerQueue.push(p);
                cout << "Passenger " << p.name << " added to the queue.\n";
                break;
            }

            case 2: {
                // Show front passenger
                if (passengerQueue.empty()) {
                    cout << "The queue is currently empty.\n";
                } else {
                    Passenger frontPassenger = passengerQueue.front();
                    cout << "Front of the queue:\n";
                    cout << "Name: " << frontPassenger.name
                         << ", Age: " << frontPassenger.age << '\n';
                }
                break;
            }

            case 3: {
                // Remove front passenger
                if (passengerQueue.empty()) {
                    cout << "No passengers to remove. The queue is empty.\n";
                } else {
                    Passenger removedPassenger = passengerQueue.front();
                    passengerQueue.pop();
                    cout << "Removed passenger " << removedPassenger.name
                         << " from the queue.\n";
                }
                break;
            }

            case 0:
                cout << "\nExiting system.\n";
                cout << "Number of passengers left in the queue: "
                     << passengerQueue.size() << '\n';
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
