#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define SIZE 10  

struct Employee {
    int id;
    string name;
    string dept;
    bool occupied;

    Employee() {
        id = -1;
        name = "";
        dept = "";
        occupied = false;
    }
};


class HashTable {
    Employee table[SIZE];

public:
    // Mid-square hash function
    int hashFunction(int key) {
        long long square = (long long)key * key; // Step 1: Square the key
        int digits = (int)log10(SIZE) + 1;       // number of digits in SIZE
        int midDigits = (int)pow(10, digits / 2); // extract middle part
        int mid = (square / midDigits) % SIZE;   // Step 2: extract middle and mod SIZE
        return mid;
    }

    // Insert record using linear probing
    void insert(int id, string name, string dept) {
        int index = hashFunction(id);
        int startIndex = index;

        while (table[index].occupied) {  // collision → linear probe
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }

        table[index].id = id;
        table[index].name = name;
        table[index].dept = dept;
        table[index].occupied = true;

        cout << "Inserted (" << id << ", " << name << ", " << dept 
             << ") at index " << index << endl;
    }

    // Search record
    void search(int id) {
        int index = hashFunction(id);
        int startIndex = index;

        while (table[index].occupied) {
            if (table[index].id == id) {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Department: " << table[index].dept << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex)
                break;
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // Display hash table
    void display() {
        cout << "\nHash Table (Employee Records):\n";
        cout << "Index\tID\tName\tDepartment\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].id << "\t" 
                     << table[i].name << "\t" << table[i].dept << endl;
            else
                cout << i << "\t-\t-\t-" << endl;
        }
    }
};

// Main Program
int main() {
    HashTable ht;
    int choice, id;
    string name, dept;

    while (true) {
        cout << "\n--- Employee Database (Mid-Square Hash + Linear Probing) ---\n";
        cout << "1. Insert Record\n2. Search Record\n3. Display Table\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Department: ";
                cin >> dept;
                ht.insert(id, name, dept);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
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
