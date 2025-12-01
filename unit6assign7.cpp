#include <iostream>
#include <string>
using namespace std;

#define SIZE 10  // hash table size


struct Faculty {
    int id;
    string name;
    string dept;
    int chain;     // index of next element in chain (-1 = none)
    bool occupied; // true if slot used

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

    
    void insert(int id, string name, string dept) {
        int index = hashFunction(id);

        // Case 1: Empty slot — insert directly
        if (!table[index].occupied) {
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;
            cout << "Inserted (" << id << ", " << name << ", " << dept << ") at index " << index << endl;
            return;
        }

        // Case 2: Collision occurs
        int home = hashFunction(table[index].id);

        // Check if existing record belongs here
        if (home != index) {
            // Replace the existing record
            Faculty temp = table[index];
            table[index].id = id;
            table[index].name = name;
            table[index].dept = dept;
            table[index].occupied = true;

            cout << "Replaced record at index " << index
                 << " (moved old record " << temp.id << " to another slot)" << endl;

            // Find new slot for displaced record
            int newIndex = (index + 1) % SIZE;
            while (table[newIndex].occupied)
                newIndex = (newIndex + 1) % SIZE;

            table[newIndex] = temp;
            table[newIndex].occupied = true;

            // Update chain links
            int prev = home;
            while (table[prev].chain != index)
                prev = table[prev].chain;
            table[prev].chain = newIndex;

            if (temp.chain != -1)
                table[newIndex].chain = temp.chain;

            return;
        }

        // Case 3: Belongs here, so find next free slot
        int newIndex = (index + 1) % SIZE;
        while (table[newIndex].occupied)
            newIndex = (newIndex + 1) % SIZE;

        // Insert new record in next slot
        table[newIndex].id = id;
        table[newIndex].name = name;
        table[newIndex].dept = dept;
        table[newIndex].occupied = true;

        // Add to chain
        int temp = index;
        while (table[temp].chain != -1)
            temp = table[temp].chain;
        table[temp].chain = newIndex;

        cout << "Inserted (" << id << ", " << name << ", " << dept << ") at index "
             << newIndex << " (chained with " << temp << ")" << endl;
    }

    // Search faculty record
    void search(int id) {
        int index = hashFunction(id);
        while (index != -1) {
            if (table[index].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[index].id << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Department: " << table[index].dept << endl;
                return;
            }
            index = table[index].chain;
        }
        cout << "Faculty with ID " << id << " not found.\n";
    }

    // Display hash table
    void display() {
        cout << "\nHash Table (Faculty Records):\n";
        cout << "Index\tID\tName\tDepartment\tChain\n";
        cout << "---------------------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].id << "\t" << table[i].name
                     << "\t" << table[i].dept << "\t\t" << table[i].chain << endl;
            else
                cout << i << "\t-\t-\t-\t\t" << table[i].chain << endl;
        }
    }
};

// Main Program
int main() {
    HashTable ht;
    int choice, id;
    string name, dept;

    while (true) {
        cout << "\n--- Faculty Database (Linear Probing with Chaining WITH Replacement) ---\n";
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
