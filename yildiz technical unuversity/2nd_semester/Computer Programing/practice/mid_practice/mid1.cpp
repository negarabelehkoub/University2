#include <iostream>
using namespace std;
int main ()
{
    double movement, position;
    char question, direction;
    movement = 0.1;
    position = 0;
    while (-5.1 < position && position < 5.1)
    {
        cout << "\n do you want to go forward'f' or backward'b' \n";
        cin >> question;
        if (question = 'f')
        {
            position += movement;
        }
        else
        {
            position -= movement;
        }
        cout << "you are at " << position << "\n";

    }
    cout << "\nfyou have exceded your limit of movment you are at "<< position << "\n";
    return 0;
}