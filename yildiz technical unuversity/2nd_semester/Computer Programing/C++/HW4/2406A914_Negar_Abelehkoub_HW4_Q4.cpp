#include <iostream>
#include <cassert>
#include <cstdlib> // for abs()
using namespace std;

// Checks if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Returns number of days in a month for a given year
int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// Converts a date to total number of days
int dateToDays(int day, int month, int year) {
    int totalDays = day;

    for (int y = 1; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth(m, year);
    }

    return totalDays;
}

// Returns absolute difference in days between two dates
int dayDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days1 = dateToDays(d1, m1, y1);
    int days2 = dateToDays(d2, m2, y2);
    return abs(days1 - days2);
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;

    cout << "Enter Date 1:\n";
    cout << "Day: ";
    cin >> d1;
    cout << "Month: ";
    cin >> m1;
    cout << "Year: ";
    cin >> y1;

    assert(m1 >= 1 && m1 <= 12);
    assert(y1 > 0);
    assert(d1 >= 1 && d1 <= daysInMonth(m1, y1));

    cout << "\nEnter Date 2:\n";
    cout << "Day: ";
    cin >> d2;
    cout << "Month: ";
    cin >> m2;
    cout << "Year: ";
    cin >> y2;

    assert(m2 >= 1 && m2 <= 12);
    assert(y2 > 0);
    assert(d2 >= 1 && d2 <= daysInMonth(m2, y2));

    int diff = dayDifference(d1, m1, y1, d2, m2, y2);

    cout << "\nDifference: " << diff << " days\n";

    return 0;
}
