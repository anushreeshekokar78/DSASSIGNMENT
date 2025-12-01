#include <iostream>
#include <string>

using namespace std;

// Maximum number of orders the pizza parlour can accept
const int MAX_ORDERS = 5;

// Structure to represent a pizza order
struct Order {
    int orderId;
    string customerName;
    string pizzaType;
};

class CircularQueue {
private:
    Order orders[MAX_ORDERS];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAX_ORDERS;
    }

    bool isEmpty() {
        return count == 0;
    }

    void placeOrder() {
        if (isFull()) {
            cout << "Sorry, the order queue is full. Cannot accept more orders.\n";
            return;
        }

        Order newOrder;
        cout << "Enter Order ID: ";
        cin >> newOrder.orderId;
        cin.ignore(); // Clear buffer
        cout << "Enter Customer Name: ";
        getline(cin, newOrder.customerName);
        cout << "Enter Pizza Type (e.g., Margherita, Pepperoni): ";
        getline(cin, newOrder.pizzaType);

        rear = (rear + 1) % MAX_ORDERS;
        orders[rear] = newOrder;
        count++;

        cout << "Order placed successfully for " << newOrder.customerName << "!\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve right now.\n";
            return;
        }

        Order servedOrder = orders[front];
        cout << "Serving Order ID " << servedOrder.orderId
             << " for " << servedOrder.customerName
             << " (Pizza: " << servedOrder.pizzaType << ").\n";

        front = (front + 1) % MAX_ORDERS;
        count--;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "\nPending Orders in the Queue:\n";
        int index = front;
        for (int i = 0; i < count; ++i) {
            Order o = orders[index];
            cout << i + 1 << ". Order ID: " << o.orderId
                 << ", Customer: " << o.customerName
                 << ", Pizza: " << o.pizzaType << '\n';

            index = (index + 1) % MAX_ORDERS;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue pizzaQueue;
    int choice;

    cout << "=== Welcome to the Pizza Parlour Order System ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Place a new order\n";
        cout << "2. Serve next order\n";
        cout << "3. Show pending orders\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                pizzaQueue.placeOrder();
                break;
            case 2:
                pizzaQueue.serveOrder();
                break;
            case 3:
                pizzaQueue.displayOrders();
                break;
            case 0:
                cout << "Thank you! Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
