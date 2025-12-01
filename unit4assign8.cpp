#include <iostream>
#include <string>
using namespace std;

// Structure for Employee node
struct Employee {
    int emp_id;
    string name;
    float salary;
    Employee* left;
    Employee* right;
};

// Function to create a new node
Employee* createNode(int id, string name, float salary) {
    Employee* newNode = new Employee();
    newNode->emp_id = id;
    newNode->name = name;
    newNode->salary = salary;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new employee record
Employee* insert(Employee* root, int id, string name, float salary) {
    if (root == NULL)
        return createNode(id, name, salary);

    if (id < root->emp_id)
        root->left = insert(root->left, id, name, salary);
    else if (id > root->emp_id)
        root->right = insert(root->right, id, name, salary);
    else
        cout << "Employee with ID " << id << " already exists!\n";

    return root;
}

// Function to search employee by emp_id
Employee* search(Employee* root, int id) {
    if (root == NULL || root->emp_id == id)
        return root;

    if (id < root->emp_id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Function to display employees (sorted by emp_id)
void display(Employee* root) {
    if (root == NULL)
        return;
    display(root->left);
    cout << "EmpID: " << root->emp_id 
         << " | Name: " << root->name 
         << " | Salary: " << root->salary << endl;
    display(root->right);
}

// Main function
int main() {
    Employee* root = NULL;
    int choice, id;
    string name;
    float salary;

    do {
        cout << "\n--- Employee Record System (BST) ---";
        cout << "\n1. Insert Employee Record";
        cout << "\n2. Search Employee by ID";
        cout << "\n3. Display All Employees (Sorted by ID)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin >> name;
                cout << "Enter Salary: ";
                cin >> salary;
                root = insert(root, id, name, salary);
                break;

            case 2:
                cout << "Enter Employee ID to Search: ";
                cin >> id;
                {
                    Employee* result = search(root, id);
                    if (result != NULL)
                        cout << "Record Found -> "
                             << "EmpID: " << result->emp_id
                             << ", Name: " << result->name
                             << ", Salary: " << result->salary << endl;
                    else
                        cout << "Employee with ID " << id << " not found!\n";
                }
                break;

            case 3:
                cout << "\n--- Employee Records (Sorted by ID) ---\n";
                display(root);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
