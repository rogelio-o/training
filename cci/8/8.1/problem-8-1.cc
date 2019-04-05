#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int solve(int n) {
    if(n == 0) {
        return 1;
    } else if(n < 0) {
        return 0;
    }

    int result = 0;
    result += solve(n - 1);
    result += solve(n - 2);
    result += solve(n - 3);

    return result;
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        int ans = solve(n);
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}