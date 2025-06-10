#include "Bin_Search_Tree.h"
#include <string.h>

int Bin_Search_Tree(TreeNode* root, char* key){
    
    if(!root)
        return -1;
    
        int cmp = strcmp(key, root->student->name);
        
        if(cmp == 0){
            return root->index;
        }

        else if(cmp < 0){
            return Bin_Search_Tree(root->left, key);
        }

        else   
            return Bin_Search_Tree(root->right, key);
}
