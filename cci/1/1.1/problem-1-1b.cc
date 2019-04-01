#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// O(n^2)
bool solve(string str) {
    bool result = true;

    for(int i = 0; i < str.size(); i++) {
        char cI = str[i];

        for(int j = i + 1; j < str.size(); j++) {
            char cJ = str[j];

            if(cI == cJ) {
                result = false;
                break;
            }
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