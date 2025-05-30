#include <iostream>
using namespace std;
int main ()
{
    double weight;
    cout << "what is the weight: "<< endl;
    cin >> weight;
    for (int zone = 1; zone <=3 ;  zone++)
    {
        if (zone == 1)
        {
            cout << "zone 1 starts :   speed = 10% of object detected" << endl;

        }
        else if (zone == 2)
        {
            cout << "zone 2 starts:    ";

            if (weight < 5)
            {
                cout << "speed = 50% of"<< endl;
            }
            else
            {
                cout << "speed = 75% of"<< endl;
            }
        
        }
        else if (zone == 3)
        {
            cout << "zone 2 starts:    ";
            cout << "speed = 100% of"<< endl;
            
        }
        
        
    }
    return 0;
}