#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../utils/binary-search-tree-node.h"

using namespace std;

int solveRec(BinarySearchTreeNode * root) {
    if(root == NULL) {
        return 0;
    }

    int leftAns = solveRec(root->left);
    if(leftAns == -1) {
        return -1;
    }

    int rightAns = solveRec(root->right);
    if(rightAns == -1) {
        return -1;
    }

    int diff = abs(leftAns - rightAns);
    if(diff > 1) {
        return -1;
    }

    return diff + 1;
}

bool solve(BinarySearchTreeNode * root) {
    return solveRec(root) != -1;
}

BinarySearchTreeNode * readNode() {
    int value;
    cin >> value;

    if(value == -1) {
        return NULL;
    } else {
        BinarySearchTreeNode * root = new BinarySearchTreeNode(value);
        root->left = readNode();
        root->right = readNode();

        return root;
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        BinarySearchTreeNode * root = readNode();
        
        string ans = solve(root) ? "true" : "false";
        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}