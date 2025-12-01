#include <iostream>
using namespace std;

#define MAX 100

// Function to convert matrix into compact form
int convertToCompact(int mat[MAX][MAX], int rows, int cols, int compact[MAX][3]) {
    int k = 1; // first row is reserved for metadata
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = mat[i][j];
                k++;
            }
        }
    }
    // First row stores metadata: rows, cols, non-zero count
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = k - 1;
    return k; // number of entries
}

// Function to display compact form
void displayCompact(int compact[MAX][3], int size) {
    cout << "\nCompact Representation (row col value):\n";
    for (int i = 0; i < size; i++) {
        cout << compact[i][0] << " " 
             << compact[i][1] << " " 
             << compact[i][2] << endl;
    }
}

// Function to compute simple transpose of sparse matrix
void simpleTranspose(int compact[MAX][3], int trans[MAX][3]) {
    int rows = compact[0][0];
    int cols = compact[0][1];
    int nonZero = compact[0][2];

    // Metadata for transpose
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int j = 0; j < cols; j++) {
        for (int i = 1; i <= nonZero; i++) {
            if (compact[i][1] == j) {
                trans[k][0] = compact[i][1];
                trans[k][1] = compact[i][0];
                trans[k][2] = compact[i][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int mat[MAX][MAX];
    int compact[MAX][3], trans[MAX][3];

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    // Convert to compact form
    int size = convertToCompact(mat, rows, cols, compact);

    // Display compact representation
    displayCompact(compact, size);

    // Transpose
    simpleTranspose(compact, trans);

    // Display transpose
    cout << "\nTranspose in Compact Representation:\n";
    displayCompact(trans, size);

    return 0;
}
