#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int temp;

    // Input up to 20 integers, ends when non-number or newline is entered
    while (cin >> temp && arr.size() < 20) {
        arr.push_back(temp);
        if (cin.peek() == '\n') break; // stop reading on Enter
    }

    int comparisons = 0;
    int swaps = 0;

    for (int i = 1; i < arr.size(); ++i) {
        int j = i;
        while (j > 0) {
            comparisons++; // each comparison attempt counts
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                swaps++;
                cout << "Swap " << swaps << ": ";
                for (int k : arr) cout << k << " ";
                cout << endl;
            } else {
                break;
            }
            j--;
        }
    }

    cout << "Total comparisons: " << comparisons 
         << " | Total swaps: " << swaps << endl;

    return 0;
}
