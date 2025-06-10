#include "Add_Student_To_Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TreeNode* Add_Student_To_Tree(TreeNode* root, Student* s, int index) {
    if (!root) {
        TreeNode* node = malloc(sizeof(TreeNode));
        if (!node) {
            printf("Ошибка выделения памяти для узла дерева\n");
            return NULL;
        }
        node->student = s;
        node->index = index;
        node->left = node->right = NULL;
        return node;
    }

    int cmp = strcmp(s->name, root->student->name);
    if (cmp < 0) {
        root->left = Add_Student_To_Tree(root->left, s, index);
    } else {
        root->right = Add_Student_To_Tree(root->right, s, index);
    }

    return root;
}
