#include <iostream>
#include <vector>
#include <chrono> // For measuring time
#include <cstdlib> // For rand()
using namespace std;


// Fills the matrix with random values between 0-9
void generateMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = rand() % 10;
}


// Prints the matrix in a simple format
void displayMatrix(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}


// Accesses elements row by row (faster because of better cache usage)
void rowMajor(const vector<vector<int>>& A,
              const vector<vector<int>>& B,
              vector<vector<int>>& C,
              int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j]; // Row of A, Column of B
            }
            C[i][j] = sum;
        }
    }
}


// Simulates accessing elements column by column (slower due to poor cache usage)
void columnMajor(const vector<vector<int>>& A,
                 const vector<vector<int>>& B,
                 vector<vector<int>>& C,
                 int n) {
    for (int j = 0; j < n; j++) {         // Column first
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j]; // Same math, different access pattern
            }
            C[i][j] = sum;
        }
    }
}


int main() {
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    // Create matrices A, B, and C
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    // Generate random values for A and B
    generateMatrix(A, n);
    generateMatrix(B, n);

    // Display the matrices
    cout << "\nMatrix A:\n";
    displayMatrix(A, n);
    cout << "\nMatrix B:\n";
    displayMatrix(B, n);

    /* ---------- Row-Major Timing ---------- */
    chrono::high_resolution_clock::time_point startRow, endRow;
    startRow = chrono::high_resolution_clock::now(); // Start timer
    rowMajor(A, B, C, n);                            // Multiply
    endRow = chrono::high_resolution_clock::now();   // End timer

    long long rowTime = chrono::duration_cast<chrono::milliseconds>(endRow - startRow).count();
    cout << "\nRow-Major Multiplication Time: " << rowTime << " ms\n";

    /* ---------- Column-Major Timing ---------- */
    chrono::high_resolution_clock::time_point startCol, endCol;
    startCol = chrono::high_resolution_clock::now(); // Start timer
    columnMajor(A, B, C, n);                         // Multiply
    endCol = chrono::high_resolution_clock::now();   // End timer

    long long colTime = chrono::duration_cast<chrono::milliseconds>(endCol - startCol).count();
    cout << "Column-Major Multiplication Time: " << colTime << " ms\n";

    /* ---------- Compare Results ---------- */
    cout << "\nPerformance Difference: ";
    if (colTime > 0) {
        cout << (double)colTime / rowTime << "x slower for Column-Major.\n";
    } else {
        cout << "Too small to measure accurately.\n";
    }

    return 0;
}


