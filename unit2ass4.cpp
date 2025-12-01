#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = NULL; }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node{val, NULL};
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    // Search element
    bool search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    Node* getHead() { return head; }

    // Display
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Intersection: A ∩ B
LinkedList intersection(LinkedList& A, LinkedList& B) {
    LinkedList result;
    Node* temp = A.getHead();
    while (temp != NULL) {
        if (B.search(temp->data)) {
            result.insert(temp->data);
        }
        temp = temp->next;
    }
    return result;
}

// Symmetric Difference: (A ∪ B) - (A ∩ B)
LinkedList symmetricDifference(LinkedList& A, LinkedList& B) {
    LinkedList result;
    Node* temp = A.getHead();
    while (temp != NULL) {
        if (!B.search(temp->data)) result.insert(temp->data);
        temp = temp->next;
    }
    temp = B.getHead();
    while (temp != NULL) {
        if (!A.search(temp->data)) result.insert(temp->data);
        temp = temp->next;
    }
    return result;
}

// Count neither
int countNeither(LinkedList& A, LinkedList& B, int totalStudents) {
    int count = 0;
    for (int i = 1; i <= totalStudents; i++) {
        if (!A.search(i) && !B.search(i)) {
            count++;
        }
    }
    return count;
}

// ---------------- Main ----------------
int main() {
    LinkedList A, B;

    int total, n1, n2, x;
    cout << "Enter total number of students in class: ";
    cin >> total;

    cout << "Enter number of students who like Cricket: ";
    cin >> n1;
    cout << "Enter roll numbers:\n";
    for (int i = 0; i < n1; i++) {
        cin >> x;
        A.insert(x);
    }

    cout << "Enter number of students who like Football: ";
    cin >> n2;
    cout << "Enter roll numbers:\n";
    for (int i = 0; i < n2; i++) {
        cin >> x;
        B.insert(x);
    }

    cout << "\nSet A (Cricket): ";
    A.display();
    cout << "Set B (Football): ";
    B.display();

    // a) Both Cricket and Football
    LinkedList both = intersection(A, B);
    cout << "\nStudents who like both Cricket and Football: ";
    both.display();

    // b) Either but not both
    LinkedList eitherOnly = symmetricDifference(A, B);
    cout << "Students who like either Cricket or Football but not both: ";
    eitherOnly.display();

    // c) Neither
    int neither = countNeither(A, B, total);
    cout << "Number of students who like neither: " << neither << endl;

    return 0;
}
