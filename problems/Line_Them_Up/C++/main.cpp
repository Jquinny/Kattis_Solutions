#include <iostream>
#include <string>

int main() {

    int n, increase = 0, decrease = 0;
    std::string name1, name2;

    std::cin >> n;
    std::cin >> name1;

    for (int i = 0; i < n-1; i++) {
        std::cin >> name2;
        if (name1 < name2) {
            increase++;
        } else if (name1 > name2) {
            decrease++;
        }
        name1 = name2;
    }

    if (increase && decrease) {
        std::cout << "NEITHER" << std::endl;
    } else if (increase) {
        std::cout << "INCREASING" << std::endl;
    } else {
        std::cout << "DECREASING" << std::endl;
    }

    return 0;
}