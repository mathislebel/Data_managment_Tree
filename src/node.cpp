#include "Includes/node.hpp"

// Constructeur
Node2::Node2(int year) {
    this->year = year;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1; // Initialisé à 1 car c'est une nouvelle feuille
}

// Affiche la valeur du nœud
void Node2::display_value() {
    cout << "Year: " << year << endl;
}
