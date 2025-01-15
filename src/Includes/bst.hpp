#ifndef BST_HPP
#define BST_HPP

#include "node.hpp"
#include <string>

class BST {
public:
    Node2* root;

    BST();
    void insert(int year);
    bool search(int year);
    void display(int highlightYear);  // Declaration with an argument for the year to highlight.
    void Delete_node(Node2* node,int yearDelete);

private:
    Node2* insert(Node2* node, int year);
    Node2* search(Node2* node, int year);
    Node2* right_rotate(Node2* y);
    Node2* left_rotate(Node2* x);
    int height(Node2* node);
    int get_balance_factor(Node2* node);
    void display(Node2* node, std::string prefix, bool isLeft, int highlightYear);  // Private method with 4 arguments.
};

#endif
