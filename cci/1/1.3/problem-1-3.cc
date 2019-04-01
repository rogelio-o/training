#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// ---- UTILS ---- //

vector<string> getParams(string str, int numParams) {
    vector<string> result(numParams);

    size_t pos = 0;
    int i = 0;
    while ((pos = str.find(",")) != string::npos) {
        result[i] = str.substr(0, pos);
        str.erase(0, pos + 1);
        i++;
    }
    result[i] = str.substr(0, pos);

    return result;
}

// ---- PROBLEM ---- //

// O(n)
void solve(string &str, int len) {
    for(int i = len - 1, j = str.size() - 1; i >= 0; i--) {
        char c = str[i];

        if(c == ' ') {
            str[j - 2] = '%';
            str[j - 1] = '2';
            str[j] = '0';

            j -= 3;
        } else {
            str[j] = c;

            j -= 1;
        }
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string problem;
        cin.ignore();
        getline(cin, problem);

        vector<string> params = getParams(problem, 2);
        string str = params[0];
        int len = stoi(params[1]);

        solve(str, len);
        cout << "Case #" << problemIndex << ": " << str << "\n";
    }
}