#include <stdio.h>
#include "Print_Massive.h"


void Print_Massive(Student arr[], int size){
    for(int i = 0; i < size; i++){
        printf("------------------------------------------------------------------------------------\n");
        printf("%-12d%-30s | %-15s | %-11s | %-5.2f\n", i + 1, arr[i].name, arr[i].faculty, arr[i].group, arr[i].GPA);
    }
}