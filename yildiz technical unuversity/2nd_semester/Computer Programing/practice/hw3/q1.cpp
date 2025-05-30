#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() 
{

    /*constants*/
    /*A-Z*/
    string uppercase;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        uppercase += i;
    }

    /*a-z*/
    string lowerCase;
    for (char i = 'a'; i <='z'; i++)
    {
        lowerCase += i;
    }
    
    /*0-9*/
    string numbers;
    for (char i = '0' ; i <= '9' ; i++)
    {
        numbers += i;
    }
    
    string allDigits;
    allDigits = uppercase + lowerCase + numbers;

    char continouGeneration;
    cout << "do you want to continou? \n";
    cin >> continouGeneration;
    
    while (continouGeneration == 'y')
    {
     /* generate pasword */
     int lenght;
     cout << "enter lenth \n";
     cin >> lenght;

     string password;

     for (int i = 0; i < lenght; i++)
     {
        int randomNumber = rand() % allDigits.length();
        char charecter = allDigits[randomNumber];
        password += charecter;

     }
     cout << password;

     cout << "do you want to continou? \n";
     cin >> continouGeneration;
    }
   
}