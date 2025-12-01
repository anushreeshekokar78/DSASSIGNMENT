#include <iostream>
using namespace std;

const int MAX = 50;
int square[MAX][MAX];

// ------------------- ODD ORDER MAGIC SQUARE -------------------
// Generates a magic square when n is odd using the Siamese method
void generateOdd(int n) {
    int i = 0, j = n / 2;
    for (int num = 1; num <= n * n; num++) {
        square[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (square[newi][newj]) {
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }
}

// ------------------- DOUBLY EVEN MAGIC SQUARE -------------------
// Generates a magic square when n is divisible by 4 (doubly even)
void generateDoublyEven(int n) {
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = num++;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                square[i][j] = n * n + 1 - square[i][j];
}

// ------------------- SINGLY EVEN MAGIC SQUARE -------------------
// Generates a magic square when n is even but not divisible by 4 (singly even)
void generateSinglyEven(int n) {
    int half = n / 2;  // size of the smaller odd-order square
    
    // Step 1: Generate smaller odd-order square
    generateOdd(half);

    // Step 2: Fill 4 quadrants with appropriate offsets
    int add[4] = {0, 2 * half * half, 3 * half * half, half * half};
    for (int r = 0; r < half; r++) {
        for (int c = 0; c < half; c++) {
            int val = square[r][c];
            square[r][c] = val + add[0];               // top-left
            square[r][c + half] = val + add[1];       // top-right
            square[r + half][c] = val + add[2];       // bottom-left
            square[r + half][c + half] = val + add[3];// bottom-right
        }
    }

    // Step 3: Swap specific columns between left and right quadrants
    int k = (n - 2) / 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i < half) swap(square[i][j], square[i + half][j]);
        }
        for (int j = n - k + 1; j < n; j++) {
            if (i < half) swap(square[i][j], square[i + half][j]);
        }
    }
}

// ------------------- PRINT MAGIC SQUARE -------------------
// Prints the square without formatting
void printSquare(int n) {
    cout << "Magic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << square[i][j] << " ";
        cout << endl;
    }
}

// ------------------- VERIFY MAGIC SQUARE -------------------
// Verifies if all rows, columns, and diagonals sum to magic constant
void verifyMagicSquare(int n) {
    int magicSum = n * (n * n + 1) / 2;
    bool isMagic = true;

    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) isMagic = false;
    }

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += square[i][i];
        diag2 += square[i][n - i - 1];
    }
    if (diag1 != magicSum || diag2 != magicSum) isMagic = false;

    cout << "\nMagic Sum should be: " << magicSum << endl;
    if (isMagic)
        cout << "Verification: This is a valid Magic Square!\n";
    else
        cout << "Verification: This is NOT a valid Magic Square.\n";
}

// ------------------- MAIN FUNCTION -------------------
int main() {
    int n;
    cout << "Enter order of magic square (n >= 3): ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3.\n";
        return 0;
    }

    if (n % 2 == 1)
        generateOdd(n);
    else if (n % 4 == 0)
        generateDoublyEven(n);
    else
        generateSinglyEven(n);

    printSquare(n);
    verifyMagicSquare(n);

    return 0;
}
