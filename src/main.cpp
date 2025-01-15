#include "Includes/bst.hpp"
#include "Includes/node.hpp"

int main() {
    BST bst;

    // Insert the years from 1900 to 2025.
    for (int year = 1900; year <= 2025; ++year) {
        bst.insert(year);
    }

    // Choose a year to highlight.
    int yearToHighlight = 1930;

    // Search for the year.
    if (bst.search(yearToHighlight)) {
        cout << "L'année " << yearToHighlight << " a été trouvée dans l'arbre." << endl;
    } else {
        cout << "L'année " << yearToHighlight << " n'est pas dans l'arbre." << endl;
    }

    // Display the tree with the highlighted year.
    cout << "Arbre binaire de recherche avec l'année " << yearToHighlight << " mise en surbrillance :" << endl;
    bst.display(yearToHighlight);

    //Delete a year from the tree.
    bst.Delete_node(bst.root,2023);

    return 0;
}
