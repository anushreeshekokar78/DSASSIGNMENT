#include <iostream>
#include <string>
using namespace std;

#define SIZE 10  


struct Faculty {
    int id;          
    string name;     
    string dept;    
    bool occupied;   

    Faculty() {
        id = -1;
        name = "";
        dept = "";
        occupied = false;
    }
};


class HashTable {
    Faculty table[SIZE];

public:
    
    int hashFunction(int id) {
        return id % SIZE;   
    }

   
    void insert(int id, string name, string dept) {
        int index = hashFunction(id);
        int start = index;

        // Linear probing for collision resolution
        while (table[index].occupied) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "Hash table is full!\n";
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;
        table[index].occupied = true;

        cout << "Inserted Faculty (" << id << ", " << name << ", " << dept << ") at index " << index << endl;
    }

    // Search Faculty Record
    void search(int id) {
        int index = hashFunction(id);
        int start = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                cout << "\nFaculty found at index " << index << ":\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Department: " << table[index].dept << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                break;
        }
        cout << "Faculty with ID " << id << " not found.\n";
    }

    // Display All Records
    void display() {
        cout << "\nHash Table (Faculty Records):\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (table[i].occupied)
                cout << "(" << table[i].id << ", " << table[i].name << ", " << table[i].dept << ")";
            else
                cout << "Empty";
            cout << endl;
        }
    }
};

// Main function
int main() {
    HashTable ht;
    int choice, id;
    string name, dept;

    while (true) {
        cout << "\n--- Faculty Database (Linear Probing) ---\n";
        cout << "1. Insert Record\n2. Search Record\n3. Display All\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Faculty ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Department: ";
                cin >> dept;
                ht.insert(id, name, dept);
                break;

            case 2:
                cout << "Enter Faculty ID to search: ";
                cin >> id;
                ht.search(id);
                break;

            case 3:
                ht.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
