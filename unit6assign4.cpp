#include <iostream>
#include <list>
#include <string>
using namespace std;

#define SIZE 10  

// Structure to store student record
struct Student {
    int rollNo;
    string name;
};


class HashTable {
    list<Student> table[SIZE];  // array of linked lists

public:
    
    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

    
    void insert(int rollNo, string name) {
        int index = hashFunction(rollNo);
        Student s = {rollNo, name};
        table[index].push_back(s);
        cout << "Inserted (" << rollNo << ", " << name << ") at index " << index << endl;
    }

    
    void search(int rollNo) {
        int index = hashFunction(rollNo);
        for (auto &s : table[index]) {
            if (s.rollNo == rollNo) {
                cout << "Record found at index " << index << ":\n";
                cout << "Roll No: " << s.rollNo << ", Name: " << s.name << endl;
                return;
            }
        }
        cout << "Record with Roll No " << rollNo << " not found.\n";
    }

    
    void remove(int rollNo) {
        int index = hashFunction(rollNo);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->rollNo == rollNo) {
                cout << "Record (" << it->rollNo << ", " << it->name << ") deleted.\n";
                table[index].erase(it);
                return;
            }
        }
        cout << "Record with Roll No " << rollNo << " not found, cannot delete.\n";
    }

    
    void display() {
        cout << "\nHash Table (Student Records):\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            for (auto &s : table[i])
                cout << "(" << s.rollNo << ", " << s.name << ") -> ";
            cout << "NULL\n";
        }
    }
};


int main() {
    HashTable ht;
    int choice, rollNo;
    string name;

    while (true) {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Insert Record\n2. Search Record\n3. Delete Record\n4. Display All\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cout << "Enter Name: ";
                cin >> name;
                ht.insert(rollNo, name);
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
