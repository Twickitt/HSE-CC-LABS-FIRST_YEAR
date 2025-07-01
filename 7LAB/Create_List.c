#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Create_List.h"


int Create_List(Student* arr, int n){

    const char *names[] = {"Ivan", "Petr", "Alex", "Dmitriy", "Sergo", "Egor", "Andrey", "Maksim", "Denis", "Jeka", "Nefed"};
    const char *surnames[] = {"Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Morozov", "Orlov", "Smirnov", "Fyodorov", "Krilov"};
    const char *patronymics[] = {"Ivanovich", "Petrovich", "Alekseyevich", "Dmitriyevich", "Sergeyevich", "Yegorovich", "Maksimovich"};
    const char *faculties[] = {"CS", "Math", "Physics", "Biology", "History", "Data Science", "Politics"};
    const char *groups[] = {"224", "245", "126", "412", "112", "B1", "CS1", "HSB"};


    int na = sizeof(names)/sizeof(names[0]);
    int sur = sizeof(surnames)/sizeof(surnames[0]);
    int patr = sizeof(patronymics)/sizeof(patronymics[0]);
    int fac = sizeof(faculties)/sizeof(faculties[0]);
    int gr = sizeof(groups)/sizeof(groups[0]);
    
    for(int i =0; i <n; i++){
        const char* gen_name = names[rand() % na];
        const char* gen_surname = surnames[rand() % sur];
        const char* gen_partonymic = patronymics[rand() % patr];
        snprintf(arr[i].name, sizeof(arr[i].name), "%s %s %s", gen_surname, gen_name, gen_partonymic);

        strcpy(arr[i].faculty, faculties[rand() % fac]);
        strcpy(arr[i].group, groups[rand() % gr]);

        arr[i].GPA = 4.0 + (float)(rand() % 601) / 100.0;
        
    }
}