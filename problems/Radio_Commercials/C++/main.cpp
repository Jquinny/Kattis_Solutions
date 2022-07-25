#include <iostream>
using namespace std;

int num;
int price;
int students;
int prof;
int maxNow = 0;
int maxEnd = 0;

int profit() {
    cin >> students;
    prof = students - price;
    return prof;
}

int main() {

    cin >> num >> price;

    for (int i = 0; i < num; i++) {
        profit();
        maxEnd = maxEnd + prof;

        if (maxEnd < 0) {
            maxEnd = 0;
        }
        if (maxNow < maxEnd) {
            maxNow = maxEnd;
        }
    }

    cout << maxNow << endl;

    return 0;
}