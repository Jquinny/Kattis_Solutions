#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    
    int k = 0;
    std::string rank;
    std::unordered_map<char, int> mymap;
    
    // taking in inputs
    for (int i = 0; i < 5; i++) {
        std::cin >> rank;
        mymap[rank[0]]++;
        if (mymap[rank[0]] > k) {
            k = mymap[rank[0]];
        }
    }

    std::cout << k << std::endl;
    
    return 0;
}