#include <iostream>
#include <string>
using namespace std;

#define SIZE 10   


struct Student {
    int rollNo;
    string name;
    string branch;
    string company;
    bool placed;
    bool occupied;

    Student() {
        rollNo = -1;
        name = branch = company = "";
        placed = false;
        occupied = false;
    }
};


class PlacementPortal {
    Student table[SIZE];

public:
    
    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

    // Insert student record
    void insertStudent(int rollNo, string name, string branch) {
        int index = hashFunction(rollNo);
        int start = index;

        while (table[index].occupied) {
            index = (index + 1) % SIZE; // linear probing
            if (index == start) {
                cout << "Table is full! Cannot insert.\n";
                return;
            }
        }

        table[index].rollNo = rollNo;
        table[index].name = name;
        table[index].branch = branch;
        table[index].placed = false;
        table[index].occupied = true;

        cout << "Student (" << rollNo << ", " << name << ") inserted at index " << index << endl;
    }

    // Update placement info
    void updatePlacement(int rollNo, string company) {
        int index = hashFunction(rollNo);
        int start = index;

        while (table[index].occupied) {
            if (table[index].rollNo == rollNo) {
                table[index].placed = true;
                table[index].company = company;
                cout << "Placement updated for " << table[index].name << " → " << company << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        cout << "Student with Roll No " << rollNo << " not found!\n";
    }

    // Search student record
    void searchStudent(int rollNo) {
        int index = hashFunction(rollNo);
        int start = index;

        while (table[index].occupied) {
            if (table[index].rollNo == rollNo) {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << table[index].rollNo << endl;
                cout << "Name: " << table[index].name << endl;
                cout << "Branch: " << table[index].branch << endl;
                cout << "Placed: " << (table[index].placed ? "Yes" : "No") << endl;
                if (table[index].placed)
                    cout << "Company: " << table[index].company << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        cout << "Student with Roll No " << rollNo << " not found!\n";
    }

    // Delete a student record
    void deleteStudent(int rollNo) {
        int index = hashFunction(rollNo);
        int start = index;

        while (table[index].occupied) {
            if (table[index].rollNo == rollNo) {
                table[index].occupied = false;
                cout << "Record of student with Roll No " << rollNo << " deleted.\n";
                return;
            }
            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        cout << "Record not found! Cannot delete.\n";
    }

    // Display all student records
    void displayAll() {
        cout << "\nPlacement Portal Records:\n";
        cout << "Index\tRoll\tName\tBranch\tPlaced\tCompany\n";
        cout << "---------------------------------------------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].occupied) {
                cout << i << "\t" << table[i].rollNo << "\t" << table[i].name << "\t"
                     << table[i].branch << "\t" << (table[i].placed ? "Yes" : "No")
                     << "\t" << table[i].company << endl;
            } else {
                cout << i << "\t-\t-\t-\t-\t-" << endl;
            }
        }
    }
};

// Main function
int main() {
    PlacementPortal portal;
    int choice, roll;
    string name, branch, company;

    while (true) {
        cout << "\n--- Smart College Placement Portal ---\n";
        cout << "1. Insert Student Record\n2. Update Placement\n3. Search Student\n4. Delete Record\n5. Display All\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> roll;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Branch: ";
                cin >> branch;
                portal.insertStudent(roll, name, branch);
                break;

            case 2:
                cout << "Enter Roll No: ";
                cin >> roll;
                cout << "Enter Company Name: ";
                cin >> company;
                portal.updatePlacement(roll, company);
                break;

            case 3:
                cout << "Enter Roll No to search: ";
                cin >> roll;
                portal.searchStudent(roll);
                break;

            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> roll;
                portal.deleteStudent(roll);
                break;

            case 5:
                portal.displayAll();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
