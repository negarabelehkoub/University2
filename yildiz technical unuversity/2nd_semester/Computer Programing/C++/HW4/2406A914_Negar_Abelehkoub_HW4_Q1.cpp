#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Returns a random number between 0 and 100
int rand100() {
    return rand() % 101;
}

// Checks the guess and tells if it's correct or not
bool checkGuess(int guess, int secret, bool isComputer) {
    if (guess < secret) {
        if (isComputer)
            cout << "Computer's guess is too low.\n";
        else
            cout << "Your guess is too low.\n";
        return false;
    } else if (guess > secret) {
        if (isComputer)
            cout << "Computer's guess is too high.\n";
        else
            cout << "Your guess is too high.\n";
        return false;
    } else {
        if (isComputer)
            cout << "Computer guessed correctly and wins!\n";
        else
            cout << "Your guess is correct! You win!\n";
        return true;
    }
}

// Player's guessing turn
bool playerTurn(int computerSecret) {
    int guess;
    cout << "\nYour turn to guess the computer's secret number:\n";
    cout << "Your guess: ";
    cin >> guess;
    return checkGuess(guess, computerSecret, false);
}

// Computer's guessing turn
bool computerTurn(int playerSecret) {
    int guess = rand100(); // Random guess between 0 and 100
    cout << "\nComputer's turn to guess...\n";
    cout << "Computer guesses: " << guess << endl;
    return checkGuess(guess, playerSecret, true);
}

int main() {
    srand(time(0)); // Seed random number generator
    char playAgain = 'y';

    cout << "=== Welcome to the Number Guessing Game ===\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        int computerSecret = rand100();
        int playerSecret;

        cout << "Please enter your secret number (between 0 and 100): ";
        cin >> playerSecret;

        bool gameOver = false;

        while (!gameOver) {
            if (computerTurn(playerSecret)) {
                gameOver = true;
            } else {
                if (playerTurn(computerSecret)) {
                    gameOver = true;
                }
            }
        }

        cout << "\nDo you want to play another game? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing!\n";
    return 0;
}
