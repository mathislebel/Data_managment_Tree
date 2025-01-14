#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Structure du noeud
struct Node {
    int data;           // Donnée du noeud
    Node *left;         // Pointeur vers le sous-arbre gauche
    Node *right;        // Pointeur vers le sous-arbre droit
    int height;         // Hauteur du noeud
};

// Fonctions pour manipuler l'arbre
Node *newNode(int data);
int height(Node *node);
int getBalance(Node *node);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
void insert(Node *&root, int data);
void printTree(Node *root, string indent, bool last);

#endif
