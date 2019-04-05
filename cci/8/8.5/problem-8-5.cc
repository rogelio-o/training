#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int solve(int a, int b) {
    if(a < b) {
        return solve(b, a);
    } else if(b == 1) {
        return a;
    } else if(b == 2) {
        return a + a;
    }

    int lastBit = b & 0x1;
    if(lastBit == 0) {
        int newA = a << 1;
        int newB = b >> 1;
        return newA + solve(a, newB);
    } else {
        return a + solve(a, b - 1);
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int a;
        cin >> a;
        int b;
        cin >> b;

        string ans = to_string(solve(a, b));
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}