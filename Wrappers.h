#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "Student_Struct.h"
#include "TreeNode_Struct.h"
#include "Linear_Search.h"
#include "Linear_Search_With_Any_Case.h"
#include "Bin_Search_Tree.h"
#include "Bin_Search_Tree_With_Any_Case.h"


int linear_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Linear_Search(students, size, key);
}

int tree_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Bin_Search_Tree(root, key);
}

int linear_search_wrapper_1(Student* students, TreeNode* root, int size, char* key) {
    return Linear_Search_With_Any_Case(students, size, key);
}

int tree_search_wrapper_1(Student* students, TreeNode* root, int size, char* key) {
    return Bin_Search_Tree_With_Any_Case(root, key);
}

#endif