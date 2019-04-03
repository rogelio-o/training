#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool solve(int n, int i, int **matrix, int end) {
    if(i == end) {
        return true;
    }

    int result = false;
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 1) {
            if(solve(n, j, matrix, end)) {
                result = true;
                break;
            }
        }
    }

    return result;
}

bool solve(int n, int **matrix, int start, int end) {
    return solve(n, start - 1, matrix, end - 1);
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        int start;
        int end;
        cin >> n;
        cin >> start;
        cin >> end;

        int **matrix;
        matrix = new int*[n];

        for(int i = 0; i < n; i++) {
            matrix[i] = new int[n];

            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        string ans = solve(n, matrix, start, end) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}