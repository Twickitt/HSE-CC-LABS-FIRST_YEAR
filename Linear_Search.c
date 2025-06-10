#include "Linear_Search.h"
#include <stdio.h>
#include <string.h>

int Linear_Search(Student arr[], int size, char* key) {
    
    
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].name, key) != NULL)
            return i;
    }
    return -1;
}