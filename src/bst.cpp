#include "Includes/bst.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructeur
BST::BST() {
    root = nullptr;
}

// Méthode d'insertion dans l'arbre
void BST::insert(int year) {
    root = insert(root, year);
}

// Méthode de recherche d'une valeur dans l'arbre
bool BST::search(int year) {
    Node2* result = search(root, year);
    return result != nullptr; // Si le résultat est non nul, la valeur a été trouvée
}

// Méthode privée de recherche récursive
Node2* BST::search(Node2* node, int year) {
    if (node == nullptr || node->year == year) {
        return node;
    }
    if (year < node->year) {
        return search(node->left, year);
    }
    return search(node->right, year);
}

// Méthode privée d'insertion récursive
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

// Rotation droite
Node2* BST::right_rotate(Node2* y) {
    Node2* x = y->left;
    Node2* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Rotation gauche
Node2* BST::left_rotate(Node2* x) {
    Node2* y = x->right;
    Node2* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Calcul de la hauteur d'un nœud
int BST::height(Node2* node) {
    return node == nullptr ? 0 : node->height;
}

// Calcul du facteur d'équilibre d'un nœud
int BST::get_balance_factor(Node2* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

// Méthode pour afficher l'arbre avec un nœud à surligner
void BST::display(int highlightYear) {
    display(root, "", true, highlightYear);  // Appel avec l'année à surligner
}

// Méthode privée d'affichage avec surlignage
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

        // Affichage de l'année avec des crochets si c'est l'année à surligner
        if (node->year == highlightYear) {
            cout << "[" << node->year << "]" << endl;
        } else {
            cout << node->year << endl;
        }

        display(node->left, prefix, true, highlightYear);
        display(node->right, prefix, false, highlightYear);
    }
}
