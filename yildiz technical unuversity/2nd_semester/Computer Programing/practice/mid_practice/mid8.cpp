#include <iostream>
using namespace std;
int torqueCalculator(double mass, double lenght, double saftyFactor)
{
    double torque = mass * 9.81 * lenght * saftyFactor;
    return torque;

}

int main()
{
    double mass, lenght , saftyFactor;
    cout << "what is your mass lenght and safty factor :\n";
    cin >> mass >> lenght >> saftyFactor;
    double torque = torqueCalculator(mass, lenght, saftyFactor);
    cout << torque;
    return 0;

}