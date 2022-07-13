#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl;

int main() {

    int n, d;
    cin >> n;
    int * line = new int[n];
    line[0] = 1;

    for (int i = 2; i < n+1; i++) {
        cin >> d;
        line[d+1] = i;
    }

    for (int i = 0; i < n; i++) {
        if (i != n-1) {
            cout << line[i] << " ";
        } else {
            cout << line[i] << endl;
        }
    }

    return 0;
}