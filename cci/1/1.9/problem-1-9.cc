#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// O(n)
bool isSubstring(string strA, string strB) {
    if(strA.size() != strB.size()) {
        return false;
    } else {
        return (strB + strB).find(strA) != string::npos;
    }
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

        string ans = isSubstring(strA, strB) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}