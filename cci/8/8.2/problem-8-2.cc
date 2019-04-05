#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool solve(int rows, int columns, int **matrix, int i, int j, vector<pair<int, int>> * result) {
    if(i < 0 || j < 0 || i >= rows || j >= columns) {
        return false;
    } else if(matrix[i][j] == 1) {
        return false;
    } else if(i == (rows - 1) && j == (columns - 1)) {
        result->push_back(make_pair(i, j));
        return true;
    }

    bool bottom = solve(rows, columns, matrix, i + 1, j, result);
    if(bottom) {
        result->push_back(make_pair(i, j));
        return true;
    }

    bool right = solve(rows, columns, matrix, i, j + 1, result);
    if(right) {
        result->push_back(make_pair(i, j));
        return true;
    }

    return false;
}

vector<pair<int, int>> solve(int rows, int columns, int **matrix) {
    vector<pair<int, int>> result;

    solve(rows, columns, matrix, 0, 0, &result);

    return result;
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int rows;
        cin >> rows;

        int columns;
        cin >> columns;

        int **matrix;
        matrix = new int*[rows];
        for(int i = 0; i < rows; i++) {
            matrix[i] = new int[columns];
            for(int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<pair<int, int>> ans = solve(rows, columns, matrix);
        cout << "Case #" << problemIndex << ":\n";
        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << "(" << ans[i].first << ", " << ans[i].second << ")\n";
        }
    }
}