#include <iostream>
using namespace std;

int num;
int dig;
int poop;
int sum;

int digSum(int x) {

    sum = 0;
    while (x > 0) {
        dig = x % 10;
        sum = dig + sum;
        x /= 10;
    }
    return sum;
}

int main() {

    cin >> num;
    while ((num % digSum(num)) != 0) { 
        num++;
    }
    cout << num << endl;
    return 0;

}
