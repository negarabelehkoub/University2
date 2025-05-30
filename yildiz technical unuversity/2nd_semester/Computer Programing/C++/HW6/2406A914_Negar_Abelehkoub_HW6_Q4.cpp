#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// Let's first take our list of words and make sure we only have one of each.
// Think of it like tidying up and removing any repeats!
int removeDuplicate(vector<string>& words, int n) {
    set<string> uniqueWords(words.begin(), words.end());
    words.assign(uniqueWords.begin(), uniqueWords.end());
    return words.size(); // We'll also count how many unique words we have now.
}

// Now that we have our unique words, let's put them in order, like arranging them in a dictionary.
void sortStrings(vector<string>& words, int n) {
    sort(words.begin(), words.end());
}

// Sometimes, words in a list share a common beginning. Let's find the longest
// starting bit that all of them have in common. If they don't share anything, we'll just say nothing.
string longestCommonPrefix(const vector<string>& words, int n) {
    if (words.empty()) {
        return ""; // If there are no words, there's no prefix!
    }
    string prefix = words[0]; // Let's assume the first word's the starting point.
    for (int i = 1; i < n; ++i) {
        int j = 0;
        // We'll compare our current prefix with the next word, letter by letter.
        while (j < prefix.length() && j < words[i].length() && prefix[j] == words[i][j]) {
            j++;
        }
        // If we found a difference, or reached the end of either word,
        // our common prefix is only as long as the matching part.
        prefix = prefix.substr(0, j);
        if (prefix.empty()) {
            break; // If at any point the common prefix becomes empty, we can stop.
        }
    }
    return prefix; // Here's the longest common start we found!
}

// Some words are special because they read the same forwards and backward, like "level".
// Let's find these palindromes in our list and keep track of where they were originally.
int findPalindromes(const vector<string>& words, int n, vector<int>& palindromeIndices) {
    int palindromeCount = 0;
    for (int i = 0; i < n; ++i) {
        string word = words[i];
        string reversedWord = word;
        reverse(reversedWord.begin(), reversedWord.end());
        if (word == reversedWord) {
            palindromeCount++;
            palindromeIndices.push_back(i); // We're saving the original position of the palindrome.
        }
    }
    return palindromeCount; // And here's how many palindromes we found.
}

int main() {
    int wordCount;
    cout << "Input:" << endl;
    cin >> wordCount;
    cin.ignore(); // To handle the newline after reading the number.

    vector<string> allWords(wordCount);
    for (int i = 0; i < wordCount; ++i) {
        getline(cin, allWords[i]); // Let's read in each word.
    }

    cout << endl; // Just for that spacing in the output.

    // First, let's get rid of any repeated words.
    int uniqueWordCount = removeDuplicate(allWords, wordCount);
    cout << "Unique sorted words (count - " << uniqueWordCount << "):" << endl;
    // Now, let's sort these unique words alphabetically.
    sortStrings(allWords, allWords.size());
    for (const string& word : allWords) {
        cout << word << " ";
    }
    cout << endl;
    cout << endl; // More spacing for the output.

    // What's the longest common start for all these unique words?
    string commonPrefix = longestCommonPrefix(allWords, allWords.size());
    cout << "Longest common prefix: \"" << commonPrefix << "\"" << endl;
    cout << endl; // Keeping that output format consistent.

    // Time to find those special words that are the same backward and forward!
    vector<int> palindromePositions;
    int palindromeTotal = findPalindromes(allWords, wordCount, palindromePositions);
    cout << "Palindrome count: " << palindromeTotal << endl;
    cout << "Palindrome Indices: ";
    for (size_t i = 0; i < palindromePositions.size(); ++i) {
        cout << palindromePositions[i];
        if (i < palindromePositions.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}