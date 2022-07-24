#include <iostream>
#include <string>

int recurse(int digits, int i) {

    if (digits == 1) {
        return i + 1;
    } else {
        int dig_num = 0;
        while (digits > 0) {
            digits /= 10;
            dig_num++;
        }
        return recurse(dig_num, i+1);
    }
}

int main() {

    std::string num;
    int ans, len;

    while (getline(std::cin, num) && num != "END") {
        if (num == "1") {
            std::cout << 1 << std::endl;
        } else {
            len = num.length();
            ans = recurse(len, 1);
            std::cout << ans << std::endl;
        }
    }

    return 0;
}