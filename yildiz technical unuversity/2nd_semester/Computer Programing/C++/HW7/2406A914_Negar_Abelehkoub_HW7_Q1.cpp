#include <iostream>
using namespace std;

void increment(int *p) {

    *p = *p + 1;  
}
int main() {
    int x = 10;  

    cout << "Initially, x = " << x << endl;

    increment(&x);  
    cout << "After function call, x = " << x << endl;

    return 0;
}
