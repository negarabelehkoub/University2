#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double force, length, area, yield_strength;

    cout << "Enter the force applied (N): ";
    cin >> force;

    cout << "Enter the length of the arm (m): ";
    cin >> length;

    cout << "Enter the cross-sectional area (mm²): ";
    cin >> area;

    cout << "Enter the material's yield strength (MPa): ";
    cin >> yield_strength;

    double torque = force * length;
    double stress = force / area; 

    cout << fixed << setprecision(2);
    cout << "\nCalculated Torque: " << torque << " N·m" << endl;
    cout << "Calculated Stress: " << stress << " MPa" << endl;
  
    if (stress > yield_strength) {
        cout << "Warning: Material will fail!" << endl;
    } 
    else {
        cout << "Material is safe under the applied load." << endl;
    }

    return 0;
}