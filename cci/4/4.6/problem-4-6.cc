#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../utils/binary-search-tree-node.h"

using namespace std;

BinarySearchTreeNode * solve(BinarySearchTreeNode * current) {
    BinarySearchTreeNode * node = current->parent;
    BinarySearchTreeNode * prev = current;

    while(node != NULL && node->right != NULL && node->right == prev) {
        prev = node;
        node = node->parent;
    }
    
    return node;
}

BinarySearchTreeNode * readNode(BinarySearchTreeNode * parent) {
    int value;
    cin >> value;

    if(value == -1) {
        return NULL;
    } else {
        BinarySearchTreeNode * root = new BinarySearchTreeNode(value);
        root->left = readNode(root);
        root->right = readNode(root);
        root->parent =  parent;

        return root;
    }
}

BinarySearchTreeNode * findCurrent(int currentValue, BinarySearchTreeNode * root) {
    if(root == NULL) {
        return NULL;
    } else if(root->value == currentValue) {
        return root;
    } else if(root->value > currentValue) {
        return findCurrent(currentValue, root->left);
    } else {
        return findCurrent(currentValue, root->right);
    }
}

int main()
{
    int numProblems;
    cin >> numProblems;

    for(int problemIndex = 1; problemIndex <= numProblems; problemIndex++) {
        BinarySearchTreeNode * root = readNode(NULL);

        int currentValue;
        cin >> currentValue;
        BinarySearchTreeNode * current = findCurrent(currentValue, root);
        
        BinarySearchTreeNode * ansNode = solve(current);
        string ans = "";
        if(ansNode != NULL) {
            ans = to_string(ansNode->value);
        }

        cout << "Case #" << problemIndex << ": " << ans << "\n";
    }
}