#include "Bin_Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Free_Tree(TreeNode* root){
    if(!root)
        return;
    Free_Tree(root->left);
    Free_Tree(root->right);
    free(root);
    
}


TreeNode* Insertation_In_Tree(TreeNode* root, Student* s, int index){

    if(!root){
        TreeNode * node = malloc(sizeof(TreeNode));
        node->student = s;
        node->index = index; 
        node->left = node->right = NULL;
        return node;
    }

    int cmp = strcmp(s->name, root->student->name);
    if(cmp <0)
        root->left = Insertation_In_Tree(root->left, s, index);
    else
        root->right = Insertation_In_Tree(root->right, s, index);

    return root;    
}