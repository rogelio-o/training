#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

pair<int, int> solve(int n) {
    int b = 0;
    int aux = n;
    int acc = 1;

    while(aux > 0) {
        int digit = aux % 10;

        if(digit == 4) {
            b += acc;
        }

        aux = floor(aux / 10);
        acc *= 10;
    }

    return make_pair(n - b, b);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        pair<int, int> ans = solve(n);
        cout << "Case #" << problemIndex << ": " << ans.first << " " << ans.second << "\n";
    }
}