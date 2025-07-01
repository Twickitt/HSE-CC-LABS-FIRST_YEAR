#include <stdio.h>
#include "Selection_Sort.h"
#include "Comparison.h"

void Selection_Sort(Student arr[], int size, int number){
    
    for(int i = 0; i < size - 1; i ++){
        
        int min_ind = i;
        
        for(int j = i + 1; j < size; j++){
            
            if(comparison(&arr[j], &arr[min_ind], number) < 0)
                min_ind = j;
        }
        if (min_ind != i){
            Student tmp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = tmp;
        }
    }
}