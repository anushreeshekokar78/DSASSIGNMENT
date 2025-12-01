#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


struct Appointment {
    int start;      // Start time in minutes (e.g., 540 = 9:00 AM)
    int end;        // End time in minutes
    bool booked;    // Whether the appointment slot is booked or not
    Appointment* next;
};


string formatTime(int minutes) {
    int hour = minutes / 60;
    int min = minutes % 60;
    char buffer[6];
    sprintf(buffer, "%02d:%02d", hour, min);
    return string(buffer);
}

// Create a random schedule
void createRandomSchedule(Appointment*& head, int startDay, int endDay, int minDur, int maxDur) {
    srand(time(0));
    int currentTime = startDay;

    while (currentTime + minDur <= endDay) {
        int duration = minDur + rand() % (maxDur - minDur + 1);
        int endTime = currentTime + duration;

        if (endTime > endDay) break;

        Appointment* newNode = new Appointment;
        newNode->start = currentTime;
        newNode->end = endTime;
        newNode->booked = false;
        newNode->next = nullptr;

        // Insert at end of linked list
        if (head == nullptr) {
            head = newNode;
        } else {
            Appointment* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }

        currentTime = endTime; // Move to next available start time
    }
}

// Display available appointments
void displayAppointments(Appointment* head) {
    cout << "\nCurrent Appointment Schedule:\n";
    cout << "-----------------------------------------\n";
    cout << "Start Time   End Time   Status\n";
    cout << "-----------------------------------------\n";

    Appointment* temp = head;
    while (temp != nullptr) {
        cout << formatTime(temp->start) << "    "
             << formatTime(temp->end) << "    "
             << (temp->booked ? "Booked" : "Available") << endl;
        temp = temp->next;
    }
    cout << "-----------------------------------------\n";
}

// Book an appointment
void bookAppointment(Appointment* head, int start, int end) {
    Appointment* temp = head;
    while (temp != nullptr) {
        if (temp->start == start && temp->end == end) {
            if (!temp->booked) {
                temp->booked = true;
                cout << "Appointment booked successfully!\n";
            } else {
                cout << "Error: This time slot is already booked.\n";
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Error: Appointment slot not found.\n";
}

// Cancel an appointment
void cancelAppointment(Appointment* head, int start, int end) {
    Appointment* temp = head;
    while (temp != nullptr) {
        if (temp->start == start && temp->end == end) {
            if (temp->booked) {
                temp->booked = false;
                cout << "Appointment cancelled successfully!\n";
            } else {
                cout << "Error: This slot was not booked.\n";
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Error: Appointment slot not found.\n";
}

/* =============================== SORTING =============================== */
// Sort appointments by swapping data values
void sortByData(Appointment* head) {
    if (!head) return;
    for (Appointment* i = head; i->next != nullptr; i = i->next) {
        for (Appointment* j = i->next; j != nullptr; j = j->next) {
            if (i->start > j->start) {
                // Swap start, end, and booked status
                swap(i->start, j->start);
                swap(i->end, j->end);
                swap(i->booked, j->booked);
            }
        }
    }
    cout << "List sorted by data swapping successfully!\n";
}

// Sort appointments by pointer manipulation (no data swapping)
void sortByPointer(Appointment*& head) {
    if (!head || !head->next) return;

    Appointment* sorted = nullptr;

    while (head != nullptr) {
        Appointment* current = head;
        head = head->next;

        if (sorted == nullptr || current->start < sorted->start) {
            current->next = sorted;
            sorted = current;
        } else {
            Appointment* temp = sorted;
            while (temp->next != nullptr && temp->next->start < current->start) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
    cout << "List sorted by pointer manipulation successfully!\n";
}

/* =============================== MAIN FUNCTION =============================== */
int main() {
    Appointment* head = nullptr;

    // Define schedule limits
    int dayStart = 9 * 60;   // 9:00 AM in minutes
    int dayEnd = 17 * 60;    // 5:00 PM in minutes
    int minDuration = 30;    // Minimum appointment duration (30 min)
    int maxDuration = 60;    // Maximum appointment duration (60 min)

    // Create random schedule
    createRandomSchedule(head, dayStart, dayEnd, minDuration, maxDuration);

    int choice;
    do {
        cout << "\n===== Appointment Scheduler Menu =====\n";
        cout << "1. Display available appointments\n";
        cout << "2. Book an appointment\n";
        cout << "3. Cancel an appointment\n";
        cout << "4. Sort by data swapping\n";
        cout << "5. Sort by pointer manipulation\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int start, end;
        switch (choice) {
        case 1:
            displayAppointments(head);
            break;

        case 2:
            cout << "Enter start time (HH MM): ";
            int sh, sm;
            cin >> sh >> sm;
            start = sh * 60 + sm;

            cout << "Enter end time (HH MM): ";
            int eh, em;
            cin >> eh >> em;
            end = eh * 60 + em;

            bookAppointment(head, start, end);
            break;

        case 3:
            cout << "Enter start time (HH MM) to cancel: ";
            cin >> sh >> sm;
            start = sh * 60 + sm;

            cout << "Enter end time (HH MM) to cancel: ";
            cin >> eh >> em;
            end = eh * 60 + em;

            cancelAppointment(head, start, end);
            break;

        case 4:
            sortByData(head);
            break;

        case 5:
            sortByPointer(head);
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    // Free memory
    while (head != nullptr) {
        Appointment* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
