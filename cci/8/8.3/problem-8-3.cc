#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int solve(int *array, int start, int end) {
    if(start > end) {
        return -1;
    } else if (start == end) {
        if(array[start] == start) {
            return start;
        } else {
            return -1;
        }
    }

    int middle = start + ((end - start) / 2);
    int value = array[middle];

    if(value == middle) {
        return value;
    } else if(value < middle) {
        return solve(array, middle + 1, end);
    } else {
        return solve(array, start, middle - 1);
    }
}

int solve(int n, int *array) {
    return solve(array, 0, n - 1);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        int array[n];
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        int solution = solve(n, array);
        string ans = "";
        if(solution >= 0) {
            ans = to_string(solution);
        }
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}