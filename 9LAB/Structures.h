#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct{
    char name[30];
    char faculty[30];
    char group[20];
    float GPA;
} Student;


typedef struct TreeNode{
    Student* student;
    int index;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

#endif