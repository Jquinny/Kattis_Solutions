#include <iostream>
#include <vector>
#include <string>
#include <set>


int main() {

    int rows, cols, r, c;
    char move;
    std::string row_moves;
    std::vector<std::vector<char>> grid;
    std::set<std::pair<int, int>> visited;
    
    std::cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
        std::cin >> row_moves;
        std::vector<char> row;
        for (int j = 0; j < cols; j++) {
            row.push_back(row_moves[j]);
        }
        grid.push_back(row);
    }

    r = 0; c = 0;
    int count = 0;
    while (true) {

        std::pair<int, int> position(r,c);
        if (visited.find(position) != visited.end()) {
            std::cout << "Lost" << std::endl;
            break;
        }
        visited.insert(position);

        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            std::cout << "Out" << std::endl;
            break;
        }

        move = grid[r][c];
        if (move == 'N') r--;
        else if (move == 'S') r++;
        else if (move == 'W') c--;
        else if (move == 'E') c++;
        else if (move == 'T') {
            std::cout << count << std::endl;
            break;
        }

        count++;
    }

    return 0;
}