#include <iostream>

int main() {

    int l, r;
    std::cin >> l >> r;

    if (l == 0 && r == 0) {
        std::cout << "Not a moose" << std::endl;
    } else if (l == r) {
        std::cout << "Even " << l + r << std::endl;
    } else {
        std::cout << "Odd " << (l > r ? 2*l : 2*r) << std::endl;
    }

    return 0;
}