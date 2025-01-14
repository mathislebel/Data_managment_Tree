#include "includes/bst.hpp"

using namespace std;

// function to insert a new node with given key in BST

void insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data < root->data )
    {
        insert(root -> left, data);
    }
    else if (data > root -> data)
    {
        insert(root -> right, data);
    }
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = getBalance(root);
    if (balance > 1 && data < root -> left -> data);
    {
        rightRotate(root);
    }
    if (balance < -1 && data > root -> right -> data);
    {
        leftRotate(root);
    }
    if (balance > 1 && data > root -> left -> data)
    {
        root -> left = leftRotate(root -> left);
    }
    if (balance < -1 && data < root -> right -> data)
    {
        root -> right = rightRotate(root -> right);
    }
}

// function to delete the node with given key in BST
void deleteNode(Node *&root, int data)
{
    if (root == NULL)
    {
        return;
    }
    if (data < root -> data)
    {
        deleteNode(root -> left, data);
    }
    else if (data > root -> data)
    {
        deleteNode(root -> right, data);
    }
    else
    {
        if (root -> left == NULL)
        {
            Node *temp = root -> right;
            delete root;
            root = temp;
        }
        else if (root -> right == NULL)
        {
            Node *temp = root -> left;
            delete root;
            root = temp;
        }
        else
        {
            Node *temp = minValueNode(root -> right);
            root -> data = temp -> data;
            deleteNode(root -> right, temp -> data);
        }
    }
    if (root == NULL)
    {
        return;
    }
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root -> left) >= 0)
    {
        rightRotate(root);
    }
    if (balance > 1 && getBalance(root -> left) < 0)
    {
        root -> left = leftRotate(root -> left);
        rightRotate(root);
    }
    if (balance < -1 && getBalance(root -> right) <= 0)
    {
        leftRotate(root);
    }
   if (balance < -1 && getBalance(root -> right) > 0)
    {
        root -> right = rightRotate(root -> right);
        leftRotate(root);
    }

}

// function to search a given key in BST
Node *search(Node *root, int data)
{
    if (root == NULL || root -> data == data)
    {
        return root;

    }
    if (root -> data < data)
    {
        return search(root -> right, data);
    }
    return search(root -> left, data);
}

// function to find the node with minimum value in BST
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current -> left != NULL)
    {
        current = current -> left;
    }
    return current;
}

// function to get the height of the node
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node -> height;
}

// function to get the balance factor of the node
int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node -> left) - height(node -> right);
}

// function to perform right rotation of the subtree
Node *rightRotate(Node *y)
{
    Node *x = y -> left;
    Node *T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    y -> height = 1 + max(height(y -> left), height(y -> right));
    x -> height = 1 + max(height(x -> left), height(x -> right));
    return x;
}

// function to perform left rotation of the subtree
Node *leftRotate(Node *X)
{
    Node *y = X -> right;
    Node *T2 = y -> left;
    y -> left = X;
    X -> right = T2;
    X -> height = 1 + max(height(X -> left), height(X -> right));
    y -> height = 1 + max(height(y -> left), height(y -> right));
    return y;
}

// function to create a new node with given key
Node *newNode(int data)
{
    Node *node = new Node();
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 1;
    return node;
}

// function to print the tree
void printTree(Node *root, string indent, bool last)
{
    if (root != NULL)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << root -> data << endl;
        printTree(root -> left, indent, false);
        printTree(root -> right, indent, true);
    }
}

