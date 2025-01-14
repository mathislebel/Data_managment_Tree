/*
here we will implement the functions of the class bst  
here is the hpp file
il dois contenir les fonctions de la classe bst pour pouvoir les coder ensuite dans le fichier cpp

*/

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// struct Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

// class BST
void insert(Node *&root, int data);

void deleteNode(Node *&root, int data);

void printTree(Node *root, std::string indent, bool last);

Node *search(Node *root, int data);

Node *minValueNode(Node *node);

int height(Node *node);

int getBalance(Node *node);

Node *rightRotate(Node *y);

Node *leftRotate(Node *x);

Node *newNode(int data);


#endif // BST_HPP