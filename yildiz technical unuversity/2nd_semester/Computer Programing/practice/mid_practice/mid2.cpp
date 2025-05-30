#include <iostream>
using namespace std;
int main()
{
double drain, batteryLevel;
batteryLevel = 100;
drain = 5;
do
{
    batteryLevel -= drain;
    if (batteryLevel > 15)
    {
        cout << "battery level : " << batteryLevel << "%\n";

    }
    else
    {
        cout << " please land the drone you have less than 15%" << "battery level : " << batteryLevel << "%\n";

    }

} while (batteryLevel >= 5);
return 0 ;
}