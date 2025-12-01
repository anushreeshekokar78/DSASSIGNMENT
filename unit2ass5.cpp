#include <iostream>

using namespace std;

// Class for a single bit (node) in our list
class Node {
public:
    int bit;
    Node* next;
    Node* prev;

    // Constructor to initialize a new node
    Node(int val) {
        bit = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Class to manage the entire binary number (the linked list)
class BinaryNumber {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    BinaryNumber() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to free memory
    ~BinaryNumber() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    // Function to create a binary number by reading char by char
    void create() {
        char bitChar;
        cout << "Enter a binary number and press Enter: ";
        
        // Loop that reads one character at a time until it finds the 'Enter' key press ('\n')
        while ((bitChar = cin.get()) != '\n') {
            if (bitChar == '0') {
                append(0);
            } else if (bitChar == '1') {
                append(1);
            }
        }
    }

    // Helper function to add a bit to the end of the list
    void append(int bitValue) {
        Node* newNode = new Node(bitValue);
        if (head == nullptr) { // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    // Helper function to add a bit to the beginning of the list
    void prepend(int bitValue) {
        Node* newNode = new Node(bitValue);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->bit;
            current = current->next;
        }
        cout << endl;
    }

    // Function to calculate and display the 1's complement
    void onesComplement() {
        cout << "1's Complement: ";
        Node* current = head;
        while (current != nullptr) {
            cout << (1 - current->bit); // Flip the bit (0->1, 1->0)
            current = current->next;
        }
        cout << endl;
    }

    // Function to calculate and display the 2's complement
    void twosComplement() {
        BinaryNumber result;
        Node* current = head;

        // 1. Create the 1's complement first
        while (current != nullptr) {
            result.append(1 - current->bit);
            current = current->next;
        }

        // 2. Add 1 to the 1's complement result
        int carry = 1;
        Node* result_tail = result.tail;
        while (result_tail != nullptr) {
            int sum = result_tail->bit + carry;
            result_tail->bit = sum % 2;
            carry = sum / 2;
            if (carry == 0) break; // No more carry, we are done
            result_tail = result_tail->prev;
        }
        
        // If there's still a carry, prepend it
        if (carry == 1) {
            result.prepend(1);
        }
        
        cout << "2's Complement: ";
        result.display();
    }
    
    // Function to add two binary numbers
    void add(BinaryNumber& num1, BinaryNumber& num2) {
        Node* p1 = num1.tail;
        Node* p2 = num2.tail;
        int carry = 0;

        // Clear any previous result in this object
        this->~BinaryNumber();

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int bit1 = (p1 != nullptr) ? p1->bit : 0;
            int bit2 = (p2 != nullptr) ? p2->bit : 0;

            int sum = bit1 + bit2 + carry;
            
            int resultBit = sum % 2;
            carry = sum / 2;
            
            this->prepend(resultBit); // Prepend to build the result in correct order

            if (p1 != nullptr) p1 = p1->prev;
            if (p2 != nullptr) p2 = p2->prev;
        }
    }
};

int main() {
    BinaryNumber num1, num2, result;
    int choice;

    do {
        cout << "\n--- Binary Number Operations Menu ---";
        cout << "\n1. Enter First Binary Number";
        cout << "\n2. Enter Second Binary Number";
        cout << "\n3. Display 1's and 2's Complement of First Number";
        cout << "\n4. Add Two Binary Numbers";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // This is important! It clears the leftover 'Enter' key press from the input buffer
        // so that the create() function can read the next line properly.
        cin.ignore(); 

        switch (choice) {
            case 1:
                num1.~BinaryNumber(); // Clear previous number
                num1.create();
                cout << "First Number stored: ";
                num1.display();
                break;
            case 2:
                num2.~BinaryNumber(); // Clear previous number
                num2.create();
                cout << "Second Number stored: ";
                num2.display();
                break;
            case 3:
                cout << "First Number is: ";
                num1.display();
                num1.onesComplement();
                num1.twosComplement();
                break;
            case 4:
                cout << "First Number:  ";
                num1.display();
                cout << "Second Number: ";
                num2.display();
                result.add(num1, num2);
                cout << "Addition Result: ";
                result.display();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}