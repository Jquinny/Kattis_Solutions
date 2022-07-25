#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

using namespace std;

string inputLine;
string newstr;
vector<string> words;
set<string> cwords;
int len;
int counter = 0;

int main() {

    // reads in the input, splits the strings at spaces and then adds those split strings to a string vector
    while (getline(cin, inputLine) && !inputLine.empty()) {
        istringstream ss(inputLine);
        for (inputLine; ss >> inputLine;) {
            words.push_back(inputLine);
        }
    }

    // gets size of words vector
    len = words.size();

    // loops over length of words vector, then a nested loop over the length of words again to concatenate the words and then add them to a set
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (words[i] != words[j]) {
                newstr = words[i] + words[j];
                if (cwords.find(newstr) == cwords.end()) {
                    cwords.insert(newstr);
                }
            }
        }
    }

    // iterate over the set and use an iterator to print out all of the elements of the set (will already be in alphabetical order because it is an ordered set)
    for (auto iter = cwords.begin(); iter != cwords.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;

}