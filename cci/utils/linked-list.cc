#include "linked-list.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

LinkedListNode::LinkedListNode(int v) {
    value = v;
}

std::string LinkedListNode::toString() {
    return "[" + std::to_string(value) + "]";
}

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::add(int value) {
    LinkedListNode * node = new LinkedListNode(value);
    if(head == NULL) {
        head = node;
    }
    if(tail != NULL) {
        tail->next = node;
    }
    node->prev = tail;
    tail = node;
}

std::string LinkedList::toString() {
    std::string result = "";
    LinkedListNode * node = head;
    while(node != NULL) {
        result += node->toString() + ", ";
        node = node->next;
    }

    return result;
} 