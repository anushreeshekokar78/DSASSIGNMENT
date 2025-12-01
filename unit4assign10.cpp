#include <iostream>
#include <string>
using namespace std;

// Structure for Product node
struct Product {
    string code;         // Unique Product Code
    string name;         // Product Name (used for BST ordering)
    float price;
    int quantity;
    string dateReceived;
    string expiryDate;

    Product* left;
    Product* right;
};

// Function to create a new node
Product* createNode(string code, string name, float price, int quantity,
                    string dateReceived, string expiryDate) {
    Product* newNode = new Product();
    newNode->code = code;
    newNode->name = name;
    newNode->price = price;
    newNode->quantity = quantity;
    newNode->dateReceived = dateReceived;
    newNode->expiryDate = expiryDate;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert product into BST (organized by product name)
Product* insert(Product* root, string code, string name, float price, int quantity,
                string dateReceived, string expiryDate) {
    if (root == NULL)
        return createNode(code, name, price, quantity, dateReceived, expiryDate);

    if (name < root->name)
        root->left = insert(root->left, code, name, price, quantity, dateReceived, expiryDate);
    else if (name > root->name)
        root->right = insert(root->right, code, name, price, quantity, dateReceived, expiryDate);
    else
        cout << "Product with name \"" << name << "\" already exists!\n";

    return root;
}

// Utility: Find minimum node (used in deletion)
Product* findMin(Product* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Utility: Compare dates in "YYYY-MM-DD" format
bool isExpired(string today, string expiry) {
    return expiry < today;  // Lexicographical comparison works for this format
}

// Delete product by Product Code
Product* deleteByCode(Product* root, string code) {
    if (root == NULL)
        return NULL;

    if (root->code == code) {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Product* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Product* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Product* temp = findMin(root->right);
            root->code = temp->code;
            root->name = temp->name;
            root->price = temp->price;
            root->quantity = temp->quantity;
            root->dateReceived = temp->dateReceived;
            root->expiryDate = temp->expiryDate;
            root->right = deleteByCode(root->right, temp->code);
        }
    } 
    else {
        // Search for the node in both subtrees
        root->left = deleteByCode(root->left, code);
        root->right = deleteByCode(root->right, code);
    }

    return root;
}

// Delete all expired products (recursive)
Product* deleteExpired(Product* root, string today) {
    if (root == NULL)
        return NULL;

    root->left = deleteExpired(root->left, today);
    root->right = deleteExpired(root->right, today);

    if (isExpired(today, root->expiryDate)) {
        cout << "Deleting expired product: " << root->name 
             << " (Code: " << root->code << ")\n";
        root = deleteByCode(root, root->code);
    }
    return root;
}

// Display all products (inorder traversal)
void display(Product* root) {
    if (root == NULL)
        return;

    display(root->left);
    cout << "\nProduct Code: " << root->code
         << "\nName: " << root->name
         << "\nPrice: " << root->price
         << "\nQuantity: " << root->quantity
         << "\nDate Received: " << root->dateReceived
         << "\nExpiration Date: " << root->expiryDate
         << "\n-----------------------------";
    display(root->right);
}

// Main function
int main() {
    Product* root = NULL;
    int choice;
    string code, name, dateReceived, expiryDate;
    float price;
    int quantity;
    string today;

    cout << "Enter today's date (YYYY-MM-DD): ";
    cin >> today;

    do {
        cout << "\n\n--- Product Inventory System (with Deletion) ---";
        cout << "\n1. Insert Product";
        cout << "\n2. Display All Products (Inorder)";
        cout << "\n3. Delete Product by Code";
        cout << "\n4. Delete All Expired Products";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product Code: ";
                cin >> code;
                cout << "Enter Product Name: ";
                cin >> name;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                cout << "Enter Date Received (YYYY-MM-DD): ";
                cin >> dateReceived;
                cout << "Enter Expiration Date (YYYY-MM-DD): ";
                cin >> expiryDate;
                root = insert(root, code, name, price, quantity, dateReceived, expiryDate);
                break;

            case 2:
                if (root == NULL)
                    cout << "No products in inventory.\n";
                else {
                    cout << "\n--- Product Inventory (Sorted by Name) ---\n";
                    display(root);
                }
                break;

            case 3:
                cout << "Enter Product Code to delete: ";
                cin >> code;
                root = deleteByCode(root, code);
                cout << "If the code existed, it has been deleted.\n";
                break;

            case 4:
                if (root == NULL)
                    cout << "Inventory empty.\n";
                else {
                    cout << "\nDeleting expired products...\n";
                    root = deleteExpired(root, today);
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
