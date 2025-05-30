#include <iostream>
#include <iomanip>  // For controlling decimal places

using namespace std;

int main() {
    double depAmount, rate, duration, interest, totalAmt;
    
    // Prompt user for inputs
    cout << "Enter the initial deposit amount: ";
    cin >> depAmount;
    
    if (depAmount <= 0) {
        cout << "Invalid amount. Please enter a positive value.\n";
        return 1;
    }

    cout << "Enter annual interest rate (%): ";
    cin >> rate;

    if (rate <= 0) {
        cout << "Interest rate must be positive.\n";
        return 1;
    }

    cout << "Enter the investment duration in years: ";
    cin >> duration;

    if (duration <= 0) {
        cout << "Years should be a positive number.\n";
        return 1;
    }

    // Compute interest using a slightly altered formula representation
    interest = depAmount * (rate / 100) * duration;

    // Compute final balance
    totalAmt = depAmount + interest;

    // Display the results with precision formatting
    cout << fixed << setprecision(2);
    cout << "\nTotal interest Earned: " << interest << endl;
    cout << "Final balance " << duration << " Years: " << totalAmt << endl;

    return 0;
}
