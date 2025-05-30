#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double principal, interestRate, years, simpleInterest, finalBalance;

    // Get user input
    cout << "Enter the initial deposit amount (Principal): ";
    cin >> principal;
    cout << "Enter the annual interest rate (in %): ";
    cin >> interestRate;
    cout << "Enter the number of years: ";
    cin >> years;

    // Calculate simple interest
    simpleInterest = (principal * interestRate * years) / 100;

    // Calculate final balance
    finalBalance = principal + simpleInterest;

    // Display results
    cout << "\nTotal Interest Earned: " << simpleInterest << endl;
    cout << "Final Balance: " << finalBalance << endl;

    return 0;
}
