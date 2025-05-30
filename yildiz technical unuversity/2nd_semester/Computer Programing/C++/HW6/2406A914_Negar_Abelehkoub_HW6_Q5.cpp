#include <iostream>
#include <vector>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// Let's start by reading in the Connect Four board. We'll first get the size,
// and then the actual layout of the game.
void readBoard(char board[MAX_ROWS][MAX_COLS], int& numRows, int& numCols) {
    cin >> numRows >> numCols;
    cin.ignore(); // This is just to clean up after reading the numbers.

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> board[i][j];
            // We need to make sure the input is just 'R' (Red), 'Y' (Yellow), or '.' (empty).
            if (board[i][j] != 'R' && board[i][j] != 'Y' && board[i][j] != '.') {
                cerr << "Whoops! Looks like there's an invalid piece on the board." << endl;
                exit(1);
            }
        }
    }
}

// Now, let's show the board we just read. It's good to see what the current game looks like.
void printBoard(const char board[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    cout << "Board:" << endl;
    for (int i = 0; i < numRows; ++i) {
        cout << "<row " << i << "> ";
        for (int j = 0; j < numCols; ++j) {
            cout << board[i][j] << (j == numCols - 1 ? "" : " "); // Let's put spaces between the pieces.
        }
        cout << endl; // And a new line for each row.
    }
}

// Let's check if anyone has four pieces in a row horizontally. That's across each line.
bool checkHorizontal(const char board[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= numCols - 4; ++j) {
            if (board[i][j] != '.' && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true; // Found a horizontal win!
            }
        }
    }
    return false; // No horizontal winner found this time.
}

// How about vertically? Let's see if there are four in a column, going up and down.
bool checkVertical(const char board[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    for (int j = 0; j < numCols; ++j) {
        for (int i = 0; i <= numRows - 4; ++i) {
            if (board[i][j] != '.' && board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return true; // Got four in a column!
            }
        }
    }
    return false; // No vertical winner here.
}

// Diagonals are a bit more complex. We need to check both ways: top-left to bottom-right,
// and top-right to bottom-left.
bool checkDiagonal(const char board[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    // Check for top-left to bottom-right diagonals
    for (int i = 0; i <= numRows - 4; ++i) {
        for (int j = 0; j <= numCols - 4; ++j) {
            if (board[i][j] != '.' && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true; // Found a top-left to bottom-right diagonal!
            }
        }
    }

    // Check for top-right to bottom-left diagonals
    for (int i = 3; i < numRows; ++i) {
        for (int j = 0; j <= numCols - 4; ++j) {
            if (board[i][j] != '.' && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                return true; // Found a top-right to bottom-left diagonal!
            }
        }
    }
    return false; // No diagonal winners found this time.
}

// This function puts all our checks together to see if there's a winner.
char findWinner(const char board[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    if (checkHorizontal(board, numRows, numCols) ||
        checkVertical(board, numRows, numCols) ||
        checkDiagonal(board, numRows, numCols)) {
        // If any of the checks are true, we know someone has won. Let's find out who!
        // We can just re-check and return the token of the winner.
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= numCols - 4; ++j) {
                if (board[i][j] != '.' && board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                    return board[i][j]; // Red or Yellow won horizontally!
                }
            }
        }
        for (int j = 0; j < numCols; ++j) {
            for (int i = 0; i <= numRows - 4; ++i) {
                if (board[i][j] != '.' && board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                    return board[i][j]; // Red or Yellow won vertically!
                }
            }
        }
        for (int i = 0; i <= numRows - 4; ++i) {
            for (int j = 0; j <= numCols - 4; ++j) {
                if (board[i][j] != '.' && board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                    return board[i][j]; // Red or Yellow won diagonally (top-left to bottom-right)!
                }
            }
        }
        for (int i = 3; i < numRows; ++i) {
            for (int j = 0; j <= numCols - 4; ++j) {
                if (board[i][j] != '.' && board[i][j] == board[i - 1][j + 1] &&
                    board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                    return board[i][j]; // Red or Yellow won diagonally (top-right to bottom-left)!
                }
            }
        }
    }
    return ' '; // If we checked everywhere and didn't find a winner.
}

int main() {
    int numRows = 0;
    int numCols = 0;
    char connectFourBoard[MAX_ROWS][MAX_COLS];

    readBoard(connectFourBoard, numRows, numCols);

    printBoard(connectFourBoard, numRows, numCols);

    char winningPlayer = findWinner(connectFourBoard, numRows, numCols);

    cout << endl;
    cout << "Result: ";
    if (winningPlayer == 'R') {
        cout << "Red wins!" << endl;
    } else if (winningPlayer == 'Y') {
        cout << "Yellow wins!" << endl;
    } else {
        cout << "No winner." << endl;
    }

    return 0;
}