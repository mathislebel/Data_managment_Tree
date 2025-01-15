#include <iostream>
#include <string>
#include "Includes/bst.hpp"
#include "Includes/node.hpp"

using namespace std;

// Prototypes des fonctions
void insert(Node *&root, int data);
void printTree(Node *root, string indent, bool last);

int main() {
    Node *root = NULL;
     
    // node creation
    Node2 *root2 = new Node2(50);



    // Insertion de plusieurs valeurs dans l'arbre
    for (int i = 10; i <= 660; i += 10) {
        insert(root, i);
    }

    // Affichage de l'arbre
    printTree(root, "", true);

    return 0;
}
