#include "Free_Tree.h"
#include <stdlib.h>

void Free_Tree(TreeNode* root){
    if(!root){
        return;
    Free_Tree(root->left);
    Free_Tree(root->right);
    free(root);
    }
}