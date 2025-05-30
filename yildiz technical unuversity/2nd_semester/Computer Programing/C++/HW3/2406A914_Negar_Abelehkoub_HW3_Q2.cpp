#include <iostream>
#include <string>
using namespace std;

// Program for analyzing digit patterns in a number
int main() {
    string number;
    char choice;
    
    do {
        cout << "Enter a number: ";
        cin >> number;
        
        int evenCount = 0, oddCount = 0;
        bool increasing = true, decreasing = true;
        
        // Analyze digits
        for (size_t i = 0; i < number.length(); i++) {
            int digit = number[i] - '0';
            
            // Count even and odd digits
            if (digit % 2 == 0)
                evenCount++;
            else
                oddCount++;
            
            // Check order
            if (i > 0) {
                int prevDigit = number[i - 1] - '0';
                if (prevDigit > digit)
                    increasing = false;
                if (prevDigit < digit)
                    decreasing = false;
            }
        }
        
        // Determine order type
        if (increasing)
            cout << "Digits are in increasing order." << endl;
        else if (decreasing)
            cout << "Digits are in decreasing order." << endl;
        else
            cout << "Digits are unordered." << endl;
        
        // Display even and odd counts
        cout << "Even digits: " << evenCount << ", Odd digits: " << oddCount << endl;
        
        // Check for palindrome
        bool isPalindrome = true;
        int len = number.length();
        for (int i = 0; i < len / 2; i++) {
            if (number[i] != number[len - i - 1]) {
                isPalindrome = false;
                break;
            }
        }
        
        if (isPalindrome)
            cout << "The number is a palindrome." << endl;
        else
            cout << "The number is not a palindrome." << endl;
        
        // Ask for another input
        cout << "\nDo you want to enter another number? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Program terminated." << endl;
    return 0;
}
