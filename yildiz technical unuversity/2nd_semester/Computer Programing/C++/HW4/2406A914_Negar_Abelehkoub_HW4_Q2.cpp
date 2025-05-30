#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

const double PI = 3.14159;

// Overloaded calculate functions

double calculate(double base, double exponent) {
    return pow(base, exponent);
}

double calculate(double angleInDegrees) {
    double radians = angleInDegrees * (PI / 180);
    return sin(radians);
}

int calculate(int x, int y) {
    return abs(x - y);
}

int calculate(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double calculate(double value, bool isLog) {
    if (isLog) {
        return log(value); // natural log
    }
    else {
        return log10(value); // base 10 log
    }
}

int main() {
    int choice;
    char again = 'y';

    cout << "=== SCIENTIFIC CALCULATOR ===\n";

    while (again == 'y' || again == 'Y') {
        cout << "\nSelect an operation:\n";
        cout << "1 - Power calculation (base ^ exponent)\n";
        cout << "2 - Sine calculation (in degrees)\n";
        cout << "3 - Absolute difference between two integers\n";
        cout << "4 - Factorial of an integer\n";
        cout << "5 - Logarithm (choose natural or base 10)\n";
        cout << "Your choice: ";
        cin >> choice;

        assert(choice >= 1 && choice <= 5);

        if (choice == 1) {
            double base, exponent;
            cout << "Enter base: ";
            cin >> base;
            cout << "Enter exponent: ";
            cin >> exponent;
            cout << "Result: " << calculate(base, exponent) << endl;
        }
        else if (choice == 2) {
            double angle;
            cout << "Enter angle in degrees: ";
            cin >> angle;
            cout << "Result: " << calculate(angle) << endl;
        }
        else if (choice == 3) {
            int x, y;
            cout << "Enter two integers: ";
            cin >> x >> y;
            cout << "Result: " << calculate(x, y) << endl;
        }
        else if (choice == 4) {
            int n;
            cout << "Enter a non-negative integer: ";
            cin >> n;
            assert(n >= 0);
            cout << "Result: " << calculate(n) << endl;
        }
        else if (choice == 5) {
            double value;
            int logType;
            cout << "Enter a positive number: ";
            cin >> value;
            assert(value > 0);
            cout << "Enter 1 for natural log, 0 for log base 10: ";
            cin >> logType;
            cout << "Result: " << calculate(value, logType == 1) << endl;
        }

        cout << "\nWould you like to perform another operation? (y/n): ";
        cin >> again;
    }

    cout << "\nThanks for using the calculator!\n";
    return 0;
}
