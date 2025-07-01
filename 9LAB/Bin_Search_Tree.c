#include "Bin_Search_Tree.h"
#include "To_Lower.h"
#include <string.h>
#include <stdio.h>

#define MAX_LEN_KEY 100


int Bin_Search_Tree(TreeNode* root, char* key){
    
    
    if (!root){
        return -1;
    }

    int cmp = strcmp(key, root->student->name);
    if (cmp == 0)
        return root->index;
    else if (cmp < 0)
        return Bin_Search_Tree(root->left, key);
    else
        return Bin_Search_Tree(root->right, key);
}


int Bin_Search_Tree_With_Any_Case(TreeNode* root, char* key){
    
    char lower_key[MAX_LEN_KEY];
    char lower_name[MAX_LEN_KEY];

    if (!root){
        return -1;
    }

    To_Lower(key, lower_key);
    To_Lower(root->student->name, lower_name);

    int cmp = strcmp(lower_key, lower_name);
    if (cmp == 0)
        return root->index;
    else if (cmp < 0)
        return Bin_Search_Tree_With_Any_Case(root->left, key);
    else
        return Bin_Search_Tree_With_Any_Case(root->right, key);
}