#include <iostream>
#include <string>
using namespace std;

// Structure to store employee details
struct Employee {
    string name;
    double height;
    double weight;

    // Function to calculate average of height and weight
    double average() {
        return (height + weight) / 2.0;
    }
};


// New display function (manual alignment)
void display(Employee employees[], int n) {
    cout << "\n---------------------------------------------\n";
    cout << "Name\t\tHeight\tWeight\tAverage\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << employees[i].name << "\t\t"
             << employees[i].height << "\t"
             << employees[i].weight << "\t"
             << employees[i].average() << "\n";
    }
    cout << "---------------------------------------------\n\n";
}


/* ======================= SELECTION SORT ======================= */
/*
    Logic:
    - Selection Sort finds the smallest element in the unsorted part of the array
      and swaps it with the first element of the unsorted part.
    - Repeats this until the array is sorted.
    - Time Complexity: O(n^2)
*/
void selectionSort(Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // assume current index is the smallest
        for (int j = i + 1; j < n; j++) {
            // Compare averages to find smaller element
            if (employees[j].average() < employees[minIndex].average()) {
                minIndex = j;
            }
        }
        // Swap smallest element with the first unsorted element
        swap(employees[i], employees[minIndex]);
    }
}

/* ======================= MERGE SORT ======================= */
/*
    Logic:
    - Merge Sort is a divide-and-conquer algorithm.
    - Divide the array into two halves.
    - Recursively sort both halves.
    - Merge the two sorted halves together.
    - Time Complexity: O(n log n)
*/

// Function to merge two halves of an array
void merge(Employee employees[], int left, int mid, int right) {
    int n1 = mid - left + 1; // size of left subarray
    int n2 = right - mid;    // size of right subarray

    // Create temporary arrays
    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) L[i] = employees[left + i];
    for (int j = 0; j < n2; j++) R[j] = employees[mid + 1 + j];

    // Merge temporary arrays back into main array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Compare averages of L and R
        if (L[i].average() <= R[j].average()) {
            employees[k++] = L[i++];
        } else {
            employees[k++] = R[j++];
        }
    }

    // Copy remaining elements from L (if any)
    while (i < n1) employees[k++] = L[i++];
    // Copy remaining elements from R (if any)
    while (j < n2) employees[k++] = R[j++];

    // Free memory
    delete[] L;
    delete[] R;
}

// Recursive function to apply merge sort
void mergeSort(Employee employees[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find mid index

        // Sort first half
        mergeSort(employees, left, mid);
        // Sort second half
        mergeSort(employees, mid + 1, right);
        // Merge the sorted halves
        merge(employees, left, mid, right);
    }
}

/* ======================= MAIN FUNCTION ======================= */
int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee employees[100]; // Array to hold employees (max 100)
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Height: ";
        cin >> employees[i].height;
        cout << "Weight: ";
        cin >> employees[i].weight;
    }

    int choice;
    do {
        // Menu options
        cout << "\n===== Employee Sorting Menu =====\n";
        cout << "1. Display Employees\n";
        cout << "2. Sort using Selection Sort\n";
        cout << "3. Sort using Merge Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Show all employees
            display(employees, n);
            break;
        case 2:
            // Sort employees using Selection Sort
            selectionSort(employees, n);
            cout << "\nEmployees sorted using Selection Sort:\n";
            display(employees, n);
            break;
        case 3:
            // Sort employees using Merge Sort
            mergeSort(employees, 0, n - 1);
            cout << "\nEmployees sorted using Merge Sort:\n";
            display(employees, n);
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}


/*=== Time Complexity Analysis ===
Selection Sort: O(n^2)
Merge Sort: O(n log n)
Conclusion: Merge Sort is faster for larger datasets.*/