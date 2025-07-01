#include <stdio.h>
#include "Heap_Sort.h"
#include "Comparison.h"


void Heap_Down(Student* arr, int size, int i, int number) {
    int root = i;
    Student temp = arr[root];
    
    while (root * 2 + 1 < size) {
        int child = root * 2 + 1;
        if (child + 1 < size && comparison(&arr[child], &arr[child + 1], number) < 0)
            child++;
        if (comparison(&temp, &arr[child], number) >= 0)
            break;

        arr[root] = arr[child];
        root = child;
    }
    arr[root] = temp;
}

void Heap_Sort(Student* arr, int size, int number){
    for(int i = size/2 - 1; i >= 0; i--)
        Heap_Down(arr, size, i, number);
    for(int i = size - 1; i >= 0; i--){
        Student tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        Heap_Down(arr, i, 0, number);
    }
}