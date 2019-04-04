#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../../utils/binary-search-tree-node.h"

using namespace std;

BinarySearchTreeNode * solve(int start, int end, int *array) {
    int size = end - start;
    if(size < 0) {
        return  NULL;
    } else if(size == 0) {
        return new BinarySearchTreeNode(array[start]);
    }

    int middle = start + floor(size / 2);
    BinarySearchTreeNode * root = new BinarySearchTreeNode(array[middle]);

    root->left = solve(start, middle - 1, array);
    root->right = solve(middle + 1, end, array);

    return root;
}

BinarySearchTreeNode * solve(int n, int *array) {
    BinarySearchTreeNode * root = new BinarySearchTreeNode(10);
    root->left = new BinarySearchTreeNode(5);

    return solve(0, n - 1, array);
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