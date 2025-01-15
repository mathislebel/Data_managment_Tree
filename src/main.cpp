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
        cout << "The year " << yearToHighlight << " has been found in the tree." << endl;
    } else {
        cout << "The year " << yearToHighlight << " is not in the tree." << endl;
    }

    // Display the tree with the highlighted year.
    cout << "Binary search tree with the year " << yearToHighlight << "is Highlighting : " << endl;
    bst.display(yearToHighlight);

    //Delete a year from the tree.
    bst.Delete_node(bst.root,2023);
    cout << "Binary search tree with the year " << yearToHighlight << "is Highlighting : " << endl;
    bst.display(yearToHighlight);
    return 0;
}
