#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structure.h"
#include "Run_Sort.h"
#include "Print_Massive.h"
#include "Heap_Sort.h"
#include "Quick_Sort.h"
#include "Selection_Sort.h"
#include "Comparison.h"
#include "Create_List.h"


int main(){

    int count;
do {
    printf("Enter positive number of students you want to generate: ");
    scanf("%d", &count);
    if (count <= 0) {
        printf("This number must be positive(count > 0)\n");
    }
} while (count <= 0);


    Student* students = malloc(count* sizeof(Student));
    if(!students){
        printf("Memory Allocation Error");
        return 1;
    }

    Create_List(students, count);
    printf("\nGenerated List:\n");
    Print_Massive(students, count);

    int choice;
    int order;
    do{
        printf("\nSelect Algorithm: \n");
        printf("1. Selection Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Heap Sort\n");
        printf("0. Exit\n> ");
        scanf("%d", &choice);
        if (choice == 0) break;

        if(choice < 1 || choice > 3){
            printf("\nInvalid algorithm number. Number should be from 1 to 3. Try again\n");
            continue;
        }

        printf("\nSelect Direction (1 for ascending or any other digit for descending):\n> ");
        scanf("%d", &order);
        int number = (order == 1);
        Run_Sort(students, count, choice, number);
    }while(1);

    free(students);

    return 0;
}