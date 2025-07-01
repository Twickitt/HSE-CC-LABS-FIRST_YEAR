#include <stdio.h>
#include "Quick_Sort.h"
#include "Comparison.h"


void Quick_Sort(Student arr[], int left, int right, int number){
    if(left >= right)
        return;
    Student middle = arr[(left + right) / 2];
    int i = left, j = right;

    while(i <= j){
        while(comparison(&arr[i], &middle, number) < 0)
            i++;      
        while(comparison(&arr[j], &middle, number) > 0)
            j--;
        
        if(i <= j){
            Student tmp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = tmp;
        }
    }
    
    Quick_Sort(arr, left, j, number);
    Quick_Sort(arr, i, right, number);
}
