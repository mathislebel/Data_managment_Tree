#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node2 {
public:
    int year;           // Node data.
    Node2* left;        // Pointer to the left subtree.
    Node2* right;       // Pointer to the right subtree.
    int height;         // Node height for balancing the tree.

    // Constructor
    Node2(int year);
    // Auxiliary methods (optional, depends on the needs).
    void display_value(); // Display the value of the node.

};

#endif
