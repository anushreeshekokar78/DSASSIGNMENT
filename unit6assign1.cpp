#include <iostream>
using namespace std;

#define SIZE 10  

class HashTable {
    int hashTable[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            hashTable[i] = -1;  
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    
    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index; 

        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash table is full!\n";
                return;
            }
        }
        hashTable[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    
    void search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex)
                break;
        }
        cout << "Key " << key << " not found.\n";
    }

    
    void remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                hashTable[index] = -1;
                cout << "Key " << key << " deleted from index " << index << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == startIndex)
                break;
        }
        cout << "Key " << key << " not found, cannot delete.\n";
    }

    
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (hashTable[i] != -1)
                cout << hashTable[i];
            cout << endl;
        }
    }
};


int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\n--- Hash Table (Linear Probing) ---\n";
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
