#include <iostream>
using namespace std;


int* create2DArray(int rows, int cols) {
    return new int[rows * cols](); 
}

void set(int* arr, int rows, int cols, int r, int c, int val) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        cout << "Error: Index out of bounds!" << endl;
        exit(1);
    }
    arr[r * cols + c] = val;
}

int get(int* arr, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        cout << "Error: Index out of bounds!" << endl;
        exit(1);
    }
    return arr[r * cols + c];
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int* matrix = create2DArray(rows, cols);

   
    set(matrix, rows, cols, 0, 0, 5);
    set(matrix, rows, cols, 0, 2, 7);
    set(matrix, rows, cols, 1, 1, 3);

 
    cout << "\nMatrix:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << get(matrix, rows, cols, r, c) << " ";
        }
        cout << endl;
    }

    delete[] matrix;

    return 0;
}
