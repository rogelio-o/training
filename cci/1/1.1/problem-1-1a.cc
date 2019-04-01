#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

// O(n)
bool solve(string str) {
    set<char> previousCharacters;
    bool result = true;

    for(int i = 0; i < str.size(); i++) {
        char c = str[i];

        if(previousCharacters.insert(c).second == false) {
            result = false;
            break;
        }
    } 

    return result;
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string str;
        cin >> str;

        string ans = solve(str) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}