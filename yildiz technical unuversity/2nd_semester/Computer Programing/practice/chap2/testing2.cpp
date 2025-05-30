#include <iostream>
#include <string>
using namespace std;
int main()
{
    string middleName, petName;
    string alterEgoName;
    cout <<"enter your middle name and pet name:\n";
    cin >> middleName;
    cin >> petName;
    alterEgoName = petName + " " + middleName;
    cout << "the name of your alter ego: \n";
    cout << alterEgoName << " " << endl;
    return 0;
}