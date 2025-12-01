#include <iostream>

using namespace std;

// A constant defining the maximum number of non-zero terms the program can handle.
#define MAX_TERMS 100

// Using a class for the triplet term as requested.
class Term {
public:
    int row;
    int col;
    int value;
};

// A class to represent and operate on a sparse matrix using a fixed-size array.
class SparseMatrix {
private:
    int numRows;
    int numCols;
    int numTerms; // The actual number of non-zero terms stored.
    Term terms[MAX_TERMS]; // A fixed-size array to store the terms.

public:
    // Default constructor to initialize the matrix as empty.
    SparseMatrix() {
        numRows = 0;
        numCols = 0;
        numTerms = 0;
    }

    // Method to set the matrix dimensions.
    void setDimensions(int r, int c, int t) {
        numRows = r;
        numCols = c;
        numTerms = t;
    }

    // Method to read the non-zero elements from the user.
    void read() {
        if (numTerms > MAX_TERMS) {
            cout << "Error: Number of terms exceeds the maximum limit of " << MAX_TERMS << endl;
            numTerms = 0; // Invalidate the matrix
            return;
        }
        cout << "Enter the " << numTerms << " non-zero elements (row col value):\n";
        for (int i = 0; i < numTerms; i++) {
            cin >> terms[i].row >> terms[i].col >> terms[i].value;
        }
    }

    // Method to display the matrix in triplet form.
    void display() {
        if (numTerms == 0) {
            cout << "\nMatrix is empty or invalid.\n";
            return;
        }
        cout << "\nRow\tColumn\tValue\n";
        cout << "---------------------\n";
        for (int i = 0; i < numTerms; i++) {
            cout << terms[i].row << "\t" << terms[i].col << "\t" << terms[i].value << "\n";
        }
    }

    // Method to compute the fast transpose.
    SparseMatrix fastTranspose() {
        SparseMatrix transpose;
        transpose.setDimensions(numCols, numRows, numTerms);
        
        if (numTerms == 0 || numCols > MAX_TERMS) {
            return transpose; // Return an empty transpose if original is empty or too large.
        }

        int col_count[MAX_TERMS] = {0}; // Helper array for counts, initialized to zero.
        int start_pos[MAX_TERMS] = {0}; // Helper array for positions, initialized to zero.

        // Step 1: Count non-zero elements in each column.
        for (int i = 0; i < numTerms; i++) {
            col_count[terms[i].col]++;
        }

        // Step 2: Determine starting position for each row in the transpose.
        start_pos[0] = 0;
        for (int i = 1; i < numCols; i++) {
            start_pos[i] = start_pos[i - 1] + col_count[i - 1];
        }

        // Step 3: Place each element into its correct position in the transpose.
        for (int i = 0; i < numTerms; i++) {
            int pos = start_pos[terms[i].col];
            transpose.terms[pos].row = terms[i].col;
            transpose.terms[pos].col = terms[i].row;
            transpose.terms[pos].value = terms[i].value;
            start_pos[terms[i].col]++;
        }

        return transpose;
    }
};

int main() {
    int rows, cols, nonZero;
    cout << "Enter the number of rows, columns, and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    if (nonZero > MAX_TERMS) {
        cout << "Error: Cannot handle more than " << MAX_TERMS << " non-zero elements." << endl;
        return 1;
    }

    SparseMatrix originalMatrix;
    originalMatrix.setDimensions(rows, cols, nonZero);
    
    SparseMatrix transposeMatrix;

    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Sparse Matrix Menu ---";
        cout << "\n1. Enter Sparse Matrix (Triplet Form)";
        cout << "\n2. Display Original Matrix";
        cout << "\n3. Compute Fast Transpose";
        cout << "\n4. Display Transposed Matrix";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                originalMatrix.read();
                break;
            case 2:
                cout << "\n--- Original Sparse Matrix ---";
                originalMatrix.display();
                break;
            case 3:
                transposeMatrix = originalMatrix.fastTranspose();
                cout << "\nFast transpose computed successfully!\n";
                break;
            case 4:
                cout << "\n--- Transposed Sparse Matrix ---";
                transposeMatrix.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}