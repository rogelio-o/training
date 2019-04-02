#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// O(n^2)
void solve(int n, int **arr) {
    for(int layer = 0; layer < n / 2; layer++) {
        int start = layer;
        int end = n - 1 - layer;

        for(int pivot = 0; pivot < (end - start); pivot++) {
            int aux = arr[end][start + pivot];
            arr[end][start + pivot] = arr[start + pivot][start];
            arr[start + pivot][start] = arr[start][end - pivot];
            arr[start][end - pivot] = arr[end - pivot][end];
            arr[end - pivot][end] = aux;
        }
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        int n;
        cin >> n;

        int **matrix;
        matrix = new int*[n];
        for(int i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for(int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        solve(n, matrix);
        cout << "Case #" << problemIndex << ":\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
}