#include <iostream>
#include <string>
using namespace std;

// Structure for each student node
struct Student {
    string name;
    int marks;
    Student* left;
    Student* right;
};

// Function to create a new node
Student* createNode(string name, int marks) {
    Student* newNode = new Student();
    newNode->name = name;
    newNode->marks = marks;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert student into BST (based on marks)
Student* insert(Student* root, string name, int marks) {
    if (root == NULL)
        return createNode(name, marks);

    if (marks < root->marks)
        root->left = insert(root->left, name, marks);
    else
        root->right = insert(root->right, name, marks);

    return root;
}

// Assign roll numbers (reverse inorder gives highest marks first)
void assignRollNos(Student* root, int &rollNo) {
    if (root == NULL)
        return;

    // Traverse right first (higher marks)
    assignRollNos(root->right, rollNo);

    cout << "Roll No. " << rollNo << " -> " << root->name 
         << " (Marks: " << root->marks << ")\n";
    rollNo++;

    // Then left (lower marks)
    assignRollNos(root->left, rollNo);
}

int main() {
    Student* root = NULL;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name;
    int marks;

    // Insert student data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i+1 << ": ";
        cin >> name;
        cout << "Enter marks of " << name << ": ";
        cin >> marks;
        root = insert(root, name, marks);
    }

    cout << "\n--- Roll Numbers Assigned ---\n";
    int rollNo = 1;
    assignRollNos(root, rollNo);

    return 0;
}
