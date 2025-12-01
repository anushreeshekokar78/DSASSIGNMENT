#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Create a new node
Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert nodes (simple binary tree, not BST)
Node* insertNode(Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    cout << "Insert " << value << " to left (L) or right (R) of " << root->data << "? ";
    char ch;
    cin >> ch;

    if (ch == 'L' || ch == 'l')
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

// Non-recursive inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Non-recursive preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

// Count leaf nodes (non-recursive)
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    stack<Node*> st;
    st.push(root);
    int count = 0;

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        if (curr->left == NULL && curr->right == NULL)
            count++;

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }

    return count;
}

// Mirror the tree (non-recursive)
void mirror(Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        // swap left and right
        Node* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        if (curr->left)
            st.push(curr->left);
        if (curr->right)
            st.push(curr->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        root = insertNode(root, val);
    }

    while (true) {
        cout << "\n--- Binary Tree Operations ---\n";
        cout << "1. Inorder Traversal\n2. Preorder Traversal\n3. Count Leaf Nodes\n4. Mirror Image\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;
                break;
            case 4:
                mirror(root);
                cout << "Tree has been mirrored!\n";
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
