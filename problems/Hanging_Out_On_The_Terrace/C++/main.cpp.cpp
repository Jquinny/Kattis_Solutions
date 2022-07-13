#include <iostream>
#include <string>

int main() {
    
    int l, x, num, groups = 0, current = 0;
    std::string event;
    
    // taking in input here
    std::cin >> l >> x;
    for (int i = 0; i < x; i++) {
        std::cin >> event >> num;
        if (event == "enter") {
            if (num + current > l) {
                groups++;
            } else {
                current += num;
            }
        } else {
            current -= num;
        }
    }
    
    std::cout << groups << std::endl;
    
    return 0;
}