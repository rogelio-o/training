#pragma once
#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <iostream>

class LinkedListNode {
public:
    LinkedListNode(int value);
    LinkedListNode *next;
    LinkedListNode *prev;
    int value;
    std::string toString();
};

class LinkedList {
private:
    LinkedListNode *head, *tail;
public:
    LinkedList();
    void add(int value);
    std::string toString();
};

#endif