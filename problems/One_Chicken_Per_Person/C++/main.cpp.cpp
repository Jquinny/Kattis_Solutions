#include <iostream>

int main() {

    int N, M, diff = 0;
    std::cin >> N >> M;

    if (N > M) {
        diff = N - M;
        std::cout << "Dr. Chaz needs " << diff << " more " << (diff == 1 ? "piece" : "pieces") << " of chicken!" << std::endl;
    } else {
        diff = M - N;
        std::cout << "Dr. Chaz will have " << M - N << (diff == 1 ? " piece" : " pieces") << " of chicken left over!" << std::endl;
    }

    return 0;
}