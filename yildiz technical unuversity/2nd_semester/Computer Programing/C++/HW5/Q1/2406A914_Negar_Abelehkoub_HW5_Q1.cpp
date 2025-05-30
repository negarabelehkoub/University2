#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Function to calculate the average
double calculateMean(const vector<double>& values) {
    double sum = 0.0;
    for (double v : values) sum += v;
    return sum / values.size();
}

// Function to calculate standard deviation
double calculateStdDev(const vector<double>& values, double mean) {
    double variance = 0.0;
    for (double v : values) variance += pow(v - mean, 2);
    return sqrt(variance / values.size());
}

int main() {
    ifstream infile("datalog.txt");
    ofstream outfile("anomalies.txt");

    if (!infile.is_open()) {
        cerr << "Error opening datalog.txt\n";
        return 1;
    }

    vector<double> values;
    double num;
    while (infile >> num) {
        values.push_back(num);
    }
    infile.close();

    if (values.empty()) {
        cerr << "No valid data in file.\n";
        return 1;
    }

    double mean = calculateMean(values);
    double stddev = calculateStdDev(values, mean);
    double minVal = *min_element(values.begin(), values.end());
    double maxVal = *max_element(values.begin(), values.end());

    int anomalies = 0;
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < values.size(); ++i) {
        if (fabs(values[i] - mean) > 2 * stddev) {
            ++anomalies;
            cout << "Line " << i + 1 << ": [" << values[i] << "] → Anomaly Detected\n";
            outfile << "Line " << i + 1 << ": [" << values[i] << "] → Anomaly Detected\n";
        }
    }

    // Summary
    cout << "\n--- Summary ---\n";
    cout << "Total values processed: " << values.size() << endl;
    cout << "Number of anomalies: " << anomalies << endl;
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;

    outfile.close();
    return 0;
}
