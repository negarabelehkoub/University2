#include <iostream>
#include <limits>

using namespace std;

int main() {
    int num;
    int sum = 0, count = 0;
    int even_count = 0, odd_count = 0;
    int largest = numeric_limits<int>::min();
    int smallest = numeric_limits<int>::max();

    cout << "Enter a positive integer (enter a negative number to stop): ";
    
    while (true) {
        cin >> num;

        if (num < 0) {
            break; 
        }

        sum += num;
        count++;

        if (num % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }

        if (num > largest) {
            largest = num;
        }
        if (num < smallest) {
            smallest = num;
        }

        cout << "Enter a positive integer (enter a negative number to stop): ";
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;

        cout << "\nSum: " << sum << endl;
        cout << "Average: " << fixed << average << endl;
        cout << "Even Numbers: " << even_count << endl;
        cout << "Odd Numbers: " << odd_count << endl;
        cout << "Largest Number: " << largest << endl;
        cout << "Smallest Number: " << smallest << endl;
    } else {
        cout << "\nNo numbers were entered." << endl;
    }

    return 0;
}