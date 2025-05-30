#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Function to generate a secure random password
string generateSecurePassword(int length) {
    if (length < 12) length = 12;  // Ensure minimum length is 12

    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    const string special = "@#$%^&*";
    const string allChars = upper + lower + digits + special;
    
    string password;
    srand(time(0));  // Seed random generator

    // Ensure at least one of each required character type
    password += upper[rand() % upper.length()];
    password += lower[rand() % lower.length()];
    password += digits[rand() % digits.length()];
    password += special[rand() % special.length()];

    // Fill the remaining characters randomly
    for (int i = 4; i < length; i++) {
        password += allChars[rand() % allChars.length()];
    }

    return password;
}

// Function to validate a password
bool isValidPassword(const string& password) {
    if (password.length() < 12) {
        cout << "- Password must be at least 12 characters long.\n";
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    const string specialChars = "@#$%^&*";

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
        if (isdigit(ch)) hasDigit = true;
        if (specialChars.find(ch) != string::npos) hasSpecial = true;
    }

    if (!hasUpper) cout << "- Missing an uppercase letter.\n";
    if (!hasLower) cout << "- Missing a lowercase letter.\n";
    if (!hasDigit) cout << "- Missing a digit.\n";
    if (!hasSpecial) cout << "- Missing a special character.\n";

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Main function to demonstrate password generation and validation
int main() {
    char choice;
    do {
        cout << "\n1 - Generate Secure Password\n2 - Validate Password\n3 - Exit\nEnter choice: ";
        int option;
        cin >> option;

        if (option == 1) {
            int length;
            cout << "Enter password length (min 12, max 32): ";
            cin >> length;
            if (length < 12 || length > 32) {
                cout << "Invalid length! Must be between 12 and 32.\n";
            } else {
                string password = generateSecurePassword(length);
                cout << "Generated Secure Password: " << password << endl;
            }
        } 
        else if (option == 2) {
            string password;
            cout << "Enter password to validate: ";
            cin >> password;
            if (isValidPassword(password)) {
                cout << "✅ Strong Password: The password is secure.\n";
            } else {
                cout << "❌ Weak Password: The password is NOT secure.\n";
            }
        } 
        else if (option == 3) {
            cout << "Program terminated.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
