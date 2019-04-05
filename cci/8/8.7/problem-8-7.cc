#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<string> solve(int index, string str) {
    if(index >= str.size()) {
        vector<string> result;
        result.push_back("");
        return result;
    }

    vector<string> prevResult = solve(index + 1, str);
    vector<string> result;
    char c = str[index];
    for(int i = 0; i < prevResult.size(); i++) {
        string prevStr = prevResult[i];

        for(int j = 0; j <= prevStr.size(); j++) {
            result.push_back(prevStr.substr(0, j) + c + prevStr.substr(j));
        }
    }

    return result;
}

vector<string> solve(string str) {
    return solve(0, str);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string str;
        cin >> str;

        vector<string> ans = solve(str);
        cout << "Case #" << problemIndex << ":\n";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ", ";
        }
        cout << "\n";
    }
}