#include "Includes/node.hpp"

// Constructor
Node2::Node2(int year) {
    this->year = year;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1; // Initialized to 1 because it's a new sheet.
}

// Display the value of the node.
void Node2::display_value() {
    cout << "Year: " << year << endl;
}
