#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double acceleration, tempreture;
    int timestamp;
    cout << "give acceleration tempreture and timestamp"<< endl;
    cin >> acceleration >> tempreture >> timestamp ;
    cout << setw(10) << setfill('0') << timestamp;
    cout << showpos << fixed << setprecision(2)<< tempreture;
    cout << fixed << setprecision(6) << acceleration;
    return 0;
}