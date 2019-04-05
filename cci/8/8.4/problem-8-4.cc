#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

void solve(int n, int *array, int index, vector<vector<int>> * result) {
    if(index >= n) {
        return;
    }

    int value = array[index];
    int size = result->size();
    for(int i = 0; i < size; i++) {
        vector<int> newSet(result->at(i));
        newSet.push_back(value);

        result->push_back(newSet);
    }

    vector<int> newSet;
    newSet.push_back(value);
    result->push_back(newSet);

    solve(n, array, index + 1, result);
}

vector<vector<int>> solve(int n, int *array) {
    vector<vector<int>> result;

    solve(n, array, 0, &result);

    return result;
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

        vector<vector<int>> ans = solve(n, array);
        cout << "Case #" << problemIndex << ":\n";
        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << ", ";
            }
            cout << "\n";
        }
    }
}