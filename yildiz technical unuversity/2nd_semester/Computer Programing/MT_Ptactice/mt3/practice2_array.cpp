#include <iostream>

const int NUMBER_OF_EMPLOYEES = 3;
int adjustDays(int oldDays);

int main()
{
    using namespace std;
    int vacation[NUMBER_OF_EMPLOYEES], number;
    cout << "enter allowed vacation days for employee 1: \n";
    for ( number = 1; number <= NUMBER_OF_EMPLOYEES; number++)
    {
        cin >> vacation[number-1];
        vacation[number-1] = adjustDays (vacation[number-1]);
        cout << "employee number: " << number << " vacation days: " << vacation[number-1];
        cout << "\nenter allowed vacation days for employee 1: \n";

    }
    return 0;
 
}
int adjustDays (int oldDays)
{
    return(oldDays + 5);
}