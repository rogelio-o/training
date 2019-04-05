#pragma once
#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

#include <iostream>

class BinarySearchTreeNode {
public:
    BinarySearchTreeNode(int value);
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
    BinarySearchTreeNode *parent;
    int value;
    void insert(BinarySearchTreeNode *node);
    std::string toString();
};

#endif