#include "To_Lower.h"
#include <ctype.h>

void To_Lower(char* S, char* B){
    while(*S){
        *B++ = tolower(*S++);

    }
    *B = '\0';

}