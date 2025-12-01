#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int roll_no;
    int total_marks;
};


void swap_students(student &a, student &b, int &swap_count) {
    student temp = a;
    a = b;
    b = temp;
    swap_count++;
}


void bubble_sort(student arr[], int n, int &swap_count) {
    swap_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                swap_students(arr[j], arr[j + 1], swap_count);
            }
        }
    }
}


int partition(student arr[], int low, int high, int &swap_count) {
    int pivot = arr[high].roll_no;  // taking last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].roll_no < pivot) {
            i++;
            swap_students(arr[i], arr[j], swap_count);
        }
    }
    swap_students(arr[i + 1], arr[high], swap_count);
    return i + 1;
}


void quick_sort(student arr[], int low, int high, int &swap_count) {
    if (low < high) {
        int pi = partition(arr, low, high, swap_count);
        quick_sort(arr, low, pi - 1, swap_count);
        quick_sort(arr, pi + 1, high, swap_count);
    }
}


void print_students(student arr[], int n) {
    cout << "roll_no\tname\tmarks\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].roll_no << "\t" << arr[i].name << "\t" << arr[i].total_marks << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "enter number of students: ";
    cin >> n;

    student students[100];

    cout << "enter student details (name roll_no marks):\n";
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].roll_no >> students[i].total_marks;
    }


    student students_copy[100];
    for (int i = 0; i < n; i++) {
        students_copy[i] = students[i];
    }

    int bubble_swaps, quick_swaps;

    cout << "\noriginal data:\n";
    print_students(students, n);


    bubble_sort(students, n, bubble_swaps);
    cout << "after bubble sort (by roll_no):\n";
    print_students(students, n);
    cout << "number of swaps in bubble sort = " << bubble_swaps << endl << endl;


    quick_sort(students_copy, 0, n - 1, quick_swaps = 0);
    cout << "after quick sort (by roll_no):\n";
    print_students(students_copy, n);
    cout << "number of swaps in quick sort = " << quick_swaps << endl;

    return 0;
}


