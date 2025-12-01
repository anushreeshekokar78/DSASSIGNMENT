#include <iostream>
using namespace std;

// Structure for a seat in a row
struct Seat {
    int seatNumber;
    bool booked;
    Seat* next;
    Seat* prev;
};

// Create a circular doubly linked list for a row
Seat* createRow(int seatsPerRow) {
    Seat* head = nullptr;
    Seat* prev = nullptr;

    for (int i = 1; i <= seatsPerRow; i++) {
        Seat* s = new Seat;
        s->seatNumber = i;
        s->booked = false;
        s->next = nullptr;
        s->prev = nullptr;

        if (!head) head = s;
        else {
            prev->next = s;
            s->prev = prev;
        }
        prev = s;
    }

    head->prev = prev;
    prev->next = head;

    return head;
}

// Display all available seats
void displaySeats(Seat* rows[], int totalRows) {
    cout << "\nSeat Availability:\n";
    for (int i = 0; i < totalRows; i++) {
        cout << "Row " << i + 1 << ": ";
        Seat* temp = rows[i];
        do {
            if (!temp->booked) cout << temp->seatNumber << " ";
            temp = temp->next;
        } while (temp != rows[i]);
        cout << "\n";
    }
}

// Book seats in a row
void bookSeats(Seat* row) {
    int numSeats;
    cout << "Enter number of seats to book: ";
    cin >> numSeats;

    for (int i = 0; i < numSeats; i++) {
        int seatNo;
        cout << "Enter seat number to book: ";
        cin >> seatNo;

        Seat* temp = row;
        bool found = false;
        do {
            if (temp->seatNumber == seatNo) {
                if (!temp->booked) {
                    temp->booked = true;
                    cout << "Seat " << seatNo << " booked successfully.\n";
                } else cout << "Seat " << seatNo << " is already booked.\n";
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != row);
        if (!found) cout << "Invalid seat number!\n";
    }
}

// Cancel booking in a row
void cancelBooking(Seat* row) {
    int seatNo;
    cout << "Enter seat number to cancel: ";
    cin >> seatNo;

    Seat* temp = row;
    bool found = false;
    do {
        if (temp->seatNumber == seatNo) {
            if (temp->booked) {
                temp->booked = false;
                cout << "Booking of seat " << seatNo << " canceled.\n";
            } else cout << "Seat " << seatNo << " was not booked.\n";
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != row);
    if (!found) cout << "Invalid seat number!\n";
}

// Main function
int main() {
    const int ROWS = 8;
    const int SEATS = 8;
    Seat* rows[ROWS];

    // Create all rows
    for (int i = 0; i < ROWS; i++) rows[i] = createRow(SEATS);

    int choice;
    do {
        cout << "\n--- Galaxy Multiplex Ticket System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seats\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int rowNumber;
        switch (choice) {
            case 1: displaySeats(rows, ROWS); break;
            case 2:
                cout << "Enter row number (1-8): ";
                cin >> rowNumber;
                if (rowNumber >= 1 && rowNumber <= ROWS) bookSeats(rows[rowNumber - 1]);
                else cout << "Invalid row number!\n";
                break;
            case 3:
                cout << "Enter row number (1-8): ";
                cin >> rowNumber;
                if (rowNumber >= 1 && rowNumber <= ROWS) cancelBooking(rows[rowNumber - 1]);
                else cout << "Invalid row number!\n";
                break;
            case 4: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
