#include <iostream>
using namespace std;

int main() {
    int inputNum, digits[5], temp, i = 0;

    // Prompt user for input
    cout << "Enter a 5-digit number: ";
    cin >> inputNum;

    // Validate input (must be a 5-digit integer)
    if (inputNum < 10000 || inputNum > 99999) {
        cout << "Error: Enter a valid five-digit number.\n";
        return 1; // Exit with an error status
    }

    // Extract digits and store them in an array
    temp = inputNum;
    while (temp > 0) {
        digits[i] = temp % 10; // Get last digit
        temp /= 10;            // Remove last digit
        i++;
    }

    // Display reversed digits with three spaces in between
    cout << "Reversed: ";
    for (int j = 0; j < 5; j++) {
        cout << digits[j];
        if (j < 4) cout << "   "; // Add spacing
    }
    cout << endl;

    return 0;
}
