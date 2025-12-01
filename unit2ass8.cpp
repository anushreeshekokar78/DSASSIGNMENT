#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Function to insert a node at the end
void insertEnd(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list
void displayList() {
    Node* temp = head;
    cout << "Marks in list: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Bubble Sort on Doubly Linked List
void bubbleSort() {
    if (head == nullptr)
        return;

    bool swapped;
    Node* ptr;
    int pass = 0;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != nullptr) {
            if (ptr->data > ptr->next->data) {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }

        pass++;
        cout << "Pass " << pass << ": ";
        displayList();

    } while (swapped);
}

int main() {
    int n, mark;
    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> mark;
        insertEnd(mark);
    }

    cout << "\nOriginal List:\n";
    displayList();

    cout << "\n--- Bubble Sort Pass Analysis ---\n";
    bubbleSort();

    cout << "\nSorted List:\n";
    displayList();

    return 0;
}


