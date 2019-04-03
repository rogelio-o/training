#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../utils/binary-search-tree-node.h"

using namespace std;

BinarySearchTreeNode * solve(int start, int end, int *array, int index) {
    BinarySearchTreeNode * root = new BinarySearchTreeNode(array[index]);
    int leftIndex = start + (index - start) / 2;
    int rightIndex = index + (end - index) / 2;

    if(leftIndex != index) {
        root->left = solve(start, index - 1, array, leftIndex);
    }

    if(rightIndex != index) {
        root->right = solve(index + 1, end, array, rightIndex);
    }

    return root;
}

BinarySearchTreeNode * solve(int n, int *array) {
    BinarySearchTreeNode * root = new BinarySearchTreeNode(10);
    root->left = new BinarySearchTreeNode(5);

    return solve(0, n - 1, array, ceil(n / 2) - 1);
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

        BinarySearchTreeNode * node = solve(n, array);
        cout << "Case #" << problemIndex << ": " << node->toString() << "\n";
    }
}