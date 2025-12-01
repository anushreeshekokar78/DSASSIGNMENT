#include <iostream>
using namespace std;

// Structure for a BST node
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key in BST
Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate keys not allowed!\n";

    return root;
}

// Function to find the smallest value node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a key from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to search for a key in BST
bool find(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    else if (key < root->key)
        return find(root->left, key);
    else
        return find(root->right, key);
}

// Function to display the BST (Inorder Traversal)
void show(Node* root) {
    if (root == NULL)
        return;
    show(root->left);
    cout << root->key << " ";
    show(root->right);
}

// Main function with menu
int main() {
    Node* root = NULL;
    int choice, key;

    do {
        cout << "\n--- BST Operations Menu ---";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Find";
        cout << "\n4. Show (Inorder Traversal)";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;

            case 3:
                cout << "Enter key to find: ";
                cin >> key;
                if (find(root, key))
                    cout << "Key found in BST.\n";
                else
                    cout << "Key not found.\n";
                break;

            case 4:
                cout << "BST (Inorder): ";
                show(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
