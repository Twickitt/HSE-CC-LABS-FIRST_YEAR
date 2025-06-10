#include "Student_Struct.h"
#include <stdlib.h>

Student* Add_Student_To_Array(Student* arr, int* size, Student new_student){
    Student* tmp =realloc(arr, (*size + 1)*sizeof(Student));
    if(!tmp){
        printf("Redistribution memory failure\n");
        return arr;
    }

    arr = tmp;
    arr[*size] = new_student;
    (*size)++;
    return arr;
}