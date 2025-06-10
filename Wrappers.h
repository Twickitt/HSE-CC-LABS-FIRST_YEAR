#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "Student_Struct.h"
#include "TreeNode_Struct.h"

int linear_search_wrapper(Student* students, TreeNode* root, int size, char* key);
int tree_search_wrapper(Student* students, TreeNode* root, int size, char* key);

#endif