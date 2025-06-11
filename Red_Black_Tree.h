#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include "Student_Struct.h"


typedef enum { RED, BLACK } Color;

typedef struct Node {
    Student* student;
    int index;  
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* Create_Node(Student* s, int index);

void Rotate_Left(Node** root, Node* x);

void Rotate_Right(Node** root, Node* y);

Node* Crash_Fix(Node* root, Node* z);

Node* Insert(Node* root, Student* s, int index);


int Red_Black_Search(Node* root, char* key);

void Free_RB_Tree(Node* root);

#endif

