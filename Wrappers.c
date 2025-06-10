#include "Wrappers.h"

int linear_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Linear_Search(students, size, key);
}

int tree_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Bin_Search_Tree(root, key);
}