#include "Includes/bst.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor
BST::BST() {
    root = nullptr;
}

// Insertion method in the tree.
void BST::insert(int year) {
    root = insert(root, year);
}

// Search method for a value in the tree.
bool BST::search(int year) {
    Node2* result = search(root, year);
    return result != nullptr; // If the result is non-null, the value has been found.
}

// Private recursive search method.
Node2* BST::search(Node2* node, int year) {
    if (node == nullptr || node->year == year) {
        return node;
    }
    if (year < node->year) {
        return search(node->left, year);
    }
    return search(node->right, year);
}

// Private recursive insertion method.
Node2* BST::insert(Node2* node, int year) {
    if (node == nullptr) {
        return new Node2(year);
    }

    if (year < node->year) {
        node->left = insert(node->left, year);
    } else if (year > node->year) {
        node->right = insert(node->right, year);
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = get_balance_factor(node);

    if (balance > 1 && year < node->left->year) {
        return right_rotate(node);
    }
    if (balance < -1 && year > node->right->year) {
        return left_rotate(node);
    }
    if (balance > 1 && year > node->left->year) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && year < node->right->year) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Right rotation.
Node2* BST::right_rotate(Node2* y) {
    Node2* x = y->left;
    Node2* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotation.
Node2* BST::left_rotate(Node2* x) {
    Node2* y = x->right;
    Node2* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Calculating the height of a node.
int BST::height(Node2* node) {
    return node == nullptr ? 0 : node->height;
}

// Calculating the balance factor of a node.
int BST::get_balance_factor(Node2* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

// Method to display the tree with a node to highlight.
void BST::display(int highlightYear) {
    display(root, "", true, highlightYear);  // Call with the year to highlight.
}

// Private method for displaying with highlighting.
void BST::display(Node2* node, string prefix, bool isLeft, int highlightYear) {
    if (node != nullptr) {
        cout << prefix;
        if (isLeft) {
            cout << "L----";
            prefix += "|   ";
        } else {
            cout << "R----";
            prefix += "    ";
        }

        // Display the year with brackets if it is the year to highlight.
        if (node->year == highlightYear) {
            cout << "[" << node->year << "]" << endl;
        } else {
            cout << node->year << endl;
        }

        display(node->left, prefix, true, highlightYear);
        display(node->right, prefix, false, highlightYear);
    }
}

void BST::Delete_node(Node2* node,int yearDelete){
    if (node == nullptr){
        cout << "node not find." << endl;
        return;
    }else{
        if (yearDelete == node->year){
            //if a node don't have child
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                node = nullptr;
                cout << "the Node is delete." << endl;
                return;
            }else{
            //if node have one child
            if(node->left == nullptr){
                Node2* temp = node;
                node = node->right;
                delete temp;
                cout << "The Node with one child is deleted." << endl;
                return;
            }if(node->right == nullptr){
                Node2* temp = node;
                node = node->left;
                delete temp;
                cout << "The Node with one child is deleted." << endl;
                return;
            }
            //if the node have two children
            else{
                Node2* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->year = temp->year;
                Delete_node(node->right, temp->year);
                cout << "The Node with two children is replaced and deleted." << endl;
                return;
                }
            }
        }else{
            if(yearDelete < node->year){
                return Delete_node(node->left, yearDelete);
            }else{
                return Delete_node(node->right, yearDelete);
            }
        }
    }
}