#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool checkIsModification(string strA, string strB) {
    bool result = true;
    bool diffAllowed = true;

    for(int i = 0; i < strA.size(); i++) {
        if(strA[i] != strB[i]) {
            if(!diffAllowed) {
                result = false;
                break;
            } else {
                diffAllowed = false;
            }
        }
    }

    return result;
}

bool checkIsAdd(string strA, string strB) {
    if(strA.size() - strB.size() > 1) {
        return false;
    }

    bool result = true;
    bool diffAllowed = true;

    for(int i = 0, j = 0; i < strA.size() && j < strB.size(); i++, j++) {
        if(strA[i] != strB[j]) {
            if(!diffAllowed) {
                result = false;
                break;
            } else {
                diffAllowed = false;
                j--;
            }
        }
    }

    return result;
}

bool checkIsRemove(string strA, string strB) {
    return checkIsAdd(strB, strA);
}

bool solve(string strA, string strB) {
    if(strA.size() == strB.size()) {
        return checkIsModification(strA, strB);
    } else if(strA.size() > strB.size()) {
        return checkIsAdd(strA, strB);
    } else {
        return checkIsRemove(strB, strA);
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        string strA;
        string strB;
        cin >> strA;
        cin >> strB;

        string ans = solve(strA, strB) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}