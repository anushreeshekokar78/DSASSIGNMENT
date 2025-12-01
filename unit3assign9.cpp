#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

// Class to manage two separate queues using arrays
class MultipleQueues {
private:
    int queue1[MAX_SIZE], queue2[MAX_SIZE];
    int front1, rear1;
    int front2, rear2;

public:
    MultipleQueues() {
        front1 = rear1 = -1;
        front2 = rear2 = -1;
    }

    void enqueue(int queueNumber, int element) {
        if (queueNumber == 1) {
            if (rear1 == MAX_SIZE - 1) {
                cout << "Queue 1 is full! Cannot add more elements.\n";
            } else {
                if (front1 == -1) front1 = 0;
                rear1++;
                queue1[rear1] = element;
                cout << "Element " << element << " added to Queue 1.\n";
            }
        } else if (queueNumber == 2) {
            if (rear2 == MAX_SIZE - 1) {
                cout << "Queue 2 is full! Cannot add more elements.\n";
            } else {
                if (front2 == -1) front2 = 0;
                rear2++;
                queue2[rear2] = element;
                cout << "Element " << element << " added to Queue 2.\n";
            }
        } else {
            cout << "Invalid queue number! Choose 1 or 2.\n";
        }
    }

    void dequeue(int queueNumber) {
        if (queueNumber == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty! Nothing to delete.\n";
            } else {
                cout << "Removed element " << queue1[front1] << " from Queue 1.\n";
                front1++;
            }
        } else if (queueNumber == 2) {
            if (front2 == -1 || front2 > rear2) {
                cout << "Queue 2 is empty! Nothing to delete.\n";
            } else {
                cout << "Removed element " << queue2[front2] << " from Queue 2.\n";
                front2++;
            }
        } else {
            cout << "Invalid queue number! Choose 1 or 2.\n";
        }
    }

    void display(int queueNumber) {
        if (queueNumber == 1) {
            if (front1 == -1 || front1 > rear1) {
                cout << "Queue 1 is empty.\n";
            } else {
                cout << "Queue 1 elements: ";
                for (int i = front1; i <= rear1; ++i)
                    cout << queue1[i] << " ";
                cout << endl;
            }
        } else if (queueNumber == 2) {
            if (front2 == -1 || front2 > rear2) {
                cout << "Queue 2 is empty.\n";
            } else {
                cout << "Queue 2 elements: ";
                for (int i = front2; i <= rear2; ++i)
                    cout << queue2[i] << " ";
                cout << endl;
            }
        } else {
            cout << "Invalid queue number! Choose 1 or 2.\n";
        }
    }
};

int main() {
    MultipleQueues mq;
    int choice, queueNumber, element;

    cout << "=== Multiple Queues System ===\n";

    do {
        cout << "\nOperations Menu:\n";
        cout << "1. Add element to a queue\n";
        cout << "2. Delete element from a queue\n";
        cout << "3. Display a queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNumber;
                cout << "Enter element to add: ";
                cin >> element;
                mq.enqueue(queueNumber, element);
                break;

            case 2:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNumber;
                mq.dequeue(queueNumber);
                break;

            case 3:
                cout << "Enter queue number (1 or 2): ";
                cin >> queueNumber;
                mq.display(queueNumber);
                break;

            case 0:
                cout << "Exiting system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
