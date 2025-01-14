#include "includes/bst.hpp"

// Fonction pour insérer une nouvelle clé dans l'arbre BST
void insert(Node *&root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    }

    // Mise à jour de la hauteur
    root->height = 1 + max(height(root->left), height(root->right));

    // Vérification du facteur d'équilibre
    int balance = getBalance(root);

    // Rotation droite
    if (balance > 1 && data < root->left->data) {
        root = rightRotate(root);
    }

    // Rotation gauche
    if (balance < -1 && data > root->right->data) {
        root = leftRotate(root);
    }

    // Double rotation gauche-droite
    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }

    // Double rotation droite-gauche
    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
}

// Autres fonctions auxiliaires (inchangées)
Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node *node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(Node *node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

void printTree(Node *root, string indent, bool last) {
    if (root != NULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->data << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}
