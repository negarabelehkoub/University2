#include <iostream>
#include <cassert>
using namespace std;

// Calculates factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Calculates combination (n choose k)
int combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int rows;
    cout << "Enter the number of rows to display (between 2 and 5): ";
    cin >> rows;
    assert(rows >= 2 && rows <= 5);

    for (int i = 0; i < rows; i++) {
        // Printing spaces for formatting
        for (int s = 0; s < rows - i - 1; s++) {
            cout << "  ";
        }

        for (int j = 0; j <= i; j++) {
            int value = combination(i, j);
            if (value % 2 == 1) {
                cout << value << "   ";
            } else {
                cout << "    "; // blank space for even numbers
            }
        }
        cout << endl;
    }

    return 0;
}

