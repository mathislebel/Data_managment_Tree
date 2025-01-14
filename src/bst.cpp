/*
here is the bst.cpp file
the continuity of the bst.hpp file
*/

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

}
