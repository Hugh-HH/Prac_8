#include "Node.h"

#include <iostream>

Node::Node() {
    data = -99;
    next = nullptr;
}

int Node::get_data() { 
    return data;
}

void Node::set_data(int info) {
    this->data = info;
}

Node* Node::get_next() {
    return next;
}

void Node::set_Next(Node* info) {
    this->next = info;
}