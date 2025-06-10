#ifndef TREENODE_STRUCT_H
#define TREENODE_STRUCT_H

#include "Student_Struct.h"

typedef struct TreeNode{
    Student* student;
    int index;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

#endif