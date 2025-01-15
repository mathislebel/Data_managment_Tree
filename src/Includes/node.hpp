#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node2 {
public:
    int year;           // Données du nœud
    Node2* left;        // Pointeur vers le sous-arbre gauche
    Node2* right;       // Pointeur vers le sous-arbre droit
    int height;         // Hauteur du nœud pour équilibrer l'arbre

    // Constructeur
    Node2(int year);
    // Méthodes auxiliaires (optionnel, dépend des besoins)
    void display_value(); // Affiche la valeur du nœud
};

#endif
