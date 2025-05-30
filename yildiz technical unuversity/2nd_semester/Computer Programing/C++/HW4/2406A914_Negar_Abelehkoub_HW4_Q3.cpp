#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;

const double PI = 3.14159;

// Overloaded functions
double unitPrice(int radius, double price) {
    double area = PI * radius * radius;
    return price / area;
}

double unitPrice(int length, int width, double price) {
    double area = length * width;
    return price / area;
}

int main() {
    char again = 'y';

    cout << "--- BEST PIZZA PRICE CALCULATOR ---\n";

    while (again == 'y' || again == 'Y') {
        double price1, price2;
        double unit1, unit2;
        char shape;
        int r, l, w;

        // Pizza 1
        cout << "\nEnter details for Pizza 1.\n";
        cout << "Enter pizza shape (R for round, D for rectangular): ";
        cin >> shape;
        shape = tolower(shape);

        if (shape == 'r') {
            cout << "Enter radius (cm): ";
            cin >> r;
            assert(r > 0);
            cout << "Enter price (₺): ";
            cin >> price1;
            assert(price1 > 0);
            unit1 = unitPrice(r, price1);
        } else if (shape == 'd') {
            cout << "Enter length (cm): ";
            cin >> l;
            assert(l > 0);
            cout << "Enter width (cm): ";
            cin >> w;
            assert(w > 0);
            cout << "Enter price (₺): ";
            cin >> price1;
            assert(price1 > 0);
            unit1 = unitPrice(l, w, price1);
        } else {
            cout << "Invalid shape.\n";
            continue;
        }

        // Pizza 2
        cout << "\nEnter details for Pizza 2.\n";
        cout << "Enter pizza shape (R for round, D for rectangular): ";
        cin >> shape;
        shape = tolower(shape);

        if (shape == 'r') {
            cout << "Enter radius (cm): ";
            cin >> r;
            assert(r > 0);
            cout << "Enter price (TL): ";
            cin >> price2;
            assert(price2 > 0);
            unit2 = unitPrice(r, price2);
        } else if (shape == 'd') {
            cout << "Enter length (cm): ";
            cin >> l;
            assert(l > 0);
            cout << "Enter width (cm): ";
            cin >> w;
            assert(w > 0);
            cout << "Enter price (TL): ";
            cin >> price2;
            assert(price2 > 0);
            unit2 = unitPrice(l, w, price2);
        } else {
            cout << "Invalid shape.\n";
            continue;
        }

        // Results
        cout << "\nPizza 1 unit price: " << unit1 << " ₺/cm^2\n";
        cout << "Pizza 2 unit price: " << unit2 << " ₺/cm^2\n";

        if (unit1 < unit2) {
            cout << "Pizza 1 is a better deal.\n";
        } else if (unit2 < unit1) {
            cout << "Pizza 2 is a better deal.\n";
        } else {
            cout << "Both pizzas are equally priced.\n";
        }

        cout << "\nDo you want to compare another pair? (y/n): ";
        cin >> again;
    }

    cout << "\nThanks for using the pizza calculator!\n";

    return 0;
}
