#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int price;
    Node* next;
};

// Stack class using linked list
class StockTracker {
private:
    Node* top;  // pointer to top of stack

public:
    StockTracker() {
        top = NULL;
    }

    // Add a new stock price
    void record(int price) {
        Node* newNode = new Node;
        newNode->price = price;
        newNode->next = top;
        top = newNode;
        cout << "Price " << price << " recorded.\n";
    }

    // Remove and return the most recent stock price
    int remove() {
        if (isEmpty()) {
            cout << "No prices to remove!\n";
            return -1;
        }
        int removedPrice = top->price;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Removed price: " << removedPrice << endl;
        return removedPrice;
    }

    // Return the most recent stock price without removing it
    int latest() {
        if (isEmpty()) {
            cout << "No prices recorded!\n";
            return -1;
        }
        return top->price;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Main program
int main() {
    StockTracker tracker;
    int choice, price;

    do {
        cout << "\n--- Stock Price Tracker ---\n";
        cout << "1. Record Price\n";
        cout << "2. Remove Latest Price\n";
        cout << "3. View Latest Price\n";
        cout << "4. Check if Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter price: ";
                cin >> price;
                tracker.record(price);
                break;

            case 2:
                tracker.remove();
                break;

            case 3:
                price = tracker.latest();
                if (price != -1)
                    cout << "Latest price: " << price << endl;
                break;

            case 4:
                if (tracker.isEmpty())
                    cout << "No prices recorded.\n";
                else
                    cout << "Prices are recorded.\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

      return 0;
}