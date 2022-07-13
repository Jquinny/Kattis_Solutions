#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int num;
int counter = 0;
unordered_set<string> hashTable;

int main() {

    cin >> num;

    string all[num];
    string teamName[num];
    string uni[num];
    vector<string> top12;

    // getting the university name and the team name
    for (int k = 0; k < num; k++) {
        cin >> uni[k] >> teamName[k];
    }

    // concatinates the strings and then checks to see if the university is in the top 12 or not
    for (int i = 0; i < num; i++) {
        all[i] = uni[i] + " " + teamName[i];

        if (hashTable.find(uni[i]) != hashTable.end()) {
            counter++;
        }
        else {
            hashTable.insert(uni[i]);
            top12.push_back(all[i]);
        }
    }

    // printing out the top 12
    int len = top12.size();
    if (len < 12) {
        for (int h = 0; h < len; h++) {
            cout << top12[h] << endl;
        }
    }
    else {
        for (int j = 0; j < 12; j++) {
            cout << top12[j] << endl;
        }
    }

    return 0;

}