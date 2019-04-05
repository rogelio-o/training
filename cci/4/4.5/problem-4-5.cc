#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../utils/binary-search-tree-node.h"

using namespace std;

bool solve(BinarySearchTreeNode * root) {
    if(root == NULL) {
        return true;
    }

    bool leftAns = solve(root->left);
    if(!leftAns) {
        return false;
    }

    bool rightAns = solve(root->right);
    if(!rightAns) {
        return false;
    }

    if(root->left != NULL && root->left->value > root->value) {
        return false;
    }

    if(root->right != NULL && root->right->value < root->value) {
        return false;
    }

    return true;
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