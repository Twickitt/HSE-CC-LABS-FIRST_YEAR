#include "Linear_Search_With_Any_Case.h"
#include "To_Lower.h"
#include <string.h>
#include <stdio.h>

#define MAX_LEN_KEY 100

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