#ifndef NODE_HPP //avoids redefinition
#define NODE_HPP

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

};



void insert_node(int val, int value); //insert a new element
void display_value(); //show the Node's value

#endif