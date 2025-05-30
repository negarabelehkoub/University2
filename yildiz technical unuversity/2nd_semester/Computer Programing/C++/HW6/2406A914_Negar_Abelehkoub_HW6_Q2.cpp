#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

using namespace std;

// Let's figure out the sum of each row in our matrix.
void computeRowSums(const vector<vector<int>>& matrix, int numRows, int numCols, vector<int>& sumsPerRow) {
    sumsPerRow.resize(numRows);
    for (int i = 0; i < numRows; ++i) {
        // For each row, we'll add up all the numbers.
        sumsPerRow[i] = accumulate(matrix[i].begin(), matrix[i].end(), 0);
    }
}

// Now, let's calculate the sum of each column. This is a little different.
void computeColSums(const vector<vector<int>>& matrix, int numRows, int numCols, vector<int>& sumsPerColumn) {
    sumsPerColumn.resize(numCols);
    for (int j = 0; j < numCols; ++j) {
        // For each column, we go through each row and add the element.
        sumsPerColumn[j] = 0;
        for (int i = 0; i < numRows; ++i) {
            sumsPerColumn[j] += matrix[i][j];
        }
    }
}

int main() {
    int numRows, numCols;
    cout << "Input:" << endl;
    cin >> numRows >> numCols;

    vector<vector<int>> matrix(numRows, vector<int>(numCols));
    cout << "mat =" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> rowSums;
    computeRowSums(matrix, numRows, numCols, rowSums);

    vector<int> colSums;
    computeColSums(matrix, numRows, numCols, colSums);

    cout << "Output:" << endl;
    cout << "Row sums:" << endl;
    for (int i = 0; i < numRows; ++i) {
        cout << rowSums[i] << (i == numRows - 1 ? "" : " ");
    }
    cout << endl;

    cout << "Column sums:" << endl;
    for (int j = 0; j < numCols; ++j) {
        cout << colSums[j] << (j == numCols - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}