#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <tuple>
#include <iomanip>
using namespace std;

struct Stats {
    long long comparisons = 0;
    long long swaps = 0;
};

Stats quickStats, heapStats, insertStats;

void insertionSort(vector<int>& a, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= left && (++insertStats.comparisons, a[j] > key)) {
            a[j + 1] = a[j];
            insertStats.swaps++;
            j--;
        }
        a[j + 1] = key;
    }
}

void heapify(vector<int>& a, int n, int i, int start) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && (++heapStats.comparisons, a[start + l] > a[start + largest]))
        largest = l;
    if (r < n && (++heapStats.comparisons, a[start + r] > a[start + largest]))
        largest = r;

    if (largest != i) {
        swap(a[start + i], a[start + largest]);
        heapStats.swaps++;
        heapify(a, n, largest, start);
    }
}

void heapSort(vector<int>& a, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, left);
    for (int i = n - 1; i > 0; i--) {
        swap(a[left], a[left + i]);
        heapStats.swaps++;
        heapify(a, i, 0, left);
    }
}

void introSortUtil(vector<int>& a, int left, int right, int depthLimit) {
    int size = right - left + 1;
    if (size <= 16) {
        insertionSort(a, left, right);
        return;
    }
    if (depthLimit == 0) {
        heapSort(a, left, right);
        return;
    }

    int pivot = a[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while ((++quickStats.comparisons, a[i] < pivot)) i++;
        while ((++quickStats.comparisons, a[j] > pivot)) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            quickStats.swaps++;
            i++;
            j--;
        }
    }
    if (left < j) introSortUtil(a, left, j, depthLimit - 1);
    if (i < right) introSortUtil(a, i, right, depthLimit - 1);
}

void introSort(vector<int>& a) {
    int depthLimit = 2 * log2(a.size());
    introSortUtil(a, 0, a.size() - 1, depthLimit);
}

void resetStats() {
    quickStats = {};
    heapStats = {};
    insertStats = {};
}

void testSize(int size) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, size);

    long long qCmp = 0, qSwp = 0;
    long long hCmp = 0, hSwp = 0;
    long long iCmp = 0, iSwp = 0;

    for (int i = 0; i < 30; ++i) {
        vector<int> a(size);
        for (int& x : a) x = dist(rng);
        resetStats();
        introSort(a);
        qCmp += quickStats.comparisons;
        qSwp += quickStats.swaps;
        hCmp += heapStats.comparisons;
        hSwp += heapStats.swaps;
        iCmp += insertStats.comparisons;
        iSwp += insertStats.swaps;
    }

    cout << size << "\tQuick\t" << qCmp / 30 << "\t" << qSwp / 30 << endl;
    cout << "\tHeap\t" << hCmp / 30 << "\t" << hSwp / 30 << endl;
    cout << "\tInsert\t" << iCmp / 30 << "\t" << iSwp / 30 << endl;
}

int main() {
    cout << "Size\tAlgPhase\tAvgCmp\tAvgSwp" << endl;
    testSize(100);
    testSize(1000);
    testSize(10000);

    cout << "\nComment: IntroSort never exceeds O(n log n) because it falls back to Heap Sort (O(n log n))\n"
         << "when recursion depth becomes too high, avoiding Quick Sort's worst-case of O(n^2)." << endl;
    return 0;
}
