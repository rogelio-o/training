#include "binary-search-tree-node.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

BinarySearchTreeNode::BinarySearchTreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
}

void BinarySearchTreeNode::insert(BinarySearchTreeNode *node) {
    if(node->value > value) {
        if(right == NULL) {
            node->parent = this;
            right = node;
        } else {
            right->insert(node);
        }
    } else {
        if(left == NULL) {
            node->parent = this;
            left = node;
        } else {
            left->insert(node);
        }
    }
}

std::string BinarySearchTreeNode::toString() {
    std::string leftString;
    if(left == NULL) {
        leftString = "";
    } else {
        leftString = left->toString();
    }

    std::string rightString;
    if(right == NULL) {
        rightString = "";
    } else {
        rightString = right->toString();
    }

    return "(value: " + std::to_string(value) + ", left: " + leftString + ", right: " + rightString + ")";
}