#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double price1, price2, price3;
    int quantity1, quantity2, quantity3;

    cout << "Enter the price of product 1: ";
    cin >> price1;
    cout << "Enter the quantity of product 1: ";
    cin >> quantity1;

    cout << "Enter the price of product 2: ";
    cin >> price2;
    cout << "Enter the quantity of product 2: ";
    cin >> quantity2;

    cout << "Enter the price of product 3: ";
    cin >> price3;
    cout << "Enter the quantity of product 3: ";
    cin >> quantity3;

    double total_price = (price1 * quantity1) + (price2 * quantity2) + (price3 * quantity3);

    const double VAT_RATE = 0.08;
    double vat_amount = total_price * VAT_RATE;
    double total_price_with_vat = total_price + vat_amount;

    cout << fixed << setprecision(2);
    cout << "\nTotal Price: " << total_price << " USD" << endl;
    cout << "VAT (8%): " << vat_amount << " USD" << endl;
    cout << "Total Price with VAT: " << total_price_with_vat << " USD" << endl;

    return 0;
}