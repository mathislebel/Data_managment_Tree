#include "includes/node.hpp" // Inclure le fichier d'en-tête

using namespace std;

// Constructeur
Node2::Node2(int val) {
    value = val;
    left = NULL;
    right = NULL;
}

// Méthode d'insertion de noeud
void Node2::insert_node(int val, int value) {
    if (val < value) {
        if (left == NULL) {
            left = new Node2(val);
        } else {
            left->insert_node(val, value);
        }
    } else if (val > value) {
        if (right == NULL) {
            right = new Node2(val);
        } else {
            right->insert_node(val,value);
        }
    }
}

// Méthode d'affichage de la valeur
void Node2::display_value() {
    cout << value << endl;
}
