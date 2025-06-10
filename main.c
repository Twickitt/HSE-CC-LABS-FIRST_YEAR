#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN_KEY 100


typedef struct{
    char name[30];
    char faculty[30];
    char group[20];
    float GPA;
} Student;

typedef struct TreeNode{
    Student* student;
    int index;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* Insertation_Of_Tree(TreeNode* root, Student* s, int index){

    if(!root){
        TreeNode * node = malloc(sizeof(TreeNode));
        node->student = s;
        node->index = index; 
        node->left = node->right = NULL;
        return node;
    }

    int cmp = strcmp(s->name, root->student->name);
    if(cmp <0)
        root->left = Insertation_Of_Tree(root->left, s, index);
    else
        root->right = Insertation_Of_Tree(root->right, s, index);

    return root;    
}

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


void Free_Tree(TreeNode* root){
    if(!root){
        return;
    Free_Tree(root->left);
    Free_Tree(root->right);
    free(root);
    }
}

int Linear_Search(Student arr[], int size, char* key) {
    
    
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].name, key) != NULL)
            return i;
    }
    return -1;
}





int Create_List(Student* arr, int n){


    
    const char *names[] = {"Ivan", "Petr", "Alex", "Dmitriy", "Sergo", "Egor", "Andrey", "Maksim", "Denis", "Jeka", "Nefed"};
    const char *surnames[] = {"Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Morozov", "Orlov", "Smirnov", "Fyodorov", "Krilov"};
    const char *patronymics[] = {"Ivanovich", "Petrovich", "Alekseyevich", "Dmitriyevich", "Sergeyevich", "Yegorovich", "Maksimovich"};
    const char *faculties[] = {"CS", "Math", "Physics", "Biology", "History", "Data Science", "Politics"};
    const char *groups[] = {"224", "245", "126", "412", "112", "B1", "CS1", "HSB"};


    int na = sizeof(names)/sizeof(names[0]);
    int sur = sizeof(surnames)/sizeof(surnames[0]);
    int patr = sizeof(patronymics)/sizeof(patronymics[0]);
    int fac = sizeof(faculties)/sizeof(faculties[0]);
    int gr = sizeof(groups)/sizeof(groups[0]);
    
    for(int i =0; i <n; i++){
        const char* gen_name = names[rand() % na];
        const char* gen_surname = surnames[rand() % sur];
        const char* gen_partonymic = patronymics[rand() % patr];
        snprintf(arr[i].name, sizeof(arr[i].name), "%s %s %s", gen_surname, gen_name, gen_partonymic);

        strcpy(arr[i].faculty, faculties[rand() % fac]);
        strcpy(arr[i].group, groups[rand() % gr]);

        arr[i].GPA = 4.0 + (float)(rand() % 601) / 100.0;
        
    }
}

void Print_List(Student arr[], int size){
    for(int i = 0; i < size; i++){
        printf("------------------------------------------------------------------------------------\n");
        printf("%-12d%-30s | %-15s | %-11s | %-5.2f\n", i + 1, arr[i].name, arr[i].faculty, arr[i].group, arr[i].GPA);
    }
}


int linear_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Linear_Search(students, size, key);
}

int tree_search_wrapper(Student* students, TreeNode* root, int size, char* key) {
    return Bin_Search_Tree(root, key);
}




int main(){


    int (*menu[])(Student*, TreeNode*, int, char*) = {linear_search_wrapper, tree_search_wrapper};

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


    for(int i = 0; i < count; i ++)
        root = Insertation_Of_Tree(root, &Students[i], i);


    do {
        printf("\n1. Linear Search\n");
        printf("2. Binary Tree Search\n");
        printf("0. Exit\n");
        printf("Select Action: ");

        if (scanf("%d", &choice) != 1) {
            printf("You can't enter non-digits\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 0 || choice > 2) {
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
            printf("First appearance of the key %s is in the index=%d\n", key, index);
        else    
            printf("There is nothing with such key in this list\n");

        printf("Searching complited within %.4f\n", sec_4_alg);

    } while (1);

    free(Students);
    Free_Tree(root);
    return 0;

}
