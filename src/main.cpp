#include <iostream>
#include <string>
#include "includes/bst.hpp"

using namespace std;

// Prototypes des fonctions
void insert(Node *&root, int data);
void printTree(Node *root, string indent, bool last);

int main() {
    Node *root = NULL;

    // Insertion de plusieurs valeurs dans l'arbre
    for (int i = 10; i <= 660; i += 10) {
        insert(root, i);
    }

    // Affichage de l'arbre
    printTree(root, "", true);

    return 0;
}
