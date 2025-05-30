#include <iostream>
#include <string>

using namespace std;

// Okay, let's figure out how many times our little 'pattern' shows up
// in the bigger 'text'. The catch is, we only want to count them if they
// don't overlap with each other. Imagine looking for "aba" in "abababa".
// We'd find one at the beginning, and then another one right after, not in the middle.

int countNonOverlapping(const string& text, const string& pattern) {
    int occurrenceCount = 0; // Let's start our counter at zero.
    size_t currentIndex = 0; // We'll start looking from the beginning of the text.

    // We'll keep searching as long as we can still find the pattern.
    while ((currentIndex = text.find(pattern, currentIndex)) != string::npos) {
        // Aha! We found the pattern! Let's make a note of it.
        occurrenceCount++;
        // Now, to make sure we don't count any overlaps, we'll jump our
        // search ahead to the position right after the pattern we just found.
        currentIndex += pattern.length();
    }

    // Alright, we've gone through the whole text. Let's tell you how many times
    // we spotted our pattern without any overlaps.
    return occurrenceCount;
}

int main() {
    string mainText;
    string searchPattern;

    cout << "Input:" << endl;
    cout << "text = ";
    getline(cin >> ws, mainText); // Let's grab the whole line of text.
    cout << "pattern = ";
    getline(cin >> ws, searchPattern); // And let's get the pattern we're looking for.

    int result = countNonOverlapping(mainText, searchPattern);

    cout << "Output:" << endl;
    cout << "Occurrences: " << result << endl; // Here's the final count!

    return 0;
}