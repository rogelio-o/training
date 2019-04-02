#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

// O(mn)
void solve(int m, int n, int **matrix) {
    vector<pair<int,int>> zeros;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                zeros.push_back(make_pair(i, j));
            }
        }
    }

    for(int zIndex = 0; zIndex < zeros.size(); zIndex++) {
        pair<int, int> zeroPosition = zeros[zIndex];

        for(int i = 0; i < m; i++) {
            matrix[i][zeroPosition.second] = 0;
        }

        for(int j = 0; j < n; j++) {
            matrix[zeroPosition.first][j] = 0;
        }
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int m;
        cin >> m;
        int n;
        cin >> n;

        int **matrix;
        matrix = new int*[m];
        for(int i = 0; i < m; i++) {
            matrix[i] = new int[n];
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        solve(m, n, matrix);
        cout << "Case #" << problemIndex << ":\n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
}