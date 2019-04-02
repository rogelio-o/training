#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

string solve(string str) {
    if(str == "") {
        return "";
    }
    
    stringstream ss;

    int buffer = 0;
    char prevChar = '.';
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];

        if(prevChar != '.' && prevChar != c) {
            ss << prevChar;
            if(buffer > 1) {
                ss << buffer;
            }
            buffer = 0;
        }

        prevChar = c;
        buffer++;
    }

    ss << prevChar;
    if(buffer > 1) {
        ss << buffer;
    }

    return ss.str();
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string str;
        cin >> str;

        string ans = solve(str);
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}