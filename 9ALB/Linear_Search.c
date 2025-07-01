#include "Linear_Search.h"
#include "To_Lower.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN_KEY 100

int Linear_Search(Student arr[], int size, char* key) {
    
    
    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].name, key) != NULL)
            return i;
    }
    return -1;
}


int Linear_Search_With_Any_Case(Student arr[], int size, char* key) {

    char lower_key[MAX_LEN_KEY];
    char lower_name[MAX_LEN_KEY];

    To_Lower(key, lower_key);
    
    for (int i = 0; i < size; i++) {
        To_Lower(arr[i].name, lower_name);
        if (strstr(lower_name, lower_key) != NULL)
            return i;
    }
    return -1;
}