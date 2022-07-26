#include <iostream>

int main() {
    
    int A, B, A_reverse = 0, B_reverse = 0;
    std::cin >> A >> B;
    
    int multiplier = 100;
    while (multiplier >= 1) {
        A_reverse += (A % 10) * multiplier;
        B_reverse += (B % 10) * multiplier;
        A /= 10; B /= 10;
        multiplier /= 10;
    }
    
    std::cout << ((A_reverse > B_reverse) ? A_reverse : B_reverse) << std::endl;
    
    return 0;
}