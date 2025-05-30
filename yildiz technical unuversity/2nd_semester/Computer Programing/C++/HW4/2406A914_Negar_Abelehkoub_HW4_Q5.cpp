#include <iostream>
#include <cassert>
using namespace std;

// Returns average score
double average(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Returns minimum score
int minScore(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Returns maximum score
int maxScore(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Scales scores with a factor and caps at 100
void scaleScores(int arr[], int size, double scaleFactor) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * scaleFactor;
        if (arr[i] > 100) {
            arr[i] = 100;
        }
    }
}

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;
    assert(numStudents > 0);

    int* scores = new int[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter score for student " << i + 1 << ": ";
        cin >> scores[i];
        assert(scores[i] >= 0 && scores[i] <= 100);
    }

    double avg = average(scores, numStudents);
    int min = minScore(scores, numStudents);
    int max = maxScore(scores, numStudents);

    cout << "\nAverage Score: " << avg << endl;
    cout << "Minimum Score: " << min << endl;
    cout << "Maximum Score: " << max << endl;

    double scaleFactor;
    cout << "\nEnter scale factor (e.g., 1.1 to increase grades by 10%): ";
    cin >> scaleFactor;

    scaleScores(scores, numStudents, scaleFactor);

    cout << "\nGrades after scaling:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": " << scores[i] << endl;
    }

    double newAvg = average(scores, numStudents);
    int newMin = minScore(scores, numStudents);
    int newMax = maxScore(scores, numStudents);

    cout << "\nNew Average Score: " << newAvg << endl;
    cout << "New Minimum Score: " << newMin << endl;
    cout << "New Maximum Score: " << newMax << endl;

    delete[] scores;

    return 0;
}
