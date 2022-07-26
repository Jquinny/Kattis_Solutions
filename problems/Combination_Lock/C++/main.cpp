#include <iostream>

int main() {
    
    int num1, num2, num3, num4;

    while (true) {
        std::cin >> num1 >> num2 >> num3 >> num4;
        if (!num1 && !num2 && !num3 && !num4) break;
        int deg_to_first = 720 + 9*((num1 - num2 + 40) % 40);
        int deg_to_second = 360 + 9*((num3 - num2 + 40) % 40);
        int deg_to_third = 9*((num3 - num4 + 40) % 40);
        std::cout << deg_to_first + deg_to_second + deg_to_third << std::endl; 
    }
    
    return 0;
}


/* ALTERNATIVE: This one uses conditional statements instead of mod to deal with
                the two cases of going past zero or not on the lock
int main() {
    
    int num1, num2, num3, num4;

    while (true) {
        std::cin >> num1 >> num2 >> num3 >> num4;
        if (!num1 && !num2 && !num3 && !num4) break;
        int diff1 = (num1 >= num2) ? num1-num2 : 40-(num2-num1);
        int diff2 = (num2 > num3) ? 40-(num2-num3) : num3-num2;
        int diff3 = (num3 >= num4) ? num3-num4 : 40-(num4-num3);
        std::cout << 9*(120 + diff1 + diff2 + diff3) << std::endl; 
    }
    
    return 0;
}
*/