#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20   // Total array size
#define N 3      // Number of stacks

int arr[MAX];
int top[N];
int size = MAX / N;

// Function to initialize all stacks
void initialize() {
    for (int i = 0; i < N; i++) {
        top[i] = i * size - 1;
    }
}

// Push operation
void push(int sn, int value) {
    if (sn < 1 || sn > N) {
        cout << "Invalid stack number!" << endl;
        return;
    }
    sn--; // convert to 0-based index

    if (top[sn] == (sn + 1) * size - 1) {
        cout << "Stack " << sn + 1 << " Overflow!" << endl;
        return;
    }

    arr[++top[sn]] = value;
    cout << "Pushed " << value << " into Stack " << sn + 1 << endl;
}

// Pop operation
void pop(int sn) {
    if (sn < 1 || sn > N) {
        cout << "Invalid stack number!" << endl;
        return;
    }
    sn--;

    if (top[sn] == sn * size - 1) {
        cout << "Stack " << sn + 1 << " Underflow!" << endl;
        return;
    }

    cout << "Popped " << arr[top[sn]--] << " from Stack " << sn + 1 << endl;
}

// Display operation
void display(int sn) {
    if (sn < 1 || sn > N) {
        cout << "Invalid stack number!" << endl;
        return;
    }
    sn--;

    if (top[sn] == sn * size - 1) {
        cout << "Stack " << sn + 1 << " is empty!" << endl;
        return;
    }

    cout << "Stack " << sn + 1 << " elements: ";
    for (int i = top[sn]; i >= sn * size; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, stackNo, value;
    initialize();

    while (true) {
        cout << "\n--- Multiple Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter stack number (1-" << N << "): ";
                cin >> stackNo;
                cout << "Enter value: ";
                cin >> value;
                push(stackNo, value);
                break;
            case 2:
                cout << "Enter stack number (1-" << N << "): ";
                cin >> stackNo;
                pop(stackNo);
                break;
            case 3:
                cout << "Enter stack number (1-" << N << "): ";
                cin >> stackNo;
                display(stackNo);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
