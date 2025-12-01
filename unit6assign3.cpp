#include <iostream>
#include <list>
using namespace std;

#define SIZE 10  
class HashTable {
    list<int> table[SIZE];  

public:
   
    int hashFunction(int key) {
        return key % SIZE; 
    }

    
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted " << key << " at index " << index << endl;
    }

    
    void search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found.\n";
    }

    
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Key " << key << " deleted from index " << index << endl;
                return;
            }
        }
        cout << "Key " << key << " not found, cannot delete.\n";
    }

    
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            for (int val : table[i])
                cout << val << " -> ";
            cout << "NULL\n";
        }
    }
};


int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\n--- Hash Table (Separate Chaining) ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
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
