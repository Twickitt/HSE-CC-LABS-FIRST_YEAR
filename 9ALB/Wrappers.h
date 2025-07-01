#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "Structures.h"
#include "Linear_Search.h"
#include "Bin_Search_Tree.h"
#include "Red_Black_Tree.h"


extern Node* start;

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

int red_black_tree_wrapper(Student* list, TreeNode* unused, int n, char* key) {
    extern Node* start;
    return Red_Black_Search(start, key);
}

#endif
