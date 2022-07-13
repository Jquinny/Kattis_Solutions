#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

int num;
std::string adventure;
std::unordered_map<char, char> mymap = {
    {'b', '$'},
    {'t', '|'},
    {'j', '*'}
};

int main() {

    std::cin >> num;
    for (int i = 0; i < num; i++) {
        std::cin >> adventure;
        std::stack<char> items;
        for (int j = 0; j < adventure.size(); j++) {
            if (adventure[j] != '.') {
                if ('a' <= adventure[j] && adventure[j] <= 'z') {
                    if (!items.empty() && mymap[adventure[j]] == items.top()) {
                        items.pop();
                    } else {
                        std::cout << "NO" << std::endl;
                        break;
                    }
                } else {
                    items.push(adventure[j]);
                }
            }
            if (j == adventure.size() - 1) {
                if (items.empty()) {
                    std::cout << "YES" << std::endl;
                } else {
                    std::cout << "NO" << std::endl;
                }
            }
        }
    }

    return 0;
}
