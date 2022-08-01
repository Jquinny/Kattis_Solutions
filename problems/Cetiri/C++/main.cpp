#include <iostream>
#include <algorithm>

int main() {

    int diff1, diff2;
    int arr[3];
    std::cin >> arr[0] >> arr[1] >> arr[2];

    std::sort(arr, arr+3);
    diff1 = arr[1] - arr[0];
    diff2 = arr[2] - arr[1];

    if (diff1 == diff2) {
        std::cout << arr[2] + diff1 << std::endl;
    } else if (diff1 > diff2) {
        std::cout << arr[0] + diff1/2 << std::endl;
    } else {
        std::cout << arr[1] + diff2/2 << std::endl;
    }

    return 0;
}