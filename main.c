#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "Insertation_In_Tree.h"
#include "To_Lower.h"
#include "Bin_Search_Tree.h"
#include "Free_Tree.h"
#include "Linear_Search.h"
#include "Create_List.h"
#include "Print_List.h"
#include "Wrappers.h"
#include "Bin_Search_Tree_With_Any_Case.h"
#include "Linear_Search_With_Any_Case.h"
#include "Red_Black_Tree.h"



#define MAX_LEN_KEY 100



Node* start = NULL;

int main(){


    int (*menu[])(Student*, TreeNode*, int, char*) = {linear_search_wrapper, tree_search_wrapper, linear_search_wrapper_1, tree_search_wrapper_1, red_black_tree_wrapper};

    char key[MAX_LEN_KEY];
    int count, choice;

    while (1) {
        printf("Enter positive number of Students you want to generate: ");
        if (scanf("%d", &count) != 1) {
            printf("You cant enter non digits\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (count <= 0 || count > 100000) {
            printf("Number must be in range (0;100000)\n");
            continue;
        }
        break;
    }


    Student* Students = malloc(sizeof(Student) *count);
    if(!Students){
        printf("\nMemorry allocation error");
        return 1;
    }

    
    TreeNode* root = NULL;

    
    Create_List(Students, count);
    printf("\nGenerated list of students\n");
    Print_List(Students, count);


    for(int i = 0; i < count; i ++){
        root = Insertation_In_Tree(root, &Students[i], i);
        start = Insert(start, &Students[i], i);
    }


    do {
        printf("\n1. Linear Search\n");
        printf("2. Binary Tree Search\n");
        printf("3. Linear Search With Any Case\n");
        printf("4. Binary Tree Search With Any Case\n");
        printf("5. Red Black Search\n");
        printf("0. Exit\n");
        printf("Select Action: ");

        if (scanf("%d", &choice) != 1) {
            printf("You can't enter non-digits\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 0 || choice > 5) {
            printf("You entered wrong number\n");
            continue;
        }

        if (choice == 0)
            break;

        
        printf("\nEnter key for searching: ");
        getchar();  
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        float sec_4_alg;
        clock_t start, end;
        start = clock();

        int index = menu[choice - 1](Students, root, count, key);

        end = clock();

        sec_4_alg = (float)(end - start)/CLOCKS_PER_SEC;

        if (index != -1)
            printf("First appearance of the key \'%s\' is in the index=%d\n", key, index);
        else    
            printf("There is nothing with such key in this list\n");

        printf("Searching complited within %.4f\n", sec_4_alg);

    } while (1);

    
    free(Students);
    Free_Tree(root);
    Free_RB_Tree(start);
    return 0;

}
