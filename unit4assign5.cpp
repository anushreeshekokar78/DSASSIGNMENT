#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Structure for tree node
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

// Function to insert nodes level-wise (for creating a binary tree)
Node* insertLevelOrder(Node* root, int value) {
    Node* newNode = createNode(value);
    if (root == nullptr)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        } else
            q.push(temp->left);

        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        } else
            q.push(temp->right);
    }

    return root;
}

// Non-recursive Inorder Traversal
void inorderNonRecursive(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s;
    Node* current = root;

    cout << "Inorder Traversal: ";
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

// Non-recursive Preorder Traversal
void preorderNonRecursive(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> s;
    s.push(root);

    cout << "Preorder Traversal: ";
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        // Push right first so that left is processed first
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
    cout << endl;
}

// Count number of leaf nodes
int countLeafNodes(Node* root) {
    if (root == nullptr)
        return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr && current->right == nullptr)
            count++;

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    return count;
}

// Mirror image of binary tree
void mirror(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        // Swap left and right children
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    cout << "Mirror image of tree created successfully!\n";
}

// Main function
int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Operations (Non-Recursive) ---\n";
        cout << "1. Insert Node\n2. Inorder Traversal\n3. Preorder Traversal\n";
        cout << "4. Count Leaf Nodes\n5. Mirror Image\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertLevelOrder(root, value);
                break;

            case 2:
                inorderNonRecursive(root);
                break;

            case 3:
                preorderNonRecursive(root);
                break;

            case 4:
                cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;
                break;

            case 5:
                mirror(root);
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
