#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Number of elements is? ";
    cin >> n;

    double* numbers = new double[n];

    cout << " enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i]; 
    } 

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    double average = sum / n;
    cout << "The average is: " << average << endl;

    delete[] numbers;

    return 0;
}
