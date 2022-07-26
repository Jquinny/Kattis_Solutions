#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {

    char order[4];
    int arr[3] = {0, 0, 0};
    std::unordered_map<char, int> mymap;

    std::cin >> arr[0] >> arr[1] >> arr[2];
    std::sort(arr, arr + 3);
    
    mymap['A'] = arr[0];
    mymap['B'] = arr[1];
    mymap['C'] = arr[2];

    std::cin >> order;

    std::cout << mymap[order[0]] << " " << mymap[order[1]] << " " << mymap[order[2]] << std::endl;

    return 0;
}