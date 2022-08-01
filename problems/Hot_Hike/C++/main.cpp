#include <iostream>

int main() {

    int n, day = 1, max, max_final = 100;

    std::cin >> n;

    int * temps = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> temps[i];
    }

    for (int i = 0; i < n-2; i++) {
        max = (temps[i] >= temps[i+2]) ? temps[i] : temps[i+2];
        if (max < max_final) {
            day = i+1;
            max_final = max;
        }
    }

    std::cout << day << " " << max_final << std::endl;

    return 0;
}