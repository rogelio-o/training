#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

bool allZerosInMap(map<char, int> characters) {
    bool result = true;

    for (map<char,int>::iterator it = characters.begin(); it != characters.end(); ++it) {
        if(it->second != 0) {
            result = false;
            break;
        }
    }

    return result;
}

void addAmountToCharacterInMap(map<char, int> &characters, string str, int amount) {
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];

        characters[c] = characters[c] + amount;
    }
}

bool solve(string strA, string strB) {
    if(strA.size() != strB.size()) {
        return false;
    }

    map<char, int> characters;

    addAmountToCharacterInMap(characters, strA, 1);

    addAmountToCharacterInMap(characters, strB, -1);

    return allZerosInMap(characters);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string strA;
        cin >> strA;
        string strB;
        cin >> strB;

        string ans = solve(strA, strB) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}