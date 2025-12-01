#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int choice;

    cout << "Enter first string: ";
    getline(cin, str1);

    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Calculate Length\n";
        cout << "2. Copy String\n";
        cout << "3. Reverse String\n";
        cout << "4. Concatenate Strings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // clear input buffer

        switch (choice) {
            case 1: {
                cout << "Length = " << str1.length() << endl;
                break;
            }

            case 2: {
                string copy = str1;
                cout << "Copied String = " << copy << endl;
                break;
            }

            case 3: {
                string rev = string(str1.rbegin(), str1.rend());
                cout << "Reversed String = " << rev << endl;
                break;
            }

            case 4: {
                cout << "Enter second string: ";
                getline(cin, str2);
                cout << "Concatenated = " << (str1 + str2) << endl;
                break;
            }

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
