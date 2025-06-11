#include "Red_Black_Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* Create_Node(Student* s, int index) {
    Node* node = malloc(sizeof(Node));
    node->student = s;
    node->index = index;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void Rotate_Left(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;
    if (!x->parent)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void Rotate_Right(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;
    if (!y->parent)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

Node* Crash_Fix(Node* root, Node* z) {
    while (z != root && z->parent->color == RED) {
        Node* grandparent = z->parent->parent;

        if (z->parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } 
            
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    Rotate_Left(&root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                Rotate_Right(&root, grandparent);
            }
        } 
        
        else {
            Node* uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            }
            
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    Rotate_Right(&root, z);
                }
                z->parent->color = BLACK;
                grandparent->color = RED;
                Rotate_Left(&root, grandparent);
            }
        }
    }
    root->color = BLACK;
    return root;
}

Node* Insert(Node* root, Student* s, int index) {
    Node* z = Create_Node(s, index);
    Node* y = NULL;
    Node* x = root;

    while (x) {
        y = x;
        if (strcmp(s->name, x->student->name) < 0)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (!y)
        root = z;
    else if (strcmp(s->name, y->student->name) < 0)
        y->left = z;
    else
        y->right = z;

    return Crash_Fix(root, z);
}



int Red_Black_Search(Node* root, char* key) {
    while (root) {
        int cmp = strcmp(key, root->student->name);
        if (cmp == 0)
            return root->index;
        else if (cmp < 0)
            root = root->left;
        else
            root = root->right;
    }
    return -1;
}

void Free_RB_Tree(Node* root) {
    if (!root)
        return;

    Free_RB_Tree(root->left);
    Free_RB_Tree(root->right);
    free(root);
}