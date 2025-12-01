#include <iostream>
#include <string>
using namespace std;

#define SIZE 10  


struct Student {
    int rollNo;
    string name;
    string course;
    bool occupied;   // true if record present
    bool deleted;    // true if record was deleted (for reuse in probing)

    Student() {
        rollNo = -1;
        name = "";
        course = "";
        occupied = false;
        deleted = false;
    }
};


class HashTable {
    Student table[SIZE];

public:
    
    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

    // Insert new student record
    void insert(int rollNo, string name, string course) {
        int index = hashFunction(rollNo);
        int startIndex = index;

        do {
            // Empty or deleted slot found
            if (!table[index].occupied || table[index].deleted) {
                table[index].rollNo = rollNo;
                table[index].name = name;
                table[index].course = course;
                table[index].occupied = true;
                table[index].deleted = false;
                cout << "Inserted (" << rollNo << ", " << name << ", " << course << ") at index " << index << endl;
                return;
            }

            // Move to next index (Linear Probing)
            index = (index + 1) % SIZE;
        } while (index != startIndex);

        cout << "Hash table is full! Cannot insert.\n";
    }

    // Search for a student record
    void search(int rollNo) {
        int index = hashFunction(rollNo);
        int startIndex = index;

        do {
            if (table[index].occupied && !table[index].deleted && table[index].rollNo == rollNo) {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << table[index].rollNo << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Course: " << table[index].course << endl;
                return;
            }

            index = (index + 1) % SIZE;
        } while (index != startIndex);

        cout << "Student with Roll No " << rollNo << " not found.\n";
    }

    // Delete a student record
    void remove(int rollNo) {
        int index = hashFunction(rollNo);
        int startIndex = index;

        do {
            if (table[index].occupied && !table[index].deleted && table[index].rollNo == rollNo) {
                table[index].deleted = true;  // mark as deleted
                table[index].occupied = false;
                cout << "Record with Roll No " << rollNo << " deleted from index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
        } while (index != startIndex);

        cout << "Record not found! Cannot delete.\n";
    }

    // Display the hash table
    void display() {
        cout << "\nHash Table (Student Records):\n";
        cout << "Index\tRollNo\tName\tCourse\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].rollNo << "\t" << table[i].name << "\t" << table[i].course << endl;
            else
                cout << i << "\t-\t-\t-" << endl;
        }
    }
};

// Main Program
int main() {
    HashTable ht;
    int choice, rollNo;
    string name, course;

    while (true) {
        cout << "\n--- Student Database using Hash Table ---\n";
        cout << "1. Insert Record\n2. Search Record\n3. Delete Record\n4. Display Table\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Course: ";
                cin >> course;
                ht.insert(rollNo, name, course);
                break;

            case 2:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                ht.search(rollNo);
                break;

            case 3:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                ht.remove(rollNo);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
