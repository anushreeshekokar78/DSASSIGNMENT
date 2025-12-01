#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    string customerName;
    Node* next;
};

// Class to implement the queue using linked list
class CallCenterQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor initializes the queue as empty
    CallCenterQueue() {
        front = rear = nullptr;
    }

    // Enqueue a new customer call
    void enqueue(const string& name) {
        Node* newNode = new Node;
        newNode->customerName = name;
        newNode->next = nullptr;

        if (rear == nullptr) {
            // First customer in the queue
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Customer call from \"" << name << "\" added to the queue.\n";
    }

    // Dequeue a customer call to assist
    void dequeue() {
        if (front == nullptr) {
            cout << "No calls in the queue. Waiting for customer calls...\n";
            return;
        }

        Node* temp = front;
        cout << "Assisting customer: " << temp->customerName << '\n';
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // Queue is now empty
        }

        delete temp;
    }

    // Display the current queue of waiting calls
    void displayQueue() {
        if (front == nullptr) {
            cout << "The call queue is empty.\n";
            return;
        }

        cout << "Current waiting calls:\n";
        Node* temp = front;
        int position = 1;
        while (temp != nullptr) {
            cout << position << ". " << temp->customerName << '\n';
            temp = temp->next;
            position++;
        }
    }
};

int main() {
    CallCenterQueue callQueue;
    int choice;
    string customerName;

    cout << "=== Call Center Queue System ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. New customer call arrives\n";
        cout << "2. Assist next customer\n";
        cout << "3. Show waiting calls\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, customerName);
                callQueue.enqueue(customerName);
                break;

            case 2:
                callQueue.dequeue();
                break;

            case 3:
                callQueue.displayQueue();
                break;

            case 0:
                cout << "Exiting system.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
