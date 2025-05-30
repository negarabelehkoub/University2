#include <iostream>
using namespace std;

int* addEntry(int* arr, int &size, int value) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    newArr[size] = value;

    size++;

    delete[] arr;

    return newArr;
}

int* deleteEntry(int* arr, int &size, int index) {
    if (index < 0 || index >= size) {
        return arr;
    }

    int* newArr = new int[size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newArr[j] = arr[i];
            j++;
        }
    }

    size--;

    delete[] arr;

    return newArr;
}

int main() {
    int size = 5;
    int* arr = new int[size]{1, 2, 3, 4, 5};

    cout << "Initial array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    arr = addEntry(arr, size, 10);

    cout << "After adding 10: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    arr = deleteEntry(arr, size, 2);

    cout << "After deleting index 2: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}
