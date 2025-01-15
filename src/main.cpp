#include "Includes/bst.hpp"
#include "Includes/node.hpp"

int main() {
    BST bst;

    // Insertion des années de 1900 à 2025
    for (int year = 1900; year <= 2025; ++year) {
        bst.insert(year);
    }

    // Choisir une année à surligner
    int yearToHighlight = 1930;

    // Recherche de l'année
    if (bst.search(yearToHighlight)) {
        cout << "L'année " << yearToHighlight << " a été trouvée dans l'arbre." << endl;
    } else {
        cout << "L'année " << yearToHighlight << " n'est pas dans l'arbre." << endl;
    }

    // Affichage de l'arbre avec l'année surlignée
    cout << "Arbre binaire de recherche avec l'année " << yearToHighlight << " mise en surbrillance :" << endl;
    bst.display(yearToHighlight);

    return 0;
}
