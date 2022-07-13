#include <iostream>

int score(int value) {
    if (value == 21) {
        return 3;
    } else if ((value%10) == (value/10)%10) {
        return 2;
    } else {
        return 1;
    }
}

void winner(int value1, int value2) {
    if (value1 == value2) {
        std::cout << "Tie." << std::endl;
        return;
    }

    int score1 = score(value1);
    int score2 = score(value2);
    if (score1 == score2) {
        value1 > value2 ? std::cout << "Player 1 wins." << std::endl : std::cout << "Player 2 wins." << std::endl;
    } else if (score1 > score2) {
        std::cout << "Player 1 wins." << std::endl;
    } else {
        std::cout << "Player 2 wins." << std::endl;
    }
}

int main() {
    
    int roll1, roll2, player1_value, player2_value;

    while (true) {
        // player 1 rolls
        std::cin >> roll1 >> roll2;
        if (roll1 == 0) break; // end of game
        player1_value = (roll1 > roll2) ? (roll1*10 + roll2) : (roll2*10 + roll1);
        
        // player 2 rolls
        std::cin >> roll1 >> roll2;
        player2_value = (roll1 > roll2) ? (roll1*10 + roll2) : (roll2*10 + roll1);
        
        // find winner
        winner(player1_value, player2_value);
    }
    
    return 0;
}