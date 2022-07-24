#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout, std::cin, std::endl;

int main() {

    int p, a, b, c, d, n;
    double high = 0, low = 0, dip = 0, price = 0;

    cin >> p >> a >> b >> c >> d >> n;

    price = p * (std::sin((a*1)+b) + std::cos((c*1)+d) + 2);
    high = price; low = price;

    for (int i = 2; i <= n; i++) {
        price = p * (std::sin((a*i)+b) + std::cos((c*i)+d) + 2);
        if (price > high) {
            high = price; low = price;
        } else if (price < low) {
            if (high - price > dip) dip = high - price;
            low = price;
        }
    }

    cout << std::fixed << std::setprecision(6) << dip << endl;

    return 0;
}