#include <iostream>
#include <string>

int main() {

    int t, g, mg, monster;
    int g_best;
    bool g_win;
    std::string blank;

    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::getline(std::cin, blank);
        g_win = true;
        g_best = 0;
        std::cin >> g >> mg;
        for (int j = 0; j < g; j++) {
            std::cin >> monster;
            if (monster > g_best) g_best = monster;
        }
        for (int k = 0; k < mg; k++) {
            std::cin >> monster;
            if (monster > g_best) {
                std::cout << "MechaGodzilla" << std::endl;
                g_win = false;
                break;
            }
        }
        if (g_win) {
            std::cout << "Godzilla" << std::endl;
        }
    }

    return 0;
}