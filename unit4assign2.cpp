#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to count total number of nodes
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to compute height of BST
int height(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Function to create mirror image of BST
void mirror(Node* root) {
    if (root == nullptr)
        return;

    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal (for display)
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert\n2. Count Nodes\n3. Compute Height\n4. Mirror Image\n5. Display (Inorder)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Total number of nodes: " << countNodes(root) << endl;
                break;

            case 3:
                cout << "Height of BST: " << height(root) << endl;
                break;

            case 4:
                mirror(root);
                cout << "Mirror image created successfully!\n";
                break;

            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
