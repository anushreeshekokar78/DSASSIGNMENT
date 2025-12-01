

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[n];
    string names[n];

    // Taking input
    cout << "Enter names and marks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> names[i];
        cout << "Marks: ";
        cin >> marks[i];
    }

    // Bubble Sort in descending order (Topper first)
    for (int pass = 0; pass < n - 1; pass++) {
        cout << "\nPass " << pass + 1 << ": ";
        for (int i = 0; i < n - pass - 1; i++) {
            if (marks[i] < marks[i + 1]) { 
                // Swap marks
                int temp = marks[i];
                marks[i] = marks[i + 1];
                marks[i + 1] = temp;

                // Swap corresponding names
                string tempName = names[i];
                names[i] = names[i + 1];
                names[i + 1] = tempName;
            }
        }

        // Printing array after each pass
        for (int k = 0; k < n; k++) {
            cout << names[k] << "(" << marks[k] << ") ";
        }
    }

    // Final Roll No. Assignment
    cout << "\n\nFinal Roll Number List (Topper = Roll No. 1):\n";
    for (int i = 0; i < n; i++) {
        cout << "Roll No. " << i + 1 << " → " << names[i] << " (" << marks[i] << ")\n";
    }

    return 0;
}