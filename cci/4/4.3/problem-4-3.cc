#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "../../utils/binary-search-tree-node.h"
#include "../../utils/linked-list.h"

using namespace std;

void solve(BinarySearchTreeNode * root, vector<LinkedList *> * result, int deep) {
    if(root == NULL) {
        return;
    }

    if(result->size() <= deep) {
        result->push_back(new LinkedList());
    }
    
    result->at(deep)->add(root->value);

    solve(root->left, result, deep + 1);
    solve(root->right, result, deep + 1);
}

vector<LinkedList *> solve(BinarySearchTreeNode * root) {
    vector<LinkedList *> result;

    solve(root, &result, 0);

    return result;
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
        
        vector<LinkedList *> ans = solve(root);
        cout << "Case #" << problemIndex << ":" << "\n";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i]->toString() << "\n";
        }
    }
}