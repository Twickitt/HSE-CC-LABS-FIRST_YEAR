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


