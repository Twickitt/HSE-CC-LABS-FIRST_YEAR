#include <stdio.h>
#include <time.h>

#include "Run_Sort.h"
#include "Selection_Sort.h"
#include "Quick_Sort.h"
#include "Heap_Sort.h"
#include "Print_Massive.h"


void Run_Sort(Student* arr, int n, int alg, int number){

    clock_t start, end;
    float sec_4_alg;

    const char* alg_name;
    const char* direction = number ? "ascending" : "descending";

    start = clock();

    switch(alg){
        case 1: 
            Selection_Sort(arr, n, number);
            alg_name = "Selection Sort"; 
            break;
        case 2: 
            Quick_Sort(arr, 0, n - 1, number); 
            alg_name = "Quick Sort";
            break;
        case 3: 
            Heap_Sort(arr, n, number); 
            alg_name = "Heap Sort";
            break;
        default: printf("Invalid number\n"); return;
    }
    
    end = clock();

    sec_4_alg = (float)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted List:\n");
    Print_Massive(arr, n);
    printf("\nAlg №%d finished in %.8f secks\n", alg, sec_4_alg);

    FILE* file = fopen("Algs_Time.csv", "a");
    if(file){
        static int header_written = 0;
        if(!header_written){
            fprintf(file, "Algorithm      Direction      Size      Time\n");
            header_written = 1;
        }

        fprintf(file, "\n%s; %s; %d; %.8f\n", alg_name, direction, n, sec_4_alg);
        fclose(file);
    }else{
        perror("File opening error");
    }
}