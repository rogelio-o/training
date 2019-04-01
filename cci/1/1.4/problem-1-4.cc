#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

bool solve(string str) {
    // Remove white space and to lowercase
    str.erase(str.find(' '), 1);
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    map<char, int> characters;
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        characters[c] = characters[c] + 1;
    }

    bool result = true;
    bool canBeOdd = str.size() % 2 != 0;
    for (map<char,int>::iterator it = characters.begin(); it != characters.end(); ++it) {
        if(it->second % 2 != 0) {
            if(!canBeOdd) {
                result = false;
                break;
            } else {
                canBeOdd = false;
            }
        }
    }

    return result;
}

int main()
{
    int numProblems;
    cin >> numProblems;
    cin.ignore();

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string str;
        getline(cin, str);

        string ans = solve(str) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}