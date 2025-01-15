/*
here is the hpp file that will be used in the node.cpp file
*/

#ifndef NODE_HPP //avoids redefinition
#define NODE_HPP

#include <iostream>

using namespace std; 

class Node2{
    public:
        int value; //value of the node
        Node2 *left; //pointer to the left subtree
        Node2 *right; //pointer to the right subtree

        Node2(int val); //constructor
        void insert_node(int val, int value); //insert a node
        void display_value(); //display the value of the node
};


#endif