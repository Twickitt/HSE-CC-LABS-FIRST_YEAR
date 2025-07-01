#include <stdio.h>
#include "Comparison.h"
#include <string.h>

int comparison(const Student* a, const Student* b, int number){
    int cmp;
    
    cmp = strcmp(a->name, b->name);
    if(cmp != 0)
        return number ? cmp : -cmp;
    cmp = strcmp(a->faculty, b->faculty);
    if(cmp != 0)
        return number ? cmp : -cmp;
    cmp = strcmp(a->group, b->group);
    if(cmp != 0)
        return number ? cmp : -cmp;
    cmp = (a->GPA > b->GPA) - (a->GPA < b->GPA);
    return number ? cmp : -cmp;


}