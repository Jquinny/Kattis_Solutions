#include <iostream>
#include <unordered_map>
#include <string>

int main() {

    int time, total_time = 0, probs_solved = 0;
    char prob;
    std::string result;
    std::unordered_map<char, int> prob_penalty_time;

    while (true) {
        std::cin >> time;
        if (time == -1) break;

        std::cin >> prob >> result;
        if (result == "right") {
            total_time += prob_penalty_time[prob] + time;
            probs_solved++;
        } else {
            prob_penalty_time[prob] += 20;
        }

    }

    std::cout << probs_solved << " " << total_time << std::endl;

    return 0;
}