#include <iostream>
#include <string>
using namespace std;

// Structure for a Product node
struct Product {
    string code;
    string name;
    float price;
    int quantity;
    string dateReceived;
    string expiryDate;

    Product* left;
    Product* right;
};

// Function to create a new product node
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

// Insert product (organized by product name)
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

// Display all products (Inorder traversal -> Sorted by name)
void displayInorder(Product* root) {
    if (root == NULL)
        return;

    displayInorder(root->left);
    cout << "\nProduct Code: " << root->code
         << "\nName: " << root->name
         << "\nPrice: " << root->price
         << "\nQuantity: " << root->quantity
         << "\nDate Received: " << root->dateReceived
         << "\nExpiration Date: " << root->expiryDate
         << "\n-----------------------------";
    displayInorder(root->right);
}

// Check if a product is expired (simple string comparison for demo)
bool isExpired(string today, string expiryDate) {
    return expiryDate < today;  // Compare YYYY-MM-DD format strings
}

// Display expired items (Preorder traversal)
void listExpired(Product* root, string today) {
    if (root == NULL)
        return;

    if (isExpired(today, root->expiryDate)) {
        cout << "\n[EXPIRED] Product: " << root->name
             << " | Code: " << root->code
             << " | Expiry: " << root->expiryDate;
    }

    listExpired(root->left, today);
    listExpired(root->right, today);
}

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
        cout << "\n\n--- Product Inventory Management System ---";
        cout << "\n1. Insert New Product";
        cout << "\n2. Display All Products (Sorted by Name)";
        cout << "\n3. List Expired Products (Preorder)";
        cout << "\n4. Exit";
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
                    cout << "\nInventory is empty!";
                else {
                    cout << "\n--- Product Inventory (Sorted by Name) ---\n";
                    displayInorder(root);
                }
                break;

            case 3:
                if (root == NULL)
                    cout << "\nNo products to check!";
                else {
                    cout << "\n--- Expired Products as of " << today << " ---";
                    listExpired(root, today);
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
