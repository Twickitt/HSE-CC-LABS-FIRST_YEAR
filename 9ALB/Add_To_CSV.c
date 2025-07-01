#include "Add_To_CSV.h"
#include <stdio.h>

void save_times_all_algorithms(const char* filename, int N, float times[], int alg_count) {
    FILE* file = fopen(filename, "a");
    if (!file){ 
        perror("Failed to open file");  // Выведет причину ошибки
        return;
    }
    fprintf(file, "%d", N);
    for (int i = 0; i < alg_count; i++) {
        fprintf(file, ",%.6f", times[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}