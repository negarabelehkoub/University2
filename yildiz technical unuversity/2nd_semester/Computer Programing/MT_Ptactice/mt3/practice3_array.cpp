#include <iostream>
void fillArray (int a[], int size, int& numUsed)
{
    using namespace std;
    cout << "guyfkuuf" << size << "ftjfjdu\n";
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index]= next;
        index ++ ; 
        cin >> next;
    }
    numUsed = index;
}



int search(const int a[], int numberUsed, int target)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
    {
        if (target == a[index])
        {
            found = true;
        }
        else
        {
            index ++;
        }
    }

    if (found)
    {
        return index;
    }
    else
    {
        return -1;
    }   
    
}



void getTotal(int& sum)
{
    using namespace std;
    cout << "ldsvgksadfcsscgsvgjkdgcjd\n";
    sum = 0;
    int next;
    cin >> next;
    while (next >= 0)
    {
        sum = sum + next;
        cin >> next;
    }
    cout<< sum ;
}



double average (const int a[], int numberUsed)
{
    double total = 0;
    for (int index = 0; index < numberUsed; index++)
    {
        total = total + a[index];
    }
    
}