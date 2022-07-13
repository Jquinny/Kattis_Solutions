#include <iostream>

int main() {
    int n, p = 1, days = 1;
    std::cin >> n;
    while (p < n) {
        p *= 2;
        days++;
    }
    std::cout << days << std::endl;
    return 0;
}