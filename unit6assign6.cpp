#include <iostream>
#include <string>
using namespace std;

#define SIZE 10  


struct Faculty {
    int id;          
    string name;     
    string dept;     
    int chain;       
    bool occupied;  

    Faculty() {
        id = -1;
        name = "";
        dept = "";
        chain = -1;
        occupied = false;
    }
};


class HashTable {
    Faculty table[SIZE];

public:
    
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Insert record using linear probing with chaining (without replacement)
    void insert(int id, string name, string dept) {
        int index = hashFunction(id);
        int start = index;

        // Case 1: Direct slot empty
        if (!table[index].occupied) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;
            cout << "Inserted (" << id << ", " << name << ", " << dept << ") at index " << index << endl;
            return;
        }

        // Case 2: Slot occupied — handle collision
        int newIndex = (index + 1) % SIZE;
        while (table[newIndex].occupied && newIndex != start)
            newIndex = (newIndex + 1) % SIZE;

        if (newIndex == start) {
            cout << "Hash table is full!\n";
            return;
        }

        // Insert new record in next free slot
        table[newIndex].id = id;
        table[newIndex].name = name;
        table[newIndex].dept = dept;
        table[newIndex].occupied = true;

        // Now link it in the chain (without replacement)
        int temp = index;
        while (table[temp].chain != -1)
            temp = table[temp].chain;
        table[temp].chain = newIndex;

        cout << "Inserted (" << id << ", " << name << ", " << dept << ") at index " << newIndex
             << " (chained with index " << temp << ")" << endl;
    }

    // Search for a faculty record
    void search(int id) {
        int index = hashFunction(id);

        while (index != -1) {
            if (table[index].id == id) {
                cout << "\nFaculty found:\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Department: " << table[index].dept << endl;
                return;
            }
            index = table[index].chain;
        }
        cout << "Faculty with ID " << id << " not found.\n";
    }

    // Display entire hash table
    void display() {
        cout << "\nHash Table (Faculty Records):\n";
        cout << "Index\tID\tName\tDepartment\tChain\n";
        cout << "-----------------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].id << "\t" << table[i].name
                     << "\t" << table[i].dept << "\t\t" << table[i].chain << endl;
            else
                cout << i << "\t" << "-\t-\t-\t\t" << table[i].chain << endl;
        }
    }
};

// Main program
int main() {
    HashTable ht;
    int choice, id;
    string name, dept;

    while (true) {
        cout << "\n--- Faculty Database (Linear Probing with Chaining Without Replacement) ---\n";
        cout << "1. Insert Record\n2. Search Record\n3. Display Table\n4. Exit\n";
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
